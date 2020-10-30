#include "..\..\script_macros.hpp"
/*
    File: fn_adminSpectate.sqf
    Author: ColinM9991
*/

if ((FETCH_CONST(life_adminlevel) < 2) && admin_duty) exitWith {closeDialog 0; hint "You must be <t color = '#7300e6'>on-duty</t> to use this."};

private _target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);
_target = call compile format ["%1", _target];

if (isNil "_target" || isNull _target) exitWith {};
if (_target == player) exitWith {hint "You are unable to do this.";};

closeDialog 0;

_target switchCamera "INTERNAL";
hint format ["You are now spectating <t color = '#7300e6'>%1</t>.\n\nPress <t color = '#7300e6'>F10</t> to stop spectating.",_target getVariable ["realname",name _target]];
if (FETCH_CONST(life_adminlevel) > 0) then {
    hint format ["<t color = '#7300e6'>%1</t> is spectating <t color = '#7300e6'>%2</t>.",player getVariable ["realname", name player],_target getVariable ["realname", name _target]];
};
AM_Exit = (findDisplay 46) displayAddEventHandler ["KeyDown", "if ((_this select 1) == 68) then {(findDisplay 46) displayRemoveEventHandler ['KeyDown',AM_Exit]; player switchCamera 'INTERNAL'; hint 'You have stopped spectating.';}; false"];
