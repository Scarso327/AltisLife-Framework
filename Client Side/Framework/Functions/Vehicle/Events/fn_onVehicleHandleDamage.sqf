/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onVehicleHandleDamage";

_this params [
    ["_vehicle", objNull, [objNull]],
    ["_part", "", [""]],
    ["_damage", 0, [0]],
    ["_source", objNull, [objNull]],
    ["_projectile", "", [""]],
    ["_index", 0, [0]],
	["_instigator", objNull, [objNull]],
    ["_hitPoint", "", [""]]
];

private _currentDamage = if (_index isEqualTo -1) then {
    damage _vehicle
} else {
    _vehicle getHitIndex _index
};

if ([_vehicle, "ImprovedHullUpgrade"] call ULP_fnc_hasUpgrade 
    && { !(_projectile isEqualTo "") }
    && { !((toLower _hitPoint) isEqualTo "hithull") }) exitWith {
    private _difference = _damage - _currentDamage;

    _currentDamage + (_difference - (_difference * 0.25))
};

if ([_vehicle, "ImprovedTyresUpgrade"] call ULP_fnc_hasUpgrade 
    && { !(_projectile isEqualTo "") }
    && { !(((toLower _hitPoint) find "wheel") isEqualTo -1) }) exitWith {
    private _difference = _damage - _currentDamage;

    _currentDamage + (_difference - (_difference * 0.25))
};


_damage