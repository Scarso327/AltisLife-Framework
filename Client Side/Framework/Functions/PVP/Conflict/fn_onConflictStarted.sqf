/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onConflictStarted";

_this params [
	["_locationCfg", configNull, [configNull]]
];

if (isNull _locationCfg || { !hasInterface } || { !([["NotifyConflict", "Notifications"] call ULP_fnc_getOption] call ULP_fnc_bool) }) exitWith {};

private _locationName = getText (_locationCfg >> "displayName");
private _maxScore = getNumber (missionConfigFile >> "CfgPvpModes" >> "Modes" >> "Conflict" >> "maxScore");

[format ["<t color='#ff0000' size='1.5px'>Conflict<br/></t><t color='#ffffff' size='1px'>A conflict has started at %1.<br/><br/>Capture and hold one of the nodes to increase your score. Once a node has been depleted a new one will spawn.<br/><br/>The first group to score <t color='#B92DE0'>%2</t> points wins.", _locationName, _maxScore]] call ULP_fnc_hint;