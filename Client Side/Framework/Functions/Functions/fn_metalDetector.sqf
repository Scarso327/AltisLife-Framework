/*
** Author: Lewis Mackinnon
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_metalDetector";

if (this && weapons player !(isEqualTo) []) then {
    [this, "metalDetector", 50, 1] remoteExecCall ["ULP_fnc_say3D"];
};