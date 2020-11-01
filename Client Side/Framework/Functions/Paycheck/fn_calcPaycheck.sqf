/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#define CFG missionConfigFile >> "CfgFactions"
scopeName "fn_calcPaycheck";

private _faction = CFG >> [player] call ULP_fnc_getFaction;

getNumber ([
	CFG >> "fallbackPay",
	_faction >> "pay"
] select (isClass (_faction)))