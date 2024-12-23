/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openHud";

if ([] call ULP_UI_fnc_isHudShown) exitWith {
	if (["EnableHUD", "HUD"] call ULP_fnc_getOption isEqualTo 0) then {
		[(["RscHUD"] call ULP_UI_fnc_getLayer)] call ULP_UI_fnc_closeHUD;
	};

	false
};

["RscHUD", "PLAIN", 3] call ULP_UI_fnc_createLayer