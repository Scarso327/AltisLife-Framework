/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscPvpScoreboard_OnLoad";
disableSerialization;

_this params [ "_display" ];

if (isNull _display) exitWith {};

uiNamespace setVariable ['RscPvpScoreboard', _display];

_display setVariable ["eachFrameHandle", ([[_display], { _this call ULP_UI_fnc_RscPvpScoreboard_OnEachFrame }] call ULP_fnc_addEachFrame)];