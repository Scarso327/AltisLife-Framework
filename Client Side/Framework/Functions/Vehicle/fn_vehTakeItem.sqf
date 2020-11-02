#include "..\..\script_macros.hpp"
#define ctrlSelData(ctrl) (lbData[##ctrl,(lbCurSel ##ctrl)])
/*
    File: fn_vehTakeItem.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Used in the vehicle trunk menu, takes the selected item and puts it in the players virtual inventory
    if the player has room.
*/
private ["_ctrl","_num","_index","_data","_old","_value","_weight","_diff"];
disableSerialization;
if (isNull life_trunk_vehicle || !alive life_trunk_vehicle) exitWith {hint "The vehicle either doesn't exist or is destroyed."};
if (!alive player) exitWith {closeDialog 0;};
if ((life_trunk_vehicle getVariable ["trunk_in_use_by",player]) != player) exitWith {  closeDialog 0; hint "This vehicle's trunk is in use, only one person can use it at a time."; };

if ((lbCurSel 3502) isEqualTo -1) exitWith {hint "You did not select anything.";};
_ctrl = ctrlSelData(3502);
_num = ctrlText 3505;
if (!([_num] call TON_fnc_isnumber)) exitWith {hint "Invalid number format";};
_num = parseNumber(_num);
if (_num < 1) exitWith {hint "You can't enter anything below 1!";};

_index = [_ctrl,((life_trunk_vehicle getVariable "Trunk") select 0)] call TON_fnc_index;
_data = (life_trunk_vehicle getVariable "Trunk") select 0;
_old = life_trunk_vehicle getVariable "Trunk";
if (_index isEqualTo -1) exitWith {};
_value = _data select _index select 1;
if (_num > _value) exitWith {hint "The vehicle doesn't have that many of that item."};
_num = [_ctrl,_num,life_carryWeight,life_maxWeight] call life_fnc_calWeightDiff;
if (_num isEqualTo 0) exitWith {hint "Your inventory space is full."};
_weight = ([_ctrl] call life_fnc_itemWeight) * _num;
if (_ctrl == "money") then {
    if (_num == _value) then {
        _data deleteAt _index;
    } else {
        _data set[_index,[_ctrl,(_value - _num)]];
    };

    CASH = CASH + _num;
    [0] call SOCK_fnc_updatePartial;
    life_trunk_vehicle setVariable ["Trunk",[_data,(_old select 1) - _weight],true];
    [life_trunk_vehicle] call life_fnc_vehInventory;
} else {
    if ([true,_ctrl,_num] call life_fnc_handleInv) then {
        if (_num == _value) then {
            _data deleteAt _index;
        } else {
            _data set[_index,[_ctrl,(_value - _num)]];
        };
        life_trunk_vehicle setVariable ["Trunk",[_data,(_old select 1) - _weight],true];
        [life_trunk_vehicle] call life_fnc_vehInventory;
    } else {
        hint "Your inventory space is full.";
    };
};
