#include "..\..\script_macros.hpp"

/*
    File: fn_giveItem.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Gives the selected item & amount to the selected player and
    removes the item & amount of it from the players virtual
    inventory.
*/

ctrlShow [2002,false];

call {
    private _value = ctrlText 2010;

    if ((lbCurSel 2023) isEqualTo -1) exitWith {
        hint "No one was selected!";
    };

    if ((lbCurSel 2005) isEqualTo -1) exitWith {
        hint "You didn't select an item you wanted to give.";
    };


    private _unit = lbData [2023, lbCurSel 2023];
    _unit = call compile format ["%1",_unit];

    if (isNil "_unit") exitWith {
        hint "The selected player is not within range.";
    };
    if (isNull _unit || {_unit isEqualTo player}) exitWith {};

    private _item = lbData [2005, lbCurSel 2005];

    if !([_value] call TON_fnc_isnumber) exitWith {
        hint "You didn't enter an actual number format.";
    };
    if (parseNumber _value <= 0) exitWith {
        hint "You need to enter an actual amount you want to give.";
    };
    if !([false,_item, parseNumber _value] call life_fnc_handleInv) exitWith {
        hint "Couldn't give that much of that item, maybe you don't have that amount?";
    };

    [_unit, _value, _item, player] remoteExecCall ["life_fnc_receiveItem", _unit];
    private _type = M_CONFIG(getText,"VirtualItems",_item,"displayName");
    hint format ["You gave %1 %2 %3.", _unit getVariable ["realname", name _unit], _value, localize _type];

    [] call life_fnc_p_updateMenu;
};

ctrlShow[2002,true];
