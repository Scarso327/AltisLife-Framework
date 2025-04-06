/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_castPvpModeVote";

_this params [
	["_unit", objNull, [objNull]],
	["_location", "", [""]]
];

diag_log _this;

private _modes = missionNamespace getVariable ["ULP_SRV_PvpModes", createHashMap];

if (isNull _unit || { !isPlayer _unit } || { _modes isEqualTo createHashMap } || { !(_location in _modes) }) exitWith {};

ULP_SRV_PvpVotes set [getPlayerUID _unit, _location];