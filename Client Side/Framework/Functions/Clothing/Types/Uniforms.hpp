class U_C_Poor_1 {
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {};
};
class U_C_Farmer : U_C_Poor_1{};
class U_C_Mechanic_01_F : U_C_Poor_1{};

class U_C_Poloshirt_blue {
	displayName = "Commoner Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
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
		class GroupUniform : U_C_Poloshirt_blue {
			displayName = "Group Uniform";
			textures[] = { "#(rgb,8,8,3)color(1,0,0,1)" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_C_Poloshirt_burgundy : U_C_Poloshirt_blue{};
class U_C_Poloshirt_stripped : U_C_Poloshirt_blue{};
class U_C_Poloshirt_tricolour : U_C_Poloshirt_blue{};
class U_C_Poloshirt_salmon : U_C_Poloshirt_blue{};
class U_C_Poloshirt_redwhite : U_C_Poloshirt_blue{};

class U_C_WorkerOveralls {
	displayName = "Worker Overalls";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_C_WorkerOveralls { 
			displayName = "Used"; 
			condition = "true";
		};
		class U_C_ConstructionCoverall_Black_F : U_C_WorkerOveralls { displayName = "Black"; };
		class U_C_ConstructionCoverall_Red_F : U_C_WorkerOveralls { displayName = "Red"; };
		class U_C_ConstructionCoverall_Blue_F : U_C_WorkerOveralls { displayName = "Blue"; };
		class U_C_ConstructionCoverall_Vrana_F : U_C_WorkerOveralls { displayName = "Vrana"; };
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
class U_C_ConstructionCoverall_Black_F : U_C_WorkerOveralls{};
class U_C_ConstructionCoverall_Red_F : U_C_WorkerOveralls{};
class U_C_ConstructionCoverall_Blue_F : U_C_WorkerOveralls{};
class U_C_ConstructionCoverall_Vrana_F : U_C_WorkerOveralls{};

class U_C_Man_casual_1_F {
	displayName = "Casual Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
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

class U_C_ArtTShirt_01_v1_F {
	displayName = "Casual T-Shirts";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_C_ArtTShirt_01_v1_F { 
			displayName = "Art of War"; 
			condition = "true";
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

class U_C_Man_casual_6_F {
	displayName = "Summer Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
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

class U_C_man_sport_1_F {
	displayName = "Sport Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
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

class U_C_Scientist {
	displayName = "Scientist Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
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

class U_I_C_Soldier_Bandit_1_F {
	displayName = "Banit Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
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

class U_I_C_Soldier_Bandit_3_F { 
	displayName = "Casual Outfit"; 
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_I_C_Soldier_Bandit_3_F { 
			displayName = "Brown"; 
			condition = "true";
		};
		class Black : U_I_C_Soldier_Bandit_3_F { 
			displayName = "Black"; 
			textures[] = { "\A3\Characters_F_exp\Syndikat\Data\U_I_C_Soldier_Bandit_2_F_2_co.paa" };
		};
		class Red : U_I_C_Soldier_Bandit_3_F { 
			displayName = "Red"; 
			textures[] = { "\A3\Characters_F_exp\Civil\Data\U_C_Man_casual_6_F_1_co.paa" };
		};
		class Blue : U_I_C_Soldier_Bandit_3_F { 
			displayName = "Blue"; 
			textures[] = { "\A3\Characters_F_exp\Civil\Data\U_C_Man_casual_4_F_1_co.paa" };
		};
		class Yellow : U_I_C_Soldier_Bandit_3_F { 
			displayName = "Yellow"; 
			textures[] = { "\A3\Characters_F_exp\Civil\Data\U_C_Man_casual_5_F_1_co.paa" };
		};
	};
};

class U_IG_Guerilla1_1 {
	displayName = "Guerilla Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_IG_Guerilla1_1 { 
			displayName = "Garment"; 
			condition = "true";
		};
		class U_IG_Guerilla2_1 : U_IG_Guerilla1_1 { displayName = "Plain, Dark"; };
		class U_IG_Guerilla2_2 : U_IG_Guerilla1_1 { displayName = "Pattern"; };
		class U_IG_Guerilla2_3 : U_IG_Guerilla1_1 { displayName = "Plain, Light"; };
		class U_IG_Guerilla3_1 : U_IG_Guerilla1_1 { displayName = "Smocks (Dark)"; };
		class U_IG_Guerilla3_2 : U_IG_Guerilla1_1 { displayName = "Smocks (Light)"; };
		class Blackwing : U_IG_Guerilla1_1 {
			displayName = "Blackwing";
			textures[] = { "\a3\characters_f_gamma\Civil\Data\c_cloth1_black.paa" };
		};
		class Black : U_IG_Guerilla1_1 {
			displayName = "Black";
			textures[] = { "\a3\characters_f_gamma\Civil\Data\c_cloth1_black.paa" };
		};
		class Red : U_IG_Guerilla1_1 {
			displayName = "Red";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_bandit_co.paa" };
		};
		class Blue : U_IG_Guerilla1_1 {
			displayName = "Blue";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_co.paa" };
		};
		class Orange : U_IG_Guerilla1_1 {
			displayName = "Orange";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_v3_co.paa" };
		};
		class Yellow : U_IG_Guerilla1_1 {
			displayName = "Yellow";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_v2_co.paa" };
		};
		class Brown : U_IG_Guerilla1_1 {
			displayName = "Brown";
			textures[] = { "\a3\characters_f_gamma\Civil\Data\c_cloth1_brown.paa" };
		};
		class U_IG_leader : U_IG_Guerilla1_1 { displayName = "Uniform"; };
	};
};
class U_IG_Guerilla2_1 : U_IG_Guerilla1_1{};
class U_IG_Guerilla2_2 : U_IG_Guerilla1_1{};
class U_IG_Guerilla2_3 : U_IG_Guerilla1_1{};
class U_IG_Guerilla3_1 : U_IG_Guerilla1_1{};
class U_IG_Guerilla3_2 : U_IG_Guerilla1_1{};
class U_IG_leader : U_IG_Guerilla1_1{};

class U_C_E_LooterJacket_01_F {
	displayName = "Looter Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_C_E_LooterJacket_01_F { 
			displayName = "Leather Jacket"; 
			condition = "true";
		};
		class U_I_L_Uniform_01_tshirt_skull_F : U_C_E_LooterJacket_01_F { displayName = "T-Shirt, Skull"; };
		class U_I_L_Uniform_01_tshirt_black_F : U_C_E_LooterJacket_01_F { displayName = "T-Shirt, Black"; };
		class U_I_L_Uniform_01_tshirt_sport_F : U_C_E_LooterJacket_01_F { displayName = "T-Shirt, Sport"; };
		class U_I_L_Uniform_01_tshirt_olive_F : U_C_E_LooterJacket_01_F { displayName = "T-Shirt, Olive"; };
	};
};
class U_I_L_Uniform_01_tshirt_skull_F : U_C_E_LooterJacket_01_F{};
class U_I_L_Uniform_01_tshirt_black_F : U_C_E_LooterJacket_01_F{};
class U_I_L_Uniform_01_tshirt_sport_F : U_C_E_LooterJacket_01_F{};
class U_I_L_Uniform_01_tshirt_olive_F : U_C_E_LooterJacket_01_F{};

class U_O_R_Gorka_01_black_F {
	displayName = "Tracksuit";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
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
		class Medic {
			displayName = "Paramedic";
			textures[] = { "Data\Textures\Uniforms\Medic\tracksuit.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class Hato {
			displayName = "Traffic Officer";
			textures[] = { "Data\Textures\Uniforms\Hato\tracksuit.paa" };
			condition = "[player, [""Hato""]] call ULP_fnc_isFaction && { [""Hato_Main"", 2] call ULP_fnc_hasAccess }";
		};
	};
};

class U_I_C_Soldier_Para_1_F {
	displayName = "Paramilitary Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_I_C_Soldier_Para_1_F { 
			displayName = "Tee"; 
			condition = "true";
		};
		class U_I_C_Soldier_Para_2_F : U_I_C_Soldier_Para_1_F { displayName = "Jacket"; };
		class U_I_C_Soldier_Para_3_F : U_I_C_Soldier_Para_1_F { displayName = "Shirt"; };
		class U_I_C_Soldier_Para_4_F : U_I_C_Soldier_Para_1_F { displayName = "Tank Top"; };
		class U_I_C_Soldier_Para_5_F : U_I_C_Soldier_Para_1_F { displayName = "Shorts"; };
	};
};
class U_I_C_Soldier_Para_2_F : U_I_C_Soldier_Para_1_F{};
class U_I_C_Soldier_Para_3_F : U_I_C_Soldier_Para_1_F{};
class U_I_C_Soldier_Para_4_F : U_I_C_Soldier_Para_1_F{};
class U_I_C_Soldier_Para_5_F : U_I_C_Soldier_Para_1_F{};

class U_B_Wetsuit {
	displayName = "Wetsuits";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_B_Wetsuit { 
			displayName = "Black"; 
			condition = "true";
		};
		class U_O_Wetsuit : U_B_Wetsuit { displayName = "Brown"; };
		class U_I_Wetsuit : U_B_Wetsuit { displayName = "Green"; };
		class MPU {
			displayName = "MPU";
			textures[] = { "Data\Textures\Uniforms\Police\Units\MPU.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_MPU"", 1] call ULP_fnc_hasAccess }";
		};
	};
};
class U_O_Wetsuit : U_B_Wetsuit{};
class U_I_Wetsuit : U_B_Wetsuit{};

class U_Marshal {
	displayName = "Driver Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_Marshal { 
			displayName = "Marshall"; 
			condition = "true";
		};
		class U_C_Driver_1_black : U_Marshal { displayName = "Black"; };
		class U_C_Driver_1_blue : U_Marshal { displayName = "Blue"; };
		class U_C_Driver_1_green : U_Marshal { displayName = "Green"; };
		class U_C_Driver_1_red : U_Marshal { displayName = "Red"; };
		class U_C_Driver_1_white : U_Marshal { displayName = "White"; };
		class U_C_Driver_1_yellow : U_Marshal { displayName = "Yellow"; };
		class U_C_Driver_1_orange : U_Marshal { displayName = "Orange"; };
		class U_C_Driver_1 : U_Marshal { displayName = "Fuel"; };
		class U_C_Driver_2 : U_Marshal { displayName = "Bluking"; };
		class U_C_Driver_3 : U_Marshal { displayName = "Redstone"; };
		class U_C_Driver_4 : U_Marshal { displayName = "Vrana"; };
	};
};
class U_C_Driver_1_black : U_Marshal{};
class U_C_Driver_1_blue : U_Marshal{};
class U_C_Driver_1_green : U_Marshal{};
class U_C_Driver_1_red : U_Marshal{};
class U_C_Driver_1_white : U_Marshal{};
class U_C_Driver_1_yellow : U_Marshal{};
class U_C_Driver_1_orange : U_Marshal{};
class U_C_Driver_1 : U_Marshal{};
class U_C_Driver_2 : U_Marshal{};
class U_C_Driver_3 : U_Marshal{};
class U_C_Driver_4 : U_Marshal{};

class U_C_IDAP_Man_shorts_F {
	displayName = "IDAP Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
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

class U_C_Journalist {
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {};
};

class U_Rangemaster {
	displayName = "Patrol Uniform";
	price = 0;
	virtualSpace = 0;
	isGas = false;
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
			displayName = "Special Contable";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\SC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 3] call ULP_fnc_hasAccess }";
		};
		class PC {
			displayName = "Contable";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\PC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class PCSO {
			displayName = "PCSO";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\PCSO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		};
	};
};

