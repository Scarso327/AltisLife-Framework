#include "..\..\script_macros.hpp"
/*
    File: fn_inventoryOpened.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    For the mean time it blocks the player from opening another persons backpack
*/
params [
    ["_unit", objNull, [objNull]],
    ["_container", objNull, [objNull]],
    ["_secContainer", objNull, [objNull]]
];

scopeName "main";
private _list = ["LandVehicle", "Ship", "Air"];

{
    if (isNull _x) then {false breakOut "main"};

    private _containerType = typeOf _x;

    if (FETCH_CONFIG2(getNumber, "CfgVehicles", _containerType, "isBackpack") isEqualTo 1) exitWith {
        hint "Their backpack appears to have a lock on it...";
        true breakOut "main";
    };

    if (_containerType in ["Box_IND_Grenades_F", "B_supplyCrate_F"]) exitWith {
        private _house = nearestObject [player, "House"];
        if (!(_house in life_vehicles) && {_house getVariable ["locked",true]}) exitWith {
            hint "You are not allowed to access this storage container without the owner opening it.";
            true breakOut "main";
        };
    };

    if (KINDOF_ARRAY(_x, _list)) exitWith {
        if (!(_x in life_vehicles) && {locked _x isEqualTo 2}) exitWith {
            hint "The vehicle appears to be locked and not accessable.";
            true breakOut "main";
        };
    };

    //Allow alive players who've been knocked out to be looted, just not the dead ones
    if (_x isKindOf "CAManBase" && {!alive _x}) exitWith {
        hint "You are not allowed to loot dead bodies.";
        true breakOut "main";
    };
} count [_container, _secContainer];

[] call FF(playerSkins);