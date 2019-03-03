#include "..\..\script_macros.hpp"
/*
    File: fn_repairTruck.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Main functionality for toolkits, to be revised in later version.
*/
private ["_veh","_upp","_ui","_progress","_pgText","_cP","_displayName","_test","_sideRepairArray"];
_veh = cursorObject;
life_interrupted = false;
if (isNull _veh) exitWith {};
if ((_veh isKindOf "Car") || (_veh isKindOf "Ship") || (_veh isKindOf "Air")) then {
    _displayName = FETCH_CONFIG2(getText,"CfgVehicles",(typeOf _veh),"displayName");
    if("ToolKit" in (items player)) then {
        _upp = format ["Repairing %1 with a tool kit...",_displayName];
    } else {
        _upp = format ["Repairing %1 without tool kit...",_displayName];
    };

    life_action_inUse = true;

    //Setup our progress bar.
    disableSerialization;
    "progressBar" cutRsc ["life_progress","PLAIN"];
    _ui = uiNamespace getVariable "life_progress";
    _progress = _ui displayCtrl 38201;
    _pgText = _ui displayCtrl 38202;
    _pgText ctrlSetText format ["%2 (1%1)...","%",_upp];
    _progress progressSetPosition 0.01;
    _cP = 0.01;

    for "_i" from 0 to 1 step 0 do {
        if (animationState player != "AinvPknlMstpSnonWnonDnon_medic_1") then {
            [player,"AinvPknlMstpSnonWnonDnon_medic_1",true] remoteExecCall ["life_fnc_animSync",RCLIENT];
            player switchMove "AinvPknlMstpSnonWnonDnon_medic_1";
            player playMoveNow "AinvPknlMstpSnonWnonDnon_medic_1";
        };

        if("ToolKit" in (items player)) then {
            uiSleep 0.27;
        } else {
            uiSleep 1.10;
        };

        _cP = _cP + 0.01;
        _progress progressSetPosition _cP;
        _pgText ctrlSetText format ["%3 (%1%2)...",round(_cP * 100),"%",_upp];
        if (_cP >= 1) exitWith {};
        if (!alive player) exitWith {};
        if !(isNull objectParent player) exitWith {};
        if (life_interrupted) exitWith {};
    };

    life_action_inUse = false;
    "progressBar" cutText ["","PLAIN"];
    player playActionNow "stop";
    if (life_interrupted) exitWith {life_interrupted = false; titleText["Action Cancelled.","PLAIN"]; life_action_inUse = false;};
    if !(isNull objectParent player) exitWith {titleText["You cannot do this while you are in a vehicle.","PLAIN"]; life_action_inUse = false;};
    
    player removeItem "ToolKit";

    _veh setDamage 0;
    titleText[localize "STR_NOTF_RepairedVehicle","PLAIN"];
};
