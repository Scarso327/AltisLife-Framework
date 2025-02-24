/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getStats";

_this params [
	["_unit", objNull, [objNull]],
	["_events", [], [[]]]
];

if (isNull _unit || { _events isEqualTo [] }) exitWith {};

private _season = missionNamespace getVariable ["ULP_SRV_Setting_Season", 1];

private _result = [];

{
	private _query = [format[getText (configFile >> "CfgPatches" >> "ULPServer" >> "Stats" >> _x >> "query"), _season, getPlayerUID _unit], 2] call DB_fnc_asyncCall;
	_result pushBack [_x, _query param [0, 0]];
} forEach _events;

if (_result isEqualTo []) exitWith {};

["ReceivedStats", _result] remoteExecCall ["ULP_fnc_invokeEvent", _unit];