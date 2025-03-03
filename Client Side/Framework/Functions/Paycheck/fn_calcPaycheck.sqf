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

if (isClass (_faction >> "Whitelisting")) then {
	{
		_pay = _pay + ((_pay * getNumber (_x >> "payMulti")) * (call (missionNamespace getVariable format["%1_%2", configName _faction, configName _x])));
	} forEach ("isNumber(_x >> 'payMulti')" configClasses (_faction >> "Whitelisting"));
};

if ([] call ULP_fnc_isGovernor) then { _pay = _pay * 1.15 } else {
	if ([] call ULP_fnc_isProtection) then { _pay = _pay * 1.05 };
};

if (["GovernmentBonus"] call ULP_fnc_hasPerk) then { _pay = _pay * 1.25 };

if (["ULP_SRV_Setting_DonationGoal"] call ULP_fnc_constant) then { _pay = _pay * getNumber(missionConfigFile >> "CfgSettings" >> "DonationRewards" >> "payIncrease"); };

_pay = [_pay] call ULP_fnc_taxPrice;

(round _pay)