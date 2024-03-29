class acc_flashlight {
	price = 130;
	reputation = true;
	class Textures {};
};
class acc_flashlight_pistol : acc_flashlight { price = 70; };
class acc_pointer_IR : acc_flashlight { price = 1620; };

class optic_MRD {
	price = 980;
	reputation = true;
	class Textures {
		class optic_MRD {
			displayName = "Tan";
			condition = "true";
		};
		class optic_MRD_black : optic_MRD { 
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
	};
};
class optic_MRD_black : optic_MRD {};
class optic_Yorris : optic_MRD { price = 985; };

class optic_Aco {
    displayName = "ACO";
	price = 1450;
	reputation = true;
	class Textures {
		class optic_Aco {
			displayName = "Red";
			condition = "true";
		};
        class optic_Aco_smg : optic_Aco { displayName = "Red (SMG)"; };
		class optic_ACO_grn : optic_Aco { displayName = "Green"; };
        class optic_ACO_grn_smg : optic_Aco { displayName = "Green (SMG)"; };
	};
};
class optic_Aco_smg : optic_Aco {};
class optic_ACO_grn : optic_Aco {};
class optic_ACO_grn_smg : optic_Aco {};

class optic_Holosight {
    displayName = "Holosight";
	price = 1760;
	reputation = true;
	class Textures {
		class optic_Holosight {
			displayName = "Brown";
			condition = "true";
		};
        class optic_Holosight_smg : optic_Holosight { displayName = "Brown (SMG)"; };
		class optic_Holosight_blk_F : optic_Holosight { 
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }"; 
		};
        class optic_Holosight_smg_blk_F : optic_Holosight_blk_F { displayName = "Black (SMG)"; };
        class optic_Holosight_khk_F : optic_Holosight { displayName = "Khaki"; };
        class optic_Holosight_smg_khk_F : optic_Holosight { displayName = "Khaki (SMG)"; };
        class optic_Holosight_lush_F : optic_Holosight { displayName = "Lush"; };
        class optic_Holosight_arid_F : optic_Holosight { displayName = "Arid"; };
	};
};
class optic_Holosight_smg : optic_Holosight {};
class optic_Holosight_blk_F : optic_Holosight {};
class optic_Holosight_smg_blk_F : optic_Holosight {};
class optic_Holosight_khk_F : optic_Holosight {};
class optic_Holosight_smg_khk_F : optic_Holosight {};
class optic_Holosight_lush_F : optic_Holosight {};
class optic_Holosight_arid_F : optic_Holosight {};

class optic_Hamr {
    displayName = "RCO";
	price = 7800;
	reputation = true;
	class Textures {
		class optic_Hamr {
			displayName = "Black";
			condition = "true";
		};
		class optic_Hamr_khk_F : optic_Hamr { displayName = "Khaki"; };
	};
};
class optic_Hamr_khk_F : optic_Hamr {};

class optic_MRCO {
	price = 8630;
	reputation = true;
	class Textures {};
};

class optic_Arco {
    displayName = "ARCO";
	price = 14950;
	reputation = true;
	class Textures {
		class optic_Arco {
			displayName = "Brown";
			condition = "true";
		};
        class optic_Arco_blk_F : optic_Arco { 
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";  
		};
		class optic_Arco_ghex_F : optic_Arco { displayName = "Green Hex"; };
        class optic_Arco_lush_F : optic_Arco { displayName = "Lush"; };
        class optic_Arco_arid_F : optic_Arco { displayName = "Arid"; };
	};
};
class optic_Arco_blk_F : optic_Arco {};
class optic_Arco_ghex_F : optic_Arco {};
class optic_Arco_lush_F : optic_Arco {};
class optic_Arco_arid_F : optic_Arco {};

class optic_ERCO_blk_F {
    displayName = "ERCO";
	price = 15320;
	reputation = true;
	class Textures {
		class optic_ERCO_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }"; 
		};
        class optic_ERCO_khk_F : optic_ERCO_blk_F { 
			displayName = "Khaki";
			condition = "true"; 
		};
		class optic_ERCO_snd_F : optic_ERCO_khk_F { displayName = "Sand"; };
	};
};
class optic_ERCO_khk_F : optic_ERCO_blk_F {};
class optic_ERCO_snd_F : optic_ERCO_blk_F {};

