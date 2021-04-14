/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_disbandGroup";

if !([] call ULP_fnc_isGroup) exitWith { false };

private _group = group player;

if !((getPlayerUID player) isEqualTo (_group getVariable ["group_owner", ""])) exitWith {
	["You must be the group owner to disband the group!"] call ULP_fnc_hint;
	false
};

if !(isNil "ULP_DisbandEvent") then { ["GroupDisbanded", ULP_DisbandEvent] call ULP_fnc_removeEventHandler; ULP_DisbandEvent = nil; };

ULP_DisbandEvent = ["GroupDisbanded", {
	private _display = findDisplay 23000;
	if (isNull _display) exitWith {};

	if ((configName (_display getVariable ["screen", ""])) in ["Group", "GroupOverview", "GroupProgression", "GroupSettings"]) then {
		["Home"] call ULP_fnc_setScreen;
		ULP_DisbandEvent = nil;
	};
}] call ULP_fnc_addEventHandler;

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Disband", "Cancel"],
	format ["Are you sure you want to disband %1...", [_group] call ULP_fnc_getGroupName], [_group],
	{	
		_this params [ "_group" ];

		[player, _group] remoteExecCall ["ULP_SRV_fnc_disbandGroup", RSERV];
		["GroupDisbanded", [player]] remoteExecCall ["ULP_fnc_invokeEvent", (units _group)];

		{
			[_x] joinSilent (createGroup [side _x, true]);
		} forEach (units _group);
		deleteGroup _group;
	}, true, { if !(isNil "ULP_DisbandEvent") then { ["GroupDisbanded", ULP_DisbandEvent] call ULP_fnc_removeEventHandler; ULP_DisbandEvent = nil; }; }
] call ULP_fnc_confirm;

true