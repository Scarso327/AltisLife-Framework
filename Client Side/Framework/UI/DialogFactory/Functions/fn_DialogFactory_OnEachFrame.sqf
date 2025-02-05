/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogFactory_OnEachFrame";

_this params [ "_list" ];

if (isNull _list) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

private _display = ctrlParent _list;
private _factory = _display getVariable ["factory", objNull];

private _index = lbCurSel _list;

private _curInv = _factory getVariable ["ULP_VirtualCargo", createHashMap];
private _lastInv = _display getVariable ["lastInventory", createHashMap];

if (!(_index isEqualTo -1) && { !(_curInv isEqualTo _lastInv) }) then {
	_display setVariable ["lastInventory", _curInv];

	[_list, _index] call ULP_UI_fnc_DialogFactory_OnListChanged;
};