/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_endFactory";

_this params [
	["_factory", objNull, [objNull]]
];

if (isNull _factory) exitWith {};

// We can now sync inventory
private _cargo = _factory getVariable ["ULP_VirtualCargo", createHashMap];

_factory setVariable ["ULP_VirtualCargo", 
	(if (_cargo isEqualTo []) then {
		nil
	} else {
		_cargo
	}), true];

_factory setVariable ["locked", nil, true];
_factory setVariable ["product_order", nil, true];

deleteVehicle (_factory getVariable ["sound", objNull]);

_factory setVariable ["cooldown", diag_tickTime + 30];

private _nearbyUnits = playableUnits select { (_x distance _factory) <= 50 };
["FactoryFinished", [ _factory ]] remoteExecCall ["ULP_fnc_invokeEvent", _nearbyUnits];