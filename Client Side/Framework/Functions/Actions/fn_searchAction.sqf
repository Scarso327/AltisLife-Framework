/*
    File: fn_searchAction.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Starts the searching process.
*/
params [
    ["_unit",objNull,[objNull]]
];
if (isNull _unit) exitWith {};
hint "Searching...";
sleep 2;
if (player distance _unit > 5 || !alive player || !alive _unit) exitWith {hint "Cannot search that person."};
[player] remoteExec ["life_fnc_searchClient",_unit];
life_action_inUse = true;