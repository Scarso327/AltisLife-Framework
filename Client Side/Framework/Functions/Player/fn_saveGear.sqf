/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_saveGear";

private _yItems = [];

private _savedVirtualItems = LIFE_SETTINGS(getArray,"saved_virtualItems");

{
    _yItems pushBack [_x, _val];
} forEach (_savedVirtualItems select { (ITEM_VALUE(_x)) > 0 });

private _fnc_getCurTexture = {
    _this params ["_container"];

    ([
        (_container getVariable ["texture", ""]),
        ""
    ] select (isNull _container))
};

ULP_Gear = [
    (getUnitLoadout player),
    _yItems,
    [
        [uniformContainer player] call _fnc_getCurTexture,
        [backpackContainer player] call _fnc_getCurTexture
    ]
];