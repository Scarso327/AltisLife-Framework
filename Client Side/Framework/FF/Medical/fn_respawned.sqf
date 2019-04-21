/*
	@File: fn_respawned.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Resetting player before respawn....
*/
#include "..\..\script_macros.hpp"

// Rest Variables...
life_action_inUse = false;
life_use_atm = true;
life_hunger = 100;
life_thirst = 100;
life_carryWeight = 0;
CASH = 0;

life_respawned = true;

player playMove "AmovPercMstpSnonWnonDnon";

// Set Loadout...
private "_handle";
switch (playerSide) do
{
    case west: {
        _handle = [] spawn LIFE(copLoadout);
    };
    case civilian: {
        _handle = [] spawn LIFE(civLoadout);
    };
    case independent: {
        _handle = [] spawn LIFE(medicLoadout);
    };
    waitUntil {scriptDone _handle};
};

// JAIL THE CUNT
if (life_is_arrested) exitWith {
    hint "Respawning in jail will reset your time!";
    life_is_arrested = false;
    [player,true] spawn LIFE(jail);
    [] call DB(updateRequest);
};

// Wanted Reward!
if !(isNil "life_copRecieve") then {
    [getPlayerUID player,player,life_copRecieve,true] remoteExecCall ["life_fnc_wantedBounty",RSERV];
    life_copRecieve = nil;
};

// Wanted Removal...
if (life_removeWanted) then {
    [getPlayerUID player] remoteExecCall ["life_fnc_wantedRemove",RSERV];
};

// Show the HUD again...
FF_hideHUD = false;
[] call FF_fnc_hudUpdate;

[] call DB(updateRequest);
[] spawn LIFE(spawnMenu);