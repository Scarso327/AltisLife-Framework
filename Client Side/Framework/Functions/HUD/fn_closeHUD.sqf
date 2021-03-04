/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_closeHUD";

_this params [
	"_ui"
];

if !(isNull _ui) then {
	["RscHUD"] call ULP_UI_fnc_destroyLayer;
};

[_thisEventHandler] call ULP_fnc_removeEachFrame;