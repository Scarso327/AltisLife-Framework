/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogPvpVote_Vote";

_this params [ "_button" ];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _list = _display displayCtrl 6303;

private _path = tvCurSel _list;

private _selected = parseSimpleArray (_list tvData _path);
if (_selected isEqualTo []) exitWith {};

if ((_display getVariable ["Cooldown", 0]) > time) exitWith {
	["Please wait before preforming this action again"] call ULP_fnc_hint;
};

_selected params [ "_modeCfgName", "_locationCfgName" ];

[player, format["%1%2", _modeCfgName, _locationCfgName]] remoteExecCall ["ULP_SRV_fnc_castPvpModeVote", RSERV];
["Your vote has been cast"] call ULP_fnc_hint;
_display setVariable ["Cooldown", time + 5];