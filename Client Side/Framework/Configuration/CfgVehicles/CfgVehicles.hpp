class CfgVehicles {
	sellPerc = 0.3;
	retrievalPerc = 0.15;

	class Base {
		conditions = "true";
		class Textures {};
	};

	class BaseTexture {
		displayName = "Default";
		buyPrice = 0;
		textures[] = {};
		conditions = "true";
	};

	class C_Kart_01_Blu_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class C_Kart_01_Fuel_F : C_Kart_01_Blu_F{};
    class C_Kart_01_Red_F : C_Kart_01_Blu_F{};
    class C_Kart_01_Vrana_F : C_Kart_01_Blu_F{};
    class C_Kart_01_black_F : C_Kart_01_Blu_F{};
    class C_Kart_01_white_F : C_Kart_01_Blu_F{};
    class C_Kart_01_green_F : C_Kart_01_Blu_F{};
    class C_Kart_01_orange_F : C_Kart_01_Blu_F{};
    class C_Kart_01_yellow_F : C_Kart_01_Blu_F{};

	class C_Quadbike_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_black_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_white_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_red_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_blue_co.paa" }; 
			};
			class Tan : BaseTexture { 
				displayName = "Tan";
				textures[] = { "\A3\Soft_F\Quadbike_01\Data\Quadbike_01_co.paa" }; 
			};
		};
	};

	class C_Hatchback_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa" }; 
			};
			class BlackWhiteSport : BaseTexture {
				displayName = "Black/White Sport"; 
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa" }; 
			};
			class Grey : BaseTexture {
				displayName = "Grey"; 
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa" }; 
			};
			class Beige : BaseTexture { 
				displayName = "Beige";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa" }; 
			};
			class BeigeSport : BaseTexture { 
				displayName = "Beige Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa" }; 
			};
			class RedSport : BaseTexture { 
				displayName = "Red Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa" }; 
			};
			class BlueSport : BaseTexture { 
				displayName = "Blue Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa" }; 
			};
			class DarkBlue : BaseTexture { 
				displayName = "Dark Blue";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa" }; 
			};
			class DarkBlueSport : BaseTexture { 
				displayName = "Dark Blue Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa" }; 
			};
			class Green : BaseTexture { 
				displayName = "Green";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa" }; 
			};
			class GreenSport : BaseTexture { 
				displayName = "Green Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa" }; 
			};
			class Yellow : BaseTexture { 
				displayName = "Yellow";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa" }; 
			};
			class OrangeSport : BaseTexture { 
				displayName = "Orange Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa" }; 
			};
			class PoliceWhite : BaseTexture { 
				displayName = "General Response";
				conditions = "[player, [""Police""]] call ULP_fnc_isFaction";
				textures[] = { "data\textures\vehicles\land\police\police_hatchback_white.paa }; 
			};
			class PoliceBlack : BaseTexture { 
				displayName = "Armed Response";
				conditions = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				textures[] = { "data\textures\vehicles\land\police\police_hatchback_black.paa }; 
			};
			class Medic : BaseTexture { 
				displayName = "Incident Response";
				conditions = "[player, [""Medic""]] call ULP_fnc_isFaction";
				textures[] = { "data\textures\vehicles\land\medic\medic_hatchback.paa }; 
			};
		};
	};
	class C_Hatchback_01_sport_F : C_Hatchback_01_F { buyPrice = 0; };

	class C_Offroad_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class White : BaseTexture {
				displayName = "White"; 
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa" 
				}; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa" 
				}; 
			};
			class DarkRed : BaseTexture { 
				displayName = "DarkRed";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa" 
				}; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa" 
				}; 
			};
			class BlueWhite : BaseTexture { 
				displayName = "Blue/White";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa" 
				}; 
			};
			class PoliceWhite : BaseTexture { 
				displayName = "General Response";
				conditions = "[player, [""Police""]] call ULP_fnc_isFaction";
				textures[] = { 
					"data\textures\Police\Vehicles\police_offroad_white.paa",
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa",
					"#(rgb,8,8,3)color(0.97,0.97,0.97,1)" 
				}; 
			};
		};
	};
	class B_G_Offroad_01_armed_F : C_Offroad_01_F { buyPrice = 0; };
	class B_GEN_Offroad_01_gen_F : C_Offroad_01_F {};

	class C_Offroad_01_covered_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = {
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_blk_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_blk_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_cover_blk_co.paa"
				}; 
			};
			class Green : BaseTexture { 
				displayName = "Green";
				textures[] = { 
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_grn_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_grn_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_cover_grn_co.paa"
				}; 
			};
		};
	};
	class C_Offroad_01_comms_F : C_Offroad_01_covered_F { buyPrice = 0; };

	class C_Offroad_01_repair_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
	};

	class C_Offroad_02_unarmed_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_white_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_red_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_orange_co.paa" }; 
			};
		};
	};
	class I_C_Offroad_02_LMG_F : C_Offroad_02_unarmed_F { buyPrice = 0; };

	class C_SUV_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" }; 
			};
			class Silver : BaseTexture { 
				displayName = "Silver";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa" }; 
			};
			class PoliceWhite : BaseTexture { 
				displayName = "General Response";
				conditions = "[player, [""Police""]] call ULP_fnc_isFaction";
				textures[] = { "data\textures\vehicles\land\police\police_suv_white.paa }; 
			};
			class PoliceBlack : BaseTexture { 
				displayName = "Armed Response";
				conditions = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SFO"", 1] call ULP_fnc_hasAccess }";
				textures[] = { "data\textures\vehicles\land\police\police_suv_black.paa }; 
			};
			class PoliceUnmarked : BaseTexture {
				displayName = "Unmarked"; 
				conditions = "[player, [""Police""]] call ULP_fnc_isFaction && ({ [""Police_Main"", 10] call ULP_fnc_hasAccess } || { [""Police_SFO"", 3] call ULP_fnc_hasAccess })";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" }; 
			};
			class Medic : BaseTexture { 
				displayName = "General Response";
				conditions = "[player, [""Medic""]] call ULP_fnc_isFaction";
				textures[] = { "data\textures\vehicles\land\medic\medic_suv.paa }; 
			};
		};
	};

	class C_Van_02_transport_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_white_CO.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Red_CO.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Orange_CO.paa" }; 
			};
			class Press : BaseTexture { 
				displayName = "Press";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_AAN_CO.paa" }; 
			};
			class Police : BaseTexture { 
				displayName = "Public Order";
				conditions = "[player, [""Police""]] call ULP_fnc_isFaction";
				textures[] = { "data\textures\vehicles\land\police\police_van.paa }; 
			};
			class PoliceUnmarked : BaseTexture {
				displayName = "Unmarked"; 
				conditions = "[player, [""Police""]] call ULP_fnc_isFaction && ({ [""Police_Main"", 10] call ULP_fnc_hasAccess } || { [""Police_SFO"", 3] call ULP_fnc_hasAccess })";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" }; 
			};
			class Medic : BaseTexture { 
				displayName = "Ambulance";
				conditions = "[player, [""Medic""]] call ULP_fnc_isFaction";
				textures[] = { "data\textures\vehicles\land\medic\medic_van.paa }; 
			};
		};
	};
	class B_GEN_Van_02_transport_F : C_Van_02_transport_F {};
	class C_Van_02_medevac_F : C_Van_02_transport_F {};
	class C_Van_02_vehicle_F : C_Van_02_transport_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class B_GEN_Van_02_vehicle_F : C_Van_02_vehicle_F {};
	class C_Van_02_service_F : C_Van_02_vehicle_F {};

	class O_LSV_02_unarmed_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { 
					"#(rgb,8,8,3)color(0.97,0.97,0.97,1)", 
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa" 
				}; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { 
					"#(rgb,8,8,3)color(0.9,0.03,0.03,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa" 
				}; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				textures[] = { 
					"#(rgb,8,8,3)color(1,0.2,0.03,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa"
				}; 
			};
			class Teal : BaseTexture { 
				displayName = "Teal";
				textures[] = { 
					"#(rgb,8,8,3)color(0.05,0.67,737,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa"
				}; 
			};
			class Green : BaseTexture { 
				displayName = "Green";
				textures[] = { 
					"#(rgb,8,8,3)color(0.03,0.9,0.03,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa" 
				}; 
			};
			class Emerald : BaseTexture { 
				displayName = "Emerald";
				textures[] = { 
					"#(rgb,8,8,3)color(0.03,1,0.6,1)", 
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa"
				}; 
			};
			class Lime : BaseTexture { 
				displayName = "Lime";
				textures[] = { 
					"#(rgb,8,8,3)color(0.1,0.6,0.03,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa"
				}; 
			};
			class Pink : BaseTexture { 
				displayName = "Pink";
				textures[] = { 
					"#(rgb,8,8,3)color(0.97,0.03,0.5,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa"
				}; 
			};
		};
	};

	class B_CTRG_LSV_01_light_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { 
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_black_co.paa" 
				}; 
			};
			class Sand : BaseTexture { 
				displayName = "Sand";
				textures[] = { 
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_sand_co.paa"
				}; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { 
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_olive_co.paa"
				}; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_orange_co.paa" }; 
			};
		};
	};
	class B_T_LSV_01_unarmed_black_F : B_CTRG_LSV_01_light_F { buyPrice = 0; };
};