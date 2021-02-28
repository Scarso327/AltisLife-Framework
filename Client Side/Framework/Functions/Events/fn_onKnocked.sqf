/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onKnocked";

_this params [
	["_attacker", objNull, [objNull]]
];

if (isNull _attacker || { _attacker isEqualTo player } || { isDowned(player) }) exitWith {};

[] spawn ULP_UI_fnc_closeDialogs;

disableUserInput true;
player setUnconscious true;
player setVariable ["knocked", true, true];

private _effectBlur = ppEffectCreate ["DynamicBlur", 300];
_effectBlur ppEffectEnable true;
_effectBlur ppEffectAdjust [2.5];
_effectBlur ppEffectCommit 3;

private _effectId = [[_effectBlur, {}]] call ULP_fnc_createEffect;

hint format["%1 has knocked you out...", name _attacker];

[
	10, [_effectId],
	{
		disableUserInput false;
		player setVariable ["knocked", false, true];

		if (isDowned(player)) exitWith {}; // If we're incapped the stuff after doesn't matter...

		[(_this select 0)] call ULP_fnc_destroyEffect;

		player setUnconscious false;
		player playMoveNow "amovppnemstpsraswrfldnon";
	}
] call ULP_fnc_waitExecute;