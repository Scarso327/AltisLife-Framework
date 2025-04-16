/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onPvpVoteStarted";

if !(hasInterface) exitWith {};

if !([["NotifyConflict", "PVP"] call ULP_fnc_getOption] call ULP_fnc_bool) exitWith {};

_this params [ "_modes" ];

missionNamespace setVariable ["ULP_PVPVoted", nil];

ULP_PVPModes = _modes;

private _duration = [getNumber (missionConfigFile >> "CfgPvpModes" >> "voteDuration"), "MM:SS"] call BIS_fnc_secondsToString;

[format ["<t color='#ff0000' size='1.5px'>PVP Event<br/></t><t color='#ffffff' size='1px'>Voting has now started for the next PVP event. You can vote using /vote. The vote lasts %1", _duration]] call ULP_fnc_hint;