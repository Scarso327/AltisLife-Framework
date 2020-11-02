#include "..\..\script_macros.hpp"
/*
    File: fn_garageLBChange.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Can't be bothered to answer it.. Already deleted it by accident..
*/
disableSerialization;
private ["_control","_index","_className","_classNameLife","_dataArr","_vehicleColor","_vehicleInfo","_trunkSpace","_sellPrice","_retrievePrice","_sellMultiplier","_price","_storageFee","_purchasePrice"];
_control = _this select 0;
_index = _this select 1;

//Fetch some information.
_dataArr = CONTROL_DATAI(_control,_index);
_dataArr = call compile format ["%1",_dataArr];
_className = (_dataArr select 0);
_classNameLife = _className;

if (!isClass (missionConfigFile >> "LifeCfgVehicles" >> _classNameLife)) then {
    _classNameLife = "Default"; //Use Default class if it doesn't exist
    diag_log format ["%1: LifeCfgVehicles class doesn't exist",_className];
};

_vehicleColor = ((M_CONFIG(getArray,"LifeCfgVehicles",_classNameLife,"textures") select (_dataArr select 1)) select 0);
if (isNil "_vehicleColor") then {_vehicleColor = "Default";};

_vehicleInfo = [_className] call life_fnc_fetchVehInfo;
_trunkSpace = [_className] call life_fnc_vehicleWeightCfg;

_price = M_CONFIG(getNumber,"LifeCfgVehicles",_classNameLife,"price");
_storageFee = LIFE_SETTINGS(getNumber,"vehicle_storage_fee_multiplier");

switch (playerSide) do {
    case civilian: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier");
    };
    case west: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier");
    };
    case independent: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier");
    };
    case east: {
        _purchasePrice = _price * LIFE_SETTINGS(getNumber,"vehicle_purchase_multiplier");
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier");
    };
};
_retrievePrice = _purchasePrice * _storageFee;
_sellPrice = _purchasePrice * _sellMultiplier;

if (!(_sellPrice isEqualType 0) || _sellPrice < 1) then {_sellPrice = 500;};
if (!(_retrievePrice isEqualType 0) || _retrievePrice < 1) then {_retrievePrice = 500;};

(CONTROL(2800,2803)) ctrlSetStructuredText parseText format [
    ("Retrieval Price:")+ " <t color='#8cff9b'>£%1</t><br/>
    " +("Sell Price:")+ " <t color='#8cff9b'>£%2</t><br/>
    " +("Color:")+ " %8<br/>
    " +("Max Speed:")+ " %3 km/h<br/>
    " +("Horse Power:")+ " %4<br/>
    " +("Passengers:")+ " %5<br/>
    " +("Storage Space:")+ " %6<br/>
    " +("Fuel Tank:")+ " %7
    ",
[_retrievePrice] call life_fnc_numberText,
[_sellPrice] call life_fnc_numberText,
(_vehicleInfo select 8),
(_vehicleInfo select 11),
(_vehicleInfo select 10),
if (_trunkSpace isEqualTo -1) then {"None"} else {_trunkSpace},
(_vehicleInfo select 12),
_vehicleColor
];

ctrlShow [2803,true];
ctrlShow [2830,true];
