/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_preInitMedical";

["Healed", {
	_this params [ "_unit" ];

	[player, 16, [ULP_Survival_Hunger, ULP_Survival_Thirst, (damage player)]] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];

	if (_unit isEqualTo player) exitWith {};
	
	[format ["You've been healed by <t color='#B92DE0'>%1</t>!", name _unit]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;