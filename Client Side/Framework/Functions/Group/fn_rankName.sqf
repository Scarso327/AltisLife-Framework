/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_rankName";

private _unit = _this param [0, player, [objNull]];
([group _unit] call ULP_fnc_groupRanks select ([_unit] call ULP_fnc_getGroupRank))