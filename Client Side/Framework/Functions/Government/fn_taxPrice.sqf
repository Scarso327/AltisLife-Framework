/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_taxPrice";

round ((_this param [0, 0, [0]]) * (1 - ((["Tax", 5] call ULP_fnc_getLegislation) / 100)))