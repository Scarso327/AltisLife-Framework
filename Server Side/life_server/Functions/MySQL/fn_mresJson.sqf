/*
** Author: Jack "Scarso" Farhall
** Description: 
*/

_this params [
    ["_strArray", "", [""]]
];

// TODO, Switch to HashMap and properly name...

(toString (toArray (_strArray select [1, (count _strArray) - 2])))