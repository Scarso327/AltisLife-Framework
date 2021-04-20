/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initGathering";

{
	{
		deleteMarkerLocal (_x select 0);
	} forEach getArray (_x >> "areas");
} forEach ("[player, getArray (_x >> ""hidden"")] call ULP_fnc_isFaction || { ""Police"" in getArray (_x >> ""hidden"") && ([] call ULP_fnc_isUndercover) }" configClasses (missionConfigFile >> "CfgGathering"));