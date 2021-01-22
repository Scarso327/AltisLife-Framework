/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_cartInfo";

format[
	"<t size='0.8'><br/>Cart Information<br/>Total Cost: <t color='#8cff9b'>£%1</t><br/></t>",
	[(uiNamespace getVariable ["cartValue", 0])] call life_fnc_numberText
]