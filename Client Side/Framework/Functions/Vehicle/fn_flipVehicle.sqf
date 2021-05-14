/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_flipVehicle";

_this params [
	["_vehicle", objNull, [objNull]],
	["_action", 0, [0]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { closeDialog 0; };

if (_action isEqualTo 0) then {
	_cfg params [ "", "_missionCfg", "", "_name" ];

	if !(isClass _missionCfg) exitWith {};

	private _time = 5;
	if (isNumber (_missionCfg >> "flipTime")) then {
		_time = _time + getNumber (_missionCfg >> "flipTime");
	};

	if ([format["Flipping %1", _name], _time, [_vehicle], { !(isNull _this select 0) }, {
		_this params [ "_vehicle" ];

		if (isNull _vehicle || { (player distance _vehicle) > 5 }) exitWith {};

		[_vehicle, 1] remoteExecCall ["ULP_fnc_flipVehicle", _vehicle];
		
		["You have flipped this vehicle..."] call ULP_fnc_hint;
	}, {}] call ULP_UI_fnc_startProgress) then {
		closeDialog 0;
	};
} else {
	private _boundingBox = 0 boundingBoxReal _vehicle;
	private _height = (abs selectMin (_boundingBox param [0, []])) max (selectMax (_boundingBox param [1, []]));

	private _pos = getPosASL _vehicle;

	private _intersection = lineIntersectsSurfaces [_pos vectorAdd [0, 0, 0.2], _pos vectorAdd [0, 0, -_height], _vehicle] param [0, []];

	if (_intersection isEqualTo []) then {
		_vehicle setVectorUp [0, 0, 1];
		_vehicle setPosWorld ((getPosASL _vehicle) vectorAdd [0, 0, _height]);
	} else {
		_vehicle setVectorUp (_intersection param [1, []]);
		_vehicle setPosASL (_intersection param [0, []]);
	};
};