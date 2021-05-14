class H_HeadBandage_clean_F {
	displayName = "Bandage";
	price = 2;
	reputation = false;
	isMask = false;
	isNV = false;
	class Textures {};
};
class H_HeadBandage_stained_F : H_HeadBandage_clean_F {};
class H_HeadBandage_bloody_F : H_HeadBandage_clean_F {};

class H_WirelessEarpiece_F {
	price = 14;
	reputation = false;
	isMask = false;
	isNV = false;
	class Textures {};
};

class H_Bandanna_gry {
	displayName = "Bandanna";
	price = 10;
	reputation = false;
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

class H_Cap_blk {
	displayName = "Cap";
	price = 30;
	reputation = false;
	isMask = false;
	isNV = false;
	class Textures {
		class H_Cap_blk {
			displayName = "Black";
			condition = "true";
		};
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
		class H_Cap_red : H_Cap_blk { displayName = "Red"; };
		class H_Cap_blu : H_Cap_blk { displayName = "Blue"; };
		class H_Cap_tan : H_Cap_blk { displayName = "Tan"; };
		class H_Cap_oli : H_Cap_blk { displayName = "Olive"; };
		class H_Cap_surfer : H_Cap_usblack { displayName = "Surfer"; };
		class H_Cap_police {
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
class H_Cap_surfer : H_Cap_blk {};
class H_Cap_headphones : H_Cap_blk {};
class H_Cap_Black_IDAP_F : H_Cap_blk {};
class H_Cap_White_IDAP_F : H_Cap_blk {};
class H_Cap_Orange_IDAP_F : H_Cap_blk {};

class H_MilCap_gry {
	displayName = "Military Cap";
	price = 45;
	reputation = false;
	isMask = false;
	isNV = false;
	class Textures {};
};
class H_MilCap_blue : H_MilCap_gry {};
class H_MilCap_grn : H_MilCap_gry {};
class H_MilCap_wdl : H_MilCap_gry {};

class H_Hat_grey {
	displayName = "Hat";
	price = 60;
	reputation = false;
	class Textures {
		class H_Hat_grey {
			displayName = "Grey";
			condition = "true";
		};
		class H_Hat_blue : H_Hat_grey { displayName = "Blue"; };
		class H_Hat_brown : H_Hat_grey { displayName = "Brown"; };
		class H_Hat_tan : H_Hat_grey { displayName = "Tan"; };
		class H_Hat_checker : H_Hat_grey { displayName = "Checker"; };
		class H_Hat_camo : H_Hat_grey { displayName = "Camo"; };
		class H_StrawHat : H_Hat_grey { displayName = "Straw (Light)"; };
		class H_StrawHat_dark : H_Hat_grey { displayName = "Straw (Dark)"; };
	};
};
class H_Hat_blue : H_Hat_grey {};
class H_Hat_brown : H_Hat_grey {};
class H_Hat_tan : H_Hat_grey {};
class H_Hat_checker : H_Hat_grey {};
class H_Hat_camo : H_Hat_grey {};
class H_StrawHat : H_Hat_grey {};
class H_StrawHat_dark : H_Hat_grey {};

class H_Hat_Safari_sand_F : H_Hat_grey {
	displayName = "Safari Hat";
	price = 65;
	class Textures {
		class H_Hat_Safari_sand_F {
			displayName = "Sand";
			condition = "true";
		};
		class H_Hat_Safari_olive_F : H_Hat_Safari_sand_F { displayName = "Olive"; };
	};
};
class H_Hat_Safari_olive_F : H_Hat_Safari_sand_F {};

class H_Watchcap_blk {
	displayName = "Beanie";
	price = 80;
	reputation = false;
	isMask = false;
	isNV = false;
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

class H_Booniehat_khk {
	displayName = "Bonniehat";
	price = 95;
	reputation = false;
	class Textures {
		class H_Booniehat_khk {
			displayName = "Khaki";
			condition = "true";
		};
		class H_Booniehat_grn : H_Booniehat_khk { displayName = "Green"; };
		class H_Booniehat_oli : H_Booniehat_khk { displayName = "Olive"; };
		class H_Booniehat_tan : H_Booniehat_khk { displayName = "Tan"; };
		class H_Booniehat_mcamo : H_Booniehat_khk { displayName = "MTP"; };
		class H_Booniehat_dgtl : H_Booniehat_khk { displayName = "Digital"; };
		class H_Booniehat_wdl : H_Booniehat_khk { displayName = "Woodland"; };
	};
};
class H_Booniehat_khk_hs : H_Booniehat_khk {};
class H_Booniehat_grn : H_Booniehat_khk {};
class H_Booniehat_oli : H_Booniehat_khk {};
class H_Booniehat_tan : H_Booniehat_khk {};
class H_Booniehat_mcamo : H_Booniehat_khk {};
class H_Booniehat_dgtl : H_Booniehat_khk {};
class H_Booniehat_wdl : H_Booniehat_khk {};

class H_Beret_blk {
	displayName = "Beret";
	price = 2800;
	reputation = false;
	isMask = false;
	isNV = false;
	class Textures {
		// Altis Police Service
		class H_Beret_blk {
			displayName = "Police Patrol";
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
		};
		class H_Beret_gen_F : H_Beret_blk {
			displayName = "Police Command";
			price = 18900;
			condition = "[""Police_Main"", 9] call ULP_fnc_hasAccess || { [""Police_COL"", 3] call ULP_fnc_hasAccess }";
		};
		class H_Beret_EAF_01_F : H_Beret_blk {
			displayName = "Spec. Command";
			price = 17450;
			condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess || { [""Police_NCA"", 3] call ULP_fnc_hasAccess }";
		};

