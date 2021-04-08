/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_toggleAdminGear";

_this params [
	["_force", false, [true]]
];

if (isDowned(player) || { !([] call ULP_fnc_isSaff) }) exitWith { false };

// Stop spam...
if (!(_force) && { time < (player getVariable ["admin_cooldown", 0]) }) exitWith {
	hint "You've changed into admin gear recently, please wait before trying again...";
	false
};
player setVariable ["admin_cooldown", time + 3];

if ([player] call ULP_fnc_onDuty) then {
	CASH = ULP_NormalCash;
	BANK = ULP_NormalBank;

	ULP_Inventory = createHashMap; // Wipe Inventory...
	ULP_CarryInfo set [0, 0];

	[] call ULP_fnc_loadGear;

} else {
	[] call ULP_fnc_saveGear;
	[] call ULP_fnc_stripGear;

	ULP_NormalCash = CASH;
	ULP_NormalBank = BANK;

	ULP_Inventory = createHashMap; // Wipe Inventory...
	ULP_CarryInfo set [0, 0];

	player forceAddUniform ([
		"U_I_Protagonist_VR", "U_B_Protagonist_VR", "U_O_Protagonist_VR"
	] select (random 2));
	player addHeadgear "H_Cap_headphones";
	player addGoggles "G_Goggles_VR";

	player linkItem "ItemMap";
	player linkItem "ItemGPS";
	player linkItem "ItemCompass";
	player linkItem "ItemWatch";
	player linkItem "ItemRadio";
};

player setVariable ["onduty", !([player] call ULP_fnc_onDuty), true];

[] call ULP_fnc_setTags;
true