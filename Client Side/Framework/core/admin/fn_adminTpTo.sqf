#include "..\..\script_macros.hpp"
/*
    File: fn_adminTpTo.sqf
    Author: Lewis Mackinnon
*/

if ((FETCH_CONST(life_adminlevel) < 2) && admin_duty) exitWith {closeDialog 0; hint "You must be <t color = '#7300e6'>on-duty</t> to use this."};

private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);
_target = call compile format ["%1", _target];

if (isNil "_target" || isNull _target) exitWith {};
if (_target == player) exitWith {hint "You are unable to do this.";};

if (!(vehicle _target isEqualTo _target)) exitWith {hint "You cannot teleport to this player as they are inside of a vehicle."};

player setPos (getPos _target);
hint format ["You have teleported to the location of <t color = '#7300e6'>%1</t>.",_target getVariable ["realname",name _target]];
