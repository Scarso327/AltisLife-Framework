/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_maxLoad";

if (canSuspend) exitWith {
    [ULP_fnc_maxLoad, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]]
];

private _containerCfg = missionConfigFile >> "CfgVehicles" >> (typeOf _container);
private _maxLoad = 0;

if (isClass _containerCfg) then {
	_maxLoad = getNumber (_containerCfg >> "virtualSpace");

	if ([_container, "ImprovedStorageUpgrade"] call ULP_fnc_hasVehicleUpgrade) exitWith {
		_maxLoad = round (_maxLoad + (_maxLoad * 0.1));
	};
};

_container getVariable ["ULP_VirtualSpace", _maxLoad];