/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_endProgress";

if (canSuspend) exitWith {
    [ULP_fnc_endProgress, _this] call ULP_fnc_directCall;
};

_this params [
	"_display", "_success"
];

if !(isNull _display) then {
	private _params = _display getVariable ["params", []];
	private _onSuccess = _display getVariable ["success", {}];
	private _onFail = _display getVariable ["fail", {}];

	_params call ([_onFail, _onSuccess] select _success);

	["RscProgress"] call ULP_UI_fnc_destroyLayer;
};