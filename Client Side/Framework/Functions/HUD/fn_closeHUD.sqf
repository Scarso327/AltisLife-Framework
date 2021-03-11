/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_closeHUD";

_this params [
	"_ui"
];

if !(isNull _ui) then {
	private _evh = _ui getVariable ["eventhandler", -1];
	if !(_evh isEqualTo -1) then {
		[_evh] call ULP_fnc_removeEachFrame;
	};
	
	["RscHUD"] call ULP_UI_fnc_destroyLayer;
};