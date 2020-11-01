#include "..\..\script_macros.hpp"
/*
    File: fn_buyHouseGarage.sqf
    Author: BoGuu
    Description:
    Buy functionality for house garages.
*/

private _house = param [0,objNull,[objNull]];
private _uid = getPlayerUID player;

if (isNull _house) exitWith {};
if (_house getVariable ["garageBought",false]) exitWith {hint "This garage has already been bought!";};
if ((_house getVariable "house_owner") select 0 != getPlayerUID player) exitWith {hint "You are not the owner of this house!";};
if (_house getVariable ["blacklistedGarage",false]) exitWith {};
closeDialog 0;

private _price = LIFE_SETTINGS(getNumber,"houseGarage_buyPrice");

_action = [
    format ["This garage is available for &lt;t color='#8cff9b'&gt;£%1&lt;/t&gt;&lt;br/&gt;",
    [_price] call life_fnc_numberText],
    "Purchase Garage",
    "Buy",
    "Cancel"
] call BIS_fnc_guiMessage;

if (_action) then {

    if (BANK < _price) exitWith {hint format [localize "STR_House_NotEnough"]};
    BANK = BANK - _price;
    [1] call SOCK_fnc_updatePartial;

    if (life_HC_isActive) then {
        [_uid,_house,0] remoteExec ["HC_fnc_houseGarage",HC_Life];
    } else {
        [_uid,_house,0] remoteExec ["TON_fnc_houseGarage",RSERV];
    };

    _house setVariable ["garageBought",true,true];

};