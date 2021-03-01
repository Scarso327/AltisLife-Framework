/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_stripGear";

removeAllWeapons player;
{ player removeMagazine _x; } forEach (magazines player);
removeUniform player;
removeVest player;
removeBackpack player;
removeGoggles player;
removeHeadGear player;

{
    player unassignItem _x;
    player removeItem _x;
} forEach (assignedItems player);

if (hmd player != "") then {
    player unlinkItem (hmd player);
};