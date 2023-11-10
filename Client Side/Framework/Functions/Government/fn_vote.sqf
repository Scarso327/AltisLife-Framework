/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vote";

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _pollingStation = _display getVariable ["pollingStation", objNull];
if (isNull _pollingStation) exitWith {};

private _list = _display displayCtrl 5202;

private _candidate = (_list lbData (lbCurSel _list));
if (_candidate isEqualTo "") exitWith {
	["You must select someone you wish to vote for..."] call ULP_fnc_hint;
};

closeDialog 0;

if !(missionNamespace getVariable ["ULP_SRV_Setting_Election", false]) exitWith {
	["No election is currently taking place..."] call ULP_fnc_hint;
};

// Easy way to avoid spam, they'd have to relog to get past and server side would block multiple votes
if (player getVariable ["voted", false]) exitWith {
	["You've already voted in this election!"] call ULP_fnc_hint;
};

if (player getVariable ["voting", false]) exitWith {
	["Your vote is already being processed!"] call ULP_fnc_hint;
};

player setVariable ["voting", true];

["ElectionVoteSubmitted", {
	private _message = _this param [0, "You have successfully cast your vote in the election..."];
	[_message] call ULP_fnc_hint;

	player setVariable ["voting", nil];

	if (_message isEqualTo "You have successfully cast your vote in the election...") then {
		player setVariable ["voted", true];
	};
}, true] call ULP_fnc_addEventHandler;

["Casting Vote..."] call ULP_fnc_hint;
[_pollingStation, player, _candidate] remoteExecCall ["ULP_SRV_fnc_submitVote", RSERV];