class G_WirelessEarpiece_F {
	price = 10;
	reputation = false;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {};
};

class G_Aviator : G_WirelessEarpiece_F {
	displayName = "Aviator Glasses";
	price = 10;
	class Textures {};
};

class G_Squares : G_WirelessEarpiece_F {
	displayName = "Square Spectacles";
	price = 10;
	class Textures {
		class G_Squares {
			displayName = "Clear";
			condition = "true";
		};
		class G_Squares_Tinted : G_Squares { 
			displayName = "Tinted";
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
	};
};
class G_Squares_Tinted : G_Squares {};

class G_Spectacles : G_WirelessEarpiece_F {
	displayName = "Spectacle Glasses";
	price = 10;
	class Textures {
		class G_Spectacles {
			displayName = "Clear";
			condition = "true";
		};
		class G_Spectacles_Tinted : G_Spectacles { 
			displayName = "Tinted"; 
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
	};
};
class G_Spectacles_Tinted : G_Spectacles {};

class G_Shades_Black : G_WirelessEarpiece_F {
	displayName = "Shades";
	price = 10;
	class Textures {
		class G_Shades_Black {
			displayName = "Black";
			condition = "true";
		};
		class G_Shades_Red : G_Shades_Black { displayName = "Red"; };
		class G_Shades_Green : G_Shades_Black { displayName = "Green"; };
		class G_Shades_Blue : G_Shades_Black { displayName = "Blue"; };
	};
};
class G_Shades_Red : G_Shades_Black {};
class G_Shades_Green : G_Shades_Black {};
class G_Shades_Blue : G_Shades_Black {};

class G_Sport_Red : G_WirelessEarpiece_F {
	displayName = "Sport Shades";
	price = 10;
	class Textures {
		class G_Sport_Red {
			displayName = "Red";
			condition = "true";
		};
		class G_Sport_BlackWhite : G_Sport_Red { displayName = "Black-White"; };
		class G_Sport_Blackred : G_Sport_Red { displayName = "Black-Red"; };
		class G_Sport_Blackyellow : G_Sport_Red { displayName = "Black-Yellow"; };
		class G_Sport_Greenblack : G_Sport_Red { displayName = "Green-Black"; };
		class G_Sport_checkered : G_Sport_Red { displayName = "Checkered"; };
	};
};
class G_Sport_BlackWhite : G_Sport_Red {};
class G_Sport_Blackred : G_Sport_Red {};
class G_Sport_Blackyellow : G_Sport_Red {};
class G_Sport_Greenblack : G_Sport_Red {};
class G_Sport_checkered : G_Sport_Red {};

class G_Lady_Blue : G_WirelessEarpiece_F {
	displayName = "Ladies Shades";
	price = 10;
	class Textures {};
};

class G_Lowprofile : G_WirelessEarpiece_F {
	displayName = "Low Profile Goggles";
	price = 50;
	class Textures {};
};

class G_Combat : G_WirelessEarpiece_F {
	displayName = "Combat Goggles";
	price = 100;
	class Textures {
		class G_Combat {
			displayName = "Brown";
			condition = "true";
		};
		class G_Combat_Goggles_tna_F : G_Combat { displayName = "Green"; };
	};
};
class G_Combat_Goggles_tna_F : G_Combat {};

class G_EyeProtectors_F : G_WirelessEarpiece_F {
	displayName = "Eye Protectors";
	price = 30;
	class Textures {
		class G_EyeProtectors_F {
			displayName = "Eye Protectors";
			condition = "true";
		};
		class G_EyeProtectors_Earpiece_F : G_EyeProtectors_F { displayName = "Eye Protectors + Earpiece"; };
	};
};
class G_EyeProtectors_Earpiece_F : G_EyeProtectors_F{};

class G_B_Diving : G_WirelessEarpiece_F {
	displayName = "Diving Goggles";
	price = 1500;
	class Textures {
		class G_B_Diving {
			displayName = "Black";
			condition = "true";
		};
		class G_O_Diving : G_B_Diving { displayName = "Brown"; };
		class G_I_Diving : G_B_Diving { displayName = "Green"; };
	};
};
class G_O_Diving : G_B_Diving {};
class G_I_Diving : G_B_Diving {};

class G_Respirator_white_F {
	displayName = "COVID Mask";
	price = 5;
	class Textures {
		class G_Respirator_white_F {
			displayName = "White";
			condition = "true";
		};
		class G_Respirator_blue_F : G_Respirator_white_F { displayName = "Blue"; };
		class G_Respirator_yellow_F : G_Respirator_white_F { displayName = "Yellow"; };
	};
};
class G_Respirator_blue_F : G_Respirator_white_F {};
class G_Respirator_yellow_F : G_Respirator_white_F {};

class G_RegulatorMask_F : G_WirelessEarpiece_F {
	displayName = "Regulator Mask";
	price = 10000;
	isMask = true;
	isGas = true;
	class Textures {};
};

class G_AirPurifyingRespirator_01_F : G_RegulatorMask_F {
	displayName = "Air Purifying Respirator";
	price = 12500;
	isNV = true;
	class Textures {
		class G_AirPurifyingRespirator_01_F {
			displayName = "Black (Old)";
			condition = "true";
		};
		class G_AirPurifyingRespirator_02_black_F : G_AirPurifyingRespirator_01_F { 
			displayName = "Black"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class G_AirPurifyingRespirator_02_olive_F : G_AirPurifyingRespirator_02_black_F { displayName = "Olive"; };
		class G_AirPurifyingRespirator_02_sand_F : G_AirPurifyingRespirator_02_black_F { displayName = "Sand"; };
	};
};
class G_AirPurifyingRespirator_02_black_F : G_AirPurifyingRespirator_01_F {};
class G_AirPurifyingRespirator_02_olive_F : G_AirPurifyingRespirator_01_F {};
class G_AirPurifyingRespirator_02_sand_F : G_AirPurifyingRespirator_01_F {};

class G_Blindfold_01_black_F : G_WirelessEarpiece_F {
	displayName = "Blindfold";
	price = 5;
	class Textures {
		class G_Blindfold_01_black_F {
			displayName = "Black";
			condition = "true";
		};
		class G_Blindfold_01_white_F : G_Blindfold_01_black_F { displayName = "White"; };
	};
};
class G_Blindfold_01_white_F : G_Blindfold_01_black_F {};

class G_Bandanna_aviator : G_WirelessEarpiece_F {
	displayName = "Bandanna";
	price = 2500;
	reputation = true;
	isMask = true;
	class Textures {
		class G_Bandanna_aviator {
			displayName = "Black + Aviators";
			condition = "true";
		};
		class G_Bandanna_shades : G_Bandanna_aviator { displayName = "Black + Shades"; };
		class G_Bandanna_sport : G_Bandanna_aviator { displayName = "Black + Sport"; };
		class G_Bandanna_blk : G_Bandanna_aviator { displayName = "Black"; };
		class G_Bandanna_khk : G_Bandanna_aviator { displayName = "Khaki"; };
		class G_Bandanna_oli : G_Bandanna_aviator { displayName = "Olive"; };
		class G_Bandanna_beast : G_Bandanna_aviator { 
			displayName = "Beast";
			condition = "[] call ULP_fnc_donatorLevel > 0";  
		};
		class G_Bandanna_BlueFlame1 : G_Bandanna_beast { displayName = "Blue Flame"; };
		class G_Bandanna_BlueFlame2 : G_Bandanna_beast { displayName = "Blue Flames"; };
		class G_Bandanna_CandySkull : G_Bandanna_beast { displayName = "Candy Skull"; };
		class G_Bandanna_OrangeFlame1 : G_Bandanna_beast { displayName = "Orange Flames"; };
		class G_Bandanna_RedFlame1 : G_Bandanna_beast { displayName = "Red Flames"; };
		class G_Bandanna_Skull1 : G_Bandanna_beast { displayName = "Skull"; };
		class G_Bandanna_Skull2 : G_Bandanna_beast { displayName = "Skull (Ornamental)"; };
		class G_Bandanna_Syndikat1 : G_Bandanna_beast { displayName = "Syndikat"; };
		class G_Bandanna_Syndikat2 : G_Bandanna_beast { displayName = "Syndikat"; };
		class G_Bandanna_Vampire_01 : G_Bandanna_beast { displayName = "Vampire"; };
	};
};
class G_Bandanna_shades : G_Bandanna_aviator {};
class G_Bandanna_sport : G_Bandanna_aviator {};
class G_Bandanna_beast : G_Bandanna_aviator {};
class G_Bandanna_blk : G_Bandanna_aviator {};
class G_Bandanna_khk : G_Bandanna_aviator {};
class G_Bandanna_oli : G_Bandanna_aviator {};
class G_Bandanna_BlueFlame1 : G_Bandanna_aviator {};
class G_Bandanna_BlueFlame2 : G_Bandanna_aviator {};
class G_Bandanna_CandySkull : G_Bandanna_aviator {};
class G_Bandanna_OrangeFlame1 : G_Bandanna_aviator {};
class G_Bandanna_RedFlame1 : G_Bandanna_aviator {};
class G_Bandanna_Skull1 : G_Bandanna_aviator {};
class G_Bandanna_Skull2 : G_Bandanna_aviator {};
class G_Bandanna_Syndikat1 : G_Bandanna_aviator {};
class G_Bandanna_Syndikat2 : G_Bandanna_aviator {};
class G_Bandanna_Vampire_01 : G_Bandanna_aviator {};

class G_Balaclava_blk : G_Bandanna_aviator {
	displayName = "Balaclava";
	price = 5000;
	class Textures {
		class G_Balaclava_blk {
			displayName = "Black";
			condition = "true";
		};
		class G_Balaclava_lowprofile : G_Balaclava_blk { displayName = "Black + Lowprofile Goggles"; };
		class G_Balaclava_combat : G_Balaclava_blk { displayName = "Black + Combat Goggles"; };
		class G_Balaclava_oli : G_Balaclava_blk { displayName = "Olive"; };
		class G_Balaclava_BlueStrips : G_Balaclava_blk { 
			displayName = "Blue Stripe"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class G_Balaclava_Flecktarn : G_Balaclava_BlueStrips { displayName = "Flecktarn"; };
		class G_Balaclava_Halloween_01 : G_Balaclava_BlueStrips { displayName = "Halloween"; };
		class G_Balaclava_Flames1 : G_Balaclava_BlueStrips { displayName = "Orange Pattern"; };
		class G_Balaclava_Scarecrow_01 : G_Balaclava_BlueStrips { displayName = "Scarecrow"; };
		class G_Balaclava_Skull1 : G_Balaclava_BlueStrips { displayName = "Skull"; };
		class G_Balaclava_Tropentarn : G_Balaclava_BlueStrips { displayName = "Tropentarn"; };
	};
};
class G_Balaclava_lowprofile : G_Balaclava_blk {};
class G_Balaclava_combat : G_Balaclava_blk {};
class G_Balaclava_oli : G_Balaclava_blk {};
class G_Balaclava_BlueStrips : G_Balaclava_blk {};
class G_Balaclava_Flecktarn : G_Balaclava_blk {};
class G_Balaclava_Halloween_01 : G_Balaclava_blk {};
class G_Balaclava_Flames1 : G_Balaclava_blk {};
class G_Balaclava_Scarecrow_01 : G_Balaclava_blk {};
class G_Balaclava_Skull1 : G_Balaclava_blk {};
class G_Balaclava_Tropentarn : G_Balaclava_blk {};

class G_Balaclava_TI_blk_F : G_Bandanna_aviator {
	displayName = "Stealth Balaclava";
	price = 15000;
	class Textures {
		class G_Balaclava_TI_blk_F {
			displayName = "Black";
			condition = "true";
		};
		class G_Balaclava_TI_tna_F : G_Balaclava_TI_blk_F { displayName = "Green"; };
	};
};
class G_Balaclava_TI_tna_F : G_Balaclava_TI_blk_F {};

class G_Balaclava_TI_G_blk_F : G_Bandanna_aviator {
	displayName = "Stealth Balaclava (NVG)";
	price = 50000;
	isNV = true;
	class Textures {
		class G_Balaclava_TI_G_blk_F {
			displayName = "Black";
			condition = "true";
		};
		class G_Balaclava_TI_G_tna_F : G_Balaclava_TI_G_blk_F { displayName = "Green"; };
	};
};
class G_Balaclava_TI_G_tna_F : G_Balaclava_TI_G_blk_F {};

class G_Tactical_Clear : G_WirelessEarpiece_F {
	displayName = "Tactical Glasses NVG";
	price = 35000;
	reputation = true;
	isNV = true;
	class Textures {
		class G_Tactical_Clear {
			displayName = "Clear";
			condition = "true";
		};
		class G_Tactical_Black : G_Tactical_Clear { 
			displayName = "Black"; 
			condition = "[] call ULP_fnc_donatorLevel > 0"; 
		};
	};
};
class G_Tactical_Black : G_Tactical_Clear {};

class G_Goggles_VR {
	displayName = "Staff Goggles";
	price = 1000000;
	reputation = false;
	isMask = false;
	isNV = true;
	isGas = true;
	class Textures {};
};
