#include "..\..\script_macros.hpp"
/*
    File: fn_syncData.sqf
    Author: Bryan "Tonic" Boardwine"

    Description:
    Used for player manual sync to the server.
*/
_fnc_scriptName = "Player Synchronization";
if (isNil "life_session_time") then {life_session_time = false;};
if (life_session_time) exitWith {hint "You have already used the sync option, you can only use this feature once every 5 minutes.";};

[] call SOCK_fnc_updateRequest;
hint "Syncing player information to the server.\n\nPlease wait up to 20 seconds before leaving.";
[] spawn {
    life_session_time = true;
    sleep (5 * 60);
    life_session_time = false;
};
