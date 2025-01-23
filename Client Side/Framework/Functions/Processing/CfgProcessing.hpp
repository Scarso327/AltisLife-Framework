class CfgProcessing {
	class BaseProcess {
		processTitle = "Processing";
		processTime = 60;
		factions[] = { "Civilian" };
		hidden[] = {};
		reqItems[] = {};
		reqLicenses[] = {};
		profession[] = { "Processing", 1, 100 };
		leveling[] = { 1, "Processing", 100 };
	};
	class BaseCook : BaseProcess {
		processTitle = "Cooking";
		processTime = 30;
		profession[] = { "Cooking", 1, 100 };
	};
	class BaseSmelt : BaseProcess {
		processTitle = "Smelting";
		profession[] = { "Smelting", 1, 100 };
	};

	// Cooking
	class Salema : BaseCook {
		materials[] = { { "Salema_F_Raw", 1 } };
		items[] = { { "CookedSalema", 1 } };
	};
	class Ornate : BaseCook {
		materials[] = { { "Ornate_random_F_Raw", 1 } };
		items[] = { { "CookedOrnate", 1 } };
	};
	class Mackerel : BaseCook {
		materials[] = { { "Mackerel_F_Raw", 1 } };
		items[] = { { "CookedMackerel", 1 } };
	};
	class Tuna : BaseCook {
		materials[] = { { "Tuna_F_Raw", 1 } };
		items[] = { { "CookedTuna", 1 } };
	};
	class Mullet : BaseCook {
		materials[] = { { "Mullet_F_Raw", 1 } };
		items[] = { { "CookedMullet", 1 } };
	};
	class Catshark : BaseCook {
		materials[] = { { "CatShark_F_Raw", 1 } };
		items[] = { { "CookedCatshark", 1 } };
	};

	// Processing
	class SchnapsApple : BaseProcess {
		processTime = 40;
		materials[] = { { "FreshApple", 2 } };
		items[] = { { "Schnapps", 1 } };
		reqLicenses[] = { "Schnapps" };
	};
	class SchnapsPeach : SchnapsApple {
		materials[] = { { "FreshPeach", 2 } };
		items[] = { { "Schnapps", 1 } };
	};
	class Cigarette : BaseProcess {
		materials[] = { { "Tobacco", 1 } };
		items[] = { { "Cigarette", 1 } };
		reqLicenses[] = { "Tobacco" };
	};
	class Cigar : Cigarette {
		materials[] = { { "Tobacco", 1 } };
		items[] = { { "Cigar", 1 } };
	};
	class Weed : BaseProcess {
		materials[] = { { "UnprocessedWeed", 1 } };
		items[] = { { "ProcessedWeed", 1 } };
		reqLicenses[] = { "Weed" };
	};
	class Heroin : BaseProcess {
		materials[] = { { "UnprocessedHeroin", 1 } };
		items[] = { { "ProcessedHeroin", 1 } };
		reqLicenses[] = { "Heroin" };
	};
	class Cocaine : BaseProcess {
		materials[] = { { "UnprocessedCocaine", 1 } };
		items[] = { { "ProcessedCocaine", 1 } };
		reqLicenses[] = { "Cocaine" };
	};
	class Meth : BaseProcess {
		materials[] = { { "EphedrineBarrel", 1 } };
		items[] = { { "ProcessedMeth", 1 } };
		reqLicenses[] = { "Meth" };
	};
	class Moonshine : BaseProcess {
		materials[] = { { "Corn", 1 } };
		items[] = { { "Moonshine", 1 } };
		reqLicenses[] = { "Moonshine" };
	};
	
  	class Weapons : BaseProcess {
		processTime = 80;
		materials[] = { { "WeaponParts", 2 } };
		items[] = { { "WeaponCrate", 1 } };
		reqLicenses[] = { "Weapons" };
	};

	// Purifing
	class PurifiedWeed : BaseProcess {
		processTime = 90;
		processTitle = "Purifing";
		materials[] = { { "ProcessedWeed", 1 } };
		items[] = { { "PurifiedWeed", 1 } };
	};
	class PurifiedHeroin : PurifiedWeed {
		materials[] = { { "ProcessedHeroin", 1 } };
		items[] = { { "PurifiedHeroin", 1 } };
	};
	class PurifiedCocaine : PurifiedWeed {
		materials[] = { { "ProcessedCocaine", 1 } };
		items[] = { { "PurifiedCocaine", 1 } };
	};
	class PurifiedMeth : PurifiedWeed {
		materials[] = { { "ProcessedMeth", 1 } };
		items[] = { { "PurifiedMeth", 1 } };
	};
	class PurifiedMoonshine : PurifiedWeed {
		materials[] = { { "Moonshine", 1 } };
		items[] = { { "PurifiedMoonshine", 1 } };
	};

	// Smelting
	class Copper : BaseSmelt {
		materials[] = { { "CopperOre", 1 } };
		items[] = { { "CopperBar", 1 } };
		reqLicenses[] = { "Copper" };
	};
	class Silver : BaseSmelt {
		materials[] = { { "SilverOre", 1 } };
		items[] = { { "SilverBar", 1 } };
		reqLicenses[] = { "Silver" };
	};
	class Iron : BaseSmelt {
		materials[] = { { "IronOre", 1 } };
		items[] = { { "IronBar", 1 } };
		reqLicenses[] = { "Iron" };
	};
	class Sand : BaseSmelt {
		materials[] = { { "Sand", 1 } };
		items[] = { { "Glass", 1 } };
		reqLicenses[] = { "Sand" };
	};
	class Uranium : BaseSmelt {
		materials[] = { { "UraniumOre", 1 } };
		items[] = { { "UraniumBar", 1 } };
		reqLicenses[] = { "Uranium" };
		processTime = 100;
	};

	// Refining
	class Salt : BaseProcess {
		processTitle = "Refining";
		materials[] = { { "UnrefinedSalt", 1 } };
		items[] = { { "RefinedSalt", 1 } };
		reqLicenses[] = { "Salt" };
	};
	class Oil : Salt {
		materials[] = { { "UnprocessedOil", 1 } };
		items[] = { { "ProcessedOil", 1 } };
		reqLicenses[] = { "Oil" };
	};

	// Cutting
	class Diamond : BaseProcess {
		processTitle = "Cutting";
		materials[] = { { "UncutDiamond", 1 } };
		items[] = { { "CutDiamond", 1 } };
		reqLicenses[] = { "Diamond" };
	};
	class BloodDiamond : Diamond {
		materials[] = { { "UncutBloodDiamond", 1 } };
		items[] = { { "CutBloodDiamond", 1 } };
	};

	// Majors
	class Gold : BaseProcess {
		processTime = 120;
		materials[] = { { "UnmarkedGold", 1 } };
		items[] = { { "MarkedGold", 1 } };
	};
	class Secrets : Gold {
		processTitle = "Decrypting";
		materials[] = { { "EncryptedDrive", 1 } };
		items[] = { { "DecryptedDrive", 1 } };
	};
};