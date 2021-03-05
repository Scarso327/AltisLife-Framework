/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_addEventHandler";

if (canSuspend) exitWith {
	[ULP_fnc_addEventHandler, _this] call ULP_fnc_directCall;
};

_this params [
	["_event", "", [""]],
	["_eventFnc", nil, [{}]],
	["_once", false, [true]]
];

if (_event isEqualTo "" || { isNil "_eventFnc" }) exitWith { -1 };

private _eventsVar = format["ULPEvent_%1", _event];
private _events = missionNamespace getVariable _eventsVar;

if (isNil "_events") then {
	_events = createHashMap;
	missionNamespace setVariable [_eventsVar, _events];
};

private _index = _events getOrDefault ["#lastId", -1];
_index = _index + 1;

_events set [_index, [_eventFnc, _once]];
_events set ["#lastId", _index];

_index