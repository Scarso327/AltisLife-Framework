class V_LegStrapBag_black_F {
	displayName = "Leg Strap";
	price = 800;
	virtualSpace = 12;
	reputation = false;
	class Textures {
		class V_LegStrapBag_black_F {
			displayName = "Black";
			condition = "true";
		};
		class V_LegStrapBag_coyote_F : V_LegStrapBag_black_F { displayName = "Coyote"; };
		class V_LegStrapBag_olive_F : V_LegStrapBag_black_F { displayName = "Olive"; };
	};
};
class V_LegStrapBag_coyote_F : V_LegStrapBag_black_F {};
class V_LegStrapBag_olive_F : V_LegStrapBag_black_F {};

class V_Plain_medical_F : V_LegStrapBag_black_F {
	displayName = "Identification Vest";
	price = 50;
	virtualSpace = 0;
	class Textures {
		class V_Plain_medical_F {
			displayName = "IDAP";
			condition = "true";
		};
		class V_Plain_crystall_F : V_Plain_medical_F { displayName = "Crystal"; };
	};
};
class V_Plain_crystall_F : V_Plain_medical_F {};

class V_Pocketed_black_F : V_LegStrapBag_black_F {
	displayName = "Pocketed Vest";
	price = 1000;
	virtualSpace = 14;
	reputation = false;
	class Textures {
		class V_Pocketed_black_F {
			displayName = "Black";
			condition = "true";
		};
		class V_Pocketed_coyote_F : V_Pocketed_black_F { displayName = "Coyote"; };
		class V_Pocketed_olive_F : V_Pocketed_black_F { displayName = "Olive"; };
	};
};
class V_Pocketed_coyote_F : V_Pocketed_black_F {};
class V_Pocketed_olive_F : V_Pocketed_black_F {};

class V_Safety_yellow_F : V_LegStrapBag_black_F {
	displayName = "Safety Vest";
	price = 250;
	virtualSpace = 3;
	class Textures {
		class V_Safety_yellow_F {
			displayName = "Yellow";
			condition = "true";
		};
		class V_Safety_orange_F : V_Safety_yellow_F { displayName = "Orange"; };
		class V_Safety_blue_F : V_Safety_orange_F { displayName = "Blue"; };
	};
};
class V_Safety_orange_F : V_Safety_yellow_F {};
class V_Safety_blue_F : V_Safety_yellow_F {};

class V_Press_F : V_LegStrapBag_black_F {
	price = 10000;
	virtualSpace = 11;
	class Textures {};
};

class V_RebreatherB : V_LegStrapBag_black_F {
	displayName = "Rebreather";
	price = 15000;
	virtualSpace = 5;
	class Textures {
		class V_RebreatherB {
			displayName = "Black";
			condition = "true";
		};
		class V_RebreatherIR : V_RebreatherB { displayName = "Brown"; };
		class V_RebreatherIA : V_RebreatherB { displayName = "Green"; };
	};
};
class V_RebreatherIR : V_RebreatherB {};
class V_RebreatherIA : V_RebreatherB {};

class V_Rangemaster_belt : V_LegStrapBag_black_F {
	displayName = "Ammo Belt";
	price = 2000;
	virtualSpace = 6;
	class Textures {};
};

class V_BandollierB_blk : V_LegStrapBag_black_F {
	displayName = "Bandollier";
	price = 2500;
	virtualSpace = 10;
	class Textures {
		class V_BandollierB_blk {
			displayName = "Black";
			condition = "true";
		};
		class V_BandollierB_cbr : V_BandollierB_blk { displayName = "Coyote"; };
		class V_BandollierB_khk : V_BandollierB_blk { displayName = "Khaki"; };
		class V_BandollierB_oli : V_BandollierB_blk { displayName = "Olive"; };
		class V_BandollierB_rgr : V_BandollierB_blk { displayName = "Green"; };
	};
};
class V_BandollierB_cbr : V_BandollierB_blk {};
class V_BandollierB_khk : V_BandollierB_blk {};
class V_BandollierB_oli : V_BandollierB_blk {};
class V_BandollierB_rgr : V_BandollierB_blk {};

