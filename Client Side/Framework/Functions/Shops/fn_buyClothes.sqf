#include "..\..\script_macros.hpp"
/*
    File: fn_buyClothes.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Buys the current set of clothes and closes out of the shop interface.
*/
private ["_price"];
if ((lbCurSel 3101) isEqualTo -1) exitWith {titleText["You didn't choose the clothes you wanted to buy.","PLAIN"];};

_price = 0;
{
    if (!(_x isEqualTo -1)) then {
        _price = _price + _x;
    };
} forEach life_clothing_purchase;

if (_price > CASH) exitWith {titleText["Sorry, you don't have enough money to buy those clothes.","PLAIN"];};
CASH = CASH - _price;
[0] call SOCK_fnc_updatePartial;

life_clothesPurchased = true;
[player, uniformContainer player, ((uniformContainer player) getVariable ["texture", ""])] call ULP_fnc_setTextures;
closeDialog 0;