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
		private _verticeCount = count _vertices;

		private _isOwned = !((_x getVariable ["site_owner_id", -1]) isEqualTo -1);
		private _isOwner = [_x] call ULP_fnc_ownsSite;
		private _inTerritory = [_mousePos select 0, _mousePos select 1, 0] inPolygon _vertices;

		private _colour = switch (true) do {
			case (_isOwner): { [0, 0.6, 0, 1] };
			case (_isOwned): { [0.94, 0.51, 0.19, 1] };
			default { [0, 0, 0, 1] };
		};

		private _alpha = if (_inTerritory) then {
			_map drawPolygon [_vertices, _colour];
			0.3
		} else {
			0.4
		};

		_colour set [3, _alpha];

		for "_j" from 0 to (_verticeCount - 1) do {
			private _p1 = _vertices select _j;
			private _p2 = _vertices select (_j + 1) % _verticeCount;

			_map drawTriangle [
				[_p1, _p2, getArray (_cfg >> "centrePos")],
				_colour,
				format["#(rgb,1,1,1)color(1,1,1,%1)", _alpha]
			];
		};
	};

	nil
} count _territories;