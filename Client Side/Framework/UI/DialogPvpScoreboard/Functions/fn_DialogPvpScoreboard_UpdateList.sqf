/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogPvpScoreboard_UpdateList";

_this params [ "_display" ];

if (isNull _display) exitWith {};

private _filter = _display displayCtrl 6404;
private _list = _display displayCtrl 6406;
lnbClear _list;

[_filter, _list] call BIS_fnc_initListNBoxSorting;

private _scores = + ULP_SRV_CurrentScores;

{
	private _group = [_x] call ULP_fnc_getGroupById;

	private _row = _list lnbAddRow [
		[_group] call ULP_fnc_getGroupName, 
		[_y] call ULP_fnc_numberText
	];

	_list lnbSetData [[_row, 0], _x];
	_list lnbSetValue [[_row, 1], _y];
} forEach _scores;

_display setVariable ["lastList", _scores];

[_list, 1, false] call BIS_fnc_sortListNBox;