class CfgProfessions {
	class Repairing {
		displayName = "Repairing";
		icon = "Data\UI\Professions\repairing.paa";
		effectDescription = "Decreases the time it takes to repair by %1%2";
		effectCalculation = "5 * (_this select 0)"; // (_this select 0) refers to the level of this profession and (_this select 1) is the current xp.
		xpLevel = 100;
		xpMultipler = 2; // XP REQUIRED FOR LEVEL = xpLevel * (xpMultipler * CURRENT LEVEL) (If CURRENT LEVEL = 0 THEN xpMultipler isn't added)
		maxLevel = 5;
	};

	class Fishing { // TODONOW
		displayName = "Fishing";
		icon = "Data\UI\Professions\fishing.paa";
		effectDescription = "Decreases the time it takes to catch fish by %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Gathering {
		displayName = "Gathering";
		icon = "Data\UI\Professions\gathering.paa";
		effectDescription = "Decreases the time it takes to gather by %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Mining {
		displayName = "Mining";
		icon = "Data\UI\Professions\mining.paa";
		effectDescription = "Decreases the time it takes to mine by %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Processing {
		displayName = "Processing";
		icon = "Data\UI\Professions\processing.paa";
		effectDescription = "Decreases the time it takes to process by %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	class Cooking {
		displayName = "Cooking";
		icon = "Data\UI\Professions\cooking.paa";
		effectDescription = "Decreases the time it takes to cook by %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};
};