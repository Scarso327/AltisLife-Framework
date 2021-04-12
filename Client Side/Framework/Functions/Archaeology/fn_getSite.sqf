/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getSite";

_this params [
	["_rarity", "", [""]]
];

if !(isClass (missionConfigFile >> "CfgArchaeology" >> _rarity)) exitWith { false };

[format["Archaeology%1", _rarity], ""] call ULP_fnc_claimMission;