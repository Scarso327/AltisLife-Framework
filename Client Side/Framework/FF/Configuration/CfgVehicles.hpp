class CfgVehicleStores {
    class car_dealership {
        side = "civ";
        conditions = "license_civ_driving";
        vehicles[] = {
            { "C_Quadbike_01_F", "" },
            { "C_Hatchback_01_F", "" },
            { "C_Offroad_01_F", "" },
            { "C_Offroad_02_unarmed_F", "" },
            { "C_SUV_01_F", "" },
            { "C_Hatchback_01_sport_F", "" },
            { "C_Van_02_transport_F", "" },
            { "C_Van_02_vehicle_F", "" }
        };
    };

    class truck_dealership {
        side = "civ";
        conditions = "license_civ_trucking";
        vehicles[] = {
            { "C_Van_01_transport_F", "" },
            { "C_Van_01_box_F", "" },
            { "C_Van_01_fuel_F", "" },
            { "C_Truck_02_transport_F", "" },
            { "C_Truck_02_covered_F", "" },
            { "C_Truck_02_fuel_F", "" },
            { "B_Truck_01_mover_F", "" },
            { "B_Truck_01_transport_F", "" },
            { "B_Truck_01_covered_F", "" },
            { "B_Truck_01_ammo_F", "" },
            { "B_Truck_01_fuel_F", "" },
            { "B_Truck_01_box_F", "" },
            { "O_T_Truck_03_transport_ghex_F", "" },
            { "O_T_Truck_03_covered_ghex_F", "" },
            { "O_T_Truck_03_ammo_ghex_F", "" },
            { "O_T_Truck_03_fuel_ghex_F", "" },
            { "O_T_Truck_03_device_ghex_F", "" }
        };
    };

    class helicopter_dealership {
        side = "civ";
        conditions = "license_civ_piloting";
        vehicles[] = {
            { "C_Heli_Light_01_civil_F", "" },
            { "B_Heli_Light_01_F", "" },
            { "O_Heli_Light_02_unarmed_F", "" },
            { "I_Heli_Transport_02_F", "" }
        };
    };

    class plane_dealership {
        side = "civ";
        conditions = "license_civ_piloting";
        vehicles[] = {
            { "C_Plane_Civil_01_F", "" },
            { "I_Plane_Fighter_03_CAS_F", "" },
            { "B_Plane_CAS_01_F", "" },
            { "O_Plane_CAS_02_F", "" },
            { "I_Plane_Fighter_04_F", "" },
            { "B_Plane_Fighter_01_F", "" },
            { "O_Plane_Fighter_02_F", "" }
        };
    };

    class boat_dealership {
        side = "civ";
        conditions = "license_civ_boating";
        vehicles[] = {
            { "C_Scooter_Transport_01_F", "" }, // Premium Membership
            { "C_Rubberboat", "" },
            { "C_Boat_Civil_01_F", "" },
            { "C_Boat_Transport_02_F", "" }
        };
    };

    class chop_shop {
        side = "civ";
        conditions = "";
        vehicles[] = {
            { "B_G_Quadbike_01_F", "" }
        };
    };

    class go_karting_dealership {
        side = "civ";
        conditions = "";
        vehicles[] = {
            { "C_Kart_01_F", "" }
        };
    };

    class syndikat_outpost {
        side = "civ";
        conditions = "license_civ_syndikat";
        vehicles[] = {
            { "O_Quadbike_01_F", "" },
            { "O_G_Offroad_01_F", "" },
            { "I_C_Offroad_02_unarmed_F", "" },
            { "I_C_Offroad_02_LMG_F", "" },
            { "O_G_Van_02_transport_F", "" },
            { "O_G_Van_02_vehicle_F", "" },
            { "O_G_Van_01_transport_F", "" }
        };
    };

    class tpc_general_dealership {
        side = "cop";
        conditions = "playerSide isEqualTo west";
        vehicles[] = {
            { "C_Quadbike_01_F", "call life_coplevel >= 1" },
            { "C_Hatchback_01_F", "call life_coplevel >= 2" },
            { "C_SUV_01_F", "call life_coplevel >= 2" },
            { "C_Offroad_01_F", "call life_coplevel >= 3" },
            { "C_Offroad_02_unarmed_F", "call life_coplevel >= 3" },
            { "C_Hatchback_01_sport_F", "call life_coplevel >= 4" },
            { "C_Van_02_transport_F", "call life_coplevel >= 4" }
        };
    };

    class tpc_aso_dealership {
        side = "cop";
        conditions = "playerSide isEqualTo west && (license_cop_aso1 || license_cop_aso2 || license_cop_aso3)";
        vehicles[] = {
            { "C_Heli_Light_01_civil_F", "license_cop_aso1 || license_cop_aso2 || license_cop_aso3" },
            { "B_Heli_Light_01_F", "license_cop_aso1 || license_cop_aso2 || license_cop_aso3" },
            { "I_Heli_light_03_unarmed_F", "license_cop_aso2 || license_cop_aso3" },
            { "O_Heli_Light_02_unarmed_F", "license_cop_aso2 || license_cop_aso3" },
            { "B_Heli_Transport_03_unarmed_F", "license_cop_aso3" }
        };
    };

    class tpc_msv_dealership {
        side = "cop";
        conditions = "playerSide isEqualTo west && (license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3)";
        vehicles[] = {
            { "C_Boat_Civil_01_police_F", "license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3" },
            { "B_G_Boat_Transport_02_F", "license_cop_sfo2 || license_cop_sfo3" },
            { "B_SDV_01_F", "license_cop_sfo3" }
        };
    };

    class tas_general_dealership {
        side = "med";
        conditions = "playerSide isEqualTo independent";
        vehicles[] = {
            { "C_Quadbike_01_F", "call life_mediclevel >= 1" },
            { "C_Hatchback_01_F", "call life_mediclevel >= 2" },
            { "C_Van_02_medevac_F", "call life_mediclevel >= 2" },
            { "C_SUV_01_F", "call life_mediclevel >= 3" },
            { "C_Offroad_01_F", "call life_coplevel >= 3" },
            { "C_Offroad_02_unarmed_F", "call life_coplevel >= 4" },
            { "C_Hatchback_01_sport_F", "call life_mediclevel >= 4" }
        };
    };

    class nhs_taa_dealership {
        side = "med";
        conditions = "playerSide isEqualTo independent && (license_med_taa1 || license_med_taa2 || license_med_taa3)";
        vehicles[] = {
            { "C_Heli_Light_01_civil_F", "license_med_taa1 || license_med_taa2 || license_med_taa3" },
            { "B_Heli_Light_01_F", "license_med_taa1 || license_med_taa2 || license_med_taa3" },
            { "I_Heli_light_03_unarmed_F", "license_med_taa2 || license_med_taa3" },
            { "O_Heli_Light_02_unarmed_F", "license_med_taa2 || license_med_taa3" },
            { "I_Heli_Transport_02_F", "license_med_taa3" },
            { "O_Heli_Transport_04_medevac_F", "license_med_taa3" }
        };
    };
};

