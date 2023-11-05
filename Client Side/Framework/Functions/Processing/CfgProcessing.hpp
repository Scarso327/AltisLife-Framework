class CfgProcessing {
	class BaseProcess {
		processTitle = "Processing";
		processTime = 60;
		factions[] = { "Civilian", "Police", "Medic", "Hato" };
		hidden[] = {};
		reqItems[] = {};
		reqLicenses[] = {};
		profession[] = { "Processing", 1, 100 };
		leveling[] = { 1, "Processing", 100 }; // Amount, Chance of increasing xp...
	};

	// Cooking
	class Cooking : BaseProcess {
		processTitle = "Cooking";
		processTime = 30;
		profession[] = { "Cooking", 1, 100 };
	};

	class Salema : Cooking {
		materials[] = { { "Salema_F_Raw", 1 } };
		items[] = { { "CookedSalema", 1 } };
	};

	class Ornate : Cooking {
		materials[] = { { "Ornate_random_F_Raw", 1 } };
		items[] = { { "CookedOrnate", 1 } };
	};

	class Mackerel : Cooking {
		materials[] = { { "Mackerel_F_Raw", 1 } };
		items[] = { { "CookedMackerel", 1 } };
	};

	class Tuna : Cooking {
		materials[] = { { "Tuna_F_Raw", 1 } };
		items[] = { { "CookedTuna", 1 } };
	};

	class Mullet : Cooking {
		materials[] = { { "Mullet_F_Raw", 1 } };
		items[] = { { "CookedMullet", 1 } };
	};

	class Catshark : Cooking {
		materials[] = { { "CatShark_F_Raw", 1 } };
		items[] = { { "CookedCatshark", 1 } };
	};

	// Smelting
	class Smelting : BaseProcess { 
		processTitle = "Smelting";
		profession[] = { "Processing", 1, 100 };
	};

	class Copper : Smelting {
		materials[] = { { "CopperOre", 1 } };
		items[] = { { "CopperBar", 1 } };
		reqLicenses[] = { "Copper" };
	};

	class Silver : Smelting {
		materials[] = { { "SilverOre", 1 } };
		items[] = { { "SilverBar", 1 } };
		reqLicenses[] = { "Silver" };
	};

	class Iron : Smelting {
		materials[] = { { "IronOre", 1 } };
		items[] = { { "IronBar", 1 } };
		reqLicenses[] = { "Iron" };
	};

	class Sand : Smelting {
		materials[] = { { "Sand", 1 } };
		items[] = { { "Glass", 1 } };
		reqLicenses[] = { "Sand" };
	};

	// Refining
	class Salt : BaseProcess {
		processTitle = "Refining";
		materials[] = { { "UnrefinedSalt", 1 } };
		items[] = { { "RefinedSalt", 1 } };
		reqLicenses[] = { "Salt" };
	};

	// Cutting
	class Diamond : BaseProcess {
		processTitle = "Cutting";
		materials[] = { { "UncutDiamond", 1 } };
		items[] = { { "CutDiamond", 1 } };
		reqLicenses[] = { "Diamond" };
	};

	// Processing
	class SchnapsApple : BaseProcess {
		processTime = 40;
		materials[] = { { "FreshApple", 2 } };
		items[] = { { "Schnapps", 1 } };
		reqLicenses[] = { "Schnapps" };
	};

	class SchnapsPeach : BaseProcess {
		processTime = 40;
		materials[] = { { "FreshPeach", 2 } };
		items[] = { { "Schnapps", 1 } };
		reqLicenses[] = { "Schnapps" };
	};

	class Cigarette : BaseProcess {
		materials[] = { { "Tobacco", 1 } };
		items[] = { { "Cigarette", 1 } };
		reqLicenses[] = { "Tobacco" };
	};

	class Cigar : BaseProcess {
		processTime = 70;
		materials[] = { { "Tobacco", 1 } };
		items[] = { { "Cigar", 1 } };
		reqLicenses[] = { "Tobacco" };
	};

	class Weed : BaseProcess {
		materials[] = { { "UnprocessedWeed", 1 } };
		items[] = { { "ProcessedWeed", 1 } };
		reqLicenses[] = { "Weed" };
	};

	class PurifiedWeed : BaseProcess {
		processTime = 100;
		materials[] = { { "ProcessedWeed", 1 } };
		items[] = { { "PurifiedWeed", 1 } };
	};

	class Heroin : BaseProcess {
		processTime = 70;
		materials[] = { { "UnprocessedHeroin", 1 } };
		items[] = { { "ProcessedHeroin", 1 } };
		reqLicenses[] = { "Heroin" };
	};

	class PurifiedHeroin : BaseProcess {
		processTime = 100;
		materials[] = { { "ProcessedHeroin", 1 } };
		items[] = { { "PurifiedHeroin", 1 } };
	};

	class Cocaine : BaseProcess {
		processTime = 80;
		materials[] = { { "UnprocessedCocaine", 1 } };
		items[] = { { "ProcessedCocaine", 1 } };
		reqLicenses[] = { "Cocaine" };
	};

	class PurifiedCocaine : BaseProcess {
		processTime = 100;
		materials[] = { { "ProcessedCocaine", 1 } };
		items[] = { { "PurifiedCocaine", 1 } };
	};

	class Meth : BaseProcess {
		processTime = 90;
		materials[] = { { "EphedrineBarrel", 1 } };
		items[] = { { "ProcessedMeth", 1 } };
		reqLicenses[] = { "Meth" };
	};

	class PurifiedMeth : BaseProcess {
		processTime = 100;
		materials[] = { { "ProcessedMeth", 1 } };
		items[] = { { "PurifiedMeth", 1 } };
	};

	class Moonshine : BaseProcess {
		processTime = 90;
		materials[] = { { "Corn", 1 } };
		items[] = { { "Moonshine", 1 } };
		reqLicenses[] = { "Moonshine" };
	};

	class PurifiedMoonshine : BaseProcess {
		processTime = 100;
		materials[] = { { "Moonshine", 1 } };
		items[] = { { "PurifiedMoonshine", 1 } };
	};

	class Uranium : BaseProcess {
		processTime = 100;
		materials[] = { { "UraniumOre", 1 } };
		items[] = { { "UraniumBar", 1 } };
		reqLicenses[] = { "Uranium" };
	};

	class Oil : BaseProcess {
		materials[] = { { "UnprocessedOil", 1 } };
		items[] = { { "ProcessedOil", 1 } };
		reqLicenses[] = { "Oil" };
	};

	class Gold : BaseProcess {
		processTime = 120;
		materials[] = { { "UnmarkedGold", 1 } };
		items[] = { { "MarkedGold", 1 } };
	};

	// Decrypting
	class Secrets : BaseProcess {
		processTitle = "Decrypting";
		processTime = 180;
		materials[] = { { "EncryptedDrive", 1 } };
		items[] = { { "DecryptedDrive", 1 } };
	};
};