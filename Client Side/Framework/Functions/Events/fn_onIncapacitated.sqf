/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onIncapacitated";

if (canSuspend) exitWith {
    [ULP_fnc_onIncapacitated, _this] call ULP_fnc_directCall;
};

_this params [
	["_unit", objNull, [objNull]],
	["_killer", objNull, [objNull]]
];

if (isNull _unit || { !(isPlayer _unit) } || { !(_unit isEqualTo player) } || { isDowned(_unit) }) exitWith {};

if !(isNull objectParent _unit) then { moveOut _unit }; // Move them out of any vehicles they may be in...

_unit switchmove "";
_unit setUnconscious true;

setKiller(_unit, _killer);
setDowned(_unit);

if ([] call ULP_UI_fnc_isProgress) then {
	[(["RscProgress"] call ULP_UI_fnc_getLayer), false] call ULP_UI_endProgress;
};

if ([] call ULP_fnc_isEscorting) then {
	detach ULP_Escort;
	ULP_Escort = nil;
};

private _deathMessage = format["<t align='center' size='2'>You killed yourself</t>"];

// Notify the server...
if (!isNull _killer && { isPlayer _killer } && { !(_killer isEqualTo _unit) }) then {
	_deathMessage = format["<t align='center' size='2'>%1 seriously injured you</t>", name _killer];

	[format ["%1 was seriously injured by %2", 
		_unit getVariable ["realname", name _unit], 
		_killer getVariable ["realname", name _killer]
	]] remoteExecCall ["systemChat", RCLIENT];
} else {
	[format ["%1 was seriously injured", 
		_unit getVariable ["realname", name _unit]
	]] remoteExecCall ["systemChat", RCLIENT];
};

[] call ULP_fnc_onUnrestrained;
player setVariable ["surrender", nil];

[["RscHUD"] call ULP_UI_fnc_getLayer] call ULP_UI_fnc_closeHUD;
[] spawn ULP_UI_fnc_closeDialogs; // Makes sure all dialogs are closed...
[] call ULP_fnc_wipeEffects;

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
if (_effectId isEqualType 0) then { uiNamespace setVariable ["IncapacitatedEffect", _effectId] };

if (["RscIncapacitated", "PLAIN", 3] call ULP_UI_fnc_createLayer) then {
	private _incapUi = ["RscIncapacitated"] call ULP_UI_fnc_getLayer;
	if (isNull _incapUi) exitWith {}; // Shouldn't happen but we'll be safe...

	(_incapUi displayCtrl 9001) ctrlSetStructuredText parseText _deathMessage;

	ULP_CanRespawn = false;

	private _startTime = time;
	private _respawnTime = getNumber(missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "WaitForBleedOutTime");
	private _endTime = time + _respawnTime + getNumber(missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "BleedOutTime");

	if !(isNil { uiNamespace getVariable "_fnc_bleedout" }) then {
		 [uiNamespace getVariable "_fnc_bleedout"] call ULP_fnc_removeEachFrame;
	};

	private _rspMsg = "Waiting to respawn...";

	uiNamespace setVariable ["_fnc_bleedout", ([[_incapUi, _unit, _startTime, _respawnTime, _endTime, _rspMsg], {
		_this params [
			["_incapUi", displayNull, [displayNull]],
			["_unit", objNull, [objNull]],
			"_startTime", "_respawnTime", "_endTime", // Time vars...
			["_rspMsg", "Waiting to respawn...", [""]]
		];

		if !(alive _unit || { isDowned(_unit) }) exitWith {
			uiNamespace setVariable ["_fnc_bleedout", nil];
			[_thisEventHandler] call ULP_fnc_removeEachFrame;
		};

		// My time has come...
		if (time >= _endTime) exitWith {
			_unit setDamage 1;
			uiNamespace setVariable ["_fnc_bleedout", nil];
			[_thisEventHandler] call ULP_fnc_removeEachFrame;
		};

		if (time >= (_startTime + _respawnTime) && { !ULP_CanRespawn }) then {
			ULP_CanRespawn = true;
			_rspMsg = "Press <t color = '#7300e6'>Shift + F</t> to respawn...";
		};

		(_incapUi displayCtrl 9002) ctrlSetStructuredText parseText format [
			"<t align='left' size='1'>%1</t><t align='right' size='1'>Nearest Medic: 0m</t>",
			_rspMsg
		];

		(_incapUi displayCtrl 9004) progressSetPosition (1 - ((time - _startTime) / (_endTime - _startTime)));
    }] call ULP_fnc_addEachFrame)];
};