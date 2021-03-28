/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasInventory";

if (canSuspend) exitWith {
    [ULP_fnc_hasInventory, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]]
];

private _containerCfg = missionConfigFile >> "CfgVehicles" >> (typeOf _container);
isClass  _containerCfg && { (getNumber (_containerCfg >> "virtualSpace") > 0) || isNumber (_containerCfg >> "tempStorage") }