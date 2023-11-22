/*
** Author: Jack "Scarso" Farhall
** Description: Returns count of all objects placed by a certain player
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isPlaceable";

private _object = _this param [0, objNull, [objNull]];

!(isNull _object && { !(isNil { _object getVariable "object_owner" }) })