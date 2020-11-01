/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_getFaction";

_this params [
	["_object", objNull, [objNull]]
];

if (isNull _object) exitWith {};

_object getVariable ["faction", getText(missionConfigFile >> "CfgFactions" >> "defaultFaction")];