/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_alliances";

_display = _this;
if (isNull _display) exitWith {};

private _listHeader = _display displayCtrl 23101;
private _list = _display displayCtrl 23102;
lnbClear _list;

if !(_listHeader getVariable ["setup", false]) then {
	[_listHeader, _list, [0]] call BIS_fnc_initListNBoxSorting;
	_listHeader getVariable ["setup", true];
};

private _alliances = + ((group player) getVariable ["group_alliances", createHashMap]);

{
	private _item = _list lnbAddRow [
		_y
	];

	_list lnbSetValue [[_item, 0], _x];
} forEach _alliances;

_list lnbSetCurSelRow 0;

if !(isNil { _display getVariable "AllianceStartedEventHandler" }) exitWith {};

_display setVariable ["AllianceStartedEventHandler", (["GroupAllianceStarted", {
	private _display = findDisplay 23000;
	private _toolbox = _display displayCtrl 23061;

	if (isNull _display || { !((lbCurSel _toolbox) isEqualTo 2) }) exitWith {
		["GroupAllianceStarted", _x] call ULP_fnc_removeEventHandler;
	};
	
	_display setVariable ["alliance_processing", nil];
	_display call ULP_fnc_alliances;
}] call ULP_fnc_addEventHandler)];

_display setVariable ["AllianceEndedEventHandler", (["GroupAllianceEnded", {
	private _display = findDisplay 23000;
	private _toolbox = _display displayCtrl 23061;

	if (isNull _display || { !((lbCurSel _toolbox) isEqualTo 2) }) exitWith {
		["GroupAllianceEnded", _x] call ULP_fnc_removeEventHandler;
	};

	_display setVariable ["alliance_processing", nil];
	_display call ULP_fnc_alliances;
}] call ULP_fnc_addEventHandler)];