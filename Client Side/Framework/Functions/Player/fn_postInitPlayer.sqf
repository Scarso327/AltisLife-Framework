/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_postInitPlayer";

if !(hasInterface) exitWith {};

[{ ULP_Loaded }, [], {
    [[], {
        private _loggedScripts = missionNamespace getVariable["ULP_SeenScripts", []];

        {
            _x params [ "_scriptName", "_fileName", "_isRunning", "_currentLine" ];

            if (_fileName isEqualTo "" && { !(_scriptName in _loggedScripts) }) then {
                [getPlayerUID player, "ScriptLog", [_scriptName]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];

                _loggedScripts pushBack _scriptName;
            };
        } forEach diag_activeSQFScripts;

        missionNamespace setVariable ["ULP_SeenScripts", _loggedScripts];

        if (isFilePatchingEnabled) then {
            ULP_Spector = ["FailedFilePatchingCheck", getPlayerUID player];
            clientOwner publicVariableClient "ULP_Spector";
            
            endMission "CheatCheck";
        };
    }, 10] call ULP_fnc_addEachFrame;
}] call ULP_fnc_waitUntilExecute;