#include "..\..\script_macros.hpp"
/*
    File: fn_safeOpen.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Opens the safe inventory menu.
*/
if (dialog) exitWith {}; //A dialog is already open.
life_safeObj = param [0,objNull,[objNull]];
if (isNull life_safeObj) exitWith {};
if !(playerSide isEqualTo civilian) exitWith {};
if ((life_safeObj getVariable ["safe",-1]) < 1) exitWith {hint "The safe is empty!";};
if (life_safeObj getVariable ["inUse",false]) exitWith {hint "Someone is already accessing the safe..."};
if (west countSide playableUnits < (LIFE_SETTINGS(getNumber,"hm_required_number"))) exitWith {
    hint format ["There needs to be %1 or more police officers online to continue.",(LIFE_SETTINGS(getNumber,"hm_required_number"))];
};
if (!createDialog "Federal_Safe") exitWith {"Failed Creating Dialog"};

disableSerialization;
ctrlSetText[3501,("Safe Inventory")];
[life_safeObj] call life_fnc_safeInventory;
life_safeObj setVariable ["inUse",true,true];

[life_safeObj] spawn {
    waitUntil {isNull (findDisplay 3500)};
    (_this select 0) setVariable ["inUse",false,true];
};
