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
	uiNamespace setVariable ["storeCfg", _cfg];
	uiNamespace setVariable ["curStore", _storeCfg];

	private _display = findDisplay 3100;

	if (isNull _display) exitWith {};

	private _idc = getNumber(_cfg >> "toolBoxIDC");

	// Hide toolboxes that aren't used by this store...
	// I use thius method as I couldn't get the pictures to update.
	{
		ctrlShow [_x, false];
	} forEach ([3102, 3113] select { !(_x isEqualTo _idc) });

	ctrlSetText [3101, getText(_storeCfg >> "storeName")];

	uiNamespace setVariable ["cartValue", 0];

	private _toolBox = _display displayCtrl _idc;
	[_toolBox, 0] call ULP_fnc_switchCategory;
	_toolBox ctrlSetEventHandler ["ToolboxSelChanged", "_this call ULP_fnc_switchCategory"];

	private _onLoad = _cfg >> "onLoad";
	if (isText(_onLoad)) then {
		[_display] call compile (getText(_onLoad));
	};

	(_display displayCtrl 3103) ctrlSetEventHandler ["LBSelChanged", "_this call ULP_fnc_onItemClick"];

	// Cart Actions..
	(_display displayCtrl 3108) ctrlSetEventHandler ["ButtonClick", "[] call ULP_fnc_addCart"];
	(_display displayCtrl 3107) ctrlSetEventHandler ["LBDblClick", "_this call ULP_fnc_removeCart"];
	(_display displayCtrl 3110) ctrlSetEventHandler ["ButtonClick", "_this spawn ULP_fnc_buyClothes"];

	private _invToolBox = _display displayCtrl 3111;
	[_invToolBox, 0] call ULP_fnc_switchInventory;
	_invToolBox ctrlSetEventHandler ["ToolboxSelChanged", "_this call ULP_fnc_switchInventory"];
};