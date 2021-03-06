#define true 1
#define false 0

class Life_Settings {
    framework_version = "5.0.0"; 
    local_version = "1.0.0";

    /* Data Logging Settings */
    battlEye_friendlyLogging = false;
    player_advancedLog = false;
    player_moneyLog = false;
    player_deathLog = false;

    /* Escape Menu Configuration */
    escapeMenu_timer = 20;
    escapeMenu_displayExtras = true;
    escapeMenu_displayText = "Thanks for playing!";

    /* Basic System Configurations */
    total_maxWeight = 24;

    sync_delay = 5 * 60;
    abort_delay = 10;

    /* Player Data Saving */
    save_virtualItems = true;
    saved_virtualItems[] = { 
        "pickaxe",
        "toolkit" 
    };
    save_playerStats = true;
    save_civilian_weapons = true;

    /* Vehicle Data Saving */
    save_vehicle_virtualItems = true;
    save_vehicle_items[] = { 
        "pickaxe",
        "toolkit" 
    };
    save_vehicle_inventory = false;
    save_vehicle_fuel = true;
    save_vehicle_damage = true;
    save_vehicle_illegal = false; 

    /* Bank System Configurations */
    starting_bank = 50000;
    bank_transferTax = .02;

    atm_cooldown = 10;
    paycheck_period = 15;

    hm_required_number = 5;

    /* Clothing System Configurations */
    civ_skins = false;
    cop_extendedSkins = false;
    clothing_noTP = false;
    clothing_box = true;
    clothing_masks[] = { 
        "H_RacingHelmet_1_black_F", 
        "H_RacingHelmet_1_blue_F", 
        "H_RacingHelmet_1_green_F", 
        "H_RacingHelmet_1_orange_F", 
        "H_RacingHelmet_1_red_F", 
        "H_RacingHelmet_1_white_F", 
        "H_RacingHelmet_1_yellow_F", 
        "G_Balaclava_blk", 
        "G_Balaclava_combat", 
        "G_Balaclava_lowprofile", 
        "G_Balaclava_oli", 
        "G_Bandanna_aviator", 
        "H_BandMask_beast", 
        "H_BandMask_blk", 
        "H_BandMask_khk", 
        "G_Bandanna_oli", 
        "G_Bandanna_shades", 
        "G_Bandanna_sport", 
        "G_Bandanna_tan", 
        "G_Balaclava_TI_G_blk_F", 
        "G_Balaclava_TI_G_blk_F"
    };

    /* Item-related Restrictions */
    restrict_medic_weapons = true;
    restrict_clothingPickup = true; 
    restrict_weaponPickup = false;
    restricted_uniforms[] = {};
    restricted_weapons[] = {};

    /* Search & Seizure System Configurations */
    seize_exempt[] = {};
    seize_uniform[] = {};
    seize_vest[] = {};
    seize_headgear[] = {};

    /* Fuel System Configurations */
    pump_service = true;
    fuel_cost = 80;
    service_aircraft = 1000;
    fuelCan_refuel = 250;

    /* Property System Configurations */
    house_limit = 1;
    houseGarage_buyPrice = 0;
    houseGarage_sellPrice = 0;

    /* Group System Configurations */
    group_price = 10000;
    group_upgradeBase = 10000; 
    gang_area[] = {"gang_area_1","gang_area_2","gang_area_3"};

    /* Player Job System Configurations */
    delivery_points[] = {};
    fuelTank_winMultiplier = 1;

    /* Hunting & Fishing System Configurations */
    animaltypes_fish[] = {};
    animaltypes_hunting[] = {};

    /* Prison System Configurations */
    jail_seize_vItems[] = {};
    jail_seize_inventory = false;
    sendtoJail_locations[] = { "hmp" };
    jail_timeMultiplier = 15;

    /* Vehicle System Configurations */
    chopShop_vehicles[] = { "Car", "Air", "Ship" };
    vehicleShop_rentalOnly[] = {
        "B_G_Quadbike_01_F",
        "C_IDAP_Offroad_02_unarmed_F",
        "C_IDAP_Offroad_01_F",
        "C_IDAP_Van_02_transport_F",
        "C_IDAP_Van_02_vehicle_F",
        "C_IDAP_Heli_Transport_02_F"
    };
    vehicleShop_3D = false;

    vehicle_purchase_multiplier = 1;
    vehicle_rental_multiplier = .60;
    vehicle_sell_multiplier = .45;
    vehicle_chopShop_multiplier = .40;
    vehicle_storage_fee_multiplier = .01;
    vehicle_cop_impound_multiplier = .3;

    /* Wanted System Settings */
    crimes[] = {
        {"STR_Crime_187V","650","187V"},
        {"STR_Crime_187","2000","187"},
        {"STR_Crime_901","450","901"},
        {"STR_Crime_215","200","215"},
        {"STR_Crime_213","1000","213"},
        {"STR_Crime_211","100","211"},
        {"STR_Crime_207","350","207"},
        {"STR_Crime_207A","200","207A"},
        {"STR_Crime_390","1500","390"},
        {"STR_Crime_487","150","487"},
        {"STR_Crime_488","70","488"},
        {"STR_Crime_480","100","480"},
        {"STR_Crime_481","100","481"},
        {"STR_Crime_482","500","482"},
        {"STR_Crime_483","950","483"},
        {"STR_Crime_459","650","459"},
        {"STR_Crime_666","200","666"},
        {"STR_Crime_667","4500","667"},
        {"STR_Crime_668","1500","668"},
        {"STR_Crime_1","250","1"},
        {"STR_Crime_2","200","2"},
        {"STR_Crime_3","150","3"},
        {"STR_Crime_4","250","4"},
        {"STR_Crime_5","100","5"},
        {"STR_Crime_6","80","6"},
        {"STR_Crime_7","150","7"},
        {"STR_Crime_8","5000","8"},
        {"STR_Crime_9","5000","9"},
        {"STR_Crime_10","15000","10"},
        {"STR_Crime_11","10000","11"},
        {"STR_Crime_12","2500","12"},
        {"STR_Crime_13","1500","13"},
        {"STR_Crime_14","500","14"},
        {"STR_Crime_15","2500","15"},
        {"STR_Crime_16","1500","16"},
        {"STR_Crime_17","100","17"},
        {"STR_Crime_18","1500","18"},
        {"STR_Crime_19","2500","19"},
        {"STR_Crime_20","500","20"},
        {"STR_Crime_21","500","21"},
        {"STR_Crime_22","2000","22"},
        {"STR_Crime_23","5000","23"},
        {"STR_Crime_24","10000","24"},
        {"STR_Crime_25","20000","25"}
    };

    doesntThreaten[] = { "", "Binocular", "Rangefinder" };
};

#include "CfgLicenses.hpp"
#include "CfgWeapons.hpp"
#include "CfgProperty.hpp"
#include "CfgFactions.hpp"
#include "CfgSpawns.hpp"
#include "CfgClothing.hpp"
#include "CfgMedical.hpp"
#include "CfgStores.hpp"
#include "CfgItems.hpp"
#include "CfgVirtualItems.hpp"
#include "CfgSurvival.hpp"
#include "CfgCredits.hpp"
#include "CfgTags.hpp"
#include "CfgGathering.hpp"
#include "CfgProcessing.hpp"
#include "CfgApps.hpp"
#include "CfgVehicles\CfgVehicles.hpp"
#include "CfgVehicles\CfgVehicleStores.hpp"
#include "CfgInteractions.hpp"