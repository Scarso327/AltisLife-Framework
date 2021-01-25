class acc_flashlight {
	price = 0;
	class Textures {};
};

class acc_flashlight_pistol : acc_flashlight {};
class acc_pointer_IR : acc_flashlight {};

class optic_MRD {
	price = 0;
	class Textures {
		class optic_MRD {
			displayName = "Tan";
			condition = "true";
		};
		class optic_MRD_black : optic_MRD { displayName = "Black"; };
	};
};
class optic_MRD_black : optic_MRD {};
class optic_Yorris : optic_MRD {};

class optic_Aco {
    displayName = "ACO";
	price = 0;
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
	price = 0;
	class Textures {
		class optic_Holosight {
			displayName = "Brown";
			condition = "true";
		};
        class optic_Holosight_smg : optic_Holosight { displayName = "Brown (SMG)"; };
		class optic_Holosight_blk_F : optic_Holosight { displayName = "Black"; };
        class optic_Holosight_smg_blk_F : optic_Holosight { displayName = "Black (SMG)"; };
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
	price = 0;
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
	price = 0;
	class Textures {};
};

class optic_Arco {
    displayName = "ARCO";
	price = 0;
	class Textures {
		class optic_Arco {
			displayName = "Black";
			condition = "true";
		};
        class optic_Arco_blk_F : optic_Arco { displayName = "Black"; };
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
	price = 0;
	class Textures {
		class optic_ERCO_blk_F {
			displayName = "Black";
			condition = "true";
		};
        class optic_ERCO_khk_F : optic_ERCO_blk_F { displayName = "Khaki"; };
		class optic_ERCO_snd_F : optic_ERCO_blk_F { displayName = "Sand"; };
	};
};
class optic_ERCO_khk_F : optic_ERCO_blk_F {};
class optic_ERCO_snd_F : optic_ERCO_blk_F {};

class optic_DMS {
    displayName = "DMS";
	price = 0;
	class Textures {
		class optic_DMS {
			displayName = "Black";
			condition = "true";
		};
        class optic_DMS_ghex_F : optic_DMS { displayName = "Green Hex"; };
		class optic_DMS_weathered_F : optic_DMS { displayName = "Old"; };
	};
};
class optic_DMS_ghex_F : optic_DMS {};
class optic_DMS_weathered_F : optic_DMS {};

class optic_NVS {
	price = 0;
	class Textures {};
};

class optic_SOS {
    displayName = "SOS";
	price = 0;
	class Textures {
		class optic_SOS {
			displayName = "Black";
			condition = "true";
		};
        class optic_SOS_khk_F : optic_SOS { displayName = "Khaki"; };
	};
};
class optic_SOS_khk_F : optic_SOS {};

class optic_KHS_blk {
    displayName = "KHS";
	price = 0;
	class Textures {
		class optic_KHS_blk {
			displayName = "Black";
			condition = "true";
		};
        class optic_KHS_hex : optic_KHS_blk { displayName = "Hex"; };
		class optic_KHS_tan : optic_KHS_blk { displayName = "Tan"; };
        class optic_KHS_old : optic_KHS_blk { displayName = "Old"; };
	};
};
class optic_KHS_hex : optic_KHS_blk {};
class optic_KHS_tan : optic_KHS_blk {};
class optic_KHS_old : optic_KHS_blk {};

class muzzle_snds_L {
    displayName = "9mm Suppressor";
	price = 0;
	class Textures {};
};

class muzzle_snds_acp {
    displayName = ".45mm Suppressor";
	price = 0;
	class Textures {};
};

class muzzle_snds_M {
	displayName = "5.56mm Suppressor";
    price = 0;
	class Textures {
        class muzzle_snds_M {
			displayName = "Black";
			condition = "true";
		};
        class muzzle_snds_m_khk_F : muzzle_snds_M { displayName = "Khaki"; };
		class muzzle_snds_m_snd_F : muzzle_snds_M { displayName = "Sand"; };
    };
};
class muzzle_snds_m_khk_F : muzzle_snds_M {};
class muzzle_snds_m_snd_F : muzzle_snds_M {};

class muzzle_snds_570 {
    displayName = "5.7mm Suppressor";
	price = 0;
	class Textures {};
};

class muzzle_snds_58_blk_F {
    displayName = "5.8mm Stealth Suppressor";
	price = 0;
	class Textures {
        class muzzle_snds_58_blk_F {
			displayName = "Black";
			condition = "true";
		};
        class muzzle_snds_58_ghex_F : muzzle_snds_58_blk_F { displayName = "Green Hex"; };
		class muzzle_snds_58_hex_F : muzzle_snds_58_blk_F { displayName = "Brown Hex"; };
    };
};
class muzzle_snds_58_ghex_F : muzzle_snds_58_blk_F {};
class muzzle_snds_58_hex_F : muzzle_snds_58_blk_F {};

class muzzle_snds_H {
    displayName = "6.5mm Suppressor";
	price = 0;
	class Textures {
        class muzzle_snds_H {
			displayName = "Black";
			condition = "true";
		};
        class muzzle_snds_H_khk_F : muzzle_snds_H { displayName = "Khaki"; };
		class muzzle_snds_H_snd_F : muzzle_snds_H { displayName = "Sand"; };
    };
};
class muzzle_snds_H_khk_F : muzzle_snds_H {};
class muzzle_snds_H_snd_F : muzzle_snds_H {};

class muzzle_snds_65_TI_blk_F {
    displayName = "6.5mm Stealth Suppressor";
	price = 0;
	class Textures {
        class muzzle_snds_65_TI_blk_F {
			displayName = "Black";
			condition = "true";
		};
        class muzzle_snds_65_TI_ghex_F : muzzle_snds_65_TI_blk_F { displayName = "Green Hex"; };
		class muzzle_snds_65_TI_hex_F : muzzle_snds_65_TI_blk_F { displayName = "Brown Hex"; };
    };
};
class muzzle_snds_65_TI_ghex_F : muzzle_snds_65_TI_blk_F {};
class muzzle_snds_65_TI_hex_F : muzzle_snds_65_TI_blk_F {};

class muzzle_snds_B {
    displayName = "7.62mm Suppressor";
	price = 0;
	class Textures {
        class muzzle_snds_B {
			displayName = "Black";
			condition = "true";
		};
        class muzzle_snds_B_khk_F : muzzle_snds_B { displayName = "Khaki"; };
		class muzzle_snds_B_snd_F : muzzle_snds_B { displayName = "Sand"; };
        class muzzle_snds_B_lush_F : muzzle_snds_B { displayName = "Lush"; };
		class muzzle_snds_B_arid_F : muzzle_snds_B { displayName = "Arid"; };
    };
};
class muzzle_snds_B_khk_F : muzzle_snds_B {};
class muzzle_snds_B_snd_F : muzzle_snds_B {};
class muzzle_snds_B_lush_F : muzzle_snds_B {};
class muzzle_snds_B_arid_F : muzzle_snds_B {};

class bipod_01_F_blk {
    displayName = "Bipod";
	price = 0;
	class Textures {
        class bipod_01_F_blk {
			displayName = "Black [NATO]";
			condition = "true";
		};
        class bipod_02_F_blk : bipod_01_F_blk { displayName = "Black [CSAT]"; };
		class bipod_03_F_blk : bipod_01_F_blk { displayName = "Black [AAF]"; };
        class bipod_01_F_snd : bipod_01_F_blk { displayName = "Sand [NATO]"; };
		class bipod_02_F_tan : bipod_01_F_blk { displayName = "Tan [CSAT]"; };
        class bipod_03_F_oli : bipod_01_F_blk { displayName = "Olive [AAF]"; };
		class bipod_01_F_khk : bipod_01_F_blk { displayName = "Khaki [NATO]"; };
        class bipod_02_F_hex : bipod_01_F_blk { displayName = "Hex [CSAT]"; };
		class bipod_01_F_mtp : bipod_01_F_blk { displayName = "MTP [NATO]"; };
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