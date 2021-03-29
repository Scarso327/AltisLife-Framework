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
	if ([_list lbValue _index] call ULP_fnc_bool) then {
		private _house = _selected call BIS_fnc_objectFromNetId;

		if !(isNull _house) then {
			_display setVariable ["spawn", _house];
			[(_display displayCtrl 3001), [_time, 0.05, position _house]] call ULP_UI_fnc_setMapPosition;
		};
	} else {
		private _cfg = missionConfigFile >> "CfgSpawns" >> worldName >> _selected;
		_display setVariable ["spawn", _cfg];

		[(_display displayCtrl 3001), [_time, 0.05, getMarkerPos getText(_cfg >> "marker")]] call ULP_UI_fnc_setMapPosition;
	};
};