class U_Competitor {
	displayName = "Response Uniform";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class DR {
			displayName = "Doctor";
			textures[] = { "Data\Textures\Uniforms\Medic\main_03.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class PAR {
			displayName = "Paramedic";
			textures[] = { "Data\Textures\Uniforms\Medic\main_02.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class STU {
			displayName = "Student";
			textures[] = { "Data\Textures\Uniforms\Medic\main_01.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_BG_Guerrilla_6_1 {
	displayName = "Patrol Jumper";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class COMMAND {
			displayName = "Command";
			textures[] = { "Data\Textures\Uniforms\Police\command.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 8] call ULP_fnc_hasAccess }";
		};
		class MAIN {
			displayName = "Main";
			textures[] = { "Data\Textures\Uniforms\Police\main.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class NCA {
			displayName = "NCA";
			textures[] = { "Data\Textures\Uniforms\Police\Units\NCA_main.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_OrestesBody {
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {};
};

class U_NikosBody {
	displayName = "Fine Shirt";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {};
};

class U_NikosAgedBody {
	displayName = "Fine Suit";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {};
};

class U_C_FormalSuit_01_tshirt_black_F {
	displayName = "Formal Suit, T-Shirt";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_C_FormalSuit_01_tshirt_black_F { 
			displayName = "Black"; 
			condition = "true";
		};
		class U_C_FormalSuit_01_tshirt_gray_F : U_C_FormalSuit_01_tshirt_black_F { displayName = "Gray"; };
		class Ridge {
			displayName = "Ridge Formal Uniform";
			textures[] = { "Data\Textures\Groups\Ridge\U_C_FormalSuit_01_tshirt_gray_F.paa" };
			condition = "true";
		};
	};
};

class U_C_FormalSuit_01_black_F {
	displayName = "Formal Suit";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_C_FormalSuit_01_black_F { 
			displayName = "Black"; 
			condition = "true";
		};
		class U_C_FormalSuit_01_gray_F : U_C_FormalSuit_01_black_F { displayName = "Gray"; };
		class U_C_FormalSuit_01_blue_F : U_C_FormalSuit_01_black_F { displayName = "Blue"; };
		class U_C_FormalSuit_01_khaki_F : U_C_FormalSuit_01_black_F { displayName = "Khaki"; };
		class ACF { 
			displayName = "ACF"; 
			textures[] = { "Data\Textures\Uniforms\Police\parade_01.paa" };
			condition = "true";
		};
	};
};
class U_C_FormalSuit_01_gray_F : U_C_FormalSuit_01_black_F{};
class U_C_FormalSuit_01_blue_F : U_C_FormalSuit_01_black_F{};
class U_C_FormalSuit_01_khaki_F : U_C_FormalSuit_01_black_F{};

class U_I_ParadeUniform_01_AAF_decorated_F {
	displayName = "Parade Uniform";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_I_ParadeUniform_01_AAF_decorated_F { 
			displayName = "Command"; 
			textures[] = { 
				"Data\Textures\Uniforms\Police\parade_01.paa",
				"Data\Textures\Uniforms\Police\parade_02.paa",
				"Data\Textures\Uniforms\Police\parade_03.paa"
			};
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 10] call ULP_fnc_hasAccess }";
		};
		class U_I_ParadeUniform_01_AAF_F : U_I_ParadeUniform_01_AAF_decorated_F { 
			displayName = "Main"; 
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 2] call ULP_fnc_hasAccess }";
		};
	};
};
class U_I_ParadeUniform_01_AAF_F : U_I_ParadeUniform_01_AAF_decorated_F{};

class U_B_survival_uniform {
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {};
};

class U_B_CombatUniform_mcam_worn {
	displayName = "Specialised Uniform";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class RPU {
			displayName = "Traffic Uniform";
			textures[] = { "Data\Textures\Uniforms\Police\Units\RPU_main.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_RPU"", 1] call ULP_fnc_hasAccess }";
		};
		class AFO {
			displayName = "AFO Uniform";
			textures[] = { "Data\Textures\Uniforms\Police\Units\AFO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_AFO"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_B_CombatUniform_mcam {
	displayName = "Combat Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_B_CombatUniform_mcam { 
			displayName = "MTP (Base)"; 
			condition = "true";
		};
		class U_B_CombatUniform_mcam_vest : U_B_CombatUniform_mcam { displayName = "MTP (Rolled)"; };
		class U_B_CombatUniform_mcam_tshirt : U_B_CombatUniform_mcam { displayName = "MTP (Tee)"; };
		class U_B_CombatUniform_mcam_wdl_f : U_B_CombatUniform_mcam { displayName = "WDL (Base)"; };
		class U_B_CombatUniform_vest_mcam_wdl_f : U_B_CombatUniform_mcam { displayName = "WDL (Rolled)"; };
		class U_B_CombatUniform_tshirt_mcam_wdL_f : U_B_CombatUniform_mcam { displayName = "WDL (Tee)"; };
	};
};
class U_B_CombatUniform_mcam_vest : U_B_CombatUniform_mcam{};
class U_B_CombatUniform_mcam_tshirt : U_B_CombatUniform_mcam{};
class U_B_CombatUniform_mcam_wdl_f : U_B_CombatUniform_mcam{};
class U_B_CombatUniform_vest_mcam_wdl_f : U_B_CombatUniform_mcam{};
class U_B_CombatUniform_tshirt_mcam_wdL_f : U_B_CombatUniform_mcam{};

class U_B_CTRG_Soldier_F {
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class SCO19 {
			displayName = "SCO19 Uniform";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SCO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SCO"", 1] call ULP_fnc_hasAccess }";
		};
		class Ridge {
			displayName = "Ridge Combat Uniform";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "true";
		};
	};
};
class U_B_CTRG_Soldier_2_Arid_F : U_B_CTRG_Soldier_F{};

