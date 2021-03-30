/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyHouse";

if (canSuspend) exitWith {
    [ULP_fnc_buyHouse, _this] call ULP_fnc_directCall;
};

_this params [
	["_house", objNull, [objNull]]
];

private _objectCfg = [typeOf _house] call ULP_fnc_vehicleCfg;

if !([_house] call ULP_fnc_isHouse || 
	{ isClass (missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction >> "Housing") } || 
	{ [_house] call ULP_fnc_isHouseOwned } ||
	{ (count _objectCfg) > 0 }
) exitWith {
	hint "This house can't be bought...";
};

if !(["Home"] call ULP_fnc_hasLicense) exitWith {
	hint "You require home owner's approval to buy a house...";
};

if (_house getVariable ["blacklisted", false]) exitWith {
	hint "This house is blacklisted...";
};

private _limit = getNumber (missionConfigFile >> "CfgHousing" >> "houseLimit");
if ((count ([_house] call ULP_fnc_ownedHouses)) >= _limit) exitWith {
	hint format ["You have already reached the limit of %1 for owned houses...", _limit];
};

private _money = getNumber (missionConfigFile >> "CfgHousing" >> "houses" >> (typeOf _house) >> "price");

_objectCfg params [ "", "", "", "_name" ];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
	format ["You are sure you want to spend %1%2 on %3...", "£", [_money] call ULP_fnc_numberText, _name], [_house, _money],
	{	
		_this params [
			["_house", objNull, [objNull]],
			["_money", 0, [0]]
		];

		if (isNull _house) exitWith {};

		if (_house getVariable ["buying", false]) exitWith {
			hint "This house is already being bought...";
		};

		_house setVariable ["buying", true];
		closeDialog 0;

		["HouseBought", {
			_this params [
				["_house", objNull, [objNull]],
				["_success", false, [true]],
				["_message", "", [""]],
				["_money", 0, [0]]
			];

			if (_success) then {
				[[_house]] call ULP_fnc_setupHouses;
			} else {
				[_money, true, "House Purchase Failed"] call ULP_fnc_addMoney;
			};

			hint _message;

			_house setVariable ["buying", nil];
		}, true] call ULP_fnc_addEventHandler;

		if ([_money, true, "Bought House"] call ULP_fnc_removeMoney) then {
			hint "Buying House...";
			[player, _house, _money] remoteExecCall ["ULP_SRV_fnc_buyHouse", RSERV];
		} else {
			hint format ["You can't afford %1%2 to buy this house...", "£", [_money] call ULP_fnc_numberText];
		};
	}, false
] call ULP_fnc_confirm;