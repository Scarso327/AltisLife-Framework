class B_LegStrapBag_black_F {
	displayName = "Leg Strap";
	price = 800;
	reputation = false;
	virtualSpace = 12;
	class Textures {
		class B_LegStrapBag_black_F {
			displayName = "Black";
			condition = "true";
		};
		class B_LegStrapBag_coyote_F : B_LegStrapBag_black_F { displayName = "Coyote"; };
		class B_LegStrapBag_olive_F : B_LegStrapBag_black_F { displayName = "Olive"; };
	};
};
class B_LegStrapBag_coyote_F : B_LegStrapBag_black_F {};
class B_LegStrapBag_olive_F : B_LegStrapBag_black_F {};

class B_Messenger_Black_F : B_LegStrapBag_black_F {
	displayName = "Messenger Bag";
	price = 1000;
	virtualSpace = 15;
	class Textures {
		class B_Messenger_Black_F {
			displayName = "Black";
			condition = "true";
		};
		class B_Messenger_Gray_F : B_Messenger_Black_F { displayName = "Gray"; };
		class B_Messenger_Coyote_F : B_Messenger_Black_F { displayName = "Coyote"; };
		class B_Messenger_Olive_F : B_Messenger_Black_F { displayName = "Olive"; };
		class B_Messenger_IDAP_F : B_Messenger_Black_F { 
			displayName = "IDAP"; 
			condition = "[""IDAP""] call ULP_fnc_hasLicense";
		};
	};
};
class B_Messenger_Gray_F : B_Messenger_Black_F {};
class B_Messenger_Coyote_F : B_Messenger_Black_F {};
class B_Messenger_Olive_F : B_Messenger_Black_F {};
class B_Messenger_IDAP_F : B_Messenger_Black_F {};

class B_SCBA_01_F : B_LegStrapBag_black_F {
	displayName = "SCBA";
	price = 10000;
	virtualSpace = 0;
	class Textures {};
};

class B_CominationUnitRespirator_01_F : B_SCBA_01_F {
	displayName = "Combination Unit Respirator";
	price = 10000;
	class Textures {};
};

