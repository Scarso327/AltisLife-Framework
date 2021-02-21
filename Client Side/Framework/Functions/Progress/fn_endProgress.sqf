/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_endProgress";

_this params [
	"_ui", "_success"
];

if !(isNull _ui) then {
	private _stance = _ui getVariable ["stance", toUpper (stance player)];
	private _animation = _ui getVariable ["anim", ""];
	private _params = _ui getVariable ["params", []];
	private _onSuccess = _ui getVariable ["success", {}];
	private _onFail = _ui getVariable ["fail", {}];

	_params call ([_onFail, _onSuccess] select _success);

	["RscProgress"] call ULP_UI_fnc_destroyLayer;

	if !(_animation isEqualTo "") then {
		player playMove (["IDLE", _stance] call ULP_fnc_getAnim);
	};
};

[_thisEventHandler] call ULP_fnc_removeEachFrame;