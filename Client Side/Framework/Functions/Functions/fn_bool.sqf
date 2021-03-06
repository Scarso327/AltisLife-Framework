/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_bool";

_this params [
    ["_value", false, [0, true]]
];

if (_value isEqualType 0) then {
    [false, true] select (_value >= 1)
} else {
    parseNumber _value
};