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
	if ([_killer, ["Civilian"]] call ULP_fnc_isFaction) then {
		[getPlayerUID player, "OffencesAgainstThePerson", "Section20",
			format [
				"Suspected Weapon: %1", 
				([currentWeapon _killer] call ULP_fnc_itemCfg) param [5, "Unknown"]
			]
		] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];
	};

	_deathMessage = format["<t align='center' size='2'>%1 seriously injured you</t>", name _killer];
	["InjuredBy", [_unit getVariable ["realname", name _unit], _killer getVariable ["realname", name _killer]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
} else {
	["Injured", [_unit getVariable ["realname", name _unit]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
};

[] call ULP_fnc_onUnrestrained;
player setVariable ["surrender", nil];

[["RscHUD"] call ULP_UI_fnc_getLayer] call ULP_UI_fnc_closeHUD;
[] spawn ULP_UI_fnc_closeDialogs; // Makes sure all dialogs are closed...
[] call ULP_fnc_wipeEffects;

private _wounds = createHashMap;
private _possibleWounds = ("isClass _x" configClasses (missionConfigFile >> "CfgMedical" >> "Damage"));

{
	private _partWounds = createHashMap;
	private _amount = (round (random getNumber (missionConfigFile >> "CfgMedical" >> "Damage" >> "amount"))) max 1;

	for "_i" from 0 to _amount do {
		private _wound = selectRandom _possibleWounds;
		_partWounds set [configName _wound, (_partWounds getOrDefault [configName _wound, 0]) + ((round (random getNumber (_wound >> "amount"))) max 1)];
	};

	_wounds set [_x, _partWounds];
} forEach ["Head", "Body", "RArm", "LArm", "RLeg", "LLeg"];

player setVariable ["IncapacitatedWounds", _wounds, true];

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
	private _endTime = getNumber(missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "BleedOutTime");
	private _respawnPer = getNumber(missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "AllowBleedoutPercentage");
	private _progressBar = _incapUi displayCtrl 9004;

	// If in redzone, change bleedout...
	if (["redzone_"] call ULP_fnc_isUnitsInZone) then {
		_endTime = _endTime * getNumber(missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "RedzonePercentage");
	};

	_incapUi setVariable ["endTime", _startTime + _endTime];

	if !(isNil { uiNamespace getVariable "_fnc_bleedout" }) then {
		 [uiNamespace getVariable "_fnc_bleedout"] call ULP_fnc_removeEachFrame;
	};

	_incapUi setVariable ["status", "Waiting to respawn..."];
	uiNamespace setVariable ["_fnc_bleedout", ([[_incapUi, _unit, _startTime, _respawnPer, _progressBar], {
		_this params [
			["_incapUi", displayNull, [displayNull]],
			["_unit", objNull, [objNull]],
			"_startTime", "_respawnPer", // Time vars...
			["_progressBar", controlNull, [controlNull]]
		];

		if !(alive _unit || { isDowned(_unit) }) exitWith {
			uiNamespace setVariable ["_fnc_bleedout", nil];
			[_thisEventHandler] call ULP_fnc_removeEachFrame;
		};

		private _endTime = _incapUi getVariable ["endTime", time + 10];

		// My time has come...
		if (time >= _endTime) exitWith {
			_unit setDamage 1;
			uiNamespace setVariable ["_fnc_bleedout", nil];
			[_thisEventHandler] call ULP_fnc_removeEachFrame;
		};

		_progressBar progressSetPosition (1 - ((time - _startTime) / (_endTime - _startTime)));

		if ((progressPosition _progressBar) <= _respawnPer) then {
			if (!ULP_CanRespawn) then {
				ULP_CanRespawn = true;
				_incapUi setVariable ["status", "Press <t color = '#7300e6'>Shift + F</t> to respawn..."];
			};
		} else {
			// We've likely been administered blood so we're above the bleedout requirement and so can no longer respawn..
			if (ULP_CanRespawn) then {
				ULP_CanRespawn = false;
				_incapUi setVariable ["status", "Waiting to respawn..."];
			};
		};

		(_incapUi displayCtrl 9002) ctrlSetStructuredText parseText format [
			"<t align='left' size='1'>%1</t><t align='right' size='1'>Medics Online: %2</t>",
			_incapUi getVariable ["status", "Waiting to respawn..."], (count (["Medic"] call ULP_fnc_allMembers))
		];

		(_incapUi displayCtrl 9005) ctrlSetStructuredText parseText ([
			"<t align='center' size='1'>Medic Requested</t>"
			"<t align='center' size='1'>Press <t color='#8A2BE2'>Space</t> to request a medic</t>"
		] select (missionNamespace getVariable ["ULP_MedicalRequest", 0] < time));
    }] call ULP_fnc_addEachFrame)];

	["Incapacitated", [_unit, _killer, _incapUi]] call ULP_fnc_invokeEvent;
};