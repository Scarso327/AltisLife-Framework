/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_storeVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_storeVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	["_location", objNull, [objNull]],
	["_types", ["Car", "Air", "Ship"], [[]]]
];

if (isNull _location) exitWith {};

private _near = _location nearEntities [_types, 15];
private _vehicle = _near param [(_near findIf { [player, _x] call ULP_fnc_isVehicleOwner }), objNull];

if (isNil "_vehicle" || { isNull _vehicle } || { !(alive _vehicle) }) exitWith {
	hint "No vehicles near stand to store...";
};

if ([[player] call ULP_fnc_getFaction, "vehicles"] call ULP_fnc_factionPresistant && { (_vehicle getVariable ["vehicle_id", -1]) >= 0  }) exitWith {
	[format["Storing %1", ([typeOf _vehicle] call ULP_fnc_itemCfg) param [5, "Vehicle"]], 15, [_location, _vehicle], { (player distance (_this select 0)) <= 5 }, {
		_this params [ "", "_vehicle" ];

		["VehicleStored", { hint "Vehicle has been stored."; }, true] call ULP_fnc_addEventHandler;
		[_vehicle] remoteExecCall ["ULP_SRV_fnc_storeVehicle", RSERV];
	}, {}] call ULP_UI_fnc_startProgress;
};

deleteVehicle _vehicle;
hint "Vehicle has been stored.";