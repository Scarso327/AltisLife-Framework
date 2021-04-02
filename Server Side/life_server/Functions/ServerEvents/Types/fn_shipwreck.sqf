/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_shipwreck";

private _cfg = _this;
if (isNull _cfg) exitWith { false };


[ { call (_this select 1) }, [_cfg, compile getText (_cfg >> "SpawnCondition")], {
	private _cfg = _this select 0;

	missionNamespace setVariable [format ["ULP_SRV_%1_Active", configName _cfg], true, true];

	private _location = selectRandom ("isClass _x" configClasses (_cfg >> "Locations"));
	if (isNil "_location" || { _location isEqualTo [] }) exitWith { false };

	private _pos = getArray (_location >> "position");

	private _marker = createMarker [format["shipwreck_marker_%1", time], _pos];
	_marker setMarkerColor "ColorRed";
	_marker setMarkerType "mil_marker";
	_marker setMarkerText "Shipwreck";

	private _ship = createVehicle ["Land_Wreck_Traw_F", _pos, [], 0, "None"];
	_ship allowDamage false;
	_ship enableSimulationGlobal false;

	["OnSpawnShipwreck", [
		"<t color='#ff0000' size='1.5px'>Shipwreck<br/></t><t color='#ffffff' size='1px'>A sunken ship has been located! It may contain important items and it has been marked on your map!"
	]] remoteExecCall ["ULP_fnc_invokeEvent", -2];

	[ { isNull (_this select 0) }, [_ship, _marker], {
		deleteMarker (_this select 1);

		["OnClaimedShipwreck", [
			"<t color='#ff0000' size='1.5px'>Shipwreck<br/></t><t color='#ffffff' size='1px'>The ship has been successfully looted and has despawned!"
		]] remoteExecCall ["ULP_fnc_invokeEvent", -2];

		private _cfg = missionConfigFile >> "CfgRandomEvents" >> "Shipwreck";
		missionNamespace setVariable [format ["ULP_SRV_%1_Active", configName _cfg], false, true];

		private _delay = getNumber (_cfg >> "Cooldown");
		_delay = _delay + (random getNumber (_cfg >> "RandomAddition"));

		[_delay, _cfg, {
			_this call compile getText (_this >> "ServerFunctions" >> "onCompleted");
		}] call ULP_fnc_waitExecute
	}] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_waitUntilExecute;