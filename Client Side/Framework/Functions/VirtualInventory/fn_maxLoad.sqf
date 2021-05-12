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
_container getVariable ["ULP_VirtualSpace", [0, getNumber (_containerCfg >> "virtualSpace")] select (isClass  _containerCfg)];