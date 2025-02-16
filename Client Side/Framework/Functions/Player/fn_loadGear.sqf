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

_textures params [
    ["_uniform", "", [""]], ["_backpack", "", [""]]
];

if !(_uniform isEqualTo "") then {
    ULP_UniformTexture = _uniform;
    [player, uniform player, uniformContainer player, _uniform] call ULP_fnc_setTextures
};

if !(_backpack isEqualTo "") then {
    ULP_BackpackTexture = _backpack;
    [unitBackpack player, typeOf (unitBackpack player), backpackContainer player, _backpack] call ULP_fnc_setTextures;
} else {
    [] call ULP_fnc_setHideBackpack;
};

{ [(_x select 0), (_x select 1), false, true] call ULP_fnc_handleItem } count _yItems;