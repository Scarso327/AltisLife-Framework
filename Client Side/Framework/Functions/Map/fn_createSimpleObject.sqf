/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_createSimpleObject";

diag_log _this;

_this params [
	["_model", "", [""]],
	["_pos", [[0,0,0], 0], []],
	["_scale", 1, [0]],
	["_global", true, [false]]
];

_pos params [
	["_xyz", [], [[]]],
	["_dir", 0, [0]]
];

private _object = createSimpleObject [_model, _xyz, !_global];
_xyz vectorAdd [0, 0, ((boundingBoxReal _object) select 0) select 2];
_object setPosASL _xyz;
_object setDir _dir;
_object setObjectScale _scale;

_object