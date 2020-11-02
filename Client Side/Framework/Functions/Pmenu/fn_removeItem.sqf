#include "..\..\script_macros.hpp"
/*
    File: fn_removeItem.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Removes the selected item & amount to remove from the players
    virtual inventory.
*/
private ["_data","_value","_obj"];
disableSerialization;
_data = lbData[2005,(lbCurSel 2005)];
_value = ctrlText 2010;

if (_data isEqualTo "") exitWith {hint "You did not select anything to remove.";};
if (!([_value] call TON_fnc_isnumber)) exitWith {hint "You didn't enter an actual number format.";};
if (parseNumber(_value) <= 0) exitWith {hint "You need to enter an actual amount you want to remove.";};
if (ITEM_ILLEGAL(_data) isEqualTo 1 && ([west,visiblePosition player,100] call life_fnc_nearUnits)) exitWith {titleText["This is an illegal item and cops are near by. You cannot dispose of the evidence.","PLAIN"]};
if !(isNull objectParent player) exitWith {titleText["You cannot remove an item when you are in a vehicle.","PLAIN"]};
if (!([false,_data,(parseNumber _value)] call life_fnc_handleInv)) exitWith {hint "Could not remove that much of that item. Maybe you do not have that amount?";};

hint format ["You have successfully removed %1 %2 from your inventory.",(parseNumber _value),(localize ITEM_NAME(_data))];

[] call life_fnc_p_updateMenu;
