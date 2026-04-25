/*
    Description:
    Initialize the server and required systems.
*/
#include "script_macros.hpp"

["Initialising ULP Core..."] call ULP_fnc_logIt;

private _dbLoaded = [] call ULP_DB_fnc_initDb;

if !(_dbLoaded) exitWith {
    ["Failed to connect to database. Check logs for more info."] call ULP_fnc_logIt;

    false
};

true