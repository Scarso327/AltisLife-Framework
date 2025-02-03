/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasRequiredPower";

_this params [
	["_factory", "", [""]]
];

private _cfg = missionConfigFile >> "CfgFactories" >> worldName >> _factory;
if !(isClass _cfg) exitWith { false };

private _requiredPower = getNumber (_cfg >> "requiredPower");

(missionNamespace getVariable [format["ULP_SRV_Factory_%1_Power", _factory], 0]) >= _requiredPower