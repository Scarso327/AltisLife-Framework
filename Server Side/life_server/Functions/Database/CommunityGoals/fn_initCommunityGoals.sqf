/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initCommunityGoals";

if (canSuspend) exitWith {
    [ULP_SRV_fnc_initCommunityGoals, _this] call ULP_fnc_directCall;
};

["Setting Up Community Goals..."] call ULP_fnc_logIt;

private _query = ["SELECT community_goals.id, community_goals.goal_cfg, DATEDIFF(community_goals.end_date, CURDATE()) as daysLeft, COALESCE((SELECT SUM(community_goal_contributions.contribution) FROM community_goal_contributions WHERE community_goal_contributions.goalId = community_goals.id), 0) AS progress FROM community_goals WHERE community_goals.paid = '0'", 2, true] call DB_fnc_asyncCall;

if (_query isEqualTo "") exitWith { ["No goals found..."] call ULP_fnc_logIt; };

private _communityGoals = createHashMap;

// Convert the goal_cfg column into the config itself
private _goals = (_query apply {
    _x set [1, missionConfigFile >> "CfgGoals" >> "Community" >> (_x # 1)];
    _x
});

// Handle completed community goals

{
    _goals deleteAt _forEachIndex; // Remove it from our active goals

    _x params [ "_id", "_goalCfg", "", "_progress" ];

    [_id, _goalCfg, _progress] call ULP_SRV_fnc_finishCommunityGoal;
} forEach + (_goals select { (_x # 2) <= 0 });

["Deleting Old Community Goals..."] call ULP_fnc_logIt;
["CALL deleteOldCommunityGoals", 1] call DB_fnc_asyncCall;

private _activeGoals = (_goals apply { configName (_x # 1) });

// Ensure we have met the minimum requirement for faction goals
private _factionMinimums = createHashMapFromArray getArray (missionConfigFile >> "CfgGoals" >> "Community" >> "amountPerFaction");

{
    private _cfgName = configName _x;
    
    private _minNumberForFactions = _factionMinimums getOrDefault [_cfgName, 0];
    private _difference = _minNumberForFactions - ({ _cfgName in getArray ((_x # 1) >> "factions") } count _goals);
    
    if (_difference > 0) then {
        private _factionGoals = (("isClass _x" configClasses (missionConfigFile >> "CfgGoals" >> "Community")) select { _cfgName in getArray (_x >> "factions") && { !(_cfgName in _activeGoals) } });

        for "_i" from 0 to (_difference - 1) do {
            if (_factionGoals isEqualTo []) exitWith {}; // There are no more goals left to use
            
            private _goal = selectRandom _factionGoals;
            _factionGoals deleteAt (_factionGoals find _goal);
            
            private _newGoal = [_goal] call ULP_SRV_fnc_addCommunityGoal;

            if !(_newGoal isEqualTo []) then {
                _goals pushBack _newGoal;
            };
        };
    };
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgFactions"));

// Add goals to server
{
    _x params [ "_id", "_goalCfg", "_daysLeft", "_progress" ];

    if (isClass _goalCfg && { _daysLeft >= 0 }) then {
        private _eventType = getText (_goalCfg >> "Event" >> "eventType");

        private _tiers = getArray (_goalCfg >> "tiers");
        private _max = _tiers param [((count _tiers) - 1), 0, [0]]; 

        private _obj = createSimpleObject ["A3\Weapons_f\empty.p3d", [0, 0, 0], false];
	    _obj setVariable ["id", _id];
        _obj setVariable ["config", _goalCfg, true];
        _obj setVariable ["days_left", _daysLeft];

        if (_progress >= _max) then {
            _obj setVariable ["complete", true, true];
        };

        private _goals = _communityGoals getOrDefault [_eventType, []];
        _goals pushBack _obj;
        _communityGoals set [_eventType, _goals];
    };
} forEach _goals;

missionNamespace setVariable ["ULP_CommunityGoals", _communityGoals, true];