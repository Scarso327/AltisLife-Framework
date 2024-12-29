/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscIncapacitated_OnUnload";

_this params [ "_display" ];

if (isNull _display) exitWith {};

private _eachFrameIndex = _display getVariable ["eachFrame", -1];
if !(_eachFrameIndex isEqualTo -1) then { [_eachFrameIndex] call ULP_fnc_removeEachFrame; };