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
	if (_y >= _highest) then {
		// New highest, remove previous...
		if (_y > _highest) then {
			_owners = [];
		};

		_owners pushBackUnique _x;
		_highest = _y;
	};
} forEach _scores;

// We have a maybe contested highest score...
if ((count _owners) > 0) exitWith {
	private _group = grpNull;

	private _marker = _cartel getVariable ["marker", ""];
	private _markerText = getText (_config >> "name");
	
	// We have an uncontested highest score...
	if ((count _owners) isEqualTo 1) then {
		_group = [_owners param [0, -5]] call ULP_fnc_getGroupById;
		if (isNull _group) exitWith { false breakOut "fn_cartelReward"; };

		_markerText = format ["%1 | %2", _markerText, [_group] call ULP_fnc_getGroupName];
	};

	if !(_marker isEqualTo "") then {
		_marker setMarkerText _markerText;
	};

	_cartel setVariable ["owner", [_group, _highest], true];
	true
};

false