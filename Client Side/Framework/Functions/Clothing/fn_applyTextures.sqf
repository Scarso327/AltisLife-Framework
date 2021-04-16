/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_applyTextures";

_this pushBack ([getNumber (configFile >> "CfgVehicles" >> (_this select 3) >> "isBackpack")] call ULP_fnc_bool);
_this pushBack (time + 5);

[([
	{ (uniform (_this select 0)) isEqualTo (_this select 3) || { time > (_this select 5) } },
	{ (typeOf (_this select 0)) isEqualTo (_this select 3) || { time > (_this select 5) } }
] select ([getNumber (configFile >> "CfgVehicles" >> (_this select 3) >> "isBackpack")] call ULP_fnc_bool)), _this, {
	_this params [ "_object", "_container", "_texture", "_classname", "_backpack" ];

	// Did we just timeout?
	if !(([uniform _object, typeOf _object] select (_backpack)) isEqualTo _classname) exitWith { false };

	if (isArray (_texture >> "textures")) then {
		{
			_object setObjectTexture [_forEachIndex, _x];
		} forEach (getArray (_texture >> "textures"));
	};

	if !(_container getVariable ["texture", ""] isEqualTo (configName _texture)) then {
		_container setVariable ["texture", configName _texture, true];
	};

	true
}] call ULP_fnc_waitUntilExecute;