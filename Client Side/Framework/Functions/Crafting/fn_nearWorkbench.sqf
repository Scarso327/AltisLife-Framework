/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_nearWorkbench";

(count (nearestObjects[player, ["Land_Workbench_01_F"], 5]) > 0)