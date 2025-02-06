/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#define JUMP_ANIM "AovrPercMrunSrasWrflDf"
scopeName "fn_jump";

if !(hasInterface) exitWith {};

_this params [
	["_unit", player, [objNull]]
];

if (isNull _unit) exitWith {};

private _oldPos = getPosATL _unit;
private _originalAnim = animationState _unit;

if (_originalAnim isEqualTo JUMP_ANIM) exitWith {};

if (local _unit) then {
    private _v1 = 3.8;
    private _v2 = .5;
    private _dir = direction _unit;
    private _vel = velocity _unit;

    _unit setVelocity [(_vel select 0)+ (sin _dir*_v2), (_vel select 1) + (cos _dir*_v2), (_vel select 2) + _v1];
};

_unit switchMove JUMP_ANIM;

if !(local _unit) exitWith {};

[{ 
	_this params [ "_unit", "_oldPos" ];

	if (((getPos _unit) select 2) > 4) then {
		_unit setPosATL _oldPos;
		_unit setVelocity [0, 0, 0];
	};
	
	!(animationState _unit isEqualTo JUMP_ANIM)
}, [_unit, _oldPos, _originalAnim], {
	_this params [ "_unit", "", "_originalAnim" ];

	_unit switchMove _originalAnim;
}] call ULP_fnc_waitUntilExecute;