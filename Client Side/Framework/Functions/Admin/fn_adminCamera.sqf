/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#include "..\..\dikCodes.hpp"
scopeName "fn_adminCamera";

if (canSuspend) exitWith {
    [ULP_fnc_adminCamera, _this] call ULP_fnc_directCall;
};

_this params [
	["_mode", "", [""]],
	["_params", [], [[], "", 0]]
];

if !([] call ULP_fnc_isStaff || { ["Camera"] call ULP_fnc_checkPower }) exitWith { false };

switch (_mode) do {
	case "Load": {
		_params params [
			["_display", displayNull, [displayNull]]
		];

		if (isNull _display) exitWith {};

		uiNamespace setVariable ['DisplayAdmin', _display];

		// Put On-Duty
		if !([player] call ULP_fnc_onDuty) then { [true] call ULP_fnc_toggleAdminGear; };

		// Make Invisible
		if !(isObjectHidden player) then { [player, true] remoteExecCall ["ULP_SRV_fnc_hidePlayer", RSERV]; };

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
		_camera camCommand "surfaceSpeed off";
		_camera camCommit 0;

		cameraEffectEnableHUD true;
		showCinemaBorder false;
		
		uiNamespace setVariable ["admin_camera", _camera];
		_camera setVariable ["display", _display];
		["SetCameraInput", [true]] call ULP_fnc_adminCamera;

		uiNamespace setVariable ["admin_esp", (addMissionEventHandler ["Draw3D", { ["draw3d"] call ULP_fnc_adminCamera }])];

		private _ctrlMap = _display displayCtrl 601;
		_ctrlMap ctrlShow false;
		_ctrlMap ctrlAddEventHandler ["Draw", { ["mapDraw", _this] call ULP_fnc_adminCamera }];
		_ctrlMap ctrlAddEventHandler ["MouseButtonClick", { ["mapClick", _this] call ULP_fnc_adminCamera }];

		uiNamespace setVariable ["admin_camera_map", _ctrlMap];

		private _ctrlMouse = _display displayCtrl 603;

		_display displayAddEventHandler ["KeyDown", { ["keyDown", _this] call ULP_fnc_adminCamera }];
		_ctrlMouse ctrlAddEventHandler ["MouseButtonDown", { ["mouseDown", _this] call ULP_fnc_adminCamera }];

		uiNamespace setVariable ["admin_camera_mouse", _ctrlMouse];
		ctrlSetFocus _ctrlMouse;

		private _list = (_display displayCtrl 602) controlsGroupCtrl 101;
		_list ctrlAddEventHandler ["MouseEnter", { ["ToggleList", [_this select 0, true]] call ULP_fnc_adminCamera; }];
		_list ctrlAddEventHandler ["MouseExit", { ["ToggleList", [_this select 0, false]] call ULP_fnc_adminCamera; }];
		["updateList", [_list]] call ULP_fnc_adminCamera;

		_list ctrlAddEventHandler ["TreeSelChanged", {
			_this params [ "_ctrl", "_select" ];

			private _object = (_ctrl tvData _select) call BIS_fnc_objectFromNetId;
			if (isNull _object) exitWith {};

			["SetCameraTarget", [_object]] call ULP_fnc_adminCamera;
		}];

		private _ctrlToolbox = _display displayCtrl 604;
		_ctrlToolbox ctrlAddEventHandler ["ToolboxSelChanged", { ["ViewToolboxChanged", _this] call ULP_fnc_adminCamera; }];

		[false] call ULP_fnc_playerTags;

		uiNamespace setVariable ["admin_each_frame", ([_display, { ["eachFrame", [_this, _thisEventHandler]] call ULP_fnc_adminCamera; }] call ULP_fnc_addEachFrame)];
	};

	case "eachFrame": {
		_params params [
			["_display", displayNull, [displayNull]],
			["_id", -1, [0]]
		];

		if (isNull _display) exitWith {
			[_id] call ULP_fnc_removeEachFrame;
		};

		if !((count allPlayers) isEqualTo (count (uiNamespace getVariable ["list_players", []]))) then {
			["updateList", [(_display displayCtrl 602) controlsGroupCtrl 101]] call ULP_fnc_adminCamera;
		};
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

	case "draw3d": {
		private _camera = uiNamespace getVariable ["admin_camera", objNull];
		if (isNull _camera) exitWith {};

		{
			private _dist = (_x distance _camera);

			if (_dist <= 2000) then {
				private _colour = [0.9, 0.9, 0.9, 1];
				private _iconColour = getArray (missionConfigFile >> "CfgFactions" >> ([_x] call ULP_fnc_getFaction) >> "colour");

				private _pos = [_x modelToWorldVisual (_x selectionPosition "spine3"), (vehicle _x) modelToWorldVisual [0,0,0]] select !(isNull objectParent _x);
				
				{ _x set [3, linearConversion [2000 / 1.2, 2000, _dist, 1, 0, true]]; } forEach [_color, _nameColor];

				drawIcon3D [ "\a3\ui_f\data\IGUI\Cfg\Cursors\select_ca.paa", _iconColour, _pos, 0.9, 0.9, 0 ];
				drawIcon3D [ "", _colour, _pos, 1, 1, 0, [_x] call ULP_fnc_getName, 0, 0.027, "RobotoCondensedBold" ];
			};
		} forEach playableUnits;
	};

	case "mapClick": {
		_params params [
			"_ctrl", "_button", "_xPos", "_yPos", "", "_ctrlKey"
		];

		if !(["Teleport"] call ULP_fnc_checkPower) exitWith {};

		private _pos = _ctrl ctrlMapScreenToWorld [_xPos, _yPos];

		switch (_button) do {
			case 0: {
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
	};

	case "mouseDown": {
		_params params [
			"_ctrl", "_button", "_xPos", "_yPos", "", "_ctrlKey"
		];

		private _ctrlMap = (ctrlParent _ctrl) displayCtrl 601;
		if (ctrlShown _ctrlMap) exitWith {}; // Map has it's own...
		
		switch (_button) do {
			case 1: {
				if ((uiNamespace getVariable ["admin_camera_mode", "free"]) isEqualTo "free") then {
					private _focus = ["GetCameraTarget"] call ULP_fnc_adminCamera;

					if !(isNull _focus) then {
						["RestCameraTarget"] call ULP_fnc_adminCamera;
					};
				};
			};
		};
	};

	case "updateList": {
		_params params [
			["_ctrl", controlNull, [controlNull]]
		];

		tvClear _ctrl;

		private _players = [];

		{
			private _cfg = _x;
			private _parent = _ctrl tvAdd [[], getText(_cfg >> "displayName")];
			_ctrl tvSetPicture [[_parent], "\a3\ui_f_curator\data\Displays\RscDisplayCurator\side_west_ca.paa"];
			_ctrl tvSetPictureColor [[_parent], getArray(_cfg >> "colour")];

			{
				_players pushBackUnique _x;

				private _member = _ctrl tvAdd [[_parent], [_x] call ULP_fnc_getName];
				_ctrl tvSetData [[_parent, _member], _x call BIS_fnc_netId];
				_ctrl tvSetPicture [[_parent, _member], [getText(configFile >> "CfgVehicles" >> typeOf _x >> "icon")] call BIS_fnc_textureVehicleIcon];
				_ctrl tvSetPictureColor [[_parent, _member], getArray(_cfg >> "colour")];
			} forEach ([configName _x] call ULP_fnc_allMembers);
		} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgFactions"));

		uiNamespace setVariable ["list_players", _players];
	};

	case "keyDown": {
		_params params [
			"_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
		];

		private _handled = false;
		
		switch (_code) do {
			case SPACE: {
				if !(["Teleport"] call ULP_fnc_checkPower) exitWith {};
				
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

				ctrlSetFocus ([(uiNamespace getVariable ["admin_camera_mouse", controlNull]), _ctrlMap] select (_isShown));

				_handled = true;
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

	case "ChangeCameraView": {
		_params params [
			["_mode", "", [""]]
		];

		private _camera = uiNamespace getVariable ["admin_camera", objNull];
		if (isNull _camera) exitWith {};

		private _focus = ["GetCameraTarget"] call ULP_fnc_adminCamera;

		switch (_mode) do {
			case "fps": {
				_camera cameraEffect ["Terminate", "BACK"];
				_focus switchCamera "INTERNAL";

				["RestCameraTarget"] call ULP_fnc_adminCamera;
				["SetCameraInput", [false]] call ULP_fnc_adminCamera;
			};
			case "free": {
				_camera cameraEffect ["Internal", "BACK"];
				player switchCamera "INTERNAL";

				if !(isNull _focus) then {
					["SetCameraTarget", [_focus]] call ULP_fnc_adminCamera;
				};
					
				private _ctrlMap = (_camera getVariable ["display", displayNull]) displayCtrl 601;
				if !(ctrlShown _ctrlMap) then {
					["SetCameraInput", [true]] call ULP_fnc_adminCamera;
				};
			};
		};

		cameraEffectEnableHUD true;
		uiNamespace setVariable ["admin_camera_mode", _mode];
	};

	case "RestCameraTarget": {
		private _camera = uiNamespace getVariable ["admin_camera", objNull];
		if (isNull _camera) exitWith {};

		_camera camPrepareTarget objNull;
		_camera camCommitPrepared 0;

		uiNamespace setVariable ["admin_camera_target", objNull];
	};

	case "SetCameraTarget": {
		_params params [
			["_target", objNull, [objNull]]
		];

		private _camera = uiNamespace getVariable ["admin_camera", objNull];
		if (isNull _camera) exitWith {};

		_camera camPrepareTarget (vehicle _target);
		_camera camCommitPrepared 0.5;

		uiNamespace setVariable ["admin_camera_target", _target];
	};

	case "GetCameraTarget": {
		uiNamespace getVariable ["admin_camera_target", objNull];
	};

	case "ViewToolboxChanged": {
		_params params [
			"_ctrl", "_index"
		];

		private _focus = ["GetCameraTarget"] call ULP_fnc_adminCamera;

		if (isNull _focus && { _index isEqualTo 1 }) exitWith {
			hint "You must target someone to spectate first...";
			_ctrl lbSetCurSel 0;
		};

		["ChangeCameraView", [(["free", "fps"] select (_index isEqualTo 1))]] call ULP_fnc_adminCamera;
	};

	case "ToggleList": {
		_params params [
			["_ctrl", controlNull, [controlNull]],
			["_enter", true, [false]]
		];

		if (_enter) then {
			_ctrl ctrlSetBackgroundColor [0, 0, 0, 0.6];
			_ctrl ctrlSetFade 0;
			_ctrl ctrlCommit 0.2;
		} else {
			_ctrl ctrlSetBackgroundColor [0, 0, 0, 0];
			_ctrl ctrlSetFade 0.8;
			_ctrl ctrlCommit 0.2;
		};
	};

	case "Unload": {
		private _camera = uiNamespace getVariable ["admin_camera", objNull];
		if !(isNull _camera) then {
			_camera cameraEffect ["terminate", "back"];
			camDestroy _camera;
		};

		removeMissionEventHandler ["Draw3D", (uiNamespace getVariable ["admin_esp", -1])];
		[uiNamespace getVariable ["admin_each_frame", -1]] call ULP_fnc_removeEachFrame;

		uiNamespace setVariable ['DisplayAdmin', nil];
		player switchCamera "INTERNAL";

		[[["EnablePlayerTags", "HUD"] call ULP_fnc_getOption] call ULP_fnc_bool] call ULP_fnc_playerTags;
	};
};