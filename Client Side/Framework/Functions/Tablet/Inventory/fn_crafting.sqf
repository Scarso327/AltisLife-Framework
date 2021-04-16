/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_crafting";

_display = _this;
if (isNull _display) exitWith {};

private _tree = _display displayCtrl 23077;
private _info = _display displayCtrl 23017;
_info ctrlSetStructuredText parseText "";

tvClear _tree;

private _selected = [];

{
	private _section = ULP_Blueprints getOrDefault [configName _x, []];
	private _type = _tree tvAdd [[], getText (_x >> "displayName")];
	_tree tvSetData [[_type], configName _x];

	{
		if ([getNumber (_x >> "isDefault")] call ULP_fnc_bool || { (configName _x) in _section }) then {
			private _item = _tree tvAdd [[_type], getText (_x >> "displayName")];
			_tree tvSetData [[_type, _item], configName _x];
			_tree tvSetPicture [[_type, _item], getText (_x >> "icon")];

			if (_selected isEqualTo []) then { _selected = [_type, _item]; };
		};
	} forEach ("isClass _x" configClasses (_x));
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgBlueprints"));

_tree tvSetCurSel _selected;
[_tree, _selected] call ULP_fnc_bpLbChange;