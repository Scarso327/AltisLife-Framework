/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#include "..\..\dikCodes.hpp"
scopeName "fn_adminCamera";

_this params [
	["_mode", "", [""]],
	["_params", [], [[]]]
];

if !([] call ULP_fnc_isSaff) exitWith { false };

switch (_mode) do {
	case "Load": {
		_params params [
			["_display", displayNull, [displayNull]]
		];

		if (isNull _display) exitWith {};

		uiNamespace setVariable ['DisplayAdmin', _display];

		if !([player] call ULP_fnc_onDuty) then {
			[] call ULP_fnc_toggleAdminGear;
		};

		_ui = findDisplay 600;

		private _camera = "camcurator" camCreate (eyePos player);

		_camera cameraEffect ["INTERNAL", "BACK"];
		_camera setPosASL (eyePos player);
		_camera setDir (getDirVisual player);
		_camera camCommand "maxPitch 90.0";
		_camera camCommand "minPitch -90.0";
		_camera camCommand "speedDefault 0.1";
		_camera camCommand "speedMax 2";
		_camera camCommand "ceilingHeight 5000";

		cameraEffectEnableHUD true;
		showCinemaBorder false;

		_camera camCommit 0;

		uiNamespace setVariable ["admin_camera", _camera];

		_display displayAddEventHandler ["KeyDown", { ["keyDown", _this] call ULP_fnc_adminCamera }];
	};

	case "keyDown": {
		_params params [
			"_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
		];

		private _handled = false;
		
		switch (_code) do {
			case SPACE: {
				if (_shift) then {
					if (time < (player getVariable ["tp_cooldown", 0])) exitWith {};
					player setVariable ["tp_cooldown", time + 1];

					private _object = vehicle player;
					private _pos = screenToWorld [0.5, 0.5];

					if (_object isKindOf "Air") then {
						_pos set [2, (getPosATL _object) select 2];
					};

					_object setPosATL _pos;
					_object setVelocity [0, 0, 0];

					_handled = true;
				};
			};
		};

		_handled
	};

	case "Unload": {
		private _camera = uiNamespace getVariable ["admin_camera", objNull];
		if !(isNull _camera) then {
			_camera cameraEffect ["terminate", "back"];
			camDestroy _camera;
		};

		uiNamespace setVariable ['DisplayAdmin', nil];
		player switchCamera "INTERNAL";
	};
};