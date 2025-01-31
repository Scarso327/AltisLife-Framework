/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_groupPermissions";

private _defaultPermissions = createHashMapFromArray (configProperties [missionConfigFile >> "CfgGroups" >> "Permissions", "isNumber (_x)", false] apply { 
	[configName _x, getNumber _x] 
});

((_this param [0, group player, [grpNull]]) getVariable ["group_permissions", _defaultPermissions])