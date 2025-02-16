class CfgProfessions {
	class Repairing {
		displayName = "Repairing";
		icon = "Data\UI\Professions\repairing.paa";
		effectDescription = "Decreases the time it takes to repair by %1%2";
		effectCalculation = "5 * (_this select 0)"; // (_this select 0) refers to the level of this profession and (_this select 1) is the current xp.
		xpLevel = 100;
		maxLevel = 5;
	};

	class Fishing : Repairing {
		displayName = "Fishing";
		icon = "Data\UI\Professions\fishing.paa";
		effectDescription = "Decreases the time it takes to catch fish by %1%2";
	};

	class Gathering : Repairing {
		displayName = "Gathering";
		icon = "Data\UI\Professions\gathering.paa";
		effectDescription = "Decreases the time it takes to gather by %1%2";
		effectCalculation = "5 * (_this select 0)";
	};

	class Mining : Repairing {
		displayName = "Mining";
		icon = "Data\UI\Professions\mining.paa";
		effectDescription = "Decreases the time it takes to mine by %1%2";
		effectCalculation = "5 * (_this select 0)";
	};

	class Processing : Repairing {
		displayName = "Processing";
		icon = "Data\UI\Professions\processing.paa";
		effectDescription = "Decreases the time it takes to process by %1%2";
		effectCalculation = "5 * (_this select 0)";
	};

	class Cooking : Repairing {
		displayName = "Cooking";
		icon = "Data\UI\Professions\cooking.paa";
		effectDescription = "Decreases the time it takes to cook by %1%2";
		effectCalculation = "5 * (_this select 0)";
	};

	class Smelting : Repairing {
		displayName = "Smelting";
		icon = "Data\UI\Professions\smelting.paa";
		effectDescription = "Decreases the time it takes to smelt by %1%2";
		effectCalculation = "5 * (_this select 0)";
	};

	class Archeology : Repairing {
		displayName = "Archeology";
		icon = "Data\UI\Professions\archeology.paa";
		effectDescription = "Decreases the time it takes to survey and dig by %1%2";
	};

	class Crafting : Repairing {
		displayName = "Crafting";
		icon = "Data\UI\Professions\crafting.paa";
		effectDescription = "Decreases the time it takes to craft by %1%2";
	};

	class Reviving : Repairing {
		displayName = "Reviving";
		icon = "Data\UI\Professions\reviving.paa";
		effectDescription = "Decreases the time it takes to revive by %1%2";
	};
};