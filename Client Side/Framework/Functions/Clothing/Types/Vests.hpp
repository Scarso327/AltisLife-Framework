class V_LegStrapBag_black_F {
	displayName = "Leg Strap";
	price = 1120;
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

class V_Plain_medical_F {
	displayName = "Identification Vest";
	price = 65;
	virtualSpace = 0;
	reputation = false;
	class Textures {};
};

class V_Pocketed_black_F {
	displayName = "Pocketed Vest";
	price = 1300;
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

class V_Safety_yellow_F {
	displayName = "Safety Vest";
	price = 1350;
	virtualSpace = 3;
	reputation = false;
	class Textures {
		class V_Safety_yellow_F {
			displayName = "Yellow";
			condition = "true";
		};
		class V_Safety_orange_F : V_Safety_yellow_F { 
			displayName = "Orange";
			condition = "[player, [""Civilian""]] call ULP_fnc_isFaction && { [] call ULP_fnc_donatorLevel > 0 } || { [player, [""Medic""]] call ULP_fnc_isFaction && [""Medic_HR"", 1] ULP_fnc_hasAccess }"; 
		};
		class V_Safety_blue_F : V_Safety_orange_F { displayName = "Blue"; };
	};
};
class V_Safety_orange_F : V_Safety_yellow_F {};
class V_Safety_blue_F : V_Safety_yellow_F {};

class V_RebreatherB {
	displayName = "Rebreather";
	price = 17800;
	virtualSpace = 5;
	reputation = false;
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

class V_Rangemaster_belt {
	displayName = "Ammo Belt";
	price = 6890;
	virtualSpace = 6;
	reputation = true;
	class Textures {};
};

class V_BandollierB_blk {
	displayName = "Bandollier";
	price = 8700;
	virtualSpace = 10;
	reputation = false;
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

class V_HarnessO_brn {
	displayName = "Combat Harness";
	price = 10550;
	virtualSpace = 14;
	reputation = true;
	class Textures {
		class V_HarnessO_brn {
			displayName = "Brown";
			condition = "true";
		};
		class V_HarnessO_gry : V_HarnessO_brn { displayName = "Gray"; };
		class V_HarnessOGL_brn : V_HarnessO_brn { displayName = "Brown (GL)"; };
		class V_HarnessOGL_gry : V_HarnessO_brn { displayName = "Gray (GL)"; };
	};
};
class V_HarnessO_gry : V_HarnessO_brn {};
class V_HarnessOGL_brn : V_HarnessO_brn {};
class V_HarnessOGL_gry : V_HarnessO_brn {};

class V_TacVestIR_blk {
	price = 11250;
	virtualSpace = 15;
	reputation = true;
	class Textures {};
};

class V_Chestrig_blk {
	displayName = "Chest Rig";
	price = 12300;
	virtualSpace = 16;
	reputation = true;
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

class V_TacChestrig_cbr_F {
	displayName = "Tactical Rig";
	price = 13500;
	virtualSpace = 18;
	reputation = true;
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

class V_Press_F {
	price = 15000;
	virtualSpace = 11;
	reputation = false;
	class Textures {};
};

class V_CarrierRigKBT_01_Olive_F {
	displayName = "Modular Carrier Vest";
	price = 38700;
	virtualSpace = 15;
	reputation = true;
	class Textures {
		class V_CarrierRigKBT_01_Olive_F {
			displayName = "Olive";
			condition = "true";
		};
		class V_CarrierRigKBT_01_EAF_F : V_CarrierRigKBT_01_Olive_F { displayName = "Geometric"; };
	};
};
class V_CarrierRigKBT_01_EAF_F : V_CarrierRigKBT_01_Olive_F {};

class V_TacVest_blk {
	displayName = "Tactical Vest";
	price = 48500;
	virtualSpace = 20;
	reputation = true;
	class Textures {
		class V_TacVest_blk {
			displayName = "Black";
			condition = "true";
		};
		class V_TacVest_blk_POLICE : V_TacVest_blk { displayName = "Police"; };
		class V_TacVest_camo : V_TacVest_blk { 
			displayName = "Camo"; 
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
		class V_TacVest_brn : V_TacVest_blk { displayName = "Brown"; };
		class V_TacVest_khk : V_TacVest_blk { displayName = "Khaki"; };
		class V_TacVest_oli : V_TacVest_blk { displayName = "Olive"; };
	};
};
class V_TacVest_blk_POLICE : V_TacVest_blk {};
class V_TacVest_camo : V_TacVest_blk {};
class V_TacVest_brn : V_TacVest_blk {};
class V_TacVest_khk : V_TacVest_blk {};
class V_TacVest_oli : V_TacVest_blk {};

class V_PlateCarrier1_blk {
	displayName = "Carrier Lite";
	price = 74000;
	virtualSpace = 23;
	reputation = true;
	class Textures {
		class V_PlateCarrier1_blk {
			displayName = "Black";
			condition = "true";
		};
		class V_PlateCarrier1_rgr : V_PlateCarrier1_blk { displayName = "Green"; };
		class V_PlateCarrier1_rgr_noflag_F : V_PlateCarrier1_blk { displayName = "Green (No Flag)"; };
		class V_PlateCarrier1_wdl : V_PlateCarrier1_blk { displayName = "Woodland"; };
		class V_PlateCarrierL_CTRG : V_PlateCarrier1_blk { 
			displayName = "CTRG";
			condition = "[] call ULP_fnc_donatorLevel > 0";   
		};
	};
};
class V_PlateCarrier1_rgr : V_PlateCarrier1_blk {};
class V_PlateCarrier1_rgr_noflag_F : V_PlateCarrier1_blk {};
class V_PlateCarrier1_wdl : V_PlateCarrier1_blk {};
class V_PlateCarrierL_CTRG : V_PlateCarrier1_blk {};

class V_PlateCarrier2_blk {
	displayName = "Carrier Rig";
	price = 105000;
	virtualSpace = 25;
	reputation = true;
	class Textures {
		class V_PlateCarrier2_blk {
			displayName = "Black";
			condition = "true";
		};
		class V_PlateCarrier2_rgr : V_PlateCarrier2_blk { displayName = "Green"; };
		class V_PlateCarrier2_rgr_noflag_F : V_PlateCarrier2_blk { displayName = "Green (No Flag)"; };
		class V_PlateCarrier2_wdl : V_PlateCarrier2_blk { displayName = "Woodland"; };
		class V_PlateCarrierH_CTRG : V_PlateCarrier2_blk { 
			displayName = "CTRG";
			condition = "[] call ULP_fnc_donatorLevel > 0";   
		};
	};
};
class V_PlateCarrier2_rgr : V_PlateCarrier2_blk {};
class V_PlateCarrier2_rgr_noflag_F : V_PlateCarrier2_blk {};
class V_PlateCarrier2_wdl : V_PlateCarrier2_blk {};
class V_PlateCarrierH_CTRG : V_PlateCarrier2_blk {};
