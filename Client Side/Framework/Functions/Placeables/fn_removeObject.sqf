/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeObject";

if (canSuspend) exitWith {
    [ULP_fnc_removeObject, _this] call ULP_fnc_directCall;
};

_this params [
	["_object", objNull, [objNull]]
];

if !([_object] call ULP_fnc_isPlaceable) exitWith { false };

(_object getVariable ["object_owner", []]) params [
	"", "", "_item", "_cfgName"
];

if !([_item, 1] call ULP_fnc_handleItem) then {
	["You were unable to carry the item so it was destroyed"] call ULP_fnc_hint;
};

private _cfg = missionConfigFile >> "CfgPlaceables" >> "Objects" >> _cfgName;
if (isClass _cfg && { isText (_cfg >> "onRemoved") }) then {
	[_object] call compile getText(_cfg >> "onRemoved");
};

deleteVehicle _object;

true