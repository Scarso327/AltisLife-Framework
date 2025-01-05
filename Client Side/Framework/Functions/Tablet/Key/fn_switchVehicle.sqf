/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_switchVehicle";

_this params [
	["_list", controlNull, [controlNull]],
	["_index", -1, [0]]
];

private _display = ctrlParent _list;
if (isNull _display) exitWith {};

private _carView = _display displayCtrl 23092;

private _vehicle = (_list lbData _index) call BIS_fnc_objectFromNetId;

_carView ctrlShow (!isNull _vehicle && { (vehicle player) isEqualTo _vehicle });

_display setVariable ["vehicle", _vehicle];