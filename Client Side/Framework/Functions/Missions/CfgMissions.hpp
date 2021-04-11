class CfgMissions {
	class Delivery {
		name = "Delivery Mission";
		description = "You need to deliver the given package to %1";
		factions[] = { "Civilian" };
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
			moneyReward = 20;
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
				name = "Central Athira";
			};
			class AltisGallery {
				pos = "altis_gallery";
				name = "Altis Gallery";
			};

			// GATHER, PROCESSING & TRADING SITES
			class AltisMetalExports {
				pos = "altis_metal_exports";
				name = "Altis Metal Exports";
			};
		};
		class Rewards {
			moneyReward = 10;
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
};