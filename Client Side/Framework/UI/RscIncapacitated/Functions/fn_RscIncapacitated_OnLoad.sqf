/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscIncapacitated_OnLoad";

_this params [ "_display" ];

if (isNull _display) exitWith {};

uiNamespace setVariable ['RscIncapacitated', _display];

// Create Incapaciated screen effect...
private _effectBlur = ppEffectCreate ["DynamicBlur", 300];
_effectBlur ppEffectEnable true;
_effectBlur ppEffectAdjust [2.5];
_effectBlur ppEffectCommit 3;

private _effectColour = ppEffectCreate ["colorCorrections", 301];
_effectColour ppEffectEnable true;
_effectColour ppEffectAdjust [1, 1, 0, [0, 0, 0, 0.7], [1, 0, 0, 0.5],[1, 1, 1, 0]]; 
_effectColour ppEffectCommit 3;

private _effectId = [[_effectBlur, {}], [_effectColour, {}]] call ULP_fnc_createEffect;
if (_effectId isEqualType 0) then { _display setVariable ["IncapacitatedEffect", _effectId] };

(_display displayCtrl 9001) ctrlSetStructuredText parseText (localNamespace getVariable ["ULP_DeathMessage", "<t align='center' size='2'>You died somehow</t>"]);

private _startTime = time;
private _endTime = getNumber(missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "BleedOutTime");

private _progressBar = _display displayCtrl 9004;
private _medicsCountText = _display displayCtrl 9002;
private _medicalRequestedText = _display displayCtrl 9005;

// If in redzone, change bleedout...
if (["redzone_"] call ULP_fnc_isUnitsInZone) then {
	_endTime = _endTime * getNumber(missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "RedzonePercentage");
};

if (localNamespace getVariable ["ULP_LastRevived", -300] > (time - 300)) then {
	_endTime = _endTime * (((-(((localNamespace getVariable ["ULP_LastRevived", time]) - time) * 0.5) / 100) min 1) max 0.25);
};

_display setVariable ["endTime", _startTime + _endTime];
_display setVariable ["status", "Waiting to respawn..."];

_display setVariable ["eachFrame", ([[_display, _startTime, _progressBar, _medicsCountText, _medicalRequestedText], ULP_UI_fnc_RscIncapacitated_OnEachFrame] call ULP_fnc_addEachFrame)];

setCurrentChannel 5;