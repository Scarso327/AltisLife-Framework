/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_togglePerk";

_this params [
	["_perk", "", [""]]
];

private _cfg = missionConfigFile >> "CfgPerks" >> _perk;

if ([_perk] call ULP_fnc_hasPerk) then {
	private _name = getText (_cfg >> "displayName");
	private _cost = getNumber (missionConfigFile >> "CfgPerks" >> "removalCost");
	_cost = _cost * getNumber (_cfg >> "removalMultiplier");
	
	if (BANK < _cost) exitWith {
		hint format ["You need %1%2 to deactivate a perk...", "£", [_cost] call ULP_fnc_numberText];
		false breakOut "fn_togglePerk";
	};

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
		format ["You are sure you want to spend %1%2 on removing %3...", "£", [_cost] call ULP_fnc_numberText, _name], [_perk, _name, _cost],
		{	
			_this params [ "_perk", "_name", "_cost" ];

			if ([_cost, true, format ["Deativating %1", _name]] call ULP_fnc_removeMoney) then {
				ULP_Perks deleteAt _perk;
				hint format ["%1 has been deactiviated for a cost of %2%3", _name, "£", [_cost] call ULP_fnc_numberText];
				["PerksChanged", [_perk, ULP_Perks]] call ULP_fnc_invokeEvent;
			};
		}, true
	] call ULP_fnc_confirm;
} else {
	if !(isClass _cfg) exitWith {
		hint "This perk no longer exists and so have been automatically removed";
		false breakOut "fn_togglePerk";
	};

	private _limit = [] call ULP_fnc_getPerkLimit;
	if ((count ULP_Perks) >= _limit) exitWith {
		hint format ["You can't have more than %1 perks activated at once...", _limit];
		false breakOut "fn_togglePerk";
	};

	ULP_Perks set [_perk, [1, 0]];
	hint format ["%1 has been succesfully activated...", getText (_cfg >> "displayName")];
	["PerksChanged", [_perk, ULP_Perks]] call ULP_fnc_invokeEvent;
};

true