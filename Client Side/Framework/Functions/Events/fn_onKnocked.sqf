/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onKnocked";

_this params [
	["_attacker", objNull, [objNull]],
	["_notify", true, [false]],
	["_sound", [], [[]]]
];

if (!(isNull (objectParent player)) || { isDowned(player) } || { [player] call ULP_fnc_onDuty }) exitWith { false };

[] spawn ULP_UI_fnc_closeDialogs;

if ([] call ULP_fnc_isEscorting) then {
	detach ULP_Escort;
	ULP_Escort = nil;
};

disableUserInput true;
player setUnconscious true;
player setVariable ["knocked", true, true];

private _effectBlur = ppEffectCreate ["DynamicBlur", 300];
_effectBlur ppEffectEnable true;
_effectBlur ppEffectAdjust [2.5];
_effectBlur ppEffectCommit 3;

private _effectId = [[_effectBlur, {}]] call ULP_fnc_createEffect;

if !(_sound isEqualTo []) then {
	([player] + _sound) remoteExecCall ["ULP_fnc_say3D"];
};

if (_notify && { !isNull _attacker }) then {
	[format ["<t color='#B92DE0'>%1</t> has knocked you out...", name _attacker]] call ULP_fnc_hint;
};

[
	10, _effectId,
	{
		disableUserInput false;
		player setVariable ["knocked", false, true];

		if (isDowned(player)) exitWith {}; // If we're incapped the stuff after doesn't matter...

		[_this] call ULP_fnc_destroyEffect;

		player setUnconscious false;
		player playMoveNow "amovppnemstpsraswrfldnon";
	}
] call ULP_fnc_waitExecute;

true