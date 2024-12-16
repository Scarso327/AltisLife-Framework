/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_licenses";

_display = _this;
if (isNull _display) exitWith {};

private _list = _display displayCtrl 23016;
private _info = _display displayCtrl 23017;
private _item = -1;

lbClear _list;

{
	private _cfg = missionConfigFile >> "CfgLicenses" >> _x;

	if (isClass _cfg) then {
		_item = _list lbAdd format ["%1", getText(_cfg >> "displayName")];
		_list lbSetData [_item, _x];
	};
} forEach ULP_Licenses;

if ((lbSize _list) > 0) then {
	_list lbSetCurSel 0;
} else {
	_list lbAdd "No Licenses...";
	_info ctrlSetStructuredText parseText "";
	[_info] call ULP_UI_fnc_setToTextHeight;
};

_display setVariable ["cfg", "CfgLicenses"];

[_list, 0] call ULP_fnc_invLbChange;