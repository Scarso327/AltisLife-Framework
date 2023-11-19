/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getEventParam";

_this params [
	["_cfg", configNull, [configNull]],
	["_param", "", [""]],
	["_default", 0]
];

if (!(isClass _cfg) || { _param isEqualTo "" }) exitWith { _default };

if !(isNil { missionNamespace getVariable "ULP_IS_DEBUG" }) then {
	_cfg = _cfg >> "Debug";
} else {
	if (missionNamespace getVariable ["ULP_SRV_Setting_BaseBidsActive", false] && { isClass (_cfg >> "BaseWars") }) then {
		_cfg = _cfg >> "BaseWars";
	};
};

(_cfg >> _param)