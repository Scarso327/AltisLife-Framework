/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_createBodyBag";

if (canSuspend) exitWith {
    [ULP_fnc_createBodyBag, _this] call ULP_fnc_directCall;
};

if !(_this params [
    ["_pos", [], [[]]],
    ["_dir", 0, [0]]
]) exitWith { false };

private _items = + ULP_Inventory;
if ("Identification" in _items) then { _items deleteAt "Identification"; };
if ((count _items) isEqualTo 0) exitWith { false };

private _bodyBag = createSimpleObject ["Land_Bodybag_01_black_F", AGLtoASL _pos];
_bodyBag setDir _dir;

{
    [_bodyBag, _x, _y, true, true] call ULP_fnc_addToCargo;
} forEach _items;

ULP_Inventory = createHashMap; // Wipe Inventory...
ULP_CarryInfo set [0, 0];
[] call ULP_fnc_saveGear;

true