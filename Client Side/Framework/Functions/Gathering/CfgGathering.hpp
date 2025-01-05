class CfgGathering {
	fish[] = { "Salema_F", "Ornate_random_F", "Mackerel_F", "Tuna_F", "Mullet_F", "CatShark_F", "Turtle_F" };
	turtleZones[] = { "turtle_poaching_1", "turtle_poaching_2" };

	class BaseGather {
		actionTitle = "Gathering";
		gatherTime = 1;
		factions[] = { "Civilian" };
		hidden[] = {};
		reqItems[] = {};
		reqLicenses[] = {};
		profession[] = { "Gathering", 1, 100 };
		leveling[] = { 1, "Gathering", 100 };
		condition = "true";
	};

	class BaseMine : BaseGather {
		actionTitle = "Mining";
		gatherTime = 3;
		reqItems[] = { "Pickaxe" };
		profession[] = { "Mining", 1, 100 };
	};

	class Apple : BaseGather {
		areas[] = { { "apple_field_1", 20 }, { "apple_field_2", 20 }, { "apple_field_3", 20 }, { "apple_field_4", 20 } };
		items[] = { { "FreshApple", 100 } };
	};

	class Peach : BaseGather {
		areas[] = { { "peach_field_1", 20 }, { "peach_field_2", 20 }, { "peach_field_3", 20 }, { "peach_field_4", 20 } };
		items[] = { { "FreshPeach", 100 } };
	};

	class Wood : BaseGather {
		reqItems[] = { "LumberAxe" };
		areas[] = { { "logging_grounds_1", 20 }, { "logging_grounds_2", 20 }, { "logging_grounds_3", 20 }, { "logging_grounds_4", 20 } };
		items[] = { { "wood", 100 } };
		gatherTime = 2;
	};

	class Coral : BaseGather {
		hidden[] = { "Police" };
		areas[] = { { "coral_reef", 20 } };
		items[] = { { "Coral", 100 } };
		leveling[] = { 2, "Gathering", 80 };
	};

	class Corn : BaseGather {
		hidden[] = { "Police" };
		areas[] = { { "corn_field", 20 } };
		items[] = { { "Corn", 100 } };
		gatherTime = 2;
	};

	class Tobacco : BaseGather {
		areas[] = { { "tobacco_field", 20 } };
		items[] = { { "Tobacco", 100 } };
	};

	class Weed : BaseGather {
		hidden[] = { "Police" };
		areas[] = { { "weed_field", 20 } };
		items[] = { { "UnprocessedWeed", 100 } };
	};

	class Heroin : BaseGather {
		hidden[] = { "Police" };
		areas[] = { { "heroin_field", 20 } };
		items[] = { { "UnprocessedHeroin", 100 } };
		leveling[] = { 2, "Gathering", 100 };
		gatherTime = 2;
	};

	class Cocaine : BaseGather {
		hidden[] = { "Police" };
		areas[] = { { "cocaine_field", 20 } };
		items[] = { { "UnprocessedCocaine", 100 } };
		leveling[] = { 2, "Gathering", 100 };
		gatherTime = 2;
	};

	class Coal : BaseMine {
		areas[] = { { "coal_mine", 20 } };
		items[] = { { "coal", 100 } };
	};

	class Copper : BaseMine {
		areas[] = { { "copper_mine", 20 } };
		items[] = { { "CopperOre", 100 } };
	};

	class Silver : BaseMine {
		areas[] = { { "silver_mine", 20 } };
		items[] = { { "SilverOre", 100 } };
		leveling[] = { 2, "Gathering", 100 };
	};

	class Iron : BaseMine {
		areas[] = { { "iron_mine", 20 } };
		items[] = { { "IronOre", 100 } };
		leveling[] = { 3, "Gathering", 90 };
	};

	class Oil : BaseMine {
		reqItems[] = { "Extractor" };
		areas[] = { { "oil_extraction", 20 } };
		items[] = { { "UnprocessedOil", 100 } };
		leveling[] = { 5, "Gathering", 90 };
	};

	class Sand : BaseMine {
		reqItems[] = { "Shovel" };
		areas[] = { { "sand_mine", 20 } };
		items[] = { { "Sand", 100 } };
	};

	class Salt : BaseMine {
		areas[] = { { "salt_mine", 20 } };
		items[] = { { "UnrefinedSalt", 100 } };
	};

	class Diamond : BaseMine {
		areas[] = { { "diamond_mine", 20 } };
		items[] = { { "UncutDiamond", 100 } };
		leveling[] = { 2, "Gathering", 100 };
	};

	class Uranium : BaseMine {
		hidden[] = { "Police" };
		areas[] = { { "uranium_mine", 20 } };
		items[] = { { "UraniumOre", 100 } };
		leveling[] = { 10, "Gathering", 70 };
		gatherTime = 4;
	};

	class Rock : BaseMine {
		areas[] = { { "hmp_rocks", 2 } };
		items[] = { { "Rock", 100 } };
		condition = "ULP_Imprisioned";
	};
};