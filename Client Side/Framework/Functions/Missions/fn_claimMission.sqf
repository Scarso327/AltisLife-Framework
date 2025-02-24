/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_claimMission";

if (canSuspend) exitWith {
    [ULP_fnc_claimMission, _this] call ULP_fnc_directCall;
};

_this params [
	["_type", "Delivery", [""]],
	["_mission", "DP1", [""]]
];

private _typeCfg = missionConfigFile >> "CfgMissions" >> _type;
if !(isClass _typeCfg) exitWith { false };

if !([player, getArray (_typeCfg >> "factions")] call ULP_fnc_isFaction) exitWith {
	["Your faction can't do this mission..."] call ULP_fnc_hint;
	false
};

if !(call compile getText(_typeCfg >> "conditions")) exitWith {
	["You don't meet the requirements to do this mission..."] call ULP_fnc_hint;
	false
};

if (_type in ULP_Missions) exitWith {
	[getText (_typeCfg >> "Messages" >> "onAlreadyHas")] call ULP_fnc_hint;
	false
};

private _location = selectRandom (("isClass _x" configClasses (_typeCfg >> "Locations")) select { !((configName _x) isEqualTo _mission) });

if (isNil "_location" || { _location isEqualTo [] }) exitWith {
	[getText (_typeCfg >> "Messages" >> "onNoLocations")] call ULP_fnc_hint;
	false
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
	_eachFrame = [[_location, _pos, _type], compile _onEachFrame] call ULP_fnc_addEachFrame;
};

private _onClaimed = getText (_typeCfg >> "onClaimed");
if !(_onClaimed isEqualTo "") then {
	_pos call compile _onClaimed;
};

private _reward = getNumber (_typeCfg >> "Rewards" >> "moneyReward");

if (_reward > 0) then {
	_reward = _reward + (["Mission"] call ULP_fnc_getLegislation);

	if ([] call ULP_fnc_isGroup) then {
		private _buff = [group player, "Missions"] call ULP_fnc_groupBuff;
		if (_buff > 0) then { _reward = _reward + (_reward * _buff); };
	};

	_reward = round (_reward * (player distance _pos));
};

ULP_Missions set [_type, [_task, _reward, _eachFrame]];
[format [getText (_typeCfg >> "Messages" >> "onAssigned"), _locName]] call ULP_fnc_hint;

true