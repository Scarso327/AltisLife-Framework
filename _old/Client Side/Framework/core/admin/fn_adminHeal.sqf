#include "..\..\script_macros.hpp"
/*
    File: fn_adminHeal.sqf
    Author: Lewis Mackinnon
*/

if ((FETCH_CONST(life_adminlevel) < 2) && admin_duty) exitWith {closeDialog 0; hint "You must be <t color = '#7300e6'>on-duty</t> to use this."};

private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);
_target = call compile format ["%1", _target];

if (isNil "_target" || isNull _target) exitWith {};

_target setDamage 0;
life_thirst = 100;
life_hunger = 100;

if (FETCH_CONST(life_adminlevel) > 0) then {
    hint format ["<t color = '#7300e6'>%1</t> has healed <t color = '#7300e6'>%2</t>.",player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
};