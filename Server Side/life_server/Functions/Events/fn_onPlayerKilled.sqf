/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_onPlayerKilled";

_this params [
	"_unit", "_killer", "_instigator"
];

// Notify the server...
if (!isNull _killer && { isPlayer _killer } && { !(_killer isEqualTo _unit) }) then {	
	["Executed", [_unit getVariable ["realname", name _unit], _killer getVariable ["realname", name _killer]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
	[getPlayerUID _unit, "Executed", [getPlayerUID _killer, getPos _unit, getUnitLoadout _unit]] call ULP_SRV_fnc_logPlayerEvent;

	if (["capture_cartel_", [_unit, _killer]] call ULP_fnc_isUnitsInZone) then {
		[_unit, _killer] call ULP_SRV_fnc_onCartelKill;	
	};
} else {
	["Bleedout", [_unit getVariable ["realname", name _unit]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
	[getPlayerUID _unit, "Bleedout", [getPos _unit, getUnitLoadout _unit]] call ULP_SRV_fnc_logPlayerEvent;
};