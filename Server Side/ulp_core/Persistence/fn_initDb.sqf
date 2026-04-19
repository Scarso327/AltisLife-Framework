/*
    Description:
    Initialize extdb connection
*/
#include "\ulp_core\script_macros.hpp"
scopeName "fn_initDb";

["Getting database connection..."] call ULP_fnc_logIt;

private _extDBNotLoaded = "";

if (isNil { PREF_NAMESPACE getVariable "ULP_SQL_ID" }) then {

    ULP_SQL_ID = round(random(9999));
    CONSTVAR(ULP_SQL_ID);

    PREF_NAMESPACE setVariable ["ULP_SQL_ID", ULP_SQL_ID];

	try {
        _result = EXTDB format ["9:ADD_DATABASE:%1", EXTDB_SETTING(getText,"DatabaseName")];

        if !(_result isEqualTo "[1]") then {
			throw "extDB3: Error with Database Connection"
		};

        _result = EXTDB format ["9:ADD_DATABASE_PROTOCOL:%2:SQL:%1:TEXT2", FETCH_CONST(ULP_SQL_ID), EXTDB_SETTING(getText,"DatabaseName")];

        if !(_result isEqualTo "[1]") then {
			throw "extDB3: Error with Database Connection"
		};
    } catch {
        diag_log _exception;
        _extDBNotLoaded = [true, _exception];
    };

    if (_extDBNotLoaded isEqualType []) exitWith {};

    EXTDB "9:LOCK";
	["extDB3: Connected to database."] call ULP_fnc_logIt;
} else {
    ULP_SQL_ID = PREF_NAMESPACE getVariable "ULP_SQL_ID";
    CONSTVAR(ULP_SQL_ID);

	["extDB3: Already connected to database."] call ULP_fnc_logIt;
};

if (_extDBNotLoaded isEqualType []) exitWith { false };

true