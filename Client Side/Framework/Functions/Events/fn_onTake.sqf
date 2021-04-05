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

{
	_x params [ "_object", "_objectContainer" ];
	private _texture = _objectContainer getVariable ["texture", ""];

	if !(_texture isEqualTo "") then {
		[_object, _objectContainer, _texture] call ULP_fnc_setTextures;
	};
} Foreach [[_unit, uniformContainer _unit], [unitBackpack _unit, backpackContainer _unit]];