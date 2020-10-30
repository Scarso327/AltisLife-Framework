#include "..\..\script_macros.hpp"
/*
    File: fn_adminCamera.sqf
    Author: Lewis Mackinnon
*/

if (FETCH_CONST(life_adminlevel) < 2) exitWith {closeDialog 0; hint "Your staff position is not high enough.";};
[] spawn BIS_fnc_camera;

if (FETCH_CONST(life_adminlevel) > 0) then {
    hint format ["<t color = '#7300e6'>%1</t> has entered the camera.",player getVariable ["realname", name player]];
};