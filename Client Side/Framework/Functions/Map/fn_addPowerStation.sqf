/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addPowerStation";

_this params [
	["_trader", objNull, [objNull]],
	["_powerStation", "", [""]]
];

private _cfg = missionConfigFile >> "CfgPowerStations" >> worldName >> _powerStation;
if (isNull _trader || { !isClass _cfg }) exitWith {};

_trader setVariable ["powerStation", _powerStation];

_trader addAction ["<t color='#B92DE0'>[Civilian]</t> Rediect Power", { _this call ULP_fnc_powerFactory }, [], 1, true, true, "", getText (_cfg >> "condition"), 3];