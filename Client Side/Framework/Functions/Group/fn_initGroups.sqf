/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initGroups";

["Initialising Groups"] call ULP_fnc_logIt;

["GroupCreationSucceeded", {
	_this params [
		["_groupId", -1, [0]]
	];
	
	hint "Your group has been created...";
	ULP_Group_Creating = false;

	[] call ULP_fnc_setTags; // Update my tags...
	[format["Created Group (%1)", _groupId]] call ULP_fnc_logIt;
}] call ULP_fnc_addEventHandler;

["GroupCreationFailed", {
	_this params [
		["_reason", "Unknown", [""]]
	];

	hint _reason;
	ULP_Group_Creating = false;

	[format["Group Creation Failed (%1)", _reason]] call ULP_fnc_logIt;
}] call ULP_fnc_addEventHandler;

["GroupWithdraw", {
	_this params [
		["_message", "", [""]],
		["_amount", 0, [0]],
		["_total", 0, [0]]
	];

	if (_amount > 0) then {
		[_amount, false, format ["Group Funds"]] call ULP_fnc_addMoney;
	};

	hint _message;
}] call ULP_fnc_addEventHandler;