/*
** Author: Jack "Scarso" Farhall
** Description: 
*/

if !(_this params [
	["_array", "", [""]]
]) exitWith { [] };

_array = call compile (format ["%1", toString (toArray(_array) apply {[_x, 39] select (_x isEqualTo 96)})]);
if (_array isEqualType "") then { _array = parseSimpleArray _array };
_array