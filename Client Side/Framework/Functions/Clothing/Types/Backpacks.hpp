class B_LegStrapBag_black_F {
	displayName = "Leg Strap";
	price = 0;
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
class B_LegStrapBag_coyote_F : B_LegStrapBag_black_F{};
class B_LegStrapBag_olive_F : B_LegStrapBag_black_F{};

class B_Messenger_Black_F {
	displayName = "Messenger Bag";
	price = 0;
	reputation = false;
	virtualSpace = 15;
	class Textures {
		class B_Messenger_Black_F {
			displayName = "Black";
			condition = "true";
		};
		class B_Messenger_Gray_F : B_Messenger_Black_F { displayName = "Gray"; };
		class B_Messenger_Coyote_F : B_Messenger_Black_F { displayName = "Coyote"; };
		class B_Messenger_Olive_F : B_Messenger_Black_F { displayName = "Olive"; };
	};
};
class B_Messenger_Gray_F : B_Messenger_Black_F{};
class B_Messenger_Coyote_F : B_Messenger_Black_F{};
class B_Messenger_Olive_F : B_Messenger_Black_F{};
class B_Messenger_IDAP_F : B_Messenger_Black_F{};

class B_SCBA_01_F {
	price = 0;
	reputation = false;
	virtualSpace = 0;
	class Textures {};
};

class B_AssaultPack_blk {
	displayName = "Assault Pack";
	price = 0;
	reputation = false;
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
		class B_AssaultPack_wdl_F : B_AssaultPack_blk { displayName = "Woodland"; };
	};
};
class B_AssaultPack_cbr : B_AssaultPack_blk{};
class B_AssaultPack_khk : B_AssaultPack_blk{};
class B_AssaultPack_rgr : B_AssaultPack_blk{};
class B_AssaultPack_sgg : B_AssaultPack_blk{};
class B_AssaultPack_wdl_F : B_AssaultPack_blk{};

class B_FieldPack_blk {
	displayName = "Field Pack";
	price = 0;
	reputation = false;
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
class B_FieldPack_cbr : B_FieldPack_blk{};
class B_FieldPack_khk : B_FieldPack_blk{};
class B_FieldPack_oli : B_FieldPack_blk{};
class B_FieldPack_green_F : B_FieldPack_blk{};

class B_Kitbag_cbr {
	displayName = "Kitbag";
	price = 0;
	reputation = false;
	virtualSpace = 24;
	class Textures {
		class B_Kitbag_cbr {
			displayName = "Coyote";
			condition = "true";
		};
		class B_Kitbag_tan : B_Kitbag_cbr { displayName = "Tan"; };
		class B_Kitbag_rgr : B_Kitbag_cbr { displayName = "Green"; };
		class B_Kitbag_sgg : B_Kitbag_cbr { displayName = "Sage"; };
		class B_Kitbag_mcamo : B_Kitbag_cbr { displayName = "MTP"; };
	};
};
class B_Kitbag_tan : B_Kitbag_cbr{};
class B_Kitbag_rgr : B_Kitbag_cbr{};
class B_Kitbag_sgg : B_Kitbag_cbr{};
class B_Kitbag_mcamo : B_Kitbag_cbr{};

class B_TacticalPack_blk {
	displayName = "Tactical Pack";
	price = 0;
	reputation = false;
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
class B_TacticalPack_oli : B_TacticalPack_blk{};
class B_TacticalPack_rgr : B_TacticalPack_blk{};

class B_CivilianBackpack_01_Everyday_Black_F {
	displayName = "Civilian Pack";
	price = 0;
	reputation = false;
	virtualSpace = 25;
	class Textures {
		class B_CivilianBackpack_01_Everyday_Black_F {
			displayName = "Black";
			condition = "true";
		};
		class B_CivilianBackpack_01_Everyday_Astra_F : B_CivilianBackpack_01_Everyday_Black_F { displayName = "Astra"; };
		class B_CivilianBackpack_01_Everyday_Vrana_F : B_CivilianBackpack_01_Everyday_Black_F { displayName = "Vrana"; };
		class B_CivilianBackpack_01_Sport_Blue_F : B_CivilianBackpack_01_Everyday_Black_F { displayName = "Blue"; };
		class B_CivilianBackpack_01_Sport_Green_F : B_CivilianBackpack_01_Everyday_Black_F { displayName = "Green"; };
		class B_CivilianBackpack_01_Sport_Red_F : B_CivilianBackpack_01_Everyday_Black_F { displayName = "Red"; };
	};
};
class B_CivilianBackpack_01_Everyday_Astra_F : B_CivilianBackpack_01_Everyday_Black_F{};
class B_CivilianBackpack_01_Everyday_Vrana_F : B_CivilianBackpack_01_Everyday_Black_F{};
class B_CivilianBackpack_01_Sport_Blue_F : B_CivilianBackpack_01_Everyday_Black_F{};
class B_CivilianBackpack_01_Sport_Green_F : B_CivilianBackpack_01_Everyday_Black_F{};
class B_CivilianBackpack_01_Sport_Red_F : B_CivilianBackpack_01_Everyday_Black_F{};

class B_Carryall_cbr {
	displayName = "Carryall";
	price = 0;
	reputation = false;
	virtualSpace = 30;
	class Textures {
		class INVIS {
			displayName = "Invisible";
			textures[] = { "" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction || [player, [""Medic""]] call ULP_fnc_isFaction || [player, [""Hato""]] call ULP_fnc_isFaction";
		};
		class B_Carryall_cbr {
			displayName = "Coyote";
			condition = "true";
		};
		class B_Carryall_khk : B_Carryall_cbr { displayName = "khaki"; };
		class B_Carryall_oli : B_Carryall_cbr { displayName = "Olive"; };
		class B_Carryall_green_F : B_Carryall_cbr { displayName = "Green"; };
		class B_Carryall_wdl_F : B_Carryall_cbr { displayName = "Woodland"; };
	};
};
class B_Carryall_khk : B_Carryall_cbr{};
class B_Carryall_oli : B_Carryall_cbr{};
class B_Carryall_green_F : B_Carryall_cbr{};
class B_Carryall_wdl_F : B_Carryall_cbr{};

class B_ViperLightHarness_blk_F {
	displayName = "Light Viper Harness";
	price = 0;
	reputation = false;
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
class B_ViperLightHarness_khk_F : B_ViperLightHarness_blk_F{};
class B_ViperLightHarness_oli_F : B_ViperLightHarness_blk_F{};

class B_ViperHarness_blk_F {
	displayName = "Viper Harness";
	price = 0;
	reputation = false;
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
class B_ViperHarness_khk_F : B_ViperHarness_blk_F{};
class B_ViperHarness_oli_F : B_ViperHarness_blk_F{};

class B_Bergen_mcamo_F {
	displayName = "Bergen";
	price = 0;
	reputation = false;
	virtualSpace = 40;
	class Textures {
		class B_Bergen_mcamo_F {
			displayName = "MTP";
			condition = "true";
		};
		class B_Bergen_dgtl_F : B_Bergen_mcamo_F { displayName = "Digital"; };
		class B_Bergen_hex_F : B_Bergen_mcamo_F { displayName = "Hex"; };
	};
};
class B_Bergen_dgtl_F : B_Bergen_mcamo_F{};
class B_Bergen_hex_F : B_Bergen_mcamo_F{};

class B_Parachute {
	price = 0;
	reputation = false;
	virtualSpace = 0;
	class Textures {};
};