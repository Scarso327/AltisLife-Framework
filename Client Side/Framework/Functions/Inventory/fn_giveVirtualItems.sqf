/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_giveVirtualItems";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit || { !(isPlayer _unit) } || { (player distance _unit) > 5 }) exitWith {};

private _items = [];

{
	private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _x;
	if !([getNumber (_itemCfg >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
		_items pushBack [getText (_itemCfg >> "icon"), getText (_itemCfg >> "displayName"), _x, _y];
	};
} forEach ULP_Inventory;

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), _items, ["Give", "Cancel"], [_unit], {
	_this params [
		["_unit", objNull, [objNull]],
		["_display", displayNull, [displayNull]]
	];

	if ((player distance _unit) > 5) exitWith {
		["You're not close enough to give this person items!"] call ULP_fnc_hint;
	};

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _index = lbCurSel _list;
	if (_index isEqualTo -1) exitWith {};

	if ([_unit, (_list lbData _index), (_list lbValue _index)] call ULP_fnc_giveItem) then {
		_list lbDelete _index;
	};
}, false] call ULP_fnc_selectObject;