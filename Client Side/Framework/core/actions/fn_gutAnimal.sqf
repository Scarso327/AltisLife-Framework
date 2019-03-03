#include "..\..\script_macros.hpp"
/*
    File: fn_gutAnimal.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Guts the animal?
*/
private ["_animalCorpse","_upp","_ui","_progress","_pgText","_cP","_displayName","_item"];
_animalCorpse = param [0,objNull,[objNull]];
if (isNull _animalCorpse) exitWith {}; //Object passed is null?

life_interrupted = false;
if (player distance _animalCorpse > 3.5) exitWith {}; //WTF need check with nearest objects I love Arma
life_action_inUse = true;

switch (typeOf _animalCorpse) do {
    case "Hen_random_F": {_displayName = "Chicken"; _item = "raw_hen";};
    case "Cock_random_F": {_displayName = "Rooster"; _item = "raw_rooster";};
    case "Goat_random_F": {_displayName = "Goat"; _item = "raw_goat";};
    case "Sheep_random_F": {_displayName = "Sheep"; _item = "raw_sheep";};
    case "Rabbit_F": {_displayName = "Rabbit"; _item = "raw_rabbit";};
    default {_displayName = ""; _item = "";};
};

if (_displayName isEqualTo "") exitWith {life_action_inUse = false;};

_upp = format ["Gutting %1...",_displayName];
//Setup our progress bar.
disableSerialization;
"progressBar" cutRsc ["life_progress","PLAIN"];
_ui = uiNamespace getVariable "life_progress";
_progress = _ui displayCtrl 38201;
_pgText = _ui displayCtrl 38202;
_pgText ctrlSetText format ["%2 (1%1)...","%",_upp];
_progress progressSetPosition 0.01;
_cP = 0.01;

for "_i" from 0 to 1 step 0 do {
    if (animationState player != "AinvPknlMstpSnonWnonDnon_medic_1") then {
        [player,"AinvPknlMstpSnonWnonDnon_medic_1",true] remoteExecCall ["life_fnc_animSync",RCLIENT];
        player switchMove "AinvPknlMstpSnonWnonDnon_medic_1";
        player playMoveNow "AinvPknlMstpSnonWnonDnon_medic_1";
    };
    uiSleep 0.15;
    _cP = _cP + 0.01;
    _progress progressSetPosition _cP;
    _pgText ctrlSetText format ["%3 (%1%2)...",round(_cP * 100),"%",_upp];
    if (_cP >= 1) exitWith {};
    if (!alive player) exitWith {};
    if (isNull _animalCorpse) exitWith {};
    if !(isNull objectParent player) exitWith {};
    if (life_interrupted) exitWith {};
};

life_action_inUse = false;
"progressBar" cutText ["","PLAIN"];
player playActionNow "stop";
if (isNull _animalCorpse) exitWith {life_action_inUse = false;};
if (life_interrupted) exitWith {life_interrupted = false; titleText["Action Cancelled.","PLAIN"]; life_action_inUse = false;};
if !(isNull objectParent player) exitWith {titleText["You cannot do this while you are in a vehicle.","PLAIN"];};

if ([true,_item,1] call life_fnc_handleInv) then {
    deleteVehicle _animalCorpse;
    titleText[format [("You have collected some raw %1 meat."),_displayName],"PLAIN"];
} else {
    titleText[("Your inventory space is full."),"PLAIN"];
};