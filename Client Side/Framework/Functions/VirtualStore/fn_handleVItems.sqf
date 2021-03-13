/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyVItems";

private _ctrl = 

_this params [
	"_controls",
	["_remove", false, [true]]
];

_controls params [
	"_ctrl"
];

disableSerialization;

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _list = _display displayCtrl 3303;

private _curSel = missionConfigFile >> "CfgVirtualItems" >> (_list lnbData [(lnbCurSelRow _list), 0]);
if !(isClass _curSel) exitWith { hint "You need to select an item first..."; };

private _buyPrice = _list lnbValue [(lnbCurSelRow _list), 1];
private _sellPrice = _list lnbValue [(lnbCurSelRow _list), 2];
private _amount = 1;

if (_remove) then {
	_amount = [configName _curSel] call ULP_fnc_hasItem;
	if (_amount isEqualTo -1) exitWith {
		hint "You don't have any of these items to sell...";
		false breakOut "fn_buyVItems";
	};
} else {
	_amount = [getNumber(_curSel >> "weight")] call ULP_fnc_getMaxQuantity;
	if (_amount isEqualTo 0) exitWith {
		hint "You don't have enough inventory space...";
		false breakOut "fn_buyVItems";
	};
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_curSel, _remove, _buyPrice, _sellPrice],
	{
		_this params [
			["_cfg", configNull, [configNull]],
			["_remove", false, [true]],
			["_buyPrice", 0, [0]],
			["_sellPrice", 0, [0]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		_display = findDisplay 3300; // We don't need select so we switch this to virtual store...
		if (isNull _display || { isNull _cfg }) exitWith {};

		_buyPrice = _buyPrice * _value;
		_sellPrice = _sellPrice * _value;

		private _name = getText(_cfg >> "displayName");
		if ([configName _cfg, _value, _remove] call ULP_fnc_handleItem) then {
			if (_remove) then {
				[_sellPrice, false, format["Sold %1 %2(s)", _value, _name]] call ULP_fnc_addMoney;
				hint format["You have sold %1 %2(s) for £%3...", _value, _name, [_sellPrice] call ULP_fnc_numberText];
			} else {
				if !([_sellPrice, false, format["Purchased %1 %2(s)", _value, _name]] call ULP_fnc_removeMoney) exitWith {
					hint format["You can't afford £%1 for %2 %3(s)...", [_buyPrice] call ULP_fnc_numberText, _value, _name]
				};

				hint format["You have bought %1 %2(s) for £%3...", _value, _name, [_buyPrice] call ULP_fnc_numberText];
			};

			[_display] call ULP_fnc_updateVStore;
		} else {
			if (_remove) then {
				hint format["You don't have %1 %2(s) to sell...", _value, _name];
			} else {
				hint "You don't have enough inventory space...";
			};
		};
	}, false
] call ULP_fnc_selectNumber;