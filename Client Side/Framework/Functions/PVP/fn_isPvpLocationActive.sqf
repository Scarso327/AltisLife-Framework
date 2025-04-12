/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isPvpLocationActive";

_this params [
	["_modeName", "", [""]],
	["_locationName", "", [""]]
];

private _currentPvpMode = missionNamespace getVariable ["ULP_SRV_CurrentPvpMode", []];

_currentPvpMode params [
	["_mode", configNull, [configNull]],
	["_location", configNull, [configNull]]
];

(!isNull _mode && { !isNull _location } && { (configName _mode) isEqualTo _modeName } && { (configName _location) isEqualTo _locationName })