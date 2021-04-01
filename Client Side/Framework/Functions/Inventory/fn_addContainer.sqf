/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addGear";

_this params [
	["_container", objNull, [objNull]],
	["_item", "", [""]],
	["_itemType", "", [""]],
	["_itemCategory", "", [""]]
];

if (isNull _container) exitWith { false };

switch (_itemType) do {
	case "Weapon": {
		_container addWeaponCargoGlobal [_item, 1];
	};
	case "Mine";
	case "Magazine": {
		_container addMagazineCargoGlobal [_item, 1];
	};
	default {
		if !(_itemCategory isEqualTo "Backpack") then {
			_container addItemCargoGlobal [_item, 1];
		};

		// _container addBackpackCargoGlobal [_item, 1];
	};
};

true