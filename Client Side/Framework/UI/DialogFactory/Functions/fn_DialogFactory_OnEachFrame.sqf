/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogFactory_OnEachFrame";

_this params [ "_list" ];

if (isNull _list) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

private _display = ctrlParent _list;
private _ctrlProgress = _display displayCtrl 5506;
private _ctrlText = _display displayCtrl 5507;

private _factory = _display getVariable ["factory", objNull];

private _factoryOrder = _factory getVariable ["product_order", []];

if !(_factoryOrder isEqualTo []) then {
	_factoryOrder params [ "_productCfg", "", "_quantity", "_startTime" ];

	private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> configName _productCfg;

	_ctrlText ctrlSetText format ["Producing %1 %2(s)", _quantity, getText (_itemCfg >> "displayName")];
	_ctrlProgress progressSetPosition ((serverTime - _startTime) / getNumber (_productCfg >> "tickTime"));
} else {
	_ctrlText ctrlSetText "No current order...";
};

private _index = lbCurSel _list;

private _curInv = _factory getVariable ["ULP_VirtualCargo", createHashMap];
private _lastInv = _display getVariable ["lastInventory", createHashMap];

if (!(_index isEqualTo -1) && { !(_curInv isEqualTo _lastInv) }) then {
	_display setVariable ["lastInventory", _curInv];

	[_list, _index] call ULP_UI_fnc_DialogFactory_OnListChanged;
};