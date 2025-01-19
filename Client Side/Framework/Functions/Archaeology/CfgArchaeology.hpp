class CfgArchaeology {
	class Common {
		surveyTime[] = { 20, 30 };
		surveyTimes = 1;
		give[] = { 2, 3 }; 
		rewards[] = {
			{ 0, { "OldCoin", 3 } },
			{ 0.55, { "Coal", 6 } },
			{ 0.55, { "UncommonMapFragment", 1 } },
			{ 0.70, { "CommonMapFragment", 2 } },
			{ 0.72, { "BrokenPot", 1 } },
			{ 0.77, { "BluntStoneKnife", 1 } },
			{ 0.78, { "Sand", 3 } },
			{ 0.80, { "Clay", 5 } },
			{ 0.85, { "FossilisedBone", 1 } },
			{ 0.90, { "PetrifiedShield", 1 } },
			{ 0.94, { "WeatheredSculpture", 1 } },
			{ 0.94, { "AncientAmber", 1 } },
			{ 0.94, { "UncutDiamond", 2 } },
			{ 0.95, { "ReligiousTotem", 1 } },
			{ 0.97, { "StrongMetalRing", 1 } }
		};
	};
	
	class Uncommon {
		surveyTime[] = { 30, 40 };
		surveyTimes = 2;
		give[] = { 4, 5 };
		rewards[] = {
			{ 0.10, { "OldCoin", 4 } },
			{ 0.55, { "FossilisedBone", 2 } },
			{ 0.62, { "UncommonMapFragment", 2 } },
			{ 0.62, { "RareMapFragment", 2 } },
			{ 0.64, { "BrokenPot", 1 } },
			{ 0.66, { "CommonMapFragment", 3 } },
			{ 0.67, { "PetrifiedShield", 1 } },
			{ 0.70, { "WeatheredSculpture", 1 } },
			{ 0.72, { "BluntStoneKnife", 2 } },
			{ 0.82, { "Sand", 4 } },
			{ 0.82, { "Clay", 2 } },
			{ 0.86, { "AncientAmber", 2 } },
			{ 0.90, { "Coal", 7 } },
			{ 0.90, { "ReligiousTotem", 1 } },
			{ 0.90, { "StrongMetalRing", 1 } },
			{ 0.90, { "Moonshine", 3 } },
			{ 0.92, { "UncutDiamond", 8 } },
			{ 0.92, { "Turtle_F_Raw", 2 } },
			{ 0.92, { "EmeraldAmulet", 1 } },
			{ 0.97, { "UnidentifiedSkull", 1 } },
			{ 0.98, { "LegendaryMapFragment", 1 } }
		};
	};

	class Rare {
		surveyTime[] = { 40, 50 };
		surveyTimes = 3;
		give[] = { 6, 8 };
		rewards[] = {
			{ 0.20, { "OldCoin", 8 } },
			{ 0.45, { "FossilisedBone", 3 } },
			{ 0.42, { "PetrifiedShield", 1 } },
			{ 0.45, { "WeatheredSculpture", 2 } },
			{ 0.58, { "UncommonMapFragment", 3 } },
			{ 0.58, { "AncientAmber", 2 } },
			{ 0.60, { "RareMapFragment", 2 } },
			{ 0.62, { "UnidentifiedSkull", 1 } },
			{ 0.67, { "ReligiousTotem", 2 } },
			{ 0.72, { "StrongMetalRing", 2 } },
			{ 0.84, { "EmeraldAmulet", 2 } },
			{ 0.86, { "AncientLedger", 1 } },
			{ 0.88, { "LegendaryMapFragment", 2 } },
			{ 0.88, { "HandSmoothedRunestone", 1 } },
			{ 0.88, { "Clay", 8 } },
			{ 0.92, { "Turtle_F_Raw", 5 } },
			{ 0.92, { "UncutDiamond", 12 } },
			{ 0.93, { "BrokenTimepiece", 1 } },
			{ 0.96, { "Moonshine", 4 } },
			{ 0.97, { "JeweledNecklace", 1 } },
			{ 0.99, { "UnmarkedGold", 1 } }
		};
	};

	class Legendary {
		surveyTime[] = { 50, 60 };
		surveyTimes = 5;
		give[] = { 8, 12 };
		rewards[] = {
			{ 0.42, { "PetrifiedShield", 2 } },
			{ 0.44, { "WeatheredSculpture", 2 } },
			{ 0.44, { "AncientAmber", 3 } },
			{ 0.50, { "ReligiousTotem", 2 } },
			{ 0.55, { "StrongMetalRing", 2 } },
			{ 0.60, { "EmeraldAmulet", 1 } },
			{ 0.67, { "AncientLedger", 1 } },
			{ 0.74, { "HandSmoothedRunestone", 1 } },
			{ 0.75, { "UnidentifiedSkull", 1 } },
			{ 0.75, { "BrokenTimepiece", 1 } },
			{ 0.92, { "Turtle_F_Raw", 8 } },
			{ 0.93, { "JeweledNecklace", 2 } },
			{ 0.96, { "CoinBundle", 2 } },
			{ 0.99, { "IdentifiedSkull", 1 } },
			{ 0.99, { "UnmarkedGold", 1 } }
		};
	};
};