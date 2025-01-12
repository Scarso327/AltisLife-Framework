/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_InventoryClosed";

_this params [
	["_unit", objNull, [objNull]],
	["_container", objNull, [objNull]],
	["_secondaryContainer", objNull, [objNull]]
];

{
	if ([getNumber (missionConfigFile >> "CfgVehicles" >> (typeOf _x) >> "isHouse")] call ULP_fnc_bool) then {
		[_x] remoteExecCall ["ULP_SRV_fnc_saveStorage", RSERV];
	};
} forEach [_container, _secondaryContainer];

[true] call ULP_fnc_saveGear;

// Delay to ensure the time sets properly
[0.1, [], { [] call ULP_fnc_maxCarry; }] call ULP_fnc_waitExecute;