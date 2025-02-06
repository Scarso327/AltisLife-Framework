/*
** Author: Jack "Scarso" Farhall
** Description: Sets if gang wars only markers are visible
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_setBaseMarkers";

private _alpha = if (missionNamespace getVariable ["ULP_SRV_Setting_BaseBidsActive", false]) then {
	1
} else {
	0
};

{
	_x setMarkerAlpha _alpha;
} forEach (getArray (missionConfigFile >> "CfgBases" >> "GangWarsOnlyMarkers"));