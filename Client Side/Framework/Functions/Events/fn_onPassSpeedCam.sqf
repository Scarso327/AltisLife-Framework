/*
** Author: Lewis Mackinnon
** Description: Auto detect speed and issue warrant
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onPassSpeedCam";

private _limit = getNumber(missionConfigFile >> "CfgSettings" >>"speedLimit");

// Trigger checks for player and that player is in "LandVehicle"
if ([player, ["Civilian"]] call ULP_fnc_isFaction && {(speed (vehicle player)) > _limit}) then {

	// Prevents warrant being added if player has a signal jammer
	if (["signalJammer"] call ULP_fnc_hasItem > 0) exitWith {
		["A speed camera was triggered, but your jammer stopped it transmitting"] call ULP_fnc_hint;
	};

	// Add warrant for speeding
	[getPlayerUID player, "RoadsAct", "Speed", "Triggered a speed camera"] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];
	
	["You triggered a speed camera and been reported for speeding"] call ULP_fnc_hint;
};
