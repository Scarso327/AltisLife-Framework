/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setOption";

_this params [
	["_valueCtrl", controlNull, [controlNull]],
	["_value", 0],
	["_default", 0]
];

private _category = _valueCtrl getVariable ["category", ""];
private _option = _valueCtrl getVariable ["option", ""];
private _resetCtrl = _valueCtrl getVariable ["resetCtrl", controlNull];

if (_category isEqualTo "" || { _option isEqualTo "" } || { isNull _resetCtrl }) exitWith { ["An error occured while changing settings!"] call ULP_fnc_hint; };

private _previous = [_option, _category, _default] call ULP_fnc_getOption;

_resetCtrl ctrlEnable !(_value isEqualTo _default);

["OptionChanged", [_option, _category, _value, _previous]] call ULP_fnc_invokeEvent;
(missionProfileNamespace setVariable [format["ULP_Options_%1_%2", _category, _option], _value])