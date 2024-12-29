/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_removeEachFrame";

// See https://github.com/CBATeam/CBA_A3/wiki/Per-Frame-Handlers

if (canSuspend) exitWith {
	[ULP_fnc_removeEachFrame, _this] call ULP_fnc_directCall;
};

_this params [
	["_index", -1, [0]]
];

if (_index < 0 || { _index >= (count ULP_eachFrameEventsHandles) } || { isNil { ULP_eachFrameEventsHandles select _index } }) exitWith { false };

[{
	_this params [ "_index" ];

	ULP_eachFrameEventsHandlers deleteAt (ULP_eachFrameEventsHandles select _index);
	ULP_eachFrameEventsHandles set [_index, nil];

	{
		_x params [ "", "", "_handleIndex" ];

		ULP_eachFrameEventsHandles set [_handleIndex, _forEachIndex];
	} forEach ULP_eachFrameEventsHandlers;
}, [_index]] call ULP_fnc_directCall;

true