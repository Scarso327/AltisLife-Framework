/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscPvpScoreboard_OnEachFrame";
disableSerialization;

_this params [
	"_display"
];

if (isNull _display) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

if (isNil "ULP_SRV_CurrentScores") exitWith {
	["RscPvpScoreboard"] call ULP_UI_fnc_destroyLayer;
};

private _timeLeft = ((missionNamespace getVariable ["ULP_SRV_PvpConflictTick", serverTime]) - serverTime) max 0;

private _ctrlHeader = _display displayCtrl 6402;
_ctrlHeader ctrlSetStructuredText parseText format ["<t align='left' size='1'>Scoreboard</t><t align='right' size='1'>Points in %1</t>", [_timeLeft, "MM:SS"] call BIS_fnc_secondsToString];

if ((_display getVariable ["lastList", createHashMap]) isEqualTo ULP_SRV_CurrentScores) exitWith {};

private _ctrlList = _display displayCtrl 6401;
lbClear _ctrlList;

{
	private _group = [_x] call ULP_fnc_getGroupById;

	private _index = _ctrlList lbAdd ([_group] call ULP_fnc_getGroupName);

	_ctrlList lbSetTextRight [_index, [_y] call ULP_fnc_numberText];
	_ctrlList lbSetValue [_index, -_y];
} forEach ULP_SRV_CurrentScores;

lbSortByValue _ctrlList;

_display setVariable ["lastList", ULP_SRV_CurrentScores];