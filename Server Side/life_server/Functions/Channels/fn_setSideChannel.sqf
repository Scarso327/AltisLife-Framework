/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_setSideChannel";

_this params [
	["_unit", objNull, [objNull]],
	["_add", true, [false]]
];

private _radio = format ["%1Side", [_unit] call ULP_fnc_getFaction];

if (isNull _unit || { !(_radio in ULP_CustomChannels) }) exitWith {};

private _radio = ULP_CustomChannels get _radio;

(radioChannelInfo _radio) params ["", "", "", "_units"];
if (_add isEqualTo (_unit in _units)) exitWith {};

if (_add) then {
	_radio radioChannelAdd [_unit];
} else {
	_radio radioChannelRemove [_unit];
};