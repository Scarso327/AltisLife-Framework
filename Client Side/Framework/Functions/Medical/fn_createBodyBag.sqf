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
if ((count _items) isEqualTo 0) exitWith { false };

private _safePos = [_pos, 0.5, 3] call BIS_fnc_findSafePos;
_safePos set [2, 0];

private _bodyBag = createSimpleObject ["Land_Bodybag_01_black_F", AGLtoASL _safePos];
_bodyBag setDir _dir;

{
    [_bodyBag, _x, _y, true, true] call ULP_fnc_addToCargo;
} forEach _items;

private _cash = + CASH;

if (_cash > 0 && { [_cash, false, "Died"] call ULP_fnc_removeMoney }) then {
	[_bodyBag, "DroppedMoney", [str _cash], true, true] call ULP_fnc_addToCargo;
};

true