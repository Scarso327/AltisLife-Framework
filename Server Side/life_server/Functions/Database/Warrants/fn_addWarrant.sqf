/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addWarrant";

_this params [
	["_unit", objNull, [objNull]],
	["_act", "", [""]],
	["_crime", "", [""]],
	["_note", "", [""]],
	["_handler", "System", [""]]
];

private _cfg = missionConfigFile >> "CfgWarrants" >> _act >> _crime;
if (isNull _unit || { !(isClass _cfg) }) exitWith { false };

[format[
	"INSERT INTO `warrants` (`pid`, `act`, `crime`, `info`, `faction`) VALUES ('%1', '%2', '%3', '%4', '%5');", 
	getPlayerUID _unit, _act, _crime, [[[_handler] call DB_fnc_mresString, [_note] call DB_fnc_mresString]] call DB_fnc_mresArray, [_unit] call ULP_fnc_getFaction
], 1] call DB_fnc_asyncCall;
true