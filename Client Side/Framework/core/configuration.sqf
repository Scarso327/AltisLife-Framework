#include "..\script_macros.hpp"
/*
    File: configuration.sqf
    Author:

    Description:
    Master Life Configuration File
    This file is to setup variables for the client, there are still other configuration files in the system

*****************************
****** Backend Variables *****
*****************************
*/
life_query_time = time;
life_action_delay = time;
life_trunk_vehicle = objNull;
life_session_completed = false;
life_garage_store = false;
life_session_tries = 0;
life_net_dropped = false;
life_siren_active = false;
life_clothing_filter = 0;
life_clothing_uniform = -1;
life_redgull_effect = time;
life_is_processing = false;
life_bail_paid = false;
life_impound_inuse = false;
life_action_inUse = false;
life_spikestrip = objNull;
life_knockout = false;
life_interrupted = false;
life_respawned = false;
life_removeWanted = false;
life_action_gathering = false;
tawvd_addon_disable = true;
life_god = false;
life_frozen = false;
life_save_gear = [];
life_container_activeObj = objNull;
life_disable_getIn = false;
life_disable_getOut = false;
life_admin_debug = false;
life_civ_position = [];
life_markers = false;
life_markers_active = false;
life_canpay_bail = true;
life_storagePlacing = scriptNull;

//Settings
life_settings_enableNewsBroadcast = profileNamespace getVariable ["life_enableNewsBroadcast", true];
life_settings_enableSidechannel = profileNamespace getVariable ["life_enableSidechannel", true];
life_settings_tagson = profileNamespace getVariable ["life_settings_tagson", true];
life_settings_revealObjects = profileNamespace getVariable ["life_settings_revealObjects", true];
life_settings_viewDistanceFoot = profileNamespace getVariable ["life_viewDistanceFoot", 1250];
life_settings_viewDistanceCar = profileNamespace getVariable ["life_viewDistanceCar", 1250];
life_settings_viewDistanceAir = profileNamespace getVariable ["life_viewDistanceAir", 1250];

//Uniform price (0),Hat Price (1),Glasses Price (2),Vest Price (3),Backpack Price (4)
life_clothing_purchase = [-1, -1, -1, -1, -1];
/*
*****************************
****** Weight Variables *****
*****************************
*/
life_maxWeight = LIFE_SETTINGS(getNumber, "total_maxWeight");
life_carryWeight = 0; //Represents the players current inventory weight (MUST START AT 0).

/*
*****************************
****** Life Variables *******
*****************************
*/
life_net_dropped = false;
life_use_atm = true;
life_is_arrested = false;
life_is_alive = false;
life_delivery_in_progress = false;
life_thirst = 100;
life_hunger = 100;
CASH = 0;

life_istazed = false;
life_isknocked = false;
life_vehicles = [];

FF_Drinks = [];
FF_Food = [];

/*
    Master Array of items?
*/
//Setup variable inv vars.
{
    missionNamespace setVariable [ITEM_VARNAME(configName _x), 0];
    
    // Setup Eat/Drink Settings...
    _cfgEdible = (_x >> "edibility"); // Config....

    // Variables...
    _isEdible = (getArray(_cfgEdible >> "edible")) select 0;
    _type = (getArray(_cfgEdible >> "edible")) select 1;
    _item = getText(_x >> "variable");

    if (_isEdible isEqualTo 1) then {
        switch (_type) do {
            case "Hunger": {
                FF_Food pushBack _item;
            };
            case "Thirst": {
                FF_Drinks pushBack _item;
            };
            default { // Both...
                FF_Drinks pushBack _item;
                FF_Food pushBack _item;
            };
        };
    };
} forEach ("true" configClasses (missionConfigFile >> "CfgItems"));

/* Setup the BLAH! */
{
    _varName = getText(_x >> "variable");
    _sideFlag = getText(_x >> "side");

    missionNamespace setVariable [LICENSE_VARNAME(_varName,_sideFlag), false];
} forEach ("true" configClasses (missionConfigFile >> "CfgLicenses"));
