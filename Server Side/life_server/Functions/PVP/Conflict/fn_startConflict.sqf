/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_startConflict";

private _location = _this;

["onStartConflict", [_location]] remoteExecCall ["ULP_fnc_invokeEvent", RANY];