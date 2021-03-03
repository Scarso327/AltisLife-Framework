/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vehicleSiren";

_this params [
	["_vehicle", objNull, [objNull]],
	["_leftLight", [], [[]]],
	["_rightLight", [], [[]]],
	["_on", true, [false]]
];

if (isNull _vehicle || { !hasInterface } || { _lightInfo isEqualTo [] }) exitWith {};

terminate (_vehicle getVariable ["lightLoop", scriptNull]);

{
	deleteVehicle _x;
} forEach (_vehicle getVariable ["lightObjs", []]);

if (_on) then {
	_leftLight params [
		"_leftPos", "_leftColour"
	];

	_rightLight params [
		"_rightPos", "_rightColour"
	];

	private _lightLeft = "#lightpoint" createVehicleLocal [0, 0, 0];
    private _lightRight = "#lightpoint" createVehicleLocal [0, 0, 0];

	{
		_x params ["_light", "_colour"];

		_light setLightColor _colour;
		_light setLightAmbient [0.1,0.1,1];
		_light setLightAttenuation [0.1, 0, 1000, 130];
        _light setLightBrightness 0;
        _light setLightIntensity 1;
		_light setLightFlareSize 0.38;
		_light setLightFlareMaxDistance 300;
		_light setLightUseFlare true;
        _light setLightDayLight true;
    } forEach [[_lightLeft, _leftColour], [_lightRight, _rightColour]];

	_vehicle setVariable ["lightObjs", [_lightLeft, _lightRight]];

	_lightLeft lightAttachObject [_vehicle, _leftPos];
	_lightRight lightAttachObject [_vehicle, _rightPos];

	private _loop = [_vehicle, _lightLeft, _lightRight] spawn {
        _this params [
			"_vehicle", "_lightLeft", "_lightRight"
		];

		private _left = false;

		for "_i" from 0 to 1 step 0 do {
			if (isNull _vehicle || { isNull _lightLeft  && isNull _lightRight } || { !alive _vehicle } || { !(_vehicle getVariable ["lights", false]) }) exitWith {};

			if (_left) then {
				_lightRight setLightBrightness 6;
				sleep 0.05;
            	_lightLeft setLightBrightness 0;
			} else {
				_lightRight setLightBrightness 0;
				sleep 0.05;
            	_lightLeft setLightBrightness 6;
			};

			_left = !_left;
            sleep 0.22;
		};

		{
			deleteVehicle _x;
		} forEach [_lightLeft, _lightRight];
    };

	_vehicle setVariable ["lightLoop", _loop];
};

_vehicle setVariable ["lights", _on];