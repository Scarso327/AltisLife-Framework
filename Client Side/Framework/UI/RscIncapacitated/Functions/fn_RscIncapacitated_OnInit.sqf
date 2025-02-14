/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscIncapacitated_OnInit";

_this params [ "_display", "_params" ];

if (isNull _display) exitWith {};

_params params [
	["_deathMessage", "<t align='center' size='2'>You died somehow</t>", [""]]
];

(_display displayCtrl 9001) ctrlSetStructuredText parseText _deathMessage;

private _startTime = serverTime;
private _endTime = getNumber(missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "BleedOutTime");

private _progressBar = _display displayCtrl 9004;
private _medicsCountText = _display displayCtrl 9002;
private _medicalRequestedText = _display displayCtrl 9005;

// If in redzone, change bleedout...
if (["redzone_"] call ULP_fnc_isUnitsInZone) then {
	_endTime = _endTime * getNumber(missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "RedzonePercentage");
};

if (localNamespace getVariable ["ULP_LastRevived", -300] > (serverTime - 300)) then {
	_endTime = _endTime * (((-(((localNamespace getVariable ["ULP_LastRevived", serverTime]) - serverTime) * 0.5) / 100) min 1) max 0.25);
};

private _bleedOutTime = _startTime + _endTime;
player setVariable ["IncapacitatedBleedOutTime", _bleedOutTime, true];

_display setVariable ["endTime", _bleedOutTime];
_display setVariable ["status", nil];

_display setVariable ["eachFrame", ([[_display, _startTime, _progressBar, _medicsCountText, _medicalRequestedText], ULP_UI_fnc_RscIncapacitated_OnEachFrame] call ULP_fnc_addEachFrame)];

[["RscHUD"] call ULP_UI_fnc_getLayer] call ULP_UI_fnc_closeHUD;

setCurrentChannel 5;