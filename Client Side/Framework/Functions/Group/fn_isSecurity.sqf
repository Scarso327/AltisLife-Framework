/*
** Author: Lewis Mackinnon
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isSecurity";

[] call ULP_fnc_isGroup && { ["SecurityContactors"] call ULP_fnc_hasGroupPerk } && { ["Security"] call ULP_fnc_hasLicense }