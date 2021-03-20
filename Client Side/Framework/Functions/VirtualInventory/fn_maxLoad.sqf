/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_maxLoad";

if (canSuspend) exitWith {
    [ULP_fnc_maxLoad, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]]
];

private _containerCfg = missionConfigFile >> "CfgVehicles" >> (typeOf _container);
if !(isClass  _containerCfg) exitWith { 0 };

getNumber (_containerCfg >> "virtualSpace")