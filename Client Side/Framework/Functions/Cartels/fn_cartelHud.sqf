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