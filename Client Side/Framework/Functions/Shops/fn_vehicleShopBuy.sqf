#include "..\..\script_macros.hpp"
/*
    File: fn_vehicleShopBuy.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Does something with vehicle purchasing.
*/

params [["_mode",true,[true]]];

if ((lbCurSel 2302) isEqualTo -1) exitWith {hint "You did not pick a vehicle!";closeDialog 0;};
if ((time - life_action_delay) < 0.2) exitWith {hint "You're doing it too fast!";};
life_action_delay = time;

private _className = lbData[2302,(lbCurSel 2302)];
private _vIndex = lbValue[2302,(lbCurSel 2302)];
private _vehicleList = M_CONFIG(getArray,"CarShops",(life_veh_shop select 0),"vehicles");
private _shopSide = M_CONFIG(getText,"CarShops",(life_veh_shop select 0),"side");


private _initalPrice = M_CONFIG(getNumber,"LifeCfgVehicles",_className,"price");

private "_buyMultiplier";
private "_rentMultiplier";

switch (playerSide) do {
    case civilian: {
        _buyMultiplier = LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_CIVILIAN");
        _rentMultiplier = LIFE_SETTINGS(getNumber,"vehicle_rental_multiplier_CIVILIAN");
    };
    case west: {
        _buyMultiplier = LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_COP");
        _rentMultiplier = LIFE_SETTINGS(getNumber,"vehicle_rental_multiplier_COP");
    };
    case independent: {
        _buyMultiplier = LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_MEDIC");
        _rentMultiplier = LIFE_SETTINGS(getNumber,"vehicle_rental_multiplier_MEDIC");
    };
    case east: {
        _buyMultiplier = LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier_OPFOR");
        _rentMultiplier = LIFE_SETTINGS(getNumber,"vehicle_rental_multiplier_OPFOR");
    };
};

private "_purchasePrice";

if (_mode) then {
    _purchasePrice = round(_initalPrice * _buyMultiplier);
} else {
    _purchasePrice = round(_initalPrice * _rentMultiplier);
};

private _conditions = M_CONFIG(getText,"LifeCfgVehicles",_className,"conditions");

if !([_conditions] call life_fnc_levelCheck) exitWith {hint "You do not have the required license and/or level!";};

private _colorIndex = lbValue[2304,(lbCurSel 2304)];

if (_purchasePrice < 0) exitWith {closeDialog 0;}; //Bad price entry
if (CASH < _purchasePrice) exitWith {hint format ["You do not have enough money to purchase this vehicle.\n\nAmount Lacking: £%1",[_purchasePrice - CASH] call life_fnc_numberText];closeDialog 0;};

private _spawnPoints = life_veh_shop select 1;
private _spawnPoint = "";

if ((life_veh_shop select 0) == "med_air_hs") then {
    if (nearestObjects[(getMarkerPos _spawnPoints),["Air"],35] isEqualTo []) exitWith {_spawnPoint = _spawnPoints};
} else {
    //Check if there is multiple spawn points and find a suitable spawnpoint.
    if (_spawnPoints isEqualType []) then {
        //Find an available spawn point.
        {
            if ((nearestObjects[(getMarkerPos _x),["Car","Ship","Air"],5]) isEqualTo []) exitWith {_spawnPoint = _x};
            true
        } count _spawnPoints;
    } else {
        if (nearestObjects[(getMarkerPos _spawnPoints),["Car","Ship","Air"],5] isEqualTo []) exitWith {_spawnPoint = _spawnPoints};
    };
};


if (_spawnPoint isEqualTo "") exitWith {hint "There is a vehicle currently blocking the spawn point"; closeDialog 0;};
CASH = CASH - _purchasePrice;
[0] call SOCK_fnc_updatePartial;
if (_mode) then {
    hint format ["You bought a %1 for £%2",getText(configFile >> "CfgVehicles" >> _className >> "displayName"),[_purchasePrice] call life_fnc_numberText];
} else {
    hint format ["You rented a %1 for £%2",getText(configFile >> "CfgVehicles" >> _className >> "displayName"),[_purchasePrice] call life_fnc_numberText];
};

