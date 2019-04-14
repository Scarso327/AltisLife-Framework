class CfgShops {
    class general_market {
        name = "General Market";
        conditions = "";
        items[] = { "water", "soda", "energy_drink", "apple", "mango", "coconut", "baguette", "croissant", "crepe", "energy_bar", "first_aid_kit", "lockpick", "pickaxe", "fuel_can", "empty_fuel_can", "empty_barrel" };
    };

    class property_agents {
        name = "Property Agents";
        conditions = "";
        items[] = { "small_container", "large_container" };
    };
    
    class tea_room {
        name = "Tea Room";
        conditions = "";
        items[] = { "red_bush", "pg_tips", "earl_grey", "green_tea", "coffee", "water", "soda", "english_breakfast", "tea_cake", "crumpet", "toast", "scone" };
    };

    class fish_and_chip_shop {
        name = "Fish & Chip Shop";
        conditions = "";
        items[] = { "water", "soda", "cheesy_chips", "fish_chips", "sausage_supper", "pasty_chips", "burger" };
    };

    class fuel_station_market {
        name = "Fuel Station Market";
        conditions = "";
        items[] = { "water", "soda", "energy_drink", "energy_bar", "first_aid_kit", "lockpick", "fuel_can", "empty_fuel_can" };
    };

    class fish_market {
        name = "Fish Market";
        conditions = "";
        items[] = { "raw_salema", "cooked_salema", "raw_ornate", "cooked_ornate", "cooked_tuna", "raw_mullet", "cooked_mullet", "raw_catshark", "cooked_catshark" };
    };

    class local_pub {
        name = "Local Pub";
        conditions = "";
        items[] = { "Apple Schnapps", "mango_schnapps", "cococut_schnapps", "cider", "beer", "whisky", "wine" };
    };

    class casino_cashier {
        name = "Casino Cashier";
        conditions = "";
        items[] = { "1k_chip", "5k_chip", "10k_chip", "25k_chipbeer", "50k_chip", "100k_chip" };
    };

    class syndikat_outpost {
        name = "Syndikat Outpost";
        conditions = "playerSide isEqualTo civilian && license_civ_syndikat";
        items[] = { "water", "soda", "energy_drink", "energy_bar", "first_aid_kit", "lockpick", "pickaxe", "fuel_can", "empty_fuel_can", "blindfold", "gag", "ear_clots", "bolt_cutter" };
    };

    class gold_buyer {
        name = "Gold Buyer";
        conditions = "";
        items[] = { "branded_gold_bar", "unbranded_gold_bar" };
    };

    class banana_trader {
        name = "Banana Trader";
        conditions = "";
        items[] = { "bannana" };
    };

    class rice_trader {
        name = "Rice Trader";
        conditions = "";
        items[] = { "rice" };
    };

    class lumber_trader {
        name = "Lumber Trader";
        conditions = "";
        items[] = { "wood", "lumber" };
    };

    class coal_plant {
        name = "Coal Plant";
        conditions = "";
        items[] = { "coal" };
    };

    class coral_exports {
        name = "Coral Exports";
        conditions = "";
        items[] = { "coral" };
    };

    class mineral_exports {
        name = "Mineral Exports";
        conditions = "";
        items[] = { "tin_ore", "tin_bar", "copper_ore", "copper_bar", "silver_ore", "silver_bar", "iron_ore", "iron_bar", "tin_ore", "tin_bar", "platinum_ore", "platinum_bar" };
    };

    class cement_trader {
        name = "Cement Trader";
        conditions = "";
        items[] = { "rock", "cement" };
    };

    class oil_exports {
        name = "Oil Exports";
        conditions = "";
        items[] = { "crude_oil", "refined_oil" };
    };

    class iridium_exports {
        name = "Iridium Exports";
        conditions = "";
        items[] = { "iridium_ore", "iridium_bar" };
    };

    class gem_trader {
        name = "Gem Trader";
        conditions = "";
        items[] = { "uncut_opal", "cut_opal", "uncut_sapphire", "cut_shappire", "uncut_ruby", "cut_ruby", "uncut_emerald", "cut_emerald", "uncut_diamond", "cut_diamond" };
    };

    class drug_dealer {
        name = "Drug Dealer";
        conditions = "";
        items[] = { "cannabis", "marijuana", "refined_marijuana", "opium", "heroin", "refined_heroin", "coca", "cocaine", "refined_cocaine", "ephedrine", "methamphetamine", "refined_methamphetamine" };
    };

    class turtle_dealer {
        name = "Turtle Dealer";
        conditions = "";
        items[] = { "raw_turtle", "cooked_turtle" };
    };

    class hmp_makret {
        name = "HMP Market";
        conditions = "";
        items[] = { "water", "baguette", "first_aid_kit", "pickaxe", "rock" };
    };

    class walkin_clinic {
        name = "Walk-In Clinic";
        conditions = "";
        items[] = { "water", "baguette", "first_aid_kit", "blood_bag", "stretcher" };
    };

    class tpc_market {
        name = "TPC Market";
        conditions = "playerSide isEqualTo west";
        items[] = { "water", "soda", "energy_drink", "energy_bar", "first_aid_kit", "lockpick", "fuel_can", "empty_fuel_can", "jaws_of_life", "breathalyzer", "stinger", "gps_tracker", "road_barrier", "road_cone" };
    };

    class nhs_market {
        name = "NHS Market";
        conditions = "playerSide isEqualTo indpendent";
        items[] = { "water", "soda", "energy_drink", "energy_bar", "first_aid_kit", "lockpick", "fuel_can", "empty_fuel_can", "jaws_of_life", "breathalyzer", "blood_bag", "stretcher", "defibrillator", "road_barrier", "road_cone" };
    };
};
