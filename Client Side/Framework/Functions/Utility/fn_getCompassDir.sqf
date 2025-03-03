/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_getCompassDir";

_this params [
	["_location", locationNull, [locationNull]],
	["_pos", player, [objNull, []]]
];

if !(_pos isEqualType []) then {
	_pos = getPos _pos;
};

if (isNull _location || { _pos isEqualTo [] } || { _pos in _location }) exitWith { localize "STR_A3_BIS_fnc_locationDescription_near" };

private _locationPos = locationPosition _location;

private _dir = round ((([_locationPos, _pos] call BIS_fnc_dirTo) + 360) % 360) / 45;

localize (switch (_dir) do {
	case 8;
	case 0: { "STR_A3_BIS_fnc_locationDescription_n" };
	case 1: { "STR_A3_BIS_fnc_locationDescription_ne" };
	case 2: { "STR_A3_BIS_fnc_locationDescription_e" };
	case 3: { "STR_A3_BIS_fnc_locationDescription_se" };
	case 4: { "STR_A3_BIS_fnc_locationDescription_s" };
	case 5: { "STR_A3_BIS_fnc_locationDescription_sw" };
	case 6: { "STR_A3_BIS_fnc_locationDescription_w" };
	case 7: { "STR_A3_BIS_fnc_locationDescription_nw" };
	default { "STR_A3_BIS_fnc_locationDescription_near" };
})