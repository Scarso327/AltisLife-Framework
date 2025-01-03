/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_cartelReward";

_this params [
	["_cartel", objNull, [objNull]],
	["_scores", createHashMap, [createHashMap]],
	["_doReward", false, [false]]
];

private _config = _cartel getVariable ["config", configNull];
if (isNull _cartel || { isNull _config } || { (count _scores) isEqualTo 0 }) exitWith { false };

private _owners = [];
private _highest = 0;

{
	if (_y isEqualTo 0) exitWith {};

	if (_y >= _highest) then {
		// New highest, remove previous...
		if (_y > _highest) then {
			_owners = [];
		};

		_owners pushBackUnique _x;
		_highest = _y;
	};
} forEach _scores;

private _marker = _cartel getVariable ["marker", ""];
private _markerText = getText (_config >> "name");

// We have a maybe contested highest score...
if ((count _owners) > 0) then {
	private _group = grpNull;
	
	// We have an uncontested highest score...
	if ((count _owners) isEqualTo 1) then {
		_group = [_owners param [0, -5]] call ULP_fnc_getGroupById;
		if (isNull _group) exitWith { false breakOut "fn_cartelReward"; };

		if (_doReward) then {
			private _units = count playableUnits;
			private _cut = round ((((getArray (missionConfigFile >> "CfgCartels" >> "Fixed" >> "rewardAmounts") select ([_units > 25] call ULP_fnc_bool)) * _highest) * _units) / 2);
			
			[_group, _cut, true] call ULP_SRV_fnc_handleGroupFunds;
			[_group, "Cartel"] call ULP_SRV_fnc_addGroupXP;
			[_group, selectRandom (("isClass _x" configClasses (missionConfigFile >> "CfgGroups" >> "Buffs")) apply { configName _x })] call ULP_SRV_fnc_addGroupBuff;

			private _groupUnits = units _group;
			private _totalUnitsInGroup = count _groupUnits;
			
			if !(_totalUnitsInGroup isEqualTo 0) then {
				private _memberCut = round (_cut / _totalUnitsInGroup);

				{
					["CartelPayout", [_markerText, _memberCut, _cut]] remoteExecCall ["ULP_fnc_invokeEvent", _x];
				} forEach _groupUnits;
			};
		};

		_markerText = format ["%1 | %2", _markerText, [_group] call ULP_fnc_getGroupName];
	};

	_cartel setVariable ["owner", [_group, _highest], true];
};

if !(_marker isEqualTo "") then {
	_marker setMarkerText _markerText;
};