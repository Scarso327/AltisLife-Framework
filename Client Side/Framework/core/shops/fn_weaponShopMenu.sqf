#include "..\..\script_macros.hpp"
/*
    File: fn_weaponShopMenu.sqf
    Author: Bryan "Tonic" Boardwine
    Description:
    Something
*/
private _shopTitle = M_CONFIG(getText,"CfgWeapons",(_this select 3),"name");
private _conditions = M_CONFIG(getText,"CfgWeapons",(_this select 3),"conditions");

_exit = [_conditions] call life_fnc_levelCheck;
if !(_exit) exitWith {hint localize "STR_Shop_Veh_NotAllowed";};

uiNamespace setVariable ["Weapon_Shop",(_this select 3)];
uiNamespace setVariable ["Weapon_Magazine",0];
uiNamespace setVariable ["Weapon_Accessories",0];
uiNamespace setVariable ["Magazine_Array",[]];
uiNamespace setVariable ["Accessories_Array",[]];

if !(createDialog "life_weapon_shop") exitWith {};
if (!isClass(missionConfigFile >> "CfgWeapons" >> (_this select 3))) exitWith {systemChat (_this select 3); closeDialog 0}; //Bad config entry.

disableSerialization;

ctrlSetText[38401,_shopTitle];

private _filters = ((findDisplay 38400) displayCtrl 38402);
lbClear _filters;

ctrlShow [38406,true];
ctrlEnable [38406,false];
ctrlShow [38407,true];
ctrlEnable [38407,false];

_filters lbAdd localize "STR_Shop_Weapon_ShopInv";
_filters lbAdd localize "STR_Shop_Weapon_YourInv";

_filters lbSetCurSel 0;