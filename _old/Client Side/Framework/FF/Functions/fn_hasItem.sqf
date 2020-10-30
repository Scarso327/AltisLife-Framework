/*
	@File: fn_hasItem.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Checks if this target has certain items or not...
*/
#include "..\..\script_macros.hpp"
params[
	["_target", player, [objNull]],
	["_check", "gps", [""]]
];

if (isNull _target) exitWith {false};

private _items = assignedItems _target + items _target;

switch (_check) do {
	case "gps": {
		["ItemGPS", "B_UavTerminal", "O_UavTerminal", "I_UavTerminal"] findIf {_x in _items} > -1
	};

	case "comms": {
		"ItemRadio" in _items
	};
};