/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogPvpVote_OnMapDraw";

_this params [ "_map" ];

if (isNull _map) exitWith {};

private _display = ctrlParent _map;
private _selectedCfg = _display getVariable ["selectedCfg", configNull];

if (isNull _selectedCfg) exitWith {};

{
	getArray (_x >> "position") params [ "_pos", "_dir" ];
	getArray (_x >> "size") params [ "_sizeX", "_sizeY" ];
	
	private _markerType = getText(_x >> "type");
	private _markerShape = getText(_x >> "shape");

	private _markerColour = getArray (configFile >> "CfgMarkerColors" >> (getText (_x >> "colour")) >> "color");

	if ((_markerColour select 0) isEqualType "") then {
		_markerColour = _markerColour apply { call compile _x };
	};

	if (isNumber (_x >> "alpha")) then {
		_markerColour set [3, getNumber (_x >> "alpha")];
	};

	switch (_markerShape) do {
		case "RECTANGLE": {
			private _brush = getText(configFile >> "CfgMarkerBrushes" >> (getText (_x >> "brush")) >> "texture");
			_map drawRectangle [_pos, _sizeX, _sizeY, _dir, _markerColour, _brush];
		}; 
		case "ELLIPSE": {
			private _brush = getText(configFile >> "CfgMarkerBrushes" >> (getText (_x >> "brush")) >> "texture");
			_map drawEllipse [_pos, _sizeX, _sizeY, _dir, _markerColour, _brush];
		};
		default {
			private _icon = getText(configFile >> "CfgMarkers" >> _markerType >> "icon");
			private _sizeMultiplier = getNumber (configFile >> "CfgMarkers" >> _markerType >> "size");
			_map drawIcon[_icon, _markerColour, _pos, _sizeX * _sizeMultiplier, _sizeY * _sizeMultiplier, _dir, "", false];
		};
	};
} forEach ("isClass _x" configClasses (_selectedCfg >> "Markers"));

{
	private _pos = getArray (_x >> "position");
	
	private _markerType = "mil_end";
	private _markerColour = getArray (configFile >> "CfgMarkerColors" >> "Color3_FD_F" >> "color");

	private _icon = getText(configFile >> "CfgMarkers" >> _markerType >> "icon");
	private _sizeMultiplier = getNumber (configFile >> "CfgMarkers" >> _markerType >> "size");

	_map drawIcon [_icon, _markerColour, _pos, 0.5 * _sizeMultiplier, 0.5 * _sizeMultiplier, 0, getText (_x >> "displayName"), false];
} forEach ("isClass _x" configClasses (_selectedCfg >> "Nodes"));