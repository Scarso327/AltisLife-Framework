/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_handleItem";

_this params [
	["_item", "", [""]],
	["_data", 0, [1, "", []]],
	["_remove", false, [true]],
	["_ignoreCarry", false, [true]]
];

private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _item;
if !(isClass _itemCfg || { _data > 0 && (_data isEqualTo "") }) exitWith { false };

private _isItemScripted = [getNumber (_itemCfg >> "Settings" >> "isScripted")] call ULP_fnc_bool;

private _weight = getNumber (_itemCfg >> "weight");
if !(_isItemScripted) then { _weight = _weight * _data; };

ULP_CarryInfo params ["_carryWeight", "_maxWeight"];

private _curData = [_item] call ULP_fnc_hasItem;
if (_curData isEqualTo -1) then { _curData = 0 };

if (_remove) then {
	private _newWeight = _carryWeight - _weight;
	if (_isItemScripted) then {
		if (_curData isEqualType 0) then {
			_curData = [];
		};

		private _index = _curData find _data;
		if (_index isEqualTo -1) exitWith { false breakOut "fn_handleItem" };
		
		_curData deleteAt _index;

		if ((count _curData) > 0) then {
			ULP_Inventory set [_item, _curData];
		} else {
			ULP_Inventory deleteAt _item;
		};
	} else {
		private _newTotal = _curData - _data;

		if (_newTotal < 0) exitWith { false breakOut "fn_handleItem" };

		if (_newTotal isEqualTo 0) then {
			ULP_Inventory deleteAt _item;
		} else {
			ULP_Inventory set [_item, _newTotal];
		};
	};

	if (isText (_itemCfg >> "Events" >> "onRemove")) exitWith {
		[_item, _data] call compile getText (_itemCfg >> "Events" >> "onRemove");
	};

	ULP_CarryInfo set [0, _newWeight];
} else {
	private _newWeight = _carryWeight + _weight;
	if (!_ignoreCarry && { _newWeight > _maxWeight }) exitWith { false breakOut "fn_handleItem" };

	if (_isItemScripted) then {
		if (_curData isEqualTo 0) then {
			if (_data isEqualType "") then {
				_data = [_data];
			};

			ULP_Inventory set [_item, _data];
		} else {
			_curData pushBack _data;
			ULP_Inventory set [_item, _curData];
		};
	} else {
		ULP_Inventory set [_item, _curData + _data];
	};
	
	ULP_CarryInfo set [0, _newWeight];
};

true