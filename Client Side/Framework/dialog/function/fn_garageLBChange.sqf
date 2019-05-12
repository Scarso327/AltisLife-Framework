#include "..\..\script_macros.hpp"
/*
    File: fn_garageLBChange.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Can't be bothered to answer it.. Already deleted it by accident..
*/
disableSerialization;
private ["_control","_index","_className","_classNameLife","_dataArr","_vehicleColor","_vehicleInfo","_trunkSpace","_sellPrice","_retrievePrice","_sellMultiplier","_price","_storageFee","_purchasePrice","_inventory","_inventoryShow"];
_control = _this select 0;
_index = _this select 1;

//Fetch some information.
_dataArr = CONTROL_DATAI(_control,_index);
_dataArr = call compile format ["%1",_dataArr];
_className = (_dataArr select 0);
_classNameLife = _className;
_inventory = (_dataArr select 2);
_inventoryShow = "";

if (!isClass (missionConfigFile >> "LifeCfgVehicles" >> _classNameLife)) then {
    _classNameLife = "Default"; //Use Default class if it doesn't exist
    diag_log format ["%1: LifeCfgVehicles class doesn't exist",_className];
};

_vehicleColor = ((M_CONFIG(getArray,"LifeCfgVehicles",_classNameLife,"textures") select (_dataArr select 1)) select 0);
if (isNil "_vehicleColor") then {_vehicleColor = "Default";};

_vehicleInfo = [_className] call life_fnc_fetchVehInfo;
_trunkSpace = [_className] call life_fnc_vehicleWeightCfg;

_price = M_CONFIG(getNumber,"LifeCfgVehicles",_classNameLife,"price");
_storageFee = LIFE_SETTINGS(getNumber,"vehicle_store_multiplier");

_purchasePrice = _price * 1;

switch (playerSide) do {
    case civilian: {
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_CIVILIAN");
    };
    case west: {
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_COP");
    };
    case independent: {
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_MEDIC");
    };
    case east: {
        _sellMultiplier = LIFE_SETTINGS(getNumber,"vehicle_sell_multiplier_OPFOR");
    };
};
_retrievePrice = _purchasePrice * _storageFee;
_sellPrice = _purchasePrice * _sellMultiplier;

if (!(_sellPrice isEqualType 0) || _sellPrice < 1) then {_sellPrice = 500;};
if (!(_retrievePrice isEqualType 0) || _retrievePrice < 1) then {_retrievePrice = 500;};
if (HAS_PERK("hardWorker")) then { _retrievePrice = _retrievePrice * 0.1 }; // 90% off...

if(str(_inventory) in ["[]","[[],0]",'"[[],0]"','"[]"']) then {
	_inventoryShow = "Empty";
}
else {
	_inventory = toArray(_inventory);

	for "_i" from 0 to (count _inventory)-1 do {
		_sel = _inventory select _i;
		if(_sel == 96) then {
			_inventory set[_i,39];
		};
	}; 

	_inventory = toString(_inventory);
	_inventory = call compile format["%1", _inventory];
	if(typeName _inventory == "STRING") then {_inventory = call compile format["%1", _inventory];};
	if(count _inventory != 0) then {_inventory = _inventory select 0;}; {
		_name = M_CONFIG(getText,"VirtualItems",(_x select 0,0),"displayName");
		_val = (_x select 1);

		if (_val > 0) then
		{
			_inventoryShow = _inventoryShow + format ["%1 x%2",localize _name,_val] + ", ";
		};
	} forEach _inventory;
};

(CONTROL(2800,2803)) ctrlSetStructuredText parseText format [
    ("Retrieval Price:")+ " <t color='#8cff9b'>£%1</t><br/>
    " +("Sell Price:")+ " <t color='#8cff9b'>£%2</t><br/>
    " +("Color:")+ " %8<br/>
    " +("Max Speed:")+ " %3 km/h<br/>
    " +("Horse Power:")+ " %4<br/>
    " +("Passenger Seats:")+ " %5<br/>
    " +("Trunk Space:")+ " %6<br/>
    " +("Fuel Storage:")+ " %7<br/>
    " +("Currently Stored:")+ " %9
    ",
[_retrievePrice] call life_fnc_numberText,
[_sellPrice] call life_fnc_numberText,
(_vehicleInfo select 8),
(_vehicleInfo select 11),
(_vehicleInfo select 10),
if (_trunkSpace isEqualTo -1) then {"None"} else {_trunkSpace},
(_vehicleInfo select 12),
_vehicleColor,
_inventoryShow
];

ctrlShow [2803,true];
ctrlShow [2830,true];
