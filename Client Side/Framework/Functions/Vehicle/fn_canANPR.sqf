/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canANPR";

_this params [
	["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle) exitWith { false };

private _texture = missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle) >> "Textures" >> (_vehicle getVariable ["texture", ""]);
(isClass _texture && { isNumber (_texture >> "anpr") } && { [getNumber (_texture >> "anpr")] call ULP_fnc_bool })