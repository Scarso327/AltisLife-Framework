/*
** Author: Jack "Scarso" Farhall
** Description: Displays left at top of screen to indicate leaving or entering a given zone
*/
#include "..\..\script_macros.hpp"
scopeName "fn_zoneText";

_this params [
	["_message", "", [""]]
];

private _display = (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd"));
if (isNull _display || { _message isEqualTo "" }) exitWith {};

private _text = _display ctrlCreate ["Life_RscStructuredText", -1];
_text ctrlSetPosition [
	0 * safezoneW + safezoneX,
	-0.5 * safezoneH + safezoneY,
	1 * safezoneW,
	0.022 * safezoneH
];
_text ctrlSetStructuredText parseText format["%1", _message];
_text ctrlCommit 0;

_text ctrlSetPosition [
	0 * safezoneW + safezoneX,
	0.025 * safezoneH + safezoneY
];

_text ctrlCommit 1;

[3, [_text], {
	_this params [ "_text" ];

	_text ctrlSetPosition [
		0 * safezoneW + safezoneX,
		-0.5 * safezoneH + safezoneY
	];

	_text ctrlCommit 1;

	[1, [_text], {
		_this params [ "_text" ];
		ctrlDelete _text;
	}] call ULP_fnc_waitExecute;
}] call ULP_fnc_waitExecute;