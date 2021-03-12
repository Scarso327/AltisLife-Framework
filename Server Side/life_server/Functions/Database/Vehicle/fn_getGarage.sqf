/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getGarage";

_this params [
	["_steamid", "", [""]],
	["_faction", "", [""]],
	["_types", ["Car", "Air", "Ship"], [[]]]
];

private _vehicles = [];

if !(_steamid isEqualTo "" && { isClass (missionConfigFile >> "CfgFactions" >> _faction) } || { _types isEqualTo [] }) then {
	_types = (_types apply {
		format["'%1'", _x]
	}) joinString ", ";

	private _query = [format["SELECT id, classname, type, texture FROM vehicles WHERE `type` IN (%1) AND pid='%2' AND faction='%3' AND active='0' AND sold='0'",
		_types, _steamid, _faction
	], 2, true] call DB_fnc_asyncCall;

	if !(_query isEqualTo "" || { _query isEqualTo [] }) then {
		_vehicles = _query;
	};
};

["GarageRetrieved", [_vehicles]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];