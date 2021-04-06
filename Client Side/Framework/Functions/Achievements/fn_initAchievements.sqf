/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initAchievements";

["Initialising Achievements"] call ULP_fnc_logIt;

["MoneyChanged", {
	_this params [ "", "_bank" ];

	if (_bank >= 1000000) then { ["OneMillion"] call ULP_fnc_achieve; };
	if (_bank >= 10000000) then { ["TenMillion"] call ULP_fnc_achieve; };
	if (_bank >= 100000000) then { ["HundredMillion"] call ULP_fnc_achieve; };
}] call ULP_fnc_addEventHandler;