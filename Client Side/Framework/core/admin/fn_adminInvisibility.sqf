#include "..\..\script_macros.hpp"
/*
    File: fn_adminInvisibility.sqf
    Author: Lewis Mackinnon
*/

if ((FETCH_CONST(life_adminlevel) < 2) && admin_duty) exitWith {closeDialog 0; hint "You must be <t color = '#7300e6'>on-duty</t> to use this."};

private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);
_target = call compile format ["%1", _target];

if (isNil "_target" || isNull _target) exitWith {};

if (admin_invisibility) then {
    _target hideObject false; 
}

else {
    _target hideObject true; 
}

if (FETCH_CONST(life_adminlevel) > 0) then {
    hint format ["<t color = '#7300e6'>%1</t> has made <t color = '#7300e6'>%2</t> invisible.",player getVariable ["realname", name player],_target getVariable ["realname", name _target]]];
};