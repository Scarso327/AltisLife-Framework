/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onUnrestrained";

if !([player] call ULP_fnc_isRestrained) exitWith {};

player setVariable ["restrained", nil, true]; // Tells the server we're unrestrained...

if (alive player) then {
    player switchMove "AmovPercMstpSlowWrflDnon_SaluteIn";
};

detach player; // Make sure we're no longer being escorted...