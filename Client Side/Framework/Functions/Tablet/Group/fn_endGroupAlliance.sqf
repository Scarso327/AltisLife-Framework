/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_endGroupAlliance";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if !([] call ULP_fnc_isGroupOwner) exitWith {
	["You must be the group owner to manage alliances!"] call ULP_fnc_hint;
	false
};

if (_display getVariable ["alliance_processing", false]) exitWith { false };

private _list = _display displayCtrl 23102;

private _selected = lnbCurSelRow _list;
private _groupId = _list lnbValue [_selected, 0];

_display setVariable ["alliance_processing", true];
[group player, _groupId] remoteExecCall ["ULP_SRV_fnc_endGroupAlliance", RSERV];

true