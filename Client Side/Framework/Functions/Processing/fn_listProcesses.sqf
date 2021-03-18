/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_listProcesses";

private _display = findDisplay 4000;
private _cfg = _display getVariable ["store", configNull];
if (isNull _cfg) exitWith {};

private _list = _display displayCtrl 4003;
lbClear _list;

{
	private _process = missionConfigFile >> "CfgProcessing" >> _x;

	if (isClass _process) then {
		private _item = _list lbAdd  _x;
		_list lbSetData [_item, _x];
	};
} forEach getArray(_cfg >> "processes");

if ((lbSize _list) isEqualTo 0) then {
	_list lbAdd "No Available Processes...";
};

_list lbSetCurSel 0;