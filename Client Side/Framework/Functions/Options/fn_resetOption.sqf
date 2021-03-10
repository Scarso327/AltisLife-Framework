/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_resetOption";

_this params [
	["_option", "", ["", controlNull]],
	["_category", "General", [""]]
];

private _valueCtrl = controlNull;
private _resetCtrl = controlNull;

if (_option isEqualType controlNull) then {
	_resetCtrl = _option;
	_valueCtrl = ((ctrlParentControlsGroup _option) controlsGroupCtrl 102);
	if (isNull _valueCtrl) exitWith { breakOut "fn_resetOption"; };

	_option = _valueCtrl getVariable ["option", ""];
	_category = _valueCtrl getVariable ["category", ""];
};

if (_option isEqualTo "" || { _category isEqualTo "" }) exitWith {};

private _class = missionConfigFile >> "CfgOptions" >> _category >> _option;
if !(isClass _class) exitWith {};

private _default = [_option, _category] call ULP_fnc_getDefaultOption;

if !(isNull _resetCtrl) then {
	
	switch (getText (_class >> "type")) do {
		case "SLIDER" : {
			_valueCtrl sliderSetPosition _default;
		};
		case "DROPDOWN" : {
			for "_i" from 0 to (lbSize _valueCtrl) do {
				if ((_valueCtrl lbValue _i) isEqualTo _default) exitWith {
					_valueCtrl lbSetCurSel _i;
				};
			};
		};
	};

	_resetCtrl ctrlEnable false;
};

["OptionChanged", [_option, _category, _default, [_option, _category, _default] call ULP_fnc_getOption]] call ULP_fnc_invokeEvent;
(profileNamespace setVariable [format["ULP_Options_%1_%2", _category, _option], _default])