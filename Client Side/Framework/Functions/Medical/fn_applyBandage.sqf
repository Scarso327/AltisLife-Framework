/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_applyBandage";

if (canSuspend) exitWith {
    [ULP_fnc_applyBandage, _this] call ULP_fnc_directCall;
};

_this params [
	["_ctrl", controlNull, [controlNull]],
	["_bandage", "", [""]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _unit = _display getVariable ["patient", objNull];

if !(isDowned(_unit)) exitWith {
	["This patient is stable and doesn't require bandaging..."] call ULP_fnc_hint;
};

private _limb = _display getVariable ["limb", ""];
private _wounds = + (_unit getVariable ["IncapacitatedWounds", createHashMap]);
private _limbWounds = _wounds getOrDefault [_limb, createHashMap];

if ((count _limbWounds) < 1) exitWith {
	["This limb doesn't require any bandaging..."] call ULP_fnc_hint;
};

private _list = _display displayCtrl 4909;
private _wound = _list lnbData [lnbCurSelRow _list, 0];

if (_wound isEqualTo "") exitWith {
	["You must select a wound to bandage on this limb..."] call ULP_fnc_hint;
};

if (([_bandage] call ULP_fnc_hasItem) < 1) exitWith {
	["You don't have the required item to apply..."] call ULP_fnc_hint;
};

private _item = missionConfigFile >> "CfgVirtualItems" >> _bandage;
private _woundCfg = missionConfigFile >> "CfgMedical" >> "Damage" >> _wound;

if (!(isClass _item) || { !(isClass _woundCfg) }) exitWith {
	["This wound or bandage isn't recongised..."] call ULP_fnc_hint;
};

private _itemCfg = ((createHashMapFromArray getArray (_woundCfg >> "items")) getOrDefault [_bandage, [0, 0.5]]) params [ "_time", "_chance" ];
_time = _time + getNumber (_woundCfg >> "time");

closeDialog 0;

[format ["Applying %1", getText (_item >> "displayName")], _time, [_item, _unit, _chance, _limb, _wound], { isDowned(_this select 1) && { (player distance (_this select 1)) < 5 } }, {
	_this params [ "_item", "_unit", "_chance", "_limb", "_wound" ];

	if ([configName _item, 1, true] call ULP_fnc_handleItem) then {

		if ((random 1) <= _chance) then {
			private _wounds = + (_unit getVariable ["IncapacitatedWounds", createHashMap]);
			private _limbWounds = _wounds getOrDefault [_limb, createHashMap];
			private _count = ((_limbWounds getOrDefault [_wound, 0]) - 1);

			if (_count <= 0) then {
				_limbWounds deleteAt _wound;
			} else {
				_limbWounds set [_wound, _count];
			};

			if ((count _limbWounds) <= 0) then {
				_wounds deleteAt _limb;
			} else {
				_wounds set [_limb, _limbWounds];
			};

			_unit setVariable ["IncapacitatedWounds", _wounds, true];

			["You applied the bandage and successfully closed the wound..."] call ULP_fnc_hint;
		} else {
			["You applied the bandage but it failed to close the wound..."] call ULP_fnc_hint;
		};
	};
}, {} , ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;