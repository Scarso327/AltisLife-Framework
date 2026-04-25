/*
    Description:
    Initialize the headless client and required systems.
*/
#include "script_macros.hpp"

private _timeStamp = diag_tickTime;
["HC Initialisation Started"] call ULP_fnc_logIt;

if !(isClass (configFile >> "CfgPatches" >> "ULPCore")) exitWith {
    ["ULP Core is not present. Please ensure it is added as a dependency and is loading correctly."] call ULP_fnc_logIt;
};

if !([] call ULP_CRE_fnc_init) exitWith {
    ["ULP Core failed to initialize."] call ULP_fnc_logIt;
};

// I am ready and headless, use me!
[clientOwner] remoteExecCall ["ULP_SRV_fnc_registerHc", RSERV];

[format["HC Initialisation Lasted %1s", diag_tickTime - _timeStamp]] call ULP_fnc_logIt;