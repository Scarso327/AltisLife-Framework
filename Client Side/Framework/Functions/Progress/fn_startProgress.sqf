/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_startProgress";

_this params [
	["_title", "Doing Something", [""]],
	["_duraction", 30, [0]],
	["_params", [], [[]]],
	["_condition", {}, [{}]],
	["_success", {}, [{}]],
	["_fail", {}, [{}]],
	["_anim", ["", toUpper (stance player)], [[]]],
	["_eachframe", {}, [{}]]
];

if ([] call ULP_UI_fnc_isProgress) exitWith {
	false
};

if (["RscProgress", "PLAIN", 3] call ULP_UI_fnc_createLayer) then {
	private _ui = ["RscProgress"] call ULP_UI_fnc_getLayer;
	if (isNull _ui) exitWith {}; // Shouldn't happen but we'll be safe...

	private _start = time;

	_ui setVariable ["start", _start];
	_ui setVariable ["end", _start + _duraction];
	_ui setVariable ["params", _params];
	_ui setVariable ["condition", _condition];
	_ui setVariable ["success", _success];
	_ui setVariable ["fail", _fail];
	_ui setVariable ["eachframe", _eachframe];
	_ui setVariable ["stance", _anim select 1];
	_ui setVariable ["anim", (_anim call ULP_fnc_getAnim)];

	disableSerialization;

	private _progress = _ui displayCtrl 38201;
	private _progressText = _ui displayCtrl 38203;

	(_ui displayCtrl 38202) ctrlSetText format ["%1", _title];

	private _anim = _ui getVariable "anim";

	if !(_anim isEqualTo "") then {
		player playMoveNow _anim;
	};

	[[_ui, _progress, _progressText], { _this call ULP_UI_fnc_eachFrameProgress }] call ULP_fnc_addEachFrame;

	true breakOut "fn_startProgress";
};

false