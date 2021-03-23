/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_invokeEvent";

if (canSuspend) exitWith {
	[ULP_fnc_invokeEvent, _this] call ULP_fnc_directCall;
};

_this params [
	["_event", "", [""]],
	["_params", [], [[]]]
];

private _events = missionNamespace getVariable format["ULPEvent_%1", _event];

if (isNil "_events") exitWith {}; // No events...

{
	if (_x isEqualType 0) then {
		private _eventId = _x;
		_y params [
			"_fnc",
			"_once"
		];

		_params call _fnc;

		if (_once) then {
			[_event, _eventId] call ULP_fnc_removeEventHandler;
		};
	};
} forEach + _events;