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

if (_category isEqualTo "" || { _option isEqualTo "" } || { isNull _resetCtrl }) exitWith { hint "An error occured while changing settings..."; };

_resetCtrl ctrlEnable !(_value isEqualTo _default);
(profileNamespace setVariable [format["ULP_Options_%1_%2", _category, _option], _value])