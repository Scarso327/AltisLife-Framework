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

// Ensure it's had a chance to apply the uniform before texturing...
[ 1, [_pItems, _textures], {
    _this params [
        "_items", "_textures"
    ];

    _textures params [
        "_uniform", "_backpack"
    ];

    if !(_uniform isEqualTo "") then {
        [{ (uniform player) isEqualTo (_this select 0) }, [((_items param [3, []]) param [0, ""]), _uniform], {
            [player, uniformContainer player, (_this select 1)] call ULP_fnc_setTextures;
        }] call ULP_fnc_waitUntilExecute;
    };

    if !(_backpack isEqualTo "") then {
        [{ (backpack player) isEqualTo (_this select 0) }, [((_items param [5, []]) param [0, ""]), _backpack], {
            [unitBackpack player, backpackContainer player, (_this select 1)] call ULP_fnc_setTextures;
        }] call ULP_fnc_waitUntilExecute;
    };
}] call ULP_fnc_waitExecute;

ULP_CarryInfo set [1, ([LIFE_SETTINGS(getNumber,"total_maxWeight"), LIFE_SETTINGS(getNumber,"total_maxWeight") + round(getNumber(configFile >> "CfgVehicles" >> (backpack player) >> "maximumload") / 4)] select ((backpack player) isEqualTo ""))];

{ [(_x select 0), (_x select 1), false, true] call ULP_fnc_handleItem } count _yItems;