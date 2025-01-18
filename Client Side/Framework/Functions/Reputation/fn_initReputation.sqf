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

["Incapacitated", {
	_this params [
		"_unit", "_killer"
	];

	if (!isNull _killer 
		&& { isPlayer _killer } 
		&& { !(_killer isEqualTo _unit) } 
		&& { (_killer getVariable ["robbed_by_me", -300]) < (time - 300) } 
		// Either No Weapon or Not Police = Hurt Rep
		&& { !((currentWeapon _unit) isEqualTo "") || { !([_killer, ["Police"]] call ULP_fnc_isFaction) } }) then {
		[_killer, missionConfigFile >> "CfgReputation" >> "Types" >> (switch (true) do {
			case (ULP_Reputation >= 500): { "IncapHigh" };
			case (ULP_Reputation > -500): { "IncapNorm" };
			default { "IncapLow" };
		})] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];
	};
}] call ULP_fnc_addEventHandler;