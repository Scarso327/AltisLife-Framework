/*
** Author: Jack "Scarso" Farhall
** Description: 
*/

_this params [
    ["_array", [], [[]]]
];

(['"', toString ((toArray (str _array)) apply { [_x, 96] select (_x isEqualTo 34) }), '"'] joinString "")