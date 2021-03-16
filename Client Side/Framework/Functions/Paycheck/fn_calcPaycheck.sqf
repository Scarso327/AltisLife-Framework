/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#define CFG missionConfigFile >> "CfgFactions"
scopeName "fn_calcPaycheck";

private _faction = CFG >> [player] call ULP_fnc_getFaction;

private _pay = getNumber ([
	CFG >> "fallbackPay",
	_faction >> "pay"
] select (isClass (_faction)));

if (["ULP_SRV_Setting_DonationGoal"] call ULP_fnc_constant) then { _pay = _pay * getNumber(missionConfigFile >> "CfgSettings" >> "DonationRewards" >> "payIncrease"); };

(round _pay)