/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_listCrimes";

if (canSuspend) exitWith {
    [ULP_fnc_listCrimes, _this] call ULP_fnc_directCall;
};

_this params [
	["_warrants", controlNull, [controlNull]],
	["_path", [], [[]]]
];

private _display = ctrlParent _warrants;
if (isNull _display || { (count _path) < 3 }) exitWith {};

private _group = _display displayCtrl 4703;
private _list = _group controlsGroupCtrl 106;
lnbClear _list;

private _crimes = _warrants tvData _path;
if (_crimes isEqualTo "") exitWith {};
(parseSimpleArray _crimes) params [ "_configName", "_crimes" ];

_crimes = createHashMapFromArray _crimes;

// Get crime information...
_path resize 2;
_display setVariable ["act_cfg_name", _warrants tvData _path];
_display setVariable ["crime_cfg_name", _configName];

// Get warrant information...
_path resize 1;
_display setVariable ["warrant_steam_id", _warrants tvData _path];

{
	_y params ["_info", "_date"];
	_date params ["_year", "_month", "_day", "_hour", "_minute"];

	private _row = _list lnbAddRow [
		_info param [0, "System"],
		format ["%1/%2/%3 %4:%5", _year, _month, _day, _hour, _minute]
	];
	_list lnbSetData [[_row, 1], _info param [1, "No Note"]];
	_list lnbSetValue [[_row, 0], _x];
} forEach _crimes;