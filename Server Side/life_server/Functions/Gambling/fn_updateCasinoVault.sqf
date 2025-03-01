/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_updateCasinoVault";

_this params [
	["_change", 0, [0]]
];

private _amount = missionNamespace getVariable ["ULP_SRV_Setting_CasinoVault", 0];
_amount = _amount + _change;

missionNamespace setVariable ["ULP_SRV_Setting_CasinoVault", _amount];

[format ["UPDATE settings SET value = '%1' WHERE setting = 'CasinoVault'", [_amount, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;