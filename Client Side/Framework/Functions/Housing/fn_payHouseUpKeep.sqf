/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_payHouseUpKeep";

_this params [
	["_building", objNull, [objNull]]
];

if (isNull _building || { !([_building] call ULP_fnc_isHouse) } || { !([_building, player, false] call ULP_fnc_isHouseOwner) }) exitWith { false };

private _daysLeft = _house getVariable ["building_days_left", 0];
private _maxDaysLeft = getNumber (missionConfigFile >> "CfgHousing" >> "maxUpKeepDays");

if (_daysLeft >= _maxDaysLeft) exitWith {
	["Your house already has the max number of up keep days paid for"] call ULP_fnc_hint;
	false
};

private _max = _maxDaysLeft - _daysLeft;

private _cfg = missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _building);
private _dayCost = round (getNumber (_cfg >> "price") * getNumber (_cfg >> "upKeepMultiplier"));

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _max], [_building, _daysLeft, _dayCost],
	{
		_this params [
			["_building", objNull, [objNull]],
			["_daysLeft", 0, [0]],
			["_dayCost", 0, [0]],
			["_display", displayNull, [displayNull]],
			["_daysPaidFor", 1, [0]]
		];

		private _cost = _dayCost * _daysPaidFor;

		if ([_cost, true, format ["%1 Days of Upkeep", _daysPaidFor]] call ULP_fnc_removeMoney) then {
			[_building, _daysLeft + _daysPaidFor] remoteExecCall ["ULP_SRV_fnc_saveHouseUpKeep", RSERV];
			[format ["You have paid for <t color='#B92DE0'>%3</t> days of up keep costing <t color='#B92DE0'>%1%2</t>", "£", [_cost] call ULP_fnc_numberText, _daysPaidFor]] call ULP_fnc_hint;
		} else {
			[format ["You can't afford <t color='#B92DE0'>%1%2</t> to pay for <t color='#B92DE0'>%3</t> days of up keep", "£", [_cost] call ULP_fnc_numberText, _daysPaidFor]] call ULP_fnc_hint;
		};
	}, false, "_this params [""_display"", ""_val""]; private _cost = ((_display getVariable [""params"", []]) select 2) * _val; format [""%1%2"", ""£"", [_cost] call ULP_fnc_numberText]", false
] call ULP_fnc_selectNumber;