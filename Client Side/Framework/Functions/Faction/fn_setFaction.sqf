/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_setFaction";

_this params [
	["_object", objNull, [objNull]],
	["_faction", "", [""]],
	["_mustBeLocal", false, [true]]
];

if (isNull _object) exitWith {};
if (_mustBeLocal && { !local _object }) exitWith {};
if (!isClass (missionConfigFile >> "CfgFactions" >> _faction)) exitWith {};

_object setVariable ["faction", _faction, true];