class B_AssaultPack_blk : B_LegStrapBag_black_F {
	displayName = "Assault Pack";
	price = 1300;
	virtualSpace = 19;
	class Textures {
		class B_AssaultPack_blk {
			displayName = "Black";
			condition = "true";
		};
		class B_AssaultPack_cbr : B_AssaultPack_blk { displayName = "Coyote"; };
		class B_AssaultPack_khk : B_AssaultPack_blk { displayName = "Coyote"; };
		class B_AssaultPack_rgr : B_AssaultPack_blk { displayName = "Green"; };
		class B_AssaultPack_sgg : B_AssaultPack_blk { displayName = "Sage"; };
		class B_AssaultPack_wdl_F : B_AssaultPack_blk { 
			displayName = "Woodland"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class B_AssaultPack_eaf_F : B_AssaultPack_wdl_F { displayName = "Geometric"; };
	};
};
class B_AssaultPack_cbr : B_AssaultPack_blk {};
class B_AssaultPack_khk : B_AssaultPack_blk {};
class B_AssaultPack_rgr : B_AssaultPack_blk {};
class B_AssaultPack_sgg : B_AssaultPack_blk {};
class B_AssaultPack_wdl_F : B_AssaultPack_blk {};
class B_AssaultPack_eaf_F : B_AssaultPack_blk {};

class B_FieldPack_blk : B_LegStrapBag_black_F {
	displayName = "Field Pack";
	price = 2000;
	virtualSpace = 22;
	class Textures {
		class B_FieldPack_blk {
			displayName = "Black";
			condition = "true";
		};
		class B_FieldPack_cbr : B_FieldPack_blk { displayName = "Coyote"; };
		class B_FieldPack_khk : B_FieldPack_blk { displayName = "Khaki"; };
		class B_FieldPack_oli : B_FieldPack_blk { displayName = "Olive"; };
		class B_FieldPack_green_F : B_FieldPack_blk { displayName = "Green"; };
	};
};
class B_FieldPack_cbr : B_FieldPack_blk {};
class B_FieldPack_khk : B_FieldPack_blk {};
class B_FieldPack_oli : B_FieldPack_blk {};
class B_FieldPack_green_F : B_FieldPack_blk {};

class B_Kitbag_cbr : B_LegStrapBag_black_F {
	displayName = "Kitbag";
	price = 3000;
	virtualSpace = 24;
	class Textures {
		class B_Kitbag_cbr {
			displayName = "Coyote";
			condition = "true";
		};
		class B_Kitbag_tan : B_Kitbag_cbr { displayName = "Tan"; };
		class B_Kitbag_rgr : B_Kitbag_cbr { displayName = "Green"; };
		class B_Kitbag_sgg : B_Kitbag_cbr { displayName = "Sage"; };
		class B_Kitbag_mcamo : B_Kitbag_cbr { 
			displayName = "MTP"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
	};
};
class B_Kitbag_tan : B_Kitbag_cbr {};
class B_Kitbag_rgr : B_Kitbag_cbr {};
class B_Kitbag_sgg : B_Kitbag_cbr {};
class B_Kitbag_mcamo : B_Kitbag_cbr {};

class B_TacticalPack_blk : B_LegStrapBag_black_F {
	displayName = "Tactical Pack";
	price = 3500;
	virtualSpace = 26;
	class Textures {
		class B_TacticalPack_blk {
			displayName = "Black";
			condition = "true";
		};
		class B_TacticalPack_oli : B_TacticalPack_blk { displayName = "Olive"; };
		class B_TacticalPack_rgr : B_TacticalPack_blk { displayName = "Green"; };
	};
};
class B_TacticalPack_oli : B_TacticalPack_blk {};
class B_TacticalPack_rgr : B_TacticalPack_blk {};

class B_CivilianBackpack_01_Everyday_Black_F : B_LegStrapBag_black_F {
	displayName = "Civilian Pack";
	price = 2000;
	virtualSpace = 25;
	class Textures {
		class B_CivilianBackpack_01_Everyday_Black_F {
			displayName = "Black";
			condition = "true";
		};
		class B_CivilianBackpack_01_Everyday_Astra_F : B_CivilianBackpack_01_Everyday_Black_F { 
			displayName = "Astra"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class B_CivilianBackpack_01_Everyday_Vrana_F : B_CivilianBackpack_01_Everyday_Astra_F { displayName = "Vrana"; };
	};
};
class B_CivilianBackpack_01_Everyday_Astra_F : B_CivilianBackpack_01_Everyday_Black_F {};
class B_CivilianBackpack_01_Everyday_Vrana_F : B_CivilianBackpack_01_Everyday_Black_F {};

class B_CivilianBackpack_01_Sport_Blue_F : B_CivilianBackpack_01_Everyday_Black_F {
	displayName = "Sports Pack";
	class Textures {
		class B_CivilianBackpack_01_Sport_Blue_F {
			displayName = "Blue";
			condition = "true";
		};
		class B_CivilianBackpack_01_Sport_Green_F : B_CivilianBackpack_01_Sport_Blue_F { displayName = "Green"; };
		class B_CivilianBackpack_01_Sport_Red_F : B_CivilianBackpack_01_Sport_Blue_F { displayName = "Red"; };
	};
};
class B_CivilianBackpack_01_Sport_Green_F : B_CivilianBackpack_01_Sport_Blue_F {};
class B_CivilianBackpack_01_Sport_Red_F : B_CivilianBackpack_01_Sport_Blue_F {};

class B_Carryall_cbr : B_LegStrapBag_black_F {
	displayName = "Carryall";
	price = 5000;
	virtualSpace = 30;
	class Textures {
		// Factions
		class INVIS {
			displayName = "Invisible";
			textures[] = { "" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction || [player, [""Medic""]] call ULP_fnc_isFaction || [player, [""Hato""]] call ULP_fnc_isFaction";
		};

