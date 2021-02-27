/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_removeItem";

_this params [
	"_ctrl"
];

disableSerialization;

private _display = ctrlParent _ctrl;
private _list = _display displayCtrl 23016;
if (isNull _display || { isNull _list }) exitWith {};

private _list = _display displayCtrl 23016;
private _curSel = missionConfigFile >> "CfgVirtualItems" >> (_list lbData (lbCurSel _list));
if !(isClass _curSel) exitWith { hint "You need to select an item first..."; };

private _amount = [configName _curSel] call ULP_fnc_hasItem;
if (_amount isEqualTo -1) exitWith {
	hint "You don't have any of these items to remove...";
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_curSel],
	{
		_this params [
			["_cfg", configNull, [configNull]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		_display = findDisplay 23000; // We don't need select so we switch this to tablet...
		if (isNull _display || { isNull _cfg }) exitWith {};

		if ([configName _cfg, _value, true] call ULP_fnc_handleItem) then {
			hint format["You have removed %1 %2(s) from your inventory...", _value, getText(_cfg >> "displayName")];
			_display call ULP_fnc_inventory;
		} else {
			hint "You don't have that many of this item...";
		};
	}
] call ULP_fnc_selectNumber;