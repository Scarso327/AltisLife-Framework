#include "..\..\script_macros.hpp"
/*
    File: fn_placeContainer.sqf
    Author: NiiRoZz
    Credits: BoGuu

    Description:
    Check container if are in house and if house are owner of player and if all this conditions are true add container in database
*/
private ["_container","_isFloating","_type","_house","_containers","_houseCfg","_message","_isPlaced"];
params [
        ["_container",objNull,[objNull]],
        ["_isFloating",true,[true]]
];

_uid = getPlayerUID player;
_house = nearestObject [player, "House"];

switch (true) do {
    case (typeOf _container isEqualTo "B_supplyCrate_F"): {_type = "large_container"};
    case (typeOf _container isEqualTo "Box_IND_Grenades_F") : {_type = "small_container"};
    default {_type = ""};
};

_message = 0;
_isPlaced = false;
if (!isNull _house) then {
    _message = 1;
    if (([player] call life_fnc_playerInBuilding) && {([_container] call life_fnc_playerInBuilding)}) then {
        _message = 2;
        if ((_house in life_vehicles) && !(isNil {_house getVariable "house_owner"})) then {
            _message = 3;
            if (!_isFloating) then {
                _message = 4;
                _containers = _house getVariable ["containers",[]];
                _houseCfg = [(typeOf _house)] call life_fnc_houseConfig;
                if (_houseCfg isEqualTo []) exitWith {};
                if (count _containers < (_houseCfg select 1)) then {
                    _isPlaced = true;
                    if (life_HC_isActive) then {
                        [_uid,_container] remoteExec ["HC_fnc_addContainer",HC_Life];
                    } else {
                        [_uid,_container] remoteExec ["TON_fnc_addContainer",RSERV];
                    };
                    _container setVariable ["Trunk",[[],0],true];
                    _container setVariable ["container_owner",[_uid],true];
                    _containers pushBack _container;
                    _house setVariable ["containers",_containers,true];
                    sleep 1;
                };
            };
        };
    };
};

if (_isPlaced) exitWith {};

deleteVehicle _container;
[true,_type,1] call life_fnc_handleInv;

if (_message isEqualTo 0 || _message isEqualTo 1) then {
    hint "There are no houses near you.";
};
if (_message isEqualTo 2) then {
    hint "You are not the owner of the house.";
};
if (_message isEqualTo 3) then {
    hint "The storage box is over the stairs!";
};
if (_message isEqualTo 4) then {
    hint "You cannot place any more storage containers in your house.";
};