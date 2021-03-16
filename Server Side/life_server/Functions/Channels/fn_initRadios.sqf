/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initRadios";

["Creating Custom Channels..."] call ULP_fnc_logIt;

ULP_CustomChannels = createHashMap;
ULP_CustomChannels set ["Joint", radioChannelCreate [[1, 1, 0, 0.8], "Joint Faction Channel", "%UNIT_NAME", []]];