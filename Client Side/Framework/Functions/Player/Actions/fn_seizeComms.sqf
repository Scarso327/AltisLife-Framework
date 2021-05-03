/*
** Author: Lewis Mackinnon
** Description: 
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

["Your communication devices have been seized! You are no longer permitted to use any communication channel outside of Direct/Vehicle..."] call ULP_fnc_hint;