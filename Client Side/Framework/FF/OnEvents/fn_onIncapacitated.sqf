/*
	@File: fn_onIncapacitated.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Does everything that needs to be done when a player is shot...

	@Parameters:
		0 - TYPE: OBJECT - DES: The object being incapacitated...
		1 - TYPE: OBJECT - DES: The object that incapacitated the object...
		2 - TYPE: STRING - DES: The stage we're at...
*/
#include "..\..\script_macros.hpp"
params [
	["_unit", objNull, [objNull]],
	["_killer", objNull, [objNull]],
	["_type", "event", [""]]
];

if !(canSuspend) exitWith { _this spawn FF(onIncapacitated) };

if (isNull _unit) exitWith {}; // What??
if !(isPlayer _unit) exitWith {}; // Only players can be incapacitated...

switch (_type) do {
	case "event": {
		if (isDowned(_unit)) exitWith {}; // No Double Downing...
		if !(isNull objectParent _unit) then { moveOut _unit }; // Get them out the vehicle...

		_unit switchmove "";
		_unit setUnconscious true;

		setKiller(_unit, _killer); // Set the source as our killer...
		setDowned(_unit); // Set the unit as incapacitated...

		// Notify the server...
		if (!isNull _killer && { isPlayer _killer } && { !(_killer isEqualTo _unit) }) then {
			[0, format ["%1 was seriously injured by %2", 
				_unit getVariable ["realname", name _unit], 
				_killer getVariable ["realname", name _killer]
			]] remoteExecCall ["life_fnc_broadcast", RCLIENT];
		} else {
			[0, format ["%1 was seriously injured", 
				_unit getVariable ["realname", name _unit]
			]] remoteExecCall ["life_fnc_broadcast", RCLIENT];
		};

		[_unit, _killer, "client"] RemoteExec ["FF_fnc_onIncapacitated", _unit]; // Time for the client to do something...
	};

	case "client": {
		if !(_unit isEqualTo player) exitWith {}; // If we're not the downed unit, why run this code?

		if !(isNull objectParent _unit) then { moveOut _unit }; // Get them out the vehicle...
		while {dialog} do { closeDialog 0 }; // Close all dialogs...

		// Create / Setup Incapacitated UI...
		("FF_Incapacitated" call BIS_fnc_RscLayer) cutRsc ["RscIncapacitated", "PLAIN", 0];

		private _display = uiNameSpace getVariable ["FF_Incapacitated", displayNull];

		(_display displayCtrl 9001) ctrlSetStructuredText parseText ([
			format["<t align='center' size='2'>You killed yourself</t>"],
			format["<t align='center' size='2'>%1 seriously injured you</t>", _killer getVariable ["realname", name _killer]]
		] select (!isNull _killer && { isPlayer _killer } && { !(_killer isEqualTo _unit) }));

		// Blurry effect...
		_effectBlur = ppEffectCreate ["DynamicBlur", 300];
		_effectBlur ppEffectEnable true;
		_effectBlur ppEffectAdjust [2.5];
		_effectBlur ppEffectCommit 3;

		_effectColour = ppEffectCreate ["colorCorrections", 301];
		_effectColour ppEffectEnable true;
		_effectColour ppEffectAdjust [1, 1, 0, [0, 0, 0, 0.7], [1, 0, 0, 0.5],[1, 1, 1, 0]]; 
		_effectColour ppEffectCommit 3;
		FF_effects pushBack [_effectColour,_effectBlur];

		// Handle Items & Needs...
		[_unit] call life_fnc_dropItems;
		life_hunger = 100;
		life_thirst = 100;
		life_carryWeight = 0;
		CASH = 0;

		// Double ensure these are done...
		_unit switchmove "";
		_unit setUnconscious true;
	
		// Wanted Handling...
		if (!isNull _killer && {!(_killer isEqualTo _unit)}) then {
			life_removeWanted = true;
		};

		if (side _killer isEqualTo west && !(playerSide isEqualTo west)) then {
			life_copRecieve = _killer;
		};

		if !(isNil "FF_fnc_bleedout_timer") then {terminate FF_fnc_bleedout_timer}; // If a loop is already running, kill it.

		FF_fnc_bleedout_timer = [_unit] spawn {
			private _unit = _this select 0;
			private _startTime = time;
			private _endTime = _startTime + (LIFE_SETTINGS(getNumber,"bleedout_timer")); // Current Time + Bleedout Time
			private _display = uiNameSpace getVariable ["FF_Incapacitated", displayNull];

			// "Bleed Loop"
			for "_i" from 0 to 1 step 0 do {
				if !(alive _unit) exitWith {}; // We're already dead...

				// My time is up... Kill me...
				if (time >= _endTime) exitWith {
					_unit setDamage 1; // Kill me...
				};

				// Get Nearest Medic...
				private _medDistance = -1;
				{
					private _distance = player distance _x;
					if (_distance < _medDistance || (_medDistance <= -1)) then { _medDistance = _distance };
				} foreach (playableUnits select {
					side _x isEqualTo independent && 
					{ alive _x } && 
					{ !(isDowned(_x)) } &&
					{ !(_x isEqualTo player) }
				});

				private _respawnStatus = [
					"Waiting to respawn...",
					"Press  <t color = '#7300e6'>Space</t> to respawn..."
				] select (time >= (_startTime + 60));

				if (time >= (_startTime + 60)) then { FF_canRespawn = true }; // Toggle respawn...

				// Set the nearest value...
				(_display displayCtrl 9002) ctrlSetStructuredText parseText ([
					format["<t align='left' size='1'>%2</t><t align='right' size='1'>Nearest Medic: %1m</t>",
						[(round _medDistance)] call life_fnc_numberText,
						_respawnStatus
					],
					format["<t align='left' size='1'>%1</t><t align='right' size='1'>No Medics Online</t>", _respawnStatus]
				] select (_medDistance <= -1));
			};
		};

		[0] call DB(updatePartial); // Update Money...
	};
};