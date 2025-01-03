/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addNLR";

if (["redzone_"] call ULP_fnc_isUnitsInZone && { !([getNumber (missionConfigFile >> "CfgFactions" >> ([player] call ULP_fnc_getFaction) >> "hasRedzoneNlr")] call ULP_fnc_bool) }) exitWith { false };

_this params [
	["_pos", [], [[]]],
	["_endTime", time + getNumber(missionConfigFile >> "CfgSettings" >> "NLR" >> "nlrTimer"), [0]]
];

private _nlrDistance = getNumber(missionConfigFile >> "CfgSettings" >> "NLR" >> "nlrDistance");
private _nlrName = format["nlr_%1_%2", _pos, _endTime];

private _nlrArea = createMarkerLocal [format["%1_area", _nlrName], _pos];
_nlrArea setMarkerShapeLocal "ELLIPSE";
_nlrArea setMarkerBrushLocal "DiagGrid";
_nlrArea setMarkerColorLocal "ColorCIV";
_nlrArea setMarkerSizeLocal [_nlrDistance, _nlrDistance];
_nlrArea setMarkerAlphaLocal 0.5;

private _nlrMarker = createMarkerLocal [format["%1_marker", _nlrName], _pos];
_nlrMarker setMarkerTypeLocal "mil_warning";
_nlrMarker setMarkerShapeLocal "ICON";
_nlrMarker setMarkerColorLocal "ColorRed";

[_pos, _nlrArea, _nlrMarker, _nlrName, _nlrDistance, _endTime] call ULP_fnc_addNLREachFrame;
true