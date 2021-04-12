class CfgArchaeology {
	class Common {
		surveyTime[] = { 20, 40 };
		surveyTimes = 1;
		give[] = { 2, 3 }; // How many unique items should be given...
		rewards[] = {
			{ 0.95, { "CopperBar", 2 } },
			{ 0.90, { "SilverBar", 2 } },
			{ 0.85, { "IronBar", 2 } },
			{ 0.70, { "UraniumBar", 2 } },
			{ 0, { "MarkedGold", 2 } }
		};
	};
	
	class Uncommon {
		surveyTime[] = { 30, 30 };
		surveyTimes = 2;
		give[] = { 3, 4 };
		rewards[] = {
			{ 0.95, { "CopperBar", 2 } },
			{ 0.90, { "SilverBar", 2 } },
			{ 0.85, { "IronBar", 2 } },
			{ 0.70, { "UraniumBar", 2 } },
			{ 0, { "MarkedGold", 2 } }
		};
	};

	class Rare {
		surveyTime[] = { 40, 60 };
		surveyTimes = 3;
		give[] = { 3, 5 };
		rewards[] = {
			{ 0.95, { "CopperBar", 2 } },
			{ 0.90, { "SilverBar", 2 } },
			{ 0.85, { "IronBar", 2 } },
			{ 0.70, { "UraniumBar", 2 } },
			{ 0, { "MarkedGold", 2 } }
		};
	};
};