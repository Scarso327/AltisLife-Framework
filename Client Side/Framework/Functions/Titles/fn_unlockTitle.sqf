/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_unlockTitle";

_this params [
	["_title", "", [""]]
];

private _cfg = missionConfigFile >> "CfgTitles" >> _title;
if !(isClass _cfg) exitWith { false };

if ([_title] call ULP_fnc_hasTitle) exitWith { false };

["TitleUnlocked", [getText(_cfg >> "description")]] call BIS_fnc_showNotification;
playSound "FD_Finish_F";

if (isText (_cfg >> "onUnlocked")) then {
	call compile getText (_cfg >> "onUnlocked");
};

ULP_Titles pushBackUnique _title;
[player, 10, ULP_Titles] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];

true