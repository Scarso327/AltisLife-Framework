/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscProgress_OnUnload";
disableSerialization;

_this params [ "_display" ];

if (isNull _display) exitWith {};

uiNamespace setVariable ['RscProgress', nil];

private _stance = _display getVariable ["stance", toUpper (stance player)];
private _animation = _display getVariable ["anim", ""];

if !(_animation isEqualTo "") then {
	player playMove (["IDLE", _stance] call ULP_fnc_getAnim);
};

private _eachFrameIndex = _display getVariable ["eachFrameHandle", -1];
if !(_eachFrameIndex isEqualTo -1) then { [_eachFrameIndex] call ULP_fnc_removeEachFrame; };