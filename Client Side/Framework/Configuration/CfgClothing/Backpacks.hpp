class B_LegStrapBag_black_F {
	price = 0;
	virtualSpace = 0;
	class Textures {};
};
class B_LegStrapBag_coyote_F : B_LegStrapBag_black_F{};
class B_LegStrapBag_olive_F : B_LegStrapBag_black_F{};

class B_Messenger_Black_F {
	price = 0;
	virtualSpace = 0;
	class Textures {};
};
class B_Messenger_Gray_F : B_Messenger_Black_F{};
class B_Messenger_Coyote_F : B_Messenger_Black_F{};
class B_Messenger_Olive_F : B_Messenger_Black_F{};
class B_Messenger_IDAP_F : B_Messenger_Black_F{};

class B_SCBA_01_F {
	price = 0;
	virtualSpace = 0;
	class Textures {};
};

class B_AssaultPack_blk {
	price = 0;
	virtualSpace = 0;
	class Textures {};
};
class B_AssaultPack_cbr : B_AssaultPack_blk{};
class B_AssaultPack_khk : B_AssaultPack_blk{};
class B_AssaultPack_rgr : B_AssaultPack_blk{};
class B_AssaultPack_sgg : B_AssaultPack_blk{};

class B_FieldPack_blk {
	price = 0;
	virtualSpace = 0;
	class Textures {};
};
class B_FieldPack_cbr : B_FieldPack_blk{};
class B_FieldPack_khk : B_FieldPack_blk{};
class B_FieldPack_oli : B_FieldPack_blk{};
class B_FieldPack_green_F : B_FieldPack_blk{};

class B_Kitbag_cbr {
	price = 0;
	virtualSpace = 0;
	class Textures {};
};
class B_Kitbag_tan : B_Kitbag_cbr{};
class B_FieldPack_khk : B_Kitbag_cbr{};
class B_FieldPack_oli : B_Kitbag_cbr{};
class B_FieldPack_green_F : B_Kitbag_cbr{};

class B_TacticalPack_blk {
	price = 0;
	virtualSpace = 0;
	class Textures {};
};
class B_TacticalPack_oli : B_TacticalPack_blk{};
class B_TacticalPack_rgr : B_TacticalPack_blk{};

class B_FieldPack_blk {
	price = 0;
	virtualSpace = 0;
	class Textures {};
};
class B_FieldPack_cbr : B_FieldPack_blk{};
class B_FieldPack_khk : B_FieldPack_blk{};
class B_FieldPack_oli : B_FieldPack_blk{};
class B_FieldPack_green_F : B_FieldPack_blk{};

class B_Carryall_cbr {
	price = 0;
	virtualSpace = 0;
	class Textures {
		class INVIS {
			displayName = "Invisible";
			textures[] = { "" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction || [player, [""Medic""]] call ULP_fnc_isFaction";
		};
	};
};
class B_Carryall_khk : B_Carryall_cbr{};
class B_Carryall_oli : B_Carryall_cbr{};
class B_Carryall_green_F : B_Carryall_cbr{};

class B_Bergen_mcamo_F {
	price = 0;
	virtualSpace = 0;
	class Textures {};
};
class B_Bergen_dgtl_F : B_Bergen_mcamo_F{};
class B_Bergen_hex_F : B_Bergen_mcamo_F{};