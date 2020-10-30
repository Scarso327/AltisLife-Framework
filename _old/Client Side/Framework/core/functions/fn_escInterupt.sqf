#include "..\..\script_macros.hpp"

/*
    File: fn_escInterupt.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Monitors when the ESC menu is pulled up and blocks off
    certain controls when conditions meet.
*/
disableSerialization;

private _escSync = { 
    disableSerialization;
    private _abortButton = CONTROL(49,104);
    private _abortTime = LIFE_SETTINGS(getNumber,"escapeMenu_timer");
    private _timeStamp = time + _abortTime;

    waitUntil {
        _abortButton ctrlSetText format ["Abort available in %1",[(_timeStamp - time),"SS.MS"] call BIS_fnc_secondsToString];
        _abortButton ctrlCommit 0;
        if (dialog && {isNull (findDisplay 7300)}) then {closeDialog 0};

        round(_timeStamp - time) <= 0 || {isNull (findDisplay 49)}
    };

    _abortButton ctrlSetText localize "STR_DISP_INT_ABORT";
    _abortButton ctrlCommit 0;
    _abortButton ctrlEnable true;
};

private _canUseControls = {
    (playerSide isEqualTo west) || {!((player getVariable ["restrained",false]) || {player getVariable ["Escorting",false]} || {player getVariable ["transporting",false]} || {life_is_arrested} || {life_istazed} || {life_isknocked})}
};

for "_i" from 0 to 1 step 0 do {
    waitUntil {!isNull (findDisplay 49)};
    private _display = (findDisplay 49);
    private _abortButton = _display displayCtrl 104;
    _abortButton buttonSetAction "call SOCK_fnc_updateRequest; [player] remoteExec [""TON_fnc_cleanupRequest"",2];";
    private _respawnButton = _display displayCtrl 1010;
    private _fieldManual = _display displayCtrl 122;
    private _saveButton = _display displayCtrl 103;
    _saveButton ctrlSetText "";

    // Block Endmission cheat
    _display displayAddEventHandler ["KeyDown", {
		_this call {
			params ["","_key","_shift"];
			if (_key isEqualTo 74 && {_shift}) exitWith {
				if !(userInputDisabled) then {
					disableUserInput true;

					if (userInputDisabled) then {
						disableUserInput false;
					};
				};
				true
			};
		};
	}];
    
    //Extras
    if (LIFE_SETTINGS(getNumber,"escapeMenu_displayExtras") isEqualTo 1) then {
        private _topButton = _display displayCtrl 2;
        _topButton ctrlEnable false;
        _topButton ctrlSetText format ["LifePLUS Framework v1"];
        _saveButton ctrlEnable false;
        _saveButton ctrlSetText format ["Player UID: %1",getPlayerUID player];
    };

    //Block off our buttons first.
    _abortButton ctrlEnable false;
    _fieldManual ctrlEnable false; //Never re-enable, blocks an old script executor.
    _fieldManual ctrlShow false;

    if (call _canUseControls) then {
        [] spawn _escSync;
    } else {
        _respawnButton ctrlEnable false;
    };

    waitUntil {isNull (findDisplay 49) || {!alive player}};
    if (!isNull (findDisplay 49) && {!alive player}) then {
        (findDisplay 49) closeDisplay 2;
    };
};
