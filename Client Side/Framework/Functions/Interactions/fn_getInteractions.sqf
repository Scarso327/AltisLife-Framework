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

if (isNull _object || { !(alive _object) } || { (_object distance player) > 7 }) exitWith { _interactions };

private _typeOf = typeOf _object;
(_typeOf call BIS_fnc_objectType) params ["", "_type"];

private _actions = missionConfigFile >> "CfgInteractions" >> (switch (true) do {
	case (_typeOf isEqualTo "Land_MoneyBills_01_stack_F" && { (_object getVariable ["ULP_MoneyStack", 0]) > 0 }): { "Money" };
	case (_typeOf isEqualTo "Land_CargoBox_V1_F"): { "Vault" };
	case ([_object] call ULP_fnc_isHouse && 
		{ isClass (missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction >> "Housing") } &&
		{ [_object, player] call ULP_fnc_isHouseOwner }
	): { "HouseOwner" };
	case ([_object] call ULP_fnc_isHouse): { "House" };
	case (isPlayer _object && { isDowned(_object) }): { "PersonMedical" };
	case (isPlayer _object && { [_object] call ULP_fnc_isEscorted } && { [] call ULP_fnc_isEscorting }): { "PersonEscortOnly" };
	case (isPlayer _object): { "Person" };
	case (_typeOf isKindOf "Box_NATO_Equip_F"): { "EquipmentBox" };
	case (_type in ["Car", "Helicopter", "Plane", "Ship"] && { !(([_object] call ULP_fnc_getVehicleOwner) isEqualTo "") }): { "Vehicle" };
	default { "" };
});

if !(isClass _actions) exitWith { _interactions };

{
	if (_object call compile getText (_x >> "condition") && { [player, getArray(_x >> "factions")] call ULP_fnc_isFaction }) then {
		_interactions pushBack [getText(_x >> "title"), getText(_x >> "onClick")];
	};
} forEach ("isClass _x" configClasses _actions);

_interactions