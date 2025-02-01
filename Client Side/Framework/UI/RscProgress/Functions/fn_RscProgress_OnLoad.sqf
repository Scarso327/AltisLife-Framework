/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscProgress_OnLoad";
disableSerialization;

_this params [ "_display" ];

if (isNull _display) exitWith {};

uiNamespace setVariable ['RscProgress', _display];