/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_getNearestLocation";

_this params [
	["_pos", player, [objNull, []]]
];

if !(_pos isEqualType []) then {
	_pos = getPos _pos;
};

(nearestLocations [_pos, ["NameVillage", "NameCity", "NameCityCapital"], 10000]) param [0, locationNull]