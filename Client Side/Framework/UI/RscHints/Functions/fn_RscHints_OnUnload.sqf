/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscHints_OnUnload";
disableSerialization;

_this params [ "_display" ];

if (isNull _display) exitWith {};

uiNamespace setVariable ['RscHints', nil];

{
	ctrlDelete _x;
} forEach + (_display getVariable ["hints", []]);

private _eachFrameIndex = _display getVariable ["eachFrame", -1];
if !(_eachFrameIndex isEqualTo -1) then { [_eachFrameIndex] call ULP_fnc_removeEachFrame; };