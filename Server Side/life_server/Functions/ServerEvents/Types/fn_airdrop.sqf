/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_airdrop";

private _cfg = _this;
if (isNull _cfg) exitWith { false };

[ { call (_this select 1) }, [_cfg, compile getText (_cfg >> "SpawnCondition")], {
	private _cfg = _this select 0;

	missionNamespace setVariable [format ["ULP_SRV_%1_Active", configName _cfg], true, true];

	private _location = selectRandom ("isClass _x" configClasses (_cfg >> "Locations"));
	if (isNil "_location" || { _location isEqualTo [] }) exitWith { false };

	private _time = getNumber (_cfg >> "NotifyDelay");

	["OnWarningAirdrop", [
		format [
			"<t color='#ff0000' size='1.5px'>Airdrop<br/></t><t color='#ffffff' size='1px'>A helicopter is dropping supplies! The location will be marked on your map in %1 minutes.",
			round (_time / 60)
		]
	]] remoteExecCall ["ULP_fnc_invokeEvent", -2];

	[ _time, [_cfg, _location], {
		_this params [
			"_cfg", "_location"
		];

		private _pos = getArray (_location >> "position");
		private _radius = getNumber (_location >> "radius");

		private _area = createMarker [format["airdrop_area_%1", time], _pos];
		_area setMarkerShape "ELLIPSE";
		_area setMarkerBrush "FDIAGONAL";
		_area setMarkerSize [_radius, _radius];
		_area setMarkerColor "ColorYellow";

		private _marker = createMarker [format["airdrop_marker_%1", time], _pos];
		_marker setMarkerColor "ColorRed";
		_marker setMarkerText "Airdrop";
		_marker setMarkerType "mil_marker";

		// Parachute...
		private _para = createVehicle ["B_parachute_02_F", _pos, [], 0, "FLY"];

		// Crate...
		private _crate = createVehicle ["O_CargoNet_01_ammo_F", position _para, [], 0, "NONE"];
		_crate setVariable ["locked", true, true];
		_crate attachTo [_para, [0, 0, -1.3]];
		_crate allowDamage false;

		private _paraPos = getPosATL _para;
		_para setPosATL [_paraPos select 0, _paraPos select 1, 1000];

		clearWeaponCargoGlobal _crate;
		clearMagazineCargoGlobal _crate;
		clearItemCargoGlobal _crate;

		["OnSpawnAirdrop", [
			_crate, "<t color='#ff0000' size='1.5px'>Airdrop<br/></t><t color='#ffffff' size='1px'>The supplies have been dropped! The location has been marked on your map."
		]] remoteExecCall ["ULP_fnc_invokeEvent", -2, "AirdropSpawn"];

		[
			{ ((getPos (_this select 0) select 2) <= 1) || { isNil "_this select 1" } }, [_crate, _para, _area, _marker], {
				private _crate = _this select 0;

				detach _crate;
				_crate enableRopeAttach false;

				[
					{ isNull (_this select 0) }, _this, {
						remoteExecCall ["", "AirdropSpawn"]; // Remove JIP

						deleteMarker (_this select 2);
						deleteMarker (_this select 3);

						private _cfg = missionConfigFile >> "CfgRandomEvents" >> "Airdrop";
						missionNamespace setVariable [format ["ULP_SRV_%1_Active", configName _cfg], false, true];

						private _delay = getNumber (_cfg >> "Cooldown");
						_delay = _delay + (random getNumber (_cfg >> "RandomAddition"));

						[_delay, _cfg, {
							_this call compile getText (_this >> "ServerFunctions" >> "onCompleted");
						}] call ULP_fnc_waitExecute
					}
				] call ULP_fnc_waitUntilExecute;
			}
		] call ULP_fnc_waitUntilExecute;
	}] call ULP_fnc_waitExecute;
} ] call ULP_fnc_waitUntilExecute;