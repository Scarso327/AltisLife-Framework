/*
    File: fn_mresToArray.sqf
    Author: Bryan "Tonic" Boardwine";
    
    Description:
    Acts as a mres (MySQL Real Escape) for arrays so they
    can be properly inserted into the database without causing
    any problems. The return method is 'hacky' but it's effective.
*/
if !(params [["_array", "", [""]]]) exitWith {[]};

call compile (format ["%1", toString (toArray(_array) apply {[_x, 39] select (_x isEqualTo 96)})]);