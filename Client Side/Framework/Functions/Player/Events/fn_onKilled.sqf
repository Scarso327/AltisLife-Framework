/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onKilled";

_this params [
	["_unit", objNull, [objNull]],
	["_killer", objNull, [objNull]]
];

if (isNull _unit || { !(isPlayer _unit) }) exitWith {}; // Checks...

if !(isNull objectParent _unit) then { moveOut _unit }; // Move them out of any vehicles they may be in...

// Notify the server...
if (!isNull _killer && { isPlayer _killer } && { !(_killer isEqualTo _unit) }) then {
	[0, format ["%1 was executed by %2", 
		_unit getVariable ["realname", name _unit], 
		_killer getVariable ["realname", name _killer]
	]] remoteExecCall ["life_fnc_broadcast", RCLIENT];

	// TODO : Add crime to killer...
} else {
	[0, format ["%1 bled out...", 
		_unit getVariable ["realname", name _unit]
	]] remoteExecCall ["life_fnc_broadcast", RCLIENT];
};

// Weapon Removal...
_unit removeWeapon (primaryWeapon _unit);
_unit removeWeapon (handgunWeapon _unit);
_unit removeWeapon (secondaryWeapon _unit);
{deleteVehicle _x;} forEach (nearestObjects [_unit, ["WeaponHolderSimulated"], 5]);

// TODO : Drop Money & Items and Default Death Related Variables...

// Close bleedout script...
if !(isNil { uiNamespace getVariable "_fnc_bleedout" }) then {
	terminate (uiNamespace getVariable "_fnc_bleedout");
	uiNamespace setVariable ["_fnc_bleedout", nil];
};

// Death Screen...
[] spawn {
	["RscIncapacitated"] call ULP_UI_fnc_destroyLayer;
	"WaitToRespawn" cutText ["<t color='#ffffff' font='PuristaLight' size='2px'>YOU HAVE DIED</t>", "BLACK", -1, false, true];

	ULP_Respawned = false;
	ULP_CanRespawn = nil;

	waitUntil { ULP_Respawned };

	uiNamespace setVariable ["IncapacitatedEffect", nil];
	[] call ULP_fnc_wipeEffects;

	"WaitToRespawn" cutText ["", "PLAIN"];
	[] call life_fnc_spawnMenu;
};