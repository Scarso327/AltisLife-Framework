/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setUpgrade";

_this params [
	["_object", objNull, [objNull]],
	["_upgrade", "", [""]]
];

private _cfg = (([_object] call ULP_fnc_upgradeCfg) >> _upgrade);
if (isNull _object || { !isClass _cfg }) exitWith { false };

private _upgrades = + (_object getVariable ["object_upgrades", createHashMap]);
_upgrades set [_upgrade, true];

_object setVariable ["object_upgrades", _upgrades, true];

if (_object isKindOf "House") then {
	[_object] remoteExecCall ["ULP_SRV_fnc_saveHouseUpgrades", RSERV];
} else {
	[_object] remoteExecCall ["ULP_SRV_fnc_saveVehicleUpgrades", RSERV];
};

if (isText (_cfg >> "onApplied")) then {
	_object call compile getText (_cfg >> "onApplied");
};

true