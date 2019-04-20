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
			private _endTime = time + (LIFE_SETTINGS(getNumber,"bleedout_timer")); // Current Time + Bleedout Time

			// "Bleed Loop"
			for "_i" from 0 to 1 step 0 do {
				if !(alive _unit) exitWith {}; // We're already dead...

				// My time is up... Kill me...
				if (time >= _endTime) exitWith {
					_unit setDamage 1; // Kill me...
				};
			};
		};

		[0] call DB(updatePartial); // Update Money...
	};
};