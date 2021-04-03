/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initCartels";

["Initialising Cartels..."] call ULP_fnc_logIt;

ULP_SRV_Cartels = createHashMap;

{
	private _pos = getArray (_x >> "position");
	private _zoneRadius = getNumber (_x >> "zoneRadius");
	private _kosRadius = getNumber (_x >> "kosRadius");

	private _zones = [[_zoneRadius, "ColorYellow", "capture_", true]];
	if (_kosRadius > 0) then { _zones pushback [_kosRadius, "ColorRed", "redzone_"] };

	private _zoneN = format ["cartel_%1", configName _x];
	private _capArea = "";

	{
		_x params [
			"_radius", "_color", "_pre", ["_isCap", false, [true]]
		];

		private _zone = createMarker [format ["%1%2", _pre, _zoneN], _pos];
		_zone setMarkerShape "Ellipse";
		_zone setMarkerColor _color;
		_zone setMarkerSize [_radius, _radius];
		_zone setMarkerBrush "FDIAGONAL";

		if (_isCap) then { _capArea = _zone; };
	} forEach _zones;

	private _marker = createMarker [_zoneN, _pos];
	_marker setMarkerType "mil_warning";
	_marker setMarkerColor "colorOPFOR";
	_marker setMarkerSize [0.5, 0.5];
	_marker setMarkerText getText (_x >> "name");

	private _obj = createSimpleObject ["A3\Weapons_f\empty.p3d", [0, 0, 0], false];
	_obj setVariable ["config", _x];
	_obj setVariable ["marker", _marker];

	ULP_SRV_Cartels set [configName _x, [_obj, _capArea, createHashMap]];
	missionNamespace setVariable [format["ULP_SRV_Cartel_%1", configName _x], _obj, true];
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgCartels" >> "Fixed"));

[] call ULP_SRV_fnc_cartelTick;