/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_initEventHandlers";

player addEventHandler ["Fired", { _this call ULP_fnc_onFired }];
player addEventHandler ["Reloaded", { _this call ULP_fnc_onReloaded }];
player addEventHandler ["GetInMan", { _this call ULP_fnc_onGetIn }];
player addEventHandler ["GetOutMan", { _this call ULP_fnc_onGetOut }];

// Settings Events...
["OptionChanged", {
	_this params [
		"_option", "_category", "_newSetting", "_lastSetting"
	];

	switch (format["%1_%2", _category, _option]) do {
		case "HUD_EnablePlayerTags": { [(_newSetting isEqualTo 1)] call ULP_fnc_playerTags };
		case "Audio_EffectsFade": { if (ULP_FadeSound) then { 0 fadeSound _newSetting; }; };
		case "Audio_MusicFade": { if (ULP_FadeSound) then { 0 fadeMusic _newSetting; }; };
	};

	// [format["Setting Changed (%1, %2, %3 -> %4)", _option, _category, _lastSetting, _newSetting]] call ULP_fnc_logIt;
}] call ULP_fnc_addEventHandler;

// Group Events...
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