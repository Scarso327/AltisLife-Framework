/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_inputLimit";

_this params ["_input", "_key", "_shift", "_ctrl", "_alt"];

private _lengthBoundaries = _input getVariable ["Length", []];
private _string = ctrlText _input;

if !(_lengthBoundaries isEqualTo []) then {
	_lengthBoundaries params ["_lowest", "_highest"];

	private _length = count _string;

	if (_length > _highest) then {
		_string = toString ((toArray _string) deleteRange [_highest - 1, _length - 1]);
	};
};

// _string = [_string] call ULP_fnc_stripString;
_input ctrlSetText _string;