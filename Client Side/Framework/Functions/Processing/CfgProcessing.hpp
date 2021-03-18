class CfgProcessing {
	class BaseProcess {
		processTime = 60;
		factions[] = { "Civilian", "Police", "Medic", "Hato" };
		reqItems[] = {};
		reqLicenses[] = {};
		profession[] = { "Processing", 1, 100 };
		leveling[] = { 1, "Processing", 100 }; // Amount, Chance of increasing xp...
	};

	// Skinning
	class Skinning : BaseProcess {
		processTitle = "Skinning";
		processTime = 40;
		profession[] = { "Skinning", 1, 100 };
		reqItems[] = { { "cuttingKnife", 1 } };
	};

	class Rabbit : Skinning {
		materials[] = { { "UnskinnedRabbit", 1 } };
		items[] = { { "SkinnedRabbit", 1 } };
	};

	class Goat : Skinning {
		materials[] = { { "UnskinnedGoat", 1 } };
		items[] = { { "SkinnedGoat", 1 } };
	};

	// Cooking
	class Cooking : BaseProcess {
		processTitle = "Cooking";
		processTime = 30;
		profession[] = { "Cooking", 1, 100 };
	};

	class Salema : Cooking {
		materials[] = { { "RawSalema", 1 } };
		items[] = { { "CookedSalema", 1 } };
	};

	class Ornate : Cooking {
		materials[] = { { "RawOrnate", 1 } };
		items[] = { { "CookedOrnate", 1 } };
	};

	class Tuna : Cooking {
		materials[] = { { "RawTuna", 1 } };
		items[] = { { "CookedTuna", 1 } };
	};

	class Mullet : Cooking {
		materials[] = { { "RawMullet", 1 } };
		items[] = { { "CookedMullet", 1 } };
	};

	class Catshark : Cooking {
		materials[] = { { "RawCatshark", 1 } };
		items[] = { { "CookedCatshark", 1 } };
	};

	// Smelting
	class Smelting : BaseProcess { 
		processTitle = "Smelting";
		profession[] = { "Smelting", 1, 100 };
	};

	class Copper : Smelting {
		materials[] = { { "CopperOre", 1 } };
		items[] = { { "CopperBar", 1 } };
		reqLicenses[] = {};
	};

	class Silver : Smelting {
		materials[] = { { "SilverOre", 1 } };
		items[] = { { "SilverBar", 1 } };
		reqLicenses[] = {};
	};

	class Iron : Smelting {
		materials[] = { { "IronOre", 1 } };
		items[] = { { "IronBar", 1 } };
		reqLicenses[] = {};
	};

	class Sand : Smelting {
		materials[] = { { "Sand", 1 } };
		items[] = { { "Glass", 1 } };
		reqLicenses[] = {};
	};

	// Refining
	class Salt : BaseProcess {
		processTitle = "Refining";
		materials[] = { { "UnrefinedSalt", 1 } };
		items[] = { { "RefindedSalt", 1 } };
		reqLicenses[] = {};
	};

	// Cutting
	class Diamond : BaseProcess {
		processTitle = "Cutting";
		materials[] = { { "UncutDiamond", 1 } };
		items[] = { { "CutDiamond", 1 } };
		reqLicenses[] = {};
	};

	// Processing
	class Processing : BaseProcess { processTitle = "Processing"; };

	class SchnapsApple : Processing {
		processTime = 40;
		materials[] = { { "FreshApple", 2 } };
		items[] = { { "Schnapps", 1 } };
		reqLicenses[] = {};
	};

	class SchnapsPeach : Processing {
		processTime = 40;
		materials[] = { { "FreshPeach", 2 } };
		items[] = { { "Schnapps", 1 } };
		reqLicenses[] = {};
	};

	class Cigarette : BaseProcess {
		materials[] = { { "Tobacco", 1 } };
		items[] = { { "Cigarette", 1 } };
		reqLicenses[] = {};
	};

	class Cigar : BaseProcess {
		processTime = 70;
		materials[] = { { "Tobacco", 1 } };
		items[] = { { "Cigar", 1 } };
		reqLicenses[] = {};
	};

	class Weed : BaseProcess {
		materials[] = { { "UnprocessedWeed", 1 } };
		items[] = { { "ProcessedWeed", 1 } };
		reqLicenses[] = {};
	};

	class PurifiedWeed : BaseProcess {
		processTime = 100;
		materials[] = { { "ProcessedWeed", 1 } };
		items[] = { { "PurifiedWeed", 1 } };
		reqLicenses[] = {};
	};

	class Heroin : BaseProcess {
		processTime = 70;
		materials[] = { { "UnprocessedHeroin", 1 } };
		items[] = { { "ProcessedHeroin", 1 } };
		reqLicenses[] = {};
	};

	class PurifiedHeroin : BaseProcess {
		processTime = 100;
		materials[] = { { "ProcessedHeroin", 1 } };
		items[] = { { "PurifiedHeroin", 1 } };
		reqLicenses[] = {};
	};

	class Cocaine : BaseProcess {
		processTime = 80;
		materials[] = { { "UnprocessedCocaine", 1 } };
		items[] = { { "ProcessedCocaine", 1 } };
		reqLicenses[] = {};
	};

	class PurifiedCocaine : BaseProcess {
		processTime = 100;
		materials[] = { { "ProcessedCocaine", 1 } };
		items[] = { { "PurifiedCocaine", 1 } };
		reqLicenses[] = {};
	};

	class Meth : BaseProcess {
		processTime = 90;
		materials[] = { { "EphedrineBarrel", 1 } };
		items[] = { { "ProcessedMeth", 1 } };
		reqLicenses[] = {};
	};

	class PurifiedMeth : BaseProcess {
		processTime = 100;
		materials[] = { { "ProcessedMeth", 1 } };
		items[] = { { "PurifiedMeth", 1 } };
		reqLicenses[] = {};
	};

	class Moonshine : BaseProcess {
		processTime = 90;
		materials[] = { { "Corn", 1 } };
		items[] = { { "Moonshine", 1 } };
		reqLicenses[] = {};
	};

	class PurifiedMoonshine : BaseProcess {
		processTime = 100;
		materials[] = { { "Moonshine", 1 } };
		items[] = { { "PurifiedMoonshine", 1 } };
		reqLicenses[] = {};
	};

	class Uranium : BaseProcess {
		processTime = 100;
		materials[] = { { "UraniumOre", 1 } };
		items[] = { { "UraniumBar", 1 } };
		reqLicenses[] = {};
	};

	class Oil : BaseProcess {
		materials[] = { { "UnprocessedOil", 1 } };
		items[] = { { "ProcessedOil", 1 } };
	};

	class Gold : BaseProcess {
		processTime = 120;
		materials[] = { { "UnmarkedGold", 1 } };
		items[] = { { "MarkedGold", 1 } };
	};
};