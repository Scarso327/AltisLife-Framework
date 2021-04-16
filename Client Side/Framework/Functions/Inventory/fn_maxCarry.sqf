/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_maxCarry";

private _carryWeight = getNumber (missionConfigFile >> "CfgSettings" >> "total_maxWeight");

{
	private _cfg = missionConfigFile >> "CfgClothing" >> _x;
	if (isClass _cfg && { isNumber (_cfg >> "virtualSpace") }) then {
		_carryWeight = _carryWeight + getNumber (_cfg >> "virtualSpace");
	};
} forEach [uniform player, vest player, backpack player];

ULP_CarryInfo set [1, _carryWeight];

[((ULP_CarryInfo select 0) > (ULP_CarryInfo select 1))] call ULP_fnc_setOverweight;