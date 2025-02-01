class CfgVehicles {
	retrievalPerc = 0.02;
	chopKeepChance = 80;
	chopPerc = 0.35;
	chopTime = 300;

	class Base {
		virtualSpace = 0;
		garageLimit = 5;
		fuelConsumptionRate = 1.25;
		isHouse = false;
		canTransfer = true;
		conditions = "true";
		blacklistedItems[] = { 
			"StolenCargo",
			"FreightCargo",

			"UnprocessedOil",
			"ProcessedOil"
		};
		class Textures {};
	};

	class BaseShip : Base {
		blacklistedItems[] = { 
			"FreightCargo",

			"UnprocessedOil",
			"ProcessedOil"
		};
	};

	class BaseTruck : Base {
		garageLimit = 2;
		fuelConsumptionRate = 1.40;
		enableRope = false;
		garageDelay = 15;
		repairTime = 15;
		crushTime = 300;
		chopKeepChance = 85;
		chopTime = 120;
		blacklistedItems[] = { 
			"UnprocessedOil",
			"ProcessedOil"
		};
		class Textures {};
	};

	class BaseAir : Base {
		garageLimit = 2;
		fuelConsumptionRate = 1.35;
		garageDelay = 20;
		repairTime = 20;
		crushTime = 300;
		chopKeepChance = 90;
		chopTime = 180;
		retrievalPerc = 0.005;
		turrets[] = {};
		blacklistedItems[] = { 
			"StolenCargo",
			"FreightCargo",

			"Turtle_F_Raw",

			"SeizedContraband",
			"SpaceCapsuleDataDrive",
			"SmallGalleryPiece",
			"MediumGalleryPiece",
			"LargeGalleryPiece",
			"MarkedGold",
			"UnmarkedGold",
			"EncryptedDrive",
			"DecryptedDrive"
		};
	};

	// LIGHTS --------------------------------------------------------------------------------------
	class PoliceColour {
		leftColour[] = {0.1, 0.1, 20};
		rightColour[] = {0.1, 0.1, 20};
	};
	class MedicColour {
		leftColour[] = {0.1, 0.1, 20};
		rightColour[] = {0.1, 0.1, 20};
	};
	class HatoColour {
		leftColour[] = {10, 5, 0};
		rightColour[] = {10, 5, 0};
	};

	// TEXTURES --------------------------------------------------------------------------------------
	class BaseTexture {
		displayName = "Default";
		buyPrice = 0;
		factions[] = { "Civilian" };
		textures[] = {};
		locked = false;
		conditions = "true";
	};

	// Base without siren or lights (for helis)
	class PoliceTextureBase : BaseTexture {
		factions[] = { "Police" };
		class Siren { SFX[] = { "Siren_1", "Siren_2", "Siren_5" }; };
		class Actions {
			class PNC {
				actionTitle = "Police National Computer";
				actionCode = "[] call ULP_fnc_openPNC";
				params[] = {};
				priority = 1;
				condition = "_target isEqualTo (vehicle _this) && { ([player, [""Police""]] call ULP_fnc_isFaction) || ((driver _this) isEqualTo _target) }";
				radius = 25;
			};
		};
	};

	// Full with sirens and lights
	class PoliceTexture : PoliceTextureBase {
		remoteGates = true;
		class Lights : PoliceColour {};
	};

	class MedicTextureBase : BaseTexture {
		factions[] = { "Medic" };
		class Siren { SFX[] = { "Siren_6", "Siren_4", "Siren_3" }; };
		class Actions {
			class NHSDispatcher {
				actionTitle = "NHS Dispatcher";
				actionCode = "[] call ULP_fnc_openMedicMap";
				params[] = {};
				priority = 1;
				condition = "_target isEqualTo (vehicle _this) && { [player, [""Medic""]] call ULP_fnc_isFaction }";
				radius = 25;
			};
		};
	};
	
	class MedicTexture : MedicTextureBase {
		remoteGates = true;
		class Lights : MedicColour {};
	};

	class HatoTexture : BaseTexture {
		factions[] = { "Hato" };
		remoteGates = true;
		class Siren {};
		class Lights : HatoColour {};
	};

	class BaseChromeGreen : BaseTexture {
		displayName = "Chrome Green";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\green.rvmat" };
		locked = true;
	};
	class BaseChromeBlue : BaseChromeGreen {
		displayName = "Chrome Blue";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\blue.rvmat" };
	};
	class BaseChromeRed : BaseChromeGreen {
		displayName = "Chrome Red";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\red.rvmat" };
	};
	class BaseChromeSilver : BaseChromeGreen {
		displayName = "Chrome Silver";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\silver.rvmat" };
	};
	class BaseChromeGold : BaseChromeGreen {
		displayName = "Chrome Gold";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\gold.rvmat" };
	};

	// CARS --------------------------------------------------------------------------------------
	class C_Kart_01_Blu_F : Base {
		description = "Kart is a small four-wheeled vehicle propelled by gravity, gas or electricity. It has 4-stroke engine offering up to 20 hp and should not be operated by drivers under 18 years old.";
		buyPrice = 2500;
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
		description = "A Quadbike is an all-terrain vehicle with low-pressure tires and handlebars for steering. The military uses quad bikes for reconnaissance and to access terrain difficult for heavier vehicles.";
		buyPrice = 9300;
		virtualSpace = 15;
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
		description = "A four-seat hatchback car mass-produced in the Far East to satisfy increasing demand for family cars. Also comes in a sporty version.";
		buyPrice = 17450;
		virtualSpace = 25;
		class Textures {
			class PoliceWhite : PoliceTexture { 
				displayName = "General Response";
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_white.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class PoliceBlack : PoliceWhite { 
				displayName = "Armed Response";
				conditions = "[""Police_RPU"", 1] call ULP_fnc_hasAccess && { [""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_SFO"", 1] call ULP_fnc_hasAccess } }";
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_black.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class PoliceANPR : PoliceWhite { 
				displayName = "ANPR Interceptor";
				anpr = true;
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_ANPR.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class UnmarkedBlack : PoliceTexture {
				displayName = "Black";
				anpr = true;
				conditions = "[""Police_RPU"", 2] call ULP_fnc_hasAccess";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class UnmarkedBlackWhiteSport : UnmarkedBlack {
				displayName = "Black/White Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedGrey : UnmarkedBlack {
				displayName = "Grey";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedWhite : UnmarkedBlack {
				displayName = "White";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa" };
				class Lights : Lights {}; 
			};
			class UnmarkedBeige : UnmarkedBlack {
				displayName = "Beige";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedBeigeSport : UnmarkedBlack {
				displayName = "Beige Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedRedSport : UnmarkedBlack {
				displayName = "Red Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa" };
				class Lights : Lights {}; 
			};
			class UnmarkedBlue : UnmarkedBlack {
				displayName = "Blue";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedBlueSport : UnmarkedBlack {
				displayName = "Blue Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedDarkBlue : UnmarkedBlack {
				displayName = "Dark Blue";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedDarkBlueSport : UnmarkedBlack {
				displayName = "Dark Blue Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedGreen : UnmarkedBlack {
				displayName = "Green";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedGreenSport : UnmarkedBlack {
				displayName = "Green Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedYellow : UnmarkedBlack {
				displayName = "Yellow";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedOrangeSport : UnmarkedBlack {
				displayName = "Orange Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa" }; 
				class Lights : Lights {};
			};
			class Medic : MedicTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Medic\hatchback.paa" }; 
				class Lights : MedicColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class Hato : HatoTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Hato\hatchback.paa" }; 
				class Lights : HatoColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
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
		};
	};
	class C_Hatchback_01_sport_F : C_Hatchback_01_F { buyPrice = 276500; };

	class C_Offroad_01_F : Base {
		description = "The 4x4 pickup by Generic Motors has a durable chassis and powerful engine and has been designed to withstand the rugged terrain of the Mediterranean.";
		buyPrice = 35800;
		virtualSpace = 60;
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
			class Ridge : BaseTexture { 
				displayName = "Ridge";
				locked = true;
				textures[] = { "Data\Textures\Vehicles\Land\Civilian\Offroad\ridge.paa" }; 
			};
		};
	};
	class B_G_Offroad_01_armed_F : C_Offroad_01_F { 
		buyPrice = 4280000; 
		virtualSpace = 20;
		garageLimit = 1;
		retrievalPerc = 0.05;
		enableRope = false;
	};
	class B_GEN_Offroad_01_gen_F : C_Offroad_01_F {};
	class C_IDAP_Offroad_01_F : C_Offroad_01_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP"; 
				textures[] = { 
					"\a3\soft_f_orange\Data\Offroad_01_ext_IDAP_CO.paa"
				}; 
			};
		};
	};
	class C_Offroad_01_covered_F : C_Offroad_01_F {
		buyPrice = 39100;
		virtualSpace = 75;
		class Textures {
			class Hato : HatoTexture { 
				displayName = "HATO"; 
				textures[] = { "Data\Textures\Vehicles\Land\Hato\offroad.paa" }; 
			};
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
	class C_Offroad_01_comms_F : C_Offroad_01_covered_F { buyPrice = 44450; };
	class C_Offroad_01_repair_F : C_Offroad_01_covered_F { buyPrice = 44450; };

	class C_Offroad_02_unarmed_F : Base {
		description = "The MB 4WD is a modern four-wheel drive off-road vehicle with a distinctive construction, powerful engine, durable chassis and great maneuverability.";
		buyPrice = 31750;
		virtualSpace = 55;
		class Textures {
			class Medic : MedicTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Medic\MB4.paa" }; 
				class Lights : MedicColour {
					leftPos[] = {0.757324,1.83252,-0.379596};
					rightPos[] = {-0.844727,1.82861,-0.379596};
				};
			};
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
			class Ridge : BaseTexture { 
				displayName = "Ridge";
				locked = true;
				textures[] = { "Data\Textures\Vehicles\Land\Civilian\MB4_WD\ridge.paa" }; 
			};
		};
	};
	class C_IDAP_Offroad_02_unarmed_F : C_Offroad_02_unarmed_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP"; 
				textures[] = { 
					"\a3\soft_f_orange\Data\Offroad_02_ext_IDAP_CO.paa"
				}; 
			};
		};
	};
	class I_C_Offroad_02_LMG_F : C_Offroad_02_unarmed_F { 
		buyPrice = 670300; 
		virtualSpace = 45;
		garageLimit = 1;
		retrievalPerc = 0.05;
		enableRope = false;
	};

	class C_SUV_01_F : Base {
		description = "A full-size luxury crossover SUV, not particularly suitable for off-road but with good on-road ability. Its powerful engine and 4x4 contribute to the enjoyable rides in higher speeds.";
		buyPrice = 54200;
		virtualSpace = 45;
		class Textures {
			class PoliceWhite : PoliceTexture { 
				displayName = "General Response";
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_white.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
			class PoliceBlack : PoliceWhite { 
				displayName = "Armed Response";
				conditions = "[""Police_SCO"", 1] call ULP_fnc_hasAccess";
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_black.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				}; 
			};
			class PoliceANPR : PoliceWhite { 
				displayName = "ANPR Interceptor";
				conditions = "[""Police_RPU"", 1] call ULP_fnc_hasAccess";
				anpr = true;
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_ANPR.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				}; 
			};
			class UnmarkedBlack : PoliceTexture {
				displayName = "Black";
				conditions = "[""Police_RPU"", 2] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
			class UnmarkedSilver : UnmarkedBlack {
				displayName = "Silver";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedRed : UnmarkedBlack {
				displayName = "Red";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa" };  
				class Lights : Lights {};
			};
			class UnmarkedOrange : UnmarkedBlack {
				displayName = "Orange";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa" }; 
				class Lights : Lights {};
			};
			class Medic : MedicTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Medic\SUV.paa" }; 
				class Lights : MedicColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
			class Hato : HatoTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Hato\SUV.paa" }; 
				class Lights : HatoColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
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
		};
	};

	class C_Van_02_transport_F : Base {
		description = "The van can be used for a variety of practical purposes. Featuring a long load length and excellent roof height, allowing for the transport of passengers, cargo and smaller vehicles.";
		buyPrice = 68000;
		virtualSpace = 90;
		enableRope = false;
		class Textures {
			class PoliceWhite : PoliceTexture { 
				displayName = "Public Order";
				textures[] = { "Data\Textures\Vehicles\Land\Police\van.paa" }; 
			};
			class UnmarkedBlack : PoliceTexture {
				displayName = "Black";
				conditions = "[""Police_RPU"", 2] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" }; 
			};
			class UnmarkedWhite : UnmarkedBlack {
				displayName = "White";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_white_CO.paa" }; 
			};
			class UnmarkedRed : UnmarkedBlack {
				displayName = "Red";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Red_CO.paa" }; 
			};
			class UnmarkedOrange : UnmarkedBlack {
				displayName = "Orange";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Orange_CO.paa" }; 
			};
			class Medic : MedicTexture { 
				displayName = "Ambulance"; 
				conditions = "[""Medic_Main"", 1] call ULP_fnc_hasAccess";
				textures[] = { "Data\Textures\Vehicles\Land\Medic\van.paa" }; 
			};
			class Hato : HatoTexture { 
				displayName = "HATO"; 
				conditions = "[""Hato_Main"", 1] call ULP_fnc_hasAccess";
				textures[] = { "Data\Textures\Vehicles\Land\Hato\van.paa" }; 
			};
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
		};
	};
	class B_GEN_Van_02_transport_F : C_Van_02_transport_F {};
	class C_Van_02_medevac_F : C_Van_02_transport_F {};
	class C_IDAP_Van_02_transport_F : C_Van_02_transport_F {
		class Textures {
			class IDAP : BaseTexture { 
				displayName = "IDAP";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_IDAP_CO.paa" }; 
			};
		};
	};
	class C_Van_02_vehicle_F : C_Van_02_transport_F {
		buyPrice = 86650;
		virtualSpace = 110;
	};
	class B_GEN_Van_02_vehicle_F : C_Van_02_vehicle_F {};
	class C_IDAP_Van_02_vehicle_F : C_Van_02_vehicle_F {
		class Textures {
			class IDAP : BaseTexture { 
				displayName = "IDAP";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_IDAP_CO.paa" }; 
			};
		};
	};
	class C_Van_02_service_F : C_Van_02_vehicle_F {};

	class B_CTRG_LSV_01_light_F : Base {
		description = "The Prowler is agile, lightly armored and uses speed, maneuverability, and off-road mobility to avoid threats.";
		buyPrice = 580000;
		virtualSpace = 50;
		garageLimit = 3;
		class Textures {
			class Police : PoliceTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Police\prowler.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {0.75293,1.99902,-0.930151};
					rightPos[] = {-0.681152,2.01074,-0.930151};
				};
			};
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
			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};
	class B_LSV_01_unarmed_black_F : B_CTRG_LSV_01_light_F { buyPrice = 585000; };

	class O_LSV_02_unarmed_F : Base {
		description = "Qilin offers safe and fast operating speeds with superior levels of mobility and maneuverability. It is adaptable to severe rugged and restrictive terrains.";
		buyPrice = 675000;
		virtualSpace = 50;
		garageLimit = 3;
		class Textures {
			class Police : PoliceTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Police\qilin.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {0.615234,2.03467,-0.40501};
					rightPos[] = {-0.943359,2.02881,-0.398304};
				};
			};
			class Black : BaseTexture { 
				displayName = "Black";
				textures[] = { "\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_01_black_CO.paa", }; 
			};
			class Hex : BaseTexture { 
				displayName = "Hex";
				textures[] = { "\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_01_arid_CO.paa", }; 
			};
			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};
	class O_LSV_02_armed_black_F : O_LSV_02_unarmed_F { 
		buyPrice = 6590000; 
		garageLimit = 1;
	};

	class B_MRAP_01_F : Base {
		description = "The Hunter is a MRAP vehicle with an armored hull that can withstand light weapons and offers a powerful engine.";
		buyPrice = 9800000;
		virtualSpace = 65;
		garageLimit = 2;
		garageDelay = 15;
		repairTime = 20;
		crushTime = 60;
		chopKeepChance = 95;
		chopTime = 300;
		retrievalPerc = 0.01;
		enableRope = false;
		class Textures {
			class Police : PoliceTexture {
				textures[] = {
					"Data\Textures\Vehicles\Land\Police\hunter_01.paa",
					"Data\Textures\Vehicles\Land\Police\hunter_02.paa"
				}; 
				class Siren { SFX[] = { "Siren_7", "Siren_8", "Siren_9" }; };
				class Lights : PoliceColour {
					leftPos[] = {0.95459,-2.73975,0.559029};
					rightPos[] = {-0.94873,-2.73975,0.557981};
				};
			};
		};
	};

	class O_MRAP_02_F : Base {
		description = "The Ifrit is a MRAP vehicle designed and manufactured in Russia. Its strengths lie in reliability in extreme weather conditions and crew protection.";
		buyPrice = 7500000;
		virtualSpace = 65;
		garageLimit = 2;
		garageDelay = 15;
		repairTime = 20;
		crushTime = 60;
		chopKeepChance = 90;
		chopTime = 300;
		retrievalPerc = 0.01;
		canTransfer = false;
		enableRope = false;
		conditions = "[""Ifrits""] call ULP_fnc_hasGroupPerk || { [""PersonalTank""] call ULP_fnc_hasPerk }";
		class Textures {
			class Hex : BaseTexture { 
				displayName = "Hex";
				textures[] = { 
					"\A3\soft_F\MRAP_02\data\MRAP_02_ext_01_CO.paa", 
					"\A3\soft_F\MRAP_02\data\MRAP_02_ext_02_CO.paa"
				}; 
			};
			class GoldLine : BaseTexture { 
				displayName = "Gold Line";
				buyPrice = 450000;
				condition = "[] call ULP_fnc_donatorLevel > 0"; 
				textures[] = { 
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\goldLine_01.paa",
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\goldLine_02.paa"
				}; 
			};
			class Oil : GoldLine { 
				displayName = "Oil Spill";
				buyPrice = 315700;
				textures[] = { 
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\oil_01.paa",
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\oil_02.paa"
				}; 
			};
			class ChromeGreen : BaseChromeGreen {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\green.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\green.rvmat"
				};
			};
			class ChromeBlue : BaseChromeBlue {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\blue.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\blue.rvmat"
				};
			};
			class ChromeRed : BaseChromeRed {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\red.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\red.rvmat"
				};
			};
			class ChromeSilver : BaseChromeSilver {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\silver.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\silver.rvmat"  
				};
			};
			class ChromeGold : BaseChromeGold {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\gold.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\gold.rvmat"  
				};
			};
		};
	};

	class I_MRAP_03_F : Base {
		description = "The Strider is a medium all-terrain vehicle with amphibious capability and enhanced crew protection, designed for reconnaissance and troop transport roles.";
		buyPrice = 5750000;
		virtualSpace = 65;
		garageLimit = 2;
		garageDelay = 15;
		repairTime = 20;
		crushTime = 60;
		chopKeepChance = 90;
		chopTime = 300;
		retrievalPerc = 0.01;
		enableRope = false;
		class Textures {
			class Tan : BaseTexture { 
				displayName = "Tan";
				textures[] = { 
					"\A3\soft_f_beta\mrap_03\data\mrap_03_ext_co.paa", 
					"\A3\data_f\vehicles\turret_co.paa"
				}; 
			};
			class Asiimov : BaseTexture { 
				displayName = "Asiimov";
				locked = true;
				textures[] = { "Data\Textures\Vehicles\Land\Civilian\Strider\asiimov.paa" }; 
			};
			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};

	// TRUCKS --------------------------------------------------------------------------------------
	class C_Tractor_01_F : BaseTruck {
		description = "Found in farm barns across the globe, the common tractor is a reliable high torque engineering vehicle, used for towing trailers and many other agricultural tasks.";
		buyPrice = 23150;
		virtualSpace = 10;
		class Textures {
			class Red : BaseTexture {
				displayName = "Red"; 
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_red_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_blue_co.paa" }; 
			};
			class Green : BaseTexture { 
				displayName = "Green";
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_green_co.paa" }; 
			};
		};
	};

	class C_Van_01_transport_F : BaseTruck {
		description = "The civilian 4x4 truck is a highly customizable truck with off-road capabilities. It builds on retro design, but utilizes a modern engine and electronics.";
		buyPrice = 105500;
		virtualSpace = 125;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_black_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_red_co.paa" }; 
			};
			class Brown : BaseTexture { 
				displayName = "Brown";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_brn_co.paa" }; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_oli_co.paa" }; 
			};
			class Aldsa : BaseTexture {
				displayName = "Aldsa"; 
				locked = true;
				textures[] = { 
					"Data\Textures\Vehicles\Land\Civilian\Truck\aldsa_01.paa", 
					"Data\Textures\Vehicles\Land\Civilian\Truck\aldsa_02.paa"
				}; 
			};
		};
	};
	class C_Van_01_box_F : C_Van_01_transport_F {
		buyPrice = 145500;
		virtualSpace = 150;
	};
	class C_Van_01_fuel_F : C_Van_01_transport_F {
		buyPrice = 200000;
		virtualSpace = 100;
		blacklistedItems[] = { 
			"StolenCargo",
			"FreightCargo"
		};
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_black_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_red_co.paa" }; 
			};
			class Brown : BaseTexture { 
				displayName = "Brown";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_brn_co.paa" }; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_oli_co.paa" }; 
			};
		};
	};

	class I_Truck_02_transport_F : BaseTruck {
		description = "The Zamak heavy truck is a 6x6 vehicle used for transport and utility. Fitted with a powerful V8 engine, these trucks are reliable even in harsh conditions.";
		buyPrice = 505000;
		virtualSpace = 280;
		class Textures {
			class Orange : BaseTexture {
				displayName = "Orange"; 
				textures[] = { 
					"\A3\Soft_F_Beta\Truck_02\data\truck_02_kab_co.paa", 
					"\a3\soft_f_beta\Truck_02\data\truck_02_kuz_co.paa"
				 }; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { 
					"\a3\soft_f_beta\truck_02\data\truck_02_kab_blue_co.paa",
					"\a3\soft_f_beta\truck_02\data\truck_02_kuz_co.paa",
					"\a3\soft_f_beta\truck_02\data\truck_02_int_co.paa"
				};
			}; 
		};
	};
	class C_IDAP_Truck_02_transport_F : I_Truck_02_transport_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP"; 
				textures[] = { 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_int_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kuz_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_water_IDAP_CO.paa"
				 }; 
			};
		};
	};
	class I_Truck_02_covered_F : I_Truck_02_transport_F {
		buyPrice = 560000;
		virtualSpace = 350;
	};
	class C_IDAP_Truck_02_F : I_Truck_02_covered_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP"; 
				textures[] = { 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_int_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kuz_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_water_IDAP_CO.paa"
				 }; 
			};
		};
	};
	class I_Truck_02_fuel_F : I_Truck_02_transport_F {
		buyPrice = 750000;
		virtualSpace = 300;
		blacklistedItems[] = { 
			"StolenCargo",
			"FreightCargo"
		};
	};
	class C_IDAP_Truck_02_water_F : I_Truck_02_fuel_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP"; 
				textures[] = { 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_int_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kuz_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_water_IDAP_CO.paa"
				 }; 
			};
		};
	};

	class O_Truck_03_transport_F : BaseTruck {
		description = "The Tempest is a 6x6 mine resistant standard transport truck. The modular design of the truck allows several transport versions.";
		buyPrice = 850550;
		virtualSpace = 370;
		class Textures {
			class BrownHex : BaseTexture {
				displayName = "Brown Hex"; 
				textures[] = { 
					"\a3\soft_f_epc\truck_03\data\truck_03_ext01_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_ext02_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_cargo_co.paa"
				 }; 
			};
			class GreenHex : BaseTexture { 
				displayName = "Green Hex";
				textures[] = { 
					"\a3\soft_f_exp\truck_03\data\truck_03_ext01_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_ext02_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_cargo_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_cover_ghex_co.paa"
				};
			}; 
		};
	};
	class O_Truck_03_covered_F : O_Truck_03_transport_F {
		buyPrice = 988600;
		virtualSpace = 410;
	};
	class O_Truck_03_repair_F : O_Truck_03_transport_F {
		buyPrice = 1398000;
		virtualSpace = 485;
	};
	class O_Truck_03_ammo_F : O_Truck_03_transport_F {
		buyPrice = 1280000;
		virtualSpace = 460;
	};
	class O_Truck_03_fuel_F : O_Truck_03_transport_F {
		buyPrice = 1500000;
		virtualSpace = 450;
		blacklistedItems[] = { 
			"StolenCargo",
			"FreightCargo"
		};
	};
	class O_Truck_03_device_F : O_Truck_03_transport_F {
		buyPrice = 7200000;
		virtualSpace = 150;
	};

	class B_Truck_01_mover_F : BaseTruck {
		description = "The Heavy Expanded Mobility Tactical Truck is an 8x8 diesel-powered off-road truck. There are several versions covering the basic transport functions.";
		buyPrice = 478500;
		virtualSpace = 10;
		canTransfer = false;
		conditions = "[""HEMTTs""] call ULP_fnc_hasGroupPerk || { [""HGVDriver""] call ULP_fnc_hasPerk } || { [""Hato_Main"", 1] call ULP_fnc_hasAccess }";
		class Textures {
			class Hato : HatoTexture { 
				displayName = "HATO";
				textures[] = { 
					"data\textures\vehicles\land\HATO\hemtt_1.paa",
					"data\textures\vehicles\land\HATO\hemtt_2.paa",
					"data\textures\vehicles\land\HATO\hemtt_primer.paa"
				};
				class Lights : HatoColour {
					leftPos[] = {0.814453,5.87402,-0.947113};
					rightPos[] = {-0.736816,5.86328,-0.947113};
				};
			}; 
		};
	};
	class B_Truck_01_flatbed_F : B_Truck_01_mover_F {
		buyPrice = 492450;
		virtualSpace = 10;
		class Textures {
			class Hato : HatoTexture { 
				displayName = "HATO";
				textures[] = { 
					"data\textures\vehicles\land\HATO\hemtt_1.paa",
					"data\textures\vehicles\land\HATO\hemtt_2.paa",
					"data\textures\vehicles\land\HATO\hemtt_flatbed.paa"
				};
				class Lights : HatoColour {
					leftPos[] = {0.814453,5.87402,-0.947113};
					rightPos[] = {-0.736816,5.86328,-0.947113};
				};
			}; 
		};
	};
	class B_Truck_01_cargo_F : B_Truck_01_mover_F {
		buyPrice = 1170000;
		virtualSpace = 450;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Sand"; 
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_ammo_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_cargo_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_ammo_pacific_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_cargo_pacific_co.paa"
				};
			}; 
		};
	};
	class B_Truck_01_transport_F : B_Truck_01_mover_F {
		buyPrice = 1596500;
		virtualSpace = 535;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Sand"; 
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_cargo_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_cargo_olive_co.paa"
				};
			}; 
		};
	};
	class B_Truck_01_covered_F : B_Truck_01_mover_F {
		buyPrice = 1834550;
		virtualSpace = 590;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Sand"; 
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_cargo_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_cover_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_cargo_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_cover_olive_co.paa"
				};
			}; 
		};
	};
	class B_Truck_01_ammo_F : B_Truck_01_mover_F {
		buyPrice = 2156000;
		virtualSpace = 650;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Sand"; 
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_gamma\truck_01\data\truck_01_ammo_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ammo_olive_co.paa"
				};
			}; 
		};
	};
	class B_Truck_01_fuel_F : B_Truck_01_mover_F {
		buyPrice = 3000000;
		virtualSpace = 750;
		blacklistedItems[] = { 
			"StolenCargo",
			"FreightCargo"
		};
		class Textures {
			class Sand : BaseTexture {
				displayName = "Sand"; 
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_gamma\truck_01\data\truck_01_fuel_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_fuel_olive_co.paa"
				};
			}; 
		};
	};
	class B_Truck_01_box_F : B_Truck_01_mover_F {
		buyPrice = 2610000;
		virtualSpace = 800;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Sand"; 
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_gamma\truck_01\data\truck_01_mprimer_co.paa",
					"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ammo_olive_co.paa",
					"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
				};
			}; 
			class Ridge : BaseTexture { 
				displayName = "Ridge";
				locked = true;
				textures[] = { 
					"data\textures\vehicles\land\civilian\ridge_hemtt_1.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_2.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_3.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_4.paa"
				};
			}; 
		};
	};

	// BOATS --------------------------------------------------------------------------------------
	class C_Scooter_Transport_01_F : BaseShip {
		description = "A Personal WaterCraft of sit-down type. Its powerful engine and great maneuverability make this craft a lot of fun to drive.";
		buyPrice = 14300;
		virtualSpace = 5;
		class Textures {
			class Police : PoliceTextureBase {
				displayName = "MPU"; 
				textures[] = { "Data\Textures\Vehicles\Sea\Police\scooter.paa" }; 
			};
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_black_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_black_co.paa"
				 }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_White_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_White_co.paa"
				};
			}; 
			class Grey : BaseTexture { 
				displayName = "Grey";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Grey_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Grey_co.paa"
				};
			}; 
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Red_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Red_co.paa"
				};
			}; 
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_blue_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_blue_co.paa"
				};
			}; 
			class Green : BaseTexture { 
				displayName = "Green";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Green_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Green_co.paa"
				};
			}; 
			class Yellow : BaseTexture { 
				displayName = "Yellow";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Yellow_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Yellow_co.paa"
				};
			}; 
		};
	};

	class C_Rubberboat : BaseShip {
		description = "An inflatable boat, often nicknamed 'rubber duck', is a lightweight boat constructed from tubes containing pressurized gas.";
		buyPrice = 4150;
		virtualSpace = 50;
	};

	class C_Boat_Civil_01_F : BaseShip {
		description = "The luxury motorboat is an engine powered boat used by the Police and Altis' richest.";
		buyPrice = 153200;
		virtualSpace = 75;
		class Textures {
			class Civilian : BaseTexture {}; 
			class Police : PoliceTexture { textures[] = { "Data\Textures\Vehicles\Sea\Police\motorboat.paa" }; };
			class Medic : MedicTexture { textures[] = { "Data\Textures\Vehicles\Sea\Medic\motorboat.paa" }; };
		};
	};
	class C_Boat_Civil_01_police_F : C_Boat_Civil_01_F {};

	class C_Boat_Transport_02_F : BaseShip {
		description = "The Naval Special Warfare Rigid Hull Inflatable Boat is a fast, high-buoyancy all weather boat designed to transport a fully equipped team of eight-men and three crew members.";
		buyPrice = 297600;
		virtualSpace = 150;
		class Textures {
			class Civilian : BaseTexture {}; 
			class Police : PoliceTexture {
				textures[] = { 
					"Data\Textures\Vehicles\Sea\Police\RHIB_01.paa",
					"Data\Textures\Vehicles\Sea\Police\RHIB_02.paa"
				}; 
			};
			class Medic : MedicTexture {};
		};
	};
	class I_C_Boat_Transport_02_F : C_Boat_Transport_02_F {};

	class B_Boat_Armed_01_minigun_F : BaseShip {
		description = "This boat excels in speed and maneuverability and is used as a coastline guard boat and for special operations.";
		buyPrice = 14360500;
		virtualSpace = 80;
		garageLimit = 1;
		repairTime = 15;
		crushTime = 30;
		chopKeepChance = 85;
		chopTime = 120;
		enableRope = false;
		turrets[] = { { { 1 },  { "LMG_Minigun" },  { "2000Rnd_65x39_belt_Tracer_Red" } } };
		class Textures {
			class Police : PoliceTexture {
				textures[] = { 
					"Data\Textures\Vehicles\Sea\Police\speedboat_01.paa", 
					"Data\Textures\Vehicles\Sea\Police\speedboat_02.paa"
				};
			};
		};
	};

	class B_SDV_01_F : BaseShip {
		description = "The SDV is a manned submersible vehicle used to transport teams of divers over long distances under water.ply or using their own SCUBA gear.";
		buyPrice = 389500;
		virtualSpace = 5;
		garageLimit = 1;
		class Textures {
			class Police : PoliceTextureBase {
				displayName = "MPU"; 
				textures[] = { "Data\Textures\Vehicles\Sea\Police\sdv.paa" }; 
			};
		};
	};

	// HELICOPTERS --------------------------------------------------------------------------------------
	class B_UAV_01_F : BaseAir {
		description = "The Darter AR-2 is a miniature remote-controlled quadcopter perfect for reconnaissance and surveillance.";
		buyPrice = 98700;
	};
	class C_UAV_06_medical_F : B_UAV_01_F {
		description = "This commercial off-the-shelf utility drone uses 6 rotors to transport small payloads inside its external cargo case.";
		buyPrice = 109700;
	};
	
	class C_Heli_Light_01_civil_F : BaseAir {
		description = "A light single-engine helicopter used in special operations by the US Army since the Vietnam War.";
		buyPrice = 465000;
		virtualSpace = 5;
		garageLimit = 3;
		retrievalPerc = 0.02;
		class Textures {
			class Police : PoliceTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Police\hummingbird.paa" }; };
			class Medic : MedicTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Medic\hummingbird.paa" }; };
			class TotalRed : BaseTexture {
				displayName = "Total Red"; 
				textures[] = { "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa" }; 
			};
			class TotalBlue : BaseTexture { 
				displayName = "Total Blue";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa" };
			}; 
			class Sheriff : BaseTexture { 
				displayName = "Sheriff";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa" };
			}; 
			class Blueline : BaseTexture { 
				displayName = "Blueline";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueline_co.paa" };
			}; 
			class Elliptical : BaseTexture { 
				displayName = "Elliptical";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa" };
			}; 
			class Furious : BaseTexture { 
				displayName = "Furious";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa" };
			}; 
			class JeansBlue : BaseTexture { 
				displayName = "Jeans Blue";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa" };
			}; 
			class SpeedyRedline : BaseTexture { 
				displayName = "Speedy Redline";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa" };
			}; 
			class Sunset : BaseTexture { 
				displayName = "Sunset";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa" };
			}; 
			class Vrana : BaseTexture { 
				displayName = "Vrana";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa" };
			}; 
			class WavesBlue : BaseTexture { 
				displayName = "Waves Blue";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa" };
			}; 
			class Shadow : BaseTexture { 
				displayName = "Shadow";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\Heli_Light_01_ext_shadow_co.paa" };
			}; 
			class GrayWatcher : BaseTexture { 
				displayName = "Gray Watcher";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\Heli_Light_01_ext_graywatcher_co.paa" };
			}; 
			class Wasp : BaseTexture { 
				displayName = "Wasp";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa" };
			}; 
			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};
	class B_Heli_Light_01_F : C_Heli_Light_01_civil_F { buyPrice = 580000; };

	class O_Heli_Light_02_unarmed_F : BaseAir {
		description = "The PO-30 Orca is a transport and utility helicopter primarily developed for the Russian Air Force.";
		buyPrice = 1850000;
		virtualSpace = 25;
		retrievalPerc = 0.02;
		class Textures {
			class Police : PoliceTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Police\orca.paa" }; };
			class Medic : MedicTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Medic\orca.paa" }; };
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_CO.paa" }; 
			};
			class BlackWhite : BaseTexture {
				displayName = "Black / White"; 
				textures[] = { "\a3\air_f_heli\heli_light_02\data\heli_light_02_ext_opfor_v2_co.paa" }; 
			};
			class WhiteBlue : BaseTexture { 
				displayName = "White / Blue";
				textures[] = { "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_civilian_co.paa" };
			}; 
		};
	};

	class I_Heli_light_03_unarmed_F : BaseAir {
		description = "The WY-55 Hellcat is a multipurpose helicopter, most suited for utility and limited transport.";
		buyPrice = 2130000;
		virtualSpace = 20;
		retrievalPerc = 0.02;
		class Textures {
			class Police : PoliceTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Police\hellcat.paa" }; };
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "#(rgb,8,8,3)color(0.03,0.03,0.03,1)" }; 
			};
			class Green : BaseTexture {
				displayName = "Green"; 
				textures[] = { "\a3\air_f_epb\Heli_Light_03\data\Heli_Light_03_base_CO.paa" }; 
			};
		};
	};
	class I_Heli_light_03_F : I_Heli_light_03_unarmed_F {
		buyPrice = 23450000;
		garageLimit = 1;
		class Textures : Textures {
			class Police : Police {
				turrets[] = { { { -1 },  { "M134_minigun" },  { "5000Rnd_762x51_Yellow_Belt" } } };
			};
		};
	};

	class B_Heli_Transport_01_F : BaseAir {
		description = "The UH-80 Ghost Hawk is a medium-lift utility helicopter with stealth design.";
		buyPrice = 19450000;
		virtualSpace = 30;
		garageLimit = 1;
		turrets[] = {};
		class Textures {
			class Police : PoliceTextureBase {
				turrets[] = { 
					{ { 1 },  { "LMG_Minigun_Transport" },  { "2000Rnd_65x39_Belt_Tracer_Red" } },
					{ { 2 },  { "LMG_Minigun_Transport2" },  { "2000Rnd_65x39_Belt_Tracer_Red" } }
				};
			};
			class Civilian : BaseTexture {};
		};
	};

	class I_Heli_Transport_02_F : BaseAir {
		description = "A successor to the wide-spread Merlin, the CH-49 Mohawk is a primary transport with many other versions, serving effectively in evac, anti-submarine warfare, or armed air support roles.";
		buyPrice = 13240000;
		virtualSpace = 160;
		class Textures {
			class Medic : MedicTextureBase {
				textures[] = { 
					"Data\Textures\Vehicles\Air\Medic\mohawk_01.paa",
					"Data\Textures\Vehicles\Air\Medic\mohawk_02.paa",
					"Data\Textures\Vehicles\Air\Medic\mohawk_03.paa"
				}; 
			};
			class Ion : BaseTexture {
				displayName = "Ion"; 
				textures[] = { 
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_1_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_2_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_3_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\heli_transport_02_int_02_co.paa"
				 }; 
			};
			class Dahoman : BaseTexture {
				displayName = "Dahoman"; 
				textures[] = { 
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_1_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_2_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_3_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\heli_transport_02_int_02_co.paa" 
				}; 
			};
		};
	};

	class C_IDAP_Heli_Transport_02_F : I_Heli_Transport_02_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP"; 
				textures[] = { 
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_1_IDAP_CO.paa",
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_2_IDAP_CO.paa",
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_3_IDAP_CO.paa",
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_int_02_IDAP_CO.paa" 
				}; 
			};
		};
	};

	class O_Heli_Transport_04_black_F : BaseAir {
		description = "The Mi-290 Taru is a heavy utility helicopter with coaxial rotors and a unique modular construction. Various mission pods allow the Taru to serve many different roles.";
		buyPrice = 11350000;
		garageLimit = 1;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				factions[] = { "Civilian", "Police" };
			};
		};
	};
	class O_Heli_Transport_04_bench_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 11176500;
		virtualSpace = 0;
	};
	class O_Heli_Transport_04_covered_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 12670000;
		virtualSpace = 35;
	};
	class O_Heli_Transport_04_box_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 28900500;
		virtualSpace = 250;
	};
	class O_Heli_Transport_04_ammo_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 29460000;
		virtualSpace = 280;
	};
	class O_Heli_Transport_04_fuel_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 13640000;
		virtualSpace = 150;
	};
	class O_Heli_Transport_04_medevac_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 11983000;
		virtualSpace = 40;
		class Textures {
			class Medic : MedicTextureBase {
				textures[] = { 
					"Data\Textures\Vehicles\Air\Medic\taru_01.paa", 
					"Data\Textures\Vehicles\Air\Medic\taru_02.paa", 
					"Data\Textures\Vehicles\Air\Medic\taru_03.paa", 
					"Data\Textures\Vehicles\Air\Medic\taru_04.paa"
				}; 
			};
		};
	};

	class B_Heli_Transport_03_unarmed_F : BaseAir {
		description = "A twin-engine, tandem rotor heavy-lift helicopter. Its primary role is the transportation of troops, vehicles and cargo.";
		buyPrice = 33400750;
		virtualSpace = 500;
		garageLimit = 1;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				factions[] = { "Civilian", "Police" };
				textures[] = { 
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_black_co.paa",
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_black_co.paa"
				 }; 
			};
			class Olive : BaseTexture {
				displayName = "Olive"; 
				textures[] = { 
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_co.paa",
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_co.paa"
				}; 
			};
		};
	};

	class B_Heli_Attack_01_F : BaseAir {
		description = "A two-seat reconnaissance and target designation helicopter used to seek targets for gunships.";
		buyPrice = 146560000;
		garageLimit = 1;
	};

	class O_Heli_Attack_02_F : B_Heli_Attack_01_F {
		description = "A multipurpose successor to the Mi-24, the Mi-48 Kajman (designated 'Hornet') is a large gunship and attack helicopter with troop transport capacity for 8 passengers";
		buyPrice = 212340000;
		virtualSpace = 30;
	};

	// PLANES --------------------------------------------------------------------------------------
	class C_Plane_Civil_01_F : BaseAir {
		description = "The Caesar BTT is one of the fastest fixed-gear, single-engine piston aircraft, reaching a speed of 235 knots (435 km/h) true air speed at 25,000 feet (7,600 m).";
		buyPrice = 1256000;
		virtualSpace = 5;
		retrievalPerc = 0.02;
	};
	class C_Plane_Civil_01_racing_F : C_Plane_Civil_01_F {};

	class B_T_VTOL_01_infantry_F : BaseAir {
		description = "The V-44X Blackfish’s third-generation tilt-rotor VTOL technology allows this long endurance aircraft to conveniently utilize a wide range of airfields and runways.";
		buyPrice = 75500000;
		virtualSpace = 650;
		garageLimit = 1;
		retrievalPerc = 0.0025;
	};
	class B_T_VTOL_01_vehicle_F : B_T_VTOL_01_infantry_F {
		buyPrice = 85750000;
		virtualSpace = 700;
	};

	class O_T_VTOL_02_infantry_F : B_T_VTOL_01_infantry_F {
		description = "The most promising prototype built by CSAT engineers presents an extremely progressive design with many unique features and top-notch bleeding-edge technologies.";
		buyPrice = 115650000;
		virtualSpace = 180;
		turrets[] = {};
	};
	class O_T_VTOL_02_vehicle_F : O_T_VTOL_02_infantry_F {
		buyPrice = 125530000;
		virtualSpace = 230;
	};

	class I_Plane_Fighter_03_CAS_F : BaseAir {
		description = "The A-143 Buzzard is a single seat, light, multipurpose combat aircraft able to carry a wide range of equipment and weaponry.";
		buyPrice = 73350000;
		garageLimit = 1;
		retrievalPerc = 0.0025;
		pylons[] = { "", "", "", "", "", "", "", "", "", "", "", "", "" };
		turrets[] = {};
	};
	class I_Plane_Fighter_04_F : I_Plane_Fighter_03_CAS_F { 
		description = "The A-149 Gryphon is a fourth-generation, single-seat, single-engine, and all-weather tactical fighter jet.";
		buyPrice = 75500000; 
	};
	
	class B_Plane_CAS_01_F : I_Plane_Fighter_03_CAS_F { 
		description = "The A-164 Wipeout is a single-seat aircraft used for close air support and air interdiction.";
		buyPrice = 90500000; 
	};
	class B_Plane_Fighter_01_F : I_Plane_Fighter_03_CAS_F { 
		description = "The F/A-181 Black Wasp II is a fifth-generation, single-seat, twin-engine, all-weather tactical fighter jet.";
		buyPrice = 105500000; 
	};
	class B_Plane_Fighter_01_Stealth_F : B_Plane_Fighter_01_F { 
		buyPrice = 115600000;
	};
	class O_Plane_CAS_02_F : I_Plane_Fighter_03_CAS_F { 
		description = "The To-199 Neophron is a new addition to CSAT air forces. An agile single-seat aircraft is used for close air support but can also take down air threats.";
		buyPrice = 86500000; 
	};
	class O_Plane_Fighter_02_F : I_Plane_Fighter_03_CAS_F { 
		description = "The To-201 Shikra is a fifth-generation, single-seat, twin-engine, all-weather tactical fighter jet.";
		buyPrice = 115500000;
	};
	class O_Plane_Fighter_02_Stealth_F : O_Plane_Fighter_02_F {
		buyPrice = 130500000; 
	};

	// CONTAINERS --------------------------------------------------------------------------------------
	class B_Slingload_01_Cargo_F : Base {
		description = "";
		buyPrice = 0;
		virtualSpace = 250;
		garageLimit = 1;
	};
	class B_Slingload_01_Fuel_F : B_Slingload_01_Cargo_F {
		description = "";
		buyPrice = 0;
		virtualSpace = 100;
		blacklistedItems[] = { 
			"StolenCargo",
			"FreightCargo"
		};
	};

	class Land_Pod_Heli_Transport_04_box_black_F : B_Slingload_01_Cargo_F {
		description = "";
		buyPrice = 0;
		virtualSpace = 125;
	};
	class Land_Pod_Heli_Transport_04_fuel_black_F : B_Slingload_01_Cargo_F {
		description = "";
		buyPrice = 0;
		virtualSpace = 50;
		blacklistedItems[] = { 
			"StolenCargo",
			"FreightCargo"
		};
	};

	// TEMP --------------------------------------------------------------------------------------
	class Land_Bodybag_01_black_F : Base {
		virtualSpace = 0;
		garageLimit = 0;
		tempStorage = true;
	};

	// HOUSING --------------------------------------------------------------------------------------
	class Land_PlasticCase_01_small_F : Base { // Addon House
		virtualSpace = 500;
		garageLimit = 0;
		isHouse = true;
	};
	class Land_PlasticCase_01_medium_F : Land_PlasticCase_01_small_F { virtualSpace = 1000; }; // Small House
	class Land_PlasticCase_01_large_F : Land_PlasticCase_01_small_F { virtualSpace = 2000; }; // Small House
	class Land_PlasticCase_01_large_gray_F : Land_PlasticCase_01_small_F { virtualSpace = 1000; }; // Lighthouse
	class B_supplyCrate_F : Land_PlasticCase_01_small_F { virtualSpace = 3000; }; // Big House
	class Land_Cargo20_white_F : Land_PlasticCase_01_small_F { virtualSpace = 5000; }; // Warehouse / Boat
	class Land_Cargo20_grey_F : Land_PlasticCase_01_small_F { virtualSpace = 20000; }; // Military Offices
	class CargoNet_01_box_F : Land_PlasticCase_01_small_F { virtualSpace = 10000; }; // DMT
	class C_IDAP_supplyCrate_F : Land_PlasticCase_01_small_F { virtualSpace = 8500; }; // Office Building

	class Land_CargoBox_V1_F : Land_Bodybag_01_black_F { requireItems = true; };
	class Land_PortableServer_01_black_F : Land_CargoBox_V1_F {};

	// SOUNDS --------------------------------------------------------------------------------------
	class Siren_1 { sound = "Siren_1"; };
	class Siren_2 { sound = "Siren_2"; };
	class Siren_3 { sound = "Siren_3"; };
	class Siren_4 { sound = "Siren_4"; };
	class Siren_5 { sound = "Siren_5"; };
	class Siren_6 { sound = "Siren_6"; };
	class Siren_7 { sound = "Siren_7"; };
	class Siren_8 { sound = "Siren_8"; };
	class Siren_9 { sound = "Siren_9"; };
};
