/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_gather";

_this params [
	["_zone", configNull, [configNull]]
];

if (isNull _zone || { !([player] call ULP_fnc_getFaction in getArray (_zone >> "factions")) } || { !(call compile getText (_zone >> "condition")) }) exitWith { false };

private _reqItems = getArray (_zone >> "reqItems");
{
	if ([_x] call ULP_fnc_hasItem isEqualTo -1) exitWith {
		hint format["This zone requires these items to gather: %1...", _reqItems];
		false breakOut "fn_gather";
	};

	nil
} count _reqItems;

private _reqLicenses = getArray (_zone >> "reqLicenses");
{
	if !([_x] call ULP_fnc_hasLicense) exitWith {
		hint format["You need these licenses to gather here: %1...", _reqLicenses];
		false breakOut "fn_gather";
	};

	nil
} count _reqLicenses;

private _resources = getArray (_zone >> "items");
if (_resources isEqualTo []) exitWith { false };

private _items = _resources apply { _x select 0 };
private _weights = _resources apply { (_x select 1) / 100 };

private _item = missionConfigFile >> "CfgVirtualItems" >> (_items selectRandomWeighted _weights);
if !(isClass _item) exitWith {};

ULP_CarryInfo params ["_carryWeight", "_maxWeight"];

private _total = floor ((_maxWeight - _carryWeight) / getNumber(_item >> "weight"));
if (_total isEqualTo 0) exitWith {
	hint "Your inventory is full";
	false
};

private _title = ["Gathering", getText (_zone >> "actionTitle")] select (isText (_zone >> "actionTitle"));
private _profession = getArray (_zone >> "profession");
private _leveling = getArray (_zone >> "leveling");

private _time = getNumber(_zone >> "gatherTime");

if !(_profession isEqualTo []) then {
	private _profCal = [(_profession select 0)] call ULP_fnc_getProfessionCalculation;
	if (_profCal > 0) then { _time = _time - (_time * (_profCal / 100)); };
};

[format["%1 %2(s)", _title, getText(_item >> "displayName")], _time * _total, [_item, _total, _profession, _leveling], { true }, {
	_this params [ "_item", "_total", "_profession", "_leveling" ];

	[configName _item, _total] call ULP_fnc_handleItem;

	hint format["You've gathered %1 %2(s)", _total, getText(_item >> "displayName")];
	["GatheredVirtualItem", [configName _item, _total]] call ULP_fnc_invokeEvent;

	if !(_profession isEqualTo []) then { _profession call ULP_fnc_increaseProfession; };
	if !(_leveling isEqualTo []) then { _leveling call ULP_fnc_addXP; };
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;

true