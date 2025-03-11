/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_deleteCrime";

_this params [
	["_unit", objNull, [objNull]],
	["_act", "", [""]],
	["_crime", "", [""]],
	["_crimeId", -1, [0]]
];

if (isNull _unit || { _act isEqualTo "" } || { _crime isEqualTo "" } || { _crimeId isEqualTo -1 }) exitWith { false };

[format["UPDATE `warrants` SET `active`='0' WHERE `pid`='%1' AND `act`='%2' AND `crime`='%3' AND `id`='%4' AND `faction`='%5' AND `active`='1'", getPlayerUID _unit, _act, _crime, _crimeId, [_unit] call ULP_fnc_getFaction], 1] call DB_fnc_asyncCall;
true