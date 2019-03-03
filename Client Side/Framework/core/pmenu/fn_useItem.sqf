#include "..\..\script_macros.hpp"
/*
    File: fn_useItem.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Main function for item effects and functionality through the player menu.
*/
private "_item";
disableSerialization;
if ((lbCurSel 2005) isEqualTo -1) exitWith {hint localize "STR_ISTR_SelectItemFirst";};
_item = CONTROL_DATA(2005);

switch (true) do {
    case (_item in FF_Drinks): {
        if ([false,_item,1] call life_fnc_handleInv) then {
            _sum = life_thirst + getNumber(missionConfigFile >> "CfgItems" >> _item >> "edibility" >> "value");
            switch (true) do {
                case (_val < 0 && _sum < 1): {life_thirst = 5;};
                case (_sum > 100): {life_thirst = 100;};
                default {life_thirst = _sum;};
            };
            if (LIFE_SETTINGS(getNumber,"player_fatigue") isEqualTo 1) then {player setFatigue 0;};
            if (_item isEqualTo "energy_drink" && {LIFE_SETTINGS(getNumber,"player_fatigue") isEqualTo 1}) then {
                [] spawn {
                    life_redgull_effect = time;
                    titleText[localize "STR_ISTR_RedGullEffect","PLAIN"];
                    player enableFatigue false;
                    waitUntil {!alive player || ((time - life_redgull_effect) > (3 * 60))};
                    player enableFatigue true;
                };
            };
        };
    };

    case (_item isEqualTo "bolt_cutter"): {
        [cursorObject] spawn life_fnc_boltcutter;
        closeDialog 0;
    };

    case (_item isEqualTo "explosive_charge"): {
        player reveal fed_bank;
        (group player) reveal fed_bank;
        [cursorObject] spawn life_fnc_blastingCharge;
        closeDialog 0;
    };

    case (_item isEqualTo "defusekit"): {
        [cursorObject] spawn life_fnc_defuseKit;
        closeDialog 0;
    };

    case (_item isEqualTo "small_container"): {
        [false] call life_fnc_storageBox;
    };

    case (_item isEqualTo "large_container"): {
        [true] call life_fnc_storageBox;
    };

    case (_item isEqualTo "stinger"): {
        if (!isNull life_spikestrip) exitWith {hint localize "STR_ISTR_SpikesDeployment"; closeDialog 0};
        if ([false,_item,1] call life_fnc_handleInv) then {
            [] spawn life_fnc_spikeStrip;
            closeDialog 0;
        };
    };

    case (_item isEqualTo "fuel_can"): {
        if !(isNull objectParent player) exitWith {hint localize "STR_ISTR_RefuelInVehicle"};
        [] spawn life_fnc_jerryRefuel;
        closeDialog 0;
    };

    case (_item isEqualTo "empty_fuel_can"): {
        [] spawn life_fnc_jerryCanRefuel;
        closeDialog 0;
    };

    case (_item isEqualTo "lockpick"): {
        [] spawn life_fnc_lockpick;
        closeDialog 0;
    };

    case (_item in FF_Food): {
        if (((getArray(missionConfigFile >> "CfgItems" >> _item >> "edibility" >> "edible")) select 0) isEqualTo 1) then {
            if ([false,_item,1] call life_fnc_handleInv) then {
                _val = getNumber(missionConfigFile >> "CfgItems" >> _item >> "edibility" >> "value");
                _sum = life_hunger + _val;
                switch (true) do {
                    case (_val < 0 && _sum < 1): {life_hunger = 5;}; //This adds the ability to set the entry edible to a negative value and decrease the hunger without death
                    case (_sum > 100): {life_hunger = 100;};
                    default {life_hunger = _sum;};
                };
                hint format["You've eaten %1 and gained %2 hunger", _item, _val];
            };
        };
    };

    default {
        hint localize "STR_ISTR_NotUsable";
    };
};

[] call life_fnc_p_updateMenu;
[] call FF_fnc_hudUpdate;