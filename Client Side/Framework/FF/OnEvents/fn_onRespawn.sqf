/*
	@File: fn_onRespawn.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Processes all the stuff that needs handling when we respawn...

	@Parameters:
		0 - TYPE: OBJECT - DES: The object respawning...
		1 - TYPE: OBJECT - DES: Our corpse...
*/
#include "..\..\script_macros.hpp"
params [
	["_unit", objNull, [objNull]],
	["_corpse", objNull, [objNull]]
];

// Corpse Removal...
if !(isNull _corpse) then {
	{deleteVehicle _x;} forEach (nearestObjects [_corpse, ["WeaponHolderSimulated"], 5]);
	deleteVehicle _corpse;
};

// Variable Reset...
_unit setVariable ["restrained",false,true];
_unit setVariable ["Escorting",false,true];
_unit setVariable ["Blindfolded",false,true];
_unit setVariable ["transporting",false,true];
_unit setVariable ["playerSurrender",false,true];
_unit setVariable ["steam64id",getPlayerUID player,true];
_unit setVariable ["realname",profileName,true];
_unit setVariable ["isKnckedOut", false, true];

[_unit,life_settings_enableSidechannel,playerSide] remoteExecCall ["TON_fnc_managesc",RSERV]; // Reset Channels...

if (LIFE_SETTINGS(getNumber,"enable_fatigue") isEqualTo 0) then { player enableFatigue false }; // Reset Fatigue...

[] call FF(setupActions);
[] spawn FF(respawned);