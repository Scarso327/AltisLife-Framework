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
	if (_x in getArray(missionConfigFile >> "CfgSettings" >> "communicationDevices")) then {
    	_unit unassignItem _x;
    	_unit removeItem _x;
  	};
} forEach (assignedItems _unit + items _unit);

if !(_unit isEqualTo player) then {
	["You have seized this person's communications..."] call ULP_fnc_hint;
};

if (local _unit) then {
	["CommunicationsSeized", [player]] call ULP_fnc_envokeEvent;
} else {
	["CommunicationsSeized", [player]] remoteExecCall ["ULP_fnc_envokeEvent", _unit];
};