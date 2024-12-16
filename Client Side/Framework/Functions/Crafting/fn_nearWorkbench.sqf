/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_nearWorkbench";

(count ((player nearObjects 5) select { (typeOf _x) isEqualTo "Land_Workbench_01_F" }) > 0)