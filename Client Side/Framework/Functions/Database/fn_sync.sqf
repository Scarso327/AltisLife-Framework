/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_sync";

if ([player] call ULP_fnc_onDuty) exitWith {
	["You can't sync data while on duty as an admin!"] call ULP_fnc_hint;
};

if (time <= (ULP_Last_Sync + getNumber(missionConfigFile >> "CfgSettings" >> "sync_delay"))) exitWith {
	["Your data has been synced recently, you must wait between automatic and manual syncs..."] call ULP_fnc_hint;
};

[] call ULP_fnc_syncPlayerInfo;
ULP_Last_Sync = time;

["Syncing player information to the server.\n\nPlease wait up to 20 seconds before leaving..."] call ULP_fnc_hint;