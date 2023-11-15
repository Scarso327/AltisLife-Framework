/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this, "DP1"] call ULP_fnc_addFreightMission;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addFreightMission";

_this params [
	["_trader", objNull, [objNull]],
	["_location", "", [""]],
	["_allowFinish", true, [false]]
];

if (isNull _trader || { _location isEqualTo "" }) exitWith {};

_trader addAction ["<t color='#073763'>[CIV]</t> Request Freight Mission", { [_this select 0, _this select 3] call ULP_fnc_claimFreight }, _location, 1.5, true, true, "", "true", 3];

if (_allowFinish) then {
	_trader addAction ["<t color='#073763'>[CIV]</t> Finish Freight Mission", { ["CorporateFreight"] call ULP_fnc_finishMission }, _location, 1.5, true, true, "", "true", 3];
};