/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onPvpVoteFinished";

if !(hasInterface) exitWith {};

missionNamespace setVariable ["ULP_PVPModes", nil];

_this params [
	["_mode", configNull, [configNull]],
	["_location", configNull, [configNull]]
];

if (isNull _location) exitWith {};

private _optionValue = ["Teleport", "PVP"] call ULP_fnc_getOption;

private _position = getMarkerPos (getText (_location >> "teleportLocation"));
if (_position isEqualTo [0,0,0] 
	|| { [] call ULP_fnc_isInputBlocked } 
	|| { !((vehicle player) isEqualTo player) }
	|| { !(missionNamespace getVariable ["ULP_PVPVoted", false]) }
	|| { !(["Rebel"] call ULP_fnc_hasLicense) }) exitWith {};

switch (_optionValue) do {
	case 2: {
		[
			(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
			"Do you want to teleport to the PVP event?", [_position],
			{	
				_this params [
					["_position", [], [[]]]
				];

				if (_position isEqualTo [] || { [] call ULP_fnc_isInputBlocked } || { !((vehicle player) isEqualTo player) }) exitWith {};

				player setPosASL AGLtoASL _position;
			}, {}, false
		] call ULP_fnc_confirm;
	};
	case 1: {
		player setPosASL AGLtoASL _position;
	};
	default {};
};