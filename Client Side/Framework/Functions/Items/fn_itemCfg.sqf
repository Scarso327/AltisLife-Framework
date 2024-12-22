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
		case "CfgMagazines";
		case "CfgWeapons": {
			// Vest, Headgear, Uniform
			if (getNumber(configFile >> "CfgWeapons" >> _item >> "type") in [4096, 131072]
				&& { getNumber(configFile >> "CfgWeapons">> _item >> "ItemInfo" >> "type") in [701, 801, 605] }) then {
				(missionConfigFile >> "CfgClothing" >> _item) breakOut "fn_getInternalCfg";
			} else {
				(missionConfigFile >> "CfgItems" >> _item) breakOut "fn_getInternalCfg";
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

private _price = ([
	0, // No defined price...
	([
		getNumber (_internalCfg >> "price"), // Reputation isn't added...
		[getNumber (_internalCfg >> "price")] call ULP_fnc_reputationPrice // Reputation is added...
	] select ([getNumber (_internalCfg >> "reputation")] call ULP_fnc_bool))
] select (isNumber (_internalCfg >> "price")));

// Cartels...
if (_class isEqualTo "CfgWeapons") then {
	{
		private _object = missionNamespace getVariable [format["ULP_SRV_Cartel_%1", configName _x], objNull];

		if !(isNull _object) then {
			private _owner = (_object getVariable ["owner", []]) param [0, grpNull];
			if (!(isNull _owner) && { isClass (_x >> "Arms") } && { (_owner isEqualTo (group player)) }) then {
				_price = switch (getNumber( _armaCfg >> "type" )) do {
					case 1: { _price - (_price * getNumber (_x >> "Arms" >> "primaryDiscount")) };
					case 2: { _price - (_price * getNumber (_x >> "Arms" >> "secondaryDiscount")) };
					default { _price };
				};
			};
		};
	} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgCartels" >> "Fixed"));
};

private _hasDlc = (getAssetDLCInfo [_item, configFile >> _class]) param [1, true, [false]];
private _dlcIcon = getText(configFile >> "CfgMods" >> (getText (_armaCfg >> "DLC")) >> "logo");

[
	_class,
	_armaCfg,
	_internalCfg,
	_item,
	getText (([_armaCfg, _internalCfg] select (isText (_internalCfg >> "picture"))) >> "picture"),
	getText (([_armaCfg, _internalCfg] select (isText (_internalCfg >> "displayName"))) >> "displayName"),
	_price,
	_textures,
	[_hasDlc, _dlcIcon]
]