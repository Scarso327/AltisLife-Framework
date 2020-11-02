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
    ["_yItems", []],
    ["_textures", []]
];

player setUnitLoadout _pItems;

[player, uniformContainer player, _textures select 0] call ULP_fnc_setTextures;
[unitBackpack player, backpackContainer player, _textures select 1, true] call ULP_fnc_setTextures;

life_maxWeight = ([LIFE_SETTINGS(getNumber,"total_maxWeight"), LIFE_SETTINGS(getNumber,"total_maxWeight") + round(FETCH_CONFIG2(getNumber,"CfgVehicles",(backpack player),"maximumload") / 4)] select ((backpack player) isEqualTo ""));

{
    [true, (_x select 0), (_x select 1)] call life_fnc_handleInv;
} forEach _yItems;