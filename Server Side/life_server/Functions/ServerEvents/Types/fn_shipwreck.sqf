/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_shipwreck";

_this params [
	["_cfg", configNull, [configNull]],
	["_shouldLoop", true, [false]]
];

if (isNull _cfg) exitWith { false };

private _location = selectRandom ("isClass _x" configClasses (_cfg >> "Locations"));
if (isNil "_location" || { _location isEqualTo [] }) exitWith { false };

private _pos = getArray (_location >> "position");

private _marker = createMarker [format["shipwreck_marker_%1", time], _pos];
_marker setMarkerColor "ColorRed";
_marker setMarkerType "mil_warning";
_marker setMarkerSize [0.5, 0.5];
_marker setMarkerText "Shipwreck";

private _ship = createVehicle ["Land_Wreck_Traw_F", [_pos # 0, _pos # 1, 0], [], 0, "None"];
_ship allowDamage false;
_ship enableSimulationGlobal false;

["OnSpawnShipwreck", [
	_ship, "<t color='#ff0000' size='1.5px'>Shipwreck<br/></t><t color='#ffffff' size='1px'>A sunken ship has been located! It may contain important items and it has been marked on your map!"
]] remoteExecCall ["ULP_fnc_invokeEvent", -2, "ShipwreckSpawn"];

[ { isNull (_this select 0) }, [_ship, _marker, _shouldLoop], {
	_this params [ "", "_marker", "_shouldLoop" ];

	remoteExecCall ["", "ShipwreckSpawn"];

	deleteMarker _marker;

	["OnClaimedShipwreck", [
		"<t color='#ff0000' size='1.5px'>Shipwreck<br/></t><t color='#ffffff' size='1px'>The ship has been successfully looted and has despawned!"
	]] remoteExecCall ["ULP_fnc_invokeEvent", -2];

	if !(_shouldLoop) exitWith {};

	private _cfg = missionConfigFile >> "CfgRandomEvents" >> "Shipwreck";
	missionNamespace setVariable [format ["ULP_SRV_%1_Active", configName _cfg], nil, true];

	private _delay = getNumber ([_cfg, "Cooldown"] call ULP_SRV_fnc_getEventParam);
	_delay = _delay + (random getNumber ([_cfg, "RandomAddition"] call ULP_SRV_fnc_getEventParam));

	[_delay, _cfg, {
		_this call compile getText (_this >> "ServerFunctions" >> "onCompleted");
	}] call ULP_fnc_waitExecute
}] call ULP_fnc_waitUntilExecute;

true