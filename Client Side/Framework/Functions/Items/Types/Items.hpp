class ItemMap {
	price = 140;
	reputation = false;
	class Textures {};	
};
class ItemCompass : ItemMap{};
class ItemWatch : ItemMap{};

class ItemGPS {
	price = 1650;
	reputation = false;
	class Textures {};	
};
class B_UavTerminal : ItemGPS{};
class ItemRadio : ItemGPS{};

class Binocular {
	price = 1050;
	reputation = false;
	class Textures {};	
};
class Rangefinder : Binocular{ price = 2430; };

class NVGoggles {
	displayName = "Night Vision Goggles";
	price = 35000;
	reputation = false;
	class Textures {
        class NVGoggles {
			displayName = "Brown";
            condition = "true";
		};
		class NVGoggles_OPFOR : NVGoggles {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
        class NVGoggles_INDEP : NVGoggles {
			displayName = "Green";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
    };	
};
class NVGoggles_OPFOR : NVGoggles {};
class NVGoggles_INDEP : NVGoggles {};

class ToolKit {
	price = 1500;
	reputation = false;
	class Textures {};	
};

class Chemlight_green {
	displayName = "Chemlight";
	price = 7600;
	reputation = true;
	class Textures {
        class Chemlight_green {
			displayName = "Green";
            condition = "true";
		};
		class Chemlight_red : Chemlight_green {
			displayName = "Red";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
        class Chemlight_yellow : Chemlight_red { displayName = "Yellow"; };
        class Chemlight_blue : Chemlight_red { displayName = "Blue"; };
    };	
};
class Chemlight_red : Chemlight_green {};
class Chemlight_yellow : Chemlight_green {};
class Chemlight_blue : Chemlight_green {};

class SmokeShell {
	displayName = "Smoke Grenade";
	price = 13450;
	reputation = true;
	class Textures {
        class SmokeShell {
			displayName = "White";
            condition = "true";
		};
		class SmokeShellRed : SmokeShell {
			displayName = "Red";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
        class SmokeShellGreen : SmokeShellRed { displayName = "Green"; };
        class SmokeShellBlue : SmokeShellRed { displayName = "Blue"; };
		class SmokeShellOrange : SmokeShellRed { displayName = "Orange"; };
        class SmokeShellPurple : SmokeShellRed { displayName = "Purple"; };
    };	
};
class SmokeShellRed : SmokeShell {};
class SmokeShellGreen : SmokeShell {};
class SmokeShellBlue : SmokeShell {};
class SmokeShellOrange : SmokeShell {};
class SmokeShellPurple : SmokeShell {};