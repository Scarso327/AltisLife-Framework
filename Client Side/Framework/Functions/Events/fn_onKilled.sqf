/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onKilled";

_this params [
	["_unit", objNull, [objNull]],
	["_killer", objNull, [objNull]]
];

if (isNull _unit || { !(isPlayer _unit) }) exitWith {}; // Checks...

if !(isNull objectParent _unit) then { moveOut _unit }; // Move them out of any vehicles they may be in...

[] spawn ULP_UI_fnc_closeDialogs; // Makes sure all dialogs are closed...

if ([] call ULP_UI_fnc_isProgress) then {
	[(["RscProgress"] call ULP_UI_fnc_getLayer), false] call ULP_UI_endProgress;
};

// Notify the server...
if (!isNull _killer && { isPlayer _killer } && { !(_killer isEqualTo _unit) }) then {	
	[format ["%1 was executed by %2", 
		_unit getVariable ["realname", name _unit], 
		_killer getVariable ["realname", name _killer]
	]] remoteExecCall ["systemChat", RCLIENT];

	// TODO : Add crime to killer...
} else {
	[format ["%1 bled out...", 
		_unit getVariable ["realname", name _unit]
	]] remoteExecCall ["systemChat", RCLIENT];
};

// Weapon Removal...
_unit removeWeapon (primaryWeapon _unit);
_unit removeWeapon (handgunWeapon _unit);
_unit removeWeapon (secondaryWeapon _unit);
{deleteVehicle _x;} forEach (nearestObjects [_unit, ["WeaponHolderSimulated"], 5]);

// TODO : Drop Money & Items and Default Death Related Variables...

// Close bleedout script...
if !(isNil { uiNamespace getVariable "_fnc_bleedout" }) then {
	[uiNamespace getVariable "_fnc_bleedout"] call ULP_fnc_removeEachFrame;
	uiNamespace setVariable ["_fnc_bleedout", nil];
};

// Death Screen...
["RscIncapacitated"] call ULP_UI_fnc_destroyLayer;
"WaitToRespawn" cutText ["<t color='#ffffff' font='PuristaLight' size='2px'>YOU HAVE DIED</t>", "BLACK", -1, false, true];

[getPos _unit] call ULP_fnc_addNLR;

ULP_Respawned = false;
ULP_CanRespawn = nil;

[ { ULP_Respawned }, [], {
	uiNamespace setVariable ["IncapacitatedEffect", nil];
	[] call ULP_fnc_wipeEffects;

	"WaitToRespawn" cutText ["", "PLAIN"];
	[] call ULP_fnc_resetSurvival;
	[] call ULP_fnc_spawnMenu;
} ] call ULP_fnc_waitUntilExecute;