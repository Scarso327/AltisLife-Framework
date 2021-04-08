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
			[true] call ULP_fnc_toggleAdminGear;
		};

		_ui = findDisplay 600;

		private _camera = "camcurator" camCreate (eyePos player);

		cameraEffectEnableHUD true;
		showCinemaBorder false;

		_camera cameraEffect ["INTERNAL", "BACK"];
		_camera setPosASL (eyePos player);
		_camera setDir (getDirVisual player);
		_camera camCommand "maxPitch 90.0";
		_camera camCommand "minPitch -90.0";
		_camera camCommand "speedDefault 0.1";
		_camera camCommand "speedMax 2";
		_camera camCommand "ceilingHeight 5000";
		_camera camCommand "surfaceSpeed off";
		_camera camCommit 0;

		uiNamespace setVariable ["admin_camera", _camera];
		["SetCameraInput", [true]] call ULP_fnc_adminCamera;

		private _ctrlMap = _display displayCtrl 601;
		_ctrlMap ctrlShow false;
		_ctrlMap ctrlAddEventHandler ["Draw", { ["mapDraw", _this] call ULP_fnc_adminCamera }];
		_ctrlMap ctrlAddEventHandler ["MouseButtonClick", { ["mapClick", _this] call ULP_fnc_adminCamera }];

		_display displayAddEventHandler ["KeyDown", { ["keyDown", _this] call ULP_fnc_adminCamera }];

		[false] call ULP_fnc_playerTags;
	};

	case "mapDraw": {
		_params params [
			["_ctrlMap", controlNull, [controlNull]]
		];

		{
			_ctrlMap drawIcon [
				"\A3\ui_f\data\map\vehicleicons\iconman_ca.paa",
				getArray (missionConfigFile >> "CfgFactions" >> ([_x] call ULP_fnc_getFaction) >> "colour"),
				getPosVisual _x, 26, 26, getDirVisual _x, _x call ULP_fnc_getName, 1, 0.06, 'TahomaB', 'right'
			];
		} forEach (allPlayers - allMissionObjects "HeadlessClient_F");

		private _camera = uiNamespace getVariable ["admin_camera", objNull];
		if !(isNull _camera) then {
			_ctrlMap drawIcon [
				"a3\3den\Data\Cfg3DEN\Camera\cameratexture_ca.paa", [0, 0, 0, 1], getPos _camera, 26, 26, getDir _camera, '', 0, 0.03, 'TahomaB', 'center'
			];
		};
	};

	case "mapClick": {
		_params params [
			"_ctrl", "_button", "_xPos", "_yPos", "", "_ctrlKey"
		];

		private _pos = _ctrl ctrlMapScreenToWorld [_xPos, _yPos];

		if (_button isEqualTo 0) then {
			if (_ctrlKey) then {
				if (time < (player getVariable ["tp_cooldown", 0])) exitWith {};
				player setVariable ["tp_cooldown", time + 1];

				private _object = vehicle player;
				
				_pos set [2, ([0, (getPosATL _object) select 2] select (_object isKindOf "Air"))];

				_object setPosATL _pos;
				_object setVelocity [0, 0, 0];
			} else {
				private _camera = uiNamespace getVariable ["admin_camera", objNull];

				if !(isNull _camera) then {
					_pos set [2, (getPos _camera) select 2];
					_camera setPos _pos;
				};
			};
		};
	};

	case "keyDown": {
		_params params [
			"_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
		];

		private _handled = false;
		
		switch (_code) do {
			case SPACE: {
				if (_ctrlKey) then {
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

			case M: {
				private _ctrlMap = _ctrl displayCtrl 601;
				private _isShown = !(ctrlShown _ctrlMap);

				["SetCameraInput", [!_isShown]] call ULP_fnc_adminCamera;
				_ctrlMap ctrlShow _isShown;
			};
		};

		_handled
	};

	case "SetCameraInput": {
		_params params [
			["_manual", false, [true]]
		];

		private _camera = uiNamespace getVariable ["admin_camera", objNull];
		if !(isNull _camera) then {
			_camera camCommand format["manual %1", (["off", "on"] select (_manual))];
		};

		uiNamespace setVariable ['admin_camera_manual', _manual];
	};

	case "isCameraManual": {
		uiNamespace getVariable ['admin_camera_manual', true];
	};

	case "Unload": {
		private _camera = uiNamespace getVariable ["admin_camera", objNull];
		if !(isNull _camera) then {
			_camera cameraEffect ["terminate", "back"];
			camDestroy _camera;
		};

		uiNamespace setVariable ['DisplayAdmin', nil];
		player switchCamera "INTERNAL";

		[[["EnablePlayerTags", "HUD"] call ULP_fnc_getOption] call ULP_fnc_bool] call ULP_fnc_playerTags;
	};
};