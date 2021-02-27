/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_sync";

if (ULP_Last_Sync <= (ULP_Last_Sync + getNumber(missionConfigFile >> "Life_Settings" >> "sync_delay"))) exitWith {
	hint "Your data has been synced recently, you must wait 5 minutes between automatic as well as manual syncs.";
};

[] call ULP_fnc_syncPlayerInfo;
ULP_Last_Sync = time;

hint "Syncing player information to the server.\n\nPlease wait up to 20 seconds before leaving.";