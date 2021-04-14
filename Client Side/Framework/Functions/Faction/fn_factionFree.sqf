/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_factionFree";

_this params [
	["_faction", "", [""]],
	["_type", "", [""]]
];

_faction = missionConfigFile >> "CfgFactions" >> _faction >> "Free";

isClass _faction && { isNumber (_faction >> _type) } && {
	getNumber (_faction >> _type) isEqualTo 1
}