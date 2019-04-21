/*
	@File: fn_onReived.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Called when a medic has revived me...
*/
#include "..\..\script_macros.hpp"
if !(params [["_medic", objNull, [objNull]]]) exitWith {};

hint format ["%1 has revived you and a fee of $%2 was taken from your bank account for their services.",
	_medic getVariable ["realname", name _medic],
	[_reviveCost] call life_fnc_numberText
];

// Unset Incapacitated Varaibles...
player setUnconscious false;
unsetKiller(player);
unsetDowned(player);

player playMoveNow "amovppnemstpsraswrfldnon"; // Get out of the incapacitated animation...

("FF_Incapacitated" call BIS_fnc_RscLayer) cutText ["","PLAIN"]; // Remove Incap UI...
{ppEffectDestroy _x} forEach FF_effects; // Remove Effects...
FF_canRespawn = false; // Default it...
life_action_inUse = false; // Default it...

// Show the HUD again...
FF_hideHUD = false;
[] call FF_fnc_hudUpdate;

// Notify the server...
[0, format ["%1 was revived by %2", 
	player getVariable ["realname", name player], 
	_medic getVariable ["realname", name _medic]
]] remoteExecCall ["life_fnc_broadcast", RCLIENT];

[] call FF(playerSkins);
[] call SOCK_fnc_updateRequest;