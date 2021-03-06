/*
** Author: Jack "Scarso" Farhall
** Description: 
*/

_this params [
    ["_array", [], [[]]]
];

_array = toArray (str _array);

private _start = _array select 0;
private _end = _array select ((count _array) - 1);

_array = _array apply { [_x, 96] select (_x isEqualTo 34) };

_array set [0, _start];
_array set [((count _array) - 1), _end];

toString _array