class V_HarnessO_brn : V_LegStrapBag_black_F {
	displayName = "Combat Harness";
	price = 3000;
	virtualSpace = 14;
	class Textures {
		class V_HarnessO_brn {
			displayName = "Brown";
			condition = "true";
		};
		class V_HarnessO_gry : V_HarnessO_brn { displayName = "Gray"; };
		class V_HarnessO_ghex_F : V_HarnessO_brn { displayName = "Green Hex"; };
		class V_HarnessOGL_brn : V_HarnessO_brn { 
			displayName = "Brown (GL)";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class V_HarnessOGL_gry : V_HarnessO_brn { displayName = "Gray (GL)"; };
		class V_HarnessOGL_ghex_F : V_HarnessO_brn { displayName = "Green Hex (GL)"; };
	};
};
class V_HarnessO_gry : V_HarnessO_brn {};
class V_HarnessO_ghex_F : V_HarnessO_brn {};
class V_HarnessOGL_brn : V_HarnessO_brn {};
class V_HarnessOGL_gry : V_HarnessO_brn {};
class V_HarnessOGL_ghex_F : V_HarnessO_brn {};

class V_TacVestIR_blk : V_LegStrapBag_black_F {
	displayName = "Raven Vest";
	price = 5000;
	virtualSpace = 15;
	class Textures {};
};

class V_Chestrig_blk : V_LegStrapBag_black_F {
	displayName = "Chest Rig";
	price = 8000;
	virtualSpace = 16;
	class Textures {
		class V_Chestrig_blk {
			displayName = "Black";
			condition = "true";
		};
		class V_Chestrig_khk : V_Chestrig_blk { displayName = "Khaki"; };
		class V_Chestrig_oli : V_Chestrig_blk { displayName = "Olive"; };
		class V_Chestrig_rgr : V_Chestrig_blk { displayName = "Green"; };
	};
};
class V_Chestrig_khk : V_Chestrig_blk {};
class V_Chestrig_oli : V_Chestrig_blk {};
class V_Chestrig_rgr : V_Chestrig_blk {};

class V_TacChestrig_cbr_F : V_LegStrapBag_black_F {
	displayName = "Tactical Rig";
	price = 8500;
	virtualSpace = 18;
	class Textures {
		class V_TacChestrig_cbr_F {
			displayName = "Coyote";
			condition = "true";
		};
		class V_TacChestrig_oli_F : V_TacChestrig_cbr_F { displayName = "Olive"; };
		class V_TacChestrig_grn_F : V_TacChestrig_cbr_F { displayName = "Green"; };
	};
};
class V_TacChestrig_oli_F : V_TacChestrig_cbr_F {};
class V_TacChestrig_grn_F : V_TacChestrig_cbr_F {};

class V_SmershVest_01_F : V_LegStrapBag_black_F {
	displayName = "Kipchak Vest";
	price = 9000;
	virtualSpace = 15;
	reputation = true;
	class Textures {
		class V_SmershVest_01_F {
			displayName = "Default";
			condition = "true";
		};
		class V_SmershVest_01_radio_F : V_SmershVest_01_F { 
			displayName = "Default w/radio"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
	};
};
class V_SmershVest_01_radio_F : V_SmershVest_01_F {};

class V_DeckCrew_white_F : V_SmershVest_01_F {
	displayName = "Deck Crew Vest";
	price = 17500;
	virtualSpace = 10;
	class Textures {
		class V_DeckCrew_white_F {
			displayName = "White";
			condition = "true";
		};
		class V_DeckCrew_blue_F : V_DeckCrew_white_F { 
			displayName = "Blue"; 
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
		class V_DeckCrew_red_F : V_DeckCrew_blue_F { displayName = "Red"; };
		class V_DeckCrew_green_F : V_DeckCrew_blue_F { displayName = "Green"; };
		class V_DeckCrew_yellow_F : V_DeckCrew_blue_F { displayName = "Yellow"; };
		class V_DeckCrew_violet_F : V_DeckCrew_blue_F { displayName = "Violet"; };
		class V_DeckCrew_brown_F : V_DeckCrew_blue_F { displayName = "Brown"; };
	};
};
class V_DeckCrew_blue_F : V_DeckCrew_white_F {};
class V_DeckCrew_red_F : V_DeckCrew_white_F {};
class V_DeckCrew_green_F : V_DeckCrew_white_F {};
class V_DeckCrew_yellow_F : V_DeckCrew_white_F {};
class V_DeckCrew_violet_F : V_DeckCrew_white_F {};
class V_DeckCrew_brown_F : V_DeckCrew_white_F {};

class V_TacVest_blk : V_SmershVest_01_F {
	displayName = "Tactical Vest";
	price = 15000;
	virtualSpace = 20;
	class Textures {
		class V_TacVest_blk {
			displayName = "Black";
			condition = "true";
		};
		class V_TacVest_brn : V_TacVest_blk { displayName = "Brown"; };
		class V_TacVest_khk : V_TacVest_blk { displayName = "Khaki"; };
		class V_TacVest_oli : V_TacVest_blk { displayName = "Olive"; };
		class V_TacVest_camo : V_TacVest_blk { 
			displayName = "Camo"; 
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
		class V_TacVest_blk_POLICE : V_TacVest_blk { 
			displayName = "Police"; 
			condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		};
	};
};
class V_TacVest_blk_POLICE : V_TacVest_blk {};
class V_TacVest_camo : V_TacVest_blk {};
class V_TacVest_brn : V_TacVest_blk {};
class V_TacVest_khk : V_TacVest_blk {};
class V_TacVest_oli : V_TacVest_blk {};

class V_PlateCarrierIA1_dgtl : V_SmershVest_01_F {
	displayName = "GA Plate Carrier";
	price = 20000;
	virtualSpace = 13;
	class Textures {
		class V_PlateCarrierIA1_dgtl {
			displayName = "Light";
			condition = "true";
		};
		class V_PlateCarrierIA2_dgtl : V_PlateCarrierIA1_dgtl { displayName = "Heavy"; };
	};
};
class V_PlateCarrierIA2_dgtl : V_PlateCarrierIA1_dgtl {};

class V_CarrierRigKBT_01_Olive_F : V_SmershVest_01_F {
	displayName = "Modular Carrier Vest";
	price = 18500;
	virtualSpace = 15;
	class Textures {
		class V_CarrierRigKBT_01_Olive_F {
			displayName = "Olive";
			condition = "true";
		};
		class V_CarrierRigKBT_01_EAF_F : V_CarrierRigKBT_01_Olive_F { displayName = "Geometric"; };
	};
};
class V_CarrierRigKBT_01_EAF_F : V_CarrierRigKBT_01_Olive_F {};

class V_CarrierRigKBT_01_light_Olive_F : V_SmershVest_01_F {
	displayName = "Modular Carrier Rig";
	price = 25000;
	virtualSpace = 17;
	class Textures {
		class V_CarrierRigKBT_01_light_Olive_F {
			displayName = "Olive";
			condition = "true";
		};
		class V_CarrierRigKBT_01_light_EAF_F : V_CarrierRigKBT_01_light_Olive_F { displayName = "Geometric"; };
	};
};
class V_CarrierRigKBT_01_light_EAF_F : V_CarrierRigKBT_01_light_Olive_F {};

class V_PlateCarrier1_blk : V_SmershVest_01_F {
	displayName = "Carrier Lite";
	price = 45000;
	virtualSpace = 23;
	class Textures {
		class V_PlateCarrier1_blk {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction } || { [] call ULP_fnc_isProtection } || { [] call ULP_fnc_isSecurity }";
		};
		class V_PlateCarrier1_rgr : V_PlateCarrier1_blk { 
			displayName = "Green"; 
			condition = "true";
		};
		class V_PlateCarrier1_rgr_noflag_F : V_PlateCarrier1_rgr { displayName = "Green (No Flag)"; };
		class V_PlateCarrier1_wdl : V_PlateCarrier1_rgr { displayName = "Woodland"; };
		class V_PlateCarrier1_tna_F : V_PlateCarrier1_rgr { displayName = "Tropic"; };
		class V_PlateCarrierL_CTRG : V_PlateCarrier1_rgr { 
			displayName = "CTRG";
			condition = "[] call ULP_fnc_donatorLevel > 0";   
		};
	};
};
class V_PlateCarrier1_rgr : V_PlateCarrier1_blk {};
class V_PlateCarrier1_rgr_noflag_F : V_PlateCarrier1_blk {};
class V_PlateCarrier1_wdl : V_PlateCarrier1_blk {};
class V_PlateCarrier1_tna_F : V_PlateCarrier1_blk {};
class V_PlateCarrierL_CTRG : V_PlateCarrier1_blk {};

class V_PlateCarrier2_blk : V_SmershVest_01_F {
	displayName = "Carrier Rig";
	price = 105000;
	virtualSpace = 25;
	class Textures {
		class V_PlateCarrier2_blk {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class V_PlateCarrier2_rgr : V_PlateCarrier2_blk { 
			displayName = "Green"; 
			condition = "true";
		};
		class V_PlateCarrier2_rgr_noflag_F : V_PlateCarrier2_rgr { displayName = "Green (No Flag)"; };
		class V_PlateCarrier2_wdl : V_PlateCarrier2_rgr { displayName = "Woodland"; };
		class V_PlateCarrier2_tna_F : V_PlateCarrier2_rgr { displayName = "Tropic"; };
		class V_PlateCarrierH_CTRG : V_PlateCarrier2_rgr { 
			displayName = "CTRG";
			condition = "[] call ULP_fnc_donatorLevel > 0";   
		};
	};
};
class V_PlateCarrier2_rgr : V_PlateCarrier2_blk {};
class V_PlateCarrier2_rgr_noflag_F : V_PlateCarrier2_blk {};
class V_PlateCarrier2_wdl : V_PlateCarrier2_blk {};
class V_PlateCarrier2_tna_F : V_PlateCarrier2_blk {};
class V_PlateCarrierH_CTRG : V_PlateCarrier2_blk {};
