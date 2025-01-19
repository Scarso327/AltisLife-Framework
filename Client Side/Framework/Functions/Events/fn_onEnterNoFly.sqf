/*
** Author: Lewis Mackinnon
** Description: Automatically alert police to helicopters entering no fly zones
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onEnterNoFly";

_this params [
	["_airspace", "", [""]]
];

if (["signalJammer"] call ULP_fnc_hasItem > 0 || { !([player, ["Police"]] call ULP_fnc_isFaction) }) exitWith {};

private _area = getText (missionConfigFile >> "CfgSettings" >> "NoFlyZones" >> _airspace >> "displayName");

private _cfg = missionConfigFile >> "CfgMessages" >> "PoliceEmergencyDispatch";
private _targets = getText (_cfg >> "targets");

[_cfg, format ["An aircraft has been detected flying near the %1", _area], _targets] call ULP_fnc_sendMessage
["You have been detected flying near a no fly zone. An alert has been sent to the Police"] call ULP_fnc_hint;
