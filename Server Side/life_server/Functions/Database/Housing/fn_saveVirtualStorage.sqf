/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_saveHouseStorage";

if (canSuspend) exitWith {
    [ULP_SRV_fnc_saveHouseStorage, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]]
];

private _id = _container getVariable ["building_id", -1];

if (isNull _container || { _id <= 0 }) exitWith { false };

private _curStorage = + (_container getVariable ["ULP_VirtualCargo", []]);
private _lastStorage = _container getVariable ["LastStorage", []];
if (_curStorage isEqualTo _lastStorage) exitWith { false };

[
	format [
		"UPDATE houses SET virtualStorage='%1' WHERE id='%2'",
		[_curStorage] call DB_fnc_mresArray, [_id, ""] call ULP_fnc_numberText
	], 1
] call DB_fnc_asyncCall;

_container setVariable ["LastStorage", _curStorage];
true