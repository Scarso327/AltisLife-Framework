/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_clearWarrants";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit) exitWith { false };

[format["UPDATE `warrants` SET `active`='0' WHERE `pid`='%1' AND `active`='1' AND `faction`='%2'", getPlayerUID _unit, [_unit] call ULP_fnc_getFaction], 1] call DB_fnc_asyncCall;
true