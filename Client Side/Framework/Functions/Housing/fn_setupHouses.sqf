/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setupHouses";

_this params [
	["_houses", [], [[]]]
];

{
	["HouseAdded", [_x]] call ULP_fnc_invokeEvent;
} forEach (_houses select {
	[_x] call ULP_fnc_isHouseOwner || {
		!(isNil "InitGroupId") && { [_x] call ULP_fnc_isHouseShared } && { ((_x getVariable ["building_owner", []]) param [1, -2]) isEqualTo InitGroupId }
	}
});