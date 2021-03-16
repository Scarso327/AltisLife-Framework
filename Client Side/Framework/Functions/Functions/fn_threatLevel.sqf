/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_threatLevel";

_this params [
	["_friendly", false, [false]]
];

if (_friendly) exitWith {
	(getArray (missionConfigFile >> "CfgSettings" >> "threatLevels") select (["ULP_SRV_Setting_ThreatLevel"] call ULP_fnc_constant))
};

(["ULP_SRV_Setting_ThreatLevel"] call ULP_fnc_constant)