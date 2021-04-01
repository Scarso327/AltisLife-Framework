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
	hint getText (_typeCfg >> "Messages" >> "onFinishWithoutMission");
};

(ULP_Missions get _type) params [
	"_task", "_reward", "_eachFrame"
];

if ((player distance (taskDestination _task)) > 10) exitWith {
	hint "You're not close enough to complete this task...";
};

if !(_eachFrame isEqualTo -1) then { [_eachFrame] call ULP_fnc_removeEachFrame; };

_task setTaskState "Succeeded";

private _message = format["Completed a %1", getText (_typeCfg >> "name")];

[_reward, false, _message] call ULP_fnc_addMoney;
[getNumber (_typeCfg >> "Rewards" >> "xpReward"), _message] call ULP_fnc_addXP;

hint format [getText (_typeCfg >> "Messages" >> "onFinished"), [_reward] call ULP_fnc_numberText];

[3, _task, { player removeSimpleTask _this; }] call ULP_fnc_waitExecute;