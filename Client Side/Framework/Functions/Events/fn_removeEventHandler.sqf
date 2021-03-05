/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_removeEventHandler";

if (canSuspend) exitWith {
	[ULP_fnc_removeEventHandler, _this] call ULP_fnc_directCall;
};

_this params [
	["_event", "", [""]],
	["_id", -1, [0]]
];

if (_event isEqualTo "" || { _id < 0 }) exitWith { false };

private _events = missionNamespace getVariable format["ULPEvent_%1", _event];

if (isNil "_events") exitWith {}; // No events...

_events deleteAt _id;

if ((count _events) <= 1) then {
	_events = nil;
};

true