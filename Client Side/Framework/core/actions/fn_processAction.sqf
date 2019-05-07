#include "..\..\script_macros.hpp"
/*
    File: fn_processAction.sqf
    Author: Bryan "Tonic" Boardwine
    Modified : NiiRoZz

    Description:
    Master handling for processing an item.
    NiiRoZz : Added multiprocess
*/
private ["_vendor","_type","_itemInfo","_oldItem","_newItemWeight","_newItem","_oldItemWeight","_cost","_upp","_hasLicense","_itemName","_oldVal","_ui","_progress","_pgText","_requiredLicense","_cP","_materialsRequired","_materialsGiven","_noLicenseCost","_text","_filter","_totalConversions","_minimumConversions"];

if (isNull FF_ProcessingVendor) exitWith{systemChat "Vendor?"};

_vendor = FF_ProcessingVendor;
_type = CONTROL_DATA(5001);

//Error check
if (isNull _vendor || _type isEqualTo "" || (player distance _vendor > 10)) exitWith {systemChat str [_vendor, _type, player distance _vendor]};
life_action_inUse = true;//Lock out other actions during processing.
closeDialog 0;
FF_ProcessingVendor = objNull;

if (isClass (missionConfigFile >> "CfgProcess" >> _type)) then {
    _filter = false;
    _materialsRequired = M_CONFIG(getArray,"CfgProcess",_type,"MaterialsReq");
    _materialsGiven = M_CONFIG(getArray,"CfgProcess",_type,"MaterialsGive");
    _requiredLicense = M_CONFIG(getText,"CfgProcess",_type,"RequiredLicense");
    _noLicenseCost = M_CONFIG(getNumber,"CfgProcess",_type,"NoLicenseCost");
    _text = M_CONFIG(getText,"CfgProcess",_type,"Text");
} else {_filter = true;};

if (_filter) exitWith {life_action_inUse = false;};

_itemInfo = [_materialsRequired, _materialsGiven, _noLicenseCost, _text, _requiredLicense];
if (count _itemInfo isEqualTo 0) exitWith {life_action_inUse = false;};

//Setup vars.
_oldItem = _itemInfo select 0;
_newItem = _itemInfo select 1;
_cost = _itemInfo select 2;
_upp = _itemInfo select 3;
private _licenseRequired = _itemInfo select 4;

_exit = false;
if (count _oldItem isEqualTo 0) exitWith {life_action_inUse = false;};

_totalConversions = [];
{
    _var = ITEM_VALUE(_x select 0);
    if (_var isEqualTo 0) exitWith {_exit = true;};
    if (_var < (_x select 1)) exitWith {_exit = true;};
    _totalConversions pushBack (floor (_var/(_x select 1)));
} forEach _oldItem;

if (_exit) exitWith {life_is_processing = false; hint "You don't have enough items!"; life_action_inUse = false;};

if (_licenseRequired isEqualTo "") then {
    _hasLicense = false;
} else {
    _hasLicense = LICENSE_VALUE(_licenseRequired,"civ");
};

_cost = _cost * (count _oldItem);

_minimumConversions = _totalConversions call BIS_fnc_lowestNum;
_oldItemWeight = 0;
{
    _weight = ([_x select 0] call life_fnc_itemWeight) * (_x select 1);
    _oldItemWeight = _oldItemWeight + _weight;
} count _oldItem;

_newItemWeight = 0;
{
    _weight = ([_x select 0] call life_fnc_itemWeight) * (_x select 1);
    _newItemWeight = _newItemWeight + _weight;
} count _newItem;

_exit = false;

if (_newItemWeight > _oldItemWeight) then {
    _netChange = _newItemWeight - _oldItemWeight;
    _freeSpace = life_maxWeight - life_carryWeight;
    if (_freeSpace < _netChange) exitWith {_exit = true;};
    private _estConversions = floor(_freeSpace / _netChange);
    if (_estConversions < _minimumConversions) then {
        _minimumConversions = _estConversions;
    };
};

if (_exit) exitWith {hint "You have no inventory space to process your materials."; life_is_processing = false; life_action_inUse = false;};

//Setup our progress bar.
disableSerialization;
"progressBar" cutRsc ["life_progress","PLAIN"];
_ui = uiNamespace getVariable "life_progress";
_progress = _ui displayCtrl 38201;
_pgText = _ui displayCtrl 38202;
_pgText ctrlSetText format ["%2 (1%1)...","%",_upp];
_progress progressSetPosition 0.01;
_cP = 0.01;

life_is_processing = true;

private _increase = 0.01;
private _level = PROF_LVL("Prof_Processing");
if (_level > 0) then { _increase = 0.01 + (_level / 2000) };

if (_hasLicense) then {
    for "_i" from 0 to 1 step 0 do {
        uiSleep  0.28;
        _cP = _cP + _increase;
        _progress progressSetPosition _cP;
        _pgText ctrlSetText format ["%3 (%1%2)...",round(_cP * 100),"%",_upp];
        if (_cP >= 1) exitWith {};
        if (player distance _vendor > 10) exitWith {};
    };
    if (player distance _vendor > 10) exitWith {hint "You need to stay within 10m to process."; "progressBar" cutText ["","PLAIN"]; life_is_processing = false; life_action_inUse = false;};

    {
        [false,(_x select 0),((_x select 1)*(_minimumConversions))] call life_fnc_handleInv;
    } count _oldItem;

    {
        [true,(_x select 0),((_x select 1)*(_minimumConversions))] call life_fnc_handleInv;
    } count _newItem;

    "progressBar" cutText ["","PLAIN"];
    if (_minimumConversions isEqualTo (_totalConversions call BIS_fnc_lowestNum)) then {hint "You have processed your items!";} else {hint "Only part of your materials could be processed due to reaching your maximum weight.";};
    life_is_processing = false; life_action_inUse = false;

    [(2 * _minimumConversions), "Processing"] spawn FF_fnc_handleXP; // 2 XP * Processed Items
} else {
    if (CASH < _cost) exitWith {hint format ["You need £%1 to process without a license!",[_cost] call life_fnc_numberText]; "progressBar" cutText ["","PLAIN"]; life_is_processing = false; life_action_inUse = false;};

    for "_i" from 0 to 1 step 0 do {
        uiSleep  0.9;
        _cP = _cP + _increase;
        _progress progressSetPosition _cP;
        _pgText ctrlSetText format ["%3 (%1%2)...",round(_cP * 100),"%",_upp];
        if (_cP >= 1) exitWith {};
        if (player distance _vendor > 10) exitWith {};
    };

    if (player distance _vendor > 10) exitWith {hint "You need to stay within 10m to process."; "progressBar" cutText ["","PLAIN"]; life_is_processing = false; life_action_inUse = false;};
    if (CASH < _cost) exitWith {hint format ["You need £%1 to process without a license!",[_cost] call life_fnc_numberText]; "progressBar" cutText ["","PLAIN"]; life_is_processing = false; life_action_inUse = false;};

    {
        [false,(_x select 0),((_x select 1)*(_minimumConversions))] call life_fnc_handleInv;
    } count _oldItem;

    {
        [true,(_x select 0),((_x select 1)*(_minimumConversions))] call life_fnc_handleInv;
    } count _newItem;

    "progressBar" cutText ["","PLAIN"];
    if (_minimumConversions isEqualTo (_totalConversions call BIS_fnc_lowestNum)) then {hint "You have processed your items!";} else {hint "Only part of your materials could be processed due to reaching your maximum weight.";};
    CASH = CASH - _cost;
    [0] call SOCK_fnc_updatePartial;
    life_is_processing = false;
    life_action_inUse = false;
};
