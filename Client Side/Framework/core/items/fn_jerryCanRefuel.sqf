#include "..\..\script_macros.hpp"
/*
    File: fn_jerryCanRefuel.sqf
    Author: Bryan "Tonic" Boardwine
    Modified: Jesse "tkcjesse" Schultz

    Description:
    Refuels the empty fuel canister at a gas pump. Based off the jerryRefuel/lockpick scripts by Tonic.
*/
private ["_startPos","_badDistance","_title","_ui","_progress","_pgText","_cP","_action","_fuelCost"];
life_interrupted = false;
if (life_inv_empty_fuel_can isEqualTo 0) exitWith {};
if (count(nearestObjects [player,["Land_FuelStation_Feed_F","Land_fs_feed_F"],3.5]) isEqualTo 0) exitWith { hint "You must be closer to the fuel pump!";};
if (life_action_inUse) exitWith {};
if !(isNull objectParent player) exitWith {};
if (player getVariable "restrained") exitWith {hint "You cannot do this while you are restrained.";};
if (player getVariable "playerSurrender") exitWith {hint "You cannot do this while you are surrendered.";};
_fuelCost = LIFE_SETTINGS(getNumber,"fuelCan_refuel");

life_action_inUse = true;
_action = [
    format ["Spend £%1 to refuel your empty fuel canister?",[_fuelCost] call life_fnc_numberText],
    "Fuel Station Pump",
    "Yes",
    "No"
] call BIS_fnc_guiMessage;

if (_action) then {
    if (CASH < _fuelCost) exitWith {hint "You don't have that much money!"; life_action_inUse = false;};
    _startPos = getPos player;
    //Setup our progress bar.
    disableSerialization;
    "progressBar" cutRsc ["life_progress","PLAIN"];
    _title = "Refuelling Fuel Canister";
    _ui = uiNamespace getVariable "life_progress";
    _progress = _ui displayCtrl 38201;
    _pgText = _ui displayCtrl 38202;
    _pgText ctrlSetText format ["%2 (1%1)...","%",_title];
    _progress progressSetPosition 0.01;
    _cP = 0.01;

    for "_i" from 0 to 1 step 0 do {
        if (animationState player != "AinvPknlMstpSnonWnonDnon_medic_1") then {
            [player,"AinvPknlMstpSnonWnonDnon_medic_1",true] remoteExecCall ["life_fnc_animSync",RCLIENT];
            player switchMove "AinvPknlMstpSnonWnonDnon_medic_1";
            player playMoveNow "AinvPknlMstpSnonWnonDnon_medic_1";
        };
        uiSleep 0.2;
        if (isNull _ui) then {
            "progressBar" cutRsc ["life_progress","PLAIN"];
            _ui = uiNamespace getVariable "life_progress";
            _progressBar = _ui displayCtrl 38201;
            _titleText = _ui displayCtrl 38202;
        };
        _cP = _cP + 0.01;
        _progress progressSetPosition _cP;
        _pgText ctrlSetText format ["%3 (%1%2)...",round(_cP * 100),"%",_title];
        if (_cP >= 1) exitWith {};
        if (!alive player || isDowned(player)) exitWith {life_action_inUse = false;};
        if (life_interrupted) exitWith {life_interrupted = false; life_action_inUse = false;};
    };

    //Kill the UI display and check for various states
    "progressBar" cutText ["","PLAIN"];
    player playActionNow "stop";

    if (!alive player || life_istazed || life_isknocked || isDowned(player)) exitWith {life_action_inUse = false;};
    if (player getVariable ["restrained",false]) exitWith {life_action_inUse = false;};
    if (!isNil "_badDistance") exitWith {titleText["You got to far away from the target.","PLAIN"]; life_action_inUse = false;};
    if (life_interrupted) exitWith {life_interrupted = false; titleText["Action Cancelled.","PLAIN"]; life_action_inUse = false;};
    if (!([false,"empty_fuel_can",1] call life_fnc_handleInv)) exitWith {life_action_inUse = false;};
    life_action_inUse = false;
    CASH = CASH - _fuelCost;
    [true,"fuel_can",1] call life_fnc_handleInv;
    hint "You have successfully refuelled the Fuel Canister!";
} else {
    hint "Action Cancelled.";
    closeDialog 0;
    life_action_inUse = false;
};