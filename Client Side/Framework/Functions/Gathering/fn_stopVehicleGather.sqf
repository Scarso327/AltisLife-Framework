/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_stopVehicleGather";

_this params [
	["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle || { !((typeOf _vehicle) isEqualTo "O_Truck_03_device_F") }) exitWith { false };

private _miner = _vehicle getVariable ["mining", objNull];

if (player isEqualTo _miner) then {
	[_vehicle getVariable ["miningEvh", -1]] call ULP_fnc_removeEachFrame;
	
	_vehicle setVariable ["miningEvh", nil];
	_vehicle setVariable ["nextMiningTime", nil];
};

private _sound = _vehicle getVariable ["sound", objNull];
if !(isNull _sound) then { deleteVehicle _sound; };

_vehicle setVariable ["sound", nil, true];
_vehicle setVariable ["mining", nil, true];
_vehicle setVariable ["locked", nil, true];
_vehicle engineOn false;