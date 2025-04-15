/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_preInitPvpModes";

if !(hasInterface) exitWith {};

["Pre-Initialising PVP Modes"] call ULP_fnc_logIt;

["PvpVoteStarted", { _this call ULP_fnc_onPvpVoteStarted; }] call ULP_fnc_addEventHandler;
["PvpVoteFinished", { _this call ULP_fnc_onPvpVoteFinished; }] call ULP_fnc_addEventHandler;

["Incapacitated", {
	_this params [
		["_unit", objNull, [objNull]],
		["_killer", objNull, [objNull]]
	];

	if (isNull _unit 
		|| { _unit isEqualTo _killer } 
		|| { !(_killer isEqualTo player) } 
		|| { [group _killer, _unit] call ULP_fnc_inGroup }
		|| { !(["redzone_syndicate_"] call ULP_fnc_isUnitsInZone 
			|| { ["pvp_redzone_"] call ULP_fnc_isUnitsInZone }
			|| { ["redzone_"] call ULP_fnc_isUnitsInZone && { missionNamespace getVariable ["ULP_SRV_Setting_BaseBidsActive", false] } }) }) exitWith {};
			
	private _money = getNumber (missionConfigFile >> "CfgBases" >> "CfgPvpModes");
	private _xp = getNumber (missionConfigFile >> "CfgBases" >> "CfgPvpModes");

	if ([_money, true, "PVP Event Kill Reward"] call ULP_fnc_addMoney) then {
		[_xp, "PVP Event Kill"] call ULP_fnc_addXP;
		[format ["<t color='#B92DE0'>%1%2</t> has been deposited into your bank for killing someone during a pvp event...", "£", [_money] call ULP_fnc_numberText]] call ULP_fnc_hint;
	};
}] call ULP_fnc_addEventHandler;

{
	private _event = _x;

	{
		[format["%1%2", configName _x, configName _event], compile getText _x] call ULP_fnc_addEventHandler;
	} forEach (configProperties [_x >> "Events", "true", true]);
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgPvpModes" >> "Modes"));