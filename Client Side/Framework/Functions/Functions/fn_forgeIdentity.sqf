/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_forgeIdentity";

if !([player, ["Civilian"]] call ULP_fnc_isFaction || { ["IDForger"] call ULP_fnc_hasPerk }) exitWith {
	["Only civilians can forge identity cards!"] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Enter Identity Name", ["Create", "Cancel"], "Type name here...", [],
	{	
		_this params [
			["_name", "", [""]]
		];
		
		_name = [_name] call ULP_fnc_stripString;

		if ((count _name) > getNumber (missionConfigFile >> "CfgSettings" >> "Identity" >> "nameLength")) exitWith {
			["Only civilians can forge identity cards!"] call ULP_fnc_hint;
		};

		private _cost = getNumber (missionConfigFile >> "CfgVirtualItems" >> "Identification" >> "buyPrice");
		if ([] call ULP_fnc_isUndercover) then { _cost = 0 };

		if (CASH < _cost) exitWith {
			[format ["You need <t color='#B92DE0'>%1%2</t> to forge an identity card!", "£", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
		};

		if ([_cost, true, "Forged ID"] call ULP_fnc_removeMoney) then {
			if (["Identification", _name] call ULP_fnc_handleItem) then {
				[format ["You've recieved an identity card with the name <t color='#B92DE0'>%1</t>.", _name]] call ULP_fnc_hint;
				["Forger"] call ULP_fnc_achieve;
			} else {
				[format ["You failed to recieve an identity card with the name <t color='#B92DE0'>%1</t>.", _name]] call ULP_fnc_hint;
			};
		} else {
			[format ["You can't afford <t color='#B92DE0'>%1%2</t> to forge an identity card.", "£", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
		};
	}, false
] call ULP_fnc_enterString;