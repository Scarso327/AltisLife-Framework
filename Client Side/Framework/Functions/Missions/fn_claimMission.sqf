/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_claimMission";

_this params [
	["_type", "Delivery", [""]],
	["_mission", "DP1", [""]]
];

private _typeCfg = missionConfigFile >> "CfgMissions" >> _type;
if !(isClass _typeCfg) exitWith {};

if (_type in ULP_Missions) exitWith {
	hint getText (_typeCfg >> "Messages" >> "onAlreadyHas");
};

private _location = selectRandom (("isClass _x" configClasses (_typeCfg >> "Locations")) select { !((configName _x) isEqualTo _mission) });

if (isNil "_location" || { _location isEqualTo [] }) exitWith {
	hint getText (_typeCfg >> "Messages" >> "onNoLocations");
};

private _pos = switch (true) do {
	case (isText (_location >> "pos")) : { getMarkerPos getText (_location >> "pos") };
	default { getArray (_location >> "pos") };
};

private _locName = getText (_location >> "name");

private _task = player createSimpleTask [format ["Mission_%1_%2", _type, _mission]];
_task setSimpleTaskDestination _pos;
_task setSimpleTaskDescription [format [getText (_typeCfg >> "description"), _locName], getText (_typeCfg >> "name"), ""];
_task setTaskState "Assigned";

if ((count ULP_Missions) isEqualTo 0) then {
	player setCurrentTask _task;
};

private _eachFrame = -1;
private _onEachFrame = getText (_typeCfg >> "eachFrame");
if !(_onEachFrame isEqualTo "") then {
	_eachFrame = [[_location, _pos], compile _onEachFrame] call ULP_fnc_addEachFrame;
};

private _onClaimed = getText (_typeCfg >> "onClaimed");
if !(_onClaimed isEqualTo "") then {
	_pos call compile _onClaimed;
};

private _reward = round (getNumber (_typeCfg >> "Rewards" >> "moneyReward") * (player distance _pos));

ULP_Missions set [_type, [_task, _reward, _eachFrame]];
hint format [getText (_typeCfg >> "Messages" >> "onAssigned"), _locName];