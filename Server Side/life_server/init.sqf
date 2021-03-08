#include "script_macros.hpp"
/*
    File: init.sqf
    Author: Bryan "Tonic" Boardwine

    Edit: Nanou for HeadlessClient optimization.
    Please read support for more informations.

    Description:
    Initialize the server and required systems.
*/
DB_Async_Active = false;
DB_Async_ExtraLock = false;

life_server_isReady = false;
publicVariable "life_server_isReady";

private _extDBNotLoaded = "";

/*
    Prepare extDB before starting the initialization process
    for the server.
*/

if (isNil {uiNamespace getVariable "life_sql_id"}) then {
    life_sql_id = round(random(9999));
    CONSTVAR(life_sql_id);
    uiNamespace setVariable ["life_sql_id",life_sql_id];
        try {
        _result = EXTDB format ["9:ADD_DATABASE:%1",EXTDB_SETTING(getText,"DatabaseName")];
        if (!(_result isEqualTo "[1]")) then {throw "extDB3: Error with Database Connection"};
        _result = EXTDB format ["9:ADD_DATABASE_PROTOCOL:%2:SQL:%1:TEXT2",FETCH_CONST(life_sql_id),EXTDB_SETTING(getText,"DatabaseName")];
        if (!(_result isEqualTo "[1]")) then {throw "extDB3: Error with Database Connection"};
    } catch {
        diag_log _exception;
        _extDBNotLoaded = [true, _exception];
    };
    if (_extDBNotLoaded isEqualType []) exitWith {};
    EXTDB "9:LOCK";
    diag_log "extDB3: Connected to Database";
} else {
    life_sql_id = uiNamespace getVariable "life_sql_id";
    CONSTVAR(life_sql_id);
    diag_log "extDB3: Still Connected to Database";
};


if (_extDBNotLoaded isEqualType []) exitWith {
    life_server_extDB_notLoaded = true;
    publicVariable "life_server_extDB_notLoaded";
};
life_server_extDB_notLoaded = false;
publicVariable "life_server_extDB_notLoaded";

{
    [format["CALL %1", _x], 1] call DB_fnc_asyncCall;
} forEach ["resetVehicles", "deleteOldGroups"];

ULP_SRV_Date = ([] call ULP_SRV_fnc_getLocalTime);
ULP_SRV_Date resize 3; // We only need Year, Month, Day

private _timeStamp = diag_tickTime;
["Initialisation Started"] call ULP_fnc_logIt;

/* Map-based server side initialization. */

{
    removeAllWeapons _x;
} forEach (allUnits select {
    !(isPlayer _x)
});

[8, true, 12] execFSM "\life_server\FSM\timeModule.fsm";

/* Event handler for disconnecting players */
addMissionEventHandler ["HandleDisconnect",{_this call TON_fnc_clientDisconnect; false;}];

/* Miscellaneous mission-required stuff */

cleanupFSM = [] execFSM "\life_server\FSM\cleanup.fsm";
cleanup = [] spawn TON_fnc_cleanup;

TON_fnc_playtime_values = [];
TON_fnc_playtime_values_request = [];

//Just incase the Headless Client connects before anyone else
publicVariable "TON_fnc_playtime_values";
publicVariable "TON_fnc_playtime_values_request";

/* Tell clients that the server is ready and is accepting queries */
life_server_isReady = true;
publicVariable "life_server_isReady";

addMissionEventHandler ["EntityRespawned", {_this call TON_fnc_entityRespawned}];

[format["Initialisation Lasted %1s", diag_tickTime - _timeStamp]] call ULP_fnc_logIt;