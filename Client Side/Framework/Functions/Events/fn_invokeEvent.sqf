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

[format ["fn_invokeEvent: '%1' invoked with '%2'", _event, _params], true] call ULP_fnc_logIt;

private _eventHandlers = missionNamespace getVariable format["ULPEvent_%1", _event];

if (isNil "_eventHandlers") exitWith {
	[format ["fn_invokeEvent: '%1' invoked but no handlers added", _event], true] call ULP_fnc_logIt;
};

// Info on JIP usage, the handlers must have been registered to be called. 
// This means you must ensure when a player is JIP - the handlers are executed before JIP during initialisation.
if (isRemoteExecutedJIP && { !(_event in getArray (missionConfigFile >> "CfgRemoteExec" >> "Functions" >> "ULP_fnc_invokeEvent" >> "validJipEvents")) }) exitWith {
	[format ["fn_invokeEvent: '%1' invoked via JIP but isn't whitelisted", _event], true] call ULP_fnc_logIt;
};

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
} forEach + _eventHandlers;