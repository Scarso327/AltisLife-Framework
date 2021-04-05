/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_createGroup";

_this params [
	["_owner", objNull, [objNull]],
	["_tag", "", [""]],
	["_name", "", [""]]
];

private _steamid = getPlayerUID _owner;
if (isNull _owner || { _steamid isEqualTo "" } || { _tag isEqualTo "" } || { _name isEqualTo "" }) exitWith {};

private _id = -1;
_tag = [_tag] call DB_fnc_mresString;
_name = [_name] call DB_fnc_mresString;

private _query = [format["SELECT id, tag, name, active FROM groups WHERE tag = '%1' OR name = '%2'",
	_tag, _name
], 2] call DB_fnc_asyncCall;

if !(_query isEqualTo "" || { _query isEqualTo [] }) then {
	scopeName "fn_createGroup_check";
	_query params [
		"_queryId", "_queryTag", "_queryName", "_queryActive"
	];

	if ([_queryActive] call ULP_fnc_bool) then {
		if (_queryTag isEqualTo _tag) exitWith {
			["GroupCreationFailed", ["The group tag you've entered is taken, please use another tag..."]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
			false breakOut "fn_createGroup";
		};
		if (_queryName isEqualTo _name) exitWith {
			["GroupCreationFailed", ["The group name you've entered is taken, please use another name..."]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
			false breakOut "fn_createGroup";
		};

		true breakOut "fn_createGroup_check";
	};

	// This gang has something matching but is also inactive, to save queries we can just update this one as ours...
	[format["UPDATE groups SET owner = '%1', tag = '%2', name = '%3', bank = '0', active = '1' WHERE id = '%4'",
		_steamid, _tag, _name, _queryId
	], 1] call DB_fnc_asyncCall;

	private _group = [_queryId] call ULP_fnc_getGroupById;

	if (isNull _group) then {
		_group = createGroup [(side _owner), true];
		[_owner] joinSilent _group;

		_group setVariable ["group_id", _queryId, true];
		_group setVariable ["group_owner", _steamid, true];
		_group setGroupIdGlobal [_name];
	} else {
		// Make sure no one is in the group still..
		{
			[_x] joinSilent createGroup [(side _x), true];
		} forEach ((units _group) - [_owner]);

		[_owner] joinSilent _group;
		
		// Make sure all group values match...

		if !((_group getVariable ["group_owner", ""]) isEqualTo _steamid) then {
			_group setVariable ["group_owner", _steamid, true];
		};

		if !((groupId _group) isEqualTo _name) then {
			_group setGroupIdGlobal [_name];
		};
	};

	_id = _queryId;
} else {
	// Get ID...
	_id = ["groups"] call ULP_SRV_fnc_getNextId;

	// Insert...
	[format[
		"INSERT INTO groups (owner, tag, name) VALUES ('%1', '%2', '%3');", 
		_steamid, _tag, _name
	], 1] call DB_fnc_asyncCall;

	private _group = createGroup [(side _owner), true];
	[_owner] joinSilent _group;

	_group setVariable ["group_id", _id, true];
	_group setVariable ["group_owner", _steamid, true];
	_group setGroupIdGlobal [_name];
};

// Update Owner's Gang ID...
[format["UPDATE players SET group_id = '%1' WHERE pid = '%2'",
	_id, _steamid
], 1] call DB_fnc_asyncCall;

["GroupCreationSucceeded", [_id]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];