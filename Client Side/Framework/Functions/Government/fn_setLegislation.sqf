/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setLegislation";

_this params [
	["_ctrl", controlNull, [controlNull]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if !([] call ULP_fnc_isGovernor) exitWith {
	["Only the governor can access this system..."] call ULP_fnc_hint;
};

// Stop spam...
if (time < (player getVariable ["governor_cooldown", 0])) exitWith {
	["You've changed some legislation recently, please wait before trying again."] call ULP_fnc_hint;
};
player setVariable ["governor_cooldown", time + 5];

private _list = _display displayCtrl 4801;
private _legislation = missionConfigFile >> "CfgGovernment" >> "Legislation" >> (_list lbData (lbCurSel _list));
if !(isClass _legislation) exitWith {
	["This legislation can't be changed... try again later..."] call ULP_fnc_hint;
};

private _values = getArray (_legislation >> "values");

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), getArray (_legislation >> "values") param [0, [0, 1]], [_legislation],
	{
		_this params [
			["_legislation", configNull, [configNull]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		[configName _legislation, _value] remoteExecCall ["ULP_SRV_fnc_saveLegislation", RSERV];

		[format ["You have changed <t color='#B92DE0'>%1</t> to <t color='#B92DE0'>%2</t>", getText (_legislation >> "displayName"), _value call compile getText (_legislation >> "format")]] call ULP_fnc_hint;
	}, false, getText (_legislation >> "format"), false
] call ULP_fnc_selectNumber;