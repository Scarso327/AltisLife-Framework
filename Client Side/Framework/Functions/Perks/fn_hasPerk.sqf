/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasPerk";

_this params [
	["_perk", "", [""]]
];

(isClass (missionConfigFile >> "CfgPerks" >> _perk) && { _perk in ULP_Perks })