/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogVehicleTuning_OnUnload";

_this params [ "_display" ];

if (isNull _display) exitWith {};

disableSerialization;
uiNamespace setVariable ["DialogVehicleTuning", nil];