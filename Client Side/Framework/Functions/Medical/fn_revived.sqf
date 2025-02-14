/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_revived";

if (canSuspend) exitWith {
    [ULP_fnc_revived, _this] call ULP_fnc_directCall;
};

if !(_this params [
	["_medic", objNull, [objNull]]
]) exitWith {};

if ([_medic] call ULP_fnc_onDuty) then {
	["You were revived by an admin..."] call ULP_fnc_hint;
} else {
	if (_medic isEqualTo player) exitWith {};

	private _isWounded = (!([_medic, ["Medic"]] call ULP_fnc_isFaction) && { !(([["Medic"]] call ULP_fnc_onlineFaction) isEqualTo 0) });

	[(if (_isWounded) then {
		format ["You have been revived by <t color='#B92DE0'>%1</t>. As they aren't a medic, you're now in a wounded state and must seek out medical assistance", [_medic, true] call ULP_fnc_getName]
	} else {
		format ["You have been revived by <t color='#B92DE0'>%1</t>", [_medic, true] call ULP_fnc_getName]
	})] call ULP_fnc_hint;

	private _unitRep = player getVariable ["reputation", 0];

	[_medic, missionConfigFile >> "CfgReputation" >> "Types" >> (switch (true) do {
		case (_unitRep >= 500): { "ReviveHigh" };
		case (_unitRep > -500): { "ReviveNorm" };
		default { "ReviveLow" };
	})] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];
	
	if (_isWounded) then {
		player setVariable ["Wounded", true, true];
		[player, 17, true] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
	};
};

if !(_medic isEqualTo player) then {
	["Revived", [name player, [[_medic, true] call ULP_fnc_getName, "an admin"] select ([_medic] call ULP_fnc_onDuty)]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
};

// Make sure we're no longer attached!
private _stretcher = attachedTo player;
if (!isNull _stretcher && { _stretcher isKindOf "Land_Stretcher_01_F" }) then {
	[player] call ULP_fnc_toggleOnStretcher;
};

player setVariable ["IncapacitatedWounds", nil, true];
player setVariable ["IncapacitatedBleedOutTime", nil, true];
player setVariable ["IncapacitatedByGroup", nil, true];
player setVariable ["AssignedMedic", nil, true];

player setUnconscious false;
unsetKiller(player);
unsetDowned(player);

player playMoveNow "amovppnemstpsraswrfldnon";

["RscIncapacitated"] call ULP_UI_fnc_destroyLayer;
[] call ULP_fnc_wipeEffects;

if (["EnableHUD", "HUD"] call ULP_fnc_getOption isEqualTo 1) then {
	[] call ULP_UI_fnc_openHUD;
};

ULP_Respawned = false;
ULP_CanRespawn = nil;

localNamespace setVariable ["ULP_LastRevived", time];

[] call ULP_fnc_syncPlayerInfo;