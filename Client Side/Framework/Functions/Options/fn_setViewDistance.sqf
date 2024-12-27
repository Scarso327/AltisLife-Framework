/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_setViewDistance";

private _vehicle = vehicle player;

private _viewDistance = switch (true) do {
	case (_vehicle isKindOf "CAManBase"): { "FootViewDistance" };
	case (_vehicle isKindOf "Air"): { "AirViewDistance" };
	default { "LandViewDistance" };
};

private _minMaxValues = (getArray (missionConfigFile >> "CfgOptions" >> "ViewDistance" >> _viewDistance >> "values")) param [0, [], [[]]];
_minMaxValues params [ "_min", "_max" ];

_viewDistance = [_viewDistance, "ViewDistance"] call ULP_fnc_getOption;

setViewDistance ((_viewDistance min _max) max _min);