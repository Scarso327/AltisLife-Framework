/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_preInitMedical";

["Healed", {
	_this params [ "_unit" ];

	[player, 16, [ULP_Survival_Hunger, ULP_Survival_Thirst, (damage player)]] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];

	// Reset Wounded State
	if (!isNull _unit && { [_unit, ["Medic"]] call ULP_fnc_isFaction } && { player getVariable ["Wounded", false] }) then {
		player setVariable ["Wounded", nil, true];
		[player, 17, false] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
	};

	if (_unit isEqualTo player) exitWith {};
	
	[format ["You've been healed by <t color='#B92DE0'>%1</t>!", name _unit]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;