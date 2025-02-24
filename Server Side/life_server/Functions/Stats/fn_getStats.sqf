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

private _eventQuery = (_events apply { format ["`event` = '%1'", _x] }) joinString " OR ";

private _result = [format["SELECT `event`, `value` FROM `player_stats` WHERE `pid`='%1' AND `season`='%2' AND %3", getPlayerUID _unit, _season, _eventQuery], 2, true] call DB_fnc_asyncCall;
if (_result isEqualType "" || { _result isEqualTo [] }) exitWith {};

["ReceivedStats", _result] remoteExecCall ["ULP_fnc_invokeEvent", _unit];