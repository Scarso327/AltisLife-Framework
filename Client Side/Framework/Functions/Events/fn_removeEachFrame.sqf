/*
** Author: Jack "Scarso" Farhall
** Description: 
** Credit: https://github.com/CBATeam/CBA_A3/blob/master/addons/common/fnc_removePerFrameHandler.sqf
*/
scopeName "fn_removeEachFrame";

_this params [
	["_handle", -1, [0]]
];

[{
	_this params [ "_handle" ];

	private _index = ULP_eachFrameEventsHandles param [_handle];

	if (isNil "_index") exitWith { false };

	ULP_eachFrameEventsHandles set [_handle, nil];
	(ULP_eachFrameEventsHandlers select _index) set [1, {}];

	if (ULP_eachFrameEventsHandlersToRemove isEqualTo []) then {
		[[], {
			diag_log "Delete Handlers";
			{
                ULP_eachFrameEventsHandlers set [_x, objNull];
            } forEach ULP_eachFrameEventsHandlersToRemove;

            ULP_eachFrameEventsHandlers = ULP_eachFrameEventsHandlers - [objNull];
            ULP_eachFrameEventsHandlersToRemove = [];

            {
                _x params [ "", "", "_handleIndex" ];
                ULP_eachFrameEventsHandles set [_handleIndex, _forEachIndex];
            } forEach ULP_eachFrameEventsHandlers;
		}] call ULP_fnc_execNextFrame;
	};

	ULP_eachFrameEventsHandlersToRemove pushBackUnique _index;

	true
}, [_handle]] call ULP_fnc_directCall