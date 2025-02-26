/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getSubTitle";

_this params [
	["_object", objNull, [objNull]]
];

if !(isNil { _object getVariable "Territory" }) exitWith {
	format ["Resupply in %1", [(ULP_SRV_TerritoriesNextTime + 60) - serverTime, "MM:SS"] call BIS_fnc_secondsToString]
};

(_object getVariable ["subtitle", ""])