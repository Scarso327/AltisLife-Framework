/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_startVehicleGather";

_this params [
	["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle || { !((typeOf _vehicle) isEqualTo "O_Truck_03_device_F") }) exitWith { false };

private _zone = [_vehicle] call ULP_fnc_getGatherZone;
if (isNull _zone || { !([player] call ULP_fnc_getFaction in getArray (_zone >> "factions")) } || { !(call compile getText (_zone >> "condition")) }) exitWith {
	["This vehicle isn't in a gather zone"] call ULP_fnc_hint;
	false
};

private _resources = getArray (_zone >> "items");
if (_resources isEqualTo []) exitWith {};

private _items = _resources apply { _x select 0 };
private _weights = _resources apply { (_x select 1) / 100 };

private _time = getNumber(_zone >> "gatherTime") * 2;

if !(_this call ULP_fnc_canVehicleGather) exitWith { ["This vehicle can't be used to gather right now, check it's fuel and make sure no one is driving"] call ULP_fnc_hint; false };
if (_this call ULP_fnc_isVehicleGathering) exitWith { ["Someone is already using this to gather"] call ULP_fnc_hint; false };

_vehicle setVariable ["nextMiningTime", diag_tickTime + _time];
_vehicle setVariable ["mining", player, true];
_vehicle setVariable ["locked", true, true];
_vehicle engineOn true;

private _source = createSoundSource ["Device_disassembled_loop", getPosATL _vehicle, [], 0];
_source attachTo [_vehicle, [0, 0, 0]];
_vehicle setVariable ["sound", _source, true];

_vehicle setVariable ["miningEvh", [[_vehicle, _zone, _items, _weights, _time], {
	_this params [ "_vehicle", "_zone", "_items", "_weights", "_time" ];

	private _nextTickTime = _vehicle getVariable ["nextMiningTime", 0];
	if (_nextTickTime > diag_tickTime) exitWith {};

	if !([_vehicle] call ULP_fnc_isVehicleGathering 
		&& { [_vehicle] call ULP_fnc_canVehicleGather }) exitWith { [_vehicle] call ULP_fnc_stopVehicleGather; };

	if !([_vehicle, (_items selectRandomWeighted _weights), 1] call ULP_fnc_addToCargo) exitWith { [_vehicle] call ULP_fnc_stopVehicleGather; };
	
	[_vehicle, (fuel _vehicle) - 0.05] call ULP_fnc_setFuel;
	_vehicle setVariable ["nextMiningTime", diag_tickTime + _time];
}] call ULP_fnc_addEachFrame];