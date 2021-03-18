/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_robObject";

_this params [
	["_object", objNull, [objNull]],
	["_store", "FuelStation", [""]],
	["_customName", "", [""]]
];

private _cfg = missionConfigFile >> "CfgRobberies" >> _store;
if (isNull _object || { !(isClass _cfg) } || { !([player, getArray (_cfg >> "factions")] call ULP_fnc_isFaction) }) exitWith {};

private _personalTimeout = getNumber (missionConfigFile >> "CfgRobberies" >> "personalTimeout");
private _timeout = getNumber (_cfg >> "timeout");
private _objectTimeout = _object getVariable "timeout";

if (!isNil "ULP_Robbery_Timeout" && { time < ULP_Robbery_Timeout }) exitWith {
	hint format["You have attempted or successfully robbed a store within the last %1 minutes", round (_personalTimeout / 60)];
};
if (!isNil "_timeout" && { time < _objectTimeout }) exitWith { hint format["This store was robbed within the last %1 minutes", round (_timeout / 60)]; };

private _condition = getText (_cfg >> "condition");
private _onFail = getText (_cfg >> "onFail");
if !(call compile _condition) exitWith { call compile _onFail; };

if !(isNull (_object getVariable ["robber", objNull])) exitWith { hint "This store is currently being robbed and so can't be robbed by you..."; };
if ((currentWeapon player) in getArray(missionConfigFile >> "CfgSettings" >> "doesntThreaten")) exitWith { hint "You require a threatening weapon to rob this store..."; };

ULP_Robbery_Timeout = time + _personalTimeout;
_object setVariable ["robber", player, true];

private _marker = createMarker [format["store_robbery_%1", getPlayerUID player], position _object];
_marker setMarkerType "mil_warning";
_marker setMarkerColor "ColorRed";
_marker setMarkerSize [0.8, 0.8];

[format["Robbing %1%2", _customName, getText (_cfg >> "name")], getNumber (_cfg >> "time"), [_object, _marker, _cfg], {
	_this params [ "_object" ];

	private _robber = _object getVariable ["robber", objNull];

	!(isNull _robber) &&
	{ alive _robber } && 
	{ player isEqualTo _robber } && 
	{ (_robber distance _object) <= 8 } && 
	{ !(lineIntersects [eyePos _robber, eyePos _object, _robber, _object]) }
}, {
	_this params [ "_object", "_marker", "_cfg" ];

	private _reward = getArray(_cfg >> "reward");
	private _money = (_reward # 0) + round (random (_reward # 1));
	[_money] call ULP_fnc_addMoney;

	getArray (_cfg >> "leveling") call ULP_fnc_addXP;

	hint format["You have robbed this store for £%1", [_money] call ULP_fnc_numberText];

	_object setVariable["timeout", time + (getNumber (_cfg >> "timeout")), true];
	_object setVariable["robber", nil, true];
	deleteMarker _marker;
}, {
	_this params [ "_object", "_marker" ];
	_object setVariable["robber", nil, true];
	deleteMarker _marker;
}] call ULP_UI_fnc_startProgress;