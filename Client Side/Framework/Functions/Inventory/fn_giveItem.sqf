/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_giveItem";

_this params [
	["_unit", objNull, [objNull]],
	["_item", "", [""]],
	["_data", 1, [0, "", []]]
];

private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _item;

if (isNull _unit || { !(isClass _itemCfg) }) exitWith { false };

private _count = _data;
if !(_data isEqualType 0) then {
	_count = 1;
};

if (_count <= 0) exitWith { false };

private _displayName = getText (_itemCfg >> "displayName");

if ([getNumber (_itemCfg >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
	_displayName = format [_displayName, _data];
};

if !([_item, _data, true] call ULP_fnc_handleItem) exitWith {
	[format ["You don't have %1 %2s to give to %3", [_count] call ULP_fnc_numberText, _displayName, [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;
	false
};

[format ["You have given %1 %2 %3s", [_unit, true] call ULP_fnc_getName, [_count] call ULP_fnc_numberText, _displayName]] call ULP_fnc_hint;
[player, _item, _data] remoteExecCall ["ULP_fnc_recieveItem", _unit];
true