/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_clothingStore";

_this params [
	["_store", "", [""]]
];

private _storeCfg = missionConfigFile >> "CfgClothesStore" >> _store;
if !(isClass (_storeCfg)) exitWith {};

if (createDialog "RscGenericStore") then {
	uiNamespace setVariable ["curStore", _storeCfg];

	private _display = findDisplay 3100;

	if (isNull _display) exitWith {};

	ctrlSetText [3101, getText(_storeCfg >> "storeName")];

	uiNamespace setVariable ["cartValue", 0];

	private _toolBox = _display displayCtrl 3102;
	[_toolBox, 0] call ULP_fnc_switchCategory;
	_toolBox ctrlSetEventHandler ["ToolboxSelChanged", "_this call ULP_fnc_switchCategory"];

	(_display displayCtrl 3105) ctrlSetStructuredText parseText "<t size='0.8'>Select and start adding items to your cart to begin...</t>";

	// Item Actions...
	(_display displayCtrl 3103) ctrlSetEventHandler ["LBSelChanged", "_this call ULP_fnc_onItemClick"];
	(_display displayCtrl 3106) ctrlSetEventHandler ["LBSelChanged", "_this call ULP_fnc_onTextureSwitch"];

	// Cart Actions..
	(_display displayCtrl 3108) ctrlSetEventHandler ["ButtonClick", "[] call ULP_fnc_addCart"];
	(_display displayCtrl 3107) ctrlSetEventHandler ["LBDblClick", "_this call ULP_fnc_removeCart"];
	(_display displayCtrl 3110) ctrlSetEventHandler ["ButtonClick", "_this spawn ULP_fnc_buyClothes"];

	private _invToolBox = _display displayCtrl 3111;
	[_invToolBox, 0] call ULP_fnc_switchInventory;
	_invToolBox ctrlSetEventHandler ["ToolboxSelChanged", "_this call ULP_fnc_switchInventory"];
};