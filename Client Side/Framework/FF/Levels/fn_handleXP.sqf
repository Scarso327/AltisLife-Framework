/*
	@File: fn_handleXP.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Increases and levels the player up...

	@Parameters:
		0 - TYPE: INTGER - DES: The XP to be added...
*/
#include "..\..\script_macros.hpp"
#include "..\GUI\HUD\macros.hpp"
params [
	["_xp", 0, [0]],
	["_reason", "Something", [""]]
];

if (_xp < 1) exitWith {}; // Can't give lower than 1 Xp!
if (_reason isEqualTo "") then { _reason = "Something" };

FF_XP = FF_XP + _xp;

[format["You've gained %1 XP for <t color = '#7300e6'>%2</t>", _xp, _reason]] spawn FF_fnc_notify;

#define MAXLVL (getNumber(missionConfigFile >> "CfgLevels" >> "maxLevel"))

private _level = switch true do {
    case (FF_Level isEqualTo MAXLVL): { MAXLVL };
    default { (FF_Level + 1) };
};

private _neededXP = getNumber(missionConfigFile >> "CfgLevels" >> format["level_%1", _level] >> "expRequired");

disableSerialization;

// Do we level up???
if (FF_XP >= _neededXP) then {
	if !(FF_Level isEqualTo MAXLVL) then {
		FF_Level = FF_Level + 1;

		[format["You are now <t color = '#7300e6'>level %1!</t>",FF_Level]] spawn FF_fnc_notify;
	} else {
		[
			format["You've been given <t color = '#7300e6'>£%1</t> for leveling up!", 
				[getNumber(missionConfigFile >> "CfgLevels" >> "maxLevelLoopReward")] call life_fnc_numberText
			]
		] spawn FF_fnc_notify;
	};

	private _carryOver = (FF_XP - _neededXP);

	if (_carryOver > 0) exitWith {
		FF_XP = _carryOver;
	};
	FF_XP = 0;
};

_level = switch true do {
    case (FF_Level isEqualTo MAXLVL): { MAXLVL };
    default { (FF_Level + 1) };
};
private _neededXP = getNumber(missionConfigFile >> "CfgLevels" >> format["level_%1", _level] >> "expRequired");

if (FF_XP >= _neededXP) then { FF_XP = _neededXP; };

LIFEctrl(IDC_LIFE_XP_TEXT) ctrlSetStructuredText parseText format["<t align='center'>%1 / %2</t>", [FF_XP] call life_fnc_numberText, [_neededXP] call life_fnc_numberText];
LIFEctrl(IDC_LIFE_BAR_XP) progressSetPosition (FF_XP / _neededXP);

LIFEctrl(IDC_LIFE_CURLVL_TEXT) ctrlSetStructuredText parseText format["<t align='center'>%1</t>", FF_Level];
LIFEctrl(IDC_LIFE_NXTLVL_TEXT) ctrlSetStructuredText parseText format["<t align='center'>%1</t>", _level];

[] call SOCK_fnc_updateRequest;