class LifeCfgVehicles {
    class Default {
        vItemSpace = -1;
        conditions = "";
        price = -1;
        textures[] = {};
    };

    class C_Kart_01_F { // Kart
        vItemSpace = 0;
        conditions = "";
        price = 1000;
        textures[] = {};
    };

    class C_Quadbike_01_F { // Quad Bike
        vItemSpace = 25;
        conditions = "";
        price = 1500;
        textures[] = {
            { "Black", "civ", {
                "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_black_co.paa"
            }, "" },
            { "Blue", "civ", {
                "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_blue_co.paa"
            }, "" },
            { "Red", "civ", {
                "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_red_co.paa"
            }, "" },
            { "White", "civ", {
                "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_white_co.paa"
            }, "" },
            { "Digi Green", "civ", {
                "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_indp_co.paa"
            }, "" },
            { "Hunter Camo", "civ", {
                "\a3\soft_f_gamma\Quadbike_01\data\quadbike_01_indp_hunter_co.paa"
            }, "" }
        };
    };

    class O_Quadbike_01_F { // [Syndikat/Black Market] Quad Bike
        vItemSpace = 25;
        conditions = "";
        price = 1500;
        textures[] = {};
    };

    class B_G_Quadbike_01_F { // [Chop Shop] Quad Bike
        vItemSpace = 25;
        conditions = "";
        price = 1500;
        textures[] = {};
    };

