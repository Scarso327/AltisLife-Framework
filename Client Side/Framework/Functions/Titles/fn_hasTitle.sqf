/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasTitle";

_this params [
	["_title", "", [""]]
];

if !(isClass (missionConfigFile >> "CfgTitles" >> _title)) exitWith { false };

(_title in ULP_Titles)