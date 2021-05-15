class CfgGoals {
	class Personal {
		class Daily {
			Amount = 3;

			class GatherApple {
				type = "GATHERING";
				item = "FreshApple";
				title = "Gather Apples";
				description = "Gather Fresh Apples before today's end!";
				tiers[] = { 250, 500, 1000 };
				condition = "true";
			};
			class GatherPeach : GatherApple {
				item = "FreshPeach";
				title = "Gather Peaches";
				description = "Gather Fresh Peachs before today's end!";
			};
			class GatherCoral : GatherApple {
				item = "Coral";
				title = "Gather Coral";
				description = "Gather Coral before today's end!";
			};
			class GatherCorn : GatherApple {
				item = "Corn";
				title = "Gather Corn";
				description = "Gather Corn before today's end!";
			};

			class MineCoal {
				type = "GATHERING";
				item = "Coal";
				title = "Mine Coal";
				description = "Mine Coal before today's end!";
				tiers[] = { 100, 300, 750 };
				condition = "true";
			};
			class MineCopper : MineCoal {
				item = "CopperOre";
				title = "Mine Copper";
				description = "Mine Copper before today's end!";
			};
			class MineSilver : MineCoal {
				item = "SilverOre";
				title = "Mine Silver";
				description = "Mine Silver before today's end!";
			};
			class MineIron : MineCoal {
				item = "IronOre";
				title = "Mine Iron";
				description = "Mine Iron before today's end!";
			};

			class ProcessTobacco {
				type = "PROCESSING";
				item = "Tobacco";
				title = "Process Tobacco";
				description = "Process Tobacco before today's end!";
				tiers[] = { 100, 250, 500 };
				condition = "true";
			};
			class ProcessOil : ProcessTobacco {
				item = "UnprocessedOil";
				title = "Process Oil";
				description = "Process Oil before today's end!";
			};
			class ProcessSand : ProcessTobacco {
				item = "Sand";
				title = "Process Sand";
				description = "Process Sand before today's end!";
			};
			class ProcessSalt : ProcessTobacco {
				item = "UnrefinedSalt";
				title = "Process Salt";
				description = "Process Salt before today's end!";
			};
			class UncutDiamond : ProcessTobacco {
				item = "UncutDiamond";
				title = "Process Diamonds";
				description = "Process Diamond before today's end!";
			};

			class ProcessUranium {
				type = "PROCESSING";
				item = "UraniumOre";
				title = "Process Uranium";
				description = "Process Uranium before today's end!";
				tiers[] = { 100, 200, 300 };
				condition = "true";
			};
		};

		class Weekly {
			Amount = 2;

			class SellSchnapps {
				type = "SELLING";
				item = "Schnapps";
				title = "Sell Schnapps";
				description = "Sell Schnapps before the week's end!";
				tiers[] = { 1000, 2000, 3000 };
				condition = "true";
			};
			class SellCigarette : SellSchnapps {
				item = "Cigarette";
				title = "Sell Cigarettes";
				description = "Sell Cigarettes before the week's end!";
			};
			class SellCigar : SellSchnapps {
				item = "Cigar";
				title = "Sell Cigars";
				description = "Sell Cigars before the week's end!";
			};
			class SellCopper : SellSchnapps {
				item = "CopperBar";
				title = "Sell Copper";
				description = "Sell Copper before the week's end!";
			};
			class SellSilver : SellSchnapps {
				item = "SilverBar";
				title = "Sell Silver";
				description = "Sell Silver before the week's end!";
			};
			class SellIron : SellSchnapps {
				item = "IronBar";
				title = "Sell Iron";
				description = "Sell Iron before the week's end!";
			};
			class SellSand : SellSchnapps {
				item = "Glass";
				title = "Sell Glass";
				description = "Sell Sand before the week's end!";
			};
			class SellSalt : SellSchnapps {
				item = "RefinedSalt";
				title = "Sell Salt";
				description = "Sell Salt before the week's end!";
			};
			class SellDiamond : SellSchnapps {
				item = "CutDiamond";
				title = "Sell Diamond";
				description = "Sell Diamond before the week's end!";
			};
			class SellMoonshine : SellSchnapps {
				item = "Moonshine";
				title = "Sell Moonshine";
				description = "Sell Moonshine before the week's end!";
			};
		};
	};

	class Community {};
};