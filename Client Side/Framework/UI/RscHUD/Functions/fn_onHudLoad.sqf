/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onHudLoad";

private _display = _this;

if (isNull _display) exitWith {};

disableSerialization;

if !(isNil { uiNamespace getVariable "RscHUD" }) exitWith {
	["Called onLoad HUD when HUD already exists?"] call ULP_fnc_logIt;
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