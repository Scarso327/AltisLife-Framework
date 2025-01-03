/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_cartelTick";

if ((count ULP_SRV_Cartels) isEqualTo 0) exitWith {};

private _tickDelay = getNumber (missionConfigFile >> "CfgCartels" >> "Fixed" >> "cartelTick");

missionNamespace setVariable ["ULP_SRV_LastCartelTick", serverTime, true];
missionNamespace setVariable ["ULP_SRV_TotalTicks", (missionNamespace getVariable ["ULP_SRV_TotalTicks", 0]) + 1];

[ _tickDelay, [] , {
	{
		_y params [
			"_obj", "_area", "_scores"
		];

		private _config = _obj getVariable ["config", configNull];

		if !(isNull _config) then {
			private _unitsInZone = [_area, allPlayers, getArray (_config >> "factions")] call ULP_fnc_unitsInZone;

			private _groups = [];
			{ _groups pushBackUnique (group _x) } forEach (_unitsInZone select {
				// Must be armed
				!((currentWeapon _x) in getArray(missionConfigFile >> "CfgSettings" >> "doesntThreaten")) &&
				// Must be in a group // Removed so Police neutralise code runs
				// { [group _x] call ULP_fnc_isGroup } &&
				// Must be out of a vehicle
				{ isNull (objectParent _x) }
			});

			if ((count _groups) isEqualTo 1) then {
				private _groupId = _groups param [0, grpNull, [grpNull]] getVariable ["group_id", -1];

				private _firstUnitInZone = _unitsInZone select 0;

				// If the controlling group is the police we decrease all by 1
				if ([_firstUnitInZone, ["Police"]] call ULP_fnc_isFaction && { [getNumber (missionConfigFile >> "CfgCartels" >> "Fixed" >> "allowPoliceNeutralise")] call ULP_fnc_bool }) then {
					private _decreaseAmount = getNumber (missionConfigFile >> "CfgCartels" >> "Fixed" >> "policeNeutralisePerTick");

					_scores = createHashMapFromArray (_scores apply {
						[_x, (_y - _decreaseAmount) min 0]
					});
				} else {
					// If we don't have a group id we can't score
					if (_groupId isEqualTo -1) exitWith {};

					private _score = _scores getOrDefault [_groupId, 0];
					_score = _score + 1;

					_scores set [_groupId, _score];
				};

				// Updates scores for everyone...
				if !(_scores isEqualTo (_obj getVariable ["scores", createHashMap])) then {
					_obj setVariable ["scores", _scores, true];
				};
				
				[configName _config] remoteExecCall ["ULP_fnc_cartelHud", _unitsInZone];
			};

			[_obj, _scores, ((ULP_SRV_TotalTicks % getNumber (missionConfigFile >> "CfgCartels" >> "Fixed" >> "rewardTicks")) isEqualTo 0)] call ULP_SRV_fnc_cartelReward;

			ULP_SRV_Cartels set [_x, [_obj, _area, _scores]];
		};
	} forEach ULP_SRV_Cartels;

	[] call ULP_SRV_fnc_cartelTick; // Restart tick...
}] call ULP_fnc_waitExecute;