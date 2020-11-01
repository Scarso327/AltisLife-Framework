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

ULP_Gear = [(getUnitLoadout player), _yItems];