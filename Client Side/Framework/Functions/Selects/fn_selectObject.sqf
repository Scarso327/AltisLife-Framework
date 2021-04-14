/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_selectVehicles";

_this params [
	["_parent", displayNull, [displayNull]],
	["_objects", [], [[]]],
	["_buttons", ["Select", "Cancel"], [[]]],
	["_params", [], [[]]],
	["_onSelect", {}, [{}]],
	["_tablet", true, [false]]
];

if (isNull _parent) exitWith {};

if (_objects isEqualTo []) exitWith {
	["There is nothing available to select..."] call ULP_fnc_hint;
	_display closeDisplay 0;
};

private _display = _parent createDisplay "DisplaySelectObject";

(_display displayCtrl 4507) ctrlShow _tablet;
(_display displayCtrl 4508) ctrlShow !_tablet;

private _list = _display displayCtrl 4509;

{
	_x params ["_icon", "_name", "_data", "_value"];

	private _item = _list lbAdd _name;
	_list lbSetData [_item, _data];
	_list lbSetValue [_item, _value];

	if !(_icon isEqualTo "") then {
		_list lbSetPicture [_item, _icon];
	};
} forEach _objects;

(_display displayCtrl 4506) ctrlSetStructuredText parseText format ["<t align = 'center'>%1</t>", _buttons select 0];

_display setVariable ["params", _params];
_display setVariable ["onSelect", _onSelect];