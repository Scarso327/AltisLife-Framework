/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
#include "..\..\..\UI\gridCommon.inc"
scopeName "fn_perks";

_display = _this;
if (isNull _display) exitWith {};

private _ctrls = _display getVariable ["display_ctrls", []];

if !(_ctrls isEqualTo []) then {
	{ ctrlDelete _x; } forEach _ctrls;
};

_ctrls = [];

private _perks = ("isClass _x" configClasses (missionConfigFile >> "CfgPerks")) apply {
	[(switch (true) do {
		case ([configName _x] call ULP_fnc_hasPerk) : { 0 };
		case ([configName _x] call ULP_fnc_getPerkRequirement isEqualTo []): { 1 };
		default { 2 };
	}), _x]
};

_perks sort true;

private _ctrlGroup = _display displayCtrl 23060;
private _lastCtrlPos = [];
private _xInc = false;
private _item = 1;

{
	_x params ["_state", "_cfg"];

	private _perkCtrl = _display ctrlCreate ["ULP_ctrlPerk", -1, _ctrlGroup];

	if !(_lastCtrlPos isEqualTo []) then {
		_lastCtrlPos params ["_xAxis", "_yAxis", "_w", "_h"];

		_perkCtrl ctrlSetPositionY _yAxis;

		if ((_item % 5) isEqualTo 0) then {
			_perkCtrl ctrlSetPositionY ((_yAxis + ((1 * GUI_GRID_CENTER_H) / 2)) + _h);
			_perkCtrl ctrlSetPositionX ((1 * GUI_GRID_CENTER_W) / 2);
		} else {
			_perkCtrl ctrlSetPositionX ((_xAxis + ((1 * GUI_GRID_CENTER_W) / 2)) + _w);
			_xInc = false;
		};

		_item = _item + 1;
	};

	_perkCtrl ctrlCommit 0;

	private _iconCtrl = _perkCtrl controlsGroupCtrl 101;
	_iconCtrl ctrlSetText getText (_cfg >> "icon");
	_iconCtrl ctrlSetTooltip format [getText (_cfg >> "description"), [configName _cfg] call ULP_fnc_getPerkBonus, "%"];

	private _nameCtrl = _perkCtrl controlsGroupCtrl 102;
	_nameCtrl ctrlSetStructuredText parseText format["<t align='center'>%1</t>",  getText (_cfg >> "displayName")];
	_nameCtrl ctrlEnable false;

	private _coverCtrl = _perkCtrl controlsGroupCtrl 103;
	_coverCtrl ctrlShow (_state isEqualTo 2);
		
	private _button = _perkCtrl controlsGroupCtrl 104;
	private _ctrlLevel = _perkCtrl controlsGroupCtrl 105;
	_ctrlLevel ctrlShow false;

	if (_state isEqualTo 2) then {
		private _requirement = [configName _cfg] call ULP_fnc_getPerkRequirement;
		_coverCtrl ctrlSetTooltip format ["Requires %1 %2", _requirement select 0, _requirement select 1];
		_button ctrlEnable false;
	} else {
		private _maxLevel = getNumber (_cfg >> "Leveling" >> "maxLevel");
		if (_maxLevel > 1) then {
			_ctrlLevel ctrlSetStructuredText parseText format["<t align='center'>%1/%2</t>", (([configName _cfg] call ULP_fnc_getPerkLevel) select 0), _maxLevel];
			_ctrlLevel ctrlShow true;
		};

		_button ctrlSetEventHandler ["ButtonClick", format["[""%1""] call ULP_fnc_togglePerk", configName _cfg]];
	};
	
	if (_state isEqualTo 0) then {
		private _cost = getNumber (missionConfigFile >> "CfgPerks" >> "removalCost");
		_cost = _cost * getNumber (_cfg >> "removalMultiplier");

		_nameCtrl ctrlSetBackgroundColor [0.451, 0, 0.902, 1];
		_button ctrlSetTooltip (["Deativate Perk", format ["Removal Cost: %1%2", "£", [_cost] call ULP_fnc_numberText]] joinString "\n");
	} else {
		_button ctrlSetTooltip "Activate Perk";
	};

	_lastCtrlPos = ctrlPosition _perkCtrl;
	_ctrls pushBack _perkCtrl;
} forEach _perks;

_display setVariable ["display_ctrls", _ctrls];