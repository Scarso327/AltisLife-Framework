/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_tickSalvageFactory";

_this params [
	["_factory", objNull, [objNull]],
	["_product", configNull, [configNull]],
	["_quantity", 0, [0]]
];

private _vehicle = _factory getVariable ["factory_vehicle", objNull];

if (isNull _vehicle || { !alive _vehicle } || { !(count (crew _vehicle) isEqualTo 0) }) exitWith { 0 };

private _materials = getArray (_product >> "materials");

{
	_x params ["_item", "_amount"];
	
	[_factory, _item, _amount, false, true] call ULP_fnc_addToCargo;
} forEach _materials;

private _cfg = missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle);

if (isClass _cfg) then {
	private _chopValue = getNumber (_cfg >> "buyPrice") * ([
			getNumber (missionConfigFile >> "CfgVehicles" >> "chopPerc"),
			getNumber (_cfg >> "chopPerc")
		] select (isNumber (_cfg >> "chopPerc")));

	if (_chopValue > 0) then {
		_chopValue = _chopValue * 1.25;

		[_factory, "DroppedMoney", [str _chopValue], true, true] call ULP_fnc_addToCargo;
	};
};

private _id = _vehicle getVariable ["vehicle_id", -1];
deleteVehicle _vehicle;

if (_id >= 0) then {
	[_id] call ULP_SRV_fnc_destroyVehicle;
};

_factory setVariable ["factory_vehicle", nil];

0