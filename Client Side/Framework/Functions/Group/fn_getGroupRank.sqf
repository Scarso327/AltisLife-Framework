/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getGroupRank";

private _unit = _this param [0, player, [objNull, 0]];
if (_unit isEqualType 0) exitWith { _unit };

(rankId _unit)