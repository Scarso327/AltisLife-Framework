/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_useItem";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
private _list = _display displayCtrl 23016;
if (isNull _display || { isNull _list }) exitWith {};

private _list = _display displayCtrl 23016;
private _curSel = missionConfigFile >> "CfgVirtualItems" >> (_list lbData (lbCurSel _list));
if !(isClass _curSel) exitWith { hint "You need to select an item first..."; };

private _amount = [configName _curSel] call ULP_fnc_hasItem;
if (_amount isEqualTo -1) exitWith {
	hint "You don't have any of these items to use...";
};

if !(isText (_curSel >> "Events" >> "onUse")) exitWith { hint "This item can't be used to do anything..."; };

if ([configName _curSel, 1, true] call ULP_fnc_handleItem) then {
	[configName _curSel] call compile getText (_curSel >> "Events" >> "onUse");
};

_display call ULP_fnc_inventory;