/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogVehicleTuning_ApplyUpgrade";

_this params [ "_button" ];

if (isNull _button) exitWith {};

private _display = ctrlParent _button;

private _cfg = _display getVariable ["selected", ""];

if !(isClass _cfg) exitWith { ["You must select an upgrade to apply"] call ULP_fnc_hint; };

private _materials = getArray (_cfg >> "materials");

private _conversion = [_materials] call ULP_fnc_calcMaxConversion;
if (_conversion <= 0) exitWith {
	[format["You are missing the required materials to upgrade this vehicle: <t color='#B92DE0'>%1</t>!", _materials]] call ULP_fnc_hint;
};

private _near = ((player nearEntities [["Car", "Air", "Ship"], 15]) select {
	[player, _x] call ULP_fnc_isVehicleOwner
});

if (_near isEqualTo []) exitWith {
	["There are no vehicles you own nearby"] call ULP_fnc_hint;
};

_display closeDisplay 1;

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (_near apply { 
 ([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "", "_picture", "_name" ]; 
 [_picture, _name, _x call BIS_fnc_netId, 0];
}), ["Upgrade", "Cancel"], [_cfg], {
	_this params [
		["_upgradeCfg", configNull, [configNull]],
		["_display", displayNull, [displayNull]]
	];

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _vehicle) exitWith { ["You didn't select a vehicle to upgrade!"] call ULP_fnc_hint; };

	if ([_vehicle, configName _upgradeCfg] call ULP_fnc_hasVehicleUpgrade) exitWith {
		["This vehicle already has this upgrade"] call ULP_fnc_hint;
	};

	private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
	if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith {};

	_cfg params [
		"", "_missionCfg", "_picture", "_name"
	];

	if !(isClass _missionCfg) exitWith {};

	if (!(_vehicle call compile getText (_upgradeCfg >> "condition")) 
		|| { isArray (_missionCfg >> "blacklistedUpgrades") 
			&& { ((configName _upgradeCfg) in getArray (_missionCfg >> "blacklistedUpgrades")) } }) exitWith {
		["This upgrade can't be applied to that vehicle"] call ULP_fnc_hint;
	};

	private _time = getNumber (_upgradeCfg >> "time");
	private _upgradeName = getText (_upgradeCfg >> "displayName");

	if !([format["Applying %1 to %2", _upgradeName, _name], _time, [_vehicle, _upgradeCfg, _name, _upgradeName], {
		!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 15 }
	}, {
		_this params [ "_vehicle", "_upgradeCfg", "_name", "_upgradeName" ];

		if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
			[format["You failed to upgrade the <t color='#B92DE0'>%1</t> as it's been destroyed."]] call ULP_fnc_hint;
		};

		{
			_x params ["_item", "_amount"];
			[_item, _amount, true] call ULP_fnc_handleItem;
		} forEach getArray (_upgradeCfg >> "materials");

		[_vehicle, configName _upgradeCfg] call ULP_fnc_setVehicleUpgrade;

		[format["You've upgrade <t color='#B92DE0'>%1</t> with <t color='#B92DE0'>%2</t>", _name, _upgradeName]] call ULP_fnc_hint;
	}, { ["You must stay near the vehicle to upgrade it..."] call ULP_fnc_hint; }, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
		["You can't upgrade a vehicle while performing another action!"] call ULP_fnc_hint;
	};
}, false] call ULP_fnc_selectObject;