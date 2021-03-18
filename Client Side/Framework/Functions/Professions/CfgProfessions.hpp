class CfgProfessions {
	class Repairing {
		displayName = "Repairing";
		icon = "Data\UI\repairing_prof.paa";
		effectDescription = "Currently decreases the time it takes to repair by %1%2";
		effectCalculation = "5 * (_this select 0)"; // (_this select 0) refers to the level of this profession and (_this select 1) is the current xp.
		xpLevel = 100;
		xpMultipler = 2; // XP REQUIRED FOR LEVEL = xpLevel * (xpMultipler * CURRENT LEVEL) (If CURRENT LEVEL = 0 THEN xpMultipler isn't added)
		maxLevel = 5;
	};

	// TODO
	class Fishing {
		displayName = "Fishing";
		icon = "Data\UI\repairing_prof.paa";
		effectDescription = "Does something %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	// TODO
	class Gathering {
		displayName = "Gathering";
		icon = "Data\UI\repairing_prof.paa";
		effectDescription = "Currently decreases the time it takes to gather at fields by %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	// TODO
	class Mining {
		displayName = "Mining";
		icon = "Data\UI\repairing_prof.paa";
		effectDescription = "Currently decreases the time it takes to gather at mines by %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	// TODO
	class Processing {
		displayName = "Processing";
		icon = "Data\UI\repairing_prof.paa";
		effectDescription = "Does something %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};

	// TODO
	class Cooking {
		displayName = "Cooking";
		icon = "Data\UI\repairing_prof.paa";
		effectDescription = "Does something %1%2";
		effectCalculation = "5 * (_this select 0)";
		xpLevel = 100;
		xpMultipler = 2;
		maxLevel = 5;
	};
};