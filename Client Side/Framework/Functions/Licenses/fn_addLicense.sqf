/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addLicense";

_this params [
	["_license", "", [""]],
	["_price", -1, [0]],
	["_save", true, [false]]
];

_license = missionConfigFile >> "CfgLicenses" >> _license;
if (!isClass _license || 
	{ [_license] call ULP_fnc_hasLicense } || 
	{ !([player] call ULP_fnc_getFaction in getArray (_license >> "factions")) } || 
	{ !([] call compile getText(_license >> "conditions")) }
) exitWith { false };

if !(_price isEqualTo -1) then {
	if (CASH < _price) exitWith {
		hint format["You can't afford this license. You need £%1", _price];
		false breakOut "fn_addLicense";
	};

	CASH = CASH - _price;
	[player, 1, CASH] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
};

ULP_Licenses pushBackUnique (configName _license);

if (_save) then {
	[player, 0, ULP_Licenses] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
};

true