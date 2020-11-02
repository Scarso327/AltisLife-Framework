#include "..\..\script_macros.hpp"
/*
    File: fn_gangUpgrade.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Determinds the upgrade price and blah
*/
private ["_maxMembers","_slotUpgrade","_upgradePrice"];
_maxMembers = group player getVariable ["gang_maxMembers",8];
_slotUpgrade = _maxMembers + 4;
_upgradePrice = round(_slotUpgrade * ((LIFE_SETTINGS(getNumber,"group_upgradeBase"))) / ((LIFE_SETTINGS(getNumber,"gang_upgradeMultiplier"))));

_action = [
    format [("You are about to upgrade the maximum members allowed for your group.")+ "<br/><br/>" +("Current Max: %1")+ "<br/>" +("Upgraded Max: %2")+ "<br/>" +("Price:")+ " <t color='#8cff9b'>£%3</t>",_maxMembers,_slotUpgrade,[_upgradePrice] call life_fnc_numberText],
    "Upgrade Maximum Allowed Group Members",
    "Buy",
    "Cancel"
] call BIS_fnc_guiMessage;

if (_action) then {
    if (BANK < _upgradePrice) exitWith {
        hint parseText format [
            (localize "You do not have enough money in your bank account to upgrade the group's maximum member limit.")+ "<br/><br/>" +("Current:")+ " <t color='#8cff9b'>£%1</t><br/>" +("Lacking:")+ " <t color='#FF0000'>£%2</t>",
            [BANK] call life_fnc_numberText,
            [_upgradePrice - BANK] call life_fnc_numberText
        ];
    };
    BANK = BANK - _upgradePrice;
    [1] call SOCK_fnc_updatePartial;
    group player setVariable ["gang_maxMembers",_slotUpgrade,true];
    hint parseText format ["You have upgraded from %1 to %2 maximum slots for &lt;t color='#8cff9b'&gt;£%3&lt;/t&gt;",_maxMembers,_slotUpgrade,[_upgradePrice] call life_fnc_numberText];

    if (life_HC_isActive) then {
        [2,group player] remoteExec ["HC_fnc_updateGang",HC_Life];
    } else {
        [2,group player] remoteExec ["TON_fnc_updateGang",RSERV];
    };

} else {
    hint "Upgrade cancelled.";
};
