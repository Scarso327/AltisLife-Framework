/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_saveHouseUpKeep";

if (canSuspend) exitWith {
    [ULP_SRV_fnc_saveHouseUpKeep, _this] call ULP_fnc_directCall;
};

_this params [
	["_house", objNull, [objNull]],
	["_newUpKeepDaysLeft", 0, [0]]
];

if (isNull _house || { !([_house] call ULP_fnc_isHouse) } || { _newUpKeepDaysLeft <= 0 }) exitWith {};

private _buildingId = _house getVariable ["building_id", -1];

[format["UPDATE `houses` SET `upkeepDaysLeft`='%2' WHERE `id`='%1'", [_buildingId, ""] call ULP_fnc_numberText, [_newUpKeepDaysLeft, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;

_house setVariable ["building_days_left", _newUpKeepDaysLeft, true];