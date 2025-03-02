class ItemMap {
	price = 40;
	reputation = false;
	class Textures {};	
};
class ItemCompass : ItemMap { price = 60; };
class ItemWatch : ItemMap { price = 1650; };
class ItemGPS : ItemMap { price = 900; };
class B_UavTerminal : ItemMap { price = 16500; };
class C_UavTerminal : B_UavTerminal {};
class ItemRadio : ItemMap { price = 1100; };
class ToolKit { price = 1000; };
class Binocular { price = 850; };
class Rangefinder : Binocular { 
	price = 12900; 
	reputation = true;
};

class NVGoggles {
	displayName = "Night Vision Goggles";
	price = 45000;
	reputation = true;
	class Textures {
        class NVGoggles {
			displayName = "Brown";
            condition = "true";
		};
		class NVGoggles_OPFOR : NVGoggles {
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0 || { [player, [""Police""]] call ULP_fnc_isFaction } || { [player, [""Medic""]] call ULP_fnc_isFaction }";
		};
        class NVGoggles_INDEP : NVGoggles {
			displayName = "Green";
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
    };	
};
class NVGoggles_OPFOR : NVGoggles {};
class NVGoggles_INDEP : NVGoggles {};

class O_NVGoggles_grn_F : NVGoggles {
	displayName = "Compact Night Vision Goggles";
	class Textures {
        class O_NVGoggles_grn_F {
			displayName = "Green";
            condition = "true";
		};
		class O_NVGoggles_urb_F : O_NVGoggles_grn_F { displayName = "Urban"; };
        class O_NVGoggles_hex_F : O_NVGoggles_grn_F { displayName = "Hex"; };
		class O_NVGoggles_ghex_F : O_NVGoggles_grn_F { displayName = "Green Hex"; };
    };	
};
class O_NVGoggles_urb_F : O_NVGoggles_grn_F {};
class O_NVGoggles_hex_F : O_NVGoggles_grn_F {};
class O_NVGoggles_ghex_F : O_NVGoggles_grn_F {};

class Chemlight_green {
	displayName = "Chemlight";
	price = 6000;
	reputation = false;
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
	price = 12450;
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