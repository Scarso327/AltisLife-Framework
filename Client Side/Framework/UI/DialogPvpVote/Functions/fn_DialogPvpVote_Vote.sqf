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

private _index = tvCurSel _list;
private _selected = _list tvData _index;

if (_selected isEqualTo "") exitWith {};

if ((_display getVariable ["Cooldown", 0]) > time) exitWith {
	["Please wait before preforming this action again"] call ULP_fnc_hint;
};

[player, _selected] remoteExecCall ["ULP_SRV_fnc_castPvpModeVote", RSERV];
["Your vote has been cast"] call ULP_fnc_hint;
_display setVariable ["Cooldown", time + 5];