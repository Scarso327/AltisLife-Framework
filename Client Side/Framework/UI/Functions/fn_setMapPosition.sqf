/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setMapPosition";

_this params [
    ["_map", controlNull, [controlNull]],
    ["_anim", [], [[]]]
];

_anim params [
    "_time", "_zoom", "_pos"
];

if (isNull _map || { _pos isEqualTo [] }) exitWith {};

_map ctrlMapAnimAdd [_time, _zoom, _pos];
ctrlMapAnimCommit _map;