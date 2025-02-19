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

		camUseNVG false;
		false setCamUseTI 0;
		ULP_AdminCameraVision = "NORMAL";
		
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
		_display displayAddEventHandler ["KeyUp", {
			_this params [
				"", "", "_shift", "_ctrlKey", "_alt"
			];

			if !(_shift || { _alt }) then {
				["SetCameraSpeed", [false]] call ULP_fnc_adminCamera;
			};
		}];
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
		[false] call ULP_fnc_groupIndicators;
		[["RscHUD"] call ULP_UI_fnc_getLayer] call ULP_UI_fnc_closeHUD;

		uiNamespace setVariable ["admin_each_frame", ([_display, { ["eachFrame", [_this, _thisEventHandler]] call ULP_fnc_adminCamera; }, 1] call ULP_fnc_addEachFrame)];

		[getPlayerUID player, "Admin", ["AdminCamera", serverTime, []]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
	};

	case "action": {
		_params params [
			["_type", "", [""]]
		];

		if !(["Teleport"] call ULP_fnc_checkPower) exitWith {};

		if (time < (player getVariable ["admin_action_cooldown", 0])) exitWith {
			["You've recently used a command, please wait before trying again..."] call ULP_fnc_hint;
			false
		};

		private _focus = ["GetCameraTarget"] call ULP_fnc_adminCamera;
		if (isNull _focus) exitWith { ["You need to select someone to preform this action on..."] call ULP_fnc_hint; };

		player setVariable ["admin_action_cooldown", time + 2];

		switch (_type) do {
			case "Eject": {
				if !([_focus] call ULP_fnc_ejectVehicleUnit) exitWith { [format ["<t color='#B92DE0'>%1</t> isn't in a vehicle...", name _focus]] call ULP_fnc_hint; };

				[getPlayerUID player, "Admin", ["AdminEjectVehicle", serverTime, [name _focus, getPlayerUID _focus, getPos _focus]]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
			};

			if (_focus isEqualTo player) exitWith { ["You can't perform these actions on yourself..."] call ULP_fnc_hint; };
			if !(isNull (objectParent player)) exitWith { ["You need to leave the vehicle you're in before you can do this..."] call ULP_fnc_hint; };

			case "To": {	
				player setPos (getPos _focus);
				[format ["You have teleported to <t color='#B92DE0'>%1</t>", name _focus]] call ULP_fnc_hint;
				[getPlayerUID player, "Admin", ["AdminTeleportTo", serverTime, [name _focus, getPlayerUID _focus, getPos _focus]]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
			};

			case "Here": {
				_focus setPos (getPos player);
				[format ["You have teleported <t color='#B92DE0'>%1</t> to you", name _focus]] call ULP_fnc_hint;
				[getPlayerUID player, "Admin", ["AdminTeleportHere", serverTime, [name _focus, getPlayerUID _focus, getPos _focus]]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
			};
			
			case "Vehicle": {
				if (isNull (objectParent _focus)) exitWith { [format ["<t color='#B92DE0'>%1</t> isn't in a vehicle...", name _focus]] call ULP_fnc_hint; };
								
				private _vehicle = (vehicle _focus);

				if (count (crew _vehicle) >= ((([typeOf _vehicle] call ULP_fnc_vehicleCfg) param [6, 0]) + 1)) exitWith {
					[format ["<t color='#B92DE0'>%1's</t> vehicle is full...", name _focus]] call ULP_fnc_hint;
				};

				player moveInCargo _vehicle;
				player moveInGunner _vehicle;

				[getPlayerUID player, "Admin", ["AdminJoinVehicle", serverTime, [name _focus, getPlayerUID _focus, getPos _focus]]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
			};
		};
	};

	case "eachFrame": {
		_params params [
			["_display", displayNull, [displayNull]],
			["_id", -1, [0]]
		];

		if (isNull _display) exitWith {
			[_id] call ULP_fnc_removeEachFrame;
		};

		["updateList", [(_display displayCtrl 602) controlsGroupCtrl 101]] call ULP_fnc_adminCamera;
	};

	case "mapDraw": {
		_params params [
			["_ctrlMap", controlNull, [controlNull]]
		];

		{
			_ctrlMap drawIcon [
				"\A3\ui_f\data\map\vehicleicons\iconman_ca.paa",
				getArray (missionConfigFile >> "CfgFactions" >> ([_x] call ULP_fnc_getFaction) >> "colour"),
				getPosVisual _x, 26, 26, getDirVisual _x, [_x] call ULP_fnc_getName, 1, 0.06, 'TahomaB', 'right'
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

					[getPlayerUID player, "Admin", ["AdminTeleport", serverTime, [getPlayerUID player, _pos]]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
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

		private _display = ctrlParent _ctrl;

		private _groups = [];
		private _newGroups = [];
		private _oldGroups = _display getVariable ["groups", []];

		{
			private _group = _x;
			private _units = ((units _group) select { isPlayer _x });

			if !(_units isEqualTo []) then {
				if ((_oldGroups findIf { (_x select 0) isEqualTo _group }) isEqualTo -1) then {
					_newGroups pushBackUnique _group;
				};

				_groups pushBack [_group, _units];
			};
		} forEach allGroups;

		if !(_groups isEqualTo _oldGroups) then {

			{
				private _parent = _ctrl tvAdd [[], groupId _x];
				_ctrl tvSetData [[_parent], _x call BIS_fnc_netId];
				_ctrl tvSetPicture [[_parent], "\a3\ui_f_curator\data\Displays\RscDisplayCurator\side_west_ca.paa"];
			} forEach _newGroups;

			for "_i" from 0 to ((_ctrl tvCount []) - 1) do {
				private _groupPath = [_i];
				private _group = (_ctrl tvData _groupPath) call BIS_fnc_groupFromNetId;
				private _units = units _group;

				if (isNull _group || { _units isEqualTo [] }) then {
					_ctrl tvDelete _groupPath;
				} else {
					for "_y" from 0 to ((_ctrl tvCount _groupPath) - 1) do {
						private _unitPath = _groupPath + [_y];
						private _unit = (_ctrl tvData _unitPath) call BIS_fnc_objectFromNetId;

						if (isNull _unit || { !(_unit in _units) }) then {
							_ctrl tvDelete _unitPath;
						};

						_units = _units - [_unit];
					};

					{
						private _member = _ctrl tvAdd [_groupPath, [_x, false, true] call ULP_fnc_getName];
						private _unitPath = _groupPath + [_member];

						_ctrl tvSetData [_unitPath, _x call BIS_fnc_netId];
						_ctrl tvSetPicture [_unitPath, [getText(configFile >> "CfgVehicles" >> typeOf _x >> "icon")] call BIS_fnc_textureVehicleIcon];
					} forEach _units;
				};
			};

			_display setVariable ["groups", _groups];
		};
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

					private _camera = uiNamespace getVariable ["admin_camera", objNull];
					private _object = vehicle player;

					private _surfaces = lineIntersectsSurfaces [getPosASL _camera, AGLtoASL screenToWorld [0.5,0.5]];
					private _worldPos = if (_surfaces isEqualTo []) then {
						screenToWorld [0.5,0.5]
					} else {
						ASLtoAGL (_surfaces select 0 select 0)
					};

					// Maintain Altitude
					private _alt = if !(_object isEqualTo player) then {
						((getPosATL _object) select 2)
					} else {
						_worldPos select 2
					};

					_object setPosATL [_worldPos select 0, _worldPos select 1, _alt];
					_object setVelocity [0,0,0];

					[getPlayerUID player, "Admin", ["AdminTeleport", serverTime, [getPlayerUID player, _worldPos]]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];

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

			case N: {
				private _camera = uiNamespace getVariable ["admin_camera", objNull];

				if ([] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { !(isNull _camera) } && { !_shift } && { !_ctrlKey } && { !_alt }) then {
					switch (ULP_AdminCameraVision) do {
						// Thermal
						case "NVG": {
							ULP_AdminCameraVision = "THERMAL";

							camUseNVG false;
							true setCamUseTI 0;
						};
						// Normal
						case "THERMAL": {
							ULP_AdminCameraVision = "NORMAL";

							camUseNVG false;
							false setCamUseTI 0;
						};
						// NVG
						default {
							ULP_AdminCameraVision = "NVG";

							camUseNVG true;
							false setCamUseTI 0;
						};
					};

					playSound ["RscDisplayCurator_visionMode", true];
					_handled = true;
				};
			};
		};

		if !(_handled) then {
			if (_shift && { _alt } && { !_ctrlKey }) then {
				["SetCameraSpeed", [true]] call ULP_fnc_adminCamera;
			};
		};

		_handled
	};

	case "SetCameraSpeed": {
		_params params [
			["_fast", false, [true]]
		];

		private _camera = uiNamespace getVariable ["admin_camera", objNull];
		if !(isNull _camera) then {
			_camera camCommand format["speedDefault %1", (["0.1", "3"] select (_fast))];
			uiNamespace setVariable ['admin_camera_speed', _fast];
		};
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
			["You must target someone to spectate first..."] call ULP_fnc_hint;
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
		[[["EnableIndicators", "Indicators"] call ULP_fnc_getOption] call ULP_fnc_bool] call ULP_fnc_groupIndicators;

		if (["EnableHUD", "HUD"] call ULP_fnc_getOption isEqualTo 1) then {
			[] call ULP_UI_fnc_openHUD;
		};
	};
};