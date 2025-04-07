/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_finishMission";

if (canSuspend) exitWith {
    [ULP_fnc_finishMission, _this] call ULP_fnc_directCall;
};

_this params [
	["_type", "Delivery", [""]]
];

private _typeCfg = missionConfigFile >> "CfgMissions" >> _type;
if !(isClass _typeCfg || { alive player } || { !(isDowned(player)) }) exitWith {};

if !(_type in ULP_Missions) exitWith {
	[getText (_typeCfg >> "Messages" >> "onFinishWithoutMission")] call ULP_fnc_hint;
};

(ULP_Missions get _type) params [
	"_task", "_reward", "_eachFrame"
];

if ((player distance (taskDestination _task)) > 10) exitWith {
	["You're not close enough to complete this task!"] call ULP_fnc_hint;
};

private _onFinished = getText (_typeCfg >> "onFinished");
if !(_onFinished isEqualTo "") then {
	if !([_reward, _type] call compile _onFinished) exitWith {
		false breakOut "fn_finishMission";
	};
};

if !(_eachFrame isEqualTo -1) then { [_eachFrame] call ULP_fnc_removeEachFrame; };

_task setTaskState "Succeeded";
["TaskMaster"] call ULP_fnc_achieve;

private _message = format["Completed a %1", getText (_typeCfg >> "name")];
[getPlayerUID player, "Mission", [getText (_typeCfg >> "name"), _reward]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];

[_reward, false, _message] call ULP_fnc_addMoney;

if (["PoliticalSavings"] call ULP_fnc_hasGroupPerk) then {
	_groupReward = _reward * 0.25;

	[[] call ULP_fnc_groupId, _groupReward, true] remoteExecCall ["ULP_SRV_fnc_updateGroupFunds", RSERV];
	[format ["Due to your group level, <t color='#B92DE0'>%1%2</t> has been given as a bonus and added to your group funds", "£", [_groupReward] call ULP_fnc_numberText]] call ULP_fnc_hint;
};

private _xp = getNumber (_typeCfg >> "Rewards" >> "xpReward");
if (_xp > 0) then { [_xp, _message] call ULP_fnc_addXP; };

private _rep = [getNumber (_typeCfg >> "Rewards" >> "repReward")] call ULP_fnc_bool;
if (_rep) then { [player, missionConfigFile >> "CfgReputation" >> "Types" >> "Mission"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV]; };

private _msg = getText (_typeCfg >> "Messages" >> "onFinished");
if !(_msg isEqualTo "") then {
	[format [getText (_typeCfg >> "Messages" >> "onFinished"), [_reward] call ULP_fnc_numberText]] call ULP_fnc_hint;
};

ULP_Missions deleteAt _type;

[3, _task, { player removeSimpleTask _this; }] call ULP_fnc_waitExecute;