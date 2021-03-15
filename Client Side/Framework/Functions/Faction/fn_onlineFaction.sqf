/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_isFaction";

_this params [
	["_factions", [], [[]]]
];

if (_factions isEqualTo []) exitWith { 0 };

({ [_x, _factions] call ULP_fnc_isFaction } count allPlayers)