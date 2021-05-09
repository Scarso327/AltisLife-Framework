/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasComms";

(getArray (missionConfigFile >> "CfgSettings" >> "communicationDevices") findIf {_x in (assignedItems (_this param [0, player, [objNull]]))} > -1)