class optic_DMS {
    displayName = "DMS";
	price = 415000;
	reputation = true;
	class Textures {
		class optic_DMS {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
        class optic_DMS_ghex_F : optic_DMS { 
			displayName = "Green Hex";
			condition = "true";  
		};
		class optic_DMS_weathered_F : optic_DMS_ghex_F { displayName = "Old"; };
	};
};
class optic_DMS_ghex_F : optic_DMS {};
class optic_DMS_weathered_F : optic_DMS {};

class optic_NVS {
	price = 380200;
	reputation = true;
	class Textures {};
};

class optic_SOS {
    displayName = "SOS";
	price = 434500;
	reputation = true;
	class Textures {
		class optic_SOS {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
        class optic_SOS_khk_F : optic_SOS { 
			displayName = "Khaki"; 
			condition = "true";
		};
	};
};
class optic_SOS_khk_F : optic_SOS {};

class optic_KHS_blk {
    displayName = "KHS";
	price = 735400;
	reputation = true;
	class Textures {
		class optic_KHS_blk {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
        class optic_KHS_hex : optic_KHS_blk { 
			displayName = "Hex"; 
			condition = "true";
		};
		class optic_KHS_tan : optic_KHS_hex { displayName = "Tan"; };
        class optic_KHS_old : optic_KHS_hex { displayName = "Old"; };
	};
};
class optic_KHS_hex : optic_KHS_blk {};
class optic_KHS_tan : optic_KHS_blk {};
class optic_KHS_old : optic_KHS_blk {};

class optic_AMS {
    displayName = "AMS";
	price = 805300;
	reputation = true;
	class Textures {
		class optic_AMS {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
        class optic_AMS_khk : optic_AMS { 
			displayName = "Khaki"; 
			condition = "true";
		};
		class optic_AMS_snd : optic_AMS_khk { displayName = "Sand"; };
	};
};
class optic_AMS_khk : optic_AMS {};
class optic_AMS_snd : optic_AMS {};

class optic_LRPS {
    displayName = "LRPS";
	price = 1140600;
	reputation = true;
	class Textures {
		class optic_LRPS {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
        class optic_LRPS_tna_F : optic_LRPS { 
			displayName = "Tropic"; 
			condition = "true";
		};
		class optic_LRPS_ghex_F : optic_LRPS { displayName = "Green Hex"; };
	};
};
class optic_LRPS_tna_F : optic_LRPS {};
class optic_LRPS_ghex_F : optic_LRPS {};

class muzzle_snds_L {
    displayName = "9mm Suppressor";
	price = 4800;
	reputation = true;
	class Textures {};
};

class muzzle_snds_acp {
    displayName = ".45mm Suppressor";
	price = 4950;
	reputation = true;
	class Textures {};
};

class muzzle_snds_M {
	displayName = "5.56mm Suppressor";
    price = 36700;
	reputation = true;
	class Textures {
        class muzzle_snds_M {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
        class muzzle_snds_m_khk_F : muzzle_snds_M { 
			displayName = "Khaki"; 
			condition = "true";  
		};
		class muzzle_snds_m_snd_F : muzzle_snds_m_khk_F { displayName = "Sand"; };
    };
};
class muzzle_snds_m_khk_F : muzzle_snds_M {};
class muzzle_snds_m_snd_F : muzzle_snds_M {};

class muzzle_snds_570 {
    displayName = "5.7mm Suppressor";
	price = 43450;
	reputation = true;
	class Textures {};
};

class muzzle_snds_58_blk_F {
    displayName = "5.8mm Stealth Suppressor";
	price = 57900;
	reputation = true;
	class Textures {
        class muzzle_snds_58_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
        class muzzle_snds_58_ghex_F : muzzle_snds_58_blk_F { 
			displayName = "Green Hex";
			condition = "true";  
		};
		class muzzle_snds_58_hex_F : muzzle_snds_58_ghex_F { displayName = "Brown Hex"; };
    };
};
class muzzle_snds_58_ghex_F : muzzle_snds_58_blk_F {};
class muzzle_snds_58_hex_F : muzzle_snds_58_blk_F {};

class muzzle_snds_H {
    displayName = "6.5mm Suppressor";
	price = 92300;
	reputation = true;
	class Textures {
        class muzzle_snds_H {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
        class muzzle_snds_H_khk_F : muzzle_snds_H { 
			displayName = "Khaki";
			condition = "true"; 
		};
		class muzzle_snds_H_snd_F : muzzle_snds_H_khk_F { displayName = "Sand"; };
    };
};
class muzzle_snds_H_khk_F : muzzle_snds_H {};
class muzzle_snds_H_snd_F : muzzle_snds_H {};

class muzzle_snds_65_TI_blk_F {
    displayName = "6.5mm Stealth Suppressor";
	price = 162450;
	reputation = true;
	class Textures {
        class muzzle_snds_65_TI_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
        class muzzle_snds_65_TI_ghex_F : muzzle_snds_65_TI_blk_F { 
			displayName = "Green Hex";
			condition = "true"; 
		};
		class muzzle_snds_65_TI_hex_F : muzzle_snds_65_TI_ghex_F { displayName = "Brown Hex"; };
    };
};
class muzzle_snds_65_TI_ghex_F : muzzle_snds_65_TI_blk_F {};
class muzzle_snds_65_TI_hex_F : muzzle_snds_65_TI_blk_F {};

class muzzle_snds_B {
    displayName = "7.62mm Suppressor";
	price = 460300;
	reputation = true;
	class Textures {
        class muzzle_snds_B {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
        class muzzle_snds_B_khk_F : muzzle_snds_B { 
			displayName = "Khaki";
			condition = "true"; 
		};
		class muzzle_snds_B_snd_F : muzzle_snds_B_khk_F { displayName = "Sand"; };
        class muzzle_snds_B_lush_F : muzzle_snds_B_khk_F { displayName = "Lush"; };
		class muzzle_snds_B_arid_F : muzzle_snds_B_khk_F { displayName = "Arid"; };
    };
};
class muzzle_snds_B_khk_F : muzzle_snds_B {};
class muzzle_snds_B_snd_F : muzzle_snds_B {};
class muzzle_snds_B_lush_F : muzzle_snds_B {};
class muzzle_snds_B_arid_F : muzzle_snds_B {};

class bipod_01_F_blk {
    displayName = "Bipod";
	price = 540;
	reputation = true;
	class Textures {
        class bipod_01_F_blk {
			displayName = "Black [NATO]";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
        class bipod_02_F_blk : bipod_01_F_blk { displayName = "Black [CSAT]"; };
		class bipod_03_F_blk : bipod_01_F_blk { displayName = "Black [AAF]"; };
        class bipod_01_F_snd : bipod_01_F_blk { 
			displayName = "Sand [NATO]"; 
			condition = "true";
		};
		class bipod_02_F_tan : bipod_01_F_snd { displayName = "Tan [CSAT]"; };
        class bipod_03_F_oli : bipod_01_F_snd { displayName = "Olive [AAF]"; };
		class bipod_01_F_khk : bipod_01_F_snd { displayName = "Khaki [NATO]"; };
        class bipod_02_F_hex : bipod_01_F_snd { displayName = "Hex [CSAT]"; };
		class bipod_01_F_mtp : bipod_01_F_snd { displayName = "MTP [NATO]"; };
    };
};
class bipod_02_F_blk : bipod_01_F_blk {};
class bipod_03_F_blk : bipod_01_F_blk {};
class bipod_01_F_snd : bipod_01_F_blk {};
class bipod_02_F_tan : bipod_01_F_blk {};
class bipod_03_F_oli : bipod_01_F_blk {};
class bipod_01_F_khk : bipod_01_F_blk {};
class bipod_02_F_hex : bipod_01_F_blk {};
class bipod_01_F_mtp : bipod_01_F_blk {};