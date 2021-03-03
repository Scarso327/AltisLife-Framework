/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_numberText";

_this params [
    ["_number", 0, [0]]
];

private _str = _number toFixed 0; // We never format decimals so this works just fine...

if (_number >= 1000) then {
    private _commas = floor (( ( count _str ) - 1 ) / 3);

    _str = _str splitString "";
    reverse _str;

    for "_i" from 3 to (4 * _commas) step 4 do {
        _str = (_str select[0, _i]) + [","] + (_str select [_i, (count _str) - 1]);
    }; 
    
    reverse _str;
    _str = _str joinString "";
};

_str