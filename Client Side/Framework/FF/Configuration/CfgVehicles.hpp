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
            { "C_Plane_Civil_01_F", "" }
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

    class tpc_arv_dealership {
        side = "cop";
        conditions = "playerSide isEqualTo west && (license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3)";
        vehicles[] = {
            { "C_SUV_01_F", "license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3" },
            { "C_Offroad_01_F", "license_cop_sfo2 || license_cop_sfo3" },
            { "C_Hatchback_01_sport_F", "license_cop_sfo3" },
            { "C_Van_02_transport_F", "license_cop_sfo3" }
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

    class nhs_general_dealership {
        side = "med";
        conditions = "playerSide isEqualTo independent";
        vehicles[] = {
            { "C_Van_02_medevac_F", "call life_medlevel >= 2" },
            { "C_SUV_01_F", "call life_medlevel >= 3" },
            { "C_Hatchback_01_sport_F", "call life_medlevel >= 4" }
        };
    };

    class nhs_taa_dealership {
        side = "med";
        conditions = "playerSide isEqualTo independent && license_med_taa";
        vehicles[] = {
            { "I_Heli_light_03_unarmed_F", "" },
            { "O_Heli_Light_02_unarmed_F", "" }
        };
    };

    class nhs_mru_dealership {
        side = "med";
        conditions = "playerSide isEqualTo independent && license_med_mru";
        vehicles[] = {
            { "B_G_Boat_Transport_02_F", "" }
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
        price = 0;
        textures[] = {};
    };

    class C_Quadbike_01_F { // Quad Bike
        vItemSpace = 25;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class O_Quadbike_01_F { // [Syndikat/Black Market] Quad Bike
        vItemSpace = 25;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class B_G_Quadbike_01_F { // [Chop Shop] Quad Bike
        vItemSpace = 25;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Hatchback_01_F { // Hatchback
        vItemSpace = 35;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Offroad_01_F { // Offroad
        vItemSpace = 65;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class O_G_Offroad_01_F { // [Syndikat] Offroad
        vItemSpace = 65;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Offroad_02_unarmed_F { // MB 4WD
        vItemSpace = 60;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class I_C_Offroad_02_unarmed_F { // [Syndikat] MB 4WD
        vItemSpace = 60;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class I_C_Offroad_02_LMG_F { // [Syndika] MB 4WD (LMG)
        vItemSpace = 0;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_SUV_01_F { // SUV
        vItemSpace = 45;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Hatchback_01_sport_F { // Hatchback (Sport)
        vItemSpace = 35;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Van_02_transport_F { // Van Transport
        vItemSpace = 90;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class O_G_Van_02_transport_F { // [Syndikat] Van Transport
        vItemSpace = 90;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Van_02_vehicle_F { // Van (Cargo)
        vItemSpace = 100;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class O_G_Van_02_vehicle_F { // [Syndikat] Van (Cargo)
        vItemSpace = 100;
        conditions = "";
        price = 0;
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
        price = 0;
        textures[] = {};
    };

    class O_G_Van_01_transport_F { // [Syndikat] Truck
        vItemSpace = 125;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Van_01_box_F { // Truck Boxer
        vItemSpace = 150;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Truck_02_transport_F { // Zamak Transport
        vItemSpace = 190;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Truck_02_covered_F { // Zamak Transport (Covered)
        vItemSpace = 230;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class B_Truck_01_mover_F { // HEMTT
        vItemSpace = 0;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class B_Truck_01_transport_F { // HEMTT Transport
        vItemSpace = 250;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class B_Truck_01_covered_F { // HEMTT Transport (Covered)
        vItemSpace = 285;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class B_Truck_01_ammo_F { // HEMTT Ammo
        vItemSpace = 300;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class B_Truck_01_box_F { // HEMTT Box
        vItemSpace = 750;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class O_T_Truck_03_transport_ghex_F { // Tempest Transport
        vItemSpace = 370;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class O_T_Truck_03_covered_ghex_F { // Tempest Transport (Covered)
        vItemSpace = 395;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class O_T_Truck_03_ammo_ghex_F { // Tempest Ammo
        vItemSpace = 480;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class O_T_Truck_03_device_ghex_F { // Tempest (Device)
        vItemSpace = 500;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Heli_Light_01_civil_F { // M-900
        vItemSpace = 60;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class B_Heli_Light_01_F { // MH-9 Hummingbird
        vItemSpace = 75;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class O_Heli_Light_02_unarmed_F { // PO-30 Orca (Unarmed)
        vItemSpace = 190;
        conditions = "";
        price = 0;
        textures[] = {};
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
        price = 0;
        textures[] = {};
    };

    class B_Heli_Transport_03_unarmed_F { // CH-67 Huron (Unarmed)
        vItemSpace = 460;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Plane_Civil_01_F { // Caesar BTT
        vItemSpace = 40;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Scooter_Transport_01_F { // Water Scooter
        vItemSpace = 20;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Rubberboat { // Rescue Boat
        vItemSpace = 35;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Boat_Civil_01_F { // Motorboat
        vItemSpace = 50;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class C_Boat_Transport_02_F { // RHIB
        vItemSpace = 65;
        conditions = "";
        price = 0;
        textures[] = {};
    };

    class B_SDV_01_F { // SDV
        vItemSpace = 15;
        conditions = "";
        price = 0;
        textures[] = {};
    };
};
