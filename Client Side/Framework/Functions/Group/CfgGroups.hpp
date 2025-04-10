class CfgGroups {
	tax[] = { 0, 25 };

	class Tag {
		MinLength = 1;
		MaxLength = 5;
		Blacklisted[] = { "APC", "APS", "NHS", "AAS", "HATO", "MTL", "MANTL" };
	};
	
	class Name {
		MinLength = 6;
    	MaxLength = 30;
		Blacklisted[] = { "Altis Police Contabulary", "Altis Police Service", "Altis Police", "Masked Player", "Police", "Medic", "Hato", "National Health Service", "Altis Ambulance Service", "Highways Agency", "Civilian", "Mantle", "Mantle Network", "Dunamis", "On Tutorial" };
	};

	ranks[] = { "PRIVATE", "CORPORAL", "SERGEANT", "LIEUTENANT", "CAPTAIN", "MAJOR", "COLONEL"  };

	class Permissions {
		deposit = 2;
		withdraw = 3;
		rank = 4;
		invite = 3;
		kick = 3;
	};

	class Types {
		class Criminal {
			displayName = "Criminal";

			class Perks {
				class CartelControl {
					displayName = "Cartel Control"; // DONE
					icon = "Data\UI\Achievements\rebel.paa"; // DONE
					description = "Increases cartel tax on drug sales by 10%";
					level = 1;
				};
				class CriminalHideouts {
					displayName = "Criminal Hideouts"; // DONE
					icon = "Data\UI\GroupPerks\hideout.paa"; // DONE
					description = "Allows the capturing of Criminal Hideouts";
					level = 2;
				};
				class Blackmarket {
					displayName = "Blackmarket"; // DONE
					icon = "Data\UI\GroupPerks\blackmarket.paa"; // DONE
					description = "Unlocks the ability to access the Blackmarket";
					level = 3;
				};
				class SeaSmuggling {
					displayName = "Sea Smuggling"; // DONE
					icon = "Data\UI\GroupPerks\smuggling.paa"; // DONE
					description = "Unlocks Sea Smuggling missions";
					level = 4;
				};
				class Ifrits {
					displayName = "Ifrits"; // DONE
					icon = "Data\UI\GroupPerks\ifrits.paa"; // DONE
					description = "Allows the purchasing of Ifrits";
					level = 5;
				};
				class MilitaryTower {
					displayName = "Military Tower"; // DONE
					icon = "Data\UI\GroupPerks\DMT.paa"; // DONE
					description = "Allows the purchasing of military towers";
					level = 6;
				};
				class IntimidatingRobber {
					displayName = "Intimidating Robber"; // DONE
					icon = "Data\UI\Achievements\successfulRobber.paa"; // DONE
					description = "Decreases the time to rob a location by 20%";
					level = 7;
				};
				class AirSmuggling {
					displayName = "Air Smuggling"; // DONE
					icon = "Data\UI\GroupPerks\smuggling.paa"; // DONE
					description = "Unlocks Air Smuggling missions";
					level = 8;
				};
				class VehicleReclaimer {
					displayName = "Vehicle Reclaimer"; // DONE
					icon = "Data\UI\Perks\scrapDealer.paa"; // DONE
					description = "Increases the keep chance when chopping by 10%";
					level = 9;
				};
				class TowerExpansion {
					displayName = "Tower Expansion";
					icon = "Data\UI\Perks\partsCarrier.paa"; // DONE
					description = "Unlocks a car garage and rebel stores";
					level = 10;
				};
			};
		};

		class Corporate {
			displayName = "Company";

			class Perks {
				class IndustrialProcessing {
					displayName = "Industrial Processing"; // DONE
					icon = "Data\UI\Perks\rapidSuveyor.paa"; // DONE
					description = "Increases processing speed by 10%";
					level = 1;
				};
				class HEMTTTrucks {
					displayName = "HEMTT Trucks"; // DONE
					icon = "Data\UI\GroupPerks\HEMTTs.paa"; // DONE
					description = "Allows the purchasing of HEMTT trucks";
					level = 2;
				};
				class FreightMissions {
					displayName = "Freight Missions"; // DONE
					icon = "Data\UI\GroupPerks\freight.paa"; // DONE
					description = "Unlocks Corporate Freight missions";
					level = 3;
				};
				class FuelHauling {
					displayName = "Fuel Hauling"; // DONE
					icon = "Data\UI\GroupPerks\fuelHaul.paa"; // DONE
					description = "Unlocks Fuel Hauling missions";
					level = 4;
				};
				class Security {
					displayName = "Security Contactors"; // DONE
					icon = "Data\UI\GroupPerks\securityContactors.paa"; // DONE
					description = "Grants your members access to become Security Officers within your company.";
					level = 5;
				};
				class MilitaryOffices {
					displayName = "Military Offices"; // DONE
					icon = "Data\UI\GroupPerks\officeBuilding.paa"; // DONE
					description = "Allows the purchasing of office buildings";
					level = 6;
				};
				class CompanyCars {
					displayName = "Company Cars"; // DONE
					icon = "Data\UI\Perks\vehicleCollector.paa"; // DONE
					description = "Increases garage limit by 100%";
					level = 7;
				};
				class TaxFreeHousing {
					displayName = "Tax-Free Housing"; // DONE
					icon = "Data\UI\Perks\landlord.paa"; // DONE
					description = "Decreases the price of houses by 20%";
					level = 8;
				};
				class AirFreight {
					displayName = "Air Freight";
					icon = "Data\UI\Perks\wideTraveller.paa"; // DONE
					description = "Unlocks the ability to store Freight in containers";
					level = 9;
				};
				class OfficeExpansion {
					displayName = "Office Expansion";
					icon = "Data\UI\Perks\partsCarrier.paa"; // DONE
					description = "Unlocks a car garage and security stores";
					level = 10;
				};
			};
		};

		class Party {
			displayName = "Political Party";

			class Perks {
				class Governorship {
					displayName = "Governorship"; // DONE
					icon = "Data\UI\GroupPerks\governor.paa"; // DONE
					description = "Allows members to run for Governor during elections";
					level = 1;
				};
				class GovernmentSalary {
					displayName = "Government Salary"; // DONE
					icon = "Data\UI\Perks\governmentBonus.paa"; // DONE
					description = "Increases paychecks by 100%";
					level = 2;
				};
				class PoliticalSavings {
					displayName = "Political Saving"; // DONE
					icon = "Data\UI\Perks\legalTrader.paa"; // DONE
					description = "Provides an additonal 25% from each mission";
					level = 3;
				};
				class GoalContributions {
					displayName = "Goal Contributions"; // DONE
					icon = "Data\UI\Perks\rapidStorer.paa"; // DONE
					description = "Increases contributions to Community Goals by 25%";
					level = 4;
				};
				class Protection {
					displayName = "Personal Protection"; // DONE
					icon = "Data\UI\GroupPerks\personalProtection.paa"; // DONE
					description = "Unlocks the Personal Protection licence and store";
					level = 5;
				};
				class OfficeBuilding {
					displayName = "Office Building"; // DONE
					icon = "Data\UI\GroupPerks\officeBuilding.paa"; // DONE
					description = "Allows the purchasing of tall office buildings";
					level = 6;
				};
				class Safehouses {
					displayName = "Safehouses"; // DONE
					icon = "Data\UI\GroupPerks\governmentSafehouses.paa"; // DONE
					description = "Unlocks a spawn at Safehouses and protection stores";
					level = 7;
				};
				class PartyExperience {
					displayName = "Party Experience"; // DONE
					icon = "Data\UI\Perks\quickLearner.paa"; // DONE
					description = "Increases personal XP gain by 20%";
					level = 8;
				};
				class PollRigging {
					displayName = "Poll Rigging"; // DONE
					icon = "Data\UI\GroupPerks\pollRigging.paa"; // DONE
					description = "Unlocks the ability to rig polls during elections";
					level = 9;
				};
				class HQExpansion {
					displayName = "HQ Expansion";
					icon = "Data\UI\Perks\partsCarrier.paa"; // DONE
					description = "Unlocks a car garage and protection stores";
					level = 10;
				};
			};
		};
	};

	class Leveling {
		baseXp = 2500;
		xpMultiplier = 1.35;
		maxLevel = 10;

		class XP {
			class HoldingCartel { amount = 10; };
			class Cartel { amount = 25; };
			class Hideout : Cartel {};
			class Popup : Cartel { amount = 80; };
			class Airdrop : Popup {};
			class Shipwreck : Popup {};
			class CargoRun { amount = 45; };
			class Election { amount = 500; }; // TODONOW
			class Rigging { amount = 35; };
			class BaseBid : Election {}; // TODONOW
			class CommunityGoals : CargoRun {}; // TODO
			class Robbery : CargoRun {};
			class SoldLegalItems : CargoRun {
				amount = 0;
				amountPerItem = 0.4; // This is a unique setting for this category
			};
		};
	};

	class Buffs {
		class Missions {
			displayName = "Increased Payout from Missions";
			icon = "Data\UI\GroupBuffs\missions.paa";
			max = 0.5;
		};
		class Lockpicking : Missions {
			displayName = "Increased Lockpicking Speed";
			icon = "Data\UI\GroupBuffs\lockpicking.paa";
		};
		class Boltcutting : Missions {
			displayName = "Increased Boltcutting Speed";
			icon = "Data\UI\GroupBuffs\boltcutting.paa";
		};
		class Hacking : Missions {
			displayName = "Increased Hacking Speed";
			icon = "Data\UI\GroupBuffs\hacking.paa";
		};
		class Surveying : Missions {
			displayName = "Increased Surveying Speed";
			icon = "Data\UI\GroupBuffs\surveying.paa";
		};
		class Digging : Missions {
			displayName = "Increased Digging Speed";
			icon = "Data\UI\GroupBuffs\digging.paa";
		};
	};
};
