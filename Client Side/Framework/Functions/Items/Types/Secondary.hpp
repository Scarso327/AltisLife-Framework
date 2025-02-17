class hgun_Pistol_Signal_F {
	price = 4500;
	reputation = false;
};
class hgun_Pistol_01_F : hgun_Pistol_Signal_F { price = 19440; };
class hgun_Rook40_F : hgun_Pistol_Signal_F { price = 27090; };
class hgun_ACPC2_F : hgun_Pistol_Signal_F { price = 37800; };
class hgun_Pistol_heavy_02_F : hgun_Pistol_Signal_F { price = 38655; };
class hgun_P07_F : hgun_Pistol_Signal_F {
	displayName = "Taser x26e";
	price = 32130;
	class NonLethal {
		distance = 20;
		sound[] = { "taserSound", 50, 1 };
		hasTaserReload = true;
	};
	class Textures {
		class hgun_P07_F {
			displayName = "Khaki";
			condition = "true";
		};
		class hgun_P07_blk_F : hgun_P07_F {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
	};	
};
class hgun_P07_blk_F : hgun_P07_F {};

class hgun_Pistol_heavy_01_F : hgun_Pistol_Signal_F {
	price = 55170;
	class Textures {
		class hgun_Pistol_heavy_01_F {
			displayName = "Tan";
			condition = "true";
		};
		class hgun_Pistol_heavy_01_green_F : hgun_Pistol_heavy_01_F {
			displayName = "Green";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
	};	
};
class hgun_Pistol_heavy_01_green_F : hgun_Pistol_heavy_01_F {};