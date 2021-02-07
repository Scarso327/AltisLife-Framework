/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasLicense";

if !(_this params [
	["_license", "", [""]]
]) exitWith {};

_license in ULP_Liceneses