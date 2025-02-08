/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onRespawn";

_this params [
	["_unit", objNull, [objNull]],
	["_corpse", objNull, [objNull]]
];

// Corpse & Weapon Removal...
if !(isNull _corpse) then {
	{ deleteVehicle _x } forEach (nearestObjects [_corpse, ["WeaponHolderSimulated"], 5]);
	deleteVehicle _corpse;
};

_unit setUnconscious false;
unsetKiller(_unit);
unsetDowned(_unit);

// Handle creation of "new life"...
ULP_Respawned = true;

player playMove "AmovPercMstpSnonWnonDnon";

if ([["SideChat", "HUD"] call ULP_fnc_getOption] call ULP_fnc_bool) then {
	[_unit] remoteExecCall ["ULP_SRV_fnc_setSideChannel", RSERV];
};

[] call ULP_fnc_setLoadout;
[] call ULP_fnc_syncPlayerInfo;