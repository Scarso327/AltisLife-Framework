/*
** Author: Jack "Scarso" Farhall
** Description: Asks the server to provide us with our information...
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_insertPlayerInfo";

_this params [
	["_unit", objNull, [objNull]],
	["_afterInsert", {}, [{}]]
];

if (_unit isEqualTo objNull) exitWith {};

if !(_unit getVariable ["isFirstInsert", false]) then {
	private _name = name _unit;
	private _uid = getPlayerUID _unit;

	[
		format ["INSERT INTO `players` (`pid`, `name`, `cash`, `bankacc`, `aliases`, `cop_licenses`, `med_licenses`, `civ_licenses`, `civ_gear`, `cop_gear`, `med_gear`, `professions`, `hato_licenses`, `hato_gear`, `achievements`, `textures`, `titles`, `cop_perks`, `med_perks`, `hato_perks`, `civ_perks`, `blueprints`, `cop_daily_tasks`, `med_daily_tasks`, `hato_daily_tasks`, `civ_daily_tasks`, `cop_weekly_tasks`, `med_weekly_tasks`, `hato_weekly_tasks`, `civ_weekly_tasks`) VALUES ('%1', '%2', '0', '%3', '%4','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""')",
			_uid,
			[_name] call DB_fnc_mresString,
			[LIFE_SETTINGS(getNumber,"starting_bank"), ""] call ULP_fnc_numberText,
			[[_name]] call DB_fnc_mresArray
		], 1
	] call DB_fnc_asyncCall;

	_unit setVariable ["isFirstInsert", true];
};

[3, [_unit], _afterInsert] call ULP_fnc_waitExecute;