/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#define CFG missionConfigFile >> "CfgClothing"
scopeName "fn_setTextures";

_this params [
	["_object", player, [objNull]],
	["_classname", "", [""]],
	["_container", uniformContainer player, [objNull]],
	["_texture", configNull, [configNull, ""]],
    ["_global", true, [false]]
];

if (isNull _object || { _classname isEqualTo "" } || { isNull _container }) exitWith { false };

if (_texture isEqualType "") then {
	_texture = CFG >> _classname >> "Textures" >> _texture;
};

if (isNull _texture) exitWith { false };

private _cfgParents = configHierarchy (_texture);

// Ensure object's uniform matches the texture we're trying to set.
if !(_classname isEqualTo (configName (_cfgParents select ((count _cfgParents) - 3)))) exitWith { false };

if (_global) then {
	[_object, _container, _texture, _classname] remoteExecCall ["ULP_fnc_applyTextures", 0];
} else {
	[_object, _container, _texture, _classname] call ULP_fnc_applyTextures;
};

true