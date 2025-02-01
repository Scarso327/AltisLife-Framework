/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onVehicleRopeAttach";

_this params [
	["_vehicle", objNull, [objNull]],
	["_rope", objNull, [objNull]],
	["_object", objNull, [objNull]]
];

if (local _vehicle && { [_object] call ULP_fnc_hasInventory }) then {
	private _itemsInCargo = keys (_object getVariable ["ULP_VirtualCargo", createHashMap]);

	private _hasNonSlingLoadableItem = !(_itemsInCargo findIf {
			private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _x;

			isClass _itemCfg && { isNumber (_itemCfg >> "Settings" >> "canSlingLoad") } && { !([getNumber (_itemCfg >> "Settings" >> "canSlingLoad")] call ULP_fnc_bool) }
		} isEqualTo -1);

	if !(_hasNonSlingLoadableItem) exitWith {};
	
	if !(diag_tickTime - (_object getVariable ["ropeAttach", 0]) < 2) then {
		["You can't sling load this vehicle as it contains blacklisted items"] call ULP_fnc_hint;
	};

	deleteVehicle _rope;

	_object setVariable ["ropeAttach", diag_tickTime];
};