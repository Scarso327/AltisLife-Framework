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
if !(isClass _cfg || { _this call ULP_fnc_isTextureUnlocked }) exitWith { false };

private _currentTextures = ULP_UnlockedTextures getOrDefault [_classname, []];
_currentTextures pushBackUnique _texture;
ULP_UnlockedTextures set [_classname, _currentTextures];

[player, 9, ULP_UnlockedTextures] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
true