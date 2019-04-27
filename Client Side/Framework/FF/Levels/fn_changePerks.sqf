/*
	@File: fn_changePerks.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Handles the changing of our active perks...

	@Parameters:
		0 - TYPE: STRING - DES: The config name for the perk we're changing...
		1 - TYPE: BOOL - DES: True means we're removing, false means we're adding the perk...
*/
scopeName "changePerks";
#include "..\..\script_macros.hpp"
#include "..\GUI\Tablet\macros.hpp"
#define CFG missionConfigFile >> "CfgPerks"
params [
	["_perk", "", [""]],
	["_type", false, [true]]
];

if (_perk isEqualTo "") exitWith { systemChat "Perk is Blank..." }; // What?
if !(isClass (CFG >> _perk)) exitWith { systemChat format["%1 is not a perk...", _perk] }; // Alright then...

private _perkName = getText(CFG >> _perk >> "displayName");

if (_type) then {
	// The type is true, this means we're going to remove a perk...

	private _removalCost = LIFE_SETTINGS(getNumber, "removal_cost");

	// Checks...
	if (BANK < _removalCost) exitWith { hint format["You don't have the required £%1 to remove a perk...", [_removalCost] call LIFE(numberText)]; breakOut "changePerks"; }; // We can't afford the removal cost...
	if !(HAS_PERK(_perk)) exitWith { hint format["The perk %1 is not currently active...", _perkName]; breakOut "changePerks"; }; // Ensure we actually have the perk active...

	FF_Perks deleteAt (FF_Perks findIf { _x isEqualTo _perk }); // Delete at the index of the perk we're removing...
	BANK = BANK - _removalCost; // Take the cost...

	hint format["The perk %1 was succesfully deactivated for a cost of £%2!", _perkName, [_removalCost] call LIFE(numberText)];
} else {
	// The type is false, this means we're going to add the perk...

	private _perkLimit = switch true do {
		case (FF_Level >= 30): {4};
		case (FF_Level >= 20): {3};
		case (FF_Level >= 10): {2};
		default {1};
	};

	// Checks...
	if (HAS_PERK(_perk)) exitWith { hint format["The perk %1 is already active...", _perkName]; breakOut "changePerks"; }; // Ensure we don't already have the perk active...
	if ((count(FF_Perks)) >= _perkLimit) exitWith { hint format["You've already reached your max perk limit of %1", _perkLimit]; breakOut "changePerks"; }; // We already have our max num of active perks...

	FF_Perks pushBackUnique _perk; // Add the perk to our array...
	hint format["The perk %1 was succesfully activated!", _perkName];
};

[] call FF(updatePerks); // Update UI if it's active...

[1] call SOCK_fnc_updatePartial; // Update our bank...
[8] call SOCK_fnc_updatePartial; // Update our perks...