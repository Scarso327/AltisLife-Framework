/*
    File: fn_init.sqf
    Author: Bryan "Tonic" Boardwine

    Edit: Nanou for HeadlessClient optimization.
    Please read support for more informations.

    Description:
    Initialize the server and required systems.
*/
#include "script_macros.hpp"
DB_Async_Active = false;
DB_Async_ExtraLock = false;

life_server_isReady = false;
publicVariable "life_server_isReady";

private _extDBNotLoaded = "";

/*
    Prepare extDB before starting the initialization process
    for the server.
*/

if (isNil {serverNamespace getVariable "life_sql_id"}) then {
    life_sql_id = round(random(9999));
    CONSTVAR(life_sql_id);
    serverNamespace setVariable ["life_sql_id",life_sql_id];
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
    life_sql_id = serverNamespace getVariable "life_sql_id";
    CONSTVAR(life_sql_id);
    diag_log "extDB3: Still Connected to Database";
};

if (_extDBNotLoaded isEqualType []) exitWith {
    life_server_extDB_notLoaded = true;
    publicVariable "life_server_extDB_notLoaded";
};
life_server_extDB_notLoaded = false;
publicVariable "life_server_extDB_notLoaded";

ULP_SRV_Date = ([] call ULP_SRV_fnc_getLocalTime);
private _date = + (ULP_SRV_Date);
_date resize 3;
_date = (_date joinString "-");

private _routines = ["resetVehicles", "deleteOldGroups", "deleteOldHouses", "deleteOldWarrants", "sortPremiumGroups", "deleteOldBaseBids", "deleteOldMail", "resetWoundedPlayers"];

private _timeStamp = diag_tickTime;
["Initialisation Started"] call ULP_fnc_logIt;

["Getting Settings..."] call ULP_fnc_logIt;

private _settings = ["SELECT * FROM settings", 2, true] call DB_fnc_asyncCall;
if (_settings isEqualTo "") then { _settings = []; };

{
    private _cfg = _x;

    private _name = configName _x;

    // Attempt to get value from database or fallback to default
    private _value = ((_settings select { (_x select 1) isEqualTo (configName _cfg) }) param [0, []]) param [2, getText (_x >> "default")];

    _value = switch (getText (_x >> "type")) do {
        case "BOOL": { [parseNumber _value] call ULP_fnc_bool };
        CASE "NUMBER": {
            _value = parseNumber _value;
            if (isArray (_x >> "bounds")) exitWith {
                private _bounds = getArray (_x >> "bounds");
                ((_value min (_bounds # 1)) max (_bounds # 0))
            };

            _value
        };
        case "ARRAY": { [_value] call DB_fnc_mresToArray };
        case "HASHMAP" : { createHashMapFromArray ([_value] call DB_fnc_mresToArray) };
        default { _value };
    };

    private _varName = format["ULP_SRV_Setting_%1", _name];

    missionNamespace setVariable [_varName, 
        ([_value, [_varName, true, _value] call ULP_fnc_constant] select ([getNumber(_x >> "constant")] call ULP_fnc_bool)), 
        [getNumber(_x >> "global")] call ULP_fnc_bool];
} forEach ("isClass _x" configClasses (configFile >> "CfgPatches" >> "ULPServer" >> "Settings"));

["Checking Election Information..."] call ULP_fnc_logIt;

if (ULP_SRV_Setting_NextElection isEqualTo _date) then {
    if !(ULP_SRV_Setting_Election) then {
        ["UPDATE settings SET value = '""[]""' WHERE setting = 'Governor'", 1] call DB_fnc_asyncCall;
        ["UPDATE settings SET value = '1' WHERE setting = 'Election'", 1] call DB_fnc_asyncCall;
        missionNamespace setVariable ["ULP_SRV_Setting_Election", true, true];
    };
} else {
    if (ULP_SRV_Setting_Election) then {
        [] call ULP_SRV_fnc_handleVotes;

        ["UPDATE settings SET value = '0' WHERE setting = 'Election'", 1] call DB_fnc_asyncCall;
        [str parseText format ["UPDATE settings SET value = DATE_FORMAT(ADDDATE(CURDATE(), INTERVAL %1 DAY), '&#37;Y-&#37;c-&#37;e') WHERE setting = 'NextElection'", getNumber (missionConfigFile >> "CfgGovernment" >> "electionInternal")], 1] call DB_fnc_asyncCall;
        
        missionNamespace setVariable ["ULP_SRV_Setting_Election", false, true];

        _routines pushBack "deleteOldElection";
    };
};

["Checking Personal Goals..."] call ULP_fnc_logIt;

if !(ULP_SRV_Setting_Day isEqualTo _date) then { _routines pushBack "resetDailyGoals"; };
if !(ULP_SRV_Setting_Week isEqualTo ([] call ULP_SRV_fnc_getWeek)) then { _routines append ["resetWeeklyGoals", "resetGroupBuffs"]; };

["Running Routines..."] call ULP_fnc_logIt;

{
    [format["CALL %1", _x], 1] call DB_fnc_asyncCall;
} forEach _routines;

["Choosing Buffed Item..."] call ULP_fnc_logIt;

private _items = (("isClass _x" configClasses (missionConfigFile >> "CfgVirtualItems")) select {
    [getNumber (_x >> "Settings" >> "isEventItem")] call ULP_fnc_bool
});

if !(_items isEqualTo []) then {
    missionNamespace setVariable ["ULP_SRV_Setting_BuffedItem", configName (selectRandom _items), true];
};

[] call ULP_SRV_fnc_initRadios;
[] call ULP_SRV_fnc_initEvents;
[] call ULP_SRV_fnc_initCrimes;
(ULP_SRV_Date select 3) call ULP_SRV_fnc_initBases;
[] call ULP_SRV_fnc_initHousing;
[] call ULP_SRV_fnc_initGathering;
[] call ULP_SRV_fnc_initCartels;
[] call ULP_SRV_fnc_initServerEvents;
[] call ULP_SRV_fnc_initCommunityGoals;

[] call ULP_SRV_fnc_handleFog;
[] call ULP_SRV_fnc_handleRain;

/* Map-based server side initialization. */

{
    removeAllWeapons _x;
} forEach (allUnits select {
    !(isPlayer _x)
});

[8, true, 12] execFSM "\life_server\FSM\timeModule.fsm";

/* Miscellaneous mission-required stuff */

["Enqueuing Cleanup Script..."] call ULP_fnc_logIt;
[] call ULP_SRV_fnc_cleanup;
cleanupFSM = [] execFSM "\life_server\FSM\cleanup.fsm";

TON_fnc_playtime_values = [];
TON_fnc_playtime_values_request = [];

//Just incase the Headless Client connects before anyone else
publicVariable "TON_fnc_playtime_values";
publicVariable "TON_fnc_playtime_values_request";

ULP_FactionGroups = createHashMap;

/* Tell clients that the server is ready and is accepting queries */
life_server_isReady = true;
publicVariable "life_server_isReady";

[format["Initialisation Lasted %1s", diag_tickTime - _timeStamp]] call ULP_fnc_logIt;