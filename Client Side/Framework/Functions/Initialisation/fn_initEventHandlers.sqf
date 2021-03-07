/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_initEventHandlers";

player addEventHandler ["GetInMan", { _this call ULP_fnc_onGetIn }];
player addEventHandler ["GetOutMan", { _this call ULP_fnc_onGetOut }];