#include "..\..\script_macros.hpp"
/*
    File: fn_virt_menu.sqf
    Author: Bryan "Tonic" Boardwine
    Description:
    Initialize the virtual shop menu.
*/

params [
    ["_shopNPC", objNull, [objNull]],
    "",
    "",
    ["_shopType", "", [""]]
];

if (isNull _shopNPC || {_shopType isEqualTo ""}) exitWith {};

life_shop_type = _shopType;
life_shop_npc = _shopNPC;

private _conditions = M_CONFIG(getText,"CfgShops",_shopType,"conditions");

if !([_conditions] call life_fnc_levelCheck) exitWith {hint "You are not allowed to use this shop!";};

createDialog "shops_menu";

[] call life_fnc_virt_update;