class hgun_Pistol_Signal_F {
	price = 5000;
	reputation = true;
	class Textures {};	
};

class hgun_Pistol_01_F {
	price = 24600;
	reputation = true;
	class Textures {};	
};

class hgun_Rook40_F {
	price = 33100;
	reputation = true;
	class Textures {};	
};

class hgun_P07_F {
	displayName = "Taser x26e";
	price = 38700;
	reputation = true;
	class Textures {
		class hgun_P07_F {
			displayName = "Khaki";
		};
		class hgun_P07_blk_F : hgun_P07_F {
			displayName = "Black";
			condition = "true";
		};
	};	
};
class hgun_P07_blk_F : hgun_P07_F {};

class hgun_ACPC2_F {
	price = 45000;
	reputation = true;
	class Textures {};	
};

class hgun_Pistol_heavy_01_F {
	price = 49950;
	reputation = true;
	class Textures {
		class hgun_Pistol_heavy_01_F {
			displayName = "Tan";
			condition = "true";
		};
		class hgun_Pistol_heavy_01_green_F : hgun_Pistol_heavy_01_F {
			displayName = "Green";
		};
	};	
};
class hgun_Pistol_heavy_01_green_F : hgun_Pistol_heavy_01_F {};

class hgun_Pistol_heavy_02_F {
	price = 62300;
	reputation = true;
	class Textures {};	
};