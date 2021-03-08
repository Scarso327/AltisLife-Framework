/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_initEventHandlers";

player addEventHandler ["Fired", { _this call ULP_fnc_onFired }];
player addEventHandler ["Reloaded", { _this call ULP_fnc_onReloaded }];
player addEventHandler ["GetInMan", { _this call ULP_fnc_onGetIn }];
player addEventHandler ["GetOutMan", { _this call ULP_fnc_onGetOut }];

// Group Events...
["GroupCreationSucceeded", {
	_this params [
		["_groupId", -1, [0]]
	];
	
	hint "Your group has been created...";
	ULP_Group_Creating = false;

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