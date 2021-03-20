/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_registerCargoUser";

_this params [
	["_container", objNull, [objNull]],
	["_user", objNull, [objNull]]
];

if (isNull _container) exitWith {};

private _cargoUser = _container getVariable ["ULP_VirtualCargo_User", objNull];

if (isNull _cargoUser) then {
	_container setVariable ["ULP_VirtualCargo_User", _user, true];

	if !(isNull _user) then {
		["RegisteredAsUser", [_container]] remoteExecCall ["ULP_fnc_invokeEvent", _user];
	};
} else {
	private _users = _container getVariable ["ULP_VirtualCargo_WaitingUsers", []];
	_users pushBackUnique _user;
	_container setVariable ["ULP_VirtualCargo_WaitingUsers", _users];
};