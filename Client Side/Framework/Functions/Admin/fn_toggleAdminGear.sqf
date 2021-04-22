/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_toggleAdminGear";

_this params [
	["_force", false, [true]]
];

if (isDowned(player) || { !([] call ULP_fnc_isSaff) } || { !(["Suit"] call ULP_fnc_checkPower) }) exitWith { false };

// Stop spam...
if (!(_force) && { time < (player getVariable ["admin_cooldown", 0]) }) exitWith {
	["You've changed into admin gear recently, please wait before trying again."] call ULP_fnc_hint;
	false
};
player setVariable ["admin_cooldown", time + 3];

if ([player] call ULP_fnc_onDuty) then {
	CASH = ULP_NormalCash;
	BANK = ULP_NormalBank;

	ULP_Inventory = createHashMap; // Wipe Inventory...
	ULP_CarryInfo set [0, 0];

	[] call ULP_fnc_loadGear;

	if (isObjectHidden player) then {
		[player, false] remoteExecCall ["ULP_SRV_fnc_hidePlayer", RSERV];
	};
} else {
	[] call ULP_fnc_saveGear;
	[] call ULP_fnc_stripGear;

	ULP_NormalCash = CASH;
	ULP_NormalBank = BANK;

	ULP_Inventory = createHashMap; // Wipe Inventory...
	ULP_CarryInfo set [0, 0];

	player forceAddUniform ([
		"U_C_Protagonist_VR", "U_B_Protagonist_VR", "U_O_Protagonist_VR", "U_I_Protagonist_VR"
	] select (random 3));
	player addGoggles "G_Goggles_VR";

	player linkItem "ItemMap";
	player linkItem "ItemCompass";
	player linkItem "ItemWatch";
};

player setVariable ["onduty", !([player] call ULP_fnc_onDuty), true];

[] call ULP_fnc_setTags;
["MoneyChanged", [CASH, BANK]] call ULP_fnc_invokeEvent;

if !(_force) then {
	[getPlayerUID player, "Admin", ["AdminSuit", serverTime, [(["Left", "Entered"] select ([player] call ULP_fnc_onDuty))]]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
};
true