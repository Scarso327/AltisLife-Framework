/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addGambling";

_this params [
	["_trader", objNull, [objNull]]
];

if (isNull _trader) exitWith {};

_trader addAction ["Slots", { ["DialogGambleSlots", []] call ULP_UI_fnc_createDialog; }, [], 1, true, true, "", "isNull (objectParent _this)", 3];

[_trader, "Casino"] call ULP_fnc_setTraderName;