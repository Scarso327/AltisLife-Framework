/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_prestige";

_this params [
	"_button"
];

if (isNull _button) exitWith {};
private _display = ctrlParent _button;

if !([] call ULP_fnc_canPrestige) exitWith {};
_button ctrlShow false;

ULP_Professions = createHashMap;
ULP_Level = 1;
ULP_XP = 0;
ULP_Prestige = ULP_Prestige + 1;

["Prestige"] call ULP_fnc_achieve;

[player, 5, ULP_Prestige] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
_display call ULP_fnc_profile;
playMusic "News_Jingle";