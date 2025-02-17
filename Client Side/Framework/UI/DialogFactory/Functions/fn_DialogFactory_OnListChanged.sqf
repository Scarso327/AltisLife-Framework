/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogMedicMap_OnListChanged";

_this params [ "_list", "_index" ];

if (isNull _list || { _index isEqualTo -1 }) exitWith {};

private _display = ctrlParent _list;
private _info = _display displayCtrl 5505;

private _factory = _display getVariable ["factory", objNull];

private _factoryCfg = missionConfigFile >> "CfgFactories" >> worldName >> (_factory getVariable ["factory", ""]);
if !(isClass _factoryCfg) exitWith {};

private _data = _list lbData _index;

private _cargo = _factory getVariable ["ULP_VirtualCargo", createHashMap];

private _productCfg = _factoryCfg >> "Products" >> _data;
private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> configName _productCfg;

private _required = [];

{
	_x params [ "_item", "_count" ];

	private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _item;

	if (isClass _itemCfg) then {
		private _countInCargo = _cargo getOrDefault [_item, 0];

		_required pushBack format [" - %1 (%2/%3)", getText (_itemCfg >> "displayName"), _countInCargo, [_count] call ULP_fnc_numberText];
	};
} forEach getArray (_productCfg >> "materials");

private _requiredPower = if (isNumber (_productCfg >> "requiredPower")) then {
	getNumber (_productCfg >> "requiredPower")
} else {
	getNumber (_factoryCfg >> "requiredPower")
};

_info ctrlSetStructuredText parsetext format [
	"<br/><img image = '%1' align='center' size='3.5' /><br/><t align = 'center' size = '1.5'>%2</t><br/><t align = 'left' size = '1'>%3<br/><br/>Required Power: <t color='#B92DE0'>Tier %4</t><br/>You can press <t color='#B92DE0'>T</t> to access the factories inventory when outside this menu.<br/><br/>Materials:<br/><t size='0.8'>%5</t></t>", 
	getText(_itemCfg >> "icon"), 
	getText(_itemCfg >> "displayName"), 
	getText(_itemCfg >> "description"), 
	_requiredPower,
	(_required joinString "<br/>")
];

[_info] call ULP_UI_fnc_setToTextHeight;

_display setVariable ["selected_product", configName _productCfg];