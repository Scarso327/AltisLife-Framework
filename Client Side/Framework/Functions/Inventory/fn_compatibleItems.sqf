/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_compatibleItems";

_this params [
	["_item", "", [""]],
	["_magazine", true, [false]],
	["_attachments", true, [false]]
];

private _items = [];

if (_item isEqualTo "" || { !_magazine && !_attachments }) exitWith { _items };

private _cfg = configFile >> "CfgWeapons" >> _item;
if !(isClass _cfg) exitWith { _items };

// Include Mags?
if (_magazine) then {
	// Weapon Mags...
	_items append getArray (_cfg >> "magazines");

	// Grenade Lunacher Mags, Etc...
    { _items append getArray (_cfg >> _x >> "magazines"); } count (getArray (_cfg >> "muzzles") select { !(_x isEqualTo "this") });
};

// Inlucde Attachments?
if (_attachments) then {
	{
		_items append getArray (_cfg >> "weaponSlotsInfo" >> _x >> "compatibleItems");

		if (isClass (_cfg >> "weaponSlotsInfo" >> _x >> "compatibleItems")) then {
			{ _items pushBackUnique (configName _x); } forEach (configProperties [_cfg >> "weaponSlotsInfo" >> _x >> "compatibleItems", "((getNumber _x) isEqualTo 1)", true]);
		};

		nil
	} count (["CowsSlot", "PointerSlot", "MuzzleSlot", "UnderBarrelSlot", "asdg_OpticRail_SMAAssault", "asdg_Underbarrel", "asdg_FrontSideRail_SMAAssault"] select {
		isClass (_cfg >> "weaponSlotsInfo" >> _x)
	});
};

_items