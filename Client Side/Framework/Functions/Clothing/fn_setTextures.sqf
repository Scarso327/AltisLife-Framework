/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#define CFG missionConfigFile >> "CfgClothing"
scopeName "fn_setTextures";

_this params [
	["_object", player, [objNull]],
	["_container", uniformContainer player, [objNull]],
	["_texture", configNull, [configNull, ""]],
	["_isBackpack", false, [true]],
    ["_isGlobal", true, [false]]
];

if (isNull _object || { isNull _container }) exitWith {};

private _clothing = ([
	uniform _object,
	(typeOf _object)
] select (_isBackpack));

if (_texture isEqualType "") then {
	_texture = CFG >> _clothing >> "Textures" >> _texture;
};

if (isNull _texture) exitWith {};

private _cfgParents = configHierarchy (_texture);

// Ensure object's uniform matches the texture we're trying to set.
if !(_clothing isEqualTo (configName (_cfgParents select ((count _cfgParents) - 3)))) exitWith {};

if (isArray (_texture >> "textures")) then {
	{
		/*
		 * Temp work around for comment by snov https://feedback.bistudio.com/T80668
		*/
		if (_x isEqualTo "") then {
			if (!isServer) then {
				[_object, _container, _texture, _isBackpack, true] remoteExecCall ["ULP_fnc_setTextures", RSERV];
				breakOut "fn_setTextures";
			} else {
				_object hideObjectGlobal true;
			};
		};

		if (_isGlobal) then {
			_object setObjectTextureGlobal [_forEachIndex, _x];
		} else {
			_object setObjectTexture [_forEachIndex, _x];
		};
	} forEach (getArray (_texture >> "textures"));
};

if !(_container getVariable ["texture", ""] isEqualTo (configName _texture)) then {
	_container setVariable ["texture", configName _texture, _isGlobal];
};