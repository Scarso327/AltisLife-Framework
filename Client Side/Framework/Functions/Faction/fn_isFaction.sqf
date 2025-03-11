/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_isFaction";

diag_log _this;

_this params [
	["_object", objNull, [objNull]],
	["_factions", [], [[]]]
];

if (isNull _object) exitWith {};

(([_object] call ULP_fnc_getFaction) in _factions)