/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setPrisonTime";

_this params [
	["_target", objNull, [objNull]]
];

if (isNull _target || { !([_target] call ULP_fnc_isRestrained) } || { isDowned(player) } || { isDowned(_target) }) exitWith {};

private _prison = missionConfigFile >> "CfgPrison" >> worldName;
if !(isClass _prison) exitWith { false };

if !([player] call ULP_fnc_canImprison || { [_target] call ULP_fnc_canImprisoned }) exitWith {
	["You're unable to send anyone to prison from here!"] call ULP_fnc_hint;
};

private _max = 
	if ([player] call ULP_fnc_onDuty && { ["Imprison", false] call ULP_fnc_checkPower }) then { 
		getNumber (_prison >> "adminDuraction");
	} else {
		getNumber (_prison >> "maxDuraction");
	}; 

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _max], [_target, _prison, _max],
	{
		_this params [
			["_target", objNull, [objNull]],
			["_prison", configNull, [configNull]],
			["_max", 1, [0]],
			["_display", displayNull, [displayNull]],
			["_duraction", 1, [0]]
		];

		if (_duraction > _max) exitWith {
			[format ["You can only sentence someone for a max of <t color='#B92DE0'>%1</t>", [_max, "MM:SS"] call BIS_fnc_secondsToString]] call ULP_fnc_hint;
		};

		detach _target;
		[_target, _duraction, player] remoteExecCall ["ULP_fnc_imprison", _target];

		["Prisoned", [name _target, [player, true] call ULP_fnc_getName, [_duraction, "MM"] call BIS_fnc_secondsToString]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];

		[format["You have sentenced <t color='#B92DE0'>%1</t> for <t color='#B92DE0'>%2</t>", name _target, [_duraction, "MM:SS"] call BIS_fnc_secondsToString]] call ULP_fnc_hint;

		if !([player] call ULP_fnc_onDuty) then { 
			private _unitRep = _target getVariable ["reputation", 0];

			[player, missionConfigFile >> "CfgReputation" >> "Types" >> (switch (true) do {
				case (_unitRep >= 500): { "ArrestHigh" };
				case (_unitRep > -500): { "ArrestNorm" };
				default { "ArrestLow" };
			})] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];

			["FirstArrest"] call ULP_fnc_achieve; 
		};

		["ArrestedSomeone", [_target, _duraction]] call ULP_fnc_invokeEvent;

		[getPlayerUID player, "Imprisoned", [_target, _duration]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
	}, false, "[_this, ""MM:SS""] call BIS_fnc_secondsToString", false
] call ULP_fnc_selectNumber;