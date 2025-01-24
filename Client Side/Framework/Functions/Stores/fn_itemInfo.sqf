/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_itemInfo";

private _item = _display getVariable ["itemData", []];
if (_item isEqualTo []) exitWith { "" };

_item params [
	"_name", "_price", "_virtualSpace"
];

format [
	"<t size='0.8'><br/>Item Information<br/>Name: %1%3<br/>Cost: <t color='#8cff9b'>£%2</t><br/></t>",
	_name, [_price] call ULP_fnc_numberText, [
		"", format ["<br/>Virtual Space: <t color='#B92DE0'>%1</t>", _virtualSpace]
	] select (_virtualSpace > 0)
]