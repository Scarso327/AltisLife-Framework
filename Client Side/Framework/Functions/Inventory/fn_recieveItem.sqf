/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_recieveItem";

_this params [
	["_unit", objNull, [objNull]],
	["_item", "", [""]],
	["_count", 1, [0]]
];

private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _item;
if (isNull _unit || { !(isClass _itemCfg) } || { [getNumber (_itemCfg >> "Settings" >> "isScripted")] call ULP_fnc_bool } || { _count < 1 }) exitWith { false };

if ([_item, _count, false, true] call ULP_fnc_handleItem) exitWith {
	[format ["%1 has given you %2 %3s", [_unit, true] call ULP_fnc_getName, [_count] call ULP_fnc_numberText, getText (_itemCfg >> "displayName")]] call ULP_fnc_hint;
	true
};

false