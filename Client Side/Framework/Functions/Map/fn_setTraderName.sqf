/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setTraderName";

_this params [
	["_trader", objNull, [objNull]],
	["_name", "", [""]]
];

if (isNull _trader || { _name isEqualTo "" } || { !isNil { _trader getVariable "name" } }) exitWith { false };

_trader setVariable ["hasPlayerTags", true];
_trader setVariable ["name", _name];
true