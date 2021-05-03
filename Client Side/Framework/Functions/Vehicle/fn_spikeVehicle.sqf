/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_spikeVehicle";

_this params [
	["_vehicle", objNull, [objNull]],
	["_owner", [], [[]]]
];

if (isNull _vehicle) exitWith {};

_owner params [ "_name", "_steamid" ];

{
	if (((toLower (configName _x)) find "wheel") > -1) then {
		_vehicle setHitPointDamage [configName _x, 1];
	};
} forEach ("isClass _x" configClasses (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "HitPoints"));