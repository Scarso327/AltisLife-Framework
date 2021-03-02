/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyVehicle";

if (canSuspend) exitWith {
	_this call ULP_fnc_buyVehicle;
};

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _texList = _display displayCtrl 3408;

private _vehInfo = _display getVariable ["selected", []];
if (_vehInfo isEqualTo []) exitWith {};

_vehInfo params [
	"", "_missionCfg", "_picture", "_name"
];

private _buyPrice = getNumber(_missionCfg >> "buyPrice");
private _plate = false;
private _texture = _texList lbData (lbCurSel _texList);

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

if (CASH >= _buyPrice) exitWith {
	private _faction = [player] call ULP_fnc_getFaction;

	if ([_faction, "vehicles"] call ULP_fnc_factionPresistant) then {
		[getPlayerUID player, profileName, _faction, configName _missionCfg, _spawn, _texture] remoteExecCall ["ULP_SRV_fnc_createVehicle", RSERV];
	} else {
		[configName _missionCfg, _spawn, _texture] call ULP_fnc_createVehicle;
	};

	closeDialog 0;
};

hint format["You can't afford to pay for this vehicle. You need £%1.", [_buyPrice] call life_fnc_numberText];