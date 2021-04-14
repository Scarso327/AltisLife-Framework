/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_forgeIdentity";

if !([player, ["Civilian"]] call ULP_fnc_isFaction || { ["IDForger"] call ULP_fnc_hasPerk }) exitWith {
	["Only civilians can forge identity cards..."] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Enter Identity Name", ["Forge", "Cancel"],
	format ["Type name here...", _name], [],
	{	
		_this params [
			["_name", "", [""]]
		];
		
		_name = [_name] call ULP_fnc_stripString;

		if ((count _name) > getNumber (missionConfigFile >> "CfgSettings" >> "Identity" >> "nameLength")) exitWith {
			["Only civilians can forge identity cards..."] call ULP_fnc_hint;
		};

		private _cost = getNumber (missionConfigFile >> "CfgVirtualItems" >> "Identification" >> "buyPrice");
		
		if (CASH < _cost) exitWith {
			[format ["You need %1%2 to forge an identity card...", "£", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
		};

		if ([_cost, true, "Forged ID"] call ULP_fnc_removeMoney) then {
			if (["Identification", _name] call ULP_fnc_handleItem) then {
				[format ["You've forge an identity card with the name %1", _name]] call ULP_fnc_hint;
			} else {
				[format ["You failed to forge an identity card with the name %1", _name]] call ULP_fnc_hint;
			};
		} else {
			[format ["You can't afford %1%2 to forge an identity card.", "£", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
		};
	}, false
] call ULP_fnc_enterString;