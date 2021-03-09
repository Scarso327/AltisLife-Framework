/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setScreen";

_this params [
	["_app", "", [""]]
];

private _display = findDisplay 23000;
private _screen = missionConfigFile >> "CfgApps" >> _app;
if !(isClass _screen || { !(isNull _display) }) exitWith {};

private _unload = _display getVariable ["onUnload", ""];
if !(_unload isEqualTo "") then {
	_display call compile _unload;
};

private _showIdcs = getArray (missionConfigFile >> "CfgApps" >> "globalIdcs");
_showIdcs append getArray (_screen >> "pageIdcs");

{
	if ((ctrlIDC _x) in _showIdcs) then {
		_x ctrlShow true;
		_x ctrlCommit 0;
	} else {
		_x ctrlShow false;
		_x ctrlCommit 0;
	};
} forEach (allControls _display);

(_display displayCtrl 23001) ctrlSetStructuredText parseText format[" <t align='left'>%1</t>", getText (_screen >> "pageTitle")];
_display setVariable ["screen", _screen];
_display setVariable ["onUnload", getText(_screen >> "onUnload")];

_display call compile getText(_screen >> "onLoad");