#include "..\..\script_macros.hpp"
/*
    File: fn_adminSpectate.sqf
    Author: ColinM9991

    Description:
    Spectate the chosen player.
*/
if (FETCH_CONST(life_adminlevel) < 3) exitWith {closeDialog 0;};

private _unit = lbData[2902,lbCurSel (2902)];
_unit = call compile format ["%1", _unit];
if (isNil "_unit") exitWith {};
if (isNull _unit) exitWith {};
if (_unit == player) exitWith {hint "You are unable to do this.";};

closeDialog 0;

_unit switchCamera "INTERNAL";
hint format ["You are now spectating %1.\n\nPress F10 to stop spectating.",_unit getVariable ["realname",name _unit]];
AM_Exit = (findDisplay 46) displayAddEventHandler ["KeyDown", "if ((_this select 1) == 68) then {(findDisplay 46) displayRemoveEventHandler ['KeyDown',AM_Exit]; player switchCamera 'INTERNAL'; hint 'You have stopped spectating.';}; false"];
