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
if (FETCH_CONST(life_adminlevel) < _reqLevel) exitWith { hint format["You are not a high enough member of staff to use this..."]; breakOut "fnc_adminPower" };
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
	case "heal": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};

		_target setDamage 0;
		life_thirst = 100;
		life_hunger = 100;

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
	};

	case "revive": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};

		// Add codeypoos

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target],_value];
	};

	case "compensate": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);
		_value = parseNumber(ctrlText 9922);

		if (_value <= 0 || _value > 999999) exitWith {hint "The value must be between <t color = '#7300e6'>£0</t> and <t color = '#7300e6'>£1,000,000</t>"};

		life_atmcash = life_atmcash  + _value;

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target],_value];
	};

	case "freeze": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};
		if (_target isEqualTo player) exitWith {hint "You are unable to do this."};

		[player] remoteExec ["life_fnc_freezePlayer",_target];

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
	};

	case "resetMoney": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};
		if (_target isEqualTo player) exitWith {hint "You are unable to do this."};

		CASH = 0;
		life_atmcash = LIFE_SETTINGS(getNumber,"starting_bank");

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
	};

	case "clearInventory": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};
		if (_target isEqualTo player) exitWith {hint "You are unable to do this."};

		CASH = 0;
		removeAllWeapons player;
		removeUniform player;
		removeVest player;
		removeBackpack player;
		removeHeadgear player;
		removeGoggles player;

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
	};

	case "camera": {
		[] spawn BIS_fnc_camera;

		_msg = format[_msg, player getVariable ["realname", name player]];
	};

	case "teleportSelect": {
		fnc_teleport = {
			params [["_pos", [], [[]]]];

			(vehicle player) setPos _pos;

			onMapSingleClick "";
			openMap [false, false];

			[true, format["%1 has teleported to cords %2", player getVariable ["realname", name player],_this]] call FF_fnc_logUsage;
		};
		
		openMap [true, false]; 
		onMapSingleClick "[_pos] call fnc_teleport";
		
		[] spawn { waitUntil { !visibleMap }; onMapSingleClick ""; }; // Fixes issues when admins close the menu and accidently teleport later on...

		_msg = format[_msg, player getVariable ["realname", name player]];
	};

	case "teleportTo": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};
		if (_target isEqualTo player || { !(vehicle _target isEqualTo _target ) }) exitWith {hint "You are unable to do this."};

		player setPos (getPos _target);

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
	};

	case "teleportHere": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};
		if (_target isEqualTo player || { !(vehicle _target isEqualTo _target ) }) exitWith {hint "You are unable to do this."};

		_target setPos (getPos player);

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
	};

	case "teleportToInVehicle": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};
		if (_target isEqualTo player || { (vehicle _target isEqualTo _target ) }) exitWith {hint "You are unable to do this."};

		player moveInCargo (vehicle _target);

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
	};

	case "teleportHereInVehicle": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};
		if (_target isEqualTo player || { !(vehicle _target isEqualTo _target ) }) exitWith {hint "You are unable to do this."};

		_target moveInCargo (vehicle player);

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
	};

	case "vehicleEject": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};
		if (_target isEqualTo player || { (vehicle _target isEqualTo _target ) }) exitWith {hint "You are unable to do this."};

		_target allowDamage false;
		doGetOut _target;
		sleep 0.2;
		_target allowDamage true;

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
	};

	case "vehicleRepair": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};
		if (_target isEqualTo player || { (vehicle _target isEqualTo _target ) }) exitWith {hint "You are unable to do this."};

		(vehicle _target) setdamage 0;

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
	};

	case "vehicleRefuel": {
		private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);

		if (isNil "_target" || isNull _target) exitWith {};
		if (_target isEqualTo player || { (vehicle _target isEqualTo _target ) }) exitWith {hint "You are unable to do this."};

		(vehicle _target) setfuel 1;

		_msg = format[_msg, player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
	};

	default { hint "No Such Power..."; breakOut "fnc_adminPower" };
};

[_notify, _msg] call FF(logUsage); // Log the usage to stop abuse + notify admins if needed...