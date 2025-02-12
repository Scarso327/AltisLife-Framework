/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_pushVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle || { !(local _vehicle) } || { (speed _vehicle) > 3 } || { !((crew _vehicle) isEqualTo []) }) exitWith { false };

private _speed = 3;
private _velocity = velocity _vehicle;
private _direction = direction player;

_vehicle setVelocity [(_velocity select 0) + (sin _direction * _speed), (_velocity select 1) + (cos _direction * _speed), (_velocity select 2)];

if (_vehicle isKindOf "Ship" && { surfaceIsWater (position _vehicle) }) then {
    [1, _vehicle, { _this setVelocity [0, 0, 0]; }] call ULP_fnc_waitExecute;
};

true