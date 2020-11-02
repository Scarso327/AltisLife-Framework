#include "..\..\script_macros.hpp"
/*
    File: fn_adminTpHere.sqf
    Author: ColinM9991

    Description:
    Teleport selected player to you.
*/
if (FETCH_CONST(life_adminlevel) < 4) exitWith {closeDialog 0;};

private _target = lbData[2902,lbCurSel (2902)];
_target = call compile format ["%1", _target];
if (isNil "_target" || isNull _target) exitWith {};
if (_target == player) exitWith {hint "You can't do that dumbass.";};

if (!(vehicle _target isEqualTo _target)) exitWith {hint "You cannot teleport the player here because they are inside of a vehicle."};
_target setPos (getPos player);
hint format ["You have teleported %1 to your location.",_target getVariable ["realname",name _target]];
