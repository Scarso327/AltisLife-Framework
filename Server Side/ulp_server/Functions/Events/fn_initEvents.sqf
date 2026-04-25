/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\ulp_server\script_macros.hpp"
scopeName "fn_initEvents";

["Adding Mission Events..."] call ULP_fnc_logIt;

addMissionEventHandler ["EntityRespawned", { _this call ULP_SRV_fnc_onPlayerRespawn; }];

addMissionEventHandler ["HandleDisconnect", { _this call ULP_SRV_fnc_onPlayerDisconnect; false }];
addMissionEventHandler ["OnUserDisconnected", {
	_this params [
		["_networkId", "", [""]]
	];

	// https://community.bistudio.com/wiki/getUserInfo - alt syntax
	private _unit = _networkId getUserInfo 10;

	if (isNull _unit) exitWith {};

	[_unit] call ULP_SRV_fnc_onPlayerDisconnect;
}];

addMissionEventHandler ["PlayerDisconnected", {
    _this params ["", "", "", "", "_owner"];

	private _isHc = _owner == (missionNamespace getVariable ["ULP_HC_ID", -1]);

	if (_isHc) then {
		[_owner] call ULP_SRV_fnc_unregisterHc;
	};
}];

addMissionEventHandler ["EntityKilled", {
	_this params [
		"_unit", "_killer"
	];

	if (isNull _unit || { !isServer }) exitWith {};

	if (isPlayer _unit && { _unit isKindOf "Man" } && { isNull _killer || { isPlayer _killer } }) then {
		_this call ULP_SRV_fnc_onPlayerKilled;
	};
}];