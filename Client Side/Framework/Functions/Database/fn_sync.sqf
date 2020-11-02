/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_sync";

if ((time - ULP_Last_Sync) <= (5 * 60)) exitWith { hint "You have already used the sync option, you can only use this feature once every 5 minutes." };

[] call ULP_fnc_syncPlayerInfo;
ULP_Last_Sync = time;

hint "Syncing player information to the server.\n\nPlease wait up to 20 seconds before leaving.";