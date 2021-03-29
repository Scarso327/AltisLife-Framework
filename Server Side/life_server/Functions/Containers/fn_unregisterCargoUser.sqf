/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_unregisterCargoUser";

_this params [
	["_container", objNull, [objNull]],
	["_user", objNull, [objNull]]
];

if (isNull _container) exitWith {};

private _cargoUser = _container getVariable ["ULP_VirtualCargo_User", objNull];

private _users = _container getVariable ["ULP_VirtualCargo_WaitingUsers", []];
private _index = _users find _user;
if (_index >= 0) then {
	_users deleteAt _index;
	_container setVariable ["ULP_VirtualCargo_WaitingUsers", _users];
} else {
	if ([getNumber (missionConfigFile >> "CfgVehicles" >> (typeOf _container) >> "isHouse")] call ULP_fnc_bool) then {
		[_container] call ULP_SRV_fnc_saveVirtualStorage;
	};

	if (!(isNull _cargoUser) && { _cargoUser isEqualTo _user }) then {
		private _newUser = _users param [0, objNull];
		_container setVariable ["ULP_VirtualCargo_User", _newUser, true];

		_users deleteAt 0;
		_container setVariable ["ULP_VirtualCargo_WaitingUsers", _users];

		if !(isNull _newUser) then {
			["RegisteredAsUser", [_container]] remoteExecCall ["ULP_fnc_invokeEvent", _newUser];
		};
	};
};