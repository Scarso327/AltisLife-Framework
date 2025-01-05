/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#define FREIGHT_ITEM_CFG missionConfigFile >> "CfgVirtualItems" >> "FreightCargo"
#include "..\..\script_macros.hpp"
scopeName "fn_claimFreight";

if (canSuspend) exitWith {
    [ULP_fnc_claimFreight, _this] call ULP_fnc_directCall;
};

_this params [
	["_trader", objNull, [objNull]],
	["_mission", "Kavala_Freight", [""]]
];

if (isNull _trader) exitWith {};

if !(["Freight"] call ULP_fnc_hasGroupPerk) exitWith {
	["Your group doesn't have access to this run"] call ULP_fnc_hint;
};

private _near = ((_trader nearEntities [["Car"], 10]) select {
	[player, _x] call ULP_fnc_isVehicleOwner
});

if (_near isEqualTo []) exitWith {
	["There are no trucks you own nearby"] call ULP_fnc_hint;
};

if ("CorporateFreight" in ULP_Missions) exitWith {
	["You can only have one freight mission at a time"] call ULP_fnc_hint;
};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (_near apply { 
	([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "", "_picture", "_name" ]; 
	[_picture, _name, _x call BIS_fnc_netId, 0];
}), ["Fill", "Cancel"], [_trader, _mission], {
	_this params [
		["_trader", objNull, [objNull]],
		["_mission", "Kavala_Freight", [""]],
		["_display", displayNull, [displayNull]]
	];

	if ((player distance _trader) > 5) exitWith {
		["You've moved too far away"] call ULP_fnc_hint;
	};

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _vehicle) exitWith { ["You didn't select a vehicle to fill with freight!"] call ULP_fnc_hint; };

	if !([_vehicle, getPos _trader] call ULP_fnc_isVehicleStationary) exitWith { ["Vehicle's engine must be turned off and close to the sign!"] call ULP_fnc_hint; };

	private _currentVehicleLoad = [_vehicle] call ULP_fnc_currentLoad;
	private _maxVehicleLoad = [_vehicle] call ULP_fnc_maxLoad;

	private _freightItemWeight = getNumber (FREIGHT_ITEM_CFG >> "weight");

	private _maxQuantity = ( floor ((_maxVehicleLoad - _currentVehicleLoad) / _freightItemWeight) max 0 );

	if (_maxQuantity <= 0) exitWith { ["This vehicle has no space and can't store even one freight item!"] call ULP_fnc_hint; };

	private _time = (_freightItemWeight * _maxQuantity) / getNumber (missionConfigFile >> "CfgMissions" >> "CorporateFreight" >> "timeDivisionAmount");

	private _vehicleCfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;

	private _item = configName (FREIGHT_ITEM_CFG);

	if (_item in getArray ((_vehicleCfg select 1) >> "blacklistedItems")) exitWith {
		["A truck must be used for freight missions"] call ULP_fnc_hint;
	};

	[format["Filling %1 with Freight", _vehicleCfg param [3, "a vehicle"]], _time, [_trader, _vehicle, _maxQuantity, _item, _mission], 
		{ (player distance (_this select 0)) <= 5 && { [(_this select 1), getPos (_this select 0)] call ULP_fnc_isVehicleStationary } }, 
		{
			_this params [ "_trader", "_vehicle", "_maxQuantity", "_item", "_mission" ];
			if (isNull _vehicle) exitWith {};

			if ("CorporateFreight" in ULP_Missions) exitWith {
				[getText (missionConfigFile >> "CfgMissions" >> "CorporateFreight" >> "Messages" >> "onAlreadyHas")] call ULP_fnc_hint;
			};

			private _cargoParams = [_vehicle, _item, _maxQuantity];

			if !(_cargoParams call ULP_fnc_addToCargo) exitWith {
				["This vehicle can't store expected amount of freight items, make sure nothing is added while this process is happening!"] call ULP_fnc_hint;
			};

			missionNamespace setVariable ["ULP_FreightVehicle", [_vehicle, _maxQuantity]];

			if !(["CorporateFreight", _mission] call ULP_fnc_claimMission) exitWith {
				_cargoParams call ULP_fnc_removeFromCargo;
			};
		}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, false] call ULP_fnc_selectObject;