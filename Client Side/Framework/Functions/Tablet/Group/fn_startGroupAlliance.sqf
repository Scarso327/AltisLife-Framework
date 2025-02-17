/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_startGroupAlliance";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if !([] call ULP_fnc_isGroupOwner) exitWith {
	["You must be the group owner to manage alliances!"] call ULP_fnc_hint;
	false
};

if (_display getVariable ["alliance_processing", false]) exitWith { false };

private _group = group player;
private _allies = [] call ULP_fnc_alliedGroups;

private _groups = (allGroups select { [_x] call ULP_fnc_isGroup && { !(_x in _allies) } && { !(_x isEqualTo _group) } });
_groups = _groups apply { ["", [_x] call ULP_fnc_getGroupName, _x call BIS_fnc_netId, -1] };

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), _groups, ["Select", "Cancel"], [], {
	_this params [
		["_display", displayNull, [displayNull]]
	];
	
	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _group = (_list lbData (lbCurSel _list)) call BIS_fnc_groupFromNetId;
	if (isNull _group) exitWith { ["You didn't select a group"] call ULP_fnc_hint; };

	private _allies = [] call ULP_fnc_alliedGroups;
	if (_group in _allies) exitWith { ["You're already allied with this group"] call ULP_fnc_hint; };
	
	private _unit = ((units _group) select { [_x] call ULP_fnc_isGroupOwner }) param [0, objNull, [objNull]];

	if (isNull _unit) exitWith { ["The owner of this group isn't online to accept your invite"] call ULP_fnc_hint; };

	_display setVariable ["alliance_processing", nil];

	["Invite Sent"] call ULP_fnc_hint;
	["GroupAllianceInvite", [group player, player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
}] call ULP_fnc_selectObject;

true