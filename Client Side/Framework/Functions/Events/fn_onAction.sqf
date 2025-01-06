/*
** Author: Jack "Scarso" Farhall
** Description: Blocks arma 3 actions if conditions met
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onAction";

private _action = _this param [3, "", [""]];

([] call ULP_fnc_isInputBlocked
	|| { _action in ["HealSoldier", "HealSoldierSelf", "TakeWeaponFromBody", "TakeWeapon", "TakeMagazine", "TakeItem", "Rearm"] })