		// Altis Ambulance Service
		class H_Beret_02 : H_Beret_blk {
			displayName = "Directors' of Ambulance Services";
			price = 19310;
			condition = "[""Medic_Main"", 7] call ULP_fnc_hasAccess";
		};
		class H_Beret_Colonel : H_Beret_blk {
			displayName = "Department Head";
			price = 15100;
			condition = "[""Medic_Main"", 6] call ULP_fnc_hasAccess";
		};
		class H_Beret_CSAT_01_F : H_Beret_blk {
			displayName = "HART Beret";
			price = 14850;
			condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess";
		};
	};
};
class H_Beret_gen_F : H_Beret_blk {};
class H_Beret_EAF_01_F : H_Beret_blk {};
class H_Beret_02 : H_Beret_blk {};
class H_Beret_Colonel : H_Beret_blk {};
class H_Beret_CSAT_01_F : H_Beret_blk {};

class H_ShemagOpen_khk {
	displayName = "Shemag";
	price = 700;
	reputation = false;
	isMask = true;
	isNV = false;
	class Textures {};
};
class H_Shemag_tan : H_ShemagOpen_khk {};
class H_Shemag_olive : H_ShemagOpen_khk {};

class H_EarProtectors_black_F {
	displayName = "Ear Protectors";
	price = 240;
	reputation = false;
	isMask = false;
	isNV = false;
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

class H_Construction_basic_black_F {
	displayName = "Hard Hat";
	price = 850;
	reputation = false;
	isMask = false;
	isNV = false;
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

class H_Helmet_Skate {
	price = 1900;
	reputation = false;
	isMask = false;
	isNV = false;
	class Textures {};
};

class H_RacingHelmet_1_black_F {
	displayName = "Racing Helmet";
	price = 4500;
	reputation = false;
	isMask = true;
	isNV = false;
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

class H_PASGT_basic_blue_press_F {
	displayName = "Press Helmet";
	price = 19500;
	reputation = false;
	isMask = false;
	isNV = false;
	class Textures {
		class H_PASGT_basic_blue_press_F {
			displayName = "Basic";
			condition = "true";
		};
		class H_PASGT_neckprot_blue_press_F : H_PASGT_basic_blue_press_F { displayName = "Neck Protection"; };
	};
};
class H_PASGT_neckprot_blue_press_F : H_PASGT_basic_blue_press_F {};
class H_PASGT_basic_black_F : H_PASGT_basic_blue_press_F {};
class H_PASGT_basic_white_F : H_PASGT_basic_blue_press_F {};
class H_PASGT_basic_blue_F : H_PASGT_basic_blue_press_F {};
class H_PASGT_basic_olive_F : H_PASGT_basic_blue_press_F {};

class H_PilotHelmetHeli_B {
	displayName = "Flight Helmet";
	price = 39400;
	reputation = false;
	isMask = true;
	isNV = true;
	class Textures {
		class H_PilotHelmetHeli_B {
			displayName = "Pilot";
			condition = "true";
		};
		class H_CrewHelmetHeli_B : H_PilotHelmetHeli_B { displayName = "Crew"; };
	};
};
class H_CrewHelmetHeli_B : H_PilotHelmetHeli_B {};

class H_HelmetB_light {
	displayName = "Light Combat Helment";
	price = 27800;
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

class H_HelmetB {
	displayName = "Combat Helment";
	price = 37600;
	reputation = true;
	isMask = false;
	isNV = false;
	class Textures {
		class H_HelmetB {
			displayName = "Green";
			condition = "true";
		};
		class H_HelmetB_plain_blk : H_HelmetB { 
			displayName = "Black"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
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

class H_HelmetSpecB {
	displayName = "Enhanced Combat Helment";
	price = 78500;
	reputation = true;
	isMask = false;
	isNV = false;
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

class H_HelmetB_TI_arid_F {
	displayName = "Stealth Combat Helment";
	price = 55000;
	reputation = true;
	isMask = true;
	isNV = false;
	class Textures {};
};
