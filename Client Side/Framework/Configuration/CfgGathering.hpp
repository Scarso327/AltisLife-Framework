class CfgGathering {
	class BaseGather {
		gatherTime = 4;
		factions[] = { "Civilian", "Police", "Medic", "Hato" };
		reqItems[] = {};
		reqLicenses[] = {};
	};

	class Apple : BaseGather {
		areas[] = { { "apple_field_1", 20 }, { "apple_field_2", 20 }, { "apple_field_3", 20 }, { "apple_field_4", 20 } };
		items[] = { { "redApple", 50 }, { "greenApple", 20 } };
	};

	class Peach : BaseGather {
		areas[] = { { "peach_field_1", 20 }, { "peach_field_2", 20 }, { "peach_field_3", 20 }, { "peach_field_4", 20 } };
		items[] = { { "peach", 100 };
	};

	class Tobacco : BaseGather {
		areas[] = { { "tobacco_field", 20 } };
		items[] = { { "tobacco", 100 } };
	};

	class Weed : BaseGather {
		areas[] = { { "weed_field", 20 } };
		items[] = { { "unprocessedWeed", 100 } };
	};

	class Heroin : BaseGather {
		areas[] = { { "heroin_field", 20 } };
		items[] = { { "unprocessedHeroin", 100 } };
	};

	class Cocaine : BaseGather {
		areas[] = { { "cocaine_field", 20 } };
		items[] = { { "unprocessedCocaine", 100 } };
	};

	class Copper : BaseGather {
		areas[] = { { "copper_mine", 20 } };
		items[] = { { "copperOre", 100 } };
		actionTitle = "Mining";
	};

	class Silver : BaseGather {
		areas[] = { { "silver_mine", 20 } };
		items[] = { { "silverOre", 100 } };
		actionTitle = "Mining";
	};

	class Iron : BaseGather {
		areas[] = { { "iron_mine", 20 } };
		items[] = { { "ironOre", 100 } };
		actionTitle = "Mining";
	};

	class Sand : BaseGather {
		areas[] = { { "sand_mine", 20 } };
		items[] = { { "sand", 100 } };
		actionTitle = "Mining";
	};

	class Salt : BaseGather {
		areas[] = { { "salt_mine", 20 } };
		items[] = { { "unrefinedSalt", 100 } };
		actionTitle = "Mining";
	};

	class Diamond : BaseGather {
		areas[] = { { "diamond_mine", 20 } };
		items[] = { { "uncutDiamond", 100 } };
		actionTitle = "Mining";
	};

	class Uranium : BaseGather {
		areas[] = { { "uranium_mine", 20 } };
		items[] = { { "uraniumOre", 100 } };
		actionTitle = "Mining";
	};
};