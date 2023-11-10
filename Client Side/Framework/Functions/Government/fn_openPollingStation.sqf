/*
** Author: Jack "Scarso" Farhall
** Description: Opens dialog with candidates in current election
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openPollingStation";

_this params [
	["_trader", objNull, [objNull]]
];

if !(missionNamespace getVariable ["ULP_SRV_Setting_Election", false]) exitWith {
	["No election is currently taking place..."] call ULP_fnc_hint;
};

if (createDialog "DialogPollingStation") then {
	private _display = findDisplay 5200;
	if (isNull _display) exitWith {};

	_display setVariable ["pollingStation", _trader];

	private _list = _display displayCtrl 5202;
	lbClear _list;

	private _button = _display displayCtrl 5203;
	_button ctrlEnable false;

	_list lbAdd "Retriving Candidates...";

	_display setVariable ["candidates_received", (["CandidatesReceived", {
		_this params [
			["_candidates", [], [[]]]
		];

		private _display = findDisplay 5200;
		if (isNull _display) exitWith { [_event, _eventId] call ULP_fnc_removeEventHandler; };
		
		private _list = _display displayCtrl 5202;
		lbClear _list;

		if ((count _candidates) isEqualTo 0) exitWith {
			["No candidates enlisted for this election..."] call ULP_fnc_hint;
			closeDialog 0;

			[_event, _eventId] call ULP_fnc_removeEventHandler;
		};

		private _button = _display displayCtrl 5203;
		_button ctrlEnable true;

		{
			_x params [ "", "_steamId", "_name", "_groupName" ];

			private _title = format ["%1 [%2]", _name, _groupName];

			private _item = _list lbAdd _title;
			_list lbSetData [_item, _steamId];
			_list lbSetTooltip [_item, _title];
		} forEach _candidates;
	}] call ULP_fnc_addEventHandler)];

	[] remoteExecCall ["ULP_SRV_fnc_getCandidates", RSERV];
};