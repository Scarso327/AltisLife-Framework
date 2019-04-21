class CfgWeapons {
    class general_store {
        name = "General Store";
        conditions = "";
        items[] = {
            { "ItemMap", "Map of Tanoa", 120, 120, "" },
            { "ItemGPS", "Handheld GPS", 250, 125, "" },
            { "ItemRadio", "Mobile Phone", 190, 190, "" },
            { "ItemCompass", "Compass", 45, 23, "" },
            { "ItemWatch", "Wrist Watch", 60, 30, "" },
            { "Binocular", "Binoculars", 270, 135, "" },
            { "NVGoggles", "Night Vision Goggles", 5000, 0, "" },
            { "FirstAidKit", "First Aid Kit", 500, 250, "" },
            { "ToolKit", "Toolkit", 1500, 750, "" }
        };
        mags[] = {};
        accs[] = {};
    };

    class fuel_station_Store {
        name = "Fuel Station Store";
        conditions = "";
        items[] = {
            { "ItemMap", "Map of Tanoa", 120, 120, "" },
            { "ItemGPS", "Handheld GPS", 250, 125, "" },
            { "ItemRadio", "Mobile Phone", 190, 190, "" },
            { "ItemCompass", "Compass", 45, 23, "" },
            { "ItemWatch", "Wrist Watch", 60, 30, "" },
            { "FirstAidKit", "First Aid Kit", 500, 250, "" },
            { "ToolKit", "Toolkit", 1500, 750, "" }
        };
        mags[] = {};
        accs[] = {};
    };

    class go_karting_store {
        name = "Go-Karting Store";
        conditions = "playerSide isEqualTo civilian && license_civ_go_karting";
        items[] = {
            { "ToolKit", "Toolkit", 1500, 750, "" }, // Premium Membership
            { "hgun_Pistol_Signal_F", "Starter Pistol", 6000, 3000, "" } // Premium Membership
        };
        mags[] = {
            { "6Rnd_GreenSignal_F", "6Rnd Green Single Mag", 70, 35, "" }, // Premium Membership
            { "6Rnd_RedSignal_F", "6Rnd Red Single Mag", 70, 35, "" } // Premium Membership
        };
        accs[] = {};
    };

    class handgun_store {
        name = "Handgun Store";
        conditions = "playerSide isEqualTo civilian && license_civ_firearms";
        items[] = {
            { "hgun_Pistol_01_F", "PM 9 mm", 11000, 5500, "" },
            { "hgun_Rook40_F", "Rook-40 9 mm", 14500, 7250, "" },
            { "hgun_ACPC2_F", "ACP-C2 .45 ACP", 19800, 9900, "" }
        };
        mags[] = {
            { "10Rnd_9x21_Mag", "10Rnd 9mm Mag", 180, 90, "" },
            { "16Rnd_9x21_Mag", "16Rnd 9mm Mag", 235, 118, "" },
            { "9Rnd_45ACP_Mag", "9Rnd .45mm Mag", 320, 160, "" }
        };
        accs[] = {};
    };

    class gang_hideout {
        name = "Gang Hideout";
        conditions = "playerSide isEqualTo civilian";
        items[] = {
            { "ItemMap", "Map of Tanoa", 120, 120, "" },
            { "ItemGPS", "Handheld GPS", 250, 125, "" },
            { "ItemRadio", "Mobile Phone", 190, 190, "" },
            { "ItemCompass", "Compass", 45, 23, "" },
            { "ItemWatch", "Wrist Watch", 60, 30, "" },
            { "Binocular", "Binoculars", 270, 135, "" },
            { "NVGoggles", "Night Vision Goggles", 5000, 0, "" },
            { "FirstAidKit", "First Aid Kit", 500, 250, "" },
            { "ToolKit", "Toolkit", 1500, 750, "" },
            { "hgun_Pistol_01_F", "PM 9 mm", 11000, 5500, "" },
            { "hgun_Rook40_F", "Rook-40 9 mm", 14500, 7250, "" },
            { "hgun_ACPC2_F", "ACP-C2 .45 ACP", 19800, 9900, "" },
            { "hgun_Pistol_heavy_02_F", "Zubr .45", 27000, 13500, "" },
            { "hgun_PDW2000_F", "PDW2000 9mm", 42750, 21375, "" },
            { "SMG_02_F", "Sting 9mm", 51000, 25500, "" },
            { "arifle_AKS_F", "AKS-74U 5.45 mm", 13000, 65000, "" },
            { "arifle_AKM_F", "AKM 7.62 mm", 290000, 145000, "" }
        };
        mags[] = {
            { "10Rnd_9x21_Mag", "10Rnd 9mm Mag", 180, 90, "" },
            { "16Rnd_9x21_Mag", "16Rnd 9mm Mag", 235, 118, "" },
            { "30Rnd_9x21_Mag", "30Rnd 9mm Mag", 400, 200, "" },
            { "9Rnd_45ACP_Mag", "9Rnd .45mm Mag", 320, 160, "" },
            { "6Rnd_45ACP_Cylinder", "6Rnd .45mm Cylinder", 410, 205, "" },
            { "30Rnd_545x39_Mag_F", "30Rnd 5.45mm Mag", 670, 335, "" },
            { "30Rnd_762x39_Mag_F", "30Rnd 7.62mm Mag", 1670, 835, "" }
        };
        accs[] = {
            { "optic_ACO_grn", "ACO (Green)", 300, 150, "" },
            { "optic_Aco", "ACO (Red)", 350, 175, "" },
            { "optic_ACO_grn_smg", "ACO SMG (Green)", 300, 150, "" },
            { "optic_Aco_smg", "ACO SMG (Red)", 350, 175, "" }
        };
    };

    class syndikat_outpost {
        name = "Syndikat Outpost";
        conditions = "playerSide isEqualTo civilian && license_civ_syndikat";
        items[] = {
            { "ItemMap", "Map of Tanoa", 120, 120, "" },
            { "ItemGPS", "Handheld GPS", 250, 125, "" },
            { "ItemRadio", "Mobile Phone", 190, 190, "" },
            { "ItemCompass", "Compass", 45, 23, "" },
            { "ItemWatch", "Wrist Watch", 60, 30, "" },
            { "Binocular", "Binoculars", 270, 135, "" },
            { "NVGoggles", "Night Vision Goggles", 5000, 0, "" },
            { "FirstAidKit", "First Aid Kit", 500, 250, "" },
            { "ToolKit", "Toolkit", 1500, 750, "" },
            { "hgun_Pistol_01_F", "PM 9 mm", 11000, 5500, "" },
            { "hgun_Rook40_F", "Rook-40 9 mm", 14500, 7250, "" },
            { "hgun_ACPC2_F", "ACP-C2 .45 ACP", 19800, 9900, "" },
            { "hgun_Pistol_heavy_02_F", "Zubr .45", 27000, 13500, "" },
            { "hgun_PDW2000_F", "PDW2000 9mm", 42750, 21375, "" },
            { "SMG_02_F", "Sting 9mm", 51000, 25500, "" },
            { "arifle_AKS_F", "AKS-74U 5.45 mm", 65000, 32500, "" },
            { "arifle_SDAR_F", "SDAR 5.56 mm", 50000, 25000, "" },
            { "arifle_TRG20_F", "TRG-21 5.56 mm", 68900, 34450, "" },
            { "arifle_Mk20C_F", "Mk20 5.56 mm", 73400, 36700, "" },
            { "arifle_Katiba_C_F", "Katiba 6.5 mm", 86850, 43425, "" },
            { "arifle_AKM_F", "AKM 7.62 mm", 145000, 72500, "" },
            { "srifle_DMR_06_olive_F", "Mk14 7.62 mm (Olive)", 198000, 99000, "" }
        };
        mags[] = {
            { "10Rnd_9x21_Mag", "10Rnd 9mm Mag", 180, 90, "" },
            { "16Rnd_9x21_Mag", "16Rnd 9mm Mag", 235, 118, "" },
            { "30Rnd_9x21_Mag", "30Rnd 9mm Mag", 400, 200, "" },
            { "9Rnd_45ACP_Mag", "9Rnd .45mm Mag", 320, 160, "" },
            { "6Rnd_45ACP_Cylinder", "6Rnd .45mm Cylinder", 410, 205, "" },
            { "30Rnd_545x39_Mag_F", "30Rnd 5.45mm Mag", 670, 335, "" },
            { "20Rnd_556x45_UW_mag", "20Rnd 5.56mm UW Mag", 450, 225, "" },
            { "30Rnd_556x45_Stanag", "30Rnd 5.56mm Mag", 750, 375, "" },
            { "30Rnd_65x39_caseless_green", "30Rnd 6.5mm Mag", 890, 445, "" },
            { "20Rnd_762x51_Mag", "20Rnd 7.62mm Mag", 1050, 525, "" },
            { "30Rnd_762x39_Mag_F", "30Rnd 7.62mm Mag", 1670, 835, "" }
        };
        accs[] = {
            { "optic_ACO_grn", "ACO (Green)", 300, 150, "" },
            { "optic_Aco", "ACO (Red)", 350, 175, "" },
            { "optic_ACO_grn_smg", "ACO SMG (Green)", 300, 150, "" },
            { "optic_Aco_smg", "ACO SMG (Red)", 350, 175, "" },
            { "optic_Holosight", "Mk17 Holosight", 585, 293, "" },
            { "optic_Holosight_smg", "Mk17 Holosight SMG", 535, 268, "" },
            { "optic_Hamr", "RCO", 1340, 670, "" },
            { "optic_MRCO", "MRCO", 1650, 825, "" },
            { "optic_Arco_blk_F", "ARCO", 1900, 950, "" },
            { "acc_flashlight_pistol", "Pistol Flashlight", 50, 25, "" },
            { "acc_flashlight", "Flashlight", 80, 40, "" }
        };
    };

    class tpc_general_Store {
        name = "TPC - General Store";
        conditions = "playerSide isEqualTo west";
        items[] = {
            { "ItemMap", "Map of Tanoa", 0, -1, "call life_coplevel >= 1" },
            { "ItemGPS", "Handheld GPS", 0, -1, "call life_coplevel >= 1" },
            { "ItemRadio", "Mobile Phone", 0, -1, "call life_coplevel >= 1" },
            { "ItemCompass", "Compass", 0, -1, "call life_coplevel >= 1" },
            { "ItemWatch", "Wrist Watch", 0, -1, "call life_coplevel >= 1" },
            { "Binocular", "Binoculars", 0, -1, "call life_coplevel >= 1" },
            { "Rangefinder", "Rangefinder", 0, -1, "call life_coplevel >= 2" },
            { "NVGoggles_OPFOR", "Night Vision Goggles", 0, -1, "call life_coplevel >= 1" },
            { "FirstAidKit", "First Aid Kit", 0, 0, "call life_coplevel >= 1" },
            { "ToolKit", "Toolkit", 0, -1, "call life_coplevel >= 1" },
            { "HandGrenade_Stone", "Flashbang Grenade", 0, -1, "license_cop_sfo2 || license_cop_sfo3" },
            { "hgun_Pistol_heavy_01_F", "Taser Pistol", 0, 0, "call life_coplevel >= 1" },
            { "hgun_ACPC2_F", "ACP-C2 .45 ACP", 0, -1, "call life_coplevel >= 2" },
            { "SMG_05_F", "Protector 9 mm", 0, -1, "call life_coplevel >= 2" },
            { "arifle_SPAR_01_blk_F", "SPAR-16 5.56 mm", 0, -1, "call life_coplevel >= 4" },
            { "SMG_03C_TR_black", "ADR-97C TR 5.7 mm", 0, -1, "license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3" },
            { "arifle_CTAR_blk_F", "CAR-95 5.8mm", 0, -1, "license_cop_sfo2 || license_cop_sfo3" },
            { "arifle_CTAR_GL_blk_F", "CAR-95 GL 5.8 mm", 0, -1, "license_cop_sfo2 || license_cop_sfo3" },
            { "arifle_ARX_blk_F", "Type 115 6.5 mm", 0, -1, "license_cop_sfo3" },
            { "arifle_SPAR_03_blk_F", "SPAR-17 7.62 mm", 0, -1, "license_cop_sfo3" }
        };
        mags[] = {
            { "11Rnd_45ACP_Mag", "Taser Cartridge", 0, -1, "call life_coplevel >= 1" },
            { "9Rnd_45ACP_Mag", "9Rnd .45mm Mag", 0, -1, "call life_coplevel >= 2" },
            { "30Rnd_9x21_Mag_SMG_02", "30Rnd 9mm Mag", 0, -1, "call life_coplevel >= 2" },
            { "30Rnd_556x45_Stanag", "30Rnd 5.56mm Mag", 0, -1, "call life_coplevel >= 3" },
            { "50Rnd_570x28_SMG_03", "50Rnd 5.7mm Mag", 0, -1, "license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3" },
            { "30Rnd_580x42_Mag_F", "30Rnd 5.8mm Mag", 0, -1, "license_cop_sfo2 || license_cop_sfo3" },
            { "30Rnd_65x39_caseless_green", "30Rnd 6.5mm Mag", 0, -1, "license_cop_sfo3" },
            { "20Rnd_762x51_Mag", "20Rnd 7.62mm Mag", 0, -1, "license_cop_sfo3" },
            { "UGL_FlareCIR_F", "Flashbang Round", 0, -1, "license_cop_sfo2 || license_cop_sfo3" }
        };
        accs[] = {
            { "optic_MRD", "MRD", 0, -1, "call life_coplevel >= 1 || (license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3)" },
            { "optic_Aco", "ACO (Red)", 0, -1, "call life_coplevel >= 2 || (license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3)" },
            { "optic_Aco_smg", "ACO SMG (Red)", 0, -1, "call life_coplevel >= 2 || (license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3)" },
            { "optic_Holosight_blk_F", "Mk17 Holosight", 0, -1, "call life_coplevel >= 2 || (license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3)" },
            { "optic_Holosight_smg_blk_F", "Mk17 Holosight SMG", 0, -1, "call life_coplevel >= 2 || (license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3)" },
            { "optic_Hamr", "RCO", 0, -1, "call life_coplevel >= 4 || (license_cop_sfo2 || license_cop_sfo3)" },
            { "optic_MRCO", "MRCO", 0, -1, "call life_coplevel >= 4 || (license_cop_sfo2 || license_cop_sfo3)" },
            { "optic_Arco_blk_F", "ARCO", 0, -1, "call life_coplevel >= 4 || (license_cop_sfo2 || license_cop_sfo3)" },
            { "optic_DMS", "DMS", 0, -1, "license_cop_sfo3" },
            { "acc_flashlight_pistol", "Pistol Flashlight", 0, -1, "call life_coplevel >= 1 || (license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3)" },
            { "acc_flashlight", "Flashlight", 0, -1, "call life_coplevel >= 4 || (license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3)" },
            { "acc_pointer_IR", "IR Laser Pointer", 0, -1, "license_cop_sfo3" },
            { "muzzle_snds_acp", "Taser Suppressor", 0, -1, "call life_coplevel >= 1 || (license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3)" }
        };
    };

    class tas_general_store {
        name = "TAS - General Store";
        conditions = "playerSide isEqualTo independent";
        items[] = {
            { "ItemMap", "Map of Tanoa", 0, -1, "call life_mediclevel >= 1" },
            { "ItemGPS", "Handheld GPS", 0, -1, "call life_mediclevel >= 1" },
            { "ItemRadio", "Mobile Phone", 0, -1, "call life_mediclevel >= 1" },
            { "ItemCompass", "Compass", 0, -1, "call life_mediclevel >= 1" },
            { "ItemWatch", "Wrist Watch", 0, -1, "call life_mediclevel >= 1" },
            { "Binocular", "Binoculars", 0, -1, "call life_mediclevel >= 1" },
            { "NVGoggles", "Night Vision Goggles", 0, -1, "call life_mediclevel >= 2" },
            { "FirstAidKit", "First Aid Kit", 0, 0, "call life_mediclevel >= 1" },
            { "ToolKit", "Toolkit", 0, -1, "call life_mediclevel >= 1" },
            { "hgun_Pistol_Signal_F", "Starter Pistol", 0, 0, "call life_mediclevel >= 4" }
        };
        mags[] = {
            { "6Rnd_GreenSignal_F", "6Rnd Green Single Mag", 0, 0, "call life_mediclevel >= 4" },
            { "6Rnd_RedSignal_F", "6Rnd Red Single Mag", 0, 0, "call life_mediclevel >= 4" }
        };
        accs[] = {};
    };
};
