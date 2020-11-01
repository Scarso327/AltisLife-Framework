/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_hasAccess";

_this params [
	["_varName", "", [""]],
	["_levelReq", 0, [0]]
];

(missionNamespace getVariable [_varName, 0]) >= _levelReq