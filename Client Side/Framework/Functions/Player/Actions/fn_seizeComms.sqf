/*
** Author: Lewis Mackinnon
** Description: Removes a player's communications and alerts both parties.
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_seizeComms";

_this params [
	["_unit", player, [objNull]]
];

if (isNull _unit) exitWith {};

{
	if (_x in getArray (missionConfigFile >> "CfgSettings" >> "communicationDevices")) then {
    	_unit unassignItem _x;
    	_unit removeItem _x;
  	};
} forEach (assignedItems _unit + items _unit);

if !(_unit isEqualTo player) then {
	["You have destroyed this person's communications..."] call ULP_fnc_hint;
	["SeizedComms"] call ULP_fnc_achieve;
};

if (local _unit) then {
	["CommunicationsSeized", [player]] call ULP_fnc_invokeEvent;
} else {
	["CommunicationsSeized", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

[getPlayerUID player, "SeizedComms", [_unit]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];