/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isCargoUser";

if (canSuspend) exitWith {
    [ULP_fnc_isCargoUser, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]],
	["_user", player, [objNull]]
];

private _cargoUser = _container getVariable ["ULP_VirtualCargo_User", objNull];
(!(isNull _container && { isNull _cargoUser }) && { _user isEqualTo _cargoUser })