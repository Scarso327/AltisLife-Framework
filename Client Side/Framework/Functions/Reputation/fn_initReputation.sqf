/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initReputation";

["Initialising Reputation"] call ULP_fnc_logIt;

["ReputationChanged", {
	_this params [
		["_reason", "", [""]],
		["_oldReputation", 0, [0]],
		["_newReputation", 0, [0]]
	];

	if !(_newReputation isEqualTo _oldReputation) then {
		ULP_Reputation = _newReputation;
	};

	[format ["Your reputation has <t color='#B92DE0'>%1</t> because you %2", (["decreased", "increased"] select (ULP_Reputation > _oldReputation)), _reason]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;