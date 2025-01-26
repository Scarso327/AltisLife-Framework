/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_handleRain";

private _rainThreshold = getNumber(missionConfigFile >> "CfgSettings" >> "Weather" >> "maxRain");

[{ rain > _this }, _rainThreshold, {
	300 setRain 0;

	[300, [], { [] call ULP_SRV_fnc_handleRain; }] call ULP_fnc_waitExecute;
}] call ULP_fnc_waitUntilExecute;