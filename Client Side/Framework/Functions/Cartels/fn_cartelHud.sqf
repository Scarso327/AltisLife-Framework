/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#define ATTACKING [0.5, 0, 0, 0.65]
#define DEFENDING [0, 0.3, 0.6, 0.65]
scopeName "fn_initCartels";

_this params [
	["_cartel", "", [""]],
	["_mode", "", [""]],
	["_animate", true, [false]]
];
	
// This can only be remote executed by server to update the visuals...
if (isRemoteExecuted && { !(_mode isEqualTo "" || remoteExecutedOwner isEqualTo 2) }) exitWith {};

private _ui = ["RscHUD"] call ULP_UI_fnc_getLayer;
if (isNull _ui) exitWith {};

private _hud = _ui getVariable ["cartel_ui", controlNull];
private _isPopup = _cartel isEqualTo "PopupCartel";

switch (_mode) do {
	case "create": {
		_hud = _ui ctrlCreate ["ULP_CartelHud", -1];
		_ui setVariable ["cartel_ui", _hud];
		_hud ctrlCommit 0;

		if (_animate) then {
			(ctrlPosition _hud) params ["", "_y", "", "_h"];

			_hud ctrlSetPositionY ((0 * safezoneH + safezoneY) - _h);
			_hud ctrlSetFade 1;
			_hud ctrlCommit 0;

			_hud ctrlSetPositionY _y;
			_hud ctrlSetFade 0;
			_hud ctrlCommit 0.5;
		};
		
		if (_isPopup) exitWith {
			private _cartelObj = _this param [3, objNull, [objNull]];
			if (isNull _cartelObj) exitWith { ["PopupCartel", "remove"] call ULP_fnc_cartelHud; };

			private _ctrlProgress = _hud controlsGroupCtrl 102;
			private _ctrlScore = _hud controlsGroupCtrl 105;

			_ctrlProgress ctrlSetTextColor ATTACKING;
			_ctrlScore ctrlSetBackgroundColor ATTACKING;

			// Remove "Tick" bar as it's only used for big cartels
			(_hud controlsGroupCtrl 106) ctrlShow false;
			(_hud controlsGroupCtrl 107) ctrlShow false;

			private _captureTime = getNumber (missionConfigFile >> "CfgCartels" >> "Popup" >> "captureTime");
			_cartelObj setVariable ["endTime", time + _captureTime];

			private _area = _cartelobj getVariable "area";

			[[_cartelObj, _area, (_hud controlsGroupCtrl 103), _ctrlProgress, _ctrlScore, _captureTime], {
				_this params [ "_cartelObj", "_area", "_ctrlStatusText", "_ctrlProgress", "_ctrlScore", "_captureTime" ];

				if (isNil "_cartelObj" || { isNull _cartelObj } || { isNil "_ctrlStatusText" } || { isNull _ctrlStatusText }) exitWith {
					["Popup Cartel has despawned, you need to be quicker next time!"] call ULP_fnc_hint;
					["PopupCartel", "remove"] call ULP_fnc_cartelHud;
					[_thisEventHandler] call ULP_fnc_removeEachFrame;
				};

				if (isNil "_ctrlStatusText" || { isNull _ctrlStatusText }) exitWith {
					[_thisEventHandler] call ULP_fnc_removeEachFrame;
				};

				private _status = switch (true) do {
					case !(isNull (objectParent player)): { "IN VEHICLE" };
					case ([player] call ULP_fnc_onDuty): { "ON DUTY" };
					case ((currentWeapon player) in getArray(missionConfigFile >> "CfgSettings" >> "doesntThreaten")): { "UNARMED" };
					case (count ([_area, allPlayers, ["Police", "Civilian"], { !(_this in (units (group player))) }] call ULP_fnc_unitsInZone) > 0): { "CONTESTED" };
					default { "CAPTURING" }
				};

				_ctrlStatusText ctrlSetStructuredText parseText format ["<t align='center' size='1.25'>%1</t>", _status];

				if !(_status isEqualTo "CAPTURING") then {
					if (isNil { _cartelObj getVariable "pauseTime" }) then {
						_cartelObj setVariable ["pauseTime", time];
					};
				} else {
					private _endTime = _cartelObj getVariable "endTime";
					private _pauseTime = _cartelObj getVariable "pauseTime";

					if !(isNil "_pauseTime") then {
						_endTime = _endTime + (time - _pauseTime); // We have to add on the time we spent not capturing

						_cartelObj setVariable ["endTime", _endTime];
						_cartelObj setVariable ["pauseTime", nil];
					};

					private _progress = (1 - ((_endTime - time) / _captureTime)) min 1;
					_ctrlProgress progressSetPosition _progress;
					_ctrlScore ctrlSetStructuredText parseText format ["<t align='center' size='1.5'>%1</t>", floor (_progress * 100) ];

					if (_progress >= 1) then {
						_cartelObj setVariable ["popup_winner", player, true];
					};
				};
				
				if !(isNil { _cartelObj getVariable "popup_winner" }) then {
					["PopupCartel", "remove"] call ULP_fnc_cartelHud;
					[_thisEventHandler] call ULP_fnc_removeEachFrame;
				};
			}] call ULP_fnc_addEachFrame;
		};

		[(_hud controlsGroupCtrl 107), {
			if (isNil "_this" || { isNull _this }) exitWith {
				[_thisEventHandler] call ULP_fnc_removeEachFrame;
			};

			if !(isNil "ULP_SRV_LastCartelTick") then {
				_this progressSetPosition ((serverTime - ULP_SRV_LastCartelTick) / getNumber (missionConfigFile >> "CfgCartels" >> "Fixed" >> "cartelTick"));
			};
		}] call ULP_fnc_addEachFrame;

		[_cartel] call ULP_fnc_cartelHud;
	};

	if (isNull _hud) exitWith {};

	case "remove": {
		if (_animate) then {
			(ctrlPosition _hud) params ["", "", "", "_h"];

			_hud ctrlSetPositionY ((0 * safezoneH + safezoneY) - _h);
			_hud ctrlSetFade 1;
			_hud ctrlCommit 0.5;
		};

		[{ (ctrlFade _this) >= 1 }, _hud, { ctrlDelete _this; }] call ULP_fnc_waitUntilExecute;
	};

	if (_isPopup) exitWith {};

	default {
		private _object = missionNamespace getVariable [format["ULP_SRV_Cartel_%1", _cartel], objNull];
		if (isNull _object) exitWith {
			["remove"] call ULP_fnc_cartelHud;
		};

		(_object getVariable ["owner", []]) params [
			["_group", grpNull, [grpNull]],
			["_highScore", 0, [0]]
		];

		private _groupScore = (_object getVariable ["scores", createHashMap]) getOrDefault [[] call ULP_fnc_groupId, 0];

		// Makes the UI mark has attacking if contested leadership...
		if (isNull _group && { _groupScore isEqualTo _highScore }) then {
			_groupScore = (_groupScore - 0.5) max 0;
		};

		private _progress = 0;
		if (_highScore > 0) then {
			_progress = _groupScore / _highScore;
		};

		private _ctrlProgress = _hud controlsGroupCtrl 102;
		_ctrlProgress progressSetPosition _progress;

		private _isDefending = ((progressPosition _ctrlProgress) >= 1);

		// Update Status Text...
		(_hud controlsGroupCtrl 103) ctrlSetStructuredText parseText format ["<t align='center' size='1.25'>%1</t>", (["ATTACKING", "DEFENDING"] select _isDefending)];

		// Update Status Colouring...
		private _colour = ([ATTACKING, DEFENDING] select _isDefending);
		(_hud controlsGroupCtrl 102) ctrlSetTextColor _colour;

		private _ctrlScore = _hud controlsGroupCtrl 105;
		_ctrlScore ctrlSetBackgroundColor _colour;

		// Update Score Text (Round the score just in case we've taken half away for the contest system...)
		_ctrlScore ctrlSetStructuredText parseText format ["<t align='center' size='1.5'>%1</t>", round (_groupScore) ];
	};
};