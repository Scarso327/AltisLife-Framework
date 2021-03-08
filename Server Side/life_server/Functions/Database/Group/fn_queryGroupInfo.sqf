/*
** Author: Jack "Scarso" Farhall
** Description: A
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_queryPlayerInfo";

_this params [
	["_unit", objNull, [objNull]],
	["_groupid", 0, [0]]
];

private _steamid = getPlayerUID _unit;
if (isNull _unit || { _steamid isEqualTo "" } || { _groupid <= 0 }) exitWith { false };

private _group = [_groupid] call ULP_fnc_getGroupById;

if (isNull _group) then {
	private _query = [format["SELECT id, owner, name, maxmembers, bank FROM groups WHERE (owner = '%1' OR id = '%2') AND active='1'",
		_steamid, _groupid
	], 2] call DB_fnc_asyncCall;

	if !(_query isEqualTo "" || { _query isEqualTo [] }) exitWith {
		_query params [
			"_queryid", "_queryowner", "_queryname"
		];

		if !(_groupid isEqualTo _queryid) exitWith {
			// Shouldn't happen...
			[format["Gang Found With Invalid IDs (%1, %2, %3)", _steamid, _groupid, _queryid]] call ULP_fnc_logIt;
			false breakOut "fn_queryPlayerInfo";
		};

		private _group = createGroup [(side _unit), true];
		[_unit] joinSilent _group;

		_group setVariable ["group_id", _queryid, true];
		_group setVariable ["group_owner", _queryowner, true];
		_group setGroupIdGlobal [_queryname];
	};

	false breakOut "fn_queryPlayerInfo";
} else {
	[_group, _unit] call ULP_fnc_joinGroup;
};

_groupid