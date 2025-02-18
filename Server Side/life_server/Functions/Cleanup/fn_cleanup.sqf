/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_cleanup";

[15 * 60, [], {
	private _totalCleanedUp = 
		({
			private _vehicle = _x;

			private _cleaned = false;

			if !(isNil { _x getVariable "storage_box" }) then {

				// 5 minutes since save + no one nearby = save and delete
				if ((_x getVariable ["storageLastSaved", time]) <= (time - (5 * 60)) && { (playableUnits findIf { (_container distance _x) <= 20 }) isEqualTo -1 }) then {
					_cleaned = [_vehicle, true] call ULP_SRV_fnc_saveStorage;
				};
			} else {

				if (!alive _vehicle || { (playableUnits findIf { (_vehicle distance _x) <= 600 }) isEqualTo -1 }) then {
					if ([_vehicle, ["Car", "Air", "Ship", "Armored", "Submarine"]] call ULP_fnc_isKindOf) exitWith {
						private _id = _vehicle getVariable ["vehicle_id", -1];

						private _sinceLastEngineOffTime = switch (true) do {
							case (["redzone_", [_vehicle]] call ULP_fnc_isUnitsInZone): { 5 * 60 };
							case (([["Hato"]] call ULP_fnc_onlineFaction) > 0): { 30 * 60 };
							default { 10 * 60 };
						};

						if (_id isEqualTo -1 
							|| { !((crew _vehicle) isEqualTo []) } 
							|| { ((_vehicle getVariable ["engineLastOffTime", 0]) + _engineOffCheckTime) > serverTime }) exitWith {};

						_cleaned = [_vehicle] call ULP_SRV_fnc_storeVehicle;
					};

					if ([_vehicle] call ULP_fnc_isPlaceable || { _vehicle isKindOf "Land_Bodybag_01_black_F" }) then {
						deleteVehicle _vehicle;
						_cleaned = true;
					};
				};
			};

			_cleaned
		} count vehicles)
		+
		({
			private _vehicle = _x;
			private _cleaned = false;

			if ((playableUnits findIf { (_vehicle distance _x) <= 300 }) isEqualTo -1) then {
				deleteVehicle _vehicle;
				_cleaned = true;
			};

			_cleaned
		} count (allMissionObjects "GroundWeaponHolder"));

	[format ["Cleanup ran and removed %1 objects", _totalCleanedUp]] call ULP_fnc_logIt;
	[] call ULP_SRV_fnc_cleanup; // Requeue myself
}] call ULP_fnc_waitExecute;