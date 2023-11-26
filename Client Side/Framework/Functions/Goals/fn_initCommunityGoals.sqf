/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initCommunityGoals";

if (canSuspend) exitWith {
    [ULP_fnc_initCommunityGoals, _this] call ULP_fnc_directCall;
};

{
	[_x, {
		{
			if (isNull _x || { _x getVariable ["complete", false] }) exitWith {};

			[format ["communityGoalContribution: '%1' invoked with '%2'", _event, _this], true] call ULP_fnc_logIt;

			private _goalCfg = _x getVariable ["config", configNull];

			if (!(isNull _goalCfg) && { [player, getArray (_goalCfg >> "factions")] call ULP_fnc_isFaction }) then {
				private _amount = [getText (_goalCfg >> "item"), _params] call compile getText (_goalCfg >> "Event" >> "getQuantity");
				if (_amount <= 0) exitWith {};

				[player, _x, _amount] remoteExecCall ["ULP_SRV_fnc_addCommunityGoalContribution", RSERV];
			};
		} forEach + ((missionNamespace getVariable ["ULP_CommunityGoals", createHashMap]) getOrDefault [_event, []]);
	}] call ULP_fnc_addEventHandler;
} forEach (keys (missionNamespace getVariable ["ULP_CommunityGoals", createHashMap]));

["CommunityGoalPaid", {
	_this params [ "_message" ];
	[_message] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;