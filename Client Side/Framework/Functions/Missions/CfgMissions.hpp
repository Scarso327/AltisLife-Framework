class CfgMissions {
	class Delivery {
		name = "Delivery Mission";
		description = "You need to deliver the given package to %1";
		factions[] = { "Civilian" };
		condition = "true";
		eachFrame = "";
		onClaimed = "";
		onFinished = "";
		class Locations {
			class DP1 {
				pos = "DP_1";
				name = "Delivery Point 1";
			};
			class DP2 {
				pos = "DP_2";
				name = "Delivery Point 2";
			};
			class DP3 {
				pos = "DP_3";
				name = "Delivery Point 3";
			};
			class DP4 {
				pos = "DP_4";
				name = "Delivery Point 4";
			};
			class DP5 {
				pos = "DP_5";
				name = "Delivery Point 5";
			};
			class DP6 {
				pos = "DP_6";
				name = "Delivery Point 6";
			};
			class DP7 {
				pos = "DP_7";
				name = "Delivery Point 7";
			};
			class DP8 {
				pos = "DP_8";
				name = "Delivery Point 8";
			};
			class DP9 {
				pos = "DP_9";
				name = "Delivery Point 9";
			};
			class DP10 {
				pos = "DP_10";
				name = "Delivery Point 10";
			};
			class DP11 {
				pos = "DP_11";
				name = "Delivery Point 11";
			};
			class DP12 {
				pos = "DP_12";
				name = "Delivery Point 12";
			};
			class DP13 {
				pos = "DP_13";
				name = "Delivery Point 13";
			};
			class DP14 {
				pos = "DP_14";
				name = "Delivery Point 14";
			};
			class DP15 {
				pos = "DP_15";
				name = "Delivery Point 15";
			};
			class DP16 {
				pos = "DP_16";
				name = "Delivery Point 16";
			};
			class DP17 {
				pos = "DP_17";
				name = "Delivery Point 17";
			};
			class DP18 {
				pos = "DP_18";
				name = "Delivery Point 18";
			};
		};
		class Rewards {
			moneyReward = 4;
			xpReward = 150;
		};
		class Messages {
			onFinishWithoutMission = "You don't have any packages to deliver here...";
			onAlreadyHas = "You already have a delivery mission active, complete it before requesting another...";
			onNoLocations = "There are currently no delivery missions available for pickup, please try again alter...";
			onAssigned = "You have been tasked to deliver this package to %1";
			onFinished = "You have successfully delivered the package, you have been paid £%1";
		};
	};

	class Patrol {
		name = "Patrol Mission";
		description = "You need to patrol %1";
		factions[] = { "Police", "Medic", "Hato" };
		condition = "true";
		eachFrame = "";
		onClaimed = "[ { (player distance _this) <= 10 }, _this, { [""Patrol""] call ULP_fnc_finishMission; } ] call ULP_fnc_waitUntilExecute;";
		onFinished = "";
		class Locations {
			// CITIES, TOWNS & KEY LOCATIONS
			class KavalaSquare {
				pos = "civ_spawn_kavala";
				name = "Kavala Square";
			};
			class CentralAthira {
				pos = "car_dealership_athira_01";
				name = "Central Athira";
			};
			class CityOfPyrgos {
				pos = "civ_spawn_pyrgos";
				name = "City of Pyrgos";
			};
			class TownOfSofia {
				pos = "civ_spawn_sofia";
				name = "Town of Sofia";
			};
			class AgiosCenter {
				pos = "civ_spawn_agios";
				name = "Agios Center";
			};
			class AltisInternational {
				pos = "altis_international";
				name = "Altis International";
			};
			class AbandonedCheckpoint {
				pos = "abandoned_checkpoint";
				name = "Abandoned Checkpoint";
			};
			class HuntingCamp {
				pos = "hunting_camp";
				name = "Hunting Camp";
			};
			class JewelleryStore {
				pos = "jewellery_store";
				name = "Jewellery Store";
			};
			class AltisArcheologists {
				pos = "altis_archeologists";
				name = "Altis Archeologists";
			};
			class Supermarket {
				pos = "supermarket";
				name = "Supermarket";
			};
			class ImpoundFacility {
				pos = "impound_facility";
				name = "Impound Facility";
			};
			class KavalaStreet {
				pos = "10_kavala_street";
				name = "10 Kavala Street";
			};

			// MINOR CRIME SITES
			class WesternRegionalBank {
				pos = "regional_bank_01";
				name = "Western Regional Bank";
			};
			class EasternRegionalBank {
				pos = "regional_bank_02";
				name = "Eastern Regional Bank";
			};

			// MAJOR CRIME SITES
			class HMTreasury {
				pos = "hm_treasury";
				name = "HM Treasury";
			};
			class HMPrisonAltis {
				pos = "hm_prison_altis";
				name = "HM Prison Altis";
			};
			class PoliceEvidenceStorage {
				pos = "police_evidence_storage";
				name = "Police Evidence Storage";
			};

			// GATHER, PROCESSING & TRADING SITES
			class AltisMetalExports {
				pos = "altis_metal_exports";
				name = "Altis Metal Exports";
			};
		};
		class Rewards {
			moneyReward = 1;
			xpReward = 100;
		};
		class Messages {
			onFinishWithoutMission = "You can't complete a patrol as you haven't been assigned any...";
			onAlreadyHas = "You have already been assigned a patrol, please complete that before requesting another...";
			onNoLocations = "There are no patrols available, please try again later...";
			onAssigned = "You have been tasked to patrol %1";
			onFinished = "You have successfully completed you patrol assignment, you have been paid a bonus of £%1";
		};
	};

	class ArchaeologyCommon {
		name = "Common Archaeology Sites";
		description = "You need to use surveying equipment at the marked location...";
		factions[] = { "Civilian" };
		condition = "true";
		eachFrame = "";
		onClaimed = "ULP_Archaeology_Digging = false; ULP_Archaeology = ""Common""; ULP_SurveyTotal = 0; [""CommonMap"", 1, true] call ULP_fnc_handleItem;";
		onFinished = "";
		class Locations {
			class dig_site_01 {
				pos = "dig_site_01";
				name = "Zaros";
			};
			class dig_site_02 {
				pos = "dig_site_02";
				name = "Zaros";
			};
			class dig_site_03 {
				pos = "dig_site_03";
				name = "Zaros";
			};
			class dig_site_04 {
				pos = "dig_site_04";
				name = "Zaros";
			};
			class dig_site_05 {
				pos = "dig_site_05";
				name = "Zaros";
			};
			class dig_site_06 {
				pos = "dig_site_06";
				name = "Zaros";
			};
			class dig_site_07 {
				pos = "dig_site_07";
				name = "Zaros";
			};
			class dig_site_08 {
				pos = "dig_site_08";
				name = "Zaros";
			};
			class dig_site_09 {
				pos = "dig_site_09";
				name = "Zaros";
			};
			class dig_site_10 {
				pos = "dig_site_10";
				name = "Alikampos";
			};
			class dig_site_11 {
				pos = "dig_site_11";
				name = "Kore";
			};
			class dig_site_12 {
				pos = "dig_site_12";
				name = "Syrta";
			};
			class dig_site_13 {
				pos = "dig_site_13";
				name = "Abdera";
			};
			class dig_site_14 {
				pos = "dig_site_14";
				name = "Galati";
			};
			class dig_site_15 {
				pos = "dig_site_15";
				name = "Galati";
			};
			class dig_site_16 {
				pos = "dig_site_16";
				name = "Galati";
			};
			class dig_site_17 {
				pos = "dig_site_17";
				name = "Telos";
			};
			class dig_site_18 {
				pos = "dig_site_18";
				name = "Anthrakia";
			};
			class dig_site_19 {
				pos = "dig_site_19";
				name = "Charkia";
			};
			class dig_site_20 {
				pos = "dig_site_20";
				name = "Dorida";
			};
			class dig_site_21 {
				pos = "dig_site_21";
				name = "Dorida";
			};
			class dig_site_22 {
				pos = "dig_site_22";
				name = "Dorida";
			};
			class dig_site_23 {
				pos = "dig_site_23";
				name = "Dorida";
			};
			class dig_site_24 {
				pos = "dig_site_24";
				name = "Chalkeia";
			};
			class dig_site_25 {
				pos = "dig_site_25";
				name = "Chalkeia";
			};
			class dig_site_26 {
				pos = "dig_site_26";
				name = "Pyrgos";
			};
			class dig_site_27 {
				pos = "dig_site_27";
				name = "Chalkeia";
			};
			class dig_site_28 {
				pos = "dig_site_28";
				name = "Oreokastro";
			};
			class dig_site_29 {
				pos = "dig_site_29";
				name = "Oreokastro";
			};
			class dig_site_30 {
				pos = "dig_site_30";
				name = "Therisa";
			};
		};
		class Rewards {
			moneyReward = 0;
			xpReward = 0;
		};
		class Messages {
			onFinishWithoutMission = "You can't survey this location as you haven't been assigned it...";
			onAlreadyHas = "You must survey your assigned location before getting another...";
			onNoLocations = "There are no suvery locations available, please try again later...";
			onAssigned = "An Archaeological Site has been marked on your map near %1";
			onFinished = "";
		};
	};

	class ArchaeologyUncommon : ArchaeologyCommon {
		name = "Uncommon Archaeology Sites";
		onClaimed = "ULP_Archaeology_Digging = false; ULP_Archaeology = ""Uncommon""; ULP_SurveyTotal = 0; [""UncommonMap"", 1, true] call ULP_fnc_handleItem;";
		class Rewards : Rewards {};
		class Messages : Messages {};
	};

	class ArchaeologyRare : ArchaeologyCommon {
		name = "Rare Archaeology Sites";
		onClaimed = "ULP_Archaeology_Digging = false; ULP_Archaeology = ""Rare""; ULP_SurveyTotal = 0; [""RareMap"", 1, true] call ULP_fnc_handleItem;";
		class Rewards : Rewards {};
		class Messages : Messages {};
	};

	class CorporateFreight {
		name = "Corporate Freight";
		description = "You need to deliver the given corporate freight to %1";
		factions[] = { "Civilian" };
		condition = "[""Freight""] call ULP_fnc_hasGroupPerk";
		eachFrame = "_this call ULP_fnc_onEachFrameCargoRun";
		onClaimed = "";
		onFinished = "_this call ULP_fnc_finishCargoRun";
		timeDivisionAmount = 2;
		vehicleRequirement[] = { { "Car" }, 10 };
		cargoItem = "FreightCargo";
		class Locations {
			class Kavala_Freight {
				pos = "freight_mission_1";
				name = "Kavala Freight Yard";
			};
			class Sofia_Freight {
				pos = "freight_mission_2";
				name = "Sofia Freight Yard";
			};
		};
		class Rewards {
			moneyReward = 5;
			xpReward = 100;
		};
		class Messages {
			onFinishWithoutMission = "You don't have any packages to deliver here...";
			onAlreadyHas = "You already have a corporate freight mission active, complete it before requesting another...";
			onNoLocations = "There are currently no corporate freight missions available for pickup, please try again alter...";
			onAssigned = "Your truck has been filled with freight, deliver it to <t color='#B92DE0'>%1</t>";
			onFinished = "You have successfully delivered the freight, you have been paid <t color='#B92DE0'>£%1</t>";
		};
	};

	class CriminalSmuggling : CorporateFreight {
		name = "Cargo Smuggling";
		description = "You need to deliver the given stolen cargo to %1";
		condition = "true";
		timeDivisionAmount = 4;
		vehicleRequirement[] = { { "Ship" }, 50 };
		cargoItem = "StolenCargo";
		class Locations {
			class Sunken_Grove {
				pos = "smuggling_location_1";
				name = "Sunken Grove";
			};
			class Discovery_Ridge {
				pos = "smuggling_location_2";
				name = "Discovery Ridge";
			};
			class Lookout_Point {
				pos = "smuggling_location_3";
				name = "Lookout Point";
			};
		};
		class Rewards {
			moneyReward = 0;
			xpReward = 150;
		};
		class Messages {
			onFinishWithoutMission = "You don't have any stolen cargo to deliver here...";
			onAlreadyHas = "You already have a criminal smuggling mission active, complete it before requesting another...";
			onNoLocations = "There are currently no criminal smuggling missions available for pickup, please try again alter...";
			onAssigned = "Your boat has been filled with stolen cargo, deliver it to <t color='#B92DE0'>%1</t>";
			onFinished = "You have successfully delivered the stolen cargo, you have been paid <t color='#B92DE0'>£%1</t>";
		};
	};
};