/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isProtection";

([] call ULP_fnc_isGroup && 
	{ ["PersonalProtection"] call ULP_fnc_hasGroupPerk } && 
	{ ["Protection"] call ULP_fnc_hasLicense } &&
	{ ((missionNamespace getVariable ["ULP_SRV_Setting_Governor", []]) param [1, ""]) in ((group player) getVariable ["group_members", createHashMap]) })