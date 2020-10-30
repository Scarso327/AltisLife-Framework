#include "..\..\script_macros.hpp"
/*
    File: fn_adminFreeze.sqf
    Author: Lewis Mackinnon
*/

if ((FETCH_CONST(life_adminlevel) < 2) && admin_duty) exitWith {closeDialog 0; hint "You must be on-duty to use this."};

private _target = lbData[2902,lbCurSel (2902)];
_target = call compile format ["%1", _target];

if (isNil "_target") exitWith {};
if (isNull _target) exitWith {};
if (_target == player) exitWith {hint "You are unable to do this.";};

[player] remoteExec ["life_fnc_freezePlayer",_target];

if (FETCH_CONST(life_adminlevel) > 0) then {
    hint format ["<t color = '#7300e6'>%1</t> has frozen <t color = '#7300e6'>%2</t>.",player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
};
