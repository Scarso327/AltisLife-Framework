/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addVehicleTuning";

_this params [
	["_trader", objNull, [objNull]]
];

if (isNull _trader) exitWith {};

_trader addAction ["<t color='#B92DE0'>[Civilian]</t> Vehicle Tuning", { ["DialogVehicleTuning", _this] call ULP_UI_fnc_createDialog }, [], 1, true, true, "", "isNull (objectParent _this) && { [_this, [""Civilian""]] call ULP_fnc_isFaction }", 3];