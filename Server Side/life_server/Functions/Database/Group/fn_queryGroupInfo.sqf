/*
** Author: Jack "Scarso" Farhall
** Description: A
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_queryPlayerInfo";

_this params [
	["_unit", objNull, [objNull]],
	["_groupid", 0, [0]],
	["_faction", configNull, [configNull]]
];

if !(isClass (_faction >> "Groups")) exitWith { false };

private _steamid = getPlayerUID _unit;
if (isNull _unit || { _steamid isEqualTo "" } || { _groupid <= 0 }) exitWith { false };

private _group = [_groupid] call ULP_fnc_getGroupById;
private _ranks = getArray (missionConfigFile >> "CfgGroups" >> "ranks");

if (isNull _group) then {
	private _query = [format["SELECT groups.id, groups.tag, groups.owner, groups.type, players.group_level, groups.name, groups.ranks, groups.bank, groups.tax, groups.premium, groups.deposit, groups.withdraw, groups.rank, groups.invite, groups.kick, groups.level, groups.xp, groups.buffs FROM groups INNER JOIN players ON players.group_id = groups.id AND players.pid = '%1' WHERE (groups.owner = '%1' OR groups.id = '%2') AND groups.active='1'",
		_steamid, _groupid
	], 2] call DB_fnc_asyncCall;

	if !(_query isEqualTo "" || { _query isEqualTo [] }) exitWith {
		_query params [
			"_queryId", "_queryTag", "_queryOwner", "_queryType", "_queryRank", "_queryName", "_queryRanks", "_queryBank", "_queryTax", "_queryPremium", "_queryDeposit", "_queryWithdraw", "_queryRankPerm", "_queryInvite", "_queryKick", "_queryLevel", "_queryXp", "_queryBuffs"
		];

		_queryRanks = [_queryRanks] call DB_fnc_mresToArray;

		if !(_groupid isEqualTo _queryid) exitWith {
			// Shouldn't happen...
			[format["Gang Found With Invalid IDs (%1, %2, %3)", _steamid, _groupid, _queryid]] call ULP_fnc_logIt;
			false breakOut "fn_queryPlayerInfo";
		};

		private _group = createGroup [(side _unit), false];
		[_unit] joinSilent _group;

		_group setVariable ["group_id", _queryid, true];
		_group setVariable ["group_tag", _queryowner, true];
		_group setVariable ["group_type", _queryTag, true];
		_group setVariable ["group_owner", _queryowner, true];
		_group setVariable ["group_permissions", [_queryDeposit, _queryWithdraw, _queryRankPerm, _queryInvite, _queryKick], true];
		_group setVariable ["group_progression", [_queryLevel, _queryXp], true];
		_group setGroupIdGlobal [_queryname];

		if !(_queryRanks isEqualTo _ranks) then {
			_group setVariable ["group_ranks", _queryRanks, true];
		};

		if (_queryBank > 0) then {
			_group setVariable ["group_viewablefunds", _queryBank, true];
			_group setVariable ["group_funds", _queryBank];
		};

		if !(_queryTax isEqualTo 0) then {
			_group setVariable ["group_tax", _queryTax, true];
		};

		_queryPremium = [_queryPremium] call ULP_fnc_bool;
		if (_queryPremium) then {
			_group setVariable ["group_premium", _queryPremium, true];
		};

		private _members = [format ["SELECT name, pid, group_level FROM players WHERE group_id = '%1'", _groupid], 2, true] call DB_fnc_asyncCall;
		if !(_members isEqualTo []) then {
			private _hash = createHashMap;

			{
				_hash set [_x select 1, [_x select 0, _x select 2]];
			} forEach _members;

			_group setVariable ["group_members", _hash, true];
		};
		
		_queryBuffs = [_queryBuffs] call DB_fnc_mresToArray;
		if !(_queryBuffs isEqualTo []) then {
			_group setVariable ["group_buffs", (createHashMapFromArray _queryBuffs), true];
		};

		_unit setUnitRank (_ranks select _queryRank);
	};

	false breakOut "fn_queryPlayerInfo";
} else {
	[_group, _unit] call ULP_fnc_joinGroup;
};

_groupid