/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this, "<t color='#073763'>[CIV]</t>", "Delivery Mission", "Delivery", "DP1"] call ULP_fnc_addMission;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addMission";

_this params [
	["_trader", objNull, [objNull]],
	["_prefix", "", [""]],
	["_title", "", [""]],
	["_type", "", [""]],
	["_location", "", [""]],
	["_allowFinish", true, [false]]
];

if (isNull _trader || { _title isEqualTo "" } || { _type isEqualTo "" } || { _location isEqualTo "" }) exitWith {};

_trader addAction [format["%1 Request %2", _prefix, _title], { (_this select 3) call ULP_fnc_claimMission }, [_type, _location], 1.5, true, true, "", "true", 3];

if (_allowFinish) then {
	_trader addAction [format["%1 Finish %2", _prefix, _title], { (_this select 3) call ULP_fnc_finishMission }, [_type], 1.5, true, true, "", "true", 3];
};

[_trader, _title] call ULP_fnc_setTraderName;