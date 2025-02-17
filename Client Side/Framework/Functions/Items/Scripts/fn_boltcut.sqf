/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_boltcut";

private _object = cursorObject;

if (_object getVariable ["block_boltcutter", false]) exitWith {
	["You can't bolt cut into this building..."] call ULP_fnc_hint;
	false
};

private _door = [_object] call ULP_fnc_getNearestDoor;
private _pos = _object;
private _isDoor = false;

if (!(_object getVariable ["locked", false]) && { _door > -1 } && { (_object getVariable [format ["bis_disabled_Door_%1", _door], 0]) isEqualTo 1 }) then {
	_isDoor = true;
	_pos = (([_object] call ULP_fnc_getBuildingDoors) select (_door - 1));
};

if (isNull _object || { (player distance _pos) > 5 } || { !(_object getVariable ["locked", false]) && !_isDoor }) exitWith {
	["You're either not close enough to something you can bolt cut or it's already been cut..."] call ULP_fnc_hint;
	false
};

[] spawn ULP_UI_fnc_closeDialogs;

private _time = ["BoltCutter", 150] call ULP_fnc_activatePerk;
private _onBreakIn = "";

if ([] call ULP_fnc_isGroup) then {
	private _buff = [group player, "Boltcutting"] call ULP_fnc_groupBuff;
	if (_buff > 0) then { _time = _time - (_time * _buff); };
};

private _storageHouse = _object getVariable ["building", objNull];
private _housingBreakInCfg = missionConfigFile >> "CfgHousing" >> "Houses" >> (if (isNull _storageHouse) then {
	typeOf _object
} else {
	typeOf _storageHouse
}) >> "BreakIn";

private _breakInCfg = _object getVariable ["breakInConfig", (if (isClass _housingBreakInCfg) then {
	_housingBreakInCfg
} else {
	configNull
})];

if !(isNull _breakInCfg) then {
	_time = getNumber (_breakInCfg >> "breakIn");
	_onBreakIn = getText (_breakInCfg >> "onBreakIn");
	if !(_object call compile getText (_breakInCfg >> "condition")) exitWith {
		_object call compile getText (_breakInCfg >> "onFail");
		false breakOut "fn_boltcut";
	};

	if (isText (_breakInCfg >> "onBreakInStart")) then {
		_object call compile getText (_breakInCfg >> "onBreakInStart");
	};
};

if ([_object, "ImprovedDoorsUpgrade"] call ULP_fnc_hasUpgrade) then {
	_time = _time * 1.5;
};

["Boltcutting", _time, [_object, _pos, _isDoor, _door, _onBreakIn], { (player distance (_this select 1)) <= 5 }, {
	_this params [ "_object", "_pos", "_isDoor", "_door", "_onBreakIn" ];

	["You have successfully broke the lock!"] call ULP_fnc_hint;

	if (_isDoor) then {
		_object setVariable [format ["bis_disabled_Door_%1", _door], 0, true];
	} else {
		_object setVariable ["locked", nil, true];
	};

	if !(_onBreakIn isEqualTo "") then {
		_object call compile _onBreakIn;
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
true