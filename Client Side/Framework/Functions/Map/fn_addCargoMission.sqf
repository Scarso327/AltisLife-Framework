/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this, "DP1"] call ULP_fnc_addCargoMission;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addCargoMission";

_this params [
	["_trader", objNull, [objNull]],
	["_missionType", "", [""]],
	["_location", "", [""]],
	["_allowFinish", true, [false]]
];

if (isNull _trader || { _location isEqualTo "" }) exitWith {};

_trader addAction ["<t color='#073763'>[CIV]</t> Request Freight Mission", { (_this select 3) call ULP_fnc_claimCargoRun }, [_trader, _missionType, _location], 1.5, true, true, "", format ["!(""%1"" in ULP_Missions)", _missionType], 3];

if (_allowFinish) then {
	_trader addAction ["<t color='#073763'>[CIV]</t> Finish Freight Mission", { (_this select 3) call ULP_fnc_finishMission }, [_missionType], 1.5, true, true, "", format ["(""%1"" in ULP_Missions)", _missionType], 3];
};