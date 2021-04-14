/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_shareHouse";

if (canSuspend) exitWith {
    [ULP_fnc_shareHouse, _this] call ULP_fnc_directCall;
};

_this params [
	["_house", objNull, [objNull]]
];

if (isNull _house) exitWith { false };

if !([_house, player, false] call ULP_fnc_isHouseOwner) exitWith {
	["Only the house owner can change whether the house is shared or not!"] call ULP_fnc_hint;
	false
};

// Stop spam...
if (time < (_house getVariable ["building_last_shared", 0])) exitWith {
	["You've changed the shared status of this house recently, please wait..."] call ULP_fnc_hint;
	false
};
_house setVariable ["building_last_shared", time + 5];

if (_house getVariable ["selling", false]) exitWith {
	["This house is being sold!"] call ULP_fnc_hint;
	false
};

private _shared = !([_house] call ULP_fnc_isHouseShared);
_house setVariable ["building_shared", _shared, true];

private _event = ([
	"HouseRemoved",
	"HouseAdded"
] select (_shared));

{
	[_event, [_house]] remoteExecCall ["ULP_fnc_invokeEvent", _x];
} forEach ((units (group player)) select {
	!(_x isEqualTo player)
});

[_house getVariable ["building_id", -1], _shared] remoteExecCall ["ULP_SRV_fnc_setHouseShared", RSERV];
[format ["This house is %1 shared with your group.", ["no longer", "now"] select (_shared)]] call ULP_fnc_hint;
true