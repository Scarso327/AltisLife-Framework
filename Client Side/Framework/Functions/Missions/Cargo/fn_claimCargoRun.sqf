/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_claimCargoRun";

if (canSuspend) exitWith {
    [ULP_fnc_claimCargoRun, _this] call ULP_fnc_directCall;
};

_this params [
	["_trader", objNull, [objNull]],
	["_missionType", "CorporateFreight", [""]],
	["_mission", "Kavala_Freight", [""]]
];

private _missionCfg = missionConfigFile >> "CfgMissions" >> _missionType;
if (isNull _trader || { !isClass _missionCfg }) exitWith {};

if !(call compile getText (_missionCfg >> "condition")) exitWith {
	["You don't meet the requirements for this run"] call ULP_fnc_hint;
};

private _near = ((_trader nearEntities [["Car"], 10]) select {
	[player, _x] call ULP_fnc_isVehicleOwner
});

if (_near isEqualTo []) exitWith {
	["There are no trucks you own nearby"] call ULP_fnc_hint;
};

if (_missionType in ULP_Missions) exitWith {
	["You can only have one of these missions at a time"] call ULP_fnc_hint;
};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (_near apply { 
	([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "", "_picture", "_name" ]; 
	[_picture, _name, _x call BIS_fnc_netId, 0];
}), ["Fill", "Cancel"], [_trader, _missionCfg, _mission], {
	_this params [
		["_trader", objNull, [objNull]],
		["_missionCfg", configNull, [configNull]],
		["_mission", "Kavala_Freight", [""]],
		["_display", displayNull, [displayNull]]
	];

	if ((player distance _trader) > 5) exitWith {
		["You've moved too far away"] call ULP_fnc_hint;
	};

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _vehicle) exitWith { ["You didn't select a vehicle to fill with cargo!"] call ULP_fnc_hint; };

	if !([_vehicle, getPos _trader] call ULP_fnc_isVehicleStationary) exitWith { ["Vehicle's engine must be turned off and close to the sign!"] call ULP_fnc_hint; };

	private _currentVehicleLoad = [_vehicle] call ULP_fnc_currentLoad;
	private _maxVehicleLoad = [_vehicle] call ULP_fnc_maxLoad;

	private _item = getText (_missionCfg >> "cargoItem");
	if !(isClass (missionConfigFile >> "CfgVirtualItems" >> _item)) exitWith {};

	private _itemWeight = getNumber (missionConfigFile >> "CfgVirtualItems" >> _item >> "weight");

	private _maxQuantity = ( floor ((_maxVehicleLoad - _currentVehicleLoad) / _itemWeight) max 0 );

	if (_maxQuantity <= 0) exitWith { ["This vehicle has no space and can't store even one cargo item!"] call ULP_fnc_hint; };

	private _time = (_itemWeight * _maxQuantity) / getNumber (_missionCfg >> "timeDivisionAmount");

	private _vehicleCfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;

	if (_item in getArray ((_vehicleCfg select 1) >> "blacklistedItems")) exitWith {
		["This vehicle can't be used for this mission"] call ULP_fnc_hint;
	};

	[format["Filling %1 with Cargo", _vehicleCfg param [3, "a vehicle"]], _time, [_trader, _vehicle, _maxQuantity, _item, _missionCfg, _mission], 
		{ (player distance (_this select 0)) <= 5 && { [(_this select 1), getPos (_this select 0)] call ULP_fnc_isVehicleStationary } }, 
		{
			_this params [ "_trader", "_vehicle", "_maxQuantity", "_item", "_missionCfg", "_mission" ];
			if (isNull _vehicle) exitWith {};

			private _missionType = configName _missionCfg;

			if (_missionType in ULP_Missions) exitWith {
				[getText (_missionCfg >> "Messages" >> "onAlreadyHas")] call ULP_fnc_hint;
			};

			private _cargoParams = [_vehicle, _item, _maxQuantity];

			if !(_cargoParams call ULP_fnc_addToCargo) exitWith {
				["This vehicle can't store expected amount of cargo items, make sure nothing is added while this process is happening!"] call ULP_fnc_hint;
			};

			if !([_missionType, _mission] call ULP_fnc_claimMission) exitWith {
				_cargoParams call ULP_fnc_removeFromCargo;
			};

			// Save vehicle information
			private _missionInfo = ULP_Missions get _missionType;
			_missionInfo pushBack [_vehicle, _missionType, _maxQuantity];

			ULP_Missions set [_missionType, _missionInfo];

		}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, false] call ULP_fnc_selectObject;