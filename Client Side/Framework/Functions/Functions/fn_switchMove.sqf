/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_switchMove";

if !(_this params [
	["_unit", objNull, [objNull]],
	["_move", "", [""]]
]) exitWith { false };

_unit switchMove _move;
[_unit, _move] remoteExec ["switchMove", -clientOwner];

true