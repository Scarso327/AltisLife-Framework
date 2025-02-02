/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_setRankPermission";

_this params [
	"_ctrl", "_permission"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if !([] call ULP_fnc_isGroupOwner) exitWith {
	["You must be the group owner to change these settings!"] call ULP_fnc_hint;
};

private _ranks = [] call ULP_fnc_groupRanks;
private _selectableRanks = _ranks apply { ["", _x, _x, -1] };

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), _selectableRanks, ["Select", "Cancel"], [_ranks, _permission], {
	_this params [
		["_ranks", [], [[]]],
		["_permission", "", [""]],
		["_display", displayNull, [displayNull]]
	];
	
	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _index = lbCurSel _list;
	if (_index isEqualTo -1) exitWith { ["You didn't select a rank"] call ULP_fnc_hint; };
	
	private _group = group player;
	private _permissions = + ([_group] call ULP_fnc_groupPermissions);

	private _currentRequirement = _permissions getOrDefault [_permission, 0];

	if (_currentRequirement isEqualTo _index) exitWith {
		["That permission is already set to that rank"] call ULP_fnc_hint;
	};

	_permissions set [_permission, _index];
	_group setVariable ["group_permissions", _permissions, true];

	[_group] remoteExecCall ["ULP_SRV_fnc_setGroupPermissions", RSERV];

	["Group Permission Updated"] call ULP_fnc_hint;
}] call ULP_fnc_selectObject;