//Spawn the vehicle and prep it.

private "_vehicle";

if ((life_veh_shop select 0) == "med_air_hs") then {
    _vehicle = createVehicle [_className,[0,0,999],[], 0, "NONE"];
    waitUntil {!isNil "_vehicle" && {!isNull _vehicle}}; //Wait?
    _vehicle allowDamage false;
    _hs = nearestObjects[getMarkerPos _spawnPoint,["Land_Hospital_side2_F"],50] select 0;
    _vehicle setPosATL (_hs modelToWorld [-0.4,-4,12.65]);
    sleep 0.6;
} else {
    _vehicle = createVehicle [_className, (getMarkerPos _spawnPoint), [], 0, "NONE"];
    waitUntil {!isNil "_vehicle" && {!isNull _vehicle}}; //Wait?
    _vehicle allowDamage false; //Temp disable damage handling..
    _vehicle setPos (getMarkerPos _spawnPoint);
    _vehicle setVectorUp (surfaceNormal (getMarkerPos _spawnPoint));
    _vehicle setDir (markerDir _spawnPoint);
};

_vehicle lock 2;

[_vehicle,_colorIndex] call life_fnc_colorVehicle;
[_vehicle] call life_fnc_clearVehicleAmmo;

_vehicle setVariable ["trunk_in_use",false,true];
_vehicle setVariable ["vehicle_info_owners",[[getPlayerUID player,profileName]],true];

_vehicle disableTIEquipment true; //No Thermals.. They're cheap but addictive.

//Side Specific actions.
switch (playerSide) do {
    case west: {
        [_vehicle,"cop_offroad",true] spawn life_fnc_vehicleAnimate;
    };
    case civilian: {
        if ((life_veh_shop select 2) isEqualTo "civ" && {_className == "B_Heli_Light_01_F"}) then {
            [_vehicle,"civ_littlebird",true] spawn life_fnc_vehicleAnimate;
        };
    };
    case independent: {
        [_vehicle,"med_offroad",true] spawn life_fnc_vehicleAnimate;
    };
};

_vehicle allowDamage true;

life_vehicles pushBack _vehicle;

//Always handle key management by the server
[getPlayerUID player,playerSide,_vehicle,1] remoteExecCall ["TON_fnc_keyManagement",RSERV];

if (_mode) then {
    if !(_className in LIFE_SETTINGS(getArray,"vehicleShop_rentalOnly")) then {
        if (life_HC_isActive) then {
            [(getPlayerUID player),playerSide,_vehicle,_colorIndex] remoteExecCall ["HC_fnc_vehicleCreate",HC_Life];
        } else {
            [(getPlayerUID player),playerSide,_vehicle,_colorIndex] remoteExecCall ["TON_fnc_vehicleCreate",RSERV];
        };
    };
};

if (LIFE_SETTINGS(getNumber,"player_advancedLog") isEqualTo 1) then {
    if (LIFE_SETTINGS(getNumber,"battlEye_friendlyLogging") isEqualTo 1) then {
        advanced_log = format ["bought vehicle %1 for £%2. On Hand Cash: £%3  Bank Balance: £%4",_className,[_purchasePrice] call life_fnc_numberText,[CASH] call life_fnc_numberText,[BANK] call life_fnc_numberText];
    } else {
        advanced_log = format ["%1 - %2 bought vehicle %3 for £%4. On Hand Cash: £%5  Bank Balance £%6",profileName,(getPlayerUID player),_className,[_purchasePrice] call life_fnc_numberText,[CASH] call life_fnc_numberText,[BANK] call life_fnc_numberText];
    };
    publicVariableServer "advanced_log";
};

closeDialog 0; //Exit the menu.
true;
