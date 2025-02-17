/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasUpgrade";

_this params [
	["_object", objNull, [objNull]],
	["_upgrade", "", [""]]
];

private _cfg = (([_object] call ULP_fnc_upgradeCfg) >> _upgrade);

if (isNull _object || { !isClass _cfg }) exitWith { false };

(_upgrade in (_object getVariable ["object_upgrades", createHashMap]))