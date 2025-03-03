/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_skinVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_skinVehicle, _this] call ULP_fnc_directCall;
};

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

if (isArray (_textureCfg >> "materials")) then {
	{
		if (_local) then {
			_vehicle setObjectMaterial [_forEachIndex, _x];
		} else {
			_vehicle setObjectMaterialGlobal [_forEachIndex, _x];
		};
	} forEach getArray(_textureCfg >> "materials");
};

if (isArray (_textureCfg >> "animations")) then {
	{
		_x params [ "_animationName", "_animationState" ];

		if !((_vehicle animationSourcePhase _animationName) isEqualTo _animationState) then {
			_vehicle animateSource [_animationName, _animationState, true];
		};
	} forEach getArray(_textureCfg >> "animations");
};

if (isArray (_textureCfg >> "upgrades")) then {
	private _upgrades = createHashMap;

	{
		_upgrades set [_x, true];
	} forEach getArray(_textureCfg >> "upgrades");

	if !(_upgrades isEqualTo createHashMap) then {
		_vehicle setVariable ["object_upgrades", _upgrades, !_local];
	};
};

if (isArray (_textureCfg >> "inventory")) then {
	private _cargo = createHashMap;

	{
		_x params [ "_item", "_quantity" ];
		_cargo set [_item, _quantity];
	} forEach getArray(_textureCfg >> "inventory");

	if !(_cargo isEqualTo createHashMap) then {
		_vehicle setVariable ["ULP_VirtualCargo", _cargo, !_local];
	};
};

_vehicle setVariable ["texture", _texture, !_local];