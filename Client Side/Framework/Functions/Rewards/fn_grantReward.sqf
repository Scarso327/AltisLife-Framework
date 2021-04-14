/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_grantReward";

_this params [
	["_tier", 0, [0]],
	["_reason", "something", [""]]
];

private _tiers = ("isClass _x" configClasses (missionConfigFile >> "CfgRewards" >> "Tiers"));
_tier = _tiers param [_tier, configNull];
if (isNull _tier) exitWith { false };

private _rewards = ("isClass _x" configClasses (_tier));
private _chance = random 1;

private _reward = (_rewards findIf { isNumber (_x >> "chance") && { _chance >= getNumber (_x >> "chance") } });
if (_reward isEqualTo -1) then {
	_reward = selectRandom (_rewards select { !(isNumber (_x >> "chance")) });
} else {
	_reward = _rewards select _reward;
};

private _type = getText (_reward >> "type");
private _value = switch (_type) do {
	case "CASH";
	case "XP": {
		private _values = getArray (_reward >> "value");
		round ((_values select 0) + (random (_values select 1)))
	};
	case "TEXTURE": { getArray (_reward >> "value") };
};

_type = missionConfigFile >> "CfgRewards" >> "Types" >> _type;
if !(isClass _type) exitWith { false };

_value = ([_reward, _value] call compile getText (_type >> "onRewarded"));
[format [getText (_type >> "message"), _value, _reason]] call ULP_fnc_hint;
true