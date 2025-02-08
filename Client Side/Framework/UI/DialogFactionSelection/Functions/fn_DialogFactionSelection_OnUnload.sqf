/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogFactionSelection_OnUnload";

_this params [ "_display" ];

if (isNull _display) exitWith {};

uiNamespace setVariable ["DialogFactionSelection", nil];

if (isNil { player getVariable "faction" }) then {
	["Abort", true, false] call BIS_fnc_endMission;
};