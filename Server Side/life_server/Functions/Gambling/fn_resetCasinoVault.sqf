/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_resetCasinoVault";

private _amount = getText (configFile >> "CfgPatches" >> "ULPServer" >> "Settings" >> "CasinoVault" >> "default");

[format ["UPDATE settings SET value = '%1' WHERE setting = 'CasinoVault'", _amount], 1] call DB_fnc_asyncCall;