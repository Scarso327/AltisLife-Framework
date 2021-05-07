/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_changeRank";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if !([2] call ULP_fnc_canGroupRank) exitWith {
	["You don't have permissions to preform this action!"] call ULP_fnc_hint;
};

private _memberList = _display displayCtrl 23062;
private _rankList = _display displayCtrl 23068;

private _selected = lnbCurSelRow _memberList;
private _selectedMember = _memberList lnbData [_selected, 1];
private _selectedRank = lbCurSel _rankList;

if !([_selectedMember, group player] call ULP_fnc_isGroupMember) exitWith {
	["You must selected a member of your group to change the rank of!"] call ULP_fnc_hint;
};

private _currentRank = _memberList lnbValue [_selected, 1];
private _myRank = [] call ULP_fnc_getGroupRank;

// Rank Checks...
if (_selectedRank isEqualTo _currentRank) exitWith { ["This member is already at this rank!"] call ULP_fnc_hint; };
if (_currentRank >= _myRank) exitWith { ["You can't change the rank of someone equal or above your rank!"] call ULP_fnc_hint; };
if (_selectedRank >= _myRank) exitWith { ["You can't set someone to a rank higher or equal to yourself!"] call ULP_fnc_hint; };

private _name = _memberList lnbData [_selected, 0];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Confirm", "Cancel"],
	format ["Are you sure you want to change %1's rank?", _name], [_display, _selectedMember, _selectedRank, _name],
	{
		_this params [ "_display", "_member", "_rank", "_name" ];

		private _unit = [_member] call ULP_fnc_playerByUID;

		if !(isNull _unit) then { _member = _unit; };

		if ([group player, _member, _rank] call ULP_fnc_setGroupRank) then {
			if !(_member isEqualType "") then {
				["GroupRankChanged", [_rank, player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			};

			_display call ULP_fnc_overview;
			[format ["You have changed %1's rank to %2", _name, [_rank] call ULP_fnc_rankName]] call ULP_fnc_hint;
		} else {
			[format ["You failed to change %1's group rank, please try again later...", _name]] call ULP_fnc_hint;
		};
	}, {}, true
] call ULP_fnc_confirm;