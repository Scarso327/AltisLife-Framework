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

{
	private _cfg = missionConfigFile >> "CfgBlueprints" >> _x;

	if (isClass _cfg) then {
		private _type = _tree tvAdd [[], _x];
		_tree tvSetData [[_type], configName _cfg];

		{
			private _itemCfg = _cfg >> _x;

			if (isClass _itemCfg) then {
				private _item = _tree tvAdd [[_type], getText (_itemCfg >> "displayName")];
				_tree tvSetData [[_type, _item], configName _itemCfg];
				_tree tvSetPicture [[_type, _item], getText (_itemCfg >> "icon")];
			};
		} forEach _y;
	};
} forEach ULP_Blueprints;

_tree tvSetCurSel [0,0];
[_tree, [0,0]] call ULP_fnc_bpLbChange;