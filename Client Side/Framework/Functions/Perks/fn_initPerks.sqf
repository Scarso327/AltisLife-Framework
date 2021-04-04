/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initPerks";

["Initialising Perks"] call ULP_fnc_logIt;

["SoldVirtualItem", {
	diag_log _this;
	_this params [ "_soldItem", "_amount", "_sellPrice", "_illegal" ];

	if (_sellPrice > 0) then {
		// We've already got the sell price, we just need to activate the perk for leveling here...
		if !(_illegal) then {
			["ExpertTrader", _sellPrice, true] call ULP_fnc_activatePerk;
		};
	};
}] call ULP_fnc_addEventHandler;