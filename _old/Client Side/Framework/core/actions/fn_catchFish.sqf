#include "..\..\script_macros.hpp"
/*
    File: fn_catchFish.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Catches a fish that is near by.
*/
private ["_fish","_type","_typeName"];
_fish = [_this,0,objNull,[objNull]] call BIS_fnc_param;
if (isNull _fish) exitWith {}; //Object passed is null?
if (player distance _fish > 3.5) exitWith {};

switch (true) do {
    case ((typeOf _fish) isEqualTo "Salema_F"): {_typeName = "Salema"; _type = "raw_salema";};
    case ((typeOf _fish) isEqualTo "Ornate_random_F") : {_typeName = "Ornate"; _type = "raw_ornate";};
    case ((typeOf _fish) isEqualTo "Mackerel_F") : {_typeName = "Mackerel"; _type = "raw_mackerel";};
    case ((typeOf _fish) isEqualTo "Tuna_F") : {_typeName = "Tuna"; _type = "raw_tuna";};
    case ((typeOf _fish) isEqualTo "Mullet_F") : {_typeName = "Mullet"; _type = "raw_mullet";};
    case ((typeOf _fish) isEqualTo "CatShark_F") : {_typeName = "Catshark"; _type = "raw_catshark";};
    case ((typeOf _fish) isEqualTo "Turtle_F") : {_typeName = "Turtle"; _type = "raw_turtle";};
    default {_type = ""};
};

if (_type isEqualTo "") exitWith {}; //Couldn't get a type

if ([true,_type,1] call life_fnc_handleInv) then {
    deleteVehicle _fish;
    titleText[format [("You caught a %1."),_typeName],"PLAIN"];
};