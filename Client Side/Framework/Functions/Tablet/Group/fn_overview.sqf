/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_overview";

_display = _this;
if (isNull _display) exitWith {};

private _members = [] call ULP_fnc_groupMembers;

private _listHeader = _display displayCtrl 23063;
private _memberList = _display displayCtrl 23062;
lnbClear _memberList;

if !(_listHeader getVariable ["setup", false]) then {
	[_listHeader, _memberList, [0, 1]] call BIS_fnc_initListNBoxSorting;
	_listHeader getVariable ["setup", true];
};

{
	private _offline = (_forEachIndex isEqualTo 1);

	{
		_y params [
			"_name", "_level"
		];

		private _item = _memberList lnbAddRow [
			_name, 
			[_level] call ULP_fnc_rankName
		];

		_memberList lnbSetData [[_item, 0], _name];
		_memberList lnbSetValue [[_item, 1], _level];

		if (_offline) then {
			_memberList lnbSetColor [[_item, 0], [1, 1, 1, 0.6]];
			_memberList lnbSetColor [[_item, 1], [1, 1, 1, 0.6]];
		};
	} forEach _x;
} forEach _members;