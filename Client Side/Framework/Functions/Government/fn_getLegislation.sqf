/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_getLegislation";

_this params [
	["_legislation", "", [""]],
	["_fallback", 0, [0, false, "", []]]
];

private _cfg = missionConfigFile >> "CfgGovernment" >> "Legislation" >> _legislation;
if !(isClass _cfg) exitWith { _fallback };

((missionNamespace getVariable ["ULP_SRV_Setting_GovernorSettings", createHashMap]) getOrDefault [_legislation, getArray (_cfg >> "values") param [1, 0]])