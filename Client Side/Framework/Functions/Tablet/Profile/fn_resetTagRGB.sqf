/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_resetTagRGB";

_this params [
	"_display"
];

if (isNull _display) exitWith {};

([player, false] call ULP_fnc_getTagColour) params [ "_r", "_g", "_b" ];

{
	(_x select 0) sliderSetPosition (round((_x select 1) * 100));
} forEach [
	[(_display displayCtrl 23072), _r],
	[(_display displayCtrl 23073), _g],
	[(_display displayCtrl 23074), _b]
];

[_display] call ULP_fnc_getTagRGB;