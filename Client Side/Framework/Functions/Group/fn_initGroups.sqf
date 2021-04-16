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
	
	["Your group has been created."] call ULP_fnc_hint;
	ULP_Group_Creating = false;

	[] call ULP_fnc_setTags; // Update my tags...
	[format["Created Group (%1)", _groupId]] call ULP_fnc_logIt;
}] call ULP_fnc_addEventHandler;

["GroupCreationFailed", {
	_this params [
		["_reason", "Unknown", [""]]
	];

	[_reason] call ULP_fnc_hint;
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

	[_message] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["GroupRankChanged", {
	_this params [
		["_rank", 0, [0]],
		["_actioner", objNull, [objNull]]
	];

	_rank = [_rank] call ULP_fnc_rankName;
	[format ["Your rank has been set to %1", ([format["%1 by %2!", _rank, name _actioner], _rank] select (isNull _actioner))]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["GroupKicked", {
	[format ["%1 has kicked you from the group!", name (_this param [0, objNull])]] call ULP_fnc_hint;
	[ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;

["GroupDisbanded", {
	[format ["%1 has disbanded the group!", name (_this param [0, objNull])]] call ULP_fnc_hint;
	[ { !([] call ULP_fnc_isGroup) }, [], { [] call ULP_fnc_setTags; }] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_addEventHandler;