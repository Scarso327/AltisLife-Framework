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
					description = "You have the ability to capture gang hideouts.";
					level = 1;
				};
			};
		};

		class Corporate {
			displayName = "Company";

			class Perks {
				class Freight {
					displayName = "Freight missions";
					description = "Grants your members access to Freight Missions.";
					level = 1;
				};
			};
		};

		class Party {
			displayName = "Political Party";

			class Perks {
				class Governor {
					displayName = "Governor";
					description = "Your members have the ability to run for governor.";
					level = 1;
				};
			};
		};
	};

	class Leveling {
		baseXp = 2500;
		xpMultiplier = 1.35;
		maxLevel = 5;

		class XP {
			class Cartel {
				amount = 10;
			};
		};
	};
};