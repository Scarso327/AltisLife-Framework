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

private _near = _location nearEntities [_types, 20];
private _vehicle = _near param [(_near findIf { [player, _x] call ULP_fnc_isVehicleOwner }), objNull];

if (isNil "_vehicle" || { isNull _vehicle } || { !(alive _vehicle) }) exitWith {
	["No vehicles near stand to store!"] call ULP_fnc_hint;
};

if ([[player] call ULP_fnc_getFaction, "vehicles"] call ULP_fnc_factionPresistant && { (_vehicle getVariable ["vehicle_id", -1]) >= 0  }) exitWith {
	[format["Storing %1", ([typeOf _vehicle] call ULP_fnc_itemCfg) param [5, "Vehicle"]], 20, [_location, _vehicle], { (player distance (_this select 0)) <= 10 }, {
		_this params [ "", "_vehicle" ];

		["VehicleStored", { ["Vehicle has been stored."] call ULP_fnc_hint; }, true] call ULP_fnc_addEventHandler;
	}, {}] call ULP_UI_fnc_startProgress;
};

deleteVehicle _vehicle;
["Vehicle has been stored."] call ULP_fnc_hint;

[getPlayerUID player, "Store", [_vehicle, _location]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];