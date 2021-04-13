class CfgVehicles {
	retrievalPerc = 0.02;
	chopKeepChance = 80;
	chopPerc = 0.35;
	chopTime = 300;

	class Base {
		virtualSpace = 0;
		garageLimit = 4;
		isHouse = false;
		conditions = "true";
		class Textures {};
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
		leftColour[] = {0.1, 0.1, 20};
		rightColour[] = {0.1, 0.1, 20};
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

	class PoliceTexture : BaseTexture {
		factions[] = { "Police" };
		class Siren {
			SFX[] = { "Police_One" };
		};
		class Lights : PoliceColour {};
	};
	
	class MedicTexture : BaseTexture {
		factions[] = { "Medic" };
		class Siren {
			SFX[] = { "Police_One" };
		};
		class Lights : MedicColour {};
	};

	class HatoTexture : BaseTexture {
		factions[] = { "Hato" };
		class Siren {
			SFX[] = { "Police_One" };
		};
		class Lights : HatoColour {};
	};

	class BaseChromeGreen : BaseTexture {
		displayName = "Chrome Green";
		materials[] = { "Data\Textures\Vehicles\Global\Chrone\green.paa" };
		locked = true;
	};
	class BaseChromeBlue : BaseChromeGreen {
		displayName = "Chrome Blue";
		materials[] = { "Data\Textures\Vehicles\Global\Chrone\blue.paa" };
	};
	class BaseChromeRed : BaseChromeGreen {
		displayName = "Chrome Red";
		materials[] = { "Data\Textures\Vehicles\Global\Chrone\red.paa" };
	};
	class BaseChromeSilver : BaseChromeGreen {
		displayName = "Chrome Silver";
		materials[] = { "Data\Textures\Vehicles\Global\Chrone\silver.paa" };
	};
	class BaseChromeGold : BaseChromeGreen {
		displayName = "Chrome Gold";
		materials[] = { "Data\Textures\Vehicles\Global\Chrone\gold.paa" };
	};

	// CARS --------------------------------------------------------------------------------------
	class C_Kart_01_Blu_F : Base {
		description = "Kart is a small four-wheeled vehicle propelled by gravity, gas or electricity. This gas powered kart is used for recreational racing in outdoor or indoor amusement parks. It has 4-stroke engine offering up to 20 hp and should not be operated by drivers under 18 years old.";
		buyPrice = 2500;
		virtualSpace = 0;
		garageLimit = 1;
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
		buyPrice = 11300;
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
		description = "A four-seat hatchback car mass-produced in the Far East to satisfy increasing demand for family cars. Economical operation, enhanced safety and a roomy trunk made these cars widely popular in the whole of Europe. Also comes in a sporty version.";
		buyPrice = 21450;
		virtualSpace = 25;
		class Textures {
			class PoliceWhite : PoliceTexture { 
				displayName = "General Response";
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_white.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {14918.6,15010.6,2.00029};
					rightPos[] = {14917.6,15010.6,1.95768};
				};
			};
			class PoliceBlack : PoliceWhite { 
				displayName = "Armed Response";
				conditions = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_black.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {14918.6,15010.6,2.00029};
					rightPos[] = {14917.6,15010.6,1.95768};
				};
			};
			class PoliceANPR : PoliceWhite { 
				displayName = "Interceptor";
				conditions = "[""Police_RPU"", 1] call ULP_fnc_hasAccess";
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_ANPR.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {14918.6,15010.6,2.00029};
					rightPos[] = {14917.6,15010.6,1.95768};
				};
			};
			class Medic : MedicTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Medic\hatchback.paa" }; 
				class Lights : MedicColour {
					leftPos[] = {14918.6,15010.6,2.00029};
					rightPos[] = {14917.6,15010.6,1.95768};
				};
			};
			class Hato : HatoTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Hato\hatchback.paa" }; 
				class Lights : HatoColour {
					leftPos[] = {14918.6,15010.6,2.00029};
					rightPos[] = {14917.6,15010.6,1.95768};
				};
			};
			class Black : BaseTexture {
				displayName = "Black";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa" };
			};
			class BlackWhiteSport : BaseTexture {
				displayName = "Black/White Sport"; 
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa" }; 
			};
			class Grey : BaseTexture {
				displayName = "Grey"; 
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa" }; 
			};
			class Beige : BaseTexture { 
				displayName = "Beige";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa" }; 
			};
			class BeigeSport : BaseTexture { 
				displayName = "Beige Sport";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa" }; 
			};
			class RedSport : BaseTexture { 
				displayName = "Red Sport";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				factions[] = { "Civilian", "Police" };
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa" }; 
			};
			class BlueSport : BaseTexture { 
				displayName = "Blue Sport";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa" }; 
			};
			class DarkBlue : BaseTexture { 
				displayName = "Dark Blue";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa" }; 
			};
			class DarkBlueSport : BaseTexture { 
				displayName = "Dark Blue Sport";
				factions[] = { "Civilian", "Civilian" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa" }; 
			};
			class Green : BaseTexture { 
				displayName = "Green";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa" }; 
			};
			class GreenSport : BaseTexture { 
				displayName = "Green Sport";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa" }; 
			};
			class Yellow : BaseTexture { 
				displayName = "Yellow";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa" }; 
			};
			class OrangeSport : BaseTexture { 
				displayName = "Orange Sport";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa" }; 
			};
		};
	};
	class C_Hatchback_01_sport_F : C_Hatchback_01_F { buyPrice = 276500; };

	class C_Offroad_01_F : Base {
		description = "	The 4x4 pickup by Generic Motors is a perfect choice for farmers and hunters. The durable chassis and powerful engine have been designed to withstand anything from the cratered highways of Central Europe to the rugged terrain of the Mediterranean. The armed version is fitted either with a .50 caliber heavy machine gun or an anti-tank recoilless rifle. It provides the combination of mobility and firepower to many paramilitary and guerilla forces in local conflicts around the globe. Specialized versions, which sport a hard rear cover and rack-mounted communications equipment, are in use by law enforcement, national park rangers, and armed forces. These vehicles feature a large floodlight, loudspeakers, and long-range antennas.";
		buyPrice = 42800;
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
	class B_G_Offroad_01_armed_F : C_Offroad_01_F { buyPrice = 4280000; };
	class B_GEN_Offroad_01_gen_F : C_Offroad_01_F {};
	class C_IDAP_Offroad_01_F : C_Offroad_01_F {};
	class C_Offroad_01_covered_F : C_Offroad_01_F {
		buyPrice = 49100;
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
	class C_Offroad_01_comms_F : C_Offroad_01_covered_F { buyPrice = 54450; };
	class C_Offroad_01_repair_F : C_Offroad_01_covered_F { buyPrice = 132400; };

	class C_Offroad_02_unarmed_F : Base {
		description = "The MB 4WD is a modern four-wheel drive off-road vehicle with a distinctive construction. The vehicle was produced in the US and exists in a number of different editions. Thanks to the powerful engine, durable chassis and great maneuverability, this vehicle can handle difficult terrains from dry deserts to humid jungles or artic wastelands.";
		buyPrice = 38750;
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
	class C_IDAP_Offroad_02_unarmed_F : C_Offroad_02_unarmed_F {};
	class I_C_Offroad_02_LMG_F : C_Offroad_02_unarmed_F { buyPrice = 670300; };

	class C_SUV_01_F : Base {
		description = "A full-size luxury crossover SUV, not particularly suitable for off-road but with good on-road ability. Its powerful engine and 4x4 contribute to the enjoyable rides in higher speeds.";
		buyPrice = 71200;
		virtualSpace = 45;
		class Textures {
			class PoliceWhite : PoliceTexture { 
				displayName = "General Response";
				remoteGates = true;
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_white.paa" };
				class Lights : PoliceColour {
					leftPos[] = {14924.6,15011.1,2.66146};
					rightPos[] = {14923.8,15011.1,2.66146};
				};
			};
			class PoliceBlack : PoliceWhite { 
				displayName = "Armed Response";
				conditions = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_black.paa" };
				class Lights : PoliceColour {
					leftPos[] = {14924.6,15011.1,2.66146};
					rightPos[] = {14923.8,15011.1,2.66146};
				}; 
			};
			class PoliceANPR : PoliceWhite { 
				displayName = "Interceptor";
				conditions = "[""Police_RPU"", 1] call ULP_fnc_hasAccess";
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_ANPR.paa" };
				class Lights : PoliceColour {
					leftPos[] = {14924.6,15011.1,2.66146};
					rightPos[] = {14923.8,15011.1,2.66146};
				}; 
			};
			class Medic : MedicTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Medic\SUV.paa" }; 
				class Lights : MedicColour {
					leftPos[] = {14924.6,15011.1,2.66146};
					rightPos[] = {14923.8,15011.1,2.66146};
				};
			};
			class Hato : HatoTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Hato\SUV.paa" }; 
				class Lights : HatoColour {
					leftPos[] = {14924.6,15011.1,2.66146};
					rightPos[] = {14923.8,15011.1,2.66146};
				};
			};
			class Black : BaseTexture {
				displayName = "Black"; 
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" }; 
			};
			class Silver : BaseTexture { 
				displayName = "Silver";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				factions[] = { "Civilian", "Police" }; 
				conditions = "[player, [""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa" };
			};
		};
	};

	class C_Van_02_transport_F : Base {
		description = "The standard van can be used for a huge variety of practical purposes. This particular model features a long load length and excellent roof height, allowing for the transport of passengers, cargo, or even some smaller vehicles. Several aftermarket exterior components, such as a ladder, protective guards and a roof rack, can be fitted where appropriate. Specialized variants are used for emergency healthcare, patient evacuation and various utility services.";
		buyPrice = 88000;
		virtualSpace = 90;
		class Textures {
			class PoliceWhite : PoliceTexture { 
				displayName = "Public Order";
				textures[] = { "Data\Textures\Vehicles\Land\Police\van.paa" }; 
			};
			class PoliceUnmarked : PoliceWhite {
				displayName = "Unmarked"; 
				conditions = "[""Police_NCA"", 1] call ULP_fnc_hasAccess";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" }; 
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
	class C_IDAP_Van_02_transport_F : C_Van_02_transport_F {};
	class C_Van_02_vehicle_F : C_Van_02_transport_F {
		buyPrice = 96650;
		virtualSpace = 110;
	};
	class B_GEN_Van_02_vehicle_F : C_Van_02_vehicle_F {};
	class C_IDAP_Van_02_vehicle_F : C_Van_02_vehicle_F {};
	class C_Van_02_service_F : C_Van_02_vehicle_F {};

	class B_CTRG_LSV_01_light_F : Base {
		description = "The Prowler is a light strike vehicle (LSV). That means it’s agile, lightly armored and uses speed, maneuverability, and off-road mobility to avoid threats. Two configurations of Prowler exist. The armed variant is equipped with two machine guns. The front seated position carries .338 SPMG medium machine gun, while the top turret is equipped with a .50 cal heavy machine gun. With this arsenal, the Prowler is ideal for quick hit and run missions. The unarmed variant is stripped of all guns, but the back part of the vehicle is opened and has reserve seats for two additional soldiers.";
		buyPrice = 580000;
		virtualSpace = 50;
		garageLimit = 3;
		class Textures {
			class Police : PoliceTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Police\prowler.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {14913,15010.4,3.42215};
					rightPos[] = {14911.6,15010.4,3.42215};
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
	class B_T_LSV_01_unarmed_black_F : B_CTRG_LSV_01_light_F { buyPrice = 675000; };

	class O_LSV_02_unarmed_F : Base {
		description = "An agile, lightly protected vehicle for 5-6 soldiers – depending on the configuration. Qilin offers safe and fast operating speeds with superior levels of mobility and maneuverability. It is highly adaptable to severe, rugged and restrictive terrains while providing off-road, cross-country mobility under all types of weather conditions. CSAT Pacific forces primarily use the unarmed variant and the armed variant fitted with a 6.5 mm minigun.";
		buyPrice = 800000;
		virtualSpace = 50;
		garageLimit = 3;
		class Textures {
			class Police : PoliceTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Police\qilin.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {14907.3,15010.4,3.05463};
					rightPos[] = {14905.8,15010.4,3.06133};
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

	class B_MRAP_01_F : Base {
		description = "The Hunter is a Mine-Resistant Ambush Protected (MRAP) vehicle manufactured by US arms factories to provide troops with enhanced protection. The armored hull can withstand light weapons and protects the crew against landmines and improvised explosive devices. Even though the heavy armor and powerful engine cause increased fuel consumption, it has been favored by frontline troops over the light vehicles for its easy maintenance and good protection level.";
		buyPrice = 9800000;
		virtualSpace = 65;
		garageLimit = 1;
		garageDelay = 15;
		repairTime = 20;
		crushTime = 60;
		chopKeepChance = 95;
		chopTime = 300;
		class Textures {
			class Police : PoliceTexture {
				textures[] = {
					"Data\Textures\Vehicles\Land\Police\hunter_01.paa",
					"Data\Textures\Vehicles\Land\Police\hunter_02.paa"
				}; 
				class Lights : PoliceColour {
					leftPos[] = {14900.8,15007.9,4.97092};
					rightPos[] = {14898.9,15007.9,4.96987};
				};
			};
		};
	};

	class O_MRAP_02_F : Base {
		description = "The Ifrit is a new Mine-Resistant Ambush Protected (MRAP) vehicle designed and manufactured in Russia. Its strengths lie in reliability in extreme weather conditions and crew protection, but its manufacturing costs are somewhat higher compared to other MRAPs.";
		buyPrice = 7500000;
		virtualSpace = 65;
		garageLimit = 2;
		garageDelay = 15;
		repairTime = 20;
		crushTime = 60;
		chopKeepChance = 90;
		chopTime = 300;
		turrets[] = { { "SmokeLauncher" } };
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
				textures[] = { 
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\goldLine_01.paa",
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\goldLine_02.paa"
				}; 
			};
			class Oil : BaseTexture { 
				displayName = "Oil Spill";
				locked = true;
				textures[] = { 
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\oil_01.paa",
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\oil_02.paa"
				}; 
			};
			class ChromeGreen : BaseChromeGreen {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrone\green.paa",
					"Data\Textures\Vehicles\Global\Chrone\green.paa"
				};
			};
			class ChromeBlue : BaseChromeBlue {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrone\blue.paa",
					"Data\Textures\Vehicles\Global\Chrone\blue.paa"
				};
			};
			class ChromeRed : BaseChromeRed {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrone\red.paa",
					"Data\Textures\Vehicles\Global\Chrone\red.paa"
				};
			};
			class ChromeSilver : BaseChromeSilver {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrone\silver.paa",
					"Data\Textures\Vehicles\Global\Chrone\silver.paa"  
				};
			};
			class ChromeGold : BaseChromeGold {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrone\gold.paa",
					"Data\Textures\Vehicles\Global\Chrone\gold.paa"  
				};
			};
		};
	};

	class I_MRAP_03_F : Base {
		description = "The Strider is a medium all-terrain vehicle with amphibious capability and enhanced crew protection, designed for reconnaissance and troop transport roles. It has been adopted by most of the AAF as a replacement for the older medium troop transports of the past decade. The unarmed version is fitted with an observation periscope package with thermal imaging and a laser marker.";
		buyPrice = 5750000;
		virtualSpace = 65;
		garageLimit = 2;
		garageDelay = 15;
		repairTime = 20;
		crushTime = 60;
		chopKeepChance = 90;
		chopTime = 300;
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
				textures[] = { "Textures\Vehicles\Land\Civilian\Strider\asiimov.paa" }; 
			};
			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};

	// TRUCKS --------------------------------------------------------------------------------------
	class C_Tractor_01_F : Base {
		description = "Found in farm barns across the globe, the common tractor is a reliable high torque engineering vehicle, used for towing trailers and many other agricultural tasks. This 2WD tractor with a diesel engine has proven itself reliable since the eighties. With solid maintenance and the occasional lick of fresh paint, this old workhorse has been in use by several generations of farmers to date.";
		buyPrice = 23150;
		virtualSpace = 10;
		garageLimit = 3;
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

	class C_Van_01_transport_F : Base {
		description = "The civilian 4x4 truck is a highly customizable truck with off-road capabilities preferred by the civilian population. It builds on retro design, but utilizes a modern engine and electronics. Most common track setups are boxed, cistern and pick-up set.";
		buyPrice = 190500;
		virtualSpace = 100;
		garageLimit = 3;
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
		buyPrice = 245000;
		virtualSpace = 150;
	};
	class C_Van_01_fuel_F : C_Van_01_transport_F {
		buyPrice = 210500;
		virtualSpace = 120;
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

	class I_Truck_02_transport_F : Base {
		description = "The Zamak heavy truck is a 6x6 vehicle used for transport, repair and utility. Fitted with a powerful V8 engine, these trucks are reliable even in harsh conditions.";
		buyPrice = 505000;
		virtualSpace = 280;
		garageLimit = 2;
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
	class C_IDAP_Truck_02_transport_F : I_Truck_02_transport_F {};
	class I_Truck_02_covered_F : I_Truck_02_transport_F {
		buyPrice = 560000;
		virtualSpace = 350;
	};
	class C_IDAP_Truck_02_F : I_Truck_02_covered_F {};
	class I_Truck_02_fuel_F : I_Truck_02_transport_F {
		buyPrice = 435000;
		virtualSpace = 200;
	};
	class C_IDAP_Truck_02_water_F : I_Truck_02_fuel_F {};

	class O_Truck_03_transport_F : Base {
		description = "The Tempest is a 6x6 mine resistant standard transport truck for the CSAT army. Its primary role is to carry troops and cargo under armor. The modular design of the truck allows several transport versions: cargo, refuel, medical, repair and ammo resupply.";
		buyPrice = 615500;
		virtualSpace = 370;
		garageLimit = 2;
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
					"\a3\soft_f_exp\truck_03\data\truck_03_cargo_ghex_co.paa"
				};
			}; 
		};
	};
	class O_Truck_03_covered_F : O_Truck_03_transport_F {
		buyPrice = 670500;
		virtualSpace = 410;
	};
	class O_Truck_03_ammo_F : O_Truck_03_transport_F {
		buyPrice = 710000;
		virtualSpace = 460;
	};
	class O_Truck_03_fuel_F : O_Truck_03_transport_F {
		buyPrice = 590500;
		virtualSpace = 350;
	};
	class O_Truck_03_device_F : O_Truck_03_transport_F {
		buyPrice = 1150000;
		virtualSpace = 150;
	};

	class B_Truck_01_mover_F : Base {
		description = "	The Heavy Expanded Mobility Tactical Truck is an 8x8 diesel-powered off-road truck. It servers as a standard heavy transport vehicle for BLUFOR armies. There are several versions covering the basic transport functions: cargo, refuel, medical, repair, and ammo resupply.";
		buyPrice = 334000;
		virtualSpace = 10;
		garageLimit = 2;
		class Textures {
			class Hato : HatoTexture { 
				displayName = "HATO";
				textures[] = { 
					"data\textures\vehicles\land\HATO\hemtt_1.paa",
					"data\textures\vehicles\land\HATO\hemtt_2.paa",
					"data\textures\vehicles\land\HATO\hemtt_primer.paa"
				};
			}; 
		};
	};
	class B_Truck_01_flatbed_F : B_Truck_01_mover_F {
		buyPrice = 376000;
		virtualSpace = 10;
		class Textures {
			class Hato : HatoTexture { 
				displayName = "HATO";
				textures[] = { 
					"data\textures\vehicles\land\HATO\hemtt_1.paa",
					"data\textures\vehicles\land\HATO\hemtt_2.paa",
					"data\textures\vehicles\land\HATO\hemtt_flatbed.paa"
				};
			}; 
		};
	};
	class B_Truck_01_cargo_F : B_Truck_01_mover_F {
		buyPrice = 690500;
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
		buyPrice = 795000;
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
		buyPrice = 865000;
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
		buyPrice = 905000;
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
		buyPrice = 880000;
		virtualSpace = 500;
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
	class B_Truck_01_box_F : Base {
		buyPrice = 995000;
		virtualSpace = 800;
		garageLimit = 3;
		garageDelay = 30;
		repairTime = 15;
		crushTime = 30;
		chopKeepChance = 85;
		chopTime = 120;
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
	class C_Scooter_Transport_01_F : Base {
		description = "	A Personal WaterCraft of sit-down type. This small-hulled craft driven by a jet-propulsion system offers seats for 3 people. Its powerful engine and great maneuverability make this craft a lot of fun to drive. And of course this water transport vehicle is perfectly suited for military use as well.";
		buyPrice = 14300;
		virtualSpace = 5;
		class Textures {
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

	class C_Rubberboat : Base {
		description = "An inflatable boat, often nicknamed 'rubber duck', is a lightweight boat constructed from tubes containing pressurized gas. Inflatables typically come in lengths between 2 to 7 meters. Due to their speed, weight and portability, inflatable boats are used in diverse roles such as lifeguard and rescue boats and even more often in the military as landing craft.";
		buyPrice = 4150;
		virtualSpace = 50;
	};

	class C_Boat_Civil_01_F : Base {
		description = "The luxury motorboat is an engine powered boat used by the Police and Altis' richest. Its speed and maneuverability is almost on par with military speedboat.";
		buyPrice = 153200;
		virtualSpace = 75;
		class Textures {
			class Civilian : BaseTexture {}; 
			class Police : PoliceTexture { textures[] = { "Data\Textures\Vehicles\Sea\Police\motorboat.paa" }; };
			class Medic : MedicTexture { textures[] = { "Data\Textures\Vehicles\Sea\Medic\motorboat.paa" }; };
		};
	};
	class C_Boat_Civil_01_police_F : C_Boat_Civil_01_F {};

	class C_Boat_Transport_02_F : Base {
		description = "	The Naval Special Warfare Rigid Hull Inflatable Boat is a fast, high-buoyancy all weather boat designed to transport a fully equipped team of eight-men and three crew members. It is also fully transportable by C-130 Hercules.";
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
		};
	};

	class B_Boat_Armed_01_minigun_F : Base {
		description = "	This V shaped boat with two powerful jet impellers excels in speed and maneuverability. It is used by both BLUFOR and OPFOR as a coastline guard boat and for special operations. The speedboat has a front-facing, remote controlled GMG turret. The OPFOR version is commonly equipped with a HMG in the rear, while BLUFOR speedboats are armed with a minigun.";
		buyPrice = 14360500;
		virtualSpace = 80;
		garageLimit = 1;
		repairTime = 15;
		crushTime = 30;
		chopKeepChance = 85;
		chopTime = 120;
		turrets[] = { { "GMG_40mm" } };
		class Textures {
			class Police : PoliceTexture {
				textures[] = { 
					"Data\Textures\Vehicles\Sea\Police\speedboat_01.paa", 
					"Data\Textures\Vehicles\Sea\Police\speedboat_02.paa"
				};
			};
		};
	};

	class B_SDV_01_F : Base {
		description = "The SDV is a manned submersible vehicle used to transport teams of divers over long distances under water. Its construction is based on the SEALs Delivery Vehicle from the early 21st century, but the engine and maneuverability have been increased rapidly. Divers drive the SDV while exposed to water and breathing from the vehicle's compressed air supply or using their own SCUBA gear. The SDV can take up to four passengers, but can be operated by just one person. It also contains a small compartment to store additional equipment.";
		buyPrice = 389500;
		virtualSpace = 5;
	};

	// HELICOPTERS --------------------------------------------------------------------------------------
	class B_UAV_01_F : Base {
		description = "The Darter AR-2 is a miniature remote-controlled quadcopter perfect for reconnaissance and surveillance. Darters are agile, silent and hard to detect. The ability to hover in one place and use the camera to observe a location is invaluable in setting ambushes.";
		buyPrice = 98700;
		virtualSpace = 0;
	};
	
	class C_Heli_Light_01_civil_F : Base {
		description = "A light single-engine helicopter used in special operations by the US Army since the Vietnam War. It now exists in several variants used by both military and civilian transport. The M-900 is a civilian version. Closed cabin and comfortable interior provides space for two passengers.";
		buyPrice = 565000;
		virtualSpace = 5;
		garageLimit = 2;
		class Textures {
			class Police : PoliceTexture { textures[] = { "Data\Textures\Vehicles\Air\Police\hummingbird.paa" }; };
			class Medic : MedicTexture { textures[] = { "Data\Textures\Vehicles\Air\Medic\hummingbird.paa" }; };
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
	class B_Heli_Light_01_F : C_Heli_Light_01_civil_F { 
		description = "A light single-engine helicopter used in special operations by the US Army since the Vietnam War, it now exists in several variants fielded by both militaries and the civilian populace. The MH-9 Hummingbird is mostly used as a special forces troop transport with its two outboard benches.";
		buyPrice = 780000; 
	};

	class O_Heli_Light_02_unarmed_F : Base {
		description = "The PO-30 Orca is a transport and utility helicopter primarily developed for the Russian Air Force. The helicopter was intended to replace the Mi-8 and can be used for reconnaissance, transporting a full squad with combat gear and special operations.";
		buyPrice = 2350000;
		virtualSpace = 25;
		garageLimit = 1;
		turrets[] = { { "CMFlareLauncher" } };
		class Textures {
			class Police : PoliceTexture { textures[] = { "Data\Textures\Vehicles\Air\Police\orca.paa" }; };
			class Medic : MedicTexture { textures[] = { "Data\Textures\Vehicles\Air\Medic\orca.paa" }; };
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

	class I_Heli_light_03_unarmed_F : Base {
		description = "The WY-55 Hellcat is a multipurpose military helicopter, most suited for anti-surface, battlefield utility with limited transport capability. It replaces its predecessor, the Super Lynx, with improved maneuverability, durability, and protection. The armed version is fitted with twin miniguns and unguided rockets. Its also fitted with a thermal camera that can be controlled by the co-pilot.";
		buyPrice = 2130000;
		virtualSpace = 20;
		garageLimit = 1;
		turrets[] = { { "CMFlareLauncher" } };
		class Textures {
			class Police : PoliceTexture {
				textures[] = { "Data\Textures\Vehicles\Air\Police\hellcat.paa" };
				turrets[] = { { "missiles_DAR", "CMFlareLauncher" } };
			};
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
		turrets[] = { { "M134_minigun", "missiles_DAR", "CMFlareLauncher" } };
	};

	class B_Heli_Transport_01_F : Base {
		description = "The UH-80 Ghost Hawk is a BLUFOR medium-lift utility helicopter with stealth design. The Ghost Hawk was developed for special operations with a focus on deployment and extraction of troops undetected by enemy radar. Some pilots say the stealth design hindered the versatility of the helicopter compared to its predecessor, the UH-60. Nevertheless, the Ghost Hawk is now used as a primary transport helicopter in the BLUFOR army.";
		buyPrice = 19450000;
		virtualSpace = 30;
		garageLimit = 1;
		turrets[] = { { "LMG_Minigun_Transport", "LMG_Minigun_Transport2", "CMFlareLauncher" } };
		class Textures {
			class Police : BaseTexture { turrets[] = { { "CMFlareLauncher" } }; };
			class Civilian : BaseTexture {};
		};
	};

	class I_Heli_Transport_02_F : Base {
		description = "A successor to the wide-spread Merlin, the CH-49 Mohawk is a primary transport used by the AAF. It can carry up to 16 soldiers plus crew. Besides the transport version, many other versions of the Mohawk exist, serving effectively in evac, anti-submarine warfare, or armed air support roles. Upgrades from its predecessor consist of more powerful engines and construction changes fully utilizing modern materials.";
		buyPrice = 13240000;
		virtualSpace = 55;
		garageLimit = 1;
		chopKeepChance = 85;
		turrets[] = { { "CMFlareLauncher" } };
		class Textures {
			class Medic : MedicTexture {
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
	class C_IDAP_Heli_Transport_02_F : I_Heli_Transport_02_F {};

	class O_Heli_Transport_04_black_F : Base {
		description = "The Mi-290 Taru is a heavy utility helicopter with coaxial rotors and a unique modular construction. Various mission pods allow the Taru to serve many different roles. It can transport cargo, troops, and provide battlefield supplies (ammunition, fuel, repair facilities, and medical equipment). The helicopter can also transport light vehicles thanks to its sling loading capabilities.";
		buyPrice = 11350000;
		virtualSpace = 0;
		garageLimit = 1;
		chopKeepChance = 85;
		chopPerc = 0.20;
		chopTime = 60;
		turrets[] = { { "CMFlareLauncher" } };
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
		virtualSpace = 70;
	};
	class O_Heli_Transport_04_ammo_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 29460000;
		virtualSpace = 80;
	};
	class O_Heli_Transport_04_fuel_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 13640000;
		virtualSpace = 50;
	};
	class O_Heli_Transport_04_medevac_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 11983000;
		virtualSpace = 40;
		class Textures {
			class Medic : MedicTexture {
				textures[] = { 
					"Data\Textures\Vehicles\Air\Medic\taru_01.paa", 
					"Data\Textures\Vehicles\Air\Medic\taru_02.paa", 
					"Data\Textures\Vehicles\Air\Medic\taru_03.paa", 
					"Data\Textures\Vehicles\Air\Medic\taru_04.paa"
				}; 
			};
		};
	};

	class B_Heli_Transport_03_unarmed_F : Base {
		description = "A twin-engine, tandem rotor heavy-lift helicopter. It is a modernized version of the CH-47 Chinook and its primary role is the transportation of troops, vehicles and cargo.";
		buyPrice = 33400750;
		virtualSpace = 100;
		garageLimit = 1;
		chopKeepChance = 95;
		chopPerc = 0.20;
		chopTime = 300;
		turrets[] = { { "CMFlareLauncher" } };
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
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

	class B_Heli_Attack_01_F : Base {
		description = "A two-seat reconnaissance and target designation helicopter used to seek targets for gunships. Even though the construction dates back some time and the program faced cancellation in the first years of the 21st century, the project was finished successfully and the Blackfoot became the first attack helicopter to field stealth technology, which was even applied to the main rotor. The Blackfoot is extremely fast, agile and hard to detect even by contemporary sensors. However it is slowly becoming outdated.";
		buyPrice = 146560000;
		virtualSpace = 0;
		garageLimit = 1;
		chopKeepChance = 97;
		chopPerc = 0.20;
		chopTime = 600;
		turrets[] = { { "CMFlareLauncher", "gatling_20mm", "missiles_DAGR", "missiles_ASRAAM" } };
	};
	class O_Heli_Attack_02_F : B_Heli_Attack_01_F {
		description = "A multipurpose successor to the Mi-24, the Mi-48 Kajman (BLUFOR designation «Hornet») is a large gunship and attack helicopter with troop transport capacity for 8 passengers. The front part of the helicopter is based on the Mi-28 attack helicopter, the coaxial rotor providing increased stability is taken from the Ka-52 and the passenger transport capacity is the same as the Mi-24.";
		buyPrice = 212340000;
		virtualSpace = 30;
		turrets[] = { { "CMFlareLauncher", "gatling_30mm", "missiles_SCALPEL", "rockets_Skyfire", "Laserdesignator_mounted" } };
	};

	// PLANES --------------------------------------------------------------------------------------
	class C_Plane_Civil_01_F : Base {
		description = "Caesar BTT is a single-engine, fixed-gear, low-wing general aviation aircraft built from composite materials. The Caesar BTT is one of the fastest fixed-gear, single-engine piston aircraft, reaching a speed of 235 knots (435 km/h) true air speed at 25,000 feet (7,600 m). It is used by civilians and smaller shipping companies all around the world.";
		buyPrice = 1256000;
		virtualSpace = 5;
		garageLimit = 2;
	};
	class C_Plane_Civil_01_racing_F : C_Plane_Civil_01_F {};

	class B_T_VTOL_01_infantry_F : Base {
		description = "The V-44X Blackfish’s third-generation tilt-rotor VTOL (Vertical Take-Off and Landing) technology allows this long endurance aircraft to conveniently utilize a wide range of airfields and runways. It also provides unparalleled maneuverability with its unique ability to perform pylon turns or merely hover in place. The huge internal storage allows for transportation of vehicles up to the size and weight of AMV-7 Marshall APC in the vehicle transport variant or up to 32 fully armed soldiers with supplies in the infantry transport variant. The storage space of the gunship variant is fully occupied by automated weapon stations and carried ammunition.";
		buyPrice = 75500000;
		virtualSpace = 175;
		garageLimit = 1;
		retrievalPerc = 0.01;
		chopKeepChance = 95;
		chopPerc = 0.15;
		chopTime = 180;
		turrets[] = { { "CMFlareLauncher_Triples" } };
	};
	class B_T_VTOL_01_vehicle_F : B_T_VTOL_01_infantry_F {
		buyPrice = 85750000;
		virtualSpace = 225;
	};

	class O_T_VTOL_02_infantry_F : B_T_VTOL_01_infantry_F {
		description = "By far the largest CSAT joint development project to date was long troubled by the conflicting requirements of the participating armies who demanded an aircraft with VTOL capabilities. The planned budget was vastly exceeded several times and development was years behind schedule. The program eventually became one of the most expensive in military procurement history and despite a great deal of information remains classified and is often compared to the older F-35 program. The final solution was based upon the most promising prototype designed in Xi'an which was able to meet most of the requirements with satisfactory results. High running and maintenance costs remains a huge issue that plagues the reputation of the otherwise extremely progressive aircraft with many unique features and top-notch bleeding-edge technologies.";
		buyPrice = 115650000;
		virtualSpace = 80;
		turrets[] = { { "CMFlareLauncher", "gatling_30mm_VTOL_02", "missiles_SCALPEL", "rockets_Skyfire" } };
	};
	class O_T_VTOL_02_vehicle_F : O_T_VTOL_02_infantry_F {
		buyPrice = 125530000;
		virtualSpace = 95;
		turrets[] = { { "CMFlareLauncher", "gatling_30mm_VTOL_02", "missiles_SCALPEL", "rockets_Skyfire" } };
	};

	class I_Plane_Fighter_03_CAS_F : Base {
		description = "The A-143 Buzzard is a single seat, light, multipurpose combat aircraft able to carry a wide range of equipment and weaponry. Possessing seven hard-points, three are located under each wing with one mounted under the fuselage.";
		buyPrice = 73350000;
		virtualSpace = 0;
		garageLimit = 1;
		retrievalPerc = 0.01;
		chopKeepChance = 99;
		chopPerc = 0.10;
		chopTime = 300;
		turrets[] = { { "CMFlareLauncher", "Twin_Cannon_20mm", "missiles_SCALPEL", "missiles_ASRAAM", "GBU12BombLauncher_Plane_Fighter_03_F" } };
	};
	class I_Plane_Fighter_04_F : I_Plane_Fighter_03_CAS_F { 
		description = "The A-149 Gryphon is a fourth-generation, single-seat, single-engine, and all-weather tactical fighter jet. The aircraft was designed as a multi-role platform at an affordable cost, and unlike some of the larger air-superiority jets, it can also perform well in low-altitude flight. Despite its aging platform, the A-149 has still been upgraded with the newest sensors and weapons systems.";
		buyPrice = 75500000; 
		turrets[] = { { "CMFlareLauncher_Singles", "weapon_Fighter_Gun20mm_AA" } };
	};
	class B_Plane_CAS_01_F : I_Plane_Fighter_03_CAS_F { 
		description = "	The A-164 Wipeout is a single-seat aircraft used for close air support and air interdiction. The life-cycle of its predecessor, the A-10, ended in 2030 and the need for replacement grew more important with the rising tension in the Pacific. A limited development budget did not allow for a fresh start, instead the concept of the A-10 was improved with better shape, engines and armaments.";
		buyPrice = 90500000; 
		turrets[] = { { "CMFlareLauncher", "Gatling_30mm_Plane_CAS_01_F", "Missile_AA_04_Plane_CAS_01_F", "Missile_AGM_02_Plane_CAS_01_F", "Rocket_04_HE_Plane_CAS_01_F", "Rocket_04_AP_Plane_CAS_01_F", "Bomb_04_Plane_CAS_01_F" } };
	};
	class B_Plane_Fighter_01_F : I_Plane_Fighter_03_CAS_F { 
		description = "The F/A-181 Black Wasp II is a fifth-generation, single-seat, twin-engine, all-weather tactical fighter jet. The aircraft was designed primarily as an air-superiority fighter, but also has ground attack capabilities. Its additional external hardpoints enable the aircraft to carry a wide variety of weapons configurations. The Black Wasp is fitted with the required equipment for carrier operations.";
		buyPrice = 105500000; 
		turrets[] = { { "CMFlareLauncher_Singles", "weapon_Fighter_Gun20mm_AA" } };
	};
	class B_Plane_Fighter_01_Stealth_F : B_Plane_Fighter_01_F { 
		buyPrice = 115600000; 
		turrets[] = { { "CMFlareLauncher_Singles", "weapon_Fighter_Gun20mm_AA" } };
	};
	class O_Plane_CAS_02_F : I_Plane_Fighter_03_CAS_F { 
		description = "The To-199 Neophron is a new addition to CSAT air forces. An agile single-seat aircraft is used for close air support but can also take down air threats. It cannot carry as much payload as NATO's A-164 and has to rearm more often, but it can take-off from even the roughest terrain, not being as dependent on air bases or aircraft carriers.";
		buyPrice = 86500000; 
		turrets[] = { { "CMFlareLauncher", "Cannon_30mm_Plane_CAS_02_F", "Missile_AA_03_Plane_CAS_02_F", "Missile_AGM_01_Plane_CAS_02_F", "Rocket_03_HE_Plane_CAS_02_F", "Rocket_03_AP_Plane_CAS_02_F", "Bomb_03_Plane_CAS_02_F" } };
	};
	class O_Plane_Fighter_02_F : I_Plane_Fighter_03_CAS_F { 
		description = "The To-201 Shikra is a fifth-generation, single-seat, twin-engine, all-weather tactical fighter jet. The aircraft was designed by a CSAT and Russian joint syndicate with the goal to build a highly agile and maneuverable air-superiority fighter.";
		buyPrice = 115500000;
		turrets[] = { { "CMFlareLauncher", "weapon_Fighter_Gun_30mm" } };
	};
	class O_Plane_Fighter_02_Stealth_F : O_Plane_Fighter_02_F {
		buyPrice = 130500000; 
		turrets[] = { { "CMFlareLauncher", "weapon_Fighter_Gun_30mm" } };
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
	};

	class Land_Bodybag_01_black_F : Base {
		virtualSpace = 0;
		garageLimit = 0;
		tempStorage = true;
	};

	class Land_WoodenCrate_01_F : Base {
		virtualSpace = 500;
		garageLimit = 0;
		isHouse = true;
	};

	class Land_PlasticCase_01_large_gray_F : Land_WoodenCrate_01_F {
		virtualSpace = 1000;
	};

	class CargoNet_01_box_F : Land_WoodenCrate_01_F {
		virtualSpace = 3000;
	};

	class Land_Cargo20_white_F : Land_WoodenCrate_01_F {
		virtualSpace = 5000;
	};

	class Land_Cargo20_grey_F : Land_WoodenCrate_01_F {
		virtualSpace = 20000;
	};

	// SOUNDS --------------------------------------------------------------------------------------
	class Police_One {
		sound = "Police_One";
	};
};