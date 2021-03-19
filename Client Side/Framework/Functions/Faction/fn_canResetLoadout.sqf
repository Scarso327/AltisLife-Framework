/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_canResetLoadout";

_this params [
	["_faction", "", [""]]
];

_faction = missionConfigFile >> "CfgFactions" >> _faction >> "Loadout";

isClass _faction && { isNumber (_faction >> "canRestLoadout") } && {
	getNumber (_faction >> "canRestLoadout") isEqualTo 1
}