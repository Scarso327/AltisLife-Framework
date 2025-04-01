/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_tickVehicleFactory";

_this params [
	["_factory", objNull, [objNull]],
	["_product", configNull, [configNull]],
	["_quantity", 0, [0]]
];

private _materials = getArray (_product >> "materials");

{
	_x params ["_item", "_amount"];
	
	[_factory, _item, _amount, false] call ULP_fnc_removeFromCargo;
} forEach _materials;

private _class = configName _product;
private _cfg = missionConfigFile >> "CfgVehicles" >> _class;

if (isClass _cfg) then {
	private _owner = _factory getVariable ["product_owner", objNull];
	
	if (isNull _owner) exitWith {};

	private _steamId = getPlayerUID _owner;
	private _name = name _owner;
	private _faction = [_owner] call ULP_fnc_getFaction;
	private _texture = _factory getVariable ["factory_texture", "Default"];

	[_steamid, _name, _faction, _class, _texture, []] call ULP_SRV_fnc_insertVehicle;
};

0