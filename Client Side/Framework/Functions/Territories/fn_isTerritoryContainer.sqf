/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isTerritoryContainer";

if (canSuspend) exitWith {
    [ULP_fnc_isTerritoryContainer, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]]
];

(!isNull _container && { !isNil { _container getVariable "Territory" } })