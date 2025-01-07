/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onPause";

disableSerialization;

with missionNamespace do {
	private _display = _this select 0;
	private _saveButton = _display displayCtrl 103;
	private _abortButton = _display displayCtrl 104;
	private _fieldButton = _display displayCtrl 122;

	[_saveButton] call ULP_UI_fnc_setSyncButton;

	_fieldButton ctrlEnable false;
	_fieldButton ctrlSetText "https://mantlenetwork.co.uk/";
	_fieldButton ctrlSetTooltip "";

	private _abortDelay = time + getNumber(missionConfigFile >> "CfgSettings" >> "abort_delay");
	
	_abortButton ctrlSetEventHandler["ButtonClick", "with missionNamespace do {
		[] call ULP_fnc_syncPlayerInfo;
		
		[""ReturnedToLobby"", [name player]] remoteExecCall [""ULP_fnc_chatMessage"", -2];
		[""Abort"", true, false] call BIS_fnc_endMission; 
	}; true"];

	if !(["Disconnect", false] call ULP_fnc_checkPower) then {
		_abortButton ctrlEnable false;

		[[_abortButton, _abortDelay], {
			_this params ["_abortButton", "_abortDelay"];
			
			if (isNull _abortButton) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

			if (time < _abortDelay) then {
				_abortButton ctrlSetText format["ABORT (%1)", [_abortDelay - time, "SS.MS"] call BIS_fnc_secondsToString];
			} else {
				_abortButton ctrlSetText "ABORT";
				_abortButton ctrlEnable true;
				[_thisEventHandler] call ULP_fnc_removeEachFrame;
			};
		}] call ULP_fnc_addEachFrame;
	};
};