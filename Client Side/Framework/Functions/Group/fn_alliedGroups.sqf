/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_alliedGroups";

private _group = _this param [0, group player, [grpNull]];

private _alliedGroupIds = keys (_group getVariable ["group_alliances", createHashMap]);

(allGroups select { private _groupId = [_x] call ULP_fnc_groupId; !(_alliedGroupIds findIf { _x isEqualTo _groupId } isEqualTo -1) })