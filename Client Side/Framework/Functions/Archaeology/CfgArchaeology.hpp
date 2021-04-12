class CfgArchaeology {
	class Common {
		surveyTime[] = { 20, 40 };
		surveyTimes = 1;
		give[] = { 2, 3 }; // How many unique items should be given...
		rewards[] = {
			{ 0.70, { "OldCoin", 5 } },
			{ 0.73, { "BrokenPot", 1 } },
			{ 0.74, { "BluntStoneKnife", 1 } },
			{ 0.75, { "FossilisedBone", 3 } },
			{ 0.76, { "UnidentifiedSkull", 2 } },
			{ 0.77, { "PetrifiedShield", 1 } },
			{ 0.78, { "WeatheredSculpture", 1 } },
			{ 0.79, { "AncientAmber", 1 } },
			{ 0.80, { "RegliousTotem", 1 } },
			{ 0.85, { "StrongMetalRing", 1 } },
			{ 0.90, { "EmeraldAmulet", 1 } },
			{ 0.92, { "AncientLedger", 1 } },
			{ 0.95, { "HandSmoothedRunestone", 1 } },
			{ 0.97, { "JeweledNecklace", 1 } },
			{ 0.99, { "BrokenTimepiece", 1 } }
		};
	};
	
	class Uncommon {
		surveyTime[] = { 30, 30 };
		surveyTimes = 2;
		give[] = { 4, 5 };
		rewards[] = {
			{ 0.65, { "AncientAmber", 3 } },
			{ 0.68, { "StrongMetalRing", 4 } },
			{ 0.70, { "OldCoin", 8 } },
			{ 0.73, { "BrokenPot", 1 } },
			{ 0.75, { "FossilisedBone", 4 } },
			{ 0.76, { "BluntStoneKnife", 2 } },
			{ 0.77, { "UnidentifiedSkull", 3 } },
			{ 0.80, { "RegliousTotem", 1 } },
			{ 0.83, { "PetrifiedShield", 2 } },
			{ 0.86, { "WeatheredSculpture", 1 } },
			{ 0.88, { "EmeraldAmulet", 2 } },
			{ 0.90, { "AncientLedger", 1 } },
			{ 0.93, { "HandSmoothedRunestone", 3 } },
			{ 0.95, { "JeweledNecklace", 2 } },
			{ 0.97, { "BrokenTimepiece", 1 } }
		};
	};

	class Rare {
		surveyTime[] = { 40, 60 };
		surveyTimes = 3;
		give[] = { 7, 8 };
		rewards[] = {
			{ 0.60, { "BluntStoneKnife", 3 } },
			{ 0.63, { "BrokenPot", 1 } },
			{ 0.65, { "OldCoin", 17 } },
			{ 0.67, { "FossilisedBone", 7 } },
			{ 0.68, { "UnidentifiedSkull", 3 } },
			{ 0.70, { "PetrifiedShield", 2 } },
			{ 0.74, { "AncientAmber", 4 } },
			{ 0.75, { "WeatheredSculpture", 2 } },
			{ 0.76, { "StrongMetalRing", 5 } },
			{ 0.78, { "EmeraldAmulet", 3 } },
			{ 0.80, { "RegliousTotem", 2 } },
			{ 0.85, { "AncientLedger", 1 } },
			{ 0.88, { "JeweledNecklace", 3 } },
			{ 0.90, { "HandSmoothedRunestone", 5 } },
			{ 0.95, { "BrokenTimepiece", 2 } }
		};
	};
};