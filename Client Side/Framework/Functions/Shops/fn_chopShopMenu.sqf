#include "..\..\script_macros.hpp"
/*
    File: fn_chopShopMenu.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Opens & initializes the chop shop menu.
*/
if (life_action_inUse) exitWith {hint "An action is already being processed..."};
if !(playerSide isEqualTo civilian) exitWith {hint "Your faction is not allowed to chop vehicles!"};

disableSerialization;

private _chopable = LIFE_SETTINGS(getArray,"chopShop_vehicles");
private _nearVehicles = nearestObjects [getMarkerPos (_this select 3),_chopable,25];
private _nearUnits = (nearestObjects[player,["CAManBase"],5]) arrayIntersect playableUnits;
if (count _nearUnits > 1) exitWith {hint "You can't chop a vehicle while a player is near!"};

life_chopShop = _this select 3;
//Error check
if (_nearVehicles isEqualTo []) exitWith {titleText["There are no vehicles near to sell.","PLAIN"];};
if (!(createDialog "Chop_Shop")) exitWith {hint "There was a problem opening the chop shop menu."};

private _control = CONTROL(39400,39402);
private "_className";
private "_displayName";
private "_picture";
private "_price";
private "_chopMultiplier";
{
    if (alive _x) then {
        _className = typeOf _x;
        _displayName = getText(configFile >> "CfgVehicles" >> _className >> "displayName");
        _picture = getText(configFile >> "CfgVehicles" >> _className >> "picture");

        if (!isClass (missionConfigFile >> "LifeCfgVehicles" >> _className)) then {
            diag_log format ["%1: LifeCfgVehicles class doesn't exist",_className];
            _className = "Default"; //Use Default class if it doesn't exist
        };

        _price = M_CONFIG(getNumber,"LifeCfgVehicles",_className,"price");
        _chopMultiplier = LIFE_SETTINGS(getNumber,"vehicle_chopShop_multiplier");

        _price = _price * _chopMultiplier;
        if (!isNil "_price" && count crew _x isEqualTo 0) then {
            _control lbAdd _displayName;
            _control lbSetData [(lbSize _control)-1,(netId _x)];
            _control lbSetPicture [(lbSize _control)-1,_picture];
            _control lbSetValue [(lbSize _control)-1,_price];
        };
    };
} forEach _nearVehicles;
