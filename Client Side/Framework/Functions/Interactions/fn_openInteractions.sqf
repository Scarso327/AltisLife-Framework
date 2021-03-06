/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#define Y_CHANGE (0.011 * safezoneH)
#define BUTTON_Y_CHANGE (0.022 * safezoneH)
scopeName "fn_openInteractions";

private _interactions = _this;

if (dialog || { _interactions isEqualTo [] }) exitWith { false };

if (createDialog "DialogInteractions") exitWith {
	private _display = findDisplay 3600;
	if (isNull _display) exitWith { false };

	private _header = _display displayCtrl 3601;
	private _headerPos = ctrlPosition _header;
	private _closeButton = _display displayCtrl 3602;

	private _count = count _interactions;

	_header ctrlSetPosition [_headerPos select 0, (_headerPos select 1) - (Y_CHANGE * _count)];
	_header ctrlCommit 0;
	_headerPos = ctrlPosition _header; // Get New Pos...

	_closeButton ctrlSetPosition [(ctrlPosition _closeButton) select 0, (_headerPos select 1) + (BUTTON_Y_CHANGE * (_count + 1))];
	_closeButton ctrlCommit 0;

	private _button = controlNull;

	{
		_x params ["_title", "_action"];

		_button = _display ctrlCreate ["Life_RscButtonCenter", 3603 + _forEachIndex];
		_button ctrlSetStructuredText parseText format["<t align = 'center'>%1</t>", _title];
		_button ctrlSetPosition [_headerPos select 0, (_headerPos select 1) + (BUTTON_Y_CHANGE * (_forEachIndex + 1)), _headerPos select 2, _headerPos select 3];
		_button ctrlSetEventHandler ["ButtonClick", _action];
		_button ctrlCommit 0;
	} forEach _interactions;

	true
};

false