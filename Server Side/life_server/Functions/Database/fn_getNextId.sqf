/*
** Author: Jack "Scarso" Farhall
** Description: 
**
** Usage: 
**	You must insert the entity using the id returned from this method to avoid auto increment resulting in a different value
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getNextId";

_this params [
	["_table", "", [""]],
	["_idColumn", "id", [""]]
];

// I don't want to spend time refactoring to prepared statements to take advantage of their return insert id
// so this is a workaround to the table status not parsing correctly. Arma 3's basically dead so spending hours
// on this seems pointless.

private _savedIds = missionNamespace getVariable ["ULP_SRV_NextIds", createHashMap];

private _nextId = _savedIds getOrDefault [_table, -1];

if (_nextId isEqualTo -1) then {
	_nextId = ([format["SELECT MAX(%2) FROM `%1`", _table, _idColumn], 2] call DB_fnc_asyncCall) param [0, 1];

	if !(isNil { ULP_DebugMode }) then {
		[format["fn_getNextId: final id: '%1'", _nextId]] call ULP_fnc_logIt;
	};

	if (_nextId isEqualType "") then {
		_nextId = parseNumber _nextId;
	};
};

_nextId = _nextId + 1;

_savedIds set [_table, _nextId];
missionNamespace setVariable ["ULP_SRV_NextIds", _savedIds];

_nextId