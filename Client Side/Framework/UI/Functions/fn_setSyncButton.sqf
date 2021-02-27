/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setSyncButton";

_this params [
	["_saveButton", controlNull, [controlNull]]
];

private _syncDelay = getNumber(missionConfigFile >> "Life_Settings" >> "sync_delay");

// Force wipes the control when clicked...
_saveButton ctrlEnable false;
_saveButton ctrlSetEventHandler["ButtonClick", "with missionNamespace do { [] call ULP_fnc_sync; [(_this select 0)] call ULP_UI_fnc_setSyncButton; }; true"];

_syncDelay = ULP_Last_Sync + _syncDelay;

[[_saveButton, _syncDelay], {
	_this params ["_saveButton", "_syncDelay"];
	
	if (isNull _saveButton) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

	if (time < _syncDelay) then {
		_saveButton ctrlEnable false; // Force disables it again, this fixes it not being disabled when button is pressed...
		_saveButton ctrlSetText format["SYNC DATA (%1)", [_syncDelay - time, "MM:SS"] call BIS_fnc_secondsToString];
	} else {
		_saveButton ctrlSetText "SYNC DATA";
		_saveButton ctrlEnable true;
		[_thisEventHandler] call GTA_fnc_removeEachFrameHandler;
	};
}] call ULP_fnc_addEachFrame;