/*
    File: fn_queryPlayerGang.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Queries to see if the player belongs to any gang.
*/
params [
    ["_gangID", -1, [0]]
];

private _queryResult = [format ["SELECT id, owner, name, maxmembers, bank FROM gangs WHERE active='1' AND id='%1'", _gangID],2] call DB_fnc_asyncCall;

if !(count _queryResult isEqualTo 0) then {
    // Members
    private _members = [format["SELECT name, pid FROM players WHERE gangid = '%1'", _queryResult select 1], 2, true] call DB_fnc_asyncCall;
    _queryResult set [5, _members];
};

life_gangLoaded = true;
_queryResult