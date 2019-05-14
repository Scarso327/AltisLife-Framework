/*
	@File: fn_doPower.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: If you don't know then you shouldn't touch.
*/
scopeName "fnc_adminPower";
#include "..\..\script_macros.hpp"
#define CFG missionConfigFile >> "CfgPowers"
params [
	["_power", "", [""]]
];

if (_power IsEqualTo "") exitWith {};

private _notify = false;

if !(isClass (CFG >> _power)) exitWith { hint "No Such Power..."; breakOut "fnc_adminPower" };

private _thisPower = CFG >> _power;
private _reqLevel = (getNumber (_thisPower >> "reqLevel"));
private _notify = [false,true] select (getNumber (_thisPower >> "notify") isEqualTo 1);
private _msg = (getText (_thisPower >> "message"));

// Checks...
if (FETCH_CONST(life_adminlevel) < _reqLevel) exitWith { hint format["You must be admin level <t color = '#7300e6'>%1</t> to use this...", _reqLevel]; breakOut "fnc_adminPower" };
if (!admin_duty && { (getNumber (_thisPower >> "onDuty")) isEqualTo 1 }) exitWith { hint "You must be <t color = '#7300e6'>on-duty</t> to use this..."; breakOut "fnc_adminPower" };
if !([getText(_thisPower >> 'conditions')] call life_fnc_levelCheck) exitWith { hint "You don't meet the conditions to use this power..."; breakOut "fnc_adminPower" };

// If dialogs is false then we need to close all open dialogs...
if !((getNumber (_thisPower >> "dialogs")) isEqualTo 1) then { 
	[] spawn {
		while {dialog} do {
			closeDialog 0;
			sleep 0.01;
		};
	}; 
};

// Now run the action specific code...
switch (_power) do {
	case "Teleport": {
		fnc_teleport = {
			_this params [ ["_xA", 0, [0]], ["_y", 0, [0]], ["_z", 0, [0]] ];

			(vehicle player) setpos [_xA, _y, 0];

			onMapSingleClick "";
			openMap [false, false];

			[true, format["%1 has teleported to cords %2", player getVariable ["realname", name player],_this]] call FF_fnc_logUsage;
		};
		
		openMap [true, false];
		onMapSingleClick "[_pos] call fnc_teleport";
		
		[] spawn { waitUntil { !visibleMap }; onMapSingleClick ""; }; // Fixes issues when admins close the menu and accidently teleport later on...

		_msg = format[_msg, player getVariable ["realname", name player]];
	};

	default { hint "No Such Power..."; breakOut "fnc_adminPower" };
};

[_notify, _msg] call FF(logUsage); // Log the usage to stop abuse + notify admins if needed...