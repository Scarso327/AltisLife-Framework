/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	Physical : [this, "<t color='#073763'>[APC]</t> Equipment Store", "Police", "CfgItemsStore"] call ULP_fnc_addStore;
** 	Clothing : [this, "<t color='#073763'>[APC]</t> Clothing Store", "Police", "CfgClothesStore"] call ULP_fnc_addStore;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addStore";

_this params [
	["_trader", objNull, [objNull]],
	["_title", "", [""]],
	["_store", "", [""]],
	["_cfg", "", [""]],
	["_condition", "", [""]]
];

private _cfgCondition = missionConfigFile >> "CfgStores" >> _cfg >> _store;
if (isNull _trader || { _title isEqualTo "" } || { !(isClass _cfgCondition) }) exitWith {};
_cfgCondition = getText(_cfgCondition >> "condition");

if !(_condition isEqualTo "") then {
	_cfgCondition = _condition;
};

_trader addAction [format["%1", _title], { [(_this select 3) select 0, (_this select 3) select 1] call ULP_fnc_openStore }, [_store, _cfg], 1.5, true, true, "", _cfgCondition, 3];