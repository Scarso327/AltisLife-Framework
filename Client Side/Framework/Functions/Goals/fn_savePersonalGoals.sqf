/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_savePersonalGoals";

if (canSuspend) exitWith {
    [ULP_fnc_savePersonalGoals, _this] call ULP_fnc_directCall;
};

private _save = [[], []];

{
	private _index = _forEachIndex;
	{
		private _arr = _save select _index;
		{ _arr pushBack (_x select [0, 2]); } forEach _y;
		_save set [_index, _arr];
	} forEach (missionNamespace getVariable [format["ULP_Goals_%1", _x], createHashMap]);
} forEach ["Daily", "Weekly"];

[player, 8, _save] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];