/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogUpgrades_OnListChanged";

_this params [ "_list", "_index" ];

if (isNull _list || { _index isEqualTo -1 }) exitWith {};

private _display = ctrlParent _list;
private _object = _display getVariable ["selectedObject", objNull];

if (isNull _object) exitWith {}; // wtf?

private _info = _display displayCtrl 5702;

private _data = _list lbData _index;
private _cfg = ([_object] call ULP_fnc_upgradeCfg) >> _data;
if !(isClass _cfg) exitWith {};

private _required = [];

{
	_x params [ "_item", "_count" ];

	private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _item;

	if (isClass _itemCfg) then {
		private _countInCargo = _cargo getOrDefault [_item, 0];

		_required pushBack format [" - %1 (%2/%3)", getText (_itemCfg >> "displayName"), (([_item] call ULP_fnc_hasItem) max 0), [_count] call ULP_fnc_numberText];
	};
} forEach getArray (_cfg >> "materials");

_info ctrlSetStructuredText parsetext format [
	"<br/><img image = '%1' align='center' size='3.5' /><br/><t align = 'center' size = '1.5'>%2</t><br/><t align = 'left' size = '1'>%3<br/><br/>Materials:<br/><t size='0.8'>%4</t></t>", 
	getText(_cfg >> "icon"), 
	getText(_cfg >> "displayName"), 
	getText(_cfg >> "description"), 
	(_required joinString "<br/>")
];

[_info] call ULP_UI_fnc_setToTextHeight;

_display setVariable ["selected", _cfg];