    class C_Hatchback_01_F { // Hatchback
        vItemSpace = 35;
        conditions = "";
        price = 12500;
        textures[] = {
            { "Beige", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa"
            }, "" },
            { "Green", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa"
            }, "" },
            { "Blue", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa"
            }, "" },
            { "Dark Blue", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa"
            }, "" },
            { "Yellow", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa"
            }, "" },
            { "White", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa"
            }, "" },
            { "Grey", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa"
            }, "" },
            { "Black", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa"
            }, "" },
            { "ARV", "cop", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa"
            }, "license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3" }
        };
    };

    class C_Offroad_01_F { // Offroad
        vItemSpace = 65;
        conditions = "";
        price = 16700;
        textures[] = {
            { "Red", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa"
            }, "" },
            { "Yellow", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE01_CO.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE01_CO.paa"
            }, "" },
            { "White", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa"
            }, "" },
            { "Blue", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa"
            }, "" },
            { "Dark Red", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa"
            }, "" },
            { "Blue / White", "civ", {
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa",
                "\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa"
            }, "" },
            { "Police", "cop", {
                "data\textures\Police\Cars\Police_offroad.paa"
            }, "" },
            { "ARV", "cop", {
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)"
            }, "license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3" }
        };
    };

    class O_G_Offroad_01_F { // [Syndikat] Offroad
        vItemSpace = 65;
        conditions = "";
        price = 16700;
        textures[] = {};
    };

    class C_Offroad_02_unarmed_F { // MB 4WD
        vItemSpace = 60;
        conditions = "";
        price = 18450;
        textures[] = {
            { "Black", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa"
            }, "" },
            { "Blue", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa"
            }, "" },
            { "Green", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_green_co.paa"
            }, "" },
            { "Orange", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_orange_co.paa"
            }, "" },
            { "Red", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_red_co.paa"
            }, "" },
            { "White", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_white_co.paa"
            }, "" }
        };
    };

    class I_C_Offroad_02_unarmed_F { // [Syndikat] MB 4WD
        vItemSpace = 60;
        conditions = "";
        price = 18450;
        textures[] = {
            { "Green", "civ", {
                "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_green_co.paa"
            }, "" }
        };
    };

    class I_C_Offroad_02_LMG_F { // [Syndika] MB 4WD (LMG)
        vItemSpace = 0;
        conditions = "";
        price = 350000;
        textures[] = {};
    };

    class C_SUV_01_F { // SUV
        vItemSpace = 45;
        conditions = "";
        price = 31900;
        textures[] = {
            { "Dark Red", "civ", {
                "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa"
            }, "" },
            { "Silver", "civ", {
                "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa"
            }, "" },
            { "Orange", "civ", {
                "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa"
            }, "" },
            { "Police", "cop", {
                "data\textures\Police\Cars\Police_SUV_White.paa"
            }, "" },
            { "ARV", "cop", {
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)"
            }, "license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3" }
        };
    };

    class C_Hatchback_01_sport_F { // Hatchback (Sport)
        vItemSpace = 35;
        conditions = "";
        price = 57800;
        textures[] = {
            { "Red", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa"
            }, "" },
            { "Dark Blue", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa"
            }, "" },
            { "Orange", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa"
            }, "" },
            { "Black / White", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa"
            }, "" },
            { "Beige", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa"
            }, "" },
            { "Green", "civ", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport06_co.paa"
            }, "" },
            { "ARV", "cop", {
                "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa"
            }, "license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3" }
        };
    };

    class C_Van_02_transport_F { // Van Transport
        vItemSpace = 90;
        conditions = "";
        price = 45000;
        textures[] = {
            { "ARV", "cop", {
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)",
                "#(argb,8,8,3)color(0.05,0.05,0.05,1)"
            }, "license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3" }
        };
    };

    class O_G_Van_02_transport_F { // [Syndikat] Van Transport
        vItemSpace = 90;
        conditions = "";
        price = 45000;
        textures[] = {};
    };

    class C_Van_02_vehicle_F { // Van (Cargo)
        vItemSpace = 100;
        conditions = "";
        price = 51200;
        textures[] = {};
    };

    class O_G_Van_02_vehicle_F { // [Syndikat] Van (Cargo)
        vItemSpace = 100;
        conditions = "";
        price = 51200;
        textures[] = {};
    };

    class C_Van_02_medevac_F { // Van (Ambulance)
        vItemSpace = 70;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Van_01_transport_F { // Truck
        vItemSpace = 0;
        conditions = "";
        price = 76000;
        textures[] = {};
    };

    class O_G_Van_01_transport_F { // [Syndikat] Truck
        vItemSpace = 125;
        conditions = "";
        price = 76000;
        textures[] = {};
    };

    class C_Van_01_box_F { // Truck Boxer
        vItemSpace = 150;
        conditions = "";
        price = 97000;
        textures[] = {};
    };

    class C_Truck_02_transport_F { // Zamak Transport
        vItemSpace = 190;
        conditions = "";
        price = 130000;
        textures[] = {};
    };

    class C_Truck_02_covered_F { // Zamak Transport (Covered)
        vItemSpace = 230;
        conditions = "";
        price = 164000;
        textures[] = {};
    };

    class B_Truck_01_mover_F { // HEMTT
        vItemSpace = 0;
        conditions = "";
        price = 105000;
        textures[] = {};
    };

    class B_Truck_01_transport_F { // HEMTT Transport
        vItemSpace = 250;
        conditions = "";
        price = 210000;
        textures[] = {};
    };

    class B_Truck_01_covered_F { // HEMTT Transport (Covered)
        vItemSpace = 285;
        conditions = "";
        price = 245000;
        textures[] = {};
    };

    class B_Truck_01_ammo_F { // HEMTT Ammo
        vItemSpace = 300;
        conditions = "";
        price = 267800;
        textures[] = {};
    };

    class B_Truck_01_box_F { // HEMTT Box
        vItemSpace = 750;
        conditions = "";
        price = 430000;
        textures[] = {};
    };

    class O_T_Truck_03_transport_ghex_F { // Tempest Transport
        vItemSpace = 370;
        conditions = "";
        price = 298000;
        textures[] = {};
    };

    class O_T_Truck_03_covered_ghex_F { // Tempest Transport (Covered)
        vItemSpace = 395;
        conditions = "";
        price = 313600;
        textures[] = {};
    };

    class O_T_Truck_03_ammo_ghex_F { // Tempest Ammo
        vItemSpace = 480;
        conditions = "";
        price = 367900;
        textures[] = {};
    };

    class O_T_Truck_03_device_ghex_F { // Tempest (Device)
        vItemSpace = 500;
        conditions = "";
        price = 500000;
        textures[] = {};
    };

    class C_Heli_Light_01_civil_F { // M-900
        vItemSpace = 60;
        conditions = "";
        price = 234000;
        textures[] = {};
    };

    class B_Heli_Light_01_F { // MH-9 Hummingbird
        vItemSpace = 75;
        conditions = "";
        price = 345000;
        textures[] = {
            { "Sheriff", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa"
            }, "" },
            { "Civ Blue", "civ", {
                "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa"
            }, "" },
            { "Civ Red", "civ", {
                "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa"
            }, "" },
            { "Blueline", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueline_co.paa"
            }, "" },
            { "Elliptical", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa"
            }, "" },
            { "Furious", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa"
            }, "" },
            { "Jeans Blue", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa"
            }, "" },
            { "Speedy Redline", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa"
            }, "" },
            { "Sunset", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa"
            }, "" },
            { "Vrana", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa"
            }, "" },
            { "Waves Blue", "civ", {
                "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa"
            }, "" }
        };
    };

    class O_Heli_Light_02_unarmed_F { // PO-30 Orca (Unarmed)
        vItemSpace = 190;
        conditions = "";
        price = 879000;
        textures[] = {
            { "White / Blue", "civ", {
                "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_civilian_co.paa"
            }, "" }
        };
    };

    class I_Heli_light_03_unarmed_F { // WY-55 Hellcat (Unarmed)
        vItemSpace = 160;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class I_Heli_Transport_02_F { // CH-49 Mohawk
        vItemSpace = 245;
        conditions = "";
        price = 2675000;
        textures[] = {};
    };

    class B_Heli_Transport_03_unarmed_F { // CH-67 Huron (Unarmed) 
        vItemSpace = 460;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class O_Heli_Transport_04_medevac_F { // Mi-290 Taru (Medical)
        vItemSpace = 450;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Plane_Civil_01_F { // Caesar BTT
        vItemSpace = 40;
        conditions = "";
        price = 300000;
        textures[] = {
            { "Racing (Tan Interior)", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Racer_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Racer_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"
            }, "" },
            { "Racing", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Racer_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Racer_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"
            }, "" },
            { "Red Line (Tan Interior)", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"
            }, "" },
            { "Red Line", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"
            }, "" },
            { "Tribal (Tan Interior)", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"
            }, "" },
            { "Tribal", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"
            }, "" },
            { "Blue Wave (Tan Interior)", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Wave_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Wave_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"
            }, "" },
            { "Blue Wave", "civ", {
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Wave_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Wave_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa",
                "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"
            }, "" }
        };    
    };

    class I_Plane_Fighter_03_CAS_F { // A-143 Buzzard (CAS)
        vItemSpace = 0;
        conditions = "";
        price = 6780000;
        textures[] = {};
    };

    class B_Plane_CAS_01_F { // A-164 Wipeout 
        vItemSpace = 0;
        conditions = "";
        price = 7895000;
        textures[] = {};
    };

    class O_Plane_CAS_02_F { // To-199 Neophron 
        vItemSpace = 0;
        conditions = "";
        price = 8145000;
        textures[] = {};
    };

    class I_Plane_Fighter_04_F { // A-149 Gryphon
        vItemSpace = 0;
        conditions = "";
        price = 8670000;
        textures[] = {};
    };

    class B_Plane_Fighter_01_F { // F/A-181 Black Wasp II
        vItemSpace = 0;
        conditions = "";
        price = 9950000;
        textures[] = {};
    };

    class O_Plane_Fighter_02_F { // To-201 Shikra
        vItemSpace = 0;
        conditions = "";
        price = 13200000;
        textures[] = {};
    };

    class C_Scooter_Transport_01_F { // Water Scooter
        vItemSpace = 20;
        conditions = "";
        price = 1300;
        textures[] = {
            { "Black", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Black_CO.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Black_CO.paa"
            }, "" },
            { "Blue", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Blue_co.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Blue_co.paa"
            }, "" },
            { "Grey", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Grey_co.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Grey_co.paa"
            }, "" },
            { "Green", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Lime_co.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Lime_co.paa"
            }, "" },
            { "Red", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Red_CO.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_CO.paa"
            }, "" },
            { "White", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_CO.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_CO.paa"
            }, "" },
            { "Yellow", "civ", {
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Yellow_CO.paa",
                "\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Yellow_CO.paa"
            }, "" }
        };
    };

    class C_Rubberboat { // Rescue Boat
        vItemSpace = 35;
        conditions = "";
        price = 8700;
        textures[] = {};
    };

    class C_Boat_Civil_01_F { // Motorboat
        vItemSpace = 50;
        conditions = "";
        price = 14500;
        textures[] = {};
    };

    class C_Boat_Transport_02_F { // RHIB
        vItemSpace = 65;
        conditions = "";
        price = 15600;
        textures[] = {};
    };

    class B_SDV_01_F { // SDV
        vItemSpace = 15;
        conditions = "";
        price = 0;
        textures[] = {};
    };
};
