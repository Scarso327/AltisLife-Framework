/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasLicense";

if !(_this params [
	["_license", "", ["", configNull]]
]) exitWith {};

if (_license isEqualType configNull) then { _license = (configName _license); };

_license in ULP_Licenses