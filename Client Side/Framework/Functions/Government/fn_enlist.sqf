/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_enlist";

if (missionNamespace getVariable ["ULP_SRV_Setting_Election", false]) exitWith {
	["You can't enlist for the election while it's on going..."] call ULP_fnc_hint;
};

if (!([player, ["Civilian"]] call ULP_fnc_isFaction) || { [] call ULP_fnc_isUndercover }) exitWith {
	["You must be a civilian to enlist in the next election..."] call ULP_fnc_hint;
};

if !([] call ULP_fnc_isGroup || { ["Governor"] call ULP_fnc_hasGroupPerk }) exitWith {
	["Your group doesn't have the ability to run for governor..."] call ULP_fnc_hint;
};

if ([] call ULP_fnc_isGovernor) exitWith {
	["As Governor, you're unable to run in the next election..."] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Confirm", "Cancel"],
	format ["Are you sure you want to run as %1 for Governor...", profileName], [],
	{	
		if (player getVariable ["enlisting", false]) exitWith {
			["Your enlistment is already being processed!"] call ULP_fnc_hint;
		};

		player setVariable ["enlisting", true];

		["Enlistment", {
			[_this param [0, "You have successfully enlisted in the next election..."]] call ULP_fnc_hint;
			player setVariable ["enlisting", nil];
		}, true] call ULP_fnc_addEventHandler;

		["Requesting Enlistment..."] call ULP_fnc_hint;
		[player] remoteExecCall ["ULP_SRV_fnc_enlistCandidate", RSERV];
	}, false
] call ULP_fnc_confirm;