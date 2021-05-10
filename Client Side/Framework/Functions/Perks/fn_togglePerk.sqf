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
		[format ["You need %1%2 to deactivate a perk!", "£", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
		false breakOut "fn_togglePerk";
	};

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
		format ["You are sure you want to spend %1%2 on removing %3...", "£", [_cost] call ULP_fnc_numberText, _name], [_perk, _name, _cost],
		{	
			_this params [ "_perk", "_name", "_cost" ];

			if ([_cost, true, format ["Deativating %1", _name]] call ULP_fnc_removeMoney) then {
				ULP_Perks deleteAt _perk;
				[format ["<t color='#B92DE0'>%1</t> has been deactiviated for a cost of <t color='#B92DE0'>%2%3</t>.", _name, "£", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
				["PerksChanged", [_perk, ULP_Perks]] call ULP_fnc_invokeEvent;
			};
		}, {}, true
	] call ULP_fnc_confirm;
} else {
	if !(isClass _cfg) exitWith {
		["This perk no longer exists and has been automatically removed"] call ULP_fnc_hint;
		false breakOut "fn_togglePerk";
	};

	private _limit = [] call ULP_fnc_getPerkLimit;
	if ((count ULP_Perks) >= _limit) exitWith {
		[format ["You can't have more than <t color='#B92DE0'>%1</t> perks activated at once!", _limit]] call ULP_fnc_hint;
		false breakOut "fn_togglePerk";
	};

	ULP_Perks set [_perk, [1, 0]];
	[format ["<t color='#B92DE0'>%1</t> has been succesfully activated!", getText (_cfg >> "displayName")]] call ULP_fnc_hint;
	["PerksChanged", [_perk, ULP_Perks]] call ULP_fnc_invokeEvent;
};

true