/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogSalvageFactory_OnInit";
disableSerialization;

_this params [ "_display", "_params" ];

if (isNull _display) exitWith {};

_params params [
	["_factory", objNull, [objNull]]
];

private _factoryCfg = missionConfigFile >> "CfgFactories" >> worldName >> (_factory getVariable ["factory", ""]);
if !(isClass _factoryCfg) exitWith { _display closeDisplay 2; };

private _info = _display displayCtrl 5605;

private _requiredPower = getNumber (_factoryCfg >> "requiredPower");
private _factoryPower = _factory getVariable ["power", 0];

if (_factoryPower < _requiredPower) exitWith {
	[format ["This factory requires <t color='#B92DE0'>tier %1</t> power, currently it has <t color='#B92DE0'>tier %2</t> power.", _requiredPower, _factoryPower]] call ULP_fnc_hint;
	_display closeDisplay 2;
};

_display setVariable ["factory", _factory];

(_display displayCtrl 5601) ctrlSetText format ["%1 | Power Tier: %2", getText (_factoryCfg >> "displayName"), _factoryPower];

private _product = (_factory getVariable ["product_order", []]) param [0, configNull, [configNull]];

private _cfg = [configName _product] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith {};

_cfg params [
	"", "_missionCfg", "_picture", "_name"
];

if !(isClass _missionCfg) exitWith {};

private _rewards = [];

{
	_x params [ "_item", "_count" ];

	private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _item;

	if (isClass _itemCfg) then {
		_rewards pushBack format [" - %1 (%2)", getText (_itemCfg >> "displayName"), [_count] call ULP_fnc_numberText];
	};
} forEach getArray (_product >> "materials");

_info ctrlSetStructuredText parseText format [
	"<br/><img image = '%1' align='center' size='3.5' /><br/><t align = 'center' size = '1.5'>%2</t><br/><t align = 'left' size = '1'>Required Power: <t color='#B92DE0'>Tier %3</t><br/>You can press <t color='#B92DE0'>T</t> to access the factories inventory when outside this menu.<br/><br/>Reward:<br/><t size='0.8'>%4</t></t>", 
	_picture, 
	_name, 
	_requiredPower,
	(_rewards joinString "<br/>")
];

[_info] call ULP_UI_fnc_setToTextHeight;

_display setVariable ["eachFrameHandle", ([[_display], { _this call ULP_UI_fnc_DialogSalvageFactory_OnEachFrame }] call ULP_fnc_addEachFrame)];