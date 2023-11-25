/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasTyreDamage";

_this params [
	["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle) exitWith { false };

// If any hitpoint containing the term "wheel" is damaged return true
(("isClass _x" configClasses (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "HitPoints")) 
	findIf { ((toLower (configName _x)) find "wheel") > -1 && { (_vehicle getHitPointDamage (configName _x)) > 0 } }) > -1