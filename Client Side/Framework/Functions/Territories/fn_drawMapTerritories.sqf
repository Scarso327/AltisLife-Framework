/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_drawMapTerritories";

_this params [ "_map" ];

if (isNull _map) exitWith {};

private _territories = missionNamespace getVariable ["ULP_Territories", []];

if (_territories isEqualTo []) exitWith {};

private _mousePos = _map ctrlMapScreenToWorld getMousePosition;

{
	private _cfg = (missionConfigFile >> "CfgTerritories" >> worldName >> (_x getVariable ["config", configNull]));

	if (isClass _cfg) then {
		private _vertices = getArray (_cfg >> "borderVertices");

		private _inTerritory = [_mousePos select 0, _mousePos select 1, 0] inPolygon _vertices;

		if (_inTerritory) then {
			private _colour = ([[0.5, 0, 0, 1], [0, 0, 0, 1]] select ([_x] call ULP_fnc_ownsSite));
			_map drawPolygon [_vertices, _colour];
		};
	};

	nil
} count _territories;