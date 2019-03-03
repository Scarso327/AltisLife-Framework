#include "..\..\script_macros.hpp"
/*
    File: fn_adminDebugCon.sqf
    Author: ColinM9991

    Description:
    Opens the Debug Console.
*/
if (FETCH_CONST(life_adminlevel) < 5) exitWith {closeDialog 0; hint "You are unable to use this.";};
life_admin_debug = true;

createDialog "RscDisplayDebugPublic";
[0,format ["%1 has opened the debug console.",profileName]] remoteExecCall ["life_fnc_broadcast",RCLIENT];
