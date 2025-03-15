/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_finishTutorial";

if !([] call ULP_fnc_isOnTutorial) exitWith { false };

player setVariable ["isOnTutorial", nil, true];

[
	"<t color='#008000' size='1.5px'>Tutorial<br/></t><t color='#ffffff' size='1px'>Congratulations, you have finish the basic introduction tutorial. You should now know the basics to help you get started elsewhere on the island. Why not try processing your Apples at Schnapps Processing?"
] call ULP_fnc_hint;

["CompletedTutorial"] call ULP_fnc_achieve;

true