class U_B_GhillieSuit {
	displayName = "Half-Ghillies";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class SCO19 {
			displayName = "SCO19 Ghillie";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SCO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SCO"", 2] call ULP_fnc_hasAccess }";
		};
		class U_B_GhillieSuit { 
			displayName = "MTP"; 
			condition = "true";
		};
		class U_O_GhillieSuit : U_B_GhillieSuit { displayName = "Hex"; };
		class U_I_GhillieSuit : U_B_GhillieSuit { displayName = "Digi"; };
	};
};
class U_O_GhillieSuit : U_B_GhillieSuit{};
class U_I_GhillieSuit : U_B_GhillieSuit{};

class U_B_FullGhillie_ard {
	displayName = "Full-Ghillies";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_B_FullGhillie_ard { 
			displayName = "Arid"; 
			condition = "true";
		};
		class U_B_FullGhillie_sard : U_B_FullGhillie_ard { displayName = "Semi-Arid"; };
		class U_B_FullGhillie_lsh : U_B_FullGhillie_ard { displayName = "Lush"; };
	};
};
class U_B_FullGhillie_sard : U_B_FullGhillie_ard{};
class U_B_FullGhillie_lsh : U_B_FullGhillie_ard{};

class U_B_HeliPilotCoveralls {
	displayName = "Flight Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class U_B_HeliPilotCoveralls { 
			displayName = "Green"; 
			condition = "true";
		};
		class U_I_HeliPilotCoveralls : U_B_HeliPilotCoveralls { displayName = "Tan"; };
	};
};
class U_I_HeliPilotCoveralls : U_B_HeliPilotCoveralls{};

class U_O_PilotCoveralls {
	displayName = "Flight Clothes";
	price = 0;
	virtualSpace = 0;
	isGas = false;
	class Textures {
		class NPAS {
			displayName = "NPAS Uniform";
			textures[] = { "Data\Textures\Uniforms\Police\Units\NPAS.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_NPAS"", 1] call ULP_fnc_hasAccess }";
		};
		class AAA {
			displayName = "AAA Uniform";
			textures[] = { "Data\Textures\Uniforms\Medic\aa.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_AA"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_C_CBRN_Suit_01_White_F {
	displayName = "CBRN Suits";
	price = 0;
	virtualSpace = 0;
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
	};
};
class U_C_CBRN_Suit_01_Blue_F : U_C_CBRN_Suit_01_White_F {};
class U_B_CBRN_Suit_01_MTP_F : U_C_CBRN_Suit_01_White_F {};
class U_B_CBRN_Suit_01_Wdl_F : U_C_CBRN_Suit_01_White_F {};
class U_I_CBRN_Suit_01_AAF_F : U_C_CBRN_Suit_01_White_F {};