/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_giveItem";

_this params [
	["_unit", objNull, [objNull]],
	["_item", "", [""]],
	["_count", 1, [0]]
];

private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _item;
if (isNull _unit || { !(isClass _itemCfg) } || { [getNumber (_itemCfg >> "Settings" >> "isScripted")] call ULP_fnc_bool } || { _count < 1 }) exitWith { false };

if (([_item] call ULP_fnc_hasItem) < _count) exitWith {
	[format ["You don't have %1 %2s to give to %3", [_count] call ULP_fnc_numberText, getText (_itemCfg >> "displayName"), [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;
	false
};

[_item, _count, true] call ULP_fnc_handleItem;
[format ["You have given %1 %2 %3s", [_unit, true] call ULP_fnc_getName, [_count] call ULP_fnc_numberText, getText (_itemCfg >> "displayName")]] call ULP_fnc_hint;
[player, _item, _count] remoteExecCall ["ULP_fnc_recieveItem", _unit];
true