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

if ([player] call ULP_fnc_onDuty) exitWith {
	["You can't buy a house while on duty..."] call ULP_fnc_hint;
};

private _objectCfg = [typeOf _house] call ULP_fnc_vehicleCfg;

if !([_house] call ULP_fnc_isHouse || 
	{ isClass (missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction >> "Housing") } || 
	{ [_house] call ULP_fnc_isHouseOwned } ||
	{ (count _objectCfg) > 0 }
) exitWith {
	["This house can't be bought!"] call ULP_fnc_hint;
};

if !(["Home"] call ULP_fnc_hasLicense) exitWith {
	["You require homeowner's approval to buy a house."] call ULP_fnc_hint;
};

if (_house getVariable ["blacklisted", false]) exitWith {
	["This house is <t color='#B92DE0'>blacklisted</t>."] call ULP_fnc_hint;
};

if !(call compile getText (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house) >> "condition")) exitWith {
	["You're unable to purchase this house at this time..."] call ULP_fnc_hint;
};

private _limit = getNumber (missionConfigFile >> "CfgHousing" >> "houseLimit");
if (["LandLord"] call ULP_fnc_hasPerk) then { _limit = _limit + 1 };
if ((count ([_house] call ULP_fnc_ownedHouses)) >= _limit) exitWith {
	[format ["You have already reached the limit of <t color='#B92DE0'>%1</t> for owned properties.", _limit]] call ULP_fnc_hint;
};

private _money = getNumber (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house) >> "price");

_objectCfg params [ "", "", "", "_name" ];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
	format ["You are sure you want to spend <t color='#B92DE0'>%1%2</t> on <t color='#B92DE0'>%3</t>...", "£", [_money] call ULP_fnc_numberText, _name], [_house, _money],
	{	
		_this params [
			["_house", objNull, [objNull]],
			["_money", 0, [0]]
		];

		if (isNull _house) exitWith {};

		if (_house getVariable ["buying", false]) exitWith {
			["This house is already being bought!"] call ULP_fnc_hint;
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
				["BuyHouse"] call ULP_fnc_achieve;
				
				private _cfg = missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house);
				if (isText (_cfg >> "onBought")) then {
					call compile getText (_cfg >> "onBought");
				};
			} else {
				[_money, true, "House Purchase Failed"] call ULP_fnc_addMoney;
			};

			[_message] call ULP_fnc_hint;

			_house setVariable ["buying", nil];
		}, true] call ULP_fnc_addEventHandler;

		if ([_money, true, "Bought House"] call ULP_fnc_removeMoney) then {
			["Buying House..."] call ULP_fnc_hint;
			[player, _house, _money] remoteExecCall ["ULP_SRV_fnc_buyHouse", RSERV];
		} else {
			[format ["You can't afford <t color='#B92DE0'>%1%2</t> to buy this property!", "£", [_money] call ULP_fnc_numberText]] call ULP_fnc_hint;
		};
	}, {}, false
] call ULP_fnc_confirm;