/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_finishMission";

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

if !(_eachFrame isEqualTo -1) then { [_eachFrame] call ULP_fnc_removeEachFrame; };

_task setTaskState "Succeeded";
["TaskMaster"] call ULP_fnc_achieve;

private _message = format["Completed a %1", getText (_typeCfg >> "name")];

[_reward, false, _message] call ULP_fnc_addMoney;

private _xp = getNumber (_typeCfg >> "Rewards" >> "xpReward");
if (_xp > 0) then { [_xp, _message] call ULP_fnc_addXP; };

private _msg = getText (_typeCfg >> "Messages" >> "onFinished");
if !(_msg isEqualTo "") then {
	[format [getText (_typeCfg >> "Messages" >> "onFinished"), [_reward] call ULP_fnc_numberText]] call ULP_fnc_hint;
};

ULP_Missions deleteAt _type;

[3, _task, { player removeSimpleTask _this; }] call ULP_fnc_waitExecute;