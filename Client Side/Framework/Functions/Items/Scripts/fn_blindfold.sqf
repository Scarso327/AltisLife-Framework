/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_blindfold";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit) exitWith {};

if (_unit getVariable ["blindfold", false]) then {
	_unit setVariable ["blindfold", nil, true];
	["Blindfold", 1, false, true] call ULP_fnc_handleItem;
	[format ["You have removed <t color='#B92DE0'>%1's</t> blindfold...", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;
} else {
	if (["Blindfold", 1, true] call ULP_fnc_handleItem) then {
		_unit setVariable ["blindfold", true, true];
		[format ["You have blindfolded <t color='#B92DE0'>%1</t>...", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;
	} else {
		breakOut "fn_blindfold";
	};
};

["Blindfold", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
closeDialog 0;