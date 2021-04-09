/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_getTagRGB";

_this params [
	"_display"
];

if (isNull _display) exitWith { "#00E613" };

private _colour = [
	((sliderPosition (_display displayCtrl 23072)) / 100),
	((sliderPosition (_display displayCtrl 23073)) / 100),
	((sliderPosition (_display displayCtrl 23074)) / 100),
	1
];

_display setVariable ["color_selected", _colour];
(_colour call BIS_fnc_colorRGBAtoHTML)