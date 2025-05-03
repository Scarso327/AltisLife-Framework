/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vehicleProcess";

if (canSuspend) exitWith {
    [ULP_fnc_vehicleProcess, _this] call ULP_fnc_directCall;
};

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith { false };

private _list = _display displayCtrl 4003;
private _process = _list lbData (lbCurSel _list);

private _cfg = missionConfigFile >> "CfgProcessing" >> _process;
if !(isClass _cfg || { !([player] call ULP_fnc_getFaction in getArray (_cfg >> "factions")) }) exitWith { false };

private _near = ((player nearEntities [["Car"], 15]) select {
	!([_x] call ULP_fnc_getVehicleOwner isEqualTo "") && { [player, _x] call ULP_fnc_isVehicleOwner } && { [_x, "AutomaticLoaderUpgrade"] call ULP_fnc_hasUpgrade }
});

if (_near isEqualTo []) exitWith {
	["There are no vehicles with processing upgrade nearby!"] call ULP_fnc_hint;
	false
};

[_display, (_near apply { 
 ([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "", "_picture", "_name" ]; 
 [_picture, _name, _x call BIS_fnc_netId, 0];
}), ["Select", "Cancel"], [_cfg], {
	_this params [
		["_cfg", configNull, [configNull]],
		["_display", displayNull, [displayNull]]
	];

	if (isNull _display || { isNull _cfg }) exitWith {};
	private _list = _display displayCtrl 4509;

	private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _vehicle) exitWith { ["You didn't select a vehicle to process!"] call ULP_fnc_hint; };

	private _items = getArray (_cfg >> "items");
	private _materials = getArray (_cfg >> "materials");
	if (_items isEqualTo [] || { _materials isEqualTo [] }) exitWith {};

	private _conversion = [_vehicle, _materials] call ULP_fnc_calcMaxConversionVehicle;
	if (_conversion <= 0) exitWith {
		[format["You are missing the required materials to process here: <t color='#B92DE0'>%1</t>!", _materials]] call ULP_fnc_hint;
	};

	if (isEngineOn _vehicle) exitWith {
		["The vehicle's engine must be off"] call ULP_fnc_hint;
	};
	
	if !(isNull (_vehicle getVariable ["processor", objNull])) exitWith {
		["Someone else is already processing this vehicle"] call ULP_fnc_hint;
	};

	closeDialog 0;

	_vehicle setVariable ["locked", true, true];
	_vehicle setVariable ["processor", player, true];

	private _time = getNumber(_cfg >> "processTime") * _conversion * 1.3;

	[format["%1 Item(s)", getText(_cfg >> "processTitle")], _time, [_vehicle, _items, _conversion, _materials, _cfg], { 
		!(isEngineOn _vehicle) && { ((_this select 0) getVariable ["processor", objNull]) isEqualTo player } }, {
		_this params [ "_vehicle", "_items", "_expectedConversion", "_materials", "_cfg" ];

		// Redo here just in case they somehow changed something?
		// Make sure to only take a max of whatever we decided to take before
		private _conversion = ([_vehicle, _materials] call ULP_fnc_calcMaxConversionVehicle) min _expectedConversion;
		if (_conversion < _expectedConversion) exitWith {
			["You lost some items during processing from when it started so it failed"] call ULP_fnc_hint;

			_vehicle setVariable ["locked", nil, true];
			_vehicle setVariable ["processor", nil, true];
		};

		private _processor = _vehicle getVariable ["processor", objNull];

		if !(_processor isEqualTo player) exitWith {
			["You aren't the registered processor for this vehicle"] call ULP_fnc_hint;

			_vehicle setVariable ["locked", nil, true];
			_vehicle setVariable ["processor", nil, true];
		};

		{
			_x params ["_item", "_amount"];
			private _total = _amount * _conversion;

			[_vehicle, _item, _total] call ULP_fnc_removeFromCargo;
		} forEach _materials;

		{
			_x params ["_item", "_amount"];
			private _total = _amount * _conversion;

			[_vehicle, _item, _total] call ULP_fnc_addToCargo;
		} forEach _items;

		["You've successfully processed this vehicle's materials!"] call ULP_fnc_hint;

		_vehicle setVariable ["locked", nil, true];
		_vehicle setVariable ["processor", nil, true];
	}, {
		_this params [ "_vehicle" ];

		_vehicle setVariable ["locked", nil, true];
		_vehicle setVariable ["processor", nil, true];

		["Someone else started processing this vehicle or the engine turned on"] call ULP_fnc_hint;
	}] call ULP_UI_fnc_startProgress;
}, false] call ULP_fnc_selectObject;