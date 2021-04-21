/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasComms";

(["ItemGPS", "B_UavTerminal", "O_UavTerminal", "I_UavTerminal", "ItemRadio"] findIf {_x in (assignedItems (_this param [0, player, objNull]))} > -1)