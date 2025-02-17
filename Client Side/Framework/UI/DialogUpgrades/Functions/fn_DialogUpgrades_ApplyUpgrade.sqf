/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogUpgrades_ApplyUpgrade";

_this params [ "_button" ];

if (isNull _button) exitWith {};

private _display = ctrlParent _button;

private _upgradeCfg = _display getVariable ["selected", ""];

if !(isClass _upgradeCfg) exitWith { ["You must select an upgrade to apply"] call ULP_fnc_hint; };

private _materials = getArray (_upgradeCfg >> "materials");

private _conversion = [_materials] call ULP_fnc_calcMaxConversion;
if (_conversion <= 0) exitWith {
	[format["You are missing the required materials for this upgrade: <t color='#B92DE0'>%1</t>!", _materials]] call ULP_fnc_hint;
};

private _object = _display getVariable ["selectedObject", objNull];
if (isNull _object) exitWith {}; // wtf?

diag_log _object;

if ([_object, configName _upgradeCfg] call ULP_fnc_hasUpgrade) exitWith {
	["This already has this upgrade"] call ULP_fnc_hint;
};

private _cfg = [typeOf _object] call ULP_fnc_vehicleCfg;
diag_log _cfg;
if (isNull _object || { _cfg isEqualTo [] }) exitWith {};

_cfg params [
	"", "_missionCfg", "", "_name"
];

diag_log _missionCfg;

if !(isClass _missionCfg) exitWith {};

_display closeDisplay 1;

if (!(_object call compile getText (_upgradeCfg >> "condition")) 
	|| { isClass _missionCfg 
		&& { isArray (_missionCfg >> "blacklistedUpgrades") }
		&& { ((configName _upgradeCfg) in getArray (_missionCfg >> "blacklistedUpgrades")) } }) exitWith {
	["This upgrade can't be applied to this"] call ULP_fnc_hint;
};

private _time = getNumber (_upgradeCfg >> "time");
private _upgradeName = getText (_upgradeCfg >> "displayName");

if !([format["Applying %1 to %2", _upgradeName, _name], _time, [_object, _upgradeCfg, _name, _upgradeName], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 15 }
}, {
	_this params [ "_object", "_upgradeCfg", "_name", "_upgradeName" ];

	if (isNull _object || { !(alive _object) }) exitWith {
		[format["You failed to upgrade the <t color='#B92DE0'>%1</t> as it's been destroyed.", _name]] call ULP_fnc_hint;
	};

	{
		_x params ["_item", "_amount"];
		[_item, _amount, true] call ULP_fnc_handleItem;
	} forEach getArray (_upgradeCfg >> "materials");

	[_object, configName _upgradeCfg] call ULP_fnc_setUpgrade;

	[format["You've upgraded <t color='#B92DE0'>%1</t> with <t color='#B92DE0'>%2</t>", _name, _upgradeName]] call ULP_fnc_hint;
}, { ["You must stay near to upgrade it..."] call ULP_fnc_hint; }, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["You can't upgrade while performing another action!"] call ULP_fnc_hint;
};