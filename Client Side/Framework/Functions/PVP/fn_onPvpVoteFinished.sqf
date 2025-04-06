/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onPvpVoteFinished";

if !(hasInterface) exitWith {};

missionNamespace setVariable ["ULP_PVPModes", nil];