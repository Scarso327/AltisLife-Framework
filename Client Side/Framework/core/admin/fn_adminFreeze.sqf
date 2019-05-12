#include "..\..\script_macros.hpp"
/*
    File: fn_adminFreeze.sqf
    Author: Lewis Mackinnon
*/

if ((FETCH_CONST(life_adminlevel) < 2) && admin_duty == 0); exitWith {closeDialog 0; hint "You must be on-duty to use this.";};

private _unit = lbData[2902,lbCurSel (2902)];
_unit = call compile format ["%1", _unit];

if (isNil "_unit") exitWith {};
if (isNull _unit) exitWith {};
if (_unit == player) exitWith {hint "You are unable to do this.";};

[player] remoteExec ["life_fnc_freezePlayer",_unit];
