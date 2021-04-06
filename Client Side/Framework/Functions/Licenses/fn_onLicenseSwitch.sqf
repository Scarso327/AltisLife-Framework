/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onLicenseSwitch";

_this params [
	["_list", controlNull, [controlNull]],
	["_index", -1, [0]]
];

private _display = ctrlParent _list;
if (isNull _display) exitWith {};

(_display displayCtrl 3904) ctrlSetStructuredText parseText format["%1%2", "£", [(_list lbValue _index)] call ULP_fnc_numberText];