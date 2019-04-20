/*
	@File: fn_switchApp.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Hides and shows stuff tbh....
*/
#include "..\..\..\..\script_macros.hpp"
#include "..\macros.hpp"
params [
	["_showIDC", -1, [0]],
	["_title", "AsYetUntitled", [""]]
];

disableSerialization;

private _display = findDisplay IDD_TABLET_MAIN;

if (_showIDC < 0) exitWith { systemChat "No IDC Passed..." };
if (!(alive player) || {isNull _display} || isDowned(player)) exitWith { closeDialog 0; };

FF_curApp = _title; // Changes for "Escape" Handling...

// Handle Controls...
{
	private _ctrl = _x;

	if (ctrlIDC _x >= _showIDC && ctrlIDC _x < (_showIDC + 100)) then {
		_ctrl ctrlShow true;
		_ctrl ctrlSetFade 0;
		_ctrl ctrlCommit 0.1;
	} else {
		_ctrl ctrlShow false;
		_ctrl ctrlSetFade 1;
		_ctrl ctrlCommit 0;
	};
} forEach (((allControls _display) select { ctrlIDC _x >= 23100 }));

// Run On Load...
[_title] call FF(onLoad);