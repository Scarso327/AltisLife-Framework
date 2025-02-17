/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_handleGroupAlliance";

_this params [
	["_groupAId", -1, [0]],
	["_groupBId", -1, [0]],
	["_remove", false, [true]]
];

if (_groupAId isEqualTo -1 || { _groupBId isEqualTo -1 }) exitWith { false };

if (_remove) then {
	[format[
		"UPDATE `group_alliances` SET `active`='0' WHERE (`group_a_id`='%1' AND `group_b_id`='%2') OR (`group_a_id`='%2' AND `group_b_id`='%1')", 
		[_groupAId, ""] call ULP_fnc_numberText, [_groupBId, ""] call ULP_fnc_numberText
	], 1] call DB_fnc_asyncCall;
} else {
	private _allianceRecord = [format[
		"SELECT `id` FROM `group_alliances` WHERE (`group_a_id`='%1' AND `group_b_id`='%2') OR (`group_a_id`='%2' AND `group_b_id`='%1')", 
		[_groupAId, ""] call ULP_fnc_numberText, [_groupBId, ""] call ULP_fnc_numberText
	], 2] call DB_fnc_asyncCall;

	private _recordId = _allianceRecord param [0, -1, [0]];

	// Insert new record
	if (_recordId isEqualTo -1) exitWith {
		[format[
			"INSERT INTO `group_alliances` (`group_a_id`, `group_b_id`) VALUES ('%1', '%2');", 
			[_groupAId, ""] call ULP_fnc_numberText, [_groupBId, ""] call ULP_fnc_numberText
		], 1] call DB_fnc_asyncCall;
	};

	// Activate old
	[format[
		"UPDATE `group_alliances` SET `active`='1' WHERE `id`='%1'", 
		[_recordId, ""] call ULP_fnc_numberText
	], 1] call DB_fnc_asyncCall;
};