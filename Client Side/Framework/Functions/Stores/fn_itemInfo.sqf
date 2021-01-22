/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_itemInfo";

private _item = uiNamespace getVariable ["itemData", []];
if (_item isEqualTo []) exitWith { "" };

_item params [
	"_name", "_price"
];

format[
	"<t size='0.8'><br/>Item Information<br/>Name: %1<br/>Cost: <t color='#8cff9b'>£%2</t><br/></t>",
	_name, [_price] call life_fnc_numberText
]