		// Civilian
		class B_Carryall_cbr {
			displayName = "Coyote";
			condition = "true";
		};
		class B_Carryall_khk : B_Carryall_cbr { displayName = "khaki"; };
		class B_Carryall_oli : B_Carryall_cbr { displayName = "Olive"; };
		class B_Carryall_green_F : B_Carryall_cbr { displayName = "Green"; };
		class B_Carryall_wdl_F : B_Carryall_cbr { 
			displayName = "Woodland"; 
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
		class B_Carryall_eaf_F : B_Carryall_wdl_F { displayName = "Geometric"; };
		class B_Carryall_ghex_F : B_Carryall_wdl_F { displayName = "Green Hex"; };
		class B_Carryall_ocamo_F : B_Carryall_wdl_F { displayName = "Hex"; };
		class B_Carryall_mcamo_F : B_Carryall_wdl_F { displayName = "MTP"; };
		class B_Carryall_occamo_F : B_Carryall_wdl_F { displayName = "Urban"; };
		class B_Carryall_taiga_F : B_Carryall_wdl_F { displayName = "Taiga"; };
		class B_Carryall_blk : B_Carryall_wdl_F { 
			displayName = "Black"; 
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
	};
};
class B_Carryall_khk : B_Carryall_cbr {};
class B_Carryall_oli : B_Carryall_cbr {};
class B_Carryall_green_F : B_Carryall_cbr {};
class B_Carryall_wdl_F : B_Carryall_cbr {};
class B_Carryall_ghex_F : B_Carryall_cbr {};
class B_Carryall_ocamo_F : B_Carryall_cbr {};
class B_Carryall_mcamo_F : B_Carryall_cbr {};
class B_Carryall_occamo_F : B_Carryall_cbr {};
class B_Carryall_taiga_F : B_Carryall_cbr {};
class B_Carryall_blk : B_Carryall_cbr {};

class B_ViperLightHarness_blk_F : B_LegStrapBag_black_F {
	displayName = "Light Viper Harness";
	price = 3500;
	reputation = true;
	virtualSpace = 24;
	class Textures {
		class B_ViperLightHarness_blk_F {
			displayName = "Black";
			condition = "true";
		};
		class B_ViperLightHarness_khk_F : B_ViperLightHarness_blk_F { displayName = "Khaki"; };
		class B_ViperLightHarness_oli_F : B_ViperLightHarness_blk_F { displayName = "Olive"; };
	};
};
class B_ViperLightHarness_khk_F : B_ViperLightHarness_blk_F {};
class B_ViperLightHarness_oli_F : B_ViperLightHarness_blk_F {};

class B_ViperHarness_blk_F : B_ViperLightHarness_blk_F {
	displayName = "Viper Harness";
	price = 4000;
	virtualSpace = 27;
	class Textures {
		class B_ViperHarness_blk_F {
			displayName = "Black";
			condition = "true";
		};
		class B_ViperHarness_khk_F : B_ViperHarness_blk_F { displayName = "Khaki"; };
		class B_ViperHarness_oli_F : B_ViperHarness_blk_F { displayName = "Olive"; };
	};
};
class B_ViperHarness_khk_F : B_ViperHarness_blk_F {};
class B_ViperHarness_oli_F : B_ViperHarness_blk_F {};

class B_Bergen_mcamo_F : B_LegStrapBag_black_F {
	displayName = "Bergen";
	price = 12500;
	virtualSpace = 40;
	class Textures {	
		// Factions
		class INVIS {
			displayName = "Invisible";
			textures[] = { "" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction || [player, [""Medic""]] call ULP_fnc_isFaction || [player, [""Hato""]] call ULP_fnc_isFaction";
		};

		// Civilian
		class B_Bergen_mcamo_F {
			displayName = "MTP";
			condition = "true";
		};
		class B_Bergen_dgtl_F : B_Bergen_mcamo_F { displayName = "Digital"; };
		class B_Bergen_hex_F : B_Bergen_mcamo_F { displayName = "Hex"; };
		class B_Bergen_tna_F : B_Bergen_mcamo_F { displayName = "Tropic"; };
	};
};
class B_Bergen_dgtl_F : B_Bergen_mcamo_F {};
class B_Bergen_hex_F : B_Bergen_mcamo_F {};
class B_Bergen_tna_F : B_Bergen_mcamo_F {};

class B_RadioBag_01_black_F : B_ViperLightHarness_blk_F {
	displayName = "Radio Pack";
	price = 25000;
	virtualSpace = 8;
	class Textures {
		class B_RadioBag_01_black_F {
			displayName = "Black";
			condition = "true";
		};
		class B_RadioBag_01_digi_F : B_RadioBag_01_black_F { displayName = "Digi"; };
		class B_RadioBag_01_eaf_F : B_RadioBag_01_black_F { displayName = "Geometric"; };
		class B_RadioBag_01_ghex_F : B_RadioBag_01_black_F { displayName = "Green Hex"; };
		class B_RadioBag_01_hex_F : B_RadioBag_01_black_F { displayName = "Hex"; };
		class B_RadioBag_01_mtp_F : B_RadioBag_01_black_F { displayName = "MTP"; };
		class B_RadioBag_01_tropic_F : B_RadioBag_01_black_F { displayName = "Tropic"; };
		class B_RadioBag_01_wdl_F : B_RadioBag_01_black_F { displayName = "Woodland"; };
	};
};
class B_RadioBag_01_digi_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_eaf_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_ghex_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_hex_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_mtp_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_tropic_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_wdl_F : B_RadioBag_01_black_F {};

class B_Parachute : B_LegStrapBag_black_F {
	displayName = "Parachute";
	price = 10000;
	virtualSpace = 0;
	class Textures {};
};