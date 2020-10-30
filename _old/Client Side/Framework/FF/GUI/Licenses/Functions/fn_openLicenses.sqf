/*
	@File: fn_openLicenses.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Opens the "Buy License" Menu...
*/
#include "..\..\..\..\script_macros.hpp"
disableSerialization;
private _licenses = _this select 3;

private _side = switch (playerSide) do {case west:{"cop"}; case civilian:{"civ"}; case independent:{"med"};};

if (life_is_processing || life_action_inUse) exitWith {}; // Already Processing or doing something...
if !(createDialog "RscLicensesShop") exitWith { systemChat "Failed to create dialog..." };

private _list = CONTROL(4000, 4001);
lbClear _list;

{
	if !(LICENSE_VALUE(_x, _side)) then { 
		_list lbAdd M_CONFIG(getText, "CfgLicenses", _x, "displayName");
		_list lbSetData [(lbSize _list)-1, _x];
		_list lbSetValue [(lbSize _list)-1, M_CONFIG(getNumber, "CfgLicenses", _x, "price")];
	};
} forEach _licenses;

ctrlEnable[4003, false]; // Disable "Buy Button"