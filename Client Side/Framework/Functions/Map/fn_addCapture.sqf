/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addCapture";

_this params [
	["_trader", objNull, [objNull]],
	["_capture", "", [""]]
];

private _cfg = missionConfigFile >> "CfgCapture" >> worldName >> _capture;
if (isNull _trader || { !isClass _cfg }) exitWith {};

_trader setVariable ["site", _capture];

_trader addAction ["<t color='#B92DE0'>[Civilian]</t> Capture", { _this call ULP_fnc_capture }, [], 1, true, true, "", "isNull (objectParent _this) && { [_this, [""Civilian""]] call ULP_fnc_isFaction }", 3];
_trader addAction ["<t color='#3266A8'>[Police]</t> Neutralise", { _this call ULP_fnc_neutralise }, [], 2, true, true, "", "isNull (objectParent _this) && { [_this, [""Police""]] call ULP_fnc_isFaction }", 3];

if !(isClass (_cfg >> "Marker")) exitWith {};

private _marker = format ["site_%1", _capture];

if (isServer) then {
	_marker = createMarker [_marker, _trader];
	_marker setMarkerType getText (_cfg >> "Marker" >> "markerType");
	_marker setMarkerColor getText (_cfg >> "Marker" >> "markerColour");
	_marker setMarkerText getText (_cfg >> "Marker" >> "defaultName");
};

_trader setVariable ["marker", _marker];