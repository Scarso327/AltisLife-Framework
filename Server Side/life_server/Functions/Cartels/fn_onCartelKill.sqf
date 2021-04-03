/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_onCartelKill";

_this params [
	["_unit", objNull, [objNull]],
	["_killer", objNull, [objNull]]
];

private _group = group _killer;

if (_unit in (units _group)) exitWith {};

{
	scopeName "fn_findCartel";
	_y params [
		"_obj", "_area", "_scores"
	];

	private _config = _obj getVariable ["config", configNull];

	if !(isNull _config) then {
		private _unitsInZone = [_area, [_unit, _killer], getArray (_config >> "factions")] call ULP_fnc_unitsInZone;

		if ((count _unitsInZone) > 0) then {
			_unitsInZone = [_area, allPlayers, getArray (_config >> "factions")] call ULP_fnc_unitsInZone;
			
			_group = _group getVariable ["group_id", -1];
			private _score = _scores getOrDefault [_group, 0];
			_score = _score + 1;

			_scores set [_group, _score];

			// Updates scores for everyone...
			if !(_scores isEqualTo (_obj getVariable ["scores", createHashMap])) then {
				_obj setVariable ["scores", _scores, true];
			};

			[_obj, _scores, false] call ULP_SRV_fnc_cartelReward;

			[configName _config] remoteExecCall ["ULP_fnc_cartelHud", _unitsInZone];

			breakOut "fn_findCartel";
		};
	};
} forEach ULP_SRV_Cartels;