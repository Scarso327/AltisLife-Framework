/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_rankName";

private _unit = _this param [0, player, [objNull, 0]];
private _ranks = [group ([_unit, player] select (_unit isEqualType 0))] call ULP_fnc_groupRanks;

(_ranks select ([_unit] call ULP_fnc_getGroupRank))