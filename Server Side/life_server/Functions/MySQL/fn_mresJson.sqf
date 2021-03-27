/*
** Author: Jack "Scarso" Farhall
** Description: 
*/

_this params [
    ["_strArray", "", [""]]
];

(toString (toArray (_strArray select [1, (count _strArray) - 2]) apply {
	switch (_x) do {
		case (91): { 123 };
		case (93): { 125 };
		default { _x };
	};
}))