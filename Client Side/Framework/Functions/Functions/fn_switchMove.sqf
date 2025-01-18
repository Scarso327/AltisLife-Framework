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

if !(isRemoteExecuted) then {
	[_unit, _move] remoteExecCall ["ULP_fnc_switchMove", -clientOwner];
};

true