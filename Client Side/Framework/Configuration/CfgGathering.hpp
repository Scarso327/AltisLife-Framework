class CfgGathering {
	class BaseGather {
		factions[] = { "Civilian" };
		reqItems[] = {};
		reqLicenses[] = {};
	};

	class Apple : BaseGather {
		areas[] = { { "apple_field_1", 20 }, { "apple_field_2", 20 }, { "apple_field_3", 20 } };
		items[] = { { "RedApple", {1, 3} }, { "GreenApple", {1, 2} } };
	};

	class Copper : BaseGather {
		areas[] = { { "copper_mine", 20 } };
		items[] = { { "CopperOre", {3, 6} } };
	};
};