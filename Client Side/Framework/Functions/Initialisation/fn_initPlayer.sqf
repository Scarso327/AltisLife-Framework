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

if (_setTags) then {
	[] call ULP_fnc_setTags;
};

player enableFatigue false;
player enableStamina false;

player setUnitTrait ["loadCoef", getNumber (missionConfigFile >> "CfgSettings" >> "Player" >> "loadCoef")];
player enableAimPrecision ([getNumber (missionConfigFile >> "CfgSettings" >> "Player" >> "aimPrecision")] call ULP_fnc_bool);

if (_addActions) then {
	{ player removeAction _x; } forEach ULP_PlayerActions;

	ULP_PlayerActions pushBackUnique (player addAction ["<img image='\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\heal_ca.paa'/> Treat Yourself", { (_this select 3) call ULP_fnc_healAction }, player, 5, true, true, "", "isNull (objectParent player) && { !([] call ULP_UI_fnc_isProgress) } && { [player] call ULP_fnc_canHeal }"]);
	ULP_PlayerActions pushBackUnique (player addAction ["<img image='\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\heal_ca.paa'/> Treat Person", { (_this select 3) call ULP_fnc_healAction }, cursorObject, 5, true, true, "", "isNull (objectParent cursorObject) && { !([] call ULP_UI_fnc_isProgress) } && { [cursorObject] call ULP_fnc_canHeal }"]);
};