/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_isFaction";

_this params [
	["_faction", "", [""]],
	["_persistance", "", [""]]
];

_faction = missionConfigFile >> "CfgFactions" >> _faction;
if !(isClass _faction) exitWith { false };

isNumber (_faction >> "Persistance" >> _persistance) && {
	getNumber (_faction >> "Persistance" >> _persistance) isEqualTo 1
}