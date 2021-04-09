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
		saveProfileNamespace;
	};
};