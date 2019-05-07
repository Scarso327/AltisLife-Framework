/*
	@File: fn_createMenu.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Creates the interaciton menu and adds all buttons...

	@Parameters:
		0 - TYPE: STRING - DES: The title of the interaction menu...
		1 - TYPE: ARRAY - DES: Array of the buttons to be created...
*/
#include "..\..\..\..\script_macros.hpp"
params [
	["_title", "Unknown Interaction", [""]],
	["_buttons", [], [[]]]
];

if !(canSuspend) exitWith { _this spawn FF(createMenu) };

// Checks...
if (_buttons isEqualTo []) exitWith {};
if (count(_buttons) > 22) then { _buttons deleteRange [23, (count(_buttons))]; systemChat "Buttons deleted due to overflow..."; }; // If it's over 22 buttons delete the overflow...

if !(createDialog "RscInteractionMenu") exitWith { systemChat "Resource Creation Fail..." };

ctrlSetText[6001, _title]; // Set the menu's title...

private _display = findDisplay 6000;
private _yVal = 0.269;
private _baseIDC = 6002;

{
	// Create Select Button...
	private _button = _display ctrlCreate ["Life_RscButtonMenu", _baseIDC];
	_button ctrlSetStructuredText parseText (_x select 0);
	_button ctrlSetPosition [0.5825 * safezoneW + safezoneX, _yVal * safezoneH + safezoneY, 0.103125 * safezoneW, 0.022 * safezoneH];
	_button ctrlSetEventHandler ["ButtonClick", (_x select 1)];
	_button ctrlCommit 0;

	_yVal = _yVal + 0.022; // Increase the y value for next button...
	_baseIDC = _baseIDC + 1; // Increase IDC for next button...
	FF_createdElements pushBack _button; // Save it to be deleted later...
} forEach _buttons;

waitUntil { isNull (findDisplay 6000) }; // Wait for the UI to close...

FF_createdElements = []; // Wipe it...