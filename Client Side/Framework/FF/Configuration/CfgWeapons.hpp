class CfgWeapons {
    class general_store {
        name = "General Store";
        conditions = "";
        items[] = {
            { "ItemMap", "Map of Altis", 0, 0, "" },
            { "ItemGPS", "Handheld GPS", 0, 0, "" },
            { "ItemRadio", "Mobile Phone", 0, 0, "" },
            { "ItemCompass", "Compass", 0, 0, "" },
            { "ItemWatch", "Wrist Watch", 0, 0, "" },
            { "Binocular", "Binoculars", 0, 0, "" },
            { "NVGoggles", "Night Vision Goggles", 0, 0, "" },
            { "G_Tactical_Black", "Night Vision Glasses", 0, 0, "" }, // Premium Membership
            { "FirstAidKit", "First Aid Kit", 0, 0, "" },
            { "ToolKit", "Toolkit", 0, 0, "" }
        };
        mags[] = {};
        accs[] = {};
    };

    class fuel_station_Store {
        name = "Fuel Station Store";
        conditions = "";
        items[] = {
            { "ItemMap", "Map of Altis", 0, 0, "" },
            { "ItemGPS", "Handheld GPS", 0, 0, "" },
            { "ItemRadio", "Mobile Phone", 0, 0, "" },
            { "ItemCompass", "Compass", 0, 0, "" },
            { "ItemWatch", "Wrist Watch", 0, 0, "" },
            { "FirstAidKit", "First Aid Kit", 0, 0, "" },
            { "ToolKit", "Toolkit", 0, 0, "" }
        };
        mags[] = {};
        accs[] = {};
    };

    class go_karting_store {
        name = "Go-Karting Store";
        conditions = "playerSide isEqualTo civilian && license_civ_go_karting";
        items[] = {
            { "ToolKit", "Toolkit", 0, 0, "" }, // Premium Membership
            { "hgun_Pistol_Signal_F", "Starter Pistol", 0, 0, "" } // Premium Membership
        };
        mags[] = {
            { "6Rnd_GreenSignal_F", "6Rnd Green Single Mag", 0, 0, "" }, // Premium Membership
            { "6Rnd_RedSignal_F", "6Rnd Red Single Mag", 0, 0, "" } // Premium Membership
        };
        accs[] = {};
    };

    class handgun_store {
        name = "Handgun Store";
        conditions = "playerSide isEqualTo civilian && license_civ_firearms";
        items[] = {
            { "hgun_Pistol_01_F", "PM 9 mm", 0, 0, "" },
            { "hgun_Rook40_F", "Rook-40 9 mm", 0, 0, "" },
            { "hgun_ACPC2_F", "ACP-C2 .45 ACP", 0, 0, "" }
        };
        mags[] = {
            { "10Rnd_9x21_Mag", "10Rnd 9mm Mag", 0, 0, "" },
            { "16Rnd_9x21_Mag", "16Rnd 9mm Mag", 0, 0, "" },
            { "30Rnd_9x21_Mag", "30Rnd 9mm Mag", 0, 0, "" },
            { "9Rnd_45ACP_Mag", "9Rnd .45mm Mag", 0, 0, "" }
        };
        accs[] = {};
    };

    class syndikat_outpost {
        name = "Syndikat Outpost";
        conditions = "playerSide isEqualTo civilian && license_civ_syndikat";
        items[] = {
            { "ItemMap", "Map of Altis", 0, 0, "" },
            { "ItemGPS", "Handheld GPS", 0, 0, "" },
            { "ItemRadio", "Mobile Phone", 0, 0, "" },
            { "ItemCompass", "Compass", 0, 0, "" },
            { "ItemWatch", "Wrist Watch", 0, 0, "" },
            { "Binocular", "Binoculars", 0, 0, "" },
            { "NVGoggles", "Night Vision Goggles", 0, 0, "" },
            { "G_Tactical_Black", "Night Vision Glasses", 0, 0, "" }, // Premium Membership
            { "FirstAidKit", "First Aid Kit", 0, 0, "" },
            { "ToolKit", "Toolkit", 0, 0, "" },
            { "hgun_Pistol_01_F", "PM 9 mm", 0, 0, "" },
            { "hgun_Rook40_F", "Rook-40 9 mm", 0, 0, "" },
            { "hgun_ACPC2_F", "ACP-C2 .45 ACP", 0, 0, "" },
            { "hgun_Pistol_heavy_02_F", "Zubr .45", 0, 0, "" },
            { "hgun_PDW2000_F", "PDW2000 9mm", 0, 0, "" },
            { "SMG_02_F", "Sting 9mm", 0, 0, "" },
            { "arifle_AKS_F", "AKS-74U 5.45 mm", 0, 0, "" },
            { "arifle_SDAR_F", "SDAR 5.56 mm", 0, 0, "" },
            { "arifle_TRG20_F", "TRG-20 5.56 mm", 0, 0, "" },
            { "arifle_Mk20C_F", "Mk20C 5.56 mm (Camo)", 0, 0, "" },
            { "arifle_Katiba_C_F", "Katiba 6.5 mm", 0, 0, "" },
            { "arifle_AKM_F", "AKM 7.62 mm", 0, 0, "" },
            { "srifle_DMR_06_olive_F", "Mk14 7.62 mm (Olive)", 0, 0, "" }
        };
        mags[] = {
            { "10Rnd_9x21_Mag", "10Rnd 9mm Mag", 0, 0, "" },
            { "16Rnd_9x21_Mag", "16Rnd 9mm Mag", 0, 0, "" },
            { "30Rnd_9x21_Mag", "30Rnd 9mm Mag", 0, 0, "" },
            { "9Rnd_45ACP_Mag", "9Rnd .45mm Mag", 0, 0, "" },
            { "6Rnd_45ACP_Cylinder", "6Rnd .45mm Cylinder", 0, 0, "" },
            { "30Rnd_545x39_Mag_F", "30Rnd 5.45mm Mag", 0, 0, "" },
            { "20Rnd_556x45_UW_mag", "20Rnd 5.56mm UW Mag", 0, 0, "" },
            { "30Rnd_556x45_Stanag", "30Rnd 5.56mm Mag", 0, 0, "" },
            { "200Rnd_556x45_Box_F", "200Rnd 5.56mm Box", 0, 0, "" },
            { "30Rnd_65x39_caseless_green", "30Rnd 6.5mm Mag", 0, 0, "" },
            { "50Rnd_570x28_SMG_03", "50Rnd 5.7mm Mag", 0, 0, "" },
            { "30Rnd_762x39_Mag_F", "30Rnd 7.62mm Mag", 0, 0, "" },
            { "10Rnd_762x54_Mag", "10Rnd 7.62mm Mag", 0, 0, "" },
            { "20Rnd_762x51_Mag", "20Rnd 7.62mm Mag", 0, 0, "" }
        };
        accs[] = {
            { "optic_ACO_grn", "ACO (Green)", 0, 0, "" },
            { "optic_Aco", "ACO (Red)", 0, 0, "" },
            { "optic_ACO_grn_smg", "ACO SMG (Green)", 0, 0, "" },
            { "optic_Aco_smg", "ACO SMG (Red)", 0, 0, "" },
            { "optic_Holosight", "Mk17 Holosight", 0, 0, "" },
            { "optic_Holosight_smg", "Mk17 Holosight SMG", 0, 0, "" },
            { "optic_Hamr", "RCO", 0, 0, "" },
            { "optic_MRCO", "MRCO", 0, 0, "" },
            { "optic_Arco_blk_F", "ARCO", 0, 0, "" },
            { "optic_KHS_old", "Kahlia (Old)", 0, 0, "" },
            { "acc_flashlight_pistol", "Pistol Flashlight", 0, 0, "" },
            { "acc_flashlight", "Flashlight", 0, 0, "" }
        };
    };

    class tpc_general_Store {
        name = "TPC - General Store";
        conditions = "playerSide isEqualTo west";
        items[] = {
            { "ItemMap", "Map of Altis", 0, -1, "call life_coplevel >= 1" },
            { "ItemGPS", "Handheld GPS", 0, -1, "call life_coplevel >= 1" },
            { "ItemRadio", "Mobile Phone", 0, -1, "call life_coplevel >= 1" },
            { "ItemCompass", "Compass", 0, -1, "call life_coplevel >= 1" },
            { "ItemWatch", "Wrist Watch", 0, -1, "call life_coplevel >= 1" },
            { "Binocular", "Binoculars", 0, -1, "call life_coplevel >= 1" },
            { "Rangefinder", "Rangefinder", 0, -1, "call life_coplevel >= 2" },
            { "NVGoggles_OPFOR", "Night Vision Goggles", 0, -1, "call life_coplevel >= 1" },
            { "G_Tactical_Black", "Night Vision Glasses", 0, -1, "call life_coplevel >= 1" }, // Premium Membership
            { "FirstAidKit", "First Aid Kit", 0, 0, "" },
            { "ToolKit", "Toolkit", 0, -1, "call life_coplevel >= 1" },
            { "HandGrenade_Stone", "Flashbang Grenade", 0, -1, "license_cop_sfo2 || license_cop_sfo3" },
            { "SmokeShellYellow", "Tear Gas Grenade", 0, -1, "license_cop_sfo3" },
            { "hgun_Pistol_heavy_01_MRD_F", "Taser Pistol", 0, 0, "call life_coplevel >= 1" },
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
            { "UGL_FlareCIR_F", "Flashbang Round", 0, -1, "license_cop_sfo2 || license_cop_sfo3" },
            { "1Rnd_SmokeYellow_Grenade_shell", "Tear Gas Round", 0, -1, "license_cop_sfo3" }
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
            { "acc_pointer_IR", "IR Laser Pointer", 0, -1, "license_cop_sfo3" }
        };
    };

    class nhs_general_store {
        name = "NHS - General Store";
        conditions = "playerSide isEqualTo independent";
        items[] = {
            { "ItemMap", "Map of Altis", 0, -1, "" },
            { "ItemGPS", "Handheld GPS", 0, -1, "" },
            { "ItemRadio", "Mobile Phone", 0, -1, "" },
            { "ItemCompass", "Compass", 0, -1, "" },
            { "ItemWatch", "Wrist Watch", 0, -1, "" },
            { "Binocular", "Binoculars", 0, -1, "" },
            { "NVGoggles", "Night Vision Goggles", 0, -1, "" },
            { "G_Tactical_Black", "Night Vision Glasses", 0, -1, "" }, // Premium Membership
            { "ToolKit", "Toolkit", 0, -1, "" }
        };
        mags[] = {};
        accs[] = {};
    };
};
