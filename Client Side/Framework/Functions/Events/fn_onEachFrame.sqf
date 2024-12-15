/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_onEachFrame";

{
	if (_x isEqualType 0) then {
		_y params ["_params", "_function"];
		private _thisEventHandler = _x;

		_params call _function;
	};
} forEach + ULP_eachFrameEvents;

// Credit: Ace Mod Team (https://ace3mod.com/wiki/development/arma-3-scheduler-and-our-practices.html)

for "_i" from 0 to 1 step 0 do {
	if (ULP_waitExecute isEqualTo [] || {
		(ULP_waitExecute select 0 select 0) >= diag_tickTime
	}) exitWith {};

	private _exec = (ULP_waitExecute deleteAt 0);
	(_exec select 1) call (_exec select 2);
};

{
	ULP_waitUntilExecute deleteAt (ULP_waitUntilExecute find _x);
	(_x select 1) call (_x select 2);

    nil
} count + (ULP_waitUntilExecute select {
	(_x select 1) call (_x select 0)
});

if !(hasInterface) exitWith {};

private _isSpeaking = !isNull findDisplay 55;
if !(player getVariable["speaking", false] isEqualTo _isSpeaking) then {
    player setVariable["speaking", _isSpeaking, true];

    if (_isSpeaking && { inputAction "PushToTalk" > 0 } && { !isNull (objectParent player) } && { currentChannel isEqualTo 5 }) then {
		setCurrentChannel 4;
    };
};

private _gpsVisible = visibleGPS;
if !(_gpsVisible isEqualTo (missionNamespace getVariable ["GPSVisible", false])) then {
	missionNamespace setVariable ["GPSVisible", _gpsVisible];
	["GPS", [_gpsVisible]] call ULP_fnc_invokeEvent;
};

if ((missionNamespace getVariable ["InRedzoneCheckTime", -1]) <= time) then {
	private _isInRedzone = ["redzone_"] call ULP_fnc_isUnitsInZone;
	if !(_isInRedzone isEqualTo (missionNamespace getVariable ["InRedzone", false])) then {
		missionNamespace setVariable ["InRedzone", _isInRedzone];
		missionNamespace setVariable ["InRedzoneCheckTime", time + 3];

		[["LeftRedzone", "EnteredRedzone"] select _isInRedzone, []] call ULP_fnc_invokeEvent;
	};
};