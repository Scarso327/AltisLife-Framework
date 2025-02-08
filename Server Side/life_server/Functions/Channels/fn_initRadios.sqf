/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initRadios";

["Creating Custom Channels..."] call ULP_fnc_logIt;

ULP_CustomChannels = createHashMap;
ULP_CustomChannels set ["Joint", radioChannelCreate [[1, 1, 0, 0.8], "Joint Faction Channel", "%UNIT_GRP_NAME (%UNIT_NAME)", []]];

{
	if ([getNumber (_x >> "sideChannel")] call ULP_fnc_bool) then {
		ULP_CustomChannels set [format ["%1Side", configName _x], radioChannelCreate [[0, 0.95, 1, 0.8], "Side Channel", "%UNIT_GRP_NAME (%UNIT_NAME)", []]];
	};
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgFactions"));

DIAG_LOG ULP_CustomChannels;