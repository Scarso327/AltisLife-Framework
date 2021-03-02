/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_skinVehicle";

_this params [
	["_vehicle", objNull, [objNull]],
	["_texture", "", [""]],
	["_local", false, [true]]
];

if (isNull _vehicle) exitWith {};

private _class = typeOf _vehicle;
private _textureCfg = missionConfigFile >> "CfgVehicles" >> _class >> "Textures" >> _texture;
if !(isClass _textureCfg) exitWith {};

{
	if (_local) then {
		_vehicle setObjectTexture [_forEachIndex, _x];
	} else {
		_vehicle setObjectTextureGlobal [_forEachIndex, _x];
	};
} forEach getArray(_textureCfg >> "textures");

_vehicle setVariable ["texture", _texture, !_local];