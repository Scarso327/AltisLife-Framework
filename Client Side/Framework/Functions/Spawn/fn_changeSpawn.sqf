/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_changeSpawn";

_this params [
	"_list",
	"_index",
	["_time", 1, [0]]
];

private _display = ctrlParent _list;
if (isNull _display) exitWith {};

private _selected = _list lbData _index;

if !(_selected isEqualTo "") then {
	private _cfg = missionConfigFile >> "CfgSpawns" >> worldName >> _selected;
	_display setVariable ["spawn", _cfg];

	[(_display displayCtrl 3001), [_time, 0.05, getMarkerPos getText(_cfg >> "marker")]] call ULP_UI_fnc_setMapPosition;
};