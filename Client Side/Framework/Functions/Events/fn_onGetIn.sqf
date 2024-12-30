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

if ([_unit] call ULP_fnc_isRestrained && { !((_unit getVariable ["restrained_in_vehicle", objNull]) isEqualTo _vehicle) }) exitWIth {
	_unit action["eject", _vehicle];
};

["SecondNature", _unit] call ULP_fnc_activatePerk;

[] call ULP_fnc_stopPlacement;

if ([["EnableAutoChatSwitch"] call ULP_fnc_getOption] call ULP_fnc_bool && { currentChannel isEqualTo 5 }) then {
	setCurrentChannel 4;
};

[] call ULP_fnc_setViewDistance;

true