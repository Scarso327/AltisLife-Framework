/*
** Author: Jack "Scarso" Farhall
** Description: Returns array of item cfg information...
*/
#include "..\..\script_macros.hpp"
scopeName "fn_itemCfg";

_this params [
	["_item", "", [""]]
];

private _class = (_item call {
	if (isClass(configFile >> "CfgWeapons" >> _this)) exitWith { "CfgWeapons" };
	if (isClass(configFile >> "CfgMagazines" >> _this)) exitWith { "CfgMagazines" };
	if (isClass(configFile >> "CfgGlasses" >> _this)) exitWith { "CfgGlasses" };
	"CfgVehicles"
});

private _armaCfg = (configFile >> _class >> _item);
private _internalCfg = ([_class, _item] call {
	scopeName "fn_getInternalCfg";

	_this params ["_class", "_item"];
	
	switch (_class) do {
		case "CfgWeapons": {
			// Vest, Headgear, Uniform
			if (getNumber(configFile >> "CfgWeapons" >> _item >> "type") in [4096, 131072]
				&& { getNumber(configFile >> "CfgWeapons">> _item >> "ItemInfo" >> "type") in [701, 801, 605] }) then {
				(missionConfigFile >> "CfgClothing" >> _item) breakOut "fn_getInternalCfg";
			};
		};
		case "CfgVehicles": {
			// Backpack
			if (getNumber (configFile >> "CfgVehicles" >> _item >> "isBackpack") isEqualTo 1) then {
				(missionConfigFile >> "CfgClothing" >> _item) breakOut "fn_getInternalCfg";
			};
		};
		case "CfgGlasses": {
			(missionConfigFile >> "CfgClothing" >> _item) breakOut "fn_getInternalCfg";
		};
	};

	configNull
});

private _textures = [];
if (!(isNull _internalCfg) && { isClass (_internalCfg >> "Textures") }) then {
	_textures = ("true" configClasses (_internalCfg >> "Textures"));
};

[
	_class,
	_armaCfg,
	_internalCfg,
	_item,
	getText (([_armaCfg, _internalCfg] select (isText (_internalCfg >> "picture"))) >> "picture"),
	getText (([_armaCfg, _internalCfg] select (isText (_internalCfg >> "displayName"))) >> "displayName"),
	([-1, getNumber (_internalCfg >> "price")] select (isNumber (_internalCfg >> "price"))),
	_textures
]