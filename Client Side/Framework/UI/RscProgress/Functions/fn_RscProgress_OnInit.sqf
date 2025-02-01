/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscProgress_OnInit";
disableSerialization;

_this params [ "_display", "_params" ];

if (isNull _display) exitWith {};

_params params [
	["_title", "Doing Something", [""]],
	["_duraction", 30, [0]],
	["_params", [], [[]]],
	["_condition", {}, [{}]],
	["_success", {}, [{}]],
	["_fail", {}, [{}]],
	["_anim", ["", toUpper (stance player)], [[]]],
	["_eachframe", {}, [{}]]
];

private _start = time;

_display setVariable ["start", _start];
_display setVariable ["end", _start + _duraction];
_display setVariable ["params", _params];
_display setVariable ["condition", _condition];
_display setVariable ["success", _success];
_display setVariable ["fail", _fail];
_display setVariable ["eachframe", _eachframe];
_display setVariable ["stance", _anim select 1];
_display setVariable ["anim", (_anim call ULP_fnc_getAnim)];

private _progress = _display displayCtrl 38201;
private _progressText = _display displayCtrl 38203;

(_display displayCtrl 38202) ctrlSetText format ["%1", _title];

private _anim = _display getVariable "anim";

if !(_anim isEqualTo "") then {
	player playMoveNow _anim;
};

_display setVariable ["eachFrameHandle", ([[_display, _progress, _progressText], { _this call ULP_UI_fnc_RscProgress_OnEachFrame }] call ULP_fnc_addEachFrame)];