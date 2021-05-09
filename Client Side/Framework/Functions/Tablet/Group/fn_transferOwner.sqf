/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_transferOwner";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = group player;

if !((getPlayerUID player) isEqualTo (_group getVariable ["group_owner", ""])) exitWith {
	["Only the owner can transfer group ownership!"] call ULP_fnc_hint;
	false
};

if !((ULP_Houses findIf { [_x, player, false] call ULP_fnc_isHouseOwner && { !(call compile getText (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _x) >> "condition")) } }) isEqualTo -1) exitWith {
	["You must sell all houses that are group dependant before you can transfer ownership!"] call ULP_fnc_hint;
	false
};

private _memberList = _display displayCtrl 23062;

private _selected = lnbCurSelRow _memberList;
private _selectedMember = _memberList lnbData [_selected, 1];

if !([_selectedMember, group player] call ULP_fnc_isGroupMember) exitWith {
	["You must selected a member of your group to transfer ownership to!"] call ULP_fnc_hint;
};

if (_selectedMember isEqualTo (_group getVariable ["group_owner", ""])) exitWith {
	["You can't transfer ownership to yourself"] call ULP_fnc_hint;
	false
};

private _name = _memberList lnbData [_selected, 0];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Confirm", "Cancel"],
	format ["Are you sure you want to transfer ownership to %1?", _name], [_display, _selectedMember, _name],
	{
		_this params [ "_display", "_member", "_name" ];

		private _unit = [_member] call ULP_fnc_playerByUID;

		if !(isNull _unit) then { _member = _unit; };

		if ([group player, _member] call ULP_fnc_setGroupOwner) then {
			if !(_member isEqualType "") then {
				["GroupOwner", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
			};

			_display call ULP_fnc_overview;
			[format ["You have made <t color='#B92DE0'>%1</t> the group owner...", _name]] call ULP_fnc_hint;
		} else {
			[format ["You've transfer ownership to <t color='#B92DE0'>%1</t>, please try again later...", _name]] call ULP_fnc_hint;
		};
	}, {}, true
] call ULP_fnc_confirm;