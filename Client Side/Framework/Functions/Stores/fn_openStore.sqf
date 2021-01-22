/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openStore";

_this params [
	["_store", "", [""]],
	["_storeCfg", "CfgClothesStore", [""]]
];

private _cfg = missionConfigFile >> _storeCfg;
_storeCfg = _cfg >> _store;
if !(isClass (_storeCfg)) exitWith {};

if (createDialog "RscGenericStore") then {
	uiNamespace setVariable ["curStore", _storeCfg];

	private _display = findDisplay 3100;

	if (isNull _display) exitWith {};

	ctrlSetText [3101, getText(_storeCfg >> "storeName")];

	uiNamespace setVariable ["cartValue", 0];

	private _onLoad = _cfg >> "onLoad";
	if (isText(_onLoad)) then {
		[_display] call compile (getText(_onLoad));
	};

	// Cart Actions..
	(_display displayCtrl 3108) ctrlSetEventHandler ["ButtonClick", "[] call ULP_fnc_addCart"];
	(_display displayCtrl 3107) ctrlSetEventHandler ["LBDblClick", "_this call ULP_fnc_removeCart"];
	(_display displayCtrl 3110) ctrlSetEventHandler ["ButtonClick", "_this spawn ULP_fnc_buyClothes"];

	private _invToolBox = _display displayCtrl 3111;
	[_invToolBox, 0] call ULP_fnc_switchInventory;
	_invToolBox ctrlSetEventHandler ["ToolboxSelChanged", "_this call ULP_fnc_switchInventory"];
};