#include "..\..\script_macros.hpp"
/*
    File: fn_onTakeItem.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Blocks the unit from taking something they should not have.
*/
private _unit = [_this,0,objNull,[objNull]] call BIS_fnc_param;
_container = [_this,1,objNull,[objNull]] call BIS_fnc_param;
private _item = [_this,2,"",[""]] call BIS_fnc_param;

if (isNull _unit || _item isEqualTo "") exitWith {}; //Bad thingies?

[] call FF(playerSkins);