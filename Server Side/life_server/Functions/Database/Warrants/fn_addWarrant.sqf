/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addWarrant";

_this params [
	["_pid", "", [""]],
	["_act", "", [""]],
	["_crime", "", [""]],
	["_note", "", [""]],
	["_handler", "System", [""]]
];

private _cfg = missionConfigFile >> "CfgWarrants" >> _act >> _crime;
if (_pid isEqualTo "" || { !(isClass _cfg) }) exitWith { false };

[format[
	"INSERT INTO `warrants` (`pid`, `act`, `crime`, `info`) VALUES ('%1', '%2', '%3', '%4');", 
	_pid, _act, _crime, [[_handler, _note]] call DB_fnc_mresArray
], 1] call DB_fnc_asyncCall;
true