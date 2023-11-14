/*
** Author: Bryan "Tonic" Boardwine
** Editor: Jack "Scarso" Farhall (Optmisation + Cleanup)
** Description: Commits an asynchronous call to ExtDB
**
** Parameters:
**  0: STRING (Query to be ran).
**  1: INTEGER (1 = ASYNC + not return for update/insert, 2 = ASYNC + return for query's).
**  2: BOOL (True to return a single array, false to return multiple entries mainly for garage).
*/
#include "\life_server\script_macros.hpp"

_this params [
    ["_statement", "", [""]],
    ["_mode", 1, [0]],
    ["_multi", false, [true]]
];

private _key = EXTDB format ["%1:%2:%3", _mode, FETCH_CONST(life_sql_id), _statement];

if (_mode isEqualTo 1) exitWith {
    if !(isNil { ULP_DebugMode }) then {
        [format["fn_asyncCall: STATEMENT: '%1'", _statement]] call ULP_fnc_logIt;
    };

    true
};

_key = (parseSimpleArray format ["%1", _key]) select 1;
private _result = EXTDB format ["4:%1", _key];

if (_result isEqualTo "[3]") then {
    for "_i" from 0 to 1 step 0 do {
        if !(_result isEqualTo "[3]") exitWith {};
        _result = EXTDB format ["4:%1", _key];
    };
};

if (_result isEqualTo "[5]") then {
    private _loop = true;

    // extDB3 returned that result is Multi-Part Message
    for "_i" from 0 to 1 step 0 do {
        _result = "";

        for "_i" from 0 to 1 step 0 do {
            _pipe = EXTDB format ["5:%1", _key];
            if (_pipe isEqualTo "") exitWith { _loop = false };
            _result = _result + _pipe;
        };

        if !(_loop) exitWith {};
    };
};

if !(isNil { ULP_DebugMode }) then {
    [format["fn_asyncCall: STATEMENT: '%1' RESULT: '%2'", _statement, _result]] call ULP_fnc_logIt;
};

_result = parseSimpleArray _result;

if ((_result select 0) isEqualTo 0) exitWith { diag_log format ["extDB3: Protocol Error: %1", _result]; []};

private _return = (_result select 1);

if (!_multi && { (count _return) > 0 }) then {
    _return = (_return select 0);
};

_return