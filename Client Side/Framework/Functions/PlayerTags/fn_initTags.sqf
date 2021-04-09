/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initTags";

["Initialising Personal Tags"] call ULP_fnc_logIt;

private _profile_icon = profileNamespace getVariable ["selected_icon", ""];
if !(_profile_icon isEqualTo "") then {
	private _cfg = missionConfigFile >> "CfgTags" >> "Icons" >> _profile_icon;

	if !(call compile getText (_cfg >> "condition")) then {
		profileNamespace setVariable ["selected_icon", nil];
	};
};

private _colour = profileNamespace getVariable ["selected_name_colour", ""];
if ([] call ULP_fnc_donatorLevel < 1 && { !(_colour isEqualTo ([player] call ULP_fnc_getTagColour)) }) then {
	profileNamespace setVariable ["selected_name_colour", nil];
};

saveProfileNamespace;