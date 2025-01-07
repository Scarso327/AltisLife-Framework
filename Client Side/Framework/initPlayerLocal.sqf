/*
** Author: 
** Description: Starts the initialization of the player.
*/
#include "script_macros.hpp"

CONST(BIS_fnc_endMission,BIS_fnc_endMission);

enableRadio false;
enableSentences false;
enableEnvironment false;
showHud false;
showChat false;
showCommandingMenu "";

[] spawn ULP_fnc_initBriefing;
[] spawn ULP_fnc_initialisation;