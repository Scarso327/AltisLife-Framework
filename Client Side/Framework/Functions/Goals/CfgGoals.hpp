class CfgGoals {
	class Personal {
		class Daily {
			Amount = 5;

			class GatherCopper {
				type = "GATHERING";
				item = "CopperOre";
				title = "Copper Kings";
				description = "Mine Copper Ore before todays end!";
				tiers[] = { 300, 500, 700 };
				condition = "true";
			};

			class GatherSilver {
				type = "GATHERING";
				item = "SilverOre";
				title = "Silverware";
				description = "Mine Silver Ore before todays end!";
				tiers[] = { 300, 500, 700 };
				condition = "true";
			};

			class GatherIron {
				type = "GATHERING";
				item = "IronOre";
				title = "Ironman";
				description = "Mine Iron Ore before todays end!";
				tiers[] = { 300, 500, 700 };
				condition = "true";
			};

			class SellCopper {
				type = "SELLING";
				item = "CopperBar";
				title = "Seat of Copper";
				description = "Sell Copper Bar(s) before todays end!";
				tiers[] = { 100, 150, 300 };
				condition = "true";
			};

			class SellSilver {
				type = "SELLING";
				item = "SilverOre";
				title = "Silver Rings";
				description = "Sell Silver Bar(s) before todays end!";
				tiers[] = { 100, 150, 300 };
				condition = "true";
			};

			class SellIron {
				type = "SELLING";
				item = "IronBar";
				title = "Iron Suits";
				description = "Sell Iron Bar(s) before todays end!";
				tiers[] = { 100, 150, 300 };
				condition = "true";
			};
		};

		class Weekly {
			Amount = 2;
			
			class GatherCopper {
				type = "GATHERING";
				item = "CopperOre";
				title = "Copper Gods";
				description = "Mine Copper Ore before the weeks end!";
				tiers[] = { 500, 750, 1000 };
				condition = "true";
			};

			class GatherSilver {
				type = "GATHERING";
				item = "SilverOre";
				title = "Roads of Silver";
				description = "Mine Silver Ore before the weeks end!";
				tiers[] = { 500, 750, 1000 };
				condition = "true";
			};

			class SellCopper {
				type = "SELLING";
				item = "CopperBar";
				title = "Throne of Copper";
				description = "Sell Copper Bar(s) before the weeks end!";
				tiers[] = { 600, 800, 1000 };
				condition = "true";
			};
		};
	};

	class Community {
		// TODO
	};
};