/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initPlayer";

_this params [
	["_setTags", true, [false]],
	["_addActions", false, [true]]
];

[] call ULP_fnc_setTags;

player enableFatigue false;
player enableStamina false;

player setUnitTrait ["loadCoef", getNumber (missionConfigFile >> "CfgSettings" >> "Player" >> "loadCoef")];
player enableAimPrecision ([getNumber (missionConfigFile >> "CfgSettings" >> "Player" >> "aimPrecision")] call ULP_fnc_bool);

if (_addActions) then {
	{ player removeAction _x; } forEach ULP_PlayerActions;

	ULP_PlayerActions pushBackUnique (player addAction ["<img image='\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\heal_ca.paa'/> Treat Yourself", { player call ULP_fnc_healAction }, nil, 5, true, true, "", "isNull (objectParent player) && { !([] call ULP_UI_fnc_isProgress) } && { [player] call ULP_fnc_canHeal }"]);
	ULP_PlayerActions pushBackUnique (player addAction ["<img image='\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\heal_ca.paa'/> Treat Person", { cursorObject call ULP_fnc_healAction }, nil, 5, true, true, "", "isNull (objectParent cursorObject) && { !([] call ULP_UI_fnc_isProgress) } && { [cursorObject] call ULP_fnc_canHeal }"]);

	if ([player, ["Police", "Hato"]] call ULP_fnc_isFaction) then {
		ULP_PlayerActions pushBackUnique (player addAction ["Packup Stinger", {
			private _spike = (nearestObjects [player, ["Land_Razorwire_F"], 5] select { !((_x getVariable ["spike_owner", []]) isEqualTo []) }) param [0, objNull];
			if (isNull _spike) exitWith {};
			
			if (["Stinger", 1, false, true] call ULP_fnc_handleItem) then {
				["You have packed up a stinger..."] call ULP_fnc_hint;
				deleteVehicle _spike;
			};
		}, nil, 10, false, false, "", "isNull (objectParent player) && { !([] call ULP_UI_fnc_isProgress) } && { private _spike = (nearestObjects [player, [""Land_Razorwire_F""], 5] select { !((_x getVariable [""spike_owner"", []]) isEqualTo []) }) param [0, objNull]; (!(isNull _spike) && { (damage _spike) isEqualTo 1 })}"]);
	};
};