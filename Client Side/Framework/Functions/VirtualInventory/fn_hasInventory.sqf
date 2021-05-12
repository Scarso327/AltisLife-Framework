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
	["_container", objNull, [objNull]],
	["_force", false, [true]]
];

if (_force) exitWith { true };

private _containerCfg = missionConfigFile >> "CfgVehicles" >> (typeOf _container);

isClass  _containerCfg && 
{ (getNumber (_containerCfg >> "virtualSpace") > 0) || isNumber (_containerCfg >> "tempStorage") } && 
{ (count (_container getVariable ["ULP_VirtualCargo", []])) > 0 || !([getNumber (_containerCfg >> "requireItems")] call ULP_fnc_bool) }