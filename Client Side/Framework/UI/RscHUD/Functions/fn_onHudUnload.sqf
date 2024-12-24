/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onHudUnload";

_this params [ "_display" ];

if (isNull _display) exitWith {};

private _frame = _display getVariable ["eachframe", -1];
if !(_frame isEqualTo -1) then { [_frame] call ULP_fnc_removeEachFrame; };

private _eventhandler = _display getVariable ["eventhandler", -1];
if !(_eventhandler isEqualTo -1) then { ["OnXPIncreased", _eventhandler] call ULP_fnc_removeEventHandler; };

private _money = _display getVariable ["money", -1];
if !(_money isEqualTo -1) then { ["MoneyChanged", _money] call ULP_fnc_removeEventHandler; };