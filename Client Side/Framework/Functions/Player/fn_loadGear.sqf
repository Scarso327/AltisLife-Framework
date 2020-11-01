/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_loadGear";

_this params [
    ["_itemArray", ULP_Gear, [[]]]
];

[] call life_fnc_stripDownPlayer;

if (_itemArray isEqualTo []) exitWith { [] call life_fnc_startLoadout };

_itemArray params [
    ["_pItems", []],
    ["_yItems", []]
];

player setUnitLoadout _pItems;

life_maxWeight = ([LIFE_SETTINGS(getNumber,"total_maxWeight"), LIFE_SETTINGS(getNumber,"total_maxWeight") + round(FETCH_CONFIG2(getNumber,"CfgVehicles",(backpack player),"maximumload") / 4)] select ((backpack player) isEqualTo ""));

{
    [true, (_x select 0), (_x select 1)] call life_fnc_handleInv;
} forEach _yItems;