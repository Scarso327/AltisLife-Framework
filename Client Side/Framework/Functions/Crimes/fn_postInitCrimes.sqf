/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_postInitCrimes";

["CrimeBreakIn", {
	_this params [
		["_unit", objNull, [objNull]],
		["_crime", "", [""]]
	];

	if (isNull _unit || { _crime isEqualTo "" }) exitWith {};

	[format ["<t color='#ff0000' size='1.5px'>%2<br/></t><t color='#ffffff' size='1px'><t color='#B92DE0'>%1</t> is breaking into <t color='#B92DE0'>%2</t>", [_unit, false, true] call ULP_fnc_getName, _crime]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;