/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_placeholder";

_this params [
	["_edit", controlNull, [controlNull]],
	["_placeholder", controlNull, [controlNull]]
];

if (isNull _edit || { isNull _placeholder }) exitWith { false };

_placeholder ctrlShow ((count (ctrlText _edit)) <= 0);
_edit setVariable ["Placeholder", _placeholder];

_edit ctrlSetEventHandler ["keyDown", "_this params [""_ctrl""]; private _holder = _ctrl getVariable [""Placeholder"", controlNull]; if (isNull _holder) exitWith {}; private _show = ((count (ctrlText _ctrl)) <= 0); if !((ctrlShown _holder) isEqualTo _show) then { _holder ctrlShow _show; };"];
_edit ctrlSetEventHandler ["keyUp", "_this params [""_ctrl""]; private _holder = _ctrl getVariable [""Placeholder"", controlNull]; if (isNull _holder) exitWith {}; private _show = ((ctrlText _ctrl) isEqualTo """"); if !((ctrlShown _holder) isEqualTo _show) then { _holder ctrlShow _show; };"];