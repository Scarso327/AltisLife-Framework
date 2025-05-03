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

if ([player] call ULP_fnc_onDuty) exitWith {
	["You can't sell or buy items while on duty..."] call ULP_fnc_hint;
};

private _list = _display displayCtrl 3303;

private _curSel = missionConfigFile >> "CfgVirtualItems" >> (_list lnbData [(lnbCurSelRow _list), 0]);
if !(isClass _curSel) exitWith { ["You need to select an item first!"] call ULP_fnc_hint; };

private _buyPrice = _list lnbValue [(lnbCurSelRow _list), 1];
private _sellPrice = _list lnbValue [(lnbCurSelRow _list), 2];
(parseSimpleArray (_list lnbData [(lnbCurSelRow _list), 2])) params [ "_gangTax", "_cartels" ];
private _amount = 1;

if (_remove) then {
	_amount = [configName _curSel] call ULP_fnc_hasItem;
	if (_amount isEqualTo -1) exitWith {
		["You don't have any of these items to sell!"] call ULP_fnc_hint;
		false breakOut "fn_buyVItems";
	};
} else {
	_amount = [getNumber(_curSel >> "weight")] call ULP_fnc_getMaxQuantity;
	if (_amount isEqualTo 0) exitWith {
		["You don't have enough inventory space!"] call ULP_fnc_hint;
		false breakOut "fn_buyVItems";
	};
};

private _allowPayByBank = _display getVariable ["allowPayByBank", false];
private _payByBank = _allowPayByBank && { cbChecked (_display displayCtrl 3307) };

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_curSel, _remove, _buyPrice, _sellPrice, _gangTax, _cartels, _payByBank],
	{
		_this params [
			["_cfg", configNull, [configNull]],
			["_remove", false, [true]],
			["_buyPrice", 0, [0]],
			["_sellPrice", 0, [0]],
			["_gangTax", 0, [0]],
			["_cartels", [], [[]]],
			["_payByBank", false, [true]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		_display = findDisplay 3300; // We don't need select so we switch this to virtual store...
		if (isNull _display || { isNull _cfg }) exitWith {};

		_buyPrice = _buyPrice * _value;
		_sellPrice = _sellPrice * _value;
		_gangTax = _gangTax * _value;

		private _name = getText(_cfg >> "displayName");

		if (_remove) then {
			if ([configName _cfg, _value, true] call ULP_fnc_handleItem) then {
				["SoldVirtualItem", [configName _cfg, _value, _sellPrice, [getNumber (_cfg >> "Settings" >> "isIllegal")] call ULP_fnc_bool]] call ULP_fnc_invokeEvent;
				[_sellPrice, false, format["Sold %1 %2(s)", _value, _name]] call ULP_fnc_addMoney;

				{
					_x params [ "_groupNetId", "_price" ];

					private _group = _groupNetId call BIS_fnc_groupFromNetId;

					if (!isNull _group && { [_group] call ULP_fnc_isGroup }) then {
						[[_group] call ULP_fnc_groupId, round (_price * _value), true] remoteExecCall ["ULP_SRV_fnc_updateGroupFunds", RSERV];
					};
				} forEach _cartels;

				if ([] call ULP_fnc_isGroup && { _gangTax > 0 }) then {
					[[] call ULP_fnc_groupId, _gangTax, true] remoteExecCall ["ULP_SRV_fnc_updateGroupFunds", RSERV];
					[format["You have sold %1 %2(s) for <t color='#B92DE0'>£%3</t> and £%4 was taken as tax by your group!", _value, _name, [_sellPrice] call ULP_fnc_numberText, [_gangTax] call ULP_fnc_numberText]] call ULP_fnc_hint;
				} else {
					[format["You have sold %1 %2(s) for <t color='#B92DE0'>£%3</t>!", _value, _name, [_sellPrice] call ULP_fnc_numberText]] call ULP_fnc_hint;
				};

				[true] call ULP_fnc_saveGear;
			} else {
				[format["You don't have %1 %2(s) to sell!", _value, _name]] call ULP_fnc_hint;
			};
		} else {
			if ([_buyPrice, _payByBank, format["Purchased %1 %2(s)", _value, _name]] call ULP_fnc_removeMoney) then {
				if ([configName _cfg, _value, false] call ULP_fnc_handleItem) then {
					[format["You have bought %1 %2(s) for £%3!", _value, _name, [_buyPrice] call ULP_fnc_numberText]] call ULP_fnc_hint;
					[true] call ULP_fnc_saveGear;
				} else {
					[_buyPrice, _payByBank] call ULP_fnc_addMoney; // Give them the money back, they didn't get what they paid for...
					["You don't have enough inventory space!"] call ULP_fnc_hint;
				};
			} else {
				[format["You can't afford <t color='#B92DE0'>£%1</t> for %2 %3(s)!", [_buyPrice] call ULP_fnc_numberText, _value, _name]] call ULP_fnc_hint;
			};
		};

		[_display] call ULP_fnc_updateVStore;
	}, false
] call ULP_fnc_selectNumber;