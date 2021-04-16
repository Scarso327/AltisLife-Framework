/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onTake";

_this params [
	["_unit", objNull, [objNull]],
    ["_container", objNull, [objNull]],
    ["_item", "", [""]]
];

if (isNull _unit || { _item isEqualTo "" }) exitWith { true };

private _uniform = (uniformContainer _unit) getVariable ["texture", ""];
private _backpack = (backpackContainer _unit) getVariable ["texture", ""];

if !(_uniform isEqualTo "") then { [_unit, uniform _unit, uniformContainer _unit, _uniform] call ULP_fnc_setTextures; };
if !(_backpack isEqualTo "") then { [unitBackpack _unit, typeOf (unitBackpack _unit), backpackContainer _unit, _backpack] call ULP_fnc_setTextures; };

[] call ULP_fnc_maxCarry;