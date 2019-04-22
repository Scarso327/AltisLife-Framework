#include "..\script_macros.hpp"
/*
    File: fn_survival.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    All survival? things merged into one thread.
*/
private ["_fnc_food","_fnc_water","_foodTime","_waterTime","_bp","_walkDis","_lastPos","_curPos"];
_fnc_food =  {
    if (life_hunger < 2) then {player setDamage 1; hint "You have starved to death.";}
    else
    {
        life_hunger = life_hunger - 10;
        [] call FF_fnc_hudUpdate;
        if (life_hunger < 2) then {player setDamage 1; hint "You have starved to death.";};
        switch (life_hunger) do {
            case 30: {hint "You haven't eaten anything in awhile, You should find something to eat soon!";};
            case 20: {hint "You are starting to starve, you need to find something to eat otherwise you will die.";};
            case 10: {
                hint "You are now starving to death, you will die very soon if you don't eat something.";
                if (LIFE_SETTINGS(getNumber,"player_fatigue") isEqualTo 1) then {player setFatigue 1;};
            };
        };
    };
};

_fnc_water = {
    if (life_thirst < 2) then {player setDamage 1; hint "You have died from dehydration.";}
    else
    {
        life_thirst = life_thirst - 10;
        [] call FF_fnc_hudUpdate;
        if (life_thirst < 2) then {player setDamage 1; hint "You have died from dehydration.";};
        switch (life_thirst) do  {
            case 30: {hint "You haven't drank anything in awhile, You should find something to drink soon.";};
            case 20: {
                hint "You haven't drank anything in along time, you should find something to drink soon or you'll start to die from dehydration.";
                if (LIFE_SETTINGS(getNumber,"player_fatigue") isEqualTo 1) then {player setFatigue 1;};
            };
            case 10: {
                hint "You are now suffering from severe dehydration find something to drink quickly!";
                if (LIFE_SETTINGS(getNumber,"player_fatigue") isEqualTo 1) then {player setFatigue 1;};
            };
        };
    };
};

//Setup the time-based variables.
_foodTime = time;
_waterTime = time;
_walkDis = 0;
_bp = "";
_lastPos = visiblePosition player;
_lastPos = (_lastPos select 0) + (_lastPos select 1);
_lastState = vehicle player;

for "_i" from 0 to 1 step 0 do {
    /* Thirst / Hunger adjustment that is time based */
    if ((time - _waterTime) > 600 && {!life_god}) then {[] call _fnc_water; _waterTime = time;};
    if ((time - _foodTime) > 850 && {!life_god}) then {[] call _fnc_food; _foodTime = time;};

    /* Adjustment of carrying capacity based on backpack changes */
    if (backpack player isEqualTo "") then {
        life_maxWeight = LIFE_SETTINGS(getNumber,"default_maxWeight");
        _bp = backpack player;
    } else {
        if (!(backpack player isEqualTo "") && {!(backpack player isEqualTo _bp)}) then {
            _bp = backpack player;
            life_maxWeight = LIFE_SETTINGS(getNumber,"default_maxWeight") + round(FETCH_CONFIG2(getNumber,"CfgVehicles",_bp,"maximumload") / 4);
        };
    };

    /* Check if the player's state changed? */
    if (!(vehicle player isEqualTo _lastState) || {!alive player}) then {
        [] call life_fnc_updateViewDistance;
        _lastState = vehicle player;
    };

    /* Check if the weight has changed and the player is carrying to much */
    if (life_carryWeight > life_maxWeight && {!isForcedWalk player} && {!life_god}) then {
        player forceWalk true;
        if (LIFE_SETTINGS(getNumber,"player_fatigue") isEqualTo 1) then {player setFatigue 1;};
        hint "You are over carrying your max weight! You will not be able to run or move fast till you drop some items!";
    } else {
        if (isForcedWalk player) then {
            player forceWalk false;
        };
    };

    /* Travelling distance to decrease thirst/hunger which is captured every second so the distance is actually greater then 650 */
    if (!alive player || {life_god}) then {_walkDis = 0;} else {
        _curPos = visiblePosition player;
        _curPos = (_curPos select 0) + (_curPos select 1);
        if (!(_curPos isEqualTo _lastPos) && {(isNull objectParent player)}) then {
            _walkDis = _walkDis + 1;
            if (_walkDis isEqualTo 650) then {
                _walkDis = 0;
                life_thirst = life_thirst - 5;
                life_hunger = life_hunger - 5;
                [] call FF_fnc_hudUpdate;
            };
        };
        _lastPos = visiblePosition player;
        _lastPos = (_lastPos select 0) + (_lastPos select 1);
    };
    uiSleep 1;
};
