/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_loadGear";

_this params [
    ["_itemArray", ULP_Gear, [[]]]
];

[] call ULP_fnc_stripGear;

if (_itemArray isEqualTo []) exitWith { [] call ULP_fnc_setLoadout };

_itemArray params [
    ["_pItems", []],
    ["_yItems", []],
    ["_textures", []]
];

player setUnitLoadout _pItems;

[player, uniformContainer player, _textures select 0] call ULP_fnc_setTextures;
[unitBackpack player, backpackContainer player, _textures select 1] call ULP_fnc_setTextures;

ULP_CarryInfo set [1, ([LIFE_SETTINGS(getNumber,"total_maxWeight"), LIFE_SETTINGS(getNumber,"total_maxWeight") + round(FETCH_CONFIG2(getNumber,"CfgVehicles",(backpack player),"maximumload") / 4)] select ((backpack player) isEqualTo ""))];

{ [(_x select 0), (_x select 1), false, true] call ULP_fnc_handleItem } count _yItems;