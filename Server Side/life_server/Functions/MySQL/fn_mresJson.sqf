/*
** Author: Jack "Scarso" Farhall
** Description: 
*/

_this params [
    ["_strArray", "", [""]]
];

// TODO, Switch to HashMap and properly name...

(toString (toArray (_strArray select [1, (count _strArray) - 2]) apply {
	switch (_x) do {
		case (91): { 123 };
		case (93): { 125 };
		default { _x };
	};
}))