/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_leaveGroup";

if !([] call ULP_fnc_isGroup) exitWith { false };

private _group = group player;

if ((getPlayerUID player) isEqualTo (_group getVariable ["group_owner", ""])) exitWith {
	["You must transfer the ownership to someone else before you can leave!"] call ULP_fnc_hint;
	false
};

private _name = [_group] call ULP_fnc_getGroupName;

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Leave", "Cancel"],
	format ["Are you sure you want to leave %1...", _name], [_group, _name],
	{	
		_this params [ "_group", "_name" ];

		if ([group player, player] call ULP_fnc_removeMember) then {
			[format ["You have <t color='#B92DE0'>left %1</t>", _name]] call ULP_fnc_hint;

			["Home"] call ULP_fnc_setScreen;
			[ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
		} else {
			[format ["You've failed to leave <t color='#B92DE0'>%1</t>, please try again later...", _name]] call ULP_fnc_hint;
		};
	}, {}, true
] call ULP_fnc_confirm;

true