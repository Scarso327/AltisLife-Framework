class hgun_PDW2000_F {
	price = 74880;
	reputation = false;
	class Textures {};
};
class SMG_05_F : hgun_PDW2000_F { price = 78030; };
class SMG_02_F : hgun_PDW2000_F { price = 85185; };
class SMG_01_F : hgun_PDW2000_F { price = 88560; };

class sgun_HunterShotgun_01_sawedoff_F {
	price = 85050;
	reputation = true;
	class Textures {
		class sgun_HunterShotgun_01_sawedoff_F {
			displayName = "Sawed-Off";
			condition = "true";
		};

		class sgun_HunterShotgun_01_F : sgun_HunterShotgun_01_sawedoff_F {
			displayName = "Full-Size";
			price = 100125;
		};
	};
};
class sgun_HunterShotgun_01_F : sgun_HunterShotgun_01_sawedoff_F {};

class SMG_03C_black {
	displayName = "ADR-97C";
	price = 114030;
	reputation = true;
	class Textures {
		class SMG_03C_black {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class SMG_03C_TR_black : SMG_03C_black {  displayName = "Black TR"; };
		class SMG_03C_khaki : SMG_03C_black { 
			displayName = "Khaki"; 
			condition = "true";
		};
		class SMG_03C_TR_khaki : SMG_03C_khaki { displayName = "Khaki TR"; };
		class SMG_03C_hex : SMG_03C_khaki { displayName = "Hex"; };
		class SMG_03C_TR_hex : SMG_03C_khaki { displayName = "Hex TR"; };
		class SMG_03C_camo : SMG_03C_khaki { displayName = "Camo"; };
		class SMG_03C_TR_camo : SMG_03C_khaki { displayName = "Camo TR"; };
	};
};
class SMG_03C_TR_black : SMG_03C_black {};
class SMG_03C_khaki : SMG_03C_black {};
class SMG_03C_TR_khaki : SMG_03C_black {};
class SMG_03C_hex : SMG_03C_black {};
class SMG_03C_TR_hex : SMG_03C_black {};
class SMG_03C_camo : SMG_03C_black {};
class SMG_03C_TR_camo : SMG_03C_black {};

class SMG_03_black {
	displayName = "ADR-97";
	price = 117945;
	reputation = true;
	class Textures {
		class SMG_03_black {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class SMG_03_TR_black : SMG_03_black { displayName = "Black TR"; };
		class SMG_03_khaki : SMG_03_black { 
			displayName = "Khaki"; 
			condition = "true";
		};
		class SMG_03_TR_khaki : SMG_03_khaki { displayName = "Khaki TR"; };
		class SMG_03_hex : SMG_03_khaki { displayName = "Hex"; };
		class SMG_03_TR_hex : SMG_03_khaki { displayName = "Hex TR"; };
		class SMG_03_camo : SMG_03_khaki { displayName = "Camo"; };
		class SMG_03_TR_camo : SMG_03_khaki { displayName = "Camo TR"; };
	};
};
class SMG_03_TR_black : SMG_03_black {};
class SMG_03_khaki : SMG_03_black {};
class SMG_03_TR_khaki : SMG_03_black {};
class SMG_03_hex : SMG_03_black {};
class SMG_03_TR_hex : SMG_03_black {};
class SMG_03_camo : SMG_03_black {};
class SMG_03_TR_camo : SMG_03_black {};

class arifle_AKS_F {
	price = 105660;
	reputation = true;
	class Textures {};
};

class arifle_SDAR_F {
	price = 171450;
	reputation = true;
	class Textures {};
};

class arifle_TRG20_F {
	displayName = "TRG 5.56 mm";
	price = 129960;
	reputation = true;
	class Textures {
		class arifle_TRG20_F {
			displayName = "TRG-20";
			condition = "true";
		};
		class arifle_TRG21_F : arifle_TRG20_F { 
			displayName = "TRG-21"; 
			price = 135180;
		};
	};
};
class arifle_TRG21_F : arifle_TRG20_F {};

class arifle_TRG21_GL_F {
	price = 151560;
	reputation = true;
	class Textures {};
};

class arifle_Mk20C_plain_F {
	displayName = "Mk20C 5.56 mm";
	price = 126900;
	reputation = true;
	class NonLethal {
		distance = 200;
		chance = 0.1;
		injuryThreshold = 0.65;
		projectiles[] = { "B_556x45_Ball_Tracer_Green" };
		sound[] = {};
	};
	class Textures {
		class arifle_Mk20C_plain_F {
			displayName = "Plain";
			condition = "true";
		};
		class arifle_Mk20C_F : arifle_Mk20C_plain_F { 
			displayName = "Camo"; 
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
	};
};
class arifle_Mk20C_F : arifle_Mk20C_plain_F {};

class arifle_Mk20_plain_F {
	displayName = "Mk20 5.56 mm";
	price = 131715;
	reputation = true;
	class Textures {
		class arifle_Mk20_plain_F {
			displayName = "Plain";
			condition = "true";
		};
		class arifle_Mk20_F : arifle_Mk20_plain_F { 
			displayName = "Camo"; 
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
	};
};
class arifle_Mk20_F : arifle_Mk20_plain_F {};

class arifle_Mk20_GL_plain_F {
	displayName = "Mk20C EGLM 5.56 mm";
	price = 153315;
	reputation = true;
	class Textures {
		class arifle_Mk20_GL_plain_F {
			displayName = "Plain";
			condition = "true";
		};
		class arifle_Mk20_GL_F : arifle_Mk20_GL_plain_F { 
			displayName = "Camo"; 
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
	};
};
class arifle_Mk20_GL_F : arifle_Mk20_GL_plain_F {};

class arifle_SPAR_01_blk_F {
	displayName = "SPAR-16 5.56 mm";
	price = 154935;
	reputation = true;
	class Textures {
		class arifle_SPAR_01_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_SPAR_01_khk_F : arifle_SPAR_01_blk_F { 
			displayName = "Khaki";
			condition = "true"; 
		};
		class arifle_SPAR_01_snd_F : arifle_SPAR_01_khk_F { displayName = "Sand"; };
	};
};
class arifle_SPAR_01_khk_F : arifle_SPAR_01_blk_F {};
class arifle_SPAR_01_snd_F : arifle_SPAR_01_blk_F {};

class arifle_SPAR_01_GL_blk_F {
	displayName = "SPAR-16 GL 5.56 mm";
	price = 176535;
	reputation = true;
	class Textures {
		class arifle_SPAR_01_GL_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_SPAR_01_GL_khk_F : arifle_SPAR_01_GL_blk_F { 
			displayName = "Khaki"; 
			condition = "true"; 
		};
		class arifle_SPAR_01_GL_snd_F : arifle_SPAR_01_GL_khk_F { displayName = "Sand"; };
	};
};
class arifle_SPAR_01_GL_khk_F : arifle_SPAR_01_GL_blk_F {};
class arifle_SPAR_01_GL_snd_F : arifle_SPAR_01_GL_blk_F {};

class arifle_SPAR_02_blk_F {
	displayName = "SPAR-16S 5.56 mm";
	price = 180450;
	reputation = true;
	class Textures {
		class arifle_SPAR_02_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_SPAR_02_khk_F : arifle_SPAR_02_blk_F { 
			displayName = "Khaki"; 
			condition = "true"; 
		};
		class arifle_SPAR_02_snd_F : arifle_SPAR_02_khk_F { displayName = "Sand"; };
	};
};
class arifle_SPAR_02_khk_F : arifle_SPAR_02_blk_F {};
class arifle_SPAR_02_snd_F : arifle_SPAR_02_blk_F {};

class LMG_03_F {
	price = 287055;
	reputation = true;
	class Textures {};
};

class arifle_CTAR_blk_F {
	displayName = "CAR-95 5.8 mm";
	price = 177840;
	reputation = true;
	class Textures {
		class arifle_CTAR_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_CTAR_ghex_F : arifle_CTAR_blk_F { 
			displayName = "Green Hex"; 
			condition = "true";
		};
		class arifle_CTAR_hex_F : arifle_CTAR_ghex_F { displayName = "Brown Hex"; };
	};
};
class arifle_CTAR_ghex_F : arifle_CTAR_blk_F {};
class arifle_CTAR_hex_F : arifle_CTAR_blk_F {};

class arifle_CTAR_GL_blk_F {
	displayName = "CAR-95 GL 5.8 mm";
	price = 199440;
	reputation = true;
	class Textures {
		class arifle_CTAR_GL_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_CTAR_GL_ghex_F : arifle_CTAR_GL_blk_F { 
			displayName = "Green Hex";
			condition = "true"; 
		};
		class arifle_CTAR_GL_hex_F : arifle_CTAR_GL_ghex_F { displayName = "Brown Hex"; };
	};
};
class arifle_CTAR_GL_ghex_F : arifle_CTAR_GL_blk_F {};
class arifle_CTAR_GL_hex_F : arifle_CTAR_GL_blk_F {};

class arifle_CTARS_blk_F {
	displayName = "CAR-95-1 5.8 mm";
	price = 197460;
	reputation = true;
	class Textures {
		class arifle_CTARS_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_CTARS_ghex_F : arifle_CTARS_blk_F { 
			displayName = "Green Hex";
			condition = "true"; 
		};
		class arifle_CTARS_hex_F : arifle_CTARS_ghex_F { displayName = "Brown Hex"; };
	};
};
class arifle_CTARS_ghex_F : arifle_CTARS_blk_F {};
class arifle_CTARS_hex_F : arifle_CTARS_blk_F {};

class srifle_DMR_07_blk_F {
	displayName = "CMR-76 6.5 mm";
	price = 183510;
	reputation = true;
	class Textures {
		class srifle_DMR_07_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class srifle_DMR_07_ghex_F : srifle_DMR_07_blk_F { 
			displayName = "Green Hex"; 
			condition = "true";
		};
		class srifle_DMR_07_hex_F : srifle_DMR_07_ghex_F { displayName = "Brown Hex"; };
	};
};
class srifle_DMR_07_ghex_F : srifle_DMR_07_blk_F {};
class srifle_DMR_07_hex_F : srifle_DMR_07_blk_F {};

class arifle_Katiba_C_F {
	price = 210222;
	reputation = true;
	class Textures {};
};

class arifle_Katiba_F {
	price = 217620;
	reputation = true;
	class Textures {};
};

class arifle_Katiba_GL_F {
	price = 239220;
	reputation = true;
	class Textures {};
};

class arifle_MSBS65_black_F {
	displayName = "Promet 6.5 mm";
	price = 214470;
	reputation = true;
	class Textures {
		class arifle_MSBS65_black_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_MSBS65_F : arifle_MSBS65_black_F { 
			displayName = "Green"; 
			condition = "true";
		};
		class arifle_MSBS65_sand_F : arifle_MSBS65_F { displayName = "Sand"; };
		class arifle_MSBS65_camo_F : arifle_MSBS65_F { displayName = "Camo"; };
	};
};
class arifle_MSBS65_F : arifle_MSBS65_black_F {};
class arifle_MSBS65_sand_F : arifle_MSBS65_black_F {};
class arifle_MSBS65_camo_F : arifle_MSBS65_black_F {};

class arifle_MSBS65_GL_black_F {
	displayName = "Promet GL 6.5 mm";
	price = 236070;
	reputation = true;
	class Textures {
		class arifle_MSBS65_GL_black_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_MSBS65_GL_F : arifle_MSBS65_GL_black_F { 
			displayName = "Green"; 
			condition = "true";
		};
		class arifle_MSBS65_GL_sand_F : arifle_MSBS65_GL_F { displayName = "Sand"; };
		class arifle_MSBS65_GL_camo_F : arifle_MSBS65_GL_F { displayName = "Camo"; };
	};
};
class arifle_MSBS65_GL_F : arifle_MSBS65_GL_black_F {};
class arifle_MSBS65_GL_sand_F : arifle_MSBS65_GL_black_F {};
class arifle_MSBS65_GL_camo_F : arifle_MSBS65_GL_black_F {};

class arifle_MSBS65_UBS_black_F {
	displayName = "Promet SG 6.5 mm";
	price = 268470;
	reputation = true;
	class Textures {
		class arifle_MSBS65_UBS_black_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_MSBS65_UBS_F : arifle_MSBS65_UBS_black_F { 
			displayName = "Green"; 
			condition = "true";
		};
		class arifle_MSBS65_UBS_sand_F : arifle_MSBS65_UBS_F { displayName = "Sand"; };
		class arifle_MSBS65_UBS_camo_F : arifle_MSBS65_UBS_F { displayName = "Camo"; };
	};
};
class arifle_MSBS65_UBS_F : arifle_MSBS65_UBS_black_F {};
class arifle_MSBS65_UBS_sand_F : arifle_MSBS65_UBS_black_F {};
class arifle_MSBS65_UBS_camo_F : arifle_MSBS65_UBS_black_F {};

class arifle_MSBS65_Mark_black_F {
	displayName = "Promet MR 6.5 mm";
	price = 214335;
	reputation = true;
	class Textures {
		class arifle_MSBS65_Mark_black_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_MSBS65_Mark_F : arifle_MSBS65_Mark_black_F { 
			displayName = "Green"; 
			condition = "true";
		};
		class arifle_MSBS65_Mark_sand_F : arifle_MSBS65_Mark_F { displayName = "Sand"; };
		class arifle_MSBS65_Mark_camo_F : arifle_MSBS65_Mark_F { displayName = "Camo"; };
	};
};
class arifle_MSBS65_Mark_F : arifle_MSBS65_Mark_black_F {};
class arifle_MSBS65_Mark_sand_F : arifle_MSBS65_Mark_black_F {};
class arifle_MSBS65_Mark_camo_F : arifle_MSBS65_Mark_black_F {};

class arifle_MXC_Black_F {
	displayName = "MXC 6.5 mm";
	price = 177507;
	reputation = true;
	class Textures {
		class arifle_MXC_Black_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_MXC_F : arifle_MXC_Black_F { 
			displayName = "Sand";
			condition = "true"; 
		};
		class arifle_MXC_khk_F : arifle_MXC_F { displayName = "Khaki"; };
	};
};
class arifle_MXC_F : arifle_MXC_Black_F {};
class arifle_MXC_khk_F : arifle_MXC_Black_F {};

class arifle_MX_Black_F {
	displayName = "MX 6.5 mm";
	price = 229860;
	reputation = true;
	class Textures {
		class arifle_MX_Black_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_MX_F : arifle_MX_Black_F { 
			displayName = "Sand"; 
			condition = "true"; 
		};
		class arifle_MX_khk_F : arifle_MX_Black_F { displayName = "Khaki"; };
	};
};
class arifle_MX_F : arifle_MX_Black_F {};
class arifle_MX_khk_F : arifle_MX_Black_F {};

class arifle_MX_GL_Black_F {
	displayName = "MX 3GL 6.5 mm";
	price = 251460;
	reputation = true;
	class Textures {
		class arifle_MX_GL_Black_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_MX_GL_F : arifle_MX_GL_Black_F { 
			displayName = "Sand";
			condition = "true";  
		};
		class arifle_MX_GL_khk_F : arifle_MX_GL_F { displayName = "Khaki"; };
	};
};
class arifle_MX_GL_F : arifle_MX_GL_Black_F {};
class arifle_MX_GL_khk_F : arifle_MX_GL_Black_F {};

class arifle_MXM_Black_F {
	displayName = "MXM 6.5 mm";
	price = 251820;
	reputation = true;
	class Textures {
		class arifle_MXM_Black_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_MXM_F : arifle_MXM_Black_F { 
			displayName = "Sand"; 
			condition = "true"; 
		};
		class arifle_MXM_khk_F : arifle_MXM_F { displayName = "Khaki"; };
	};
};
class arifle_MXM_F : arifle_MXM_Black_F {};
class arifle_MXM_khk_F : arifle_MXM_Black_F {};

class arifle_MX_SW_Black_F {
	displayName = "MX SW 6.5 mm";
	price = 296730;
	reputation = true;
	class Textures {
		class arifle_MX_SW_Black_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_MX_SW_F : arifle_MX_SW_Black_F { 
			displayName = "Sand";
			condition = "true"; 
		};
		class arifle_MX_SW_khk_F : arifle_MX_SW_F { displayName = "Khaki"; };
	};
};
class arifle_MX_SW_F : arifle_MXM_Black_F {};
class arifle_MX_SW_khk_F : arifle_MXM_Black_F {};

class arifle_ARX_blk_F {
	displayName = "Type 115 6.5 mm";
	price = 270540;
	reputation = true;
	class Textures {
		class arifle_ARX_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_ARX_ghex_F : arifle_ARX_blk_F { 
			displayName = "Green Hex";
			condition = "true"; 
		};
		class arifle_ARX_hex_F : arifle_ARX_ghex_F { displayName = "Brown Hex"; };
	};
};
class arifle_ARX_ghex_F : arifle_ARX_blk_F {};
class arifle_ARX_hex_F : arifle_ARX_blk_F {};

class LMG_Mk200_F {
	displayName = "Mk200 6.5 mm";
	price = 419850;
	reputation = true;
	class Textures {
		class LMG_Mk200_F {
			displayName = "Tan";
			condition = "true";
		};
		class LMG_Mk200_black_F : LMG_Mk200_F { 
			displayName = "Black"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
	};
};
class LMG_Mk200_black_F : LMG_Mk200_F {};

class arifle_AKM_F {
	price = 300150;
	reputation = true;
	class Textures {};
};

class arifle_AK12U_F {
	displayName = "AKU-12 7.62 mm";
	price = 310050;
	reputation = true;
	class Textures {
		class arifle_AK12U_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class arifle_AK12U_lush_F : arifle_AK12U_F { 
			displayName = "Lush"; 
			condition = "true";
		};
		class arifle_AK12U_arid_F : arifle_AK12U_lush_F { displayName = "Arid"; };
	};
};
class arifle_AK12U_lush_F : arifle_AK12U_F {};
class arifle_AK12U_arid_F : arifle_AK12U_F {};

class arifle_AK12_F {
	displayName = "AK-12 7.62 mm";
	price = 324450;
	reputation = true;
	class Textures {
		class arifle_AK12_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class arifle_AK12_lush_F : arifle_AK12_F { 
			displayName = "Lush";
			condition = "true";
		};
		class arifle_AK12_arid_F : arifle_AK12_lush_F { displayName = "Arid"; };
	};
};
class arifle_AK12_lush_F : arifle_AK12_F {};
class arifle_AK12_arid_F : arifle_AK12_F {};

class srifle_DMR_01_F {
	price = 258840;
	reputation = true;
	class Textures {};
};

class arifle_SPAR_03_blk_F {
	displayName = "SPAR-17 7.62 mm";
	price = 350010;
	reputation = true;
	class Textures {
		class arifle_SPAR_03_blk_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class arifle_SPAR_03_khk_F : arifle_SPAR_03_blk_F { 
			displayName = "Khaki"; 
			condition = "true";
		};
		class arifle_SPAR_03_snd_F : arifle_SPAR_03_khk_F { displayName = "Sand"; };
	};
};
class arifle_SPAR_03_khk_F : arifle_SPAR_03_blk_F {};
class arifle_SPAR_03_snd_F : arifle_SPAR_03_blk_F {};

class srifle_DMR_06_olive_F {
	displayName = "Mk14 7.62 mm";
	price = 334800;
	reputation = true;
	class Textures {
		class srifle_DMR_06_olive_F { 
			displayName = "Olive"; 
			condition = "true";
		};
		class srifle_DMR_06_camo_F : srifle_DMR_06_olive_F { displayName = "Camo"; };
		class srifle_DMR_06_hunter_F : srifle_DMR_06_olive_F { 
			displayName = "Classic"; 
			price = 324990;
		};
	};
};
class srifle_DMR_06_camo_F : srifle_DMR_06_olive_F {};
class srifle_DMR_06_hunter_F : srifle_DMR_06_olive_F {};

class srifle_EBR_F {
	price = 359730;
	reputation = true;
	class Textures {};
};

class srifle_DMR_03_F {
	displayName = "Mk-I EMR 7.62 mm";
	price = 383310;
	reputation = true;
	class Textures {
		class srifle_DMR_03_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class srifle_DMR_03_khaki_F : srifle_DMR_03_F { 
			displayName = "Khaki"; 
			condition = "true"; 
		};
		class srifle_DMR_03_tan_F : srifle_DMR_03_khaki_F { displayName = "Sand"; };
		class srifle_DMR_03_multicam_F : srifle_DMR_03_khaki_F { displayName = "Camo"; };
		class srifle_DMR_03_woodland_F : srifle_DMR_03_khaki_F { displayName = "Woodland"; };
	};
};
class srifle_DMR_03_khaki_F : srifle_DMR_03_F {};
class srifle_DMR_03_tan_F : srifle_DMR_03_F {};
class srifle_DMR_03_multicam_F : srifle_DMR_03_F {};
class srifle_DMR_03_woodland_F : srifle_DMR_03_F {};

class LMG_Zafir_F {
	price = 1111500;
	reputation = true;
	class Textures {};
};

class srifle_DMR_04_F {
	displayName = "ASP-1 Kir 12.7 mm";
	price = 801405;
	reputation = true;
	class Textures {
		class srifle_DMR_04_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class srifle_DMR_04_Tan_F : srifle_DMR_04_F { 
			displayName = "Tan"; 
			condition = "true";
		};
	};
};
class srifle_DMR_04_Tan_F : srifle_DMR_04_F {};

class srifle_DMR_02_F {
	displayName = "MAR-10 .338";
	price = 5634630;
	reputation = true;
	class Textures {
		class srifle_DMR_02_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class srifle_DMR_02_sniper_F : srifle_DMR_02_F { 
			displayName = "Sand"; 
			condition = "true";
		};
		class srifle_DMR_02_camo_F : srifle_DMR_02_sniper_F { displayName = "Camo"; };
	};
};
class srifle_DMR_02_sniper_F : srifle_DMR_02_F {};
class srifle_DMR_02_camo_F : srifle_DMR_02_F {};

class srifle_DMR_05_blk_F {
	displayName = "Cyrus 9.3 mm";
	price = 8595000;
	reputation = true;
	class Textures {
		class srifle_DMR_02_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class srifle_DMR_05_tan_f : srifle_DMR_02_F { 
			displayName = "Tan";
			condition = "true"; 
		};
		class srifle_DMR_05_hex_F : srifle_DMR_05_tan_f { displayName = "Hex"; };
	};
};
class srifle_DMR_05_tan_f : srifle_DMR_05_blk_F {};
class srifle_DMR_05_hex_F : srifle_DMR_05_blk_F {};

class srifle_LRR_F {
	displayName = "M320 LRR .408";
	price = 10170270;
	reputation = true;
	class Textures {
		class srifle_LRR_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class srifle_LRR_tna_F : srifle_LRR_F { 
			displayName = "Tropic"; 
			condition = "true";
		};
	};
};
class srifle_LRR_tna_F : srifle_LRR_F {};