/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscHints_OnLoad";
disableSerialization;

_this params [ "_display" ];

if (isNull _display) exitWith {};

uiNamespace setVariable ['RscHints', _display];

_display setVariable ["eachFrame", ([[_display], { _this call ULP_UI_fnc_RscHints_OnEachFrame }] call ULP_fnc_addEachFrame)];