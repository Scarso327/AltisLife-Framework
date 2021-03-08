/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_openGroup";

if ([] call ULP_fnc_isGroup) then {
	["Group"] call ULP_fnc_setScreen;
} else {
	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [], [],
		{
			
		}
	] call ULP_fnc_selectNumber;
};