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

if (dialog) exitWith {};

private _cfg = missionConfigFile >> "CfgStores" >> _storeCfg;
_storeCfg = _cfg >> _store;
if !(isClass (_storeCfg)) exitWith {};

if (createDialog "DialogGenericStore") then {
	private _display = findDisplay 3100;

	if (isNull _display) exitWith {};

	_display setVariable ["storeCfg", _cfg];
	_display setVariable ["curStore", _storeCfg];

	private _idc = getNumber(_cfg >> "toolBoxIDC");

	// Hide toolboxes that aren't used by this store...
	// I use thius method as I couldn't get the pictures to update.
	{
		ctrlShow [_x, false];
	} forEach ([3102, 3113] select { !(_x isEqualTo _idc) });

	ctrlSetText [3101, getText(_storeCfg >> "storeName")];

	_display setVariable ["cartValue", 0];

	private _toolBox = _display displayCtrl _idc;

	private _openPage = 0;
	if (isNumber (_storeCfg >> "default")) then { _openPage = (getNumber (_storeCfg >> "default") min 4) max 0; };

	_toolBox lbSetCurSel _openPage;
	[_toolBox, _openPage] call ULP_fnc_switchCategory;

	_toolBox ctrlSetEventHandler ["ToolboxSelChanged", "_this call ULP_fnc_switchCategory"];

	(_display displayCtrl 3105) ctrlSetStructuredText parseText "<t size='0.8'>Select and start adding items to your cart to begin...</t>";

	// Item Actions...
	(_display displayCtrl 3106) ctrlSetEventHandler ["LBSelChanged", "_this call ULP_fnc_onTextureSwitch"];
	(_display displayCtrl 3103) ctrlSetEventHandler ["LBSelChanged", "_this call ULP_fnc_onItemClick"];

	// Cart Actions..
	(_display displayCtrl 3108) ctrlSetEventHandler ["ButtonClick", "[] call ULP_fnc_addCart"];
	(_display displayCtrl 3107) ctrlSetEventHandler ["LBDblClick", "_this call ULP_fnc_removeCart"];
	(_display displayCtrl 3109) ctrlSetEventHandler ["ButtonClick", "_this call ULP_fnc_removeCart"];
	(_display displayCtrl 3110) ctrlSetEventHandler ["ButtonClick", "_this spawn ULP_fnc_buyItems"];

	(_display displayCtrl 3115) ctrlEnable false;
	(_display displayCtrl 3117) ctrlEnable false;
	(_display displayCtrl 3118) ctrlEnable false;
};