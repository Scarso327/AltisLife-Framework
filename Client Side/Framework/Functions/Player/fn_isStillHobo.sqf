/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isStillHobo";

if ([] call ULP_fnc_isHobo) exitWith { true };

if (!isNil { player getVariable "isHobo" }) then {
	player setVariable ["isHobo", nil, true];
};

if (!isNil "ULP_HoboEventHandlers") then {
	{
		_x call ULP_fnc_removeEventHandler;
	} forEach ULP_HoboEventHandlers;

	ULP_HoboEventHandlers = nil;
};

false