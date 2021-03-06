/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getInteractions";

_this params [
	["_object", objNull, [objNull]]
];

private _interactions = [];

if (isNull _object || { (_object distance player) > 5 }) exitWith { _interactions };

((typeOf _object) call BIS_fnc_objectType) params ["", "_type"];

private _actions = missionConfigFile >> "CfgInteractions" >> (switch (true) do {
	case (_type in ["Car", "Air", "Ship"]): { "Vehicle" };
	default { "" };
});

if !(isClass _actions) exitWith { _interactions };

{
	if (call compile getText (_x >> "condition") && { [player, getArray(_x >> "factions")] call ULP_fnc_isFaction }) then {
		_interactions pushBack [getText(_x >> "title"), getText(_x >> "onClick")];
	};
} forEach ("isClass _x" configClasses _actions);

_interactions