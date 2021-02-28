/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_handleGear";

_this params [
	["_item", "", [""]],
	["_replace", false, [true]],
	["_texture", "", [""]] // Only used if uniform or backpack...
];

(_item call BIS_fnc_itemType) params ["_itemType", "_itemCategory"];

// Check for space, if there is just add it directly...
if ([_item, _itemType, _itemCategory, _replace] call ULP_fnc_canFitGear) exitWith {
	[_item, _itemType, _itemCategory, _texture] call ULP_fnc_setGear;
};

private _container = (_item call {
	if (player canAddItemToUniform _this) exitWith { uniformContainer player };
	if (player canAddItemToVest _this) exitWith { vestContainer player };
	if (player canAddItemToBackpack _this) exitWith { backpackContainer player };
	objNull
});

if (isNull _container) exitWith { false };

[backpackContainer player, _item, _itemType, _itemCategory] call ULP_fnc_addContainer