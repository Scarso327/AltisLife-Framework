#include "..\..\script_macros.hpp"
/*
    File: fn_giveDiff.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    ??A?SD?ADS?A
*/
private ["_unit","_item","_val","_from","_bool"];
_unit = _this select 0;
if !(_unit isEqualTo player) exitWith {};
_item = _this select 1;
_val = _this select 2;
_from = _this select 3;
_bool = if (count _this > 4) then {true} else {false};
_type = M_CONFIG(getText,"CfgItems",_item,"displayName");

if (_bool) then {
    if ([true,_item,(parseNumber _val)] call life_fnc_handleInv) then {
        hint format ["You tried to give %1 %2 %3 but they couldn't hold that so it was returned.",_from getVariable ["realname",name _from],_val,(localize _type)];
    };
} else {
    if ([true,_item,(parseNumber _val)] call life_fnc_handleInv) then {
        hint format ["%1 returned %2 %3 because they couldn't hold that amount.",_from getVariable ["realname",name _from],_val,(localize _type)];
    };
};