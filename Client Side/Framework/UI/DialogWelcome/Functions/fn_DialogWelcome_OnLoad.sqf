/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogWelcome_OnLoad";

_this params [ "_display" ];

if (isNull _display) exitWith {};

disableSerialization;
uiNamespace setVariable ["DialogWelcome", _display];