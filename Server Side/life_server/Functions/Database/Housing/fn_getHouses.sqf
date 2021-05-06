/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getHouses";

_this params [
	["_unit", objNull, [objNull]],
	["_faction", configNull, [configNull]],
	["_groupId", -1, [0, false]]
];

if !(isClass (_faction >> "Housing")) exitWith { false };

((missionNamespace getVariable ["ULP_SRV_Houses", []]) select {
	[_x, _unit, false] call ULP_fnc_isHouseOwner || {
		[_x] call ULP_fnc_isHouseShared && { _groupId isEqualType 0 } && { ((_x getVariable ["building_owner", []]) param [1, -2]) isEqualTo _groupId }
	}
})