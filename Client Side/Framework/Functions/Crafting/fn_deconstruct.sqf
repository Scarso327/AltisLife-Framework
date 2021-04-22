/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_deconstruct";

_this params [
	["_item", "", [""]]
];

if !(isNull (objectParent player)) exitWith {
	["You can't deconstruct items while in a vehicle..."] call ULP_fnc_hint;
	false;
};

private _cfg =  missionConfigFile >> "CfgVirtualItems" >> _item;
if !(isClass (_cfg >> "Deconstruction")) exitWith {
	["This item can't be deconstructed"] call ULP_fnc_hint;
	false
};

if (["Toolbox"] call ULP_fnc_hasItem < 1) exitWith {
	["You need a Tool Box to descontruct items..."] call ULP_fnc_hint;
	false
};

if ([getNumber (_cfg >> "Deconstruction" >> "workbench")] call ULP_fnc_bool && { !([] call ULP_fnc_nearWorkbench) }) exitWith {
	["To deconstruct this item you must be near a workbench"] call ULP_fnc_hint;
	false
};

private _name = getText (_cfg >> "displayName");

private _total = [_item] call ULP_fnc_hasItem;
if (_total < 1) exitWith {
	[format ["You don't have any %1 to deconstruct", _name]] call ULP_fnc_hint;
	false
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _total], [_cfg, _name],
	{
		_this params [
			["_cfg", configNull, [configNull]],
			["_name", "", [""]],
			["_display", displayNull, [displayNull]],
			["_amount", 1, [0]]
		];

		if (_amount < 0 || { _amount > ([configName _cfg] call ULP_fnc_hasItem) }) exitWith {};
		closeDialog 0;

		[format["Deconstructing %1(s)", _name], getNumber (_cfg >> "Deconstruction" >> "time") * _amount, [_cfg, _name, _amount], { true }, {
			_this params [ "_cfg", "_name", "_amount" ];

			if ([configName _cfg, _amount, true] call ULP_fnc_handleItem) then {
				{ [_x select 0, (_x select 1) * _amount, false, true] call ULP_fnc_handleItem; } forEach getArray (_cfg >> "Deconstruction" >> "materials");
				{ _x call ULP_fnc_unlockBlueprint; } forEach getArray (_cfg >> "Deconstruction" >> "blueprints");

				[format ["You've deconstructed %2 %1(s)...", _name, [_amount] call ULP_fnc_numberText]] call ULP_fnc_hint;
			} else {
				[format ["You don't have any %2 x %1 to deconstruct...", _name, [_amount] call ULP_fnc_numberText]] call ULP_fnc_hint;
			};
		}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, true
] call ULP_fnc_selectNumber;
true