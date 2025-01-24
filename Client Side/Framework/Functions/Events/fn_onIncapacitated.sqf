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
		[getPlayerUID _killer, "OffencesAct", "S18",
			format [
				"Suspected Weapon: %1", 
				([currentWeapon _killer] call ULP_fnc_itemCfg) param [5, "Unknown"]
			]
		] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];
	};

	private _killerName = [_killer] call ULP_fnc_getName;

	_deathMessage = format["<t align='center' size='2'>%1 seriously injured you</t>", _killerName];
	
	["InjuredBy", [[_unit] call ULP_fnc_getName, _killerName]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
	[getPlayerUID _unit, "InjuredBy", [getPlayerUID _killer, getPos _unit, getUnitLoadout _unit]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];

	player setVariable ["IncapacitatedByGroup", group _killer, true];
} else {
	["Injured", [[_unit] call ULP_fnc_getName]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
	[getPlayerUID _unit, "Injured", [getPos _unit, getUnitLoadout _unit]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
};

localNamespace setVariable ["ULP_DeathMessage", _deathMessage];

[] call ULP_fnc_onUnrestrained;
player setVariable ["surrender", nil];

if (visibleMap) then {
	openMap false; 
};

[["RscHUD"] call ULP_UI_fnc_getLayer] call ULP_UI_fnc_closeHUD;
[] spawn ULP_UI_fnc_closeDialogs; // Makes sure all dialogs are closed...
[] call ULP_fnc_wipeEffects;
[] call ULP_fnc_stopPlacement;

private _wounds = createHashMap;
private _possibleWounds = ("isClass _x" configClasses (missionConfigFile >> "CfgMedical" >> "Damage"));
private _totalWounds = 0;

{
	scopeName "fn_woundLoop";
	private _partWounds = createHashMap;
	private _amount = (round (random getNumber (missionConfigFile >> "CfgMedical" >> "Damage" >> "amount"))) max 1;

	for "_i" from 0 to _amount do {
		if (_totalWounds >= getNumber (missionConfigFile >> "CfgMedical" >> "Damage" >> "maxWounds")) exitWith { breakOut "fn_woundLoop"; };

		private _wound = selectRandom _possibleWounds;
		_partWounds set [configName _wound, (_partWounds getOrDefault [configName _wound, 0]) + 1];
		_totalWounds = _totalWounds + 1;
	};

	_wounds set [_x, _partWounds];
} forEach ["Head", "Body", "RArm", "LArm", "RLeg", "LLeg"];

player setVariable ["IncapacitatedWounds", _wounds, true];
["Incapacitated", [_unit, _killer], true] call ULP_fnc_invokeEvent;

if (["RscIncapacitated", "PLAIN", 3] call ULP_UI_fnc_createLayer) then {
	ULP_CanRespawn = false;
};