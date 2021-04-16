/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
#include "..\..\..\UI\gridCommon.inc"
scopeName "fn_progression";

_display = _this;
if (isNull _display) exitWith {};

private _xp = [] call ULP_fnc_groupXP;
private _required = [(([] call ULP_fnc_groupLevel) + 1), missionConfigFile >> "CfgGroups" >> "Leveling"] call ULP_fnc_getRequiredXP;

(_display displayCtrl 23083) progressSetPosition (_xp / _required);

(_display displayCtrl 23084) ctrlSetStructuredText parseText format ["<t size='2.5'>Level %1<t align='center'>%2/%3</t><t align='right'>Level %4</t>",
	[[] call ULP_fnc_groupLevel] call ULP_fnc_numberText,
	[_xp] call ULP_fnc_numberText,
	[_required] call ULP_fnc_numberText,
	[((([] call ULP_fnc_groupLevel) + 1) min ([missionConfigFile >> "CfgGroups" >> "Leveling"] call ULP_fnc_getMaxLevel))] call ULP_fnc_numberText
];

private _ctrls = _display getVariable ["display_ctrls", []];

if !(_ctrls isEqualTo []) then {
	{ ctrlDelete _x; } forEach _ctrls;
};

_ctrls = [];

private _ctrlGroup = _display displayCtrl 23085;
private _lastCtrlPos = [];

{
	private _perk = _display ctrlCreate ["ULP_ctrlGroupPerk", -1, _ctrlGroup];

	if !(_lastCtrlPos isEqualTo []) then {
		_perk ctrlSetPositionY (((_lastCtrlPos # 1) + ((1 * GUI_GRID_CENTER_H) / 2)) + (_lastCtrlPos # 3));
	};

	_perk ctrlCommit 0;

	private _iconCtrl = _perk controlsGroupCtrl 101;
	_iconCtrl ctrlSetText getText (_x >> "icon");

	private _nameCtrl = _perk controlsGroupCtrl 102;
	_nameCtrl ctrlSetStructuredText parseText getText (_x >> "displayName");

	private _descCtrl = _perk controlsGroupCtrl 103;
	_descCtrl ctrlSetStructuredText parseText getText (_x >> "description");

	private _overlay = _perk controlsGroupCtrl 105;
	_overlay ctrlSetStructuredText parseText format["<br/><br/><t size='2' align='center'>Requires Level %1</t>", getNumber (_x >> "level")];
	_overlay ctrlShow !([configName _x] call ULP_fnc_hasGroupPerk);

	_lastCtrlPos = ctrlPosition _perk;
	_ctrls pushBack _perk;
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgGroups" >> "Types" >> ((group player) getVariable ["group_type", ""]) >> "Perks"));

_ctrlGroup = _display displayCtrl 23086;
_lastCtrlPos = [];

{
	private _buff = _display ctrlCreate ["ULP_ctrlGroupBuff", -1, _ctrlGroup];

	if !(_lastCtrlPos isEqualTo []) then {
		_buff ctrlSetPositionY (((_lastCtrlPos # 1) + ((1 * GUI_GRID_CENTER_H) / 2)) + (_lastCtrlPos # 3));
	};

	_buff ctrlCommit 0;

	private _iconCtrl = _buff controlsGroupCtrl 101;
	_iconCtrl ctrlSetText getText (_x >> "icon");

	private _nameCtrl = _buff controlsGroupCtrl 102;
	_nameCtrl ctrlSetStructuredText parseText getText (_x >> "displayName");

	private _progressCtrl = _buff controlsGroupCtrl 103;
	_progressCtrl progressSetPosition (([group player, configName _x] call ULP_fnc_groupBuff) / getNumber (_x >> "max"));

	private _textCtrl = _buff controlsGroupCtrl 104;
	_textCtrl ctrlSetStructuredText parseText format["<t align='center'>%1%2</t>", (([group player, configName _x] call ULP_fnc_groupBuff) * 100), "%"];

	_lastCtrlPos = ctrlPosition _buff;
	_ctrls pushBack _buff;
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgGroups" >> "Buffs"));

_display setVariable ["display_ctrls", _ctrls];