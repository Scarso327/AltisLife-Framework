/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_houseBreakInAlert";

_this params [
	["_building", objNull, [objNull]],
	["_message", "A house is being broken into!", [""]]
];

private _units = ["Police"] call ULP_fnc_allMembers;

private _hasGroupUpgrade = [_building, "CentralAlarmUpgrade"] call ULP_fnc_hasUpgrade;

if ([_building, "PersonalAlarmUpgrade"] call ULP_fnc_hasUpgrade || { _hasGroupUpgrade }) then {
	_units append (allPlayers select { [_building, _x, _hasGroupUpgrade] call ULP_fnc_isHouseOwner });
};

["BreakIn", _message, _units] call ULP_fnc_sendMessage;