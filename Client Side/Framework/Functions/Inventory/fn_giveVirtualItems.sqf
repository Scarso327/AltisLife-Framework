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

	if (isClass _itemCfg) then {
		private _icon = getText (_itemCfg >> "icon");
		private _displayName = getText (_itemCfg >> "displayName");

		if ([getNumber (_itemCfg >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
			private _configName = _x;

			{
				_items pushBack [_icon, format [_displayName, _x], [_configName, _x], -1];
			} forEach _y;
		} else {
			_items pushBack [_icon, _displayName, _x, _y];
		};
	};
} forEach ULP_Inventory;

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), _items, ["Give", "Cancel"], [_unit], {
	_this params [
		["_unit", objNull, [objNull]],
		["_display", displayNull, [displayNull]]
	];

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _index = lbCurSel _list;
	if (_index isEqualTo -1) exitWith {};

	private _value = _list lbValue _index;
	private _data = _list lbData _index;

	if (_value isEqualTo -1) then {
		_value = 1;
		_data = parseSimpleArray _data;
	};

	[0.01, [_unit, _data, _value], {
		_this params [
			["_unit", objNull, [objNull]],
			["_item", "", ["", []]],
			["_count", 1, [0]]
		];

		[
			(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _count], [_unit, _item],
			{
				_this params [
					["_unit", objNull, [objNull]],
					["_item", "", ["", []]],
					["_display", displayNull, [displayNull]],
					["_value", 1, [0]]
				];

				if ((player distance _unit) > 5) exitWith {
					["You're not close enough to give this person items!"] call ULP_fnc_hint;
				};

				if (_item isEqualType []) then {
					_value = _item param [1, []];
					_item = _item param [0, "", [""]];
				};
				
				[_unit, _item, _value] call ULP_fnc_giveItem;
			}, false
		] call ULP_fnc_selectNumber;
	}] call ULP_fnc_waitExecute;
}, false] call ULP_fnc_selectObject;