/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_unlockTexture";

_this params [
	["_classname", "", [""]],
	["_texture", "", [""]]
];

private _cfg = missionConfigFile >> "CfgVehicles" >> _classname >> "Textures" >> _texture;
(isClass _cfg && { getNumber (_cfg >> "locked") isEqualTo 0 || { (_texture in (ULP_UnlockedTextures getOrDefault [_classname, []])) } })