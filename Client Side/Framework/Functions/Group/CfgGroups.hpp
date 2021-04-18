class CfgGroups {
	class Tag {
		MinLength = 1;
		MaxLength = 4;
		Blacklisted[] = { "APC", "NHS", "HATO" };
	};
	
	class Name {
		MinLength = 6;
    	MaxLength = 30;
		Blacklisted[] = { "Altis Police Contabulary", "National Health Service", "Highways Agency", "Civilian" };
	};

	ranks[] = {
		"PRIVATE", "CORPORAL", "SERGEANT", "LIEUTENANT", "CAPTAIN", "MAJOR", "COLONEL"
	};

	class Permissions {
		deposit = 3;
		withdraw = 3;
		rank = 4;
		invite = 4;
		kick = 4;
	};

	class Types {
		class Criminal {
			displayName = "Criminal";

			class Perks {
				class Hideout {
					displayName = "Capture Hideout";
					icon = "Data\UI\GroupPerks\hideout.paa";
					description = "You have the ability to capture gang hideouts.";
					level = 1;
				};

				class Blackmarket {
					displayName = "Blackmarketer";
					icon = "Data\UI\GroupPerks\blackmarket.paa";
					description = "You have the ability to access the Blackmarket.";
					level = 2;
				};

				class Governor { // TODONOW
					displayName = "Governorship";
					icon = "Data\UI\GroupPerks\governor.paa";
					description = "Your members have the ability to run for governor.";
					level = 3;
				};

				class Ifrits {
					displayName = "Ifrit Drivers";
					icon = "Data\UI\GroupPerks\ifrits.paa";
					description = "You have the ability to access Ifrits within the Blackmarket.";
					level = 4;
				};

				class DMT {
					displayName = "DMT Ownership";
					icon = "Data\UI\GroupPerks\DMT.paa";
					description = "Your members have the ability to purchase a DMT.";
					level = 5;
				};
			};
		};

		class Corporate {
			displayName = "Company";

			class Perks {
				class Freight { // TODO
					displayName = "Freight Missions";
					icon = "Data\UI\GroupPerks\freight.paa";
					description = "Grants your members access to Freight Missions.";
					level = 1;
				};

				class HEMTTs {
					displayName = "HEMTT Trucks";
					icon = "Data\UI\GroupPerks\HEMTTs.paa";
					description = "Grants your members access to all variants of the HEMTT Transports.";
					level = 2;
				};

				class Governor { // TODONOW
					displayName = "Governorship";
					icon = "Data\UI\GroupPerks\governor.paa";
					description = "Your members have the ability to run for governor.";
					level = 3;
				};

				class GoalContributions { // TODONOW
					displayName = "Goal Contributions";
					icon = "Data\UI\GroupPerks\goalContributions.paa";
					description = "Your members have an increased contribution to community goals.";
					level = 4;
				};

				class MilitaryOffices {
					displayName = "Offices Ownership";
					icon = "Data\UI\GroupPerks\officeBuilding.paa";
					description = "Your members have the ability to purchase an Abandonded Military Office building.";
					level = 5;
				};
			};
		};

		class Party {
			displayName = "Political Party";

			class Perks {
				class Governor { // TODONOW
					displayName = "Governorship";
					icon = "Data\UI\GroupPerks\governor.paa";
					description = "Your members have the ability to run for governor.";
					level = 1;
				};

				class PersonalProtection { // TODONOW
					displayName = "Personal Protection";
					icon = "Data\UI\GroupPerks\personalProtection.paa";
					description = "Grants your members access to become Personal Protection Officers.";
					level = 2;
				};

				class GovernmentSafehouses { // TODONOW
					displayName = "Personal Protection";
					icon = "Data\UI\GroupPerks\governmentSafehouses.paa";
					description = "Grants your members access to various Government Safehouses.";
					level = 3;
				};

				class OfficeBuilding {
					displayName = "Office Ownership";
					icon = "Data\UI\GroupPerks\officeBuilding.paa";
					description = "Your members have the ability to purchase an Office Building.";
					level = 4;
				};

				class PollRigging { // TODONOW
					displayName = "Poll Rigging";
					icon = "Data\UI\GroupPerks\pollRigging.paa";
					description = "Your members have the ability to rig polling boothes.";
					level = 5;
				};
			};
		};
	};

	class Leveling {
		baseXp = 2500;
		xpMultiplier = 1.35;
		maxLevel = 5;

		class XP {
			class Cartel { amount = 10; };
			class Popup : Cartel {}; // TODONOW
			class Airdrop : Cartel {};
			class Freight { amount = 5; }; // TODONOW
			class Election { amount = 100; }; // TODONOW
			class Rigging { amount = 20; }; // TODONOW
			class Hideout : Cartel {}; // TODONOW
			class BaseBid : Election {}; // TODONOW
			class GoldDrives : Freight {}; // TODONOW
			class CommunityGoals : Freight {}; // TODONOW
			class MedicalAid { amount = 3; }; // TODONOW
			class Robbery : Freight {};
		};
	};

	class Buffs {
		class Missions {
			displayName = "Increased Payout from Missions";
			icon = "Data\UI\GroupBuffs\missions.paa";
			max = 0.25;
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