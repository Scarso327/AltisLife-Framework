/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this] call ULP_fnc_addMailBox;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addMailBox";

_this params [
	["_trader", objNull, [objNull]]
];

_trader addAction ["<t color='#B92DE0'>[Civilian]</t> Mail Box", { [(_this select 3)] call ULP_fnc_openMailBox }, _cfg, 1, true, true, "", "[_this, [""Civilian""]] call ULP_fnc_isFaction", 3];