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

private _typeOf = typeOf _object;
(_typeOf call BIS_fnc_objectType) params ["", "_type"];

private _actions = missionConfigFile >> "CfgInteractions" >> (switch (true) do {
	case (isPlayer _object && { [_object] call ULP_fnc_isEscorted } && { [] call ULP_fnc_isEscorting }): { "PersonEscortOnly" };
	case (isPlayer _object): { "Person" };
	case (_typeOf isKindOf "Box_NATO_Equip_F"): { "EquipmentBox" };
	case (_type in ["Car", "Air", "Ship"]): { "Vehicle" };
	default { "" };
});

if !(isClass _actions) exitWith { _interactions };

{
	if (_object call compile getText (_x >> "condition") && { [player, getArray(_x >> "factions")] call ULP_fnc_isFaction }) then {
		_interactions pushBack [getText(_x >> "title"), getText(_x >> "onClick")];
	};
} forEach ("isClass _x" configClasses _actions);

_interactions