/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_retrieveGarage";

if (canSuspend) exitWith {
    [ULP_fnc_retrieveGarage, _this] call ULP_fnc_directCall;
};

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _impound = _display getVariable ["impound", false];

private _vehInfo = _display getVariable ["selected", []];
if (_vehInfo isEqualTo []) exitWith {};

_vehInfo params [
	"_id", "_classname", "_texture", "_price"
];

private _spawns = _display getVariable ["spawns", []];

_spawns = _spawns apply {
	if (_x isEqualType []) exitWith { [_x] };
	[markerPos _x, markerDir _x]
};

private _spawn = {
	if (((_x select 0) nearEntities [["Car", "Ship", "Air"], 8]) isEqualTo []) exitWith { _x };
} forEach _spawns;

if (isNil "_spawn") exitWith {
	hint "There are no available spawn points...";
};

if ([_price, true, (["Garage Retrieval Fees", "Vehicle Impound Fees"] select (_impound))] call ULP_fnc_removeMoney) exitWith {
	closeDialog 0;

	[_classname, _spawn, _texture, _id] call ULP_fnc_createVehicle;
	[_id] remoteExecCall ["ULP_SRV_fnc_retrieveVehicle", RSERV];
};

hint format["You can't afford to retrieve this vehicle. You need £%1.", [_price] call ULP_fnc_numberText];