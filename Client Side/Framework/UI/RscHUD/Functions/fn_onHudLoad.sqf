/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onHudLoad";

_this params [ "_display" ];

if (isNull _display) exitWith {};

disableSerialization;

if !(isNil { uiNamespace getVariable "RscHUD" }) then {
	["RscHUD"] call ULP_UI_fnc_destroyLayer;
};

_display setVariable ["food", -1];
_display setVariable ["water", -1];
_display setVariable ["health", -1];
_display setVariable ["icons", []];

uiNamespace setVariable ["RscHUD", _display];

private _foodText = _display displayCtrl 501;
private _foodBar = _display displayCtrl 515;
private _waterText = _display displayCtrl 503;
private _waterBar = _display displayCtrl 514;
private _healthText = _display displayCtrl 505;
private _healthBar = _display displayCtrl 513;
private _moneyText = _display displayCtrl 512;
_moneyText ctrlSetStructuredText parseText format["<t align='right'>£%1</t>", [CASH] call ULP_fnc_numberText];

_display setVariable ["eachframe", ([[_display, [_foodText, _foodBar], [_waterText, _waterBar], [_healthText, _healthBar]], { _this call ULP_UI_fnc_eachFrameHUD }] call ULP_fnc_addEachFrame)];

[] call ULP_UI_fnc_onXPUpdateHud;
_display setVariable ["eventhandler", (["OnXPIncreased", { [] call ULP_UI_fnc_onXPUpdateHud; }] call ULP_fnc_addEventHandler)];

_display setVariable ["money", (["MoneyChanged", {
	_this params [
		["_cash", 0, [0]],
		["_bank", 0, [0]]
	];

	private _display = ["RscHUD"] call ULP_UI_fnc_getLayer;
	if (isNull _display) exitWith {};

	(_display displayCtrl 512) ctrlSetStructuredText parseText format["<t align='right'>£%1</t>", [_cash] call ULP_fnc_numberText];
}] call ULP_fnc_addEventHandler)];

private _onEnteredRedzone = {
	private _display = ["RscHUD"] call ULP_UI_fnc_getLayer;

	if (isNull _display) exitWith { [_event, _eventId] call ULP_fnc_removeEventHandler; };

	["ReceivedStats", {
		private _display = ["RscHUD"] call ULP_UI_fnc_getLayer;

		private _redzoneUi = _display getVariable ["redzone_hud", controlNull];
		if (isNull _display || { isNull _redzoneUi }) exitWith {};

		private _scoreCtrl = _redzoneUi controlsGroupCtrl 103;

		private _stats = createHashMapFromArray _this;

		private _kills = _stats getOrDefault ["Kills", 0];
		private _deaths = _stats getOrDefault ["Deaths", 0];

		_scoreCtrl ctrlSetStructuredText parseText format ["<t align='left' size='1'>%1</t><t align='right' size='1'>%2</t>", _kills, _deaths];

		_scoreCtrl setVariable ["Kills", _kills];
		_scoreCtrl setVariable ["Deaths", _deaths];

		_display setVariable ["IncapacitatedEvent", (["Incapacitated", {
			_this params [
				["_unit", objNull, [objNull]],
				["_killer", objNull, [objNull]]
			];
			
			if (isNull _unit || { !(_killer isEqualTo player) } || { _unit isEqualTo player }) exitWith {};

			private _display = ["RscHUD"] call ULP_UI_fnc_getLayer;

			private _redzoneUi = _display getVariable ["redzone_hud", controlNull];
			if (isNull _display || { isNull _redzoneUi }) exitWith { [_event, _eventId] call ULP_fnc_removeEventHandler; };

			private _scoreCtrl = _redzoneUi controlsGroupCtrl 103;
				
			private _kills = (_scoreCtrl getVariable ["Kills", 0]) + 1;
			private _deaths = _scoreCtrl getVariable ["Deaths", 0];

			_scoreCtrl ctrlSetStructuredText parseText format ["<t align='left' size='1'>%1</t><t align='right' size='1'>%2</t>", _kills, _deaths];

			_scoreCtrl setVariable ["Kills", _kills];
		}] call ULP_fnc_addEventHandler)];
	}, true] call ULP_fnc_addEventHandler;

	[player, ["Kills", "Deaths"]] remoteExecCall ["ULP_SRV_fnc_getStats", 2];

	private _redzoneUi = _display ctrlCreate ["ULP_RedzoneHud", -1];
	_display setVariable ["redzone_hud", _redzoneUi];

	_redzoneUi ctrlSetFade 1;
	_redzoneUi ctrlCommit 0;

	_redzoneUi ctrlSetFade 0;
	_redzoneUi ctrlCommit 0.5;
};

if (missionNamespace getVariable ["InRedzone", false]) then {
	[] call _onEnteredRedzone;
};

_display setVariable ["EnteredRedzoneEvent", (["EnteredRedzone", _onEnteredRedzone] call ULP_fnc_addEventHandler)];

_display setVariable ["LeftRedzoneEvent", (["LeftRedzone", {
	private _display = ["RscHUD"] call ULP_UI_fnc_getLayer;

	if (isNull _display) exitWith { [_event, _eventId] call ULP_fnc_removeEventHandler; };
	
	private _redzoneUi = _display getVariable ["redzone_hud", controlNull];
	if (isNull _redzoneUi) exitWith {};

	["Incapacitated", _display getVariable ["IncapacitatedEvent", -1]] call ULP_fnc_removeEventHandler;

	_display setVariable ["redzone_hud", nil];

	_redzoneUi ctrlSetFade 1;
	_redzoneUi ctrlCommit 0.5;

	[{ (ctrlFade _this) >= 1 }, _redzoneUi, { ctrlDelete _this; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler)];