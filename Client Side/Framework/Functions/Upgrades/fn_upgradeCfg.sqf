/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_upgradeCfg";

_this params [
	["_object", objNull, [objNull]]
];

(missionConfigFile >> (["CfgVehicleUpgrades", "CfgHousingUpgrades"] select (_object isKindOf "House")));