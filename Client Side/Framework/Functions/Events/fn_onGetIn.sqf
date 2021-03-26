/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onGetIn";

_this params [
	["_unit", objNull, [objNull]],
	["_role", "", [""]],
	["_vehicle", objNull, [objNull]],
	["_turret", [], [[]]]
]; 

if ([] call ULP_UI_fnc_isProgress) then {
	[["RscProgress"] call ULP_UI_fnc_getLayer, false] call ULP_UI_fnc_endProgress;
};

if ([] call ULP_fnc_isEscorting) then {
	[ULP_Escort, player, false] call ULP_fnc_escort;
};

true