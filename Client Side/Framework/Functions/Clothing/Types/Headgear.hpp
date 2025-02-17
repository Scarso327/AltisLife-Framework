class H_HeadBandage_clean_F {
	displayName = "Bandage";
	price = 5;
	reputation = false;
	isMask = false;
	isNV = false;
	class Textures {};
};
class H_HeadBandage_stained_F : H_HeadBandage_clean_F {};
class H_HeadBandage_bloody_F : H_HeadBandage_clean_F {};

class H_Hat_Tinfoil_F : H_HeadBandage_clean_F {
	displayName = "Tin Foil";
	price = 5;
	class Textures {};
};

class H_WirelessEarpiece_F : H_HeadBandage_clean_F {
	displayName = "Wireless Earpiece";
	price = 10;
	class Textures {};
};

class H_Bandanna_gry : H_HeadBandage_clean_F {
	displayName = "Bandanna";
	price = 10;
	class Textures {
		class H_Bandanna_gry {
			displayName = "Gray";
			condition = "true";
		};
		class H_Bandanna_blu : H_Bandanna_gry { displayName = "Blue"; };
		class H_Bandanna_khk : H_Bandanna_gry { displayName = "Khaki"; };
		class H_Bandanna_cbr : H_Bandanna_gry { displayName = "Coyote"; };
		class H_Bandanna_sand : H_Bandanna_gry { displayName = "Sand"; };
		class H_Bandanna_sgg : H_Bandanna_gry { displayName = "Sage"; };
		class H_Bandanna_camo : H_Bandanna_gry { displayName = "Camo"; };
		class H_Bandanna_mcamo : H_Bandanna_gry { 
			displayName = "MTP";
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
		class H_Bandanna_surfer : H_Bandanna_mcamo { displayName = "Surfer"; };
		class H_Bandanna_surfer_blk : H_Bandanna_mcamo { displayName = "Surfer, Black"; };
		class H_Bandanna_surfer_grn : H_Bandanna_mcamo { displayName = "Surfer, Green"; };
	};
};
class H_Bandanna_blu : H_Bandanna_gry {};
class H_Bandanna_khk : H_Bandanna_gry {};
class H_Bandanna_khk_hs : H_Bandanna_gry {};
class H_Bandanna_cbr : H_Bandanna_gry {};
class H_Bandanna_sand : H_Bandanna_gry {};
class H_Bandanna_sgg : H_Bandanna_gry {};
class H_Bandanna_camo : H_Bandanna_gry {};
class H_Bandanna_mcamo : H_Bandanna_gry {};
class H_Bandanna_surfer : H_Bandanna_gry {};
class H_Bandanna_surfer_blk : H_Bandanna_gry {};
class H_Bandanna_surfer_grn : H_Bandanna_gry {};

class H_Cap_blk : H_HeadBandage_clean_F {
	displayName = "Cap";
	price = 50;
	class Textures {
		class H_Cap_blk {
			displayName = "Black";
			condition = "true";
		};
		class H_Cap_red : H_Cap_blk { displayName = "Red"; };
		class H_Cap_blu : H_Cap_blk { displayName = "Blue"; };
		class H_Cap_tan : H_Cap_blk { displayName = "Tan"; };
		class H_Cap_oli : H_Cap_blk { displayName = "Olive"; };
		class H_Cap_oli_hs : H_Cap_blk { displayName = "Olive (Headset)"; };
		class H_Cap_marshal : H_Cap_blk { displayName = "Red (Headset)"; };
		class H_Cap_press : H_Cap_blk { displayName = "Press"; };
		class H_Cap_usblack : H_Cap_blk { 
			displayName = "US (Black)";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class H_Cap_tan_specops_US : H_Cap_usblack { displayName = "US (MTP)"; };
		class H_Cap_khaki_specops_UK : H_Cap_usblack { displayName = "UK"; };
		class H_Cap_brn_SPECOPS : H_Cap_usblack { displayName = "OPFOR"; };
		class H_Cap_blk_Raven : H_Cap_usblack { displayName = "AAF"; };
		class H_Cap_grn_BI : H_Cap_usblack { displayName = "BI"; };
		class H_Cap_blk_ION : H_Cap_usblack { displayName = "ION"; };
		class H_Cap_blk_CMMG : H_Cap_usblack { displayName = "CMMG"; };
		class H_Cap_Black_IDAP_F : H_Cap_usblack { displayName = "IDAP (Black)"; };
		class H_Cap_White_IDAP_F : H_Cap_usblack { displayName = "IDAP (White)"; };
		class H_Cap_Orange_IDAP_F : H_Cap_usblack { displayName = "IDAP (Orange)"; };
		class H_Cap_surfer : H_Cap_usblack { displayName = "Surfer"; };
		class H_Cap_police : H_Cap_blk {
			displayName = "Police";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		};
	};
};
class H_Cap_usblack : H_Cap_blk {};
class H_Cap_tan_specops_US : H_Cap_blk {};
class H_Cap_khaki_specops_UK : H_Cap_blk {};
class H_Cap_brn_SPECOPS : H_Cap_blk {};
class H_Cap_blk_Raven : H_Cap_blk {};
class H_Cap_police : H_Cap_blk {};
class H_Cap_press : H_Cap_blk {};
class H_Cap_grn_BI : H_Cap_blk {};
class H_Cap_blk_ION : H_Cap_blk {};
class H_Cap_blk_CMMG : H_Cap_blk {};
class H_Cap_red : H_Cap_blk {};
class H_Cap_blu : H_Cap_blk {};
class H_Cap_tan : H_Cap_blk {};
class H_Cap_oli : H_Cap_blk {};
class H_Cap_oli_hs : H_Cap_blk {};
class H_Cap_marshal : H_Cap_blk {};
class H_Cap_surfer : H_Cap_blk {};
class H_Cap_Black_IDAP_F : H_Cap_blk {};
class H_Cap_White_IDAP_F : H_Cap_blk {};
class H_Cap_Orange_IDAP_F : H_Cap_blk {};

class H_MilCap_gry : H_HeadBandage_clean_F {
	displayName = "Military Cap";
	price = 50;
	class Textures {
		class H_MilCap_gry {
			displayName = "Black";
			condition = "true";
		};
		class H_MilCap_blue : H_MilCap_gry { displayName = "Blue"; };
		class H_MilCap_grn : H_MilCap_gry { displayName = "Green"; };
		class H_MilCap_wdl : H_MilCap_gry { 
			displayName = "Woodland";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class H_MilCap_ghex_F : H_MilCap_wdl { displayName = "Green Hex"; };
		class H_MilCap_ocamo : H_MilCap_wdl { displayName = "Hex"; };
		class H_MilCap_mcamo : H_MilCap_wdl { displayName = "MTP"; };
		class H_MilCap_taiga : H_MilCap_wdl { displayName = "Taiga"; };
		class H_MilCap_tna_F : H_MilCap_wdl { displayName = "Tropic"; };
		class H_MilCap_dgtl : H_MilCap_wdl { displayName = "AAF"; };
		class H_MilCap_eaf : H_MilCap_wdl { displayName = "LDF"; };
	};
};
class H_MilCap_blue : H_MilCap_gry {};
class H_MilCap_grn : H_MilCap_gry {};
class H_MilCap_wdl : H_MilCap_gry {};
class H_MilCap_ghex_F : H_MilCap_gry {};
class H_MilCap_ocamo : H_MilCap_gry {};
class H_MilCap_mcamo : H_MilCap_gry {};
class H_MilCap_taiga : H_MilCap_gry {};
class H_MilCap_tna_F : H_MilCap_gry {};
class H_MilCap_dgtl : H_MilCap_gry {};
class H_MilCap_eaf : H_MilCap_gry {};

class H_Hat_grey : H_HeadBandage_clean_F {
	displayName = "Fedora Hat";
	price = 50;
	class Textures {
		class H_Hat_grey {
			displayName = "Grey";
			condition = "true";
		};
		class H_Hat_blue : H_Hat_grey { displayName = "Blue"; };
		class H_Hat_brown : H_Hat_grey { displayName = "Brown"; };
		class H_Hat_tan : H_Hat_grey { displayName = "Tan"; };
		class H_Hat_checker : H_Hat_grey { 
			displayName = "Checker";
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
		class H_Hat_camo : H_Hat_checker { displayName = "Camo"; };
	};
};
class H_Hat_blue : H_Hat_grey {};
class H_Hat_brown : H_Hat_grey {};
class H_Hat_tan : H_Hat_grey {};
class H_Hat_checker : H_Hat_grey {};
class H_Hat_camo : H_Hat_grey {};

class H_StrawHat : H_HeadBandage_clean_F {
	displayName = "Straw Hat";
	price = 50;
	class Textures {
		class H_StrawHat {
			displayName = "Light Brown";
			condition = "true";
		};
		class H_StrawHat_dark : H_StrawHat { displayName = "Dark Brown"; };
	};
};
class H_StrawHat_dark : H_StrawHat {};

class H_Hat_Safari_sand_F : H_HeadBandage_clean_F {
	displayName = "Safari Hat";
	price = 60;
	class Textures {
		class H_Hat_Safari_sand_F {
			displayName = "Sand";
			condition = "true";
		};
		class H_Hat_Safari_olive_F : H_Hat_Safari_sand_F { 
			displayName = "Olive"; 
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
	};
};
class H_Hat_Safari_olive_F : H_Hat_Safari_sand_F {};

class H_Watchcap_blk : H_HeadBandage_clean_F {
	displayName = "Beanie";
	price = 80;
	class Textures {
		class H_Watchcap_blk {
			displayName = "Black";
			condition = "true";
		};
		class H_Watchcap_cbr : H_Watchcap_blk { displayName = "Brown"; };
		class H_Watchcap_khk : H_Watchcap_blk { displayName = "Khaki"; };
		class H_Watchcap_camo : H_Watchcap_blk { displayName = "Green"; };
	};
};
class H_Watchcap_cbr : H_Watchcap_blk {};
class H_Watchcap_khk : H_Watchcap_blk {};
class H_Watchcap_camo : H_Watchcap_blk {};

class H_Booniehat_khk : H_HeadBandage_clean_F {
	displayName = "Bonniehat";
	price = 80;
	class Textures {
		class H_Booniehat_khk {
			displayName = "Khaki";
			condition = "true";
		};
		class H_Booniehat_grn : H_Booniehat_khk { displayName = "Green"; };
		class H_Booniehat_oli : H_Booniehat_khk { displayName = "Olive"; };
		class H_Booniehat_tan : H_Booniehat_khk { displayName = "Tan"; };
		class H_Booniehat_mcamo : H_Booniehat_khk { 
			displayName = "MTP"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class H_Booniehat_dgtl : H_Booniehat_mcamo { displayName = "Digital"; };
		class H_Booniehat_wdl : H_Booniehat_mcamo { displayName = "Woodland"; };
		class H_Booniehat_mgrn : H_Booniehat_mcamo { displayName = "Green (Faded)"; };
		class H_Booniehat_taiga : H_Booniehat_mcamo { displayName = "Taiga"; };
		class H_Booniehat_tna_F : H_Booniehat_mcamo { displayName = "Tropic"; };
		class H_Booniehat_eaf : H_Booniehat_mcamo { displayName = "LDF"; };
	};
};
class H_Booniehat_khk_hs : H_Booniehat_khk {};
class H_Booniehat_grn : H_Booniehat_khk {};
class H_Booniehat_oli : H_Booniehat_khk {};
class H_Booniehat_tan : H_Booniehat_khk {};
class H_Booniehat_mcamo : H_Booniehat_khk {};
class H_Booniehat_dgtl : H_Booniehat_khk {};
class H_Booniehat_wdl : H_Booniehat_khk {};
class H_Booniehat_mgrn : H_Booniehat_khk {};
class H_Booniehat_taiga : H_Booniehat_khk {};
class H_Booniehat_tna_F : H_Booniehat_khk {};
class H_Booniehat_eaf : H_Booniehat_khk {};

class H_Beret_blk : H_HeadBandage_clean_F {
	displayName = "Beret";
	price = 1000;
	class Textures {
		// Altis Police Service
		class H_Beret_blk {
			displayName = "Police Patrol";
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
		};
		class H_Beret_gen_F : H_Beret_blk {
			displayName = "Police Command";
			condition = "[""Police_Main"", 8] call ULP_fnc_hasAccess || { [""Police_COL"", 3] call ULP_fnc_hasAccess }";
		};
		class H_Beret_EAF_01_F : H_Beret_blk {
			displayName = "Spec. Command";
			condition = "[""Police_SCO"", 3] call ULP_fnc_hasAccess || { [""Police_NCA"", 3] call ULP_fnc_hasAccess }";
		};

