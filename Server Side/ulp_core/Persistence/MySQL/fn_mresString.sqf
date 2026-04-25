/*
** Author: Jack "Scarso" Farhall
** Description: 
*/

_this params [
    ["_str", "", [""]]
];

// toArray "'/\`:|;,{}-""<>"

toString ((toArray _str) select {
    !(_x in [39, 47, 92, 96, 58, 124, 59, 44, 123, 125, 45, 34, 60, 62])
})