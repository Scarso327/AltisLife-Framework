/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_handleFog";

private _maxFog = getNumber(missionConfigFile >> "CfgSettings" >> "Weather" >> "maxFog");

[{ fog > _this }, _maxFog, {
	300 setFog 0;

	[300, [], { [] call ULP_SRV_fnc_handleFog; }] call ULP_fnc_waitExecute;
}] call ULP_fnc_waitUntilExecute;