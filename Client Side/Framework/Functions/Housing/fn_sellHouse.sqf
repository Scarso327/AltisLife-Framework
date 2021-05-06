/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_sellHouse";

_this params [
	["_building", objNull, [objNull]]
];

if ([player] call ULP_fnc_onDuty) exitWith {
	["You can't sell a house while on duty..."] call ULP_fnc_hint;
};

private _cfg = [typeOf _building] call ULP_fnc_vehicleCfg;

if !(_cfg isEqualTo []) then {
	_cfg params [ "", "", "", "_name" ];

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
		format ["Are you sure you want to sell %1, all stored items will be lost...", _name], [_building],
		{	
			private _house = _this param [0, objNull];
			if (isNull _house) exitWith {};

			if (_house getVariable ["selling", false]) exitWith {
				["This house is already being sold!"] call ULP_fnc_hint;
			};

			_house setVariable ["selling", true];
			closeDialog 0;

			["HouseSold", {
				_this params [
					["_house", objNull, [objNull]],
					["_success", false, [true]],
					["_message", "", [""]],
					["_money", 0, [0]]
				];

				if (_success) then { [_money, true, "House Sold"] call ULP_fnc_addMoney; };
				[_message] call ULP_fnc_hint;

				_house setVariable ["selling", nil];
			}, true] call ULP_fnc_addEventHandler;

			["Selling House..."] call ULP_fnc_hint;
			[getPlayerUID player, _house] remoteExecCall ["ULP_SRV_fnc_sellHouse", RSERV];
		}, false
	] call ULP_fnc_confirm;
};