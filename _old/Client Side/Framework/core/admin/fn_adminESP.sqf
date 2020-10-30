#include "..\..\script_macros.hpp"
/*
    File: fn_adminESP.sqf
    Author: Lewis Mackinnon
*/

params [
    ["_reOpen", false, [false]]
];

if (FETCH_CONST(life_adminlevel) < 2) exitWith {closeDialog 0; hint "Your staff position is not high enough.";};

if (admin_esp) then {

};