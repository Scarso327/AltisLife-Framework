/*
** Author: Jack "Scarso" Farhall
** Description: Sets the backpack state locally
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setHideBackpack";

private _isInvsible = ([["EnableInvisBackpack", "General"] call ULP_fnc_getOption] call ULP_fnc_bool);
private _textures = getArray(configFile >> "cfgVehicles" >> (backpack player) >> "hiddenSelectionsTextures");
private _backpack = unitBackpack player;

{
	_backpack setObjectTexture [_forEachIndex, ([_x, ""] select (_isInvsible))];
} forEach _textures;