		// Altis Ambulance Service
		class H_Beret_02 : H_Beret_blk {
			displayName = "Directors' of Ambulance Services";
			condition = "[""Medic_Main"", 7] call ULP_fnc_hasAccess";
		};
		class H_Beret_Colonel : H_Beret_blk {
			displayName = "Department Head";
			condition = "[""Medic_Main"", 6] call ULP_fnc_hasAccess";
		};
		class H_Beret_CSAT_01_F : H_Beret_blk {
			displayName = "HEMS Beret";
			condition = "[""Medic_AA"", 1] call ULP_fnc_hasAccess";
		};
	};
};
class H_Beret_gen_F : H_Beret_blk {};
class H_Beret_EAF_01_F : H_Beret_blk {};
class H_Beret_02 : H_Beret_blk {};
class H_Beret_Colonel : H_Beret_blk {};
class H_Beret_CSAT_01_F : H_Beret_blk {};

class H_ShemagOpen_khk : H_HeadBandage_clean_F {
	displayName = "Shemag";
	price = 2000;
	reputation = true;
	isMask = true;
	class Textures {
		class H_ShemagOpen_khk {
			displayName = "White";
			condition = "true";
		};
		class H_Shemag_tan : H_ShemagOpen_khk { displayName = "Tan"; };
		class H_Shemag_olive : H_ShemagOpen_khk { displayName = "Olive"; };
		class H_Shemag_olive_hs : H_ShemagOpen_khk { 
			displayName = "Olive (Headset)";
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
	};
};
class H_Shemag_tan : H_ShemagOpen_khk {};
class H_Shemag_olive : H_ShemagOpen_khk {};
class H_Shemag_olive_hs : H_ShemagOpen_khk {};

class H_EarProtectors_black_F : H_HeadBandage_clean_F {
	displayName = "Ear Protectors";
	price = 100;
	class Textures {
		class H_EarProtectors_black_F {
			displayName = "Black";
			condition = "true";
		};
		class H_HeadSet_black_F : H_EarProtectors_black_F { displayName = "Black (Headset)"; };
		class H_EarProtectors_white_F : H_EarProtectors_black_F { displayName = "White"; };
		class H_HeadSet_white_F : H_EarProtectors_black_F { displayName = "White (Headset)"; };
		class H_EarProtectors_red_F : H_EarProtectors_black_F { displayName = "Red"; };
		class H_HeadSet_red_F : H_EarProtectors_black_F { displayName = "Red (Headset)"; };
		class H_EarProtectors_orange_F : H_EarProtectors_black_F { displayName = "Orange"; };
		class H_HeadSet_orange_F : H_EarProtectors_black_F { displayName = "Orange (Headset)"; };
		class H_EarProtectors_yellow_F : H_EarProtectors_black_F { displayName = "Yellow"; };
		class H_HeadSet_yellow_F : H_EarProtectors_black_F { displayName = "Yellow (Headset)"; };
	};
};
class H_EarProtectors_white_F : H_EarProtectors_black_F {};
class H_EarProtectors_red_F : H_EarProtectors_black_F {};
class H_EarProtectors_orange_F : H_EarProtectors_black_F {};
class H_EarProtectors_yellow_F : H_EarProtectors_black_F {};
class H_HeadSet_black_F : H_EarProtectors_black_F {};
class H_HeadSet_white_F : H_EarProtectors_black_F {};
class H_HeadSet_red_F : H_EarProtectors_black_F {};
class H_HeadSet_orange_F : H_EarProtectors_black_F {};
class H_HeadSet_yellow_F : H_EarProtectors_black_F {};

class H_Construction_basic_black_F : H_HeadBandage_clean_F {
	displayName = "Hard Hat";
	price = 150;
	class Textures {
		class H_Construction_basic_black_F {
			displayName = "Black";
			condition = "true";
		};
		class H_Construction_headset_black_F : H_Construction_basic_black_F { displayName = "Black (Headset)"; };
		class H_Construction_basic_white_F : H_Construction_basic_black_F { displayName = "White"; };
		class H_Construction_headset_white_F : H_Construction_basic_black_F { displayName = "White (Headset)"; };
		class H_Construction_basic_red_F : H_Construction_basic_black_F { displayName = "Red"; };
		class H_Construction_headset_red_F : H_Construction_basic_black_F { displayName = "Red (Headset)"; };
		class H_Construction_basic_orange_F : H_Construction_basic_black_F { displayName = "Orange"; };
		class H_Construction_headset_orange_F : H_Construction_basic_black_F { displayName = "Orange (Headset)"; };
		class H_Construction_basic_yellow_F : H_Construction_basic_black_F { displayName = "Yellow"; };
		class H_Construction_headset_yellow_F : H_Construction_basic_black_F { displayName = "Yellow (Headset)"; };
		class H_Construction_basic_vrana_F : H_Construction_basic_black_F { displayName = "Virana"; };
		class H_Construction_headset_vrana_F : H_Construction_basic_black_F { displayName = "Virana (Headset)"; };
	};
};
class H_Construction_headset_black_F : H_Construction_basic_black_F {};
class H_Construction_basic_white_F : H_Construction_basic_black_F {};
class H_Construction_headset_white_F : H_Construction_basic_black_F {};
class H_Construction_basic_red_F : H_Construction_basic_black_F {};
class H_Construction_headset_red_F : H_Construction_basic_black_F {};
class H_Construction_basic_orange_F : H_Construction_basic_black_F {};
class H_Construction_headset_orange_F : H_Construction_basic_black_F {};
class H_Construction_basic_yellow_F : H_Construction_basic_black_F {};
class H_Construction_headset_yellow_F : H_Construction_basic_black_F {};
class H_Construction_basic_vrana_F : H_Construction_basic_black_F {};
class H_Construction_headset_vrana_F : H_Construction_basic_black_F {};

class H_Helmet_Skate : H_HeadBandage_clean_F {
	displayName = "Skate Helmet";
	price = 300;
	class Textures {};
};

class H_RacingHelmet_1_black_F : H_HeadBandage_clean_F {
	displayName = "Racing Helmet";
	price = 1500;
	isMask = true;
	class Textures {
		class H_RacingHelmet_1_black_F {
			displayName = "Black";
			condition = "true";
		};
		class H_RacingHelmet_1_white_F : H_RacingHelmet_1_black_F { displayName = "Black"; };
		class H_RacingHelmet_1_red_F : H_RacingHelmet_1_black_F { displayName = "Red"; };
		class H_RacingHelmet_1_blue_F : H_RacingHelmet_1_black_F { displayName = "Blue"; };
		class H_RacingHelmet_1_green_F : H_RacingHelmet_1_black_F { displayName = "Green"; };
		class H_RacingHelmet_1_orange_F : H_RacingHelmet_1_black_F { displayName = "Orange"; };
		class H_RacingHelmet_1_yellow_F : H_RacingHelmet_1_black_F { displayName = "Yellow"; };
		class H_RacingHelmet_4_F : H_RacingHelmet_1_black_F { 
			displayName = "Vrana";
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
		class H_RacingHelmet_3_F : H_RacingHelmet_4_F { displayName = "Redstone"; };
		class H_RacingHelmet_2_F : H_RacingHelmet_4_F { displayName = "Bluking"; };
		class H_RacingHelmet_1_F : H_RacingHelmet_4_F { displayName = "Fuel"; };
	};
};
class H_RacingHelmet_1_white_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_red_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_blue_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_green_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_orange_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_yellow_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_4_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_3_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_2_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_F : H_RacingHelmet_1_black_F {};

class H_PASGT_basic_black_F : H_HeadBandage_clean_F {
	displayName = "Basic Helmet";
	price = 10000;
	reputation = true;
	class Textures {
		class H_PASGT_basic_black_F {
			displayName = "Black";
			condition = "[""Police_COL"", 1] call ULP_fnc_hasAccess";
		};
		class H_PASGT_basic_blue_F : H_PASGT_basic_black_F { 
			displayName = "Blue"; 
			condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess";
		};
		class H_PASGT_basic_white_F : H_PASGT_basic_black_F { 
			displayName = "White"; 
			condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess";
		};
		class H_PASGT_basic_olive_F : H_PASGT_basic_black_F { 
			displayName = "Olive"; 
			condition = "true";
		};
		class H_PASGT_basic_blue_press_F : H_PASGT_basic_black_F { displayName = "Press"; };
		class H_PASGT_neckprot_blue_press_F : H_PASGT_basic_black_F { 
			displayName = "Press (Neck Protection)"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
	};
};
class H_PASGT_basic_blue_F : H_PASGT_basic_black_F {};
class H_PASGT_basic_white_F : H_PASGT_basic_black_F {};
class H_PASGT_basic_olive_F : H_PASGT_basic_black_F {};
class H_PASGT_basic_blue_press_F : H_PASGT_basic_black_F {};
class H_PASGT_neckprot_blue_press_F : H_PASGT_basic_black_F {};

class H_PilotHelmetHeli_B : H_HeadBandage_clean_F {
	displayName = "Flight Helmet";
	price = 35000;
	reputation = true;
	isMask = true;
	class Textures {
		class H_PilotHelmetHeli_B {
			displayName = "Pilot (Black)";
			condition = "true";
		};
		class H_PilotHelmetHeli_O : H_PilotHelmetHeli_B { displayName = "Pilot (Olive)"; };
		class H_PilotHelmetHeli_I : H_PilotHelmetHeli_B { displayName = "Pilot (Digi)"; };
		class H_CrewHelmetHeli_B : H_PilotHelmetHeli_B { 
			displayName = "Crew (Black)";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }  || { [player, [""Medic""]] call ULP_fnc_isFaction }";
		};
		class H_CrewHelmetHeli_O : H_CrewHelmetHeli_B { displayName = "Crew Olive)"; };
		class H_CrewHelmetHeli_I : H_CrewHelmetHeli_B { displayName = "Crew (Digi)"; };
	};
};
class H_PilotHelmetHeli_O : H_PilotHelmetHeli_B {};
class H_PilotHelmetHeli_I : H_PilotHelmetHeli_B {};
class H_CrewHelmetHeli_B : H_PilotHelmetHeli_B {};
class H_CrewHelmetHeli_O : H_PilotHelmetHeli_B {};
class H_CrewHelmetHeli_I : H_PilotHelmetHeli_B {};

class H_HelmetIA : H_HeadBandage_clean_F {
	displayName = "IA Combat Helmet";
	price = 25000;
	reputation = true;
	class Textures {};
};

class H_HelmetB_light : H_HelmetIA {
	displayName = "Light Combat Helment";
	price = 25000;
	reputation = true;
	class Textures {
		class H_HelmetB_light {
			displayName = "Green";
			condition = "true";
		};
		class H_HelmetB_light_black : H_HelmetB_light { 
			displayName = "Black"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class H_HelmetB_light_desert : H_HelmetB_light { displayName = "Desert"; };
		class H_HelmetB_light_sand : H_HelmetB_light { displayName = "Sand"; };
		class H_HelmetB_light_snakeskin : H_HelmetB_light { displayName = "Snakeskin"; };
		class H_HelmetB_light_grass : H_HelmetB_light { displayName = "Grass"; };
		class H_HelmetB_light_wdl : H_HelmetB_light { displayName = "Woodland"; };
	};
};
class H_HelmetB_light_black : H_HelmetB_light {};
class H_HelmetB_light_desert : H_HelmetB_light {};
class H_HelmetB_light_sand : H_HelmetB_light {};
class H_HelmetB_light_snakeskin : H_HelmetB_light{ };
class H_HelmetB_light_grass : H_HelmetB_light {};
class H_HelmetB_light_wdl : H_HelmetB_light {};

class H_HelmetB : H_HelmetB_light {
	displayName = "Combat Helment";
	price = 40000;
	class Textures {
		class H_HelmetB {
			displayName = "Green";
			condition = "true";
		};
		class H_HelmetB_plain_blk : H_HelmetB { 
			displayName = "Black"; 
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class H_HelmetB_desert : H_HelmetB { displayName = "Desert"; };
		class H_HelmetB_sand : H_HelmetB { displayName = "Sand"; };
		class H_HelmetB_snakeskin : H_HelmetB { displayName = "Snakeskin"; };
		class H_HelmetB_grass : H_HelmetB { displayName = "Grass"; };
		class H_HelmetB_camo : H_HelmetB { displayName = "Camo"; };
		class H_HelmetB_paint : H_HelmetB { displayName = "Spraypaint"; };
		class H_HelmetB_plain_wdl : H_HelmetB { displayName = "Woodland"; };
	};
};
class H_HelmetB_plain_blk : H_HelmetB {};
class H_HelmetB_desert : H_HelmetB {};
class H_HelmetB_sand : H_HelmetB {};
class H_HelmetB_snakeskin : H_HelmetB {};
class H_HelmetB_grass : H_HelmetB {};
class H_HelmetB_camo : H_HelmetB {};
class H_HelmetB_paint : H_HelmetB {};
class H_HelmetB_plain_wdl : H_HelmetB {};

class H_HelmetSpecB : H_HelmetB_light {
	displayName = "Enhanced Combat Helment";
	price = 75000;
	class Textures {
		class H_HelmetSpecB {
			displayName = "Green";
			condition = "true";
		};
		class H_HelmetSpecB_blk : H_HelmetSpecB { 
			displayName = "Black"; 
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class H_HelmetSpecB_paint2 : H_HelmetSpecB { displayName = "Desert"; };
		class H_HelmetSpecB_sand : H_HelmetSpecB { displayName = "Sand"; };
		class H_HelmetSpecB_snakeskin : H_HelmetSpecB { displayName = "Snakeskin"; };
		class H_HelmetSpecB_paint1 : H_HelmetSpecB { displayName = "Grass"; };
		class H_HelmetSpecB_wdl : H_HelmetSpecB { displayName = "Woodland"; };
	};
};
class H_HelmetSpecB_blk : H_HelmetSpecB {};
class H_HelmetSpecB_paint2 : H_HelmetSpecB {};
class H_HelmetSpecB_sand : H_HelmetSpecB {};
class H_HelmetSpecB_snakeskin : H_HelmetSpecB {};
class H_HelmetSpecB_paint1 : H_HelmetSpecB {};
class H_HelmetSpecB_wdl : H_HelmetSpecB {};

class H_HelmetB_TI_arid_F : H_HelmetB_light {
	displayName = "Stealth Combat Helment";
	price = 90000;
	isMask = true;
	class Textures {
		class H_HelmetB_TI_arid_F {
			displayName = "Arid";
			condition = "true";
		};
		class H_HelmetB_TI_tna_F : H_HelmetB_TI_arid_F { displayName = "Green"; };
	};
};
class H_HelmetB_TI_tna_F : H_HelmetB_TI_arid_F {};

class H_HelmetHBK_F : H_HelmetB_light {
	displayName = "Advanced Modular Helmet";
	price = 40000;
	class Textures {
		class H_HelmetHBK_F {
			displayName = "Olive";
			condition = "true";
		};
		class H_HelmetHBK_headset_F : H_HelmetHBK_F { displayName = "Headset"; };
		class H_HelmetHBK_ear_F : H_HelmetHBK_F { 
			displayName = "Ear Protectors"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class H_HelmetHBK_chops_F : H_HelmetHBK_ear_F { displayName = "Chops"; };
	};
};
class H_HelmetHBK_headset_F : H_HelmetHBK_F {};
class H_HelmetHBK_ear_F : H_HelmetHBK_F {};
class H_HelmetHBK_chops_F : H_HelmetHBK_F {};

class H_HelmetAggressor_F : H_HelmetB_light {
	displayName = "Avenger Helmet";
	price = 70000;
	class Textures {
		class H_HelmetAggressor_F {
			displayName = "Olive";
			condition = "true";
		};
		class H_HelmetAggressor_cover_F : H_HelmetAggressor_F { displayName = "Covered"; };
		class H_HelmetAggressor_cover_taiga_F : H_HelmetAggressor_F { 
			displayName = "Taiga"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
	};
};
class H_HelmetAggressor_cover_F : H_HelmetAggressor_F {};
class H_HelmetAggressor_cover_taiga_F : H_HelmetAggressor_F {};
