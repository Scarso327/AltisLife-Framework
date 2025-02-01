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

_trader addAction ["<t color='#B92DE0'>[Civilian]</t> Request Cargo Mission", { (_this select 3) call ULP_fnc_claimCargoRun }, [_trader, _missionType, _location], 1.5, true, true, "", format ["!(""%1"" in ULP_Missions)", _missionType], 3];

if (_allowFinish) then {
	_trader addAction ["<t color='#B92DE0'>[Civilian]</t> Finish Cargo Mission", { (_this select 3) call ULP_fnc_finishMission }, [_missionType], 1.5, true, true, "", format ["(""%1"" in ULP_Missions)", _missionType], 3];
};