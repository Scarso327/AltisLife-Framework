/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_forgeIdentity";

if !([player, ["Civilian"]] call ULP_fnc_isFaction) exitWith {
	hint "Only civilians can forge identity cards...";
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
			hint "This name is too long...";
		};

		private _cost = getNumber (missionConfigFile >> "CfgVirtualItems" >> "Identification" >> "buyPrice");
		
		if (CASH < _cost) exitWith {
			hint format ["You need %1%2 to forge an identity card...", "£", [_cost] call ULP_fnc_numberText];
		};

		if ([_cost, true, "Forged ID"] call ULP_fnc_removeMoney) then {
			if (["Identification", _name] call ULP_fnc_handleItem) then {
				hint format ["You've forge an identity card with the name %1", _name];
			} else {
				hint format ["You failed to forge an identity card with the name %1", _name];
			};
		} else {
			hint format ["You can't afford %1%2 to forge an identity card...", "£", [_cost] call ULP_fnc_numberText];
		};
	}, false
] call ULP_fnc_enterString;