/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initTags";

["Initialising Personal Tags"] call ULP_fnc_logIt;

private _profile_icon = missionProfileNamespace getVariable ["selected_icon", ""];
if !(_profile_icon isEqualTo "") then {
	private _cfg = missionConfigFile >> "CfgTags" >> "Icons" >> _profile_icon;

	if !(call compile getText (_cfg >> "condition")) then {
		missionProfileNamespace setVariable ["selected_icon", nil];
	};
};

private _colour = missionProfileNamespace getVariable ["selected_name_colour", ""];
if ([] call ULP_fnc_donatorLevel < 1 && { !(_colour isEqualTo ([player] call ULP_fnc_getTagColour)) }) then {
	missionProfileNamespace setVariable ["selected_name_colour", nil];
};

saveMissionProfileNamespace;