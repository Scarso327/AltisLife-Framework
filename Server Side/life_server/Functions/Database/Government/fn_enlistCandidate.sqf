/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_enlistCandidate";

_this params [
	["_candidate", objNull, [objNull]]
];

if (isNull _candidate) exitWith { false };

if !([group _candidate] call ULP_fnc_isGroup || { ["Governor", group _candidate] call ULP_fnc_hasGroupPerk }) exitWith {
	["Enlistment", ["Your group doesn't have the ability to run for governor..."]] remoteExecCall ["ULP_fnc_invokeEvent", _candidate];
};

private _steamid = getPlayerUID _candidate;

if !(([format["SELECT * FROM `candidates` WHERE `pid` = '%1'", _steamid], 2] call DB_fnc_asyncCall) isEqualTo []) exitWith {
	["Enlistment", ["You're already enlisted for the next general election..."]] remoteExecCall ["ULP_fnc_invokeEvent", _candidate];
};

if (((missionNamespace getVariable ["ULP_SRV_Setting_Governor", []]) param [1, ""]) isEqualTo _steamid) exitWith {
	["Enlistment", ["As Governor, you're unable to run in the next election..."]] remoteExecCall ["ULP_fnc_invokeEvent", _candidate];
};

[format["INSERT INTO `candidates` (`pid`, `name`) VALUES ('%1', '%2');", _steamid, [name _candidate] call DB_fnc_mresString], 1] call DB_fnc_asyncCall;
["Enlistment"] remoteExecCall ["ULP_fnc_invokeEvent", _candidate];