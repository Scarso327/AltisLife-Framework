/*
** Author: Jack "Scarso" Farhall
** Description: Checks if a cached value exists for the given key, and returns it if it does. Otherwise, it calls the provided function to generate the value, caches it, and returns it.
*/

_this params [
	["_call", [{}, []], [[]]],
	["_key", "", [""]],
	["_ttl", 1, [0]],
	["_namespace", missionNamespace]
];

if ((_namespace getVariable [_key, [0]]) select 0 > diag_tickTime) exitWith {
	// Cache hit, return the cached value
	(_namespace getVariable [_key, [0]]) select 1
};

_call params [
	["_func", {}, [{}]],
	["_params", [], [[]]]
];

private _result = _params call _func;

_namespace setVariable [_key, [diag_tickTime + _ttl, _result]];

_result