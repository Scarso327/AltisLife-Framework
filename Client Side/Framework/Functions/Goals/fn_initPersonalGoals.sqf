/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initPersonalGoals";

if (canSuspend) exitWith {
    [ULP_fnc_initPersonalGoals, _this] call ULP_fnc_directCall;
};

_this params [
	["_daily", createHashMap, [createHashMap]],
	["_weekly", createHashMap, [createHashMap]]
];

["Setting Personal Goals"] call ULP_fnc_logIt;

private _addedEvhs = [];

{
	_x params [
		["_cfgName", "", [""]],
		["_current", createHashMap, [createHashMap]]
	];

	private _cfg = missionConfigFile >> "CfgGoals" >> "Personal" >> _cfgName;
	if (isClass _cfg) then {
		private _goals = _current;

		// If the database doesn't return anything then its time to set new for this...
		if (count _goals <= 0) then {
			_goals = ("call compile getText (_x >> ""condition"")" configClasses (_cfg));
			
			if !(_goals isEqualTo []) then {
				private _selectedGoals = createHashMap;

				for "_i" from 0 to (getNumber (_cfg >> "Amount") - 1) do {
					if (_goals isEqualTo []) exitWith {}; // Found them all...
					private _goal = selectRandom _goals;
					_goals deleteAt (_goals find _goal);
					_selectedGoals set [configName _goal, 0];
				};

				_goals = _selectedGoals;
			};
		};

		private _goalsVar = missionNamespace getVariable [format["ULP_Goals_%1", _cfgName], createHashMap];

		{
			private _goalCfg = _cfg >> _x;

			if (isClass _goalCfg) then {
				private _tiers = getArray (_goalCfg >> "tiers");
				private _tier = _tiers findIf { _y <= _x };
				if (_tier <= -1) then { _tier = 0; };

				private _type = getText (_goalCfg >> "type");
				private _goal = [_x, _y, _tier, ((_tiers select ((count _tiers) - 1)) isEqualTo _y)];

				if (_type in _goalsVar) then {
					private _goalsInType = _goalsVar get _type;
					_goalsInType pushBack _goal;
					_goalsVar set [_type, _goalsInType];
				} else {
					_goalsVar set [_type, [_goal]];
				};
			};
		} forEach _goals;

		// Setup EventHandlers...
		{
			if !(_x in _addedEvhs) then {
				switch (_x) do {
					case "GATHERING": {
						["GatheredVirtualItem", {
							if (["GATHERING", _this, {
								_this params ["_evhParams", "_goal", "_goalType"];
								_evhParams params [ "_gatheredItem", "_amount" ];
								_goal params [ "_cfgName", "_progress", "_tier" ];

								private _goalCfg = missionConfigFile >> "CfgGoals" >> "Personal" >> _goalType >> _cfgName;
								private _item = getText (_goalCfg >> "item");

								if (_item isEqualTo _gatheredItem) then {
									_goal = [_goal, _goalCfg] call ULP_fnc_increaseGoal;
								};

								_goal
							}] call ULP_fnc_handleGoal) then {
								[_event, _eventId] call ULP_fnc_removeEventHandler;
							};
						}] call ULP_fnc_addEventHandler;
					};
					case "SELLING": {
						["SoldVirtualItem", {
							if (["SELLING", _this, {
								_this params ["_evhParams", "_goal", "_goalType"];
								_evhParams params [ "_soldItem", "_amount" ];
								_goal params [ "_cfgName", "_progress", "_tier" ];

								private _goalCfg = missionConfigFile >> "CfgGoals" >> "Personal" >> _goalType >> _cfgName;
								private _item = getText (_goalCfg >> "item");

								if (_item isEqualTo _soldItem) then {
									_goal = [_goal, _goalCfg] call ULP_fnc_increaseGoal;
								};

								_goal
							}] call ULP_fnc_handleGoal) then {
								[_event, _eventId] call ULP_fnc_removeEventHandler;
							};
						}] call ULP_fnc_addEventHandler;
					};
				};

				_addedEvhs pushBackUnique _x;
			};
		} forEach (keys _goalsVar);

		missionNamespace setVariable [format["ULP_Goals_%1", _cfgName], _goalsVar];
	};
} forEach [
	["Daily", _daily],
	["Weekly", _weekly]
];

[] call ULP_fnc_saveGoals;