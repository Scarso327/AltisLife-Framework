/*
** Author: Jack "Scarso" Farhall
** Description: Adds polling station scroll actions to given trader
** Usage:
** 	[this] call ULP_fnc_addPollingStation;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addPollingStation";

_this params [
	["_trader", objNull, [objNull]]
];

if (isNull _trader) exitWith {};

_trader addAction ["<t color='#B528D0'>[GOV]</t> Polling Station", { _this call ULP_fnc_openPollingStation }, 
	nil, 1.5, true, true, "", "missionNamespace getVariable [""ULP_SRV_Setting_Election"", false]", 5];

_trader addAction ["<t color='#B528D0'>[GOV]</t> Rig Polling Station", { _this call ULP_fnc_rigPollingStation }, 
	nil, 1.5, true, true, "", "missionNamespace getVariable [""ULP_SRV_Setting_Election"", false] && { [""PollRigging"", group _this] call ULP_fnc_hasGroupPerk } && { !((_target getVariable [""rigged_group"", grpNull]) isEqualTo (group _this)) }", 5];

_trader addAction ["<t color='#B528D0'>[GOV]</t> Election Enlistment", { [] call ULP_fnc_enlist }, 
	nil, 1.5, true, true, "", "!(missionNamespace getVariable [""ULP_SRV_Setting_Election"", false])", 5];

[_trader, "Polling Office"] call ULP_fnc_setTraderName;