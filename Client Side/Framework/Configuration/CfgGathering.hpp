class CfgGathering {
	class BaseGather {
		gatherTime = 4;
		factions[] = { "Civilian" };
		reqItems[] = {};
		reqLicenses[] = {};
	};

	class Apple : BaseGather {
		areas[] = { { "apple_field_1", 20 }, { "apple_field_2", 20 }, { "apple_field_3", 20 } };
		items[] = { { "RedApple", 50 }, { "GreenApple", 20 } };
	};

	class Copper : BaseGather {
		areas[] = { { "copper_mine", 20 } };
		items[] = { { "CopperOre", 100 } };
		actionTitle = "Mining";
	};
};