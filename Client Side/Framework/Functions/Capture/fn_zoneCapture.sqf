/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#define ATTACKING [0.5, 0, 0, 0.65]
#define DEFENDING [0, 0.3, 0.6, 0.65]
scopeName "fn_zoneCapture";

_this params [
	["_obj", objNull, [objNull]],
	["_zoneName", "", [""]],
	["_mode", 0, [0]]
];

private _display = ["RscHUD"] call ULP_UI_fnc_getLayer;
private _captureCtrl = _display getVariable ["zoneCaptureCtrl", controlNull];

switch (_mode) do {
	case 0: {
		if (isNull _display || { _zoneName isEqualTo "" }) exitWith {};

		if !(isNull _captureCtrl) then {
			ctrlDelete _captureCtrl;
		};

		_captureCtrl = _display ctrlCreate ["ULP_CartelHud", -1];
		_display setVariable ["zoneCaptureCtrl", _captureCtrl];
		_captureCtrl ctrlCommit 0;

		(ctrlPosition _captureCtrl) params ["", "_y", "", "_h"];

		_captureCtrl ctrlSetPositionY ((0 * safezoneH + safezoneY) - _h);
		_captureCtrl ctrlSetFade 1;
		_captureCtrl ctrlCommit 0;

		_captureCtrl ctrlSetPositionY _y;
		_captureCtrl ctrlSetFade 0;
		_captureCtrl ctrlCommit 0.5;

		_captureCtrl setVariable ["zoneName", _zoneName];

		_obj setVariable ["nextTick", diag_tickTime + 2];

		private _ctrlProgress = _captureCtrl controlsGroupCtrl 102;
		private _ctrlStatusText = _captureCtrl controlsGroupCtrl 103;
		private _ctrlScore = _captureCtrl controlsGroupCtrl 105;

		_ctrlProgress ctrlSetTextColor ATTACKING;
		_ctrlScore ctrlSetBackgroundColor ATTACKING;
		
		(_captureCtrl controlsGroupCtrl 106) ctrlShow false;
		(_captureCtrl controlsGroupCtrl 107) ctrlShow false;

		[_zoneName, ([[_obj, _zoneName, _captureCtrl, _ctrlProgress, _ctrlStatusText, _ctrlScore], {
			_this params [ "_obj", "_zoneName", "_captureCtrl", "_ctrlProgress", "_ctrlStatusText", "_ctrlScore" ];
			
			private _area = format ["redzone_%1_zone", _zoneName];

			if (isNull _obj || { !([_area] call ULP_fnc_isUnitsInZone) }) exitWith {
				[_obj, _zoneName, 1] call ULP_fnc_zoneCapture;
			};

			private _doesNotThreaten = getArray (missionConfigFile >> "CfgSettings" >> "doesntThreaten");
			private _group = group player;

			private _status = switch (true) do {
				case !(([_area, allPlayers, ["Police", "Civilian", "Dunamis"], { !(_this in (units (group player))) && { !((currentWeapon _this) in _doesNotThreaten) } }] call ULP_fnc_unitsInZone) isEqualTo []): { "CONTESTED" };
				case ((_obj getVariable ["object_owner", grpNull]) isEqualTo _group): {
					if !((progressPosition _ctrlProgress) isEqualTo 1) then {
						_obj setVariable ["progress", nil];
						_ctrlScore ctrlSetStructuredText parseText "<t align='center' size='1.5'>100%</t>";
						_ctrlProgress progressSetPosition 1;
					};
					"CAPTURED"
				};
				case (([] call ULP_fnc_groupId) isEqualTo -1): { "MUST BE IN GROUP" };
				case !(isNull (objectParent player)): { "IN VEHICLE" };
				case ([player] call ULP_fnc_onDuty): { "ON DUTY" };
				case ((currentWeapon player) in _doesNotThreaten): { "UNARMED" };
				default { "CAPTURING" };
			};

			_ctrlStatusText ctrlSetStructuredText parseText format ["<t align='center' size='1.25'>%1</t>", _status];

			private _nextTick = _obj getVariable ["nextTick", diag_tickTime];
			if (_nextTick > diag_tickTime || { !(_status isEqualTo "CAPTURING") }) exitWith {};

			_obj setVariable ["nextTick", diag_tickTime + 0.5];

			private _progress = _obj getVariable ["progress", 0];
			_progress = _progress + 0.01;

			_obj setVariable ["progress", _progress];

			private _progressTotal = _progress / 1;
			_ctrlProgress progressSetPosition _progressTotal;
			_ctrlScore ctrlSetStructuredText parseText format ["<t align='center' size='1.5'>%1%2</t>", floor (_progressTotal * 100), "%" ];

			if (_progress >= 1 && { !((_obj getVariable ["object_owner", grpNull]) isEqualTo _group) }) then {
				_obj setVariable ["object_owner", _group, true];

				// TODO - This method is supposed to be "unique" so need to think about broadcasting this uniquely?
				["onConflictNodeCapturedConflict", [_obj, _group], true] call ULP_fnc_invokeEvent;
			};
		}] call ULP_fnc_addEachFrame)] call ULP_fnc_addZoneCaptureEachFrame;
	};
	case 1: {

		if !(isNull _captureCtrl) then {
			private _uiZone = _captureCtrl getVariable ["zoneName", _zoneName];
			if !(_uiZone isEqualTo _zoneName) exitWith {};

			(ctrlPosition _captureCtrl) params ["", "", "", "_h"];

			_captureCtrl ctrlSetPositionY ((0 * safezoneH + safezoneY) - _h);
			_captureCtrl ctrlSetFade 1;
			_captureCtrl ctrlCommit 0.5;

			_zoneName = _captureCtrl getVariable ["zoneName", _zoneName];
			[{ (ctrlFade _this) >= 1 }, _captureCtrl, { ctrlDelete _this; }] call ULP_fnc_waitUntilExecute;
		};

		_obj setVariable ["progress", nil];
		_obj setVariable ["nextTick", nil];

		[_zoneName] call ULP_fnc_removeZoneCaptureEachFrame;
	};
};