/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addFactory";

_this params [
	["_trader", objNull, [objNull]],
	["_factory", "", [""]]
];

private _cfg = missionConfigFile >> "CfgFactories" >> worldName >> _factory;
if (isNull _trader || { !isClass _cfg }) exitWith {};

_trader setVariable ["factory", _factory];

private _marker = format ["factory_%1", _factory];

if (isServer) then {
	_trader setVariable ["ULP_ScriptedInventory", true, true];
	_trader setVariable ["ULP_VirtualSpace", 10000, true];

	_marker = createMarker [_marker, _trader];
	_marker setMarkerType getText (missionConfigFile >> "CfgFactories" >> "markerType");
	_marker setMarkerColor getText (missionConfigFile >> "CfgFactories" >> "colourDefault");
	_marker setMarkerText getText (_cfg >> "displayName");
};

_trader setVariable ["marker", _marker];