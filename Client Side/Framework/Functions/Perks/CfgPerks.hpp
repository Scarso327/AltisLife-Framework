class CfgPerks {
	baseLimit = 3;
	maxLimit = 15;
	removalCost = 100000;

	class SecondNature {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Second Nature";
		description = "Automatically applies your seatbelt.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 1;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "_params setVariable [""seatbelt"", true]; _params";
	};

	class ImprovedMetabolism { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Improved Metabolism";
		description = "Slows your hunger and dehydration gain by 50%.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 2;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class GovernmentBonus {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Government Bonus";
		description = "Increases your base paycheck by %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 5;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "10 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 3;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class Muscleman { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Muscleman";
		description = "Increases your Item carry limit by 25%.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 4;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class GeneralMechanic { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "General Mechanic";
		description = "Decreases the likelihood of breaking your toolkit by %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 5;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class MindfulPlanner { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Mindful Planner";
		description = "You will spawn with a GPS and Binoculars.";
		removalMultiplier = 2;
		class Requirements {
			factions[] = { "Civilian" };
			level = 6;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class WideTraveller {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Wide Traveller";
		description = "Allows you to spawn in Sofia, Agios and Neochori.";
		removalMultiplier = 5;
		class Requirements {
			factions[] = { "Civilian" };
			level = 8;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class LegalTrader {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Legal Trader";
		description = "Increase the price you sell legal items for by %1%2.";
		removalMultiplier = 3;
		class Leveling {
			maxLevel = 3;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "5 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 10;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class ShadyTrader {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Shady Trader";
		description = "Increase the price you sell illegal items for by %1%2.";
		removalMultiplier = 3;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "5 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 13;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class EcoDriver { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Eco Driver";
		description = "Decreases the cost of fuel per litre by %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 16;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class SlightofHand { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Slight of Hand";
		description = "Increases repacking of your magazines speed by %1%2.";
		removalMultiplier = 1.5;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "15 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police" };
			level = 20;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class BloodCarrier { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Blood Carrier";
		description = "Blood bags become 50% more effective.";
		removalMultiplier = 1.2;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 22;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class FirstAider { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "First Aider";
		description = "FirstAidKits becomes 100% effective.";
		removalMultiplier = 1.2;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 24;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class SpeedyLocksmith { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Speedy Locksmith";
		description = "Increases your lockpicking speed by %1%2.";
		removalMultiplier = 1.3;
		class Leveling {
			maxLevel = 3;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "20 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 25;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class SilentLocksmith { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Silent Locksmith";
		description = "Decreases the likelihood of triggering an alarm by %1%2.";
		removalMultiplier = 1.3;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 25;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class QuickLearner { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Quick Learner";
		description = "Increases the amount of profession's XP gained by 10%.";
		removalMultiplier = 1.5;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 27;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class UncertainPersonality { // TODO
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa"; // ICON
		displayName = "Uncertain Personality";
		description = "Gain the chance of keeping a vehicle when chopping.";
		removalMultiplier = 2;
		class Requirements {
			factions[] = { "Civilian" };
			level = 30;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};
};