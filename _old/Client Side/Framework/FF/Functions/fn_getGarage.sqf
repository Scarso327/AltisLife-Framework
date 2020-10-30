/*
	@File: fn_getGarage.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Actually does the garage setup...
*/
#include "..\..\script_macros.hpp"
private _params = _this # 3;
_params params [
	["_spawmpoint", "", [""]],
	["_type", "", [""]]
];

if (_type isEqualTo "" || {_spawmpoint isEqualTo ""}) exitWith { systemChat "Garage Failuire" };

[getPlayerUID player,playerSide,_type,player] remoteExecCall ["TON_fnc_getVehicles", RSERV];

createDialog "Life_impound_menu";

disableSerialization;
ctrlSetText[2802,"Fetching Vehicles...."];

life_garage_sp = _spawmpoint;
life_garage_type = _type;