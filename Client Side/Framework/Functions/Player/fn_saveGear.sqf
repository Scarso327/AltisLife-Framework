/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_saveGear";

_this params [
    ["_syncWithDatabase", false, [true]]
];

if ([player] call ULP_fnc_onDuty) exitWith { false };

private _yItems = [];

{
    _yItems pushBackUnique _x;
} forEach ((("getNumber(_x >> ""Settings"" >> ""isSavable"") isEqualTo 1" configClasses (missionConfigFile >> "CfgVirtualItems")) apply {
    [configName _x, [configName _x] call ULP_fnc_hasItem]
}) select { (_x select 1) isEqualType [] || { (_x select 1) > 0 } });

ULP_Gear = [
    (getUnitLoadout player),
    _yItems,
    [
        [ULP_UniformTexture, ""] select ((uniform player) isEqualTo ""),
        [ULP_BackpackTexture, ""] select ((backpack player) isEqualTo "")
    ]
];

if (_syncWithDatabase) then {
    [player, 15, ULP_Gear] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
};

true