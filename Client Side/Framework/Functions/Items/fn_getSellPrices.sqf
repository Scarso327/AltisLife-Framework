/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getSellPrices";

_this params [
	["_buyPrice", -1, [0]],
	["_sellPrice", -1, [0]],
	["_isLegal", false, [true]]
];

if (_buyPrice isEqualTo -1 && { _sellPrice isEqualTo -1 }) exitWith { [] };

private _gangTax = 0;

if (_sellPrice > 0) then {
	if (["ULP_SRV_Setting_DonationGoal"] call ULP_fnc_constant) then { _sellPrice = _sellPrice * getNumber(missionConfigFile >> "CfgSettings" >> "DonationRewards" >> "sellIncrease"); };

	// TODO : Group Tax...

	// If the sell price is higher than buy, make sell 95% of buy...
	if (_sellPrice > _buyPrice && { _buyPrice > 0 }) then { _sellPrice = _buyPrice * 0.95; };
};

// Force round...
_sellPrice = round _sellPrice;
_gangTax = round _gangTax;

[
	_sellPrice, // Price you get from selling...
	_gangTax // Price to be added to gang funds from taxes..
]