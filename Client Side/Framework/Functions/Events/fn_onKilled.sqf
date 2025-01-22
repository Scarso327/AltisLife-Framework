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

if ([] call ULP_fnc_isEscorting) then {
	detach ULP_Escort;
	ULP_Escort = nil;
};

// Weapon Removal...
_unit removeWeapon (primaryWeapon _unit);
_unit removeWeapon (handgunWeapon _unit);
_unit removeWeapon (secondaryWeapon _unit);
{deleteVehicle _x;} forEach (nearestObjects [_unit, ["WeaponHolderSimulated"], 5]);

[getPos _unit] call ULP_fnc_dropMoney;
[getPos _unit, getDir _unit] call ULP_fnc_createBodyBag;

ULP_Inventory = createHashMap; // Wipe Inventory...
ULP_CarryInfo set [0, 0];
[true] call ULP_fnc_saveGear;

// Death Screen...
["RscIncapacitated"] call ULP_UI_fnc_destroyLayer;
"WaitToRespawn" cutText ["<t color='#ffffff' font='PuristaLight' size='2px'>YOU HAVE DIED</t>", "BLACK", -1, false, true];

[getPos _unit] call ULP_fnc_addNLR;

ULP_Respawned = false;
ULP_CanRespawn = nil;

player setVariable ["IncapacitatedWounds", nil, true];
player setVariable ["IncapacitatedByGroup", nil, true];
player setVariable ["AssignedMedic", nil, true];

["Died", [_unit, _killer], true] call ULP_fnc_invokeEvent;

[ { ULP_Respawned }, [], {
	[] call ULP_fnc_wipeEffects;

	"WaitToRespawn" cutText ["", "PLAIN"];
	[] call ULP_fnc_resetSurvival;
	[] call ULP_fnc_spawnMenu;
} ] call ULP_fnc_waitUntilExecute;