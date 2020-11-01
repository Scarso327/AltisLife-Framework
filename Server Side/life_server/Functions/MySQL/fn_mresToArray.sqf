/*
    File: fn_mresToArray.sqf
    Author: Bryan "Tonic" Boardwine";

    Description:
    Acts as a mres (MySQL Real Escape) for arrays so they
    can be properly inserted into the database without causing
    any problems. The return method is 'hacky' but it's effective.
*/
if !(_this params [["_array", "", [""]]]) exitWith {[]};

private _array = call compile (format ["%1", toString (toArray(_array) apply {[_x, 39] select (_x isEqualTo 96)})]);
if (_array isEqualType "") then { _array = parseSimpleArray _array };
_array