/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_ownsCartel";

_this params [
	["_cartel", "", [""]],
	["_group", group player, [grpNull]]
];

private _object = missionNamespace getVariable [format["ULP_SRV_Cartel_%1", _cartel], objNull];
if (isNull _object) exitWith { false };

([_group] call ULP_fnc_isGroup && { ((_object getVariable ["owner", []]) param [0, grpNull]) isEqualTo _group })