/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getInventroy";

_this params [
	["_object", player, [objNull]]
];

if (isNull _object) exitWith { [] };

private _inv = [];

// Clothing...
if !((headgear _object) isEqualTo "") then { _inv pushBack (headgear _object) };
if !((goggles _object) isEqualTo "") then { _inv pushBack (goggles _object) };
if !((uniform _object) isEqualTo "") then { _inv pushBack (uniform _object) };
if !((vest _object) isEqualTo "") then { _inv pushBack (vest _object) };
if !((backpack _object) isEqualTo "") then { _inv pushBack (backpack _object) };

// Weapons...
if !((primaryWeapon _object) isEqualTo "") then { _inv pushBack (primaryWeapon _object) };
if !((secondaryWeapon _object) isEqualTo "") then { _inv pushBack (secondaryWeapon _object) };
if !((handgunWeapon _object) isEqualTo "") then { _inv pushBack (handgunWeapon _object) };

// Items...
_inv append (primaryWeaponItems _object);
_inv append (assignedItems _object);
_inv append (uniformItems _object);
_inv append (vestItems _object);
_inv append (backpackItems _object);

(_inv select { !(_x isEqualTo "") })