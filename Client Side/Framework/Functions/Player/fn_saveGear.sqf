/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_saveGear";

if ([player] call ULP_fnc_onDuty) exitWith { false };

private _yItems = [];

{
    _yItems pushBackUnique _x;
} forEach ((("getNumber(_x >> ""Settings"" >> ""isSavable"") isEqualTo 1" configClasses (missionConfigFile >> "CfgVirtualItems")) apply {
    [configName _x, [configName _x] call ULP_fnc_hasItem]
}) select { (_x select 1) isEqualType [] || { (_x select 1) > 0 } });

private _fnc_getCurTexture = {
    _this params ["_container"];

    ([
        (_container getVariable ["texture", ""]),
        ""
    ] select (isNull _container))
};

ULP_Gear = [
    (getUnitLoadout player),
    _yItems,
    [
        [uniformContainer player] call _fnc_getCurTexture,
        [backpackContainer player] call _fnc_getCurTexture
    ]
];

true