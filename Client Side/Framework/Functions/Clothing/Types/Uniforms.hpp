class U_C_Poor_1 {
	price = 50;
	virtualSpace = 2;
	reputation = false;
	isGas = false;
	class Textures {};
};
class U_C_Farmer : U_C_Poor_1 {};
class U_C_Mechanic_01_F : U_C_Poor_1 {};

class U_C_Poloshirt_blue : U_C_Poor_1 {
	displayName = "Commoner Clothes";
	price = 100;
	class Textures {
		class U_C_Poloshirt_blue { 
			displayName = "Blue"; 
			condition = "true";
		};
		class U_C_Poloshirt_burgundy : U_C_Poloshirt_blue { displayName = "Burgundy"; };
		class U_C_Poloshirt_stripped : U_C_Poloshirt_blue { displayName = "Stripped"; };
		class U_C_Poloshirt_tricolour : U_C_Poloshirt_blue { displayName = "Tricolor"; };
		class U_C_Poloshirt_salmon : U_C_Poloshirt_blue { displayName = "Salmon"; };
		class U_C_Poloshirt_redwhite : U_C_Poloshirt_blue { displayName = "Redwhite"; };
	};
};
class U_C_Poloshirt_burgundy : U_C_Poloshirt_blue {};
class U_C_Poloshirt_stripped : U_C_Poloshirt_blue {};
class U_C_Poloshirt_tricolour : U_C_Poloshirt_blue {};
class U_C_Poloshirt_salmon : U_C_Poloshirt_blue {};
class U_C_Poloshirt_redwhite : U_C_Poloshirt_blue {};

class U_C_WorkerOveralls : U_C_Poor_1 {
	displayName = "Worker Overalls";
	price = 150;
	virtualSpace = 4;
	class Textures {
		class U_C_WorkerOveralls { 
			displayName = "Used"; 
			condition = "true";
		};
		class White : U_C_WorkerOveralls { 
			displayName = "White"; 
			textures[] = { "\A3\characters_f\common\data\coveralls_grey_co.paa" };
		};
		class Gray : U_C_WorkerOveralls { 
			displayName = "Gray"; 
			textures[] = { "\A3\characters_f\common\data\coveralls_black_co.paa" };
		};
		class Rust : U_C_WorkerOveralls { 
			displayName = "Rust"; 
			textures[] = { "\A3\characters_f\common\data\coveralls_bandit_co.paa" };
		};
		class Camo : U_C_WorkerOveralls { 
			displayName = "Camo"; 
			textures[] = { "\A3\characters_f\common\data\coveralls_urbancamo_co.paa" };
		};
	};
};

class U_C_ConstructionCoverall_Black_F : U_C_WorkerOveralls {
	displayName = "Construction Overalls";
	class Textures {
		class U_C_ConstructionCoverall_Black_F { 
			displayName = "Black"; 
			condition = "true";
		};
		class U_C_ConstructionCoverall_Red_F : U_C_ConstructionCoverall_Black_F { displayName = "Red"; };
		class U_C_ConstructionCoverall_Blue_F : U_C_ConstructionCoverall_Black_F { displayName = "Blue"; };
		class U_C_ConstructionCoverall_Vrana_F : U_C_ConstructionCoverall_Black_F { 
			displayName = "Vrana"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
	};
};
class U_C_ConstructionCoverall_Red_F : U_C_WorkerOveralls {};
class U_C_ConstructionCoverall_Blue_F : U_C_WorkerOveralls {};
class U_C_ConstructionCoverall_Vrana_F : U_C_WorkerOveralls {};

class U_C_Man_casual_1_F : U_C_Poor_1 {
	displayName = "Casual Clothes";
	price = 100;
	class Textures {
		class U_C_Man_casual_1_F { 
			displayName = "Navy"; 
			condition = "true";
		};
		class U_C_Man_casual_2_F : U_C_Man_casual_1_F { displayName = "Blue"; };
		class U_C_Man_casual_3_F : U_C_Man_casual_1_F { displayName = "Green"; };
		class Brown : U_C_Man_casual_1_F { 
			displayName = "Brown"; 
			textures[] = { "A3\Characters_F\Civil\Data\ig_poloshirt_2_co.paa" };
		};
		class Gray : U_C_Man_casual_1_F { 
			displayName = "Gray"; 
			textures[] = { "A3\Characters_F\Civil\Data\ig_poloshirt_1_co.paa" };
		};
	};
};
class U_C_Man_casual_2_F : U_C_Man_casual_1_F{};
class U_C_Man_casual_3_F : U_C_Man_casual_1_F{};

class U_C_ArtTShirt_01_v1_F : U_C_Poor_1 {
	displayName = "Casual T-Shirts";
	price = 100;
	class Textures {
		class U_C_ArtTShirt_01_v1_F { 
			displayName = "Art of War"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class U_C_ArtTShirt_01_v2_F : U_C_ArtTShirt_01_v1_F { displayName = "Drones"; };
		class U_C_ArtTShirt_01_v3_F : U_C_ArtTShirt_01_v1_F { displayName = "Waltham Robotics"; };
		class U_C_ArtTShirt_01_v4_F : U_C_ArtTShirt_01_v1_F { displayName = "Exhibition"; };
		class U_C_ArtTShirt_01_v5_F : U_C_ArtTShirt_01_v1_F { displayName = "Robogeddon"; };
		class U_C_ArtTShirt_01_v6_F : U_C_ArtTShirt_01_v1_F { displayName = "Abstract"; };
	};
};
class U_C_ArtTShirt_01_v2_F : U_C_ArtTShirt_01_v1_F{};
class U_C_ArtTShirt_01_v3_F : U_C_ArtTShirt_01_v1_F{};
class U_C_ArtTShirt_01_v4_F : U_C_ArtTShirt_01_v1_F{};
class U_C_ArtTShirt_01_v5_F : U_C_ArtTShirt_01_v1_F{};
class U_C_ArtTShirt_01_v6_F : U_C_ArtTShirt_01_v1_F{};

class U_C_Man_casual_6_F : U_C_Poor_1 {
	displayName = "Summer Clothes";
	price = 100;
	class Textures {
		class U_C_Man_casual_6_F { 
			displayName = "Red"; 
			condition = "true";
		};
		class U_C_Man_casual_5_F : U_C_Man_casual_6_F { displayName = "Yellow"; };
		class U_C_Man_casual_4_F : U_C_Man_casual_6_F { displayName = "Sky"; };
	};
};
class U_C_Man_casual_5_F : U_C_Man_casual_6_F{};
class U_C_Man_casual_4_F : U_C_Man_casual_6_F{};

class U_C_man_sport_1_F : U_C_Poor_1 {
	displayName = "Sport Clothes";
	price = 100;
	class Textures {
		class U_C_man_sport_1_F { 
			displayName = "Beach"; 
			condition = "true";
		};
		class U_C_man_sport_2_F : U_C_man_sport_1_F { displayName = "Orange"; };
		class U_C_man_sport_3_F : U_C_man_sport_1_F { displayName = "Blue"; };
	};
};
class U_C_man_sport_2_F : U_C_man_sport_1_F{};
class U_C_man_sport_3_F : U_C_man_sport_1_F{};

class U_C_Scientist : U_C_Poor_1 {
	displayName = "Scientist Clothes";
	price = 100;
	class Textures {
		class U_C_Scientist { 
			displayName = "White Overalls"; 
			condition = "true";
		};
		class U_C_Uniform_Scientist_01_F : U_C_Scientist { displayName = "White"; };
		class U_C_Uniform_Scientist_01_formal_F : U_C_Scientist { displayName = "Blue"; };
		class U_C_Uniform_Scientist_02_F : U_C_Scientist { displayName = "Black"; };
		class U_C_Uniform_Scientist_02_formal_F : U_C_Scientist { displayName = "Red"; };
	};
};
class U_C_Uniform_Scientist_01_F : U_C_Scientist{};
class U_C_Uniform_Scientist_01_formal_F : U_C_Scientist{};
class U_C_Uniform_Scientist_02_F : U_C_Scientist{};
class U_C_Uniform_Scientist_02_formal_F : U_C_Scientist{};

class U_I_C_Soldier_Bandit_1_F : U_C_Poor_1 {
	displayName = "Banit Clothes";
	price = 150;
	virtualSpace = 4;
	class Textures {
		class U_I_C_Soldier_Bandit_1_F { 
			displayName = "Polo Shirt"; 
			condition = "true";
		};
		class U_I_C_Soldier_Bandit_2_F : U_I_C_Soldier_Bandit_1_F { displayName = "Skull"; };
		class U_I_C_Soldier_Bandit_4_F : U_I_C_Soldier_Bandit_1_F { displayName = "Checkered"; };
		class U_I_C_Soldier_Bandit_5_F : U_I_C_Soldier_Bandit_1_F { displayName = "Tank Top"; };
	};
};
class U_I_C_Soldier_Bandit_2_F : U_I_C_Soldier_Bandit_1_F{};
class U_I_C_Soldier_Bandit_4_F : U_I_C_Soldier_Bandit_1_F{};
class U_I_C_Soldier_Bandit_5_F : U_I_C_Soldier_Bandit_1_F{};

class U_I_C_Soldier_Bandit_3_F : U_C_Poor_1 { 
	displayName = "Casual Outfit"; 
	price = 150;
	virtualSpace = 4;
	class Textures {
		class U_I_C_Soldier_Bandit_3_F { 
			displayName = "Brown"; 
			condition = "true";
		};
		class Black : U_I_C_Soldier_Bandit_3_F { 
			displayName = "Black";
			condition = "[] call ULP_fnc_donatorLevel > 0";  
			textures[] = { "\A3\Characters_F_exp\Syndikat\Data\U_I_C_Soldier_Bandit_2_F_2_co.paa" };
		};
		class Red : Black { 
			displayName = "Red"; 
			textures[] = { "\A3\Characters_F_exp\Civil\Data\U_C_Man_casual_6_F_1_co.paa" };
		};
		class Blue : Black { 
			displayName = "Blue"; 
			textures[] = { "\A3\Characters_F_exp\Civil\Data\U_C_Man_casual_4_F_1_co.paa" };
		};
		class Yellow : Black { 
			displayName = "Yellow"; 
			textures[] = { "\A3\Characters_F_exp\Civil\Data\U_C_Man_casual_5_F_1_co.paa" };
		};
	};
};

class U_IG_Guerilla1_1 : U_C_Poor_1 {
	displayName = "Guerilla Clothes";
	price = 150;
	virtualSpace = 4;
	class Textures {
		class U_IG_Guerilla1_1 { 
			displayName = "Garment (Brown)"; 
			condition = "true";
		};
		class U_IG_Guerilla1_2_F : U_IG_Guerilla1_1 { displayName = "Garment (Olive)"; };
		class U_IG_Guerilla2_1 : U_IG_Guerilla1_1 { displayName = "Plain, Dark"; };
		class U_IG_Guerilla2_2 : U_IG_Guerilla1_1 { displayName = "Pattern"; };
		class U_IG_Guerilla2_3 : U_IG_Guerilla1_1 { displayName = "Plain, Light"; };
		class U_IG_Guerilla3_1 : U_IG_Guerilla1_1 { displayName = "Smocks (Dark)"; };
		class U_IG_Guerilla3_2 : U_IG_Guerilla1_1 { displayName = "Smocks (Light)"; };
		class Blackwing : U_IG_Guerilla1_1 {
			displayName = "Blackwing";
			textures[] = { "\a3\characters_f_gamma\Civil\Data\c_cloth1_black.paa" };
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class Black : Blackwing {
			displayName = "Black";
			textures[] = { "\a3\characters_f_gamma\Civil\Data\c_cloth1_black.paa" };
		};
		class Red : Blackwing {
			displayName = "Red";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_bandit_co.paa" };
		};
		class Blue : Blackwing {
			displayName = "Blue";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_co.paa" };
		};
		class Orange : Blackwing {
			displayName = "Orange";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_v3_co.paa" };
		};
		class Yellow : Blackwing {
			displayName = "Yellow";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_v2_co.paa" };
		};
		class Brown : Blackwing {
			displayName = "Brown";
			textures[] = { "\a3\characters_f_gamma\Civil\Data\c_cloth1_brown.paa" };
		};
		class U_IG_leader : U_IG_Guerilla1_1 { displayName = "Uniform"; };
	};
};
class U_IG_Guerilla1_2_F : U_IG_Guerilla1_1 {};
class U_IG_Guerilla2_1 : U_IG_Guerilla1_1 {};
class U_IG_Guerilla2_2 : U_IG_Guerilla1_1 {};
class U_IG_Guerilla2_3 : U_IG_Guerilla1_1 {};
class U_IG_Guerilla3_1 : U_IG_Guerilla1_1 {};
class U_IG_Guerilla3_2 : U_IG_Guerilla1_1 {};
class U_IG_leader : U_IG_Guerilla1_1 {};

class U_C_HunterBody_grn : U_C_Poor_1 {
	displayName = "Hunting Clothes";
	price = 200;
	virtualSpace = 4;
	class Textures {};
};

class U_C_E_LooterJacket_01_F : U_C_Poor_1 {
	displayName = "Looter Clothes";
	price = 150;
	class Textures {
		class U_C_E_LooterJacket_01_F { 
			displayName = "Leather Jacket"; 
			condition = "true";
		};
		class U_I_L_Uniform_01_tshirt_black_F : U_C_E_LooterJacket_01_F { displayName = "T-Shirt, Black"; };
		class U_I_L_Uniform_01_tshirt_sport_F : U_C_E_LooterJacket_01_F { displayName = "T-Shirt, Sport"; };
		class U_I_L_Uniform_01_tshirt_olive_F : U_C_E_LooterJacket_01_F { displayName = "T-Shirt, Olive"; };
		class U_I_L_Uniform_01_tshirt_skull_F : U_C_E_LooterJacket_01_F { 
			displayName = "T-Shirt, Skull"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
	};
};
class U_I_L_Uniform_01_tshirt_skull_F : U_C_E_LooterJacket_01_F {};
class U_I_L_Uniform_01_tshirt_black_F : U_C_E_LooterJacket_01_F {};
class U_I_L_Uniform_01_tshirt_sport_F : U_C_E_LooterJacket_01_F {};
class U_I_L_Uniform_01_tshirt_olive_F : U_C_E_LooterJacket_01_F {};

class U_O_R_Gorka_01_black_F : U_C_Poor_1 {
	displayName = "Tracksuit";
	price = 15000;
	reputation = true;
	virtualSpace = 8;
	class Textures {
		// Police
		class RPU {
			displayName = "RPU";
			textures[] = { "Data\Textures\Uniforms\Police\Units\RPU_tracksuit.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_RPU"", 1] call ULP_fnc_hasAccess }";
		};
		class NCA {
			displayName = "NCA";
			textures[] = { "Data\Textures\Uniforms\Police\Units\NCA_tracksuit.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
		};

		// Medic
		class Paramedic {
			displayName = "Paramedic";
			textures[] = { "Data\Textures\Uniforms\Medic\tracksuit.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class Doctor {
			displayName = "Medical Advisor";
			textures[] = { "Data\Textures\Uniforms\Medic\tracksuit.paa" }; // TODO
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class Commander {
			displayName = "Incident Commander";
			textures[] = { "Data\Textures\Uniforms\Medic\tracksuit.paa" }; // TODO
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 5] call ULP_fnc_hasAccess }";
		};
		/*class HART {
			displayName = "Hazardous Area Response";
			textures[] = { "Data\Textures\Uniforms\Medic\tracksuit.paa" }; // TODO
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_HART"", 1] call ULP_fnc_hasAccess }";
		};*/

		// Highways
		class Hato {
			displayName = "Traffic Officer";
			textures[] = { "Data\Textures\Uniforms\Hato\tracksuit.paa" };
			condition = "[player, [""Hato""]] call ULP_fnc_isFaction";
		};

		// Civilian
		class U_O_R_Gorka_01_black_F {
			displayName = "Black"; 
			condition = "true";
		};
		class U_O_R_Gorka_01_brown_F : U_O_R_Gorka_01_black_F { displayName = "Brown"; };
		class U_O_R_Gorka_01_camo_F : U_O_R_Gorka_01_black_F { displayName = "Camo"; };
	};
};
class U_O_R_Gorka_01_brown_F : U_O_R_Gorka_01_black_F {};
class U_O_R_Gorka_01_camo_F : U_O_R_Gorka_01_black_F {};

class U_I_C_Soldier_Para_1_F : U_O_R_Gorka_01_black_F {
	displayName = "Paramilitary Clothes";
	price = 150;
	class Textures {
		class U_I_C_Soldier_Para_1_F { 
			displayName = "Tee"; 
			condition = "true";
		};
		class U_I_C_Soldier_Para_2_F : U_I_C_Soldier_Para_1_F { displayName = "Jacket"; };
		class U_I_C_Soldier_Para_3_F : U_I_C_Soldier_Para_1_F { displayName = "Shirt"; };
		class U_I_C_Soldier_Para_4_F : U_I_C_Soldier_Para_1_F { displayName = "Tank Top"; };
		class U_I_C_Soldier_Para_5_F : U_I_C_Soldier_Para_1_F { 
			displayName = "Shorts"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
	};
};
class U_I_C_Soldier_Para_2_F : U_I_C_Soldier_Para_1_F {};
class U_I_C_Soldier_Para_3_F : U_I_C_Soldier_Para_1_F {};
class U_I_C_Soldier_Para_4_F : U_I_C_Soldier_Para_1_F {};
class U_I_C_Soldier_Para_5_F : U_I_C_Soldier_Para_1_F {};

class U_I_E_Uniform_01_F : U_O_R_Gorka_01_black_F {
	displayName = "Geometric Clothes";
	price = 150;
	class Textures {
		class U_I_E_Uniform_01_F { 
			displayName = "Jacket"; 
			condition = "true";
		};
		class U_I_E_Uniform_01_shortsleeve_F : U_I_E_Uniform_01_F { displayName = "Jacket (Rolled)"; };
		class U_I_L_Uniform_01_camo_F : U_I_E_Uniform_01_F { displayName = "Camo"; };
		class U_I_E_Uniform_01_sweater_F : U_I_E_Uniform_01_F { displayName = "Sweater"; };
		class U_I_L_Uniform_01_deserter_F : U_I_E_Uniform_01_F { displayName = "T-Shirt"; };
		class U_I_E_Uniform_01_tanktop_F : U_I_E_Uniform_01_F { displayName = "Tank Top"; };
		class U_I_E_Uniform_01_officer_F : U_I_E_Uniform_01_F { 
			displayName = "Officer"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
	};
};
class U_I_E_Uniform_01_shortsleeve_F : U_I_E_Uniform_01_F {};
class U_I_L_Uniform_01_camo_F : U_I_E_Uniform_01_F {};
class U_I_E_Uniform_01_sweater_F : U_I_E_Uniform_01_F {};
class U_I_L_Uniform_01_deserter_F : U_I_E_Uniform_01_F {};
class U_I_E_Uniform_01_tanktop_F : U_I_E_Uniform_01_F {};
class U_I_E_Uniform_01_officer_F : U_I_E_Uniform_01_F {};

class U_B_Wetsuit : U_O_R_Gorka_01_black_F {
	displayName = "Wetsuits";
	price = 2500;
	virtualSpace = 0;
	class Textures {
		// Police
		class MPU {
			displayName = "MPU";
			textures[] = { "Data\Textures\Uniforms\Police\Units\MPU.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_MPU"", 1] call ULP_fnc_hasAccess }";
		};

		// Civilian
		class U_B_Wetsuit { 
			displayName = "Black"; 
			condition = "true";
		};
		class U_O_Wetsuit : U_B_Wetsuit { displayName = "Brown"; };
		class U_I_Wetsuit : U_B_Wetsuit { displayName = "Green"; };
	};
};
class U_O_Wetsuit : U_B_Wetsuit{};
class U_I_Wetsuit : U_B_Wetsuit{};

class U_Marshal : U_C_Poor_1 {
	displayName = "Protection Uniform";
	price = 1000;
	class Textures {};
};

class U_C_Driver_1_black : U_C_Poor_1 {
	displayName = "Driver Clothes";
	price = 500;
	class Textures {
		class U_C_Driver_1_black { 
			displayName = "Black"; 
			condition = "true";
		};
		class U_C_Driver_1_blue : U_C_Driver_1_black { displayName = "Blue"; };
		class U_C_Driver_1_green : U_C_Driver_1_black { displayName = "Green"; };
		class U_C_Driver_1_red : U_C_Driver_1_black { displayName = "Red"; };
		class U_C_Driver_1_white : U_C_Driver_1_black { displayName = "White"; };
		class U_C_Driver_1_yellow : U_C_Driver_1_black { displayName = "Yellow"; };
		class U_C_Driver_1_orange : U_C_Driver_1_black { displayName = "Orange"; };
		class U_C_Driver_1 : U_C_Driver_1_black { 
			displayName = "Fuel"; 
			condition = "[] call ULP_fnc_donatorLevel > 0";
		};
		class U_C_Driver_2 : U_C_Driver_1 { displayName = "Bluking"; };
		class U_C_Driver_3 : U_C_Driver_1 { displayName = "Redstone"; };
		class U_C_Driver_4 : U_C_Driver_1 { displayName = "Vrana"; };
	};
};
class U_C_Driver_1_blue : U_C_Driver_1_black{};
class U_C_Driver_1_green : U_C_Driver_1_black{};
class U_C_Driver_1_red : U_C_Driver_1_black{};
class U_C_Driver_1_white : U_C_Driver_1_black{};
class U_C_Driver_1_yellow : U_C_Driver_1_black{};
class U_C_Driver_1_orange : U_C_Driver_1_black{};
class U_C_Driver_1 : U_C_Driver_1_black{};
class U_C_Driver_2 : U_C_Driver_1_black{};
class U_C_Driver_3 : U_C_Driver_1_black{};
class U_C_Driver_4 : U_C_Driver_1_black{};

class U_C_IDAP_Man_shorts_F : U_C_Poor_1 {
	displayName = "IDAP Clothes";
	price = 500;
	class Textures {
		class U_C_IDAP_Man_shorts_F { 
			displayName = "Polo, Shorts"; 
			condition = "true";
		};
		class U_C_IDAP_Man_casual_F : U_C_IDAP_Man_shorts_F { displayName = "Polo"; };
		class U_C_IDAP_Man_cargo_F : U_C_IDAP_Man_shorts_F { displayName = "Cargo"; };
		class U_C_IDAP_Man_Tee_F : U_C_IDAP_Man_shorts_F { displayName = "Tee"; };
		class U_C_IDAP_Man_Jeans_F : U_C_IDAP_Man_shorts_F { displayName = "Jeans"; };
		class U_C_IDAP_Man_TeeShorts_F : U_C_IDAP_Man_shorts_F { displayName = "Tee, Shorts"; };
	};
};
class U_C_IDAP_Man_casual_F : U_C_IDAP_Man_shorts_F{};
class U_C_IDAP_Man_cargo_F : U_C_IDAP_Man_shorts_F{ };
class U_C_IDAP_Man_Tee_F : U_C_IDAP_Man_shorts_F{
	class Textures {
		class HMP {
			displayName = "HMP";
			textures[] = { "Data\Textures\Uniforms\Global\hmp_uniform.paa" };
			condition = "true";
		};
	};
};
class U_C_IDAP_Man_Jeans_F : U_C_IDAP_Man_shorts_F{};
class U_C_IDAP_Man_TeeShorts_F : U_C_IDAP_Man_shorts_F{};

class U_C_Journalist : U_C_Poor_1 {
	price = 100;
	class Textures {};
};

class U_Rangemaster : U_C_Poor_1 {
	displayName = "Patrol Uniform";
	price = 100;
	class Textures {
		class CC {
			displayName = "Chief Constable";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\CC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 11] call ULP_fnc_hasAccess }";
		};
		class DCC {
			displayName = "Deputy Chief Constable";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\DCC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 10] call ULP_fnc_hasAccess }";
		};
		class CSU {
			displayName = "Chief Superindendent";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\CSU.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 9] call ULP_fnc_hasAccess }";
		};
		class SU {
			displayName = "Superindendent";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\SU.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 8] call ULP_fnc_hasAccess }";
		};
		class CI {
			displayName = "Chief Inspector";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\CI.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 7] call ULP_fnc_hasAccess }";
		};
		class PI {
			displayName = "Police Inspector";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\PI.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 6] call ULP_fnc_hasAccess }";
		};
		class PS {
			displayName = "Police Sergeant";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\PS.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 5] call ULP_fnc_hasAccess }";
		};
		class SC {
			displayName = "Senior Police Constable";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\SC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class PC {
			displayName = "Police Constable";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\PC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class PCSO {
			displayName = "Police Community Support Officer";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\PCSO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		};
		class SEG {
			displayName = "Special Escort Group";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SEG.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SEG"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_Competitor : U_C_Poor_1 {
	displayName = "Response Uniform";
	price = 100;
	virtualSpace = 12;
	class Textures {
		class DR {
			displayName = "Consultant";
			textures[] = { "Data\Textures\Uniforms\Medic\main_03.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 5] call ULP_fnc_hasAccess }";
		};
		class PAR {
			displayName = "Doctor";
			textures[] = { "Data\Textures\Uniforms\Medic\main_02.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class STU {
			displayName = "Student";
			textures[] = { "Data\Textures\Uniforms\Medic\main_01.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_B_GEN_Commander_F : U_C_Poor_1 {
	displayName = "Patrol Jumper";
	price = 200;
	class Textures {
		class College {
			displayName = "College of Policing";
			textures[] = { "Data\Textures\Uniforms\Police\Units\COL.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_COL"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_BG_Guerrilla_6_1 : U_B_GEN_Commander_F {
	displayName = "NCA Jumper";
	class Textures {
		class NCA {
			displayName = "NCA";
			textures[] = { "Data\Textures\Uniforms\Police\Units\NCA_main.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_OrestesBody : U_C_Poor_1 {
	displayName = "New Look";
	price = 1000;
	class Textures {};
};

class U_NikosBody : U_C_Poor_1 {
	displayName = "Casual Look";
	price = 1000;
	class Textures {};
};

class U_NikosAgedBody : U_C_Poor_1 {
	displayName = "Fine Suit";
	price = 3500;
	class Textures {};
};

class U_C_FormalSuit_01_tshirt_black_F : U_C_Poor_1 {
	displayName = "Formal Suit, T-Shirt";
	price = 5000;
	class Textures {
		class U_C_FormalSuit_01_tshirt_black_F { 
			displayName = "Black"; 
			condition = "true";
		};
		class U_C_FormalSuit_01_tshirt_gray_F : U_C_FormalSuit_01_tshirt_black_F { displayName = "Gray"; };

		// Group
		class Ridge : U_C_FormalSuit_01_tshirt_gray_F {
			displayName = "Ridge Formal Uniform";
			textures[] = { "Data\Textures\Groups\Ridge\U_C_FormalSuit_01_tshirt_gray_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_C_FormalSuit_01_tshirt_gray_F : U_C_FormalSuit_01_tshirt_black_F {};

class U_C_FormalSuit_01_black_F : U_C_Poor_1 {
	displayName = "Formal Suit";
	price = 6000;
	class Textures {
		class U_C_FormalSuit_01_black_F { 
			displayName = "Black"; 
			condition = "true";
		};
		class U_C_FormalSuit_01_gray_F : U_C_FormalSuit_01_black_F { displayName = "Gray"; };
		class U_C_FormalSuit_01_blue_F : U_C_FormalSuit_01_black_F { displayName = "Blue"; };
		class U_C_FormalSuit_01_khaki_F : U_C_FormalSuit_01_black_F { 
			displayName = "Khaki";
			condition = "[] call ULP_fnc_donatorLevel > 0";  
		};
	};
};
class U_C_FormalSuit_01_gray_F : U_C_FormalSuit_01_black_F {};
class U_C_FormalSuit_01_blue_F : U_C_FormalSuit_01_black_F {};
class U_C_FormalSuit_01_khaki_F : U_C_FormalSuit_01_black_F {};

class U_I_ParadeUniform_01_AAF_decorated_F : U_C_Poor_1 {
	displayName = "Command Parade Uniform";
	price = 10000;
	class Textures {
		class Command { 
			displayName = "Parade Uniform";
			textures[] = { 
				"Data\Textures\Uniforms\Police\parade_01.paa",
				"Data\Textures\Uniforms\Police\parade_02.paa",
				"Data\Textures\Uniforms\Police\parade_03.paa"
			};
			condition = "true";
		};
	};
};
class U_I_ParadeUniform_01_AAF_F : U_I_ParadeUniform_01_AAF_decorated_F {
	displayName = "Parade Uniform";
	class Textures {
		class Main { 
			displayName = "Parade Uniform";
			condition = "true";
			textures[] = { 
				"Data\Textures\Uniforms\Police\parade_01.paa",
				"Data\Textures\Uniforms\Police\parade_02.paa",
				"Data\Textures\Uniforms\Police\parade_03.paa"
			};
		};
	};
};

class U_B_survival_uniform : U_C_Poor_1 {
	price = 15000;
	reputation = true;
	class Textures {
		// Civilian
		class U_B_survival_uniform { 
			displayName = "MTP"; 
			condition = "true";
		};

		// Group
		class Ridge : U_B_survival_uniform {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class KLR : U_B_survival_uniform {
			displayName = "KLR";
			textures[] = { "Data\Textures\Groups\KLR\U_B_CTRG_Soldier_F.paa" };
			condition = "[31] call ULP_fnc_isGroupPremium";
		};
		class Relic : U_B_survival_uniform {
			displayName = "Relic";
			textures[] = { "Data\Textures\Groups\Relic\U_B_CTRG_Soldier_F.paa" };
			condition = "[27] call ULP_fnc_isGroupPremium";
		};
		class Vulcan : U_B_survival_uniform {
			displayName = "Vulcan";
			textures[] = { "Data\Textures\Groups\Vulcan\U_B_CTRG_Soldier_F.paa" };
			condition = "[11] call ULP_fnc_isGroupPremium";
		};
		class NOHON : U_B_survival_uniform {
			displayName = "NO HONOR";
			textures[] = { "Data\Textures\Groups\NOHON\U_B_CTRG_Soldier_F.paa" };
			condition = "[19] call ULP_fnc_isGroupPremium";
		};
		class TwoPointNine : U_B_survival_uniform {
			displayName = "2.9";
			textures[] = { "Data\Textures\Groups\TwoPointNine\U_B_CTRG_Soldier_F.paa" };
			condition = "[92] call ULP_fnc_isGroupPremium";
		};
	};
};

class U_B_CombatUniform_mcam_worn : U_B_survival_uniform {
	displayName = "Traffic Uniform";
	price = 1000;
	virtualSpace = 4;
	class Textures {
		class RPU {
			displayName = "Traffic Uniform";
			textures[] = { "Data\Textures\Uniforms\Police\Units\RPU_main.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_RPU"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_I_CombatUniform : U_B_survival_uniform {
	displayName = "Combat Fatigues";
	price = 1500;
	virtualSpace = 4;
	class Textures {
		class U_I_CombatUniform { 
			displayName = "AAF (Base)"; 
			condition = "true";
		};
		class U_I_CombatUniform_shortsleeve : U_I_CombatUniform { displayName = "AAF (Rolled)"; };
	};
};
class U_I_CombatUniform_shortsleeve : U_I_CombatUniform {};

class U_B_CombatUniform_mcam : U_B_survival_uniform {
	displayName = "Combat Clothes";
	price = 1500;
	virtualSpace = 4;
	class Textures {
		// Civilian
		class U_B_CombatUniform_mcam { 
			displayName = "MTP"; 
			condition = "true";
		};
		class U_B_CombatUniform_mcam_wdl_f : U_B_CombatUniform_mcam { displayName = "WDL"; };
		class U_B_T_Solider_F : U_B_CombatUniform_mcam { displayName = "Tropic"; };

		// Group
		class Ridge : U_B_CombatUniform_mcam {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class KLR : U_B_CombatUniform_mcam {
			displayName = "KLR";
			textures[] = { "Data\Textures\Groups\KLR\U_B_CTRG_Soldier_F.paa" };
			condition = "[31] call ULP_fnc_isGroupPremium";
		};
		class Relic : U_B_CombatUniform_mcam {
			displayName = "Relic";
			textures[] = { "Data\Textures\Groups\Relic\U_B_CTRG_Soldier_F.paa" };
			condition = "[27] call ULP_fnc_isGroupPremium";
		};
		class Vulcan : U_B_CombatUniform_mcam {
			displayName = "Vulcan";
			textures[] = { "Data\Textures\Groups\Vulcan\U_B_CTRG_Soldier_F.paa" };
			condition = "[11] call ULP_fnc_isGroupPremium";
		};
		class NOHON : U_B_CombatUniform_mcam {
			displayName = "NO HONOR";
			textures[] = { "Data\Textures\Groups\NOHON\U_B_CTRG_Soldier_F.paa" };
			condition = "[19] call ULP_fnc_isGroupPremium";
		};
		class TwoPointNine : U_B_CombatUniform_mcam {
			displayName = "2.9";
			textures[] = { "Data\Textures\Groups\TwoPointNine\U_B_CTRG_Soldier_F.paa" };
			condition = "[92] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CombatUniform_mcam_wdl_f : U_B_CombatUniform_mcam {};
class U_B_T_Solider_F : U_B_CombatUniform_mcam {};

class U_B_CombatUniform_mcam_vest : U_B_CombatUniform_mcam {
	displayName = "Combat Clothes (Rolled)";
	class Textures {
		// Civilian
		class U_B_CombatUniform_mcam_vest { 
			displayName = "MTP"; 
			condition = "true";
		};
		class U_B_CombatUniform_vest_mcam_wdl_f : U_B_CombatUniform_mcam_vest { displayName = "WDL"; };
		class U_B_T_Solider_SL_F : U_B_CombatUniform_mcam_vest { displayName = "Tropic"; };

		// Group
		class Ridge : U_B_CombatUniform_mcam_vest {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class KLR : U_B_CombatUniform_mcam_vest {
			displayName = "KLR";
			textures[] = { "Data\Textures\Groups\KLR\U_B_CTRG_Soldier_F.paa" };
			condition = "[31] call ULP_fnc_isGroupPremium";
		};
		class Relic : U_B_CombatUniform_mcam_vest {
			displayName = "Relic";
			textures[] = { "Data\Textures\Groups\Relic\U_B_CTRG_Soldier_F.paa" };
			condition = "[27] call ULP_fnc_isGroupPremium";
		};
		class Vulcan : U_B_CombatUniform_mcam_vest {
			displayName = "Vulcan";
			textures[] = { "Data\Textures\Groups\Vulcan\U_B_CTRG_Soldier_F.paa" };
			condition = "[11] call ULP_fnc_isGroupPremium";
		};
		class NOHON : U_B_CombatUniform_mcam_vest {
			displayName = "NO HONOR";
			textures[] = { "Data\Textures\Groups\NOHON\U_B_CTRG_Soldier_F.paa" };
			condition = "[19] call ULP_fnc_isGroupPremium";
		};
		class TwoPointNine : U_B_CombatUniform_mcam_vest {
			displayName = "2.9";
			textures[] = { "Data\Textures\Groups\TwoPointNine\U_B_CTRG_Soldier_F.paa" };
			condition = "[92] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CombatUniform_vest_mcam_wdl_f : U_B_CombatUniform_mcam {};
class U_B_T_Solider_SL_F : U_B_CombatUniform_mcam {};

class U_B_CombatUniform_mcam_tshirt : U_B_CombatUniform_mcam {
	displayName = "Combat Clothes (Tee)";
	class Textures {
		// Civilian
		class U_B_CombatUniform_mcam_tshirt { 
			displayName = "MTP (Base)"; 
			condition = "true";
		};
		class U_B_CombatUniform_tshirt_mcam_wdL_f : U_B_CombatUniform_mcam_tshirt { displayName = "WDL"; };
		class U_B_T_Solider_AR_F : U_B_CombatUniform_mcam_tshirt { displayName = "Tropic"; };

		// Group
		class Ridge : U_B_CombatUniform_mcam_tshirt {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class KLR : U_B_CombatUniform_mcam_tshirt {
			displayName = "KLR";
			textures[] = { "Data\Textures\Groups\KLR\U_B_CTRG_Soldier_F.paa" };
			condition = "[31] call ULP_fnc_isGroupPremium";
		};
		class Relic : U_B_CombatUniform_mcam_tshirt {
			displayName = "Relic";
			textures[] = { "Data\Textures\Groups\Relic\U_B_CTRG_Soldier_F.paa" };
			condition = "[27] call ULP_fnc_isGroupPremium";
		};
		class Vulcan : U_B_CombatUniform_mcam_tshirt {
			displayName = "Vulcan";
			textures[] = { "Data\Textures\Groups\Vulcan\U_B_CTRG_Soldier_F.paa" };
			condition = "[11] call ULP_fnc_isGroupPremium";
		};
		class NOHON : U_B_CombatUniform_mcam_tshirt {
			displayName = "NO HONOR";
			textures[] = { "Data\Textures\Groups\NOHON\U_B_CTRG_Soldier_F.paa" };
			condition = "[19] call ULP_fnc_isGroupPremium";
		};
		class TwoPointNine : U_B_CombatUniform_mcam_tshirt {
			displayName = "2.9";
			textures[] = { "Data\Textures\Groups\TwoPointNine\U_B_CTRG_Soldier_F.paa" };
			condition = "[92] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CombatUniform_tshirt_mcam_wdL_f : U_B_CombatUniform_mcam {};
class U_B_T_Solider_AR_F : U_B_CombatUniform_mcam {};

class U_B_CTRG_Soldier_F : U_B_survival_uniform {
	displayName = "Stealth Uniform";
	price = 45000;
	virtualSpace = 4;
	class Textures {
		// Police
		class SCO19 {
			displayName = "SCO19 Uniform";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SCO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SCO"", 1] call ULP_fnc_hasAccess }";
		};

		// Civilian
		class U_B_CTRG_Soldier_F {
			displayName = "Tropic";
			condition = "true";
		};
		class U_B_CTRG_Soldier_Arid_F : U_B_CTRG_Soldier_F { displayName = "Arid"; };
		class U_B_CTRG_Soldier_urb_1_F : U_B_CTRG_Soldier_F { displayName = "Urban"; };

		// Group
		class Ridge : U_B_CTRG_Soldier_F {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class KLR : U_B_CTRG_Soldier_F {
			displayName = "KLR";
			textures[] = { "Data\Textures\Groups\KLR\U_B_CTRG_Soldier_F.paa" };
			condition = "[31] call ULP_fnc_isGroupPremium";
		};
		class Relic : U_B_CTRG_Soldier_F {
			displayName = "Relic";
			textures[] = { "Data\Textures\Groups\Relic\U_B_CTRG_Soldier_F.paa" };
			condition = "[27] call ULP_fnc_isGroupPremium";
		};
		class Vulcan : U_B_CombatUniform_mcam {
			displayName = "Vulcan";
			textures[] = { "Data\Textures\Groups\Vulcan\U_B_CTRG_Soldier_F.paa" };
			condition = "[11] call ULP_fnc_isGroupPremium";
		};
		class NOHON : U_B_CombatUniform_mcam {
			displayName = "NO HONOR";
			textures[] = { "Data\Textures\Groups\NOHON\U_B_CTRG_Soldier_F.paa" };
			condition = "[19] call ULP_fnc_isGroupPremium";
		};
		class TwoPointNine : U_B_CombatUniform_mcam {
			displayName = "2.9";
			textures[] = { "Data\Textures\Groups\TwoPointNine\U_B_CTRG_Soldier_F.paa" };
			condition = "[92] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CTRG_Soldier_Arid_F : U_B_CTRG_Soldier_F {};
class U_B_CTRG_Soldier_urb_1_F : U_B_CTRG_Soldier_F {};

class U_B_CTRG_Soldier_3_F : U_B_CTRG_Soldier_F {
	displayName = "Stealth Uniform (Rolled)";
	class Textures {
		// Police
		class SCO19 {
			displayName = "SCO19 Uniform";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SCO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SCO"", 2] call ULP_fnc_hasAccess }";
		};

		// Civilian
		class U_B_CTRG_Soldier_3_F { 
			displayName = "Tropic"; 
			condition = "true";
		};
		class U_B_CTRG_Soldier_3_Arid_F : U_B_CTRG_Soldier_3_F { displayName = "Arid"; };
		class U_B_CTRG_Soldier_urb_3_F : U_B_CTRG_Soldier_3_F { displayName = "Urban"; };

		// Group
		class Ridge : U_B_CTRG_Soldier_3_F {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class KLR : U_B_CTRG_Soldier_3_F {
			displayName = "KLR";
			textures[] = { "Data\Textures\Groups\KLR\U_B_CTRG_Soldier_F.paa" };
			condition = "[31] call ULP_fnc_isGroupPremium";
		};
		class Relic : U_B_CTRG_Soldier_3_F {
			displayName = "Relic";
			textures[] = { "Data\Textures\Groups\Relic\U_B_CTRG_Soldier_F.paa" };
			condition = "[27] call ULP_fnc_isGroupPremium";
		};
		class Vulcan : U_B_CTRG_Soldier_3_F {
			displayName = "Vulcan";
			textures[] = { "Data\Textures\Groups\Vulcan\U_B_CTRG_Soldier_F.paa" };
			condition = "[11] call ULP_fnc_isGroupPremium";
		};
		class NOHON : U_B_CTRG_Soldier_3_F {
			displayName = "NO HONOR";
			textures[] = { "Data\Textures\Groups\NOHON\U_B_CTRG_Soldier_F.paa" };
			condition = "[19] call ULP_fnc_isGroupPremium";
		};
		class TwoPointNine : U_B_CTRG_Soldier_3_F {
			displayName = "2.9";
			textures[] = { "Data\Textures\Groups\TwoPointNine\U_B_CTRG_Soldier_F.paa" };
			condition = "[92] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CTRG_Soldier_3_Arid_F : U_B_CTRG_Soldier_3_F {};
class U_B_CTRG_Soldier_urb_3_F : U_B_CTRG_Soldier_3_F {};

class U_B_CTRG_Soldier_2_Arid_F : U_B_CTRG_Soldier_F {
	displayName = "Stealth Uniform (Tee)";
	class Textures {
		// Police
		class SCO19 {
			displayName = "SCO19 Uniform";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SCO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SCO"", 3] call ULP_fnc_hasAccess }";
		};

		// Civilian
		class U_B_CTRG_Soldier_2_Arid_F { 
			displayName = "Arid"; 
			condition = "true";
		};
		class U_B_CTRG_Soldier_2_F : U_B_CTRG_Soldier_2_Arid_F { displayName = "Tropic"; };
		class U_B_CTRG_Soldier_urb_2_F : U_B_CTRG_Soldier_2_Arid_F { displayName = "Urban"; };

		// Group
		class Ridge : U_B_CTRG_Soldier_2_Arid_F {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class KLR : U_B_CTRG_Soldier_2_Arid_F {
			displayName = "KLR";
			textures[] = { "Data\Textures\Groups\KLR\U_B_CTRG_Soldier_F.paa" };
			condition = "[31] call ULP_fnc_isGroupPremium";
		};
		class Relic : U_B_CTRG_Soldier_2_Arid_F {
			displayName = "Relic";
			textures[] = { "Data\Textures\Groups\Relic\U_B_CTRG_Soldier_F.paa" };
			condition = "[27] call ULP_fnc_isGroupPremium";
		};
		class Vulcan : U_B_CTRG_Soldier_2_Arid_F {
			displayName = "Vulcan";
			textures[] = { "Data\Textures\Groups\Vulcan\U_B_CTRG_Soldier_F.paa" };
			condition = "[11] call ULP_fnc_isGroupPremium";
		};
		class NOHON : U_B_CTRG_Soldier_2_Arid_F {
			displayName = "NO HONOR";
			textures[] = { "Data\Textures\Groups\NOHON\U_B_CTRG_Soldier_F.paa" };
			condition = "[19] call ULP_fnc_isGroupPremium";
		};
		class TwoPointNine : U_B_CTRG_Soldier_2_Arid_F {
			displayName = "2.9";
			textures[] = { "Data\Textures\Groups\TwoPointNine\U_B_CTRG_Soldier_F.paa" };
			condition = "[92] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CTRG_Soldier_2_F : U_B_CTRG_Soldier_2_Arid_F {};
class U_B_CTRG_Soldier_urb_2_F : U_B_CTRG_Soldier_2_Arid_F {};

class U_B_GhillieSuit : U_B_survival_uniform {
	displayName = "Half-Ghillies";
	price = 100000;
	virtualSpace = 4;
	isMask = true;
	class Textures {
		// Police
		class SCO19 {
			displayName = "SCO19 Ghillie";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SCO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SCO"", 2] call ULP_fnc_hasAccess }";
		};

		// Civilian
		class U_B_GhillieSuit { 
			displayName = "MTP"; 
			condition = "true";
		};
		class U_O_GhillieSuit : U_B_GhillieSuit { displayName = "Hex"; };
		class U_I_GhillieSuit : U_B_GhillieSuit { displayName = "Digi"; };
		class U_B_T_Sniper_F : U_B_GhillieSuit { displayName = "Tropic"; };

		// Group
		class Ridge : U_B_GhillieSuit {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class KLR : U_B_GhillieSuit {
			displayName = "KLR";
			textures[] = { "Data\Textures\Groups\KLR\U_B_CTRG_Soldier_F.paa" };
			condition = "[31] call ULP_fnc_isGroupPremium";
		};
		class Relic : U_B_GhillieSuit {
			displayName = "Relic";
			textures[] = { "Data\Textures\Groups\Relic\U_B_CTRG_Soldier_F.paa" };
			condition = "[27] call ULP_fnc_isGroupPremium";
		};
		class Vulcan : U_B_GhillieSuit {
			displayName = "Vulcan";
			textures[] = { "Data\Textures\Groups\Vulcan\U_B_CTRG_Soldier_F.paa" };
			condition = "[11] call ULP_fnc_isGroupPremium";
		};
		class NOHON : U_B_GhillieSuit {
			displayName = "NO HONOR";
			textures[] = { "Data\Textures\Groups\NOHON\U_B_CTRG_Soldier_F.paa" };
			condition = "[19] call ULP_fnc_isGroupPremium";
		};
		class TwoPointNine : U_B_GhillieSuit {
			displayName = "2.9";
			textures[] = { "Data\Textures\Groups\TwoPointNine\U_B_CTRG_Soldier_F.paa" };
			condition = "[92] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_O_GhillieSuit : U_B_GhillieSuit {};
class U_I_GhillieSuit : U_B_GhillieSuit {};
class U_B_T_Sniper_F : U_B_GhillieSuit {};

class U_B_FullGhillie_ard : U_B_GhillieSuit {
	displayName = "Full-Ghillies";
	price = 150000;
	class Textures {
		class U_B_FullGhillie_ard { 
			displayName = "Arid"; 
			condition = "true";
		};
		class U_B_FullGhillie_sard : U_B_FullGhillie_ard { displayName = "Semi-Arid"; };
		class U_B_FullGhillie_lsh : U_B_FullGhillie_ard { displayName = "Lush"; };
		class U_B_T_FullGhillie_tna_F : U_B_FullGhillie_ard { displayName = "Jungle"; };
	};
};
class U_B_FullGhillie_sard : U_B_FullGhillie_ard {};
class U_B_FullGhillie_lsh : U_B_FullGhillie_ard {};
class U_B_T_FullGhillie_tna_F : U_B_FullGhillie_ard {};

class U_B_HeliPilotCoveralls : U_B_survival_uniform {
	displayName = "Flight Clothes";
	price = 5000;
	virtualSpace = 4;
	class Textures {
		class U_B_HeliPilotCoveralls { 
			displayName = "Green"; 
			condition = "true";
		};
		class U_I_HeliPilotCoveralls : U_B_HeliPilotCoveralls { displayName = "Tan"; };
		class U_I_E_Uniform_01_coveralls_F : U_B_HeliPilotCoveralls { displayName = "Geometric"; };
	};
};
class U_I_HeliPilotCoveralls : U_B_HeliPilotCoveralls {};
class U_I_E_Uniform_01_coveralls_F : U_B_HeliPilotCoveralls {};

class U_O_PilotCoveralls : U_B_survival_uniform {
	displayName = "Flight Clothes";
	price = 20000;
	virtualSpace = 8;
	class Textures {
		// Police
		class NPAS {
			displayName = "NPAS Uniform";
			textures[] = { "Data\Textures\Uniforms\Police\Units\NPAS.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_NPAS"", 1] call ULP_fnc_hasAccess }";
		};

		// Medic
		class AAA {
			displayName = "AAA Uniform";
			textures[] = { "Data\Textures\Uniforms\Medic\aa.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_AA"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_C_CBRN_Suit_01_White_F : U_B_survival_uniform {
	displayName = "CBRN Suits";
	price = 50000;
	isGas = true;
	class Textures {
		class U_C_CBRN_Suit_01_White_F { 
			displayName = "White"; 
			condition = "true";
		};
		class U_C_CBRN_Suit_01_Blue_F : U_C_CBRN_Suit_01_White_F { displayName = "Blue"; };
		class U_B_CBRN_Suit_01_MTP_F : U_C_CBRN_Suit_01_White_F { displayName = "MTP"; };
		class U_B_CBRN_Suit_01_Wdl_F : U_C_CBRN_Suit_01_White_F { displayName = "WDL"; };
		class U_I_CBRN_Suit_01_AAF_F : U_C_CBRN_Suit_01_White_F { displayName = "DIGI"; };
		class U_I_E_CBRN_Suit_01_EAF_F : U_C_CBRN_Suit_01_White_F { displayName = "LDF"; };
		class U_I_CBRN_Suit_01_Tropic_F : U_C_CBRN_Suit_01_White_F { displayName = "Tropic"; };
	};
};
class U_C_CBRN_Suit_01_Blue_F : U_C_CBRN_Suit_01_White_F {};
class U_B_CBRN_Suit_01_MTP_F : U_C_CBRN_Suit_01_White_F {};
class U_B_CBRN_Suit_01_Wdl_F : U_C_CBRN_Suit_01_White_F {};
class U_I_CBRN_Suit_01_AAF_F : U_C_CBRN_Suit_01_White_F {};
class U_I_E_CBRN_Suit_01_EAF_F : U_C_CBRN_Suit_01_White_F {};
class U_I_CBRN_Suit_01_Tropic_F : U_C_CBRN_Suit_01_White_F {};

class U_C_Protagonist_VR : U_B_survival_uniform {
	displayName = "Staff Suits";
	price = 1000000;
	virtualSpace = 100;
	isGas = true;
	class Textures {
		class U_C_Protagonist_VR { 
			displayName = "Purple"; 
			condition = "true";
		};
		class Black : U_C_Protagonist_VR {
			displayName = "Black"; 
			textures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
		};
		class Gray : U_C_Protagonist_VR { 
			displayName = "Gray"; 
			textures[] = { "\A3\Characters_F\Common\Data\basicbody_grey_co.paa" };
		};
		class U_O_Protagonist_VR : U_C_Protagonist_VR { displayName = "Red"; };
		class U_B_Protagonist_VR : U_C_Protagonist_VR { displayName = "Blue"; };
		class DullBlue : U_C_Protagonist_VR { 
			displayName = "Dull Blue"; 
			textures[] = { "\A3\Characters_F\Common\Data\basicbody_blue_co.paa" };
		};
		class U_I_Protagonist_VR : U_C_Protagonist_VR { displayName = "Green"; };
		class DullGreen : U_C_Protagonist_VR { 
			displayName = "Dull Green"; 
			textures[] = { "\A3\Characters_F\Common\Data\basicbody_green_co.paa" };
		};
		class Brown : U_C_Protagonist_VR { 
			displayName = "Brown"; 
			textures[] = { "\A3\Characters_F\Common\Data\basicbody_brown_co.paa" };
		};
	};
};
class U_O_Protagonist_VR : U_C_Protagonist_VR {};
class U_B_Protagonist_VR : U_C_Protagonist_VR {};
class U_I_Protagonist_VR : U_C_Protagonist_VR {};
