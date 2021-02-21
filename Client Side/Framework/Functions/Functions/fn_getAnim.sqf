/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getAnim";

_this params [
	["_type", "", [""]],
	["_stance", "STAND", [""]]
];

private _stances = ["STAND", "CROUCH", "PRONE"];
if !(_stance in _stances) exitWith { "" };

private _anim = switch (_type) do {
	case "IDLE": {
		format["AmovP%1M%2S%3W%4Dnon", 
			["erc", "knl", "pne"] select(["STAND", "CROUCH", "PRONE"] find _stance) max 0, 
			["stp", "run"] select (vectorMagnitude velocity player > 1), 
			[["ras", "low"] select (weaponLowered player), "non"] select (currentWeapon player isEqualTo ""), 
			["non", "rfl", "lnr", "pst", "bin"] select(["", primaryWeapon player, secondaryWeapon player, handgunWeapon player, binocular player] find currentWeapon player) max 0
		]
	};
	case "GRAB": {
		format["AinvP%1MstpS%2W%3Dnon", 
			["erc", "knl", "pne"] select (_stances find _stance) max 0, 
			["ras", "non"] select(currentWeapon player isEqualTo ""), 
			["non", "rfl", "lnr", "pst"] select(["", primaryWeapon player, secondaryWeapon player, handgunWeapon player] find currentWeapon player) max 0
		];
	};
	default { "" };
};

_anim