/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addRadio";

_this params [
	["_radio", "", [""]],
	["_unit", objNull, [objNull]]
];

if (isNull _unit || { !(_radio in ULP_CustomChannels) }) exitWith {};

private _radio = ULP_CustomChannels get _radio;

(radioChannelInfo _radio) params ["", "", "", "_units"];
if (_unit in _units) exitWith {};

_radio radioChannelAdd [_unit];