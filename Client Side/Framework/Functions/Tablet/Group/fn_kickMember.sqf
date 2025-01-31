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

if !(["kick"] call ULP_fnc_canGroupRank) exitWith {
	["You don't have permissions to preform this action!"] call ULP_fnc_hint;
};

private _memberList = _display displayCtrl 23062;

private _selected = lnbCurSelRow _memberList;
private _selectedMember = _memberList lnbData [_selected, 1];

if !([_selectedMember, group player] call ULP_fnc_isGroupMember) exitWith {
	["You must selected a member of your group to kick!"] call ULP_fnc_hint;
};

// Rank Checks...
if ((_memberList lnbValue [_selected, 1]) >= ([] call ULP_fnc_getGroupRank)) exitWith { ["You can't kick someone equal or above your rank!"] call ULP_fnc_hint; };

private _name = _memberList lnbData [_selected, 0];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Confirm", "Cancel"],
	format ["Are you sure you want to kick %1?", _name], [_display, _selectedMember, _name],
	{
		_this params [ "_display", "_member", "_name" ];

		private _unit = [_member] call ULP_fnc_playerByUID;

		if !(isNull _unit) then { _member = _unit; };

		if ([group player, _member] call ULP_fnc_removeMember) then {
			if !(_member isEqualType "") then {
				["GroupKicked", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			};

			_display call ULP_fnc_overview;
			[format ["You have kicked <t color='#B92DE0'>%1</t> from the group", _name]] call ULP_fnc_hint;
		} else {
			[format ["You've failed to kick <t color='#B92DE0'>%1</t>, please try again later...", _name]] call ULP_fnc_hint;
		};
	}, {}, true
] call ULP_fnc_confirm;