/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogMedicMap_OnUnload";

_this params [ "_display" ];

if (isNull _display) exitWith {};

uiNamespace setVariable ["DialogMedicMap", nil];

["Incapacitated", _display getVariable ["Incapacitated", -1]] call ULP_fnc_removeEventHandler;
["Died", _display getVariable ["Died", -1]] call ULP_fnc_removeEventHandler;
["AssignedMedicChanged", _display getVariable ["AssignedMedicChanged", -1]] call ULP_fnc_removeEventHandler;