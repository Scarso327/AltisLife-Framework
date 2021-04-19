class CfgPerks {
	baseLimit = 3;
	maxLimit = 15;
	removalCost = 100000;

	class SecondNature {
		icon = "Data\UI\Perks\secondNature.paa";
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

	class ImprovedMetabolism {
		icon = "Data\UI\Perks\improvedMetabolism.paa";
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
		icon = "Data\UI\Perks\governmentBonus.paa";
		displayName = "Government Bonus";
		description = "Increases your base paycheck by 30%.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 3;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class Muscleman {
		icon = "Data\UI\Perks\muscleman.paa";
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

	class GeneralMechanic {
		icon = "Data\UI\Perks\generalMechanic.paa";
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
			profession[] = { "Repairing", 1 };
		};
		onActivated = "_params + (_bonus / 100)";
	};

	class MindfulPlanner {
		icon = "Data\UI\Perks\mindfulPlanner.paa";
		displayName = "Mindful Planner";
		description = "You will spawn with a Map, Radio and GPS.";
		removalMultiplier = 2;
		class Requirements {
			factions[] = { "Civilian" };
			level = 6;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class SpeedyLocksmith {
		icon = "Data\UI\Perks\speedyLocksmith.paa";
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
			level = 7;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class WideTraveller {
		icon = "Data\UI\Perks\wideTraveller.paa";
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

	class CompletedCV {
		icon = "Data\UI\Perks\completedCV.paa";
		displayName = "Completed CV";
		description = "Allows you to get employed at various job sites.";
		removalMultiplier = 3;
		class Requirements {
			factions[] = { "Civilian" };
			level = 9;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class LegalTrader {
		icon = "Data\UI\Perks\legalTrader.paa";
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

	class RapidSurveyor {
		icon = "Data\UI\Perks\rapidSurveyor.paa";
		displayName = "Rapid Surveyor";
		description = "Increases your surveying speed on dig sites speed by %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "15 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian" };
			level = 11;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class BoltCutter {
		icon = "Data\UI\Perks\boltCutter.paa";
		displayName = "Bolt Cutter";
		description = "Increases your bolt cutting speed by %1%2.";
		removalMultiplier = 1.3;
		class Leveling {
			maxLevel = 2;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 12;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class ShadyTrader {
		icon = "Data\UI\Perks\shadyTrader.paa";
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

	class cuffCourier {
		icon = "Data\UI\Perks\cuffCourier.paa";
		displayName = "Cuff Courier";
		description = "Gain the ability to reuse zip ties.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Civilian" };
			level = 14;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class IDForger {
		icon = "Data\UI\Perks\idForger.paa";
		displayName = "ID Forger";
		description = "Allows you to forge fake IDs.";
		removalMultiplier = 3;
		class Requirements {
			factions[] = { "Civilian" };
			level = 15;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class EcoDriver { // TODO
		icon = "Data\UI\Perks\ecoDriver.paa";
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

	class MatesRates {
		icon = "Data\UI\Perks\matesRates.paa";
		displayName = "Mates Rates";
		description = "Decreases garage retrieval fees by 50%.";
		removalMultiplier = 6;
		class Requirements {
			factions[] = { "Civilian" };
			level = 17;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class PartsCarrier {
		icon = "Data\UI\Perks\partsCarrier.paa";
		displayName = "Parts Carrier";
		description = "Decreases the cost of servicing an aircraft by %1%2.";
		removalMultiplier = 2;
		class Leveling {
			maxLevel = 3;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian" };
			level = 18;
			prestige = 0;
			profession[] = { "Repairing", 3 };
		};
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class ScrapDealer {
		icon = "Data\UI\Perks\scrapDealer.paa";
		displayName = "Scrap Dealer";
		description = "Increases the amount of money made from chopping a vehicle by %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 5;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "3 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian" };
			level = 19;
			prestige = 0;
			profession[] = { "Repairing", 3 };
		};
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class SlightofHand { // TODO
		icon = "Data\UI\Perks\slightOfHand.paa";
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

	class VehicleCollector {
		icon = "Data\UI\Perks\vehicleCollector.paa";
		displayName = "Vehicle Collector";
		description = "Increases the garage limit of each vehicle type by 1.";
		removalMultiplier = 10;
		class Requirements {
			factions[] = { "Civilian" };
			level = 21;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class BloodCarrier {
		icon = "Data\UI\Perks\bloodCarrier.paa";
		displayName = "Blood Carrier";
		description = "Increases Blood bag effenciency by %1%2.";
		removalMultiplier = 1.2;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 22;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class IntelligentBanker { // TODONOW
		icon = "Data\UI\Perks\intelligentBanker.paa";
		displayName = "Intelligent Banker";
		description = "Decreases your wire transfer costs by %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 4;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "25 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 23;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class FirstAider {
		icon = "Data\UI\Perks\firstAider.paa";
		displayName = "First Aider";
		description = "Increase the effeciency of FirstAidKits by %1%2.";
		removalMultiplier = 1.2;
		class Leveling {
			maxLevel = 5;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "5 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian", "Police", "Medic", "Hato" };
			level = 24;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "_params + (_params * (_bonus / 100))";
	};

	class SilentLocksmith { // TODO : Add to vehicle lockpicking...
		icon = "Data\UI\Perks\silentLocksmith.paa";
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
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class Blackmarketer {
		icon = "Data\UI\Perks\blackmarketer.paa";
		displayName = "Blackmarketer";
		description = "Permits access to the Blackmarket.";
		removalMultiplier = 10;
		class Requirements {
			factions[] = { "Civilian" };
			level = 26;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class QuickLearner { // TODONOW
		icon = "Data\UI\Perks\quickLearner.paa";
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

	class LandLord {
		icon = "Data\UI\Perks\landLord.paa";
		displayName = "Land Lord";
		description = "Allows you to purchase an additional property.";
		removalMultiplier = 4;
		class Requirements {
			factions[] = { "Civilian" };
			level = 28;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "";
	};

	class rapidStorer {
		icon = "Data\UI\Perks\rapidStorer.paa";
		displayName = "Rapid Storer";
		description = "Decreases the time it takes to store a vehicle by %1%2.";
		removalMultiplier = 1;
		class Leveling {
			maxLevel = 3;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "10 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian" };
			level = 29;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "_params - (_params * (_bonus / 100))";
	};

	class UncertainMind {
		icon = "Data\UI\Perks\uncertainPerson.paa";
		displayName = "Uncertain Person";
		description = "Gain the chance of keeping a vehicle when chopping.";
		removalMultiplier = 2;
		class Requirements {
			factions[] = { "Civilian" };
			level = 30;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "((random 100) max 1)";
	};
};