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
if (["Muscleman"] call ULP_fnc_hasPerk) then { _carryWeight = round (_carryWeight * 1.25); };

_carryWeight