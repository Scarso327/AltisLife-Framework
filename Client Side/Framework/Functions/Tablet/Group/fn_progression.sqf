/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_progression";

_display = _this;
if (isNull _display) exitWith {};

private _xp = [] call ULP_fnc_groupXP;
private _required = [(([] call ULP_fnc_groupLevel) + 1), missionConfigFile >> "CfgGroups" >> "Leveling"] call ULP_fnc_getRequiredXP;

(_display displayCtrl 23083) progressSetPosition (_xp / _required);

(_display displayCtrl 23084) ctrlSetStructuredText parseText format ["<t size='2.5'>Level %1<t align='center'>%2/%3</t><t align='right'>Level %4</t>",
	[[] call ULP_fnc_groupLevel] call ULP_fnc_numberText,
	[_xp] call ULP_fnc_numberText,
	[_required] call ULP_fnc_numberText,
	[((([] call ULP_fnc_groupLevel) + 1) min ([missionConfigFile >> "CfgGroups" >> "Leveling"] call ULP_fnc_getMaxLevel))] call ULP_fnc_numberText
];