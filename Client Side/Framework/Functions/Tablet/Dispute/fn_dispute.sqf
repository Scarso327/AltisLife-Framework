/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_dispute";

_display = _this;
if (isNull _display) exitWith {};

// Stop spam...
if (time < (missionNamespace getVariable ["ULP_LastDispute", 0])) exitWith {
	hint "You've disputed someone recently, please wait...";
	["Home"] call ULP_fnc_setScreen;
	false
};

[ (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), ["Police", "Medic", "Civilian"], [_display], {
	_this params [
		["_display", displayNull, [displayNull]],
		["_selectDisplay", displayNull, [displayNull]]
	];

	if (isNull _selectDisplay || { isNull _display }) exitWith {};

	private _list = _selectDisplay displayCtrl 3809;

	private _player = (_list tvData (tvCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _player) exitWith {
		hint "You didn't select anyone to dispute...";
	};
	
	missionNamespace setVariable ["ULP_LastDispute", time + 5];
	
	[missionConfigFile >> "CfgMessages" >> "Dispute", format ["%1 would like you to come onto teamspeak to discuss a situation...", name player], _player] call ULP_fnc_sendMessage;
	hint format ["You have disputed %1", name _player];

	[getPlayerUID player, "Dispute", [getPlayerUID _player]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
}, false, true] call ULP_fnc_selectPlayer;

["Home"] call ULP_fnc_setScreen;