/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_selectProcess";

if (canSuspend) exitWith {
    [ULP_fnc_selectProcess, _this] call ULP_fnc_directCall;
};

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _list = _display displayCtrl 4003;
[_list lbData (lbCurSel _list)] call ULP_fnc_process;
closeDialog 0;