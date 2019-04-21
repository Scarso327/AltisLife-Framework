/*
	@File: fn_onKilled.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Processes all the stuff that needs handling when we are killed...

	@Parameters:
		0 - TYPE: OBJECT - DES: The object being killed...
		1 - TYPE: OBJECT - DES: The object that killed the object...
*/
#include "..\..\script_macros.hpp"
params [
	["_unit", objNull, [objNull]],
	["_killer", objNull, [objNull]]
];

if !(canSuspend) exitWith { _this spawn FF(onKilled) };

if (isNull _unit) exitWith {}; // What??
if !(isPlayer _unit) exitWith {}; // Only players can be killed...

if !(isNull objectParent _unit) then { moveOut _unit }; // Get them out the vehicle...

// Weapon Removal...
_unit removeWeapon (primaryWeapon _unit);
_unit removeWeapon (handgunWeapon _unit);
_unit removeWeapon (secondaryWeapon _unit);
{deleteVehicle _x;} forEach (nearestObjects [_unit, ["WeaponHolderSimulated"], 5]);

// Notify the server...
if (!isNull _killer && { isPlayer _killer } && { !(_killer isEqualTo _unit) }) then {
	[0, format ["%1 was executed by %2", 
		_unit getVariable ["realname", name _unit], 
		_killer getVariable ["realname", name _killer]
	]] remoteExecCall ["life_fnc_broadcast", RCLIENT];

	[getPlayerUID _killer,_killer getVariable ["realname",name _killer],"187"] remoteExecCall ["life_fnc_wantedAdd",RSERV]; // Add Killer...
} else {
	[0, format ["%1 bled out...", 
		_unit getVariable ["realname", name _unit]
	]] remoteExecCall ["life_fnc_broadcast", RCLIENT];
};

// Variable Rest Time...
_unit setUnconscious false;
_unit setVariable ["restrained",false,true];
_unit setVariable ["Escorting",false,true];
_unit setVariable ["transporting",false,true];
_unit setVariable ["playerSurrender",false,true];
unsetKiller(_unit);
unsetDowned(_unit);

[_unit] call life_fnc_dropItems; // Force Drop Items...

[player,life_settings_enableSidechannel,playerSide] remoteExecCall ["TON_fnc_managesc",RSERV]; // Rest Channels...

[] spawn {
	("FF_Incapacitated" call BIS_fnc_RscLayer) cutText ["","PLAIN"]; // Remove Incap UI...
	{ppEffectDestroy _x} forEach FF_effects; // Remove Effects...
	FF_canRespawn = false; // Default it...
	
	"WaitToRespawn" cutText ["<t color='#ffffff' font='PuristaLight' size='2px'>YOU HAVE DIED</t>", "BLACK", -1, false, true];

	life_respawned = false;

	waitUntil {life_respawned};
	"WaitToRespawn" cutText ["", "PLAIN"];
	
	// Show the HUD again...
	FF_hideHUD = true;
	[] call FF_fnc_hudUpdate;
};