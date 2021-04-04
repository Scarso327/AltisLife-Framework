class CfgPerks {
	baseLimit = 3;
	maxLimit = 15;
	removalCost = 100000;

	class SecondNature {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa";
		displayName = "Second Nature";
		description = "Automatically put on your seatbelt when entering a vehicle.";
		removalMultiplier = 1;
		class Requirements {
			factions[] = { "Police", "Medic", "Hato", "Civilian" };
			level = 5;
			prestige = 0;
			profession[] = {};
		};
		onActivated = "_params setVariable [""seatbelt"", true]; _params";
	};

	class ExpertTrader {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa";
		displayName = "Expert Trader";
		description = "Increase the price you sell legal items for by %1%2.";
		removalMultiplier = 1.1; // Increase removal cost by 10%...
		class Leveling {
			maxLevel = 5;
			xpLevel = 100;
			xpMultipler = 2;
			levelCalculation = "5 * (_this select 0)";
		};
		class Requirements {
			factions[] = { "Civilian" };
			level = 5;
			prestige = 0;
			profession[] = { "Gathering", 1 };
		};
		onActivated = "_params + (_params * (_bonus / 100))";
	};
};