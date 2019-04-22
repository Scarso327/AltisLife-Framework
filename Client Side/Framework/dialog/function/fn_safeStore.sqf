#include "..\..\script_macros.hpp"
/*
    File: fn_safeStore.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Gateway copy of fn_vehStoreItem but designed for the safe.
*/
private ["_ctrl","_num"];
disableSerialization;
_ctrl = CONTROL_DATA(3503);
_num = ctrlText 3506;

//Error checks
if (!([_num] call TON_fnc_isnumber)) exitWith {hint localize "STR_MISC_WrongNumFormat";};
_num = parseNumber(_num);
if (_num < 1) exitWith {hint "You can't enter anything below 1!";};
if (!(_ctrl isEqualTo "branded_gold_bar")) exitWith {hint "You can't store anything but gold bars in the safe."};
if (_num > life_inv_branded_gold_bar) exitWith {hint format ["You don't have %1 gold bars",_num];};

//Store it.
if (!([false,_ctrl,_num] call life_fnc_handleInv)) exitWith {hint "Couldn't remove the items from your inventory to put in the safe.";};
_safeInfo = life_safeObj getVariable ["safe",0];
life_safeObj getVariable ["safe",_safeInfo + _num,true];

[life_safeObj] call life_fnc_safeInventory;
