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
	["You've disputed someone recently, please wait..."] call ULP_fnc_hint;
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
		["You didn't select anyone to dispute!"] call ULP_fnc_hint;
	};
	
	missionNamespace setVariable ["ULP_LastDispute", time + 5];
	
	[missionConfigFile >> "CfgMessages" >> "Dispute", format ["%1 would like for you to come onto teamspeak (ts3.mantlenetwork.co.uk) to discuss a situation", name player], _player] call ULP_fnc_sendMessage;
	[format ["You have disputed <t color='#B92DE0'>%1</t>.", name _player]] call ULP_fnc_hint;

	[getPlayerUID player, "Dispute", [getPlayerUID _player]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
}, false, true] call ULP_fnc_selectPlayer;

["Home"] call ULP_fnc_setScreen;