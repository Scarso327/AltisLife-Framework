class G_WirelessEarpiece_F {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {};
};

class G_Aviator {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {};
};

class G_Squares {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {
		class G_Squares {
			displayName = "Clear";
			condition = "true";
		};
		class G_Squares_Tinted : G_Squares { displayName = "Tinted"; };
	};
};
class G_Squares_Tinted : G_Squares{};

class G_Spectacles {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {
		class G_Spectacles {
			displayName = "Clear";
			condition = "true";
		};
		class G_Spectacles_Tinted : G_Spectacles { displayName = "Tinted"; };
	};
};
class G_Spectacles_Tinted : G_Spectacles{};

class G_Shades_Black {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {
		class G_Shades_Black {
			displayName = "Black";
			condition = "true";
		};
		class G_Shades_Red : G_Shades_Black { displayName = "Red"; };
		class G_Squares_Green : G_Shades_Black { displayName = "Green"; };
		class G_Squares_Blue : G_Shades_Black { displayName = "Blue"; };
	};
};
class G_Shades_Red : G_Shades_Black{};
class G_Squares_Green : G_Shades_Black{};
class G_Squares_Blue : G_Shades_Black{};

class G_Sport_Red {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {
		class G_Sport_Red {
			displayName = "Red";
			condition = "true";
		};
		class G_Shades_BlackWhite : G_Sport_Red { displayName = "Black-White"; };
		class G_Shades_Blackred : G_Sport_Red { displayName = "Black-Red"; };
		class G_Shades_Blackyellow : G_Sport_Red { displayName = "Black-Yellow"; };
		class G_Shades_Greenblack : G_Sport_Red { displayName = "Green-Black"; };
		class G_Shades_checkered : G_Sport_Red { displayName = "Checkered"; };
	};
};
class G_Shades_BlackWhite : G_Sport_Red{};
class G_Shades_Blackred : G_Sport_Red{};
class G_Shades_Blackyellow : G_Sport_Red{};
class G_Shades_Greenblack : G_Sport_Red{};
class G_Shades_checkered : G_Sport_Red{};

class G_Lady_Blue {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {};
};

class G_Lowprofile {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {};
};

class G_Combat {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {};
};

class G_Tactical_Clear {
	displayName = "Night Vision Glasses";
	price = 0;
	isMask = false;
	isNV = true;
	isGas = false;
	class Textures {};
};

class G_EyeProtectors_F {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {
		class G_EyeProtectors_F {
			displayName = "Eye Protectors";
			condition = "true";
		};
		class G_EyeProtectors_Earpiece_F : G_EyeProtectors_F { displayName = "Eye Protectors + Earpiece"; };
	};
};
class G_EyeProtectors_Earpiece_F : G_EyeProtectors_F{};

class G_B_Diving {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {
		class G_B_Diving {
			displayName = "Black";
			condition = "true";
		};
		class G_O_Diving : G_B_Diving { displayName = "Brown"; };
		class G_I_Diving : G_B_Diving { displayName = "Green"; };
	};
};
class G_O_Diving : G_B_Diving{};
class G_I_Diving : G_B_Diving{};

class G_Respirator_white_F {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = true;
	class Textures {
		class G_Respirator_white_F {
			displayName = "White";
			condition = "true";
		};
		class G_Respirator_blue_F : G_Respirator_white_F { displayName = "Blue"; };
		class G_Respirator_yellow_F : G_Respirator_white_F { displayName = "Yellow"; };
	};
};
class G_Respirator_blue_F : G_Respirator_white_F{};
class G_Respirator_yellow_F : G_Respirator_white_F{};

class G_RegulatorMask_F {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = true;
	class Textures {};
};

class G_Blindfold_01_black__F {
	price = 0;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {};
};
class G_Blindfold_01_white__F : G_Blindfold_01_black__F{};

class G_Bandanna_aviator {
	price = 0;
	isMask = true;
	isNV = false;
	isGas = false;
	class Textures {
		class G_Bandanna_aviator {
			displayName = "Black + Aviators";
			condition = "true";
		};
		class G_Bandanna_shades : G_Bandanna_aviator { displayName = "Black + Shades"; };
		class G_Bandanna_sport : G_Bandanna_aviator { displayName = "Black + Sport"; };
		class G_Bandanna_beast : G_Bandanna_aviator { displayName = "Beast"; };
		class G_Bandanna_blk : G_Bandanna_aviator { displayName = "Black"; };
	};
};
class G_Bandanna_shades : G_Bandanna_aviator{};
class G_Bandanna_sport : G_Bandanna_aviator{};
class G_Bandanna_beast : G_Bandanna_aviator{};
class G_Bandanna_blk : G_Bandanna_aviator{};
class G_Bandanna_khk : G_Bandanna_aviator{};
class G_Bandanna_oli : G_Bandanna_aviator{};

class G_Balaclava_blk {
	price = 0;
	isMask = true;
	isNV = false;
	isGas = false;
	class Textures {};
};
class G_Balaclava_lowprofile : G_Balaclava_blk{};
class G_Balaclava_combat : G_Balaclava_blk{};
class G_Balaclava_oli : G_Balaclava_blk{};

class G_Balaclava_TI_blk_F {
	price = 0;
	isMask = true;
	isNV = false;
	isGas = false;
	class Textures {
		class G_Balaclava_TI_blk_F {
			displayName = "Black";
			condition = "true";
		};
		class G_Balaclava_TI_G_blk_F : G_Balaclava_TI_blk_F { displayName = "Black + Goggles"; };
	};
};
class G_Balaclava_TI_G_blk_F : G_Balaclava_TI_blk_F{};