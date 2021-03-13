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
	private _frame = _ui getVariable ["eachframe", -1];
	if !(_frame isEqualTo -1) then { [_frame] call ULP_fnc_removeEachFrame; };

	private _eventhandler = _ui getVariable ["eventhandler", -1];
	if !(_eventhandler isEqualTo -1) then { [_eventhandler] call ULP_fnc_removeEventHandler; };
	
	["RscHUD"] call ULP_UI_fnc_destroyLayer;
};