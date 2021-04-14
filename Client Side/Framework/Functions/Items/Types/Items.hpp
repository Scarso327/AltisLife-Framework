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
		};
        class NVGoggles_INDEP : NVGoggles {
			displayName = "Green";
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
		};
        class SmokeShellGreen : SmokeShell {
			displayName = "Green";
		};
        class SmokeShellBlue : SmokeShell {
			displayName = "Blue";
		};
		class SmokeShellOrange : SmokeShell {
			displayName = "Orange";
		};
        class SmokeShellPurple : SmokeShell {
			displayName = "Purple";
		};
    };	
};
class SmokeShellRed : SmokeShell {};
class SmokeShellGreen : SmokeShell {};
class SmokeShellBlue : SmokeShell {};
class SmokeShellOrange : SmokeShell {};
class SmokeShellPurple : SmokeShell {};