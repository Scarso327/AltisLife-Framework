/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_onPlayerRespawn";

_this params [
	["_unit", objNull, [objNull]],
	["_corpse", objNull, [objNull]]
];

if !(isPlayer _unit) exitWith {};

private _cfg = missionConfigFile >> "CfgFactions" >> [_unit] call ULP_fnc_getFaction;

if !(isClass _cfg) exitWith {};

if (isNumber (_cfg >> "jointChannel") && { [getNumber(_cfg >> "jointChannel")] call ULP_fnc_bool }) then {
	["Joint", _corpse] call ULP_SRV_fnc_removeRadio;
	["Joint", _unit] call ULP_SRV_fnc_addRadio;
};

// Check if they have a side channel and readd them if they were in it previously
if (isNumber (_cfg >> "sideChannel") && { [getNumber(_cfg >> "sideChannel")] call ULP_fnc_bool }) then {
	private _radio = format ["%1Side", [_unit] call ULP_fnc_getFaction];
	
	if !(_radio in ULP_CustomChannels) exitWith {};

	private _radio = ULP_CustomChannels get _radio;

	(radioChannelInfo _radio) params ["", "", "", "_units"];

	if (_unit in _units) then {
		[_radio, _corpse] call ULP_SRV_fnc_removeRadio;
		[_radio, _unit] call ULP_SRV_fnc_addRadio;
	};
};