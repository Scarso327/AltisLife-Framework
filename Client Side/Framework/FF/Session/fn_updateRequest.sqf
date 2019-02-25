#include "..\..\script_macros.hpp"
/*
    File: fn_updateRequest.sqf
    Author: Tonic

    Description:
    Passes ALL player information to the server to save player data to the database.
*/
private ["_packet","_array","_flag","_alive","_position"];
_packet = [getPlayerUID player,(profileName),playerSide,CASH,BANK];
_array = [];
private _professions = [];
_alive = alive player;
_position = getPosATL player;
_flag = switch (playerSide) do {case west: {"cop"}; case civilian: {"civ"}; case independent: {"med"};};

{
    _varName = LICENSE_VARNAME(configName _x,_flag);
    _array pushBack [_varName,LICENSE_VALUE(configName _x,_flag)];
} forEach (format ["getText(_x >> 'side') isEqualTo '%1'",_flag] configClasses (missionConfigFile >> "CfgLicenses"));

{
    private _side = switch (playerSide) do {case west: {"Police"}; case independent: {"NHS"}; case civilian : {"Civ"}; default {"Unknown"};};
    if((getText(_x >> "side")) isEqualTo _side) then {
        _varName = PROF_VARNAME(configName _x);
        _professions pushBack [_varName,PROF_VALUE(configName _x)];
    };
} foreach ("true" configClasses (missionConfigFile >> "CfgProfessions"));

_packet pushBack _array;

[] call life_fnc_saveGear;
_packet pushBack life_gear;

_array = [];
_array pushBack life_hunger;
_array pushBack life_thirst;
_array pushBack (damage player);
_packet pushBack _array;

_packet pushBack _professions;

// Level Stuff...
_packet pushBack [FF_Level, FF_XP];

switch (playerSide) do {
    case civilian: {
        _packet pushBack life_is_arrested;
        _packet pushBack _alive;
        _packet pushBack _position;
    };
};

if (life_HC_isActive) then {
    _packet remoteExecCall ["HC_fnc_updateRequest",HC_Life];
} else {
    _packet remoteExecCall ["DB_fnc_updateRequest",RSERV];
};

[] call FF_fnc_hudUpdate;