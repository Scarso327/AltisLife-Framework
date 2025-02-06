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

_trader addAction ["<t color='#B92DE0'>[Civilian]</t> Factory", { _this call (_this select 3) }, compile getText (_cfg >> "Events" >> "onOpen"), 1, true, true, "", "isNull (objectParent _this) && { [_this, [""Civilian""]] call ULP_fnc_isFaction }", 3];

_trader setVariable ["ULP_ScriptedInventory", true];
_trader setVariable ["ULP_VirtualSpace", 10000];

private _marker = format ["factory_%1", _factory];

if (isServer) then {
	_marker = createMarker [_marker, _trader];
	_marker setMarkerType getText (missionConfigFile >> "CfgFactories" >> "markerType");
	_marker setMarkerColor getText (missionConfigFile >> "CfgFactories" >> "colourDefault");
	_marker setMarkerText getText (_cfg >> "displayName");
	_marker setMarkerSize [0.8, 0.8];

	_trader setVariable ["factory_onTick", compileFinal getText (_cfg >> "Events" >> "onTick")];
	_trader setVariable ["factory_preTickCondition", compileFinal getText (_cfg >> "Events" >> "preTickCondition")];
};

_trader setVariable ["marker", _marker];