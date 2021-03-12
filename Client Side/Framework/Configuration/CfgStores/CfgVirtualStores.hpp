class CfgVirtualStores {
	class Police {
		storeName = "Police Market";
		conditions = "[player, [""Police""]] call ULP_fnc_isFaction";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class FuelCan {};
			class Breathalyser {};
			class GPSTracker {};
			class Stinger {};
			class Lockpick {};
			class BoltCutter {};
			class Painkillers {};
			class Bandage {};
			class BloodBag {};
			class FirstAidKit {};
			class MediKit {};
			class FirstAidKit {};
			class FirstAidKit {};
			class FirstAidKit {};
			class FirstAidKit {};
			class FirstAidKit {};
		};
	};

	class Medic {
		storeName = "Medic Market";
		conditions = "[player, [""Medic""]] call ULP_fnc_isFaction";
		class Items {
			class Apple {};
			class Peach {};
			class Bacon {};
			class Water {};
			class Redbull {};
			class Pickaxe {};
			class Shovel {};
			class FishingNet {};
			class FuelCan {};
			class Lockpick {};
		};
	};

	class Civilian {
		storeName = "General Market";
		conditions = "true";
		class Items {
			class Apple {};
			class Peach {};
			class Bacon {};
			class Water {};
			class Redbull {};
			class Pickaxe {};
			class Shovel {};
			class FishingNet {};
			class FuelCan {};
			class Lockpick {};
		};
	};

	class Rebel {
		storeName = "Rebel Market";
		conditions = "true";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			class BoltCutter {};
			class Painkillers {};
			class Bandage {};
			class FirstAidKit {};
		};
	};

	class Blackmarket {
		storeName = "Blackmarket";
		conditions = "true";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			class BoltCutter {};
			class HackingDevice {};
			class ExplosiveCharge {};
			class IndustrialDrill {};
			class Painkillers {};
			class Bandage {};
			class FirstAidKit {};
			class GalleryPiece {};
		};
	};

	class Burger {
		storeName = "Redburger";
		conditions = "true";
		class Items {
			class Burger {};
			class Hotdog {};
			class Chips {};
			class Water {};
			class Redbull {};
		};
	};

	class Tea {
		storeName = "Tea Room";
		conditions = "true";
		class Items {
			class Doughnut {};
			class Coffee {};
			class Tea {};
		};
	};

	class Pub {
		storeName = "Local Pub";
		conditions = "true";
		class Items {
			class Beer {};
			class Schnaps {};
			class Gin {};
			class Whiskey {};
		};
	};

	class Medical {
		storeName = "Medical Supplies";
		conditions = "true";
		class Items {
			class Painkillers {};
			class Bandage {};
			class BloodBag {};
			class FirstAidKit {};
			class MediKit {};
		};
	};

	class Fish {
		storeName = "Fish Market";
		conditions = "true";
		class Items {
			class RawSalema {};
			class CookedSalema {};
			class RawOrnate {};
			class CookedOrnate {};
			class RawTuna {};
			class CookedTuna {};
			class RawMullet {};
			class CookedMullet {};
			class RawCatshark {};
			class CookedCatshark {};
		};
	};

	class Turtle {
		storeName = "Turtle Dealer";
		conditions = "true";
		class Items {
			class Turtle {};
		};
	};

	class Hunting {
		storeName = "Hunting Camp";
		conditions = "true";
		class Items {
			class CuttingKnife {};
			class UnskinnedRabbit {};
			class SkinnedRabbit {};
			class UnskinnedGoat {};
			class SkinnedGoat {};
		};
	};
	
	class Cigarette {
		storeName = "Cigarette Trader";
		conditions = "true";
		class Items {
			class Cigarette {};
		};
	};

	class Cigar {
		storeName = "Cigar Trader";
		conditions = "true";
		class Items {
			class Cigar {};
		};
	};

	class Coal {
		storeName = "Coal Trader";
		conditions = "true";
		class Items {
			class Coal {};
		};
	};

	class Coral {
		storeName = "Coral Trader";
		conditions = "true";
		class Items {
			class Coral {};
		};
	};

	class Glass {
		storeName = "Glass Trader";
		conditions = "true";
		class Items {
			class Glass {};
		};
	};

	class Salt {
		storeName = "Salt Trader";
		conditions = "true";
		class Items {
			class RefindedSalt {};
		};
	};

	class Diamond {
		storeName = "Diamond Trader";
		conditions = "true";
		class Items {
			class CutDiamond {};
		};
	};

	class Oil {
		storeName = "Oil Trader";
		conditions = "true";
		class Items {
			class ProcessedOil {};
		};
	};

	class Metal {
		storeName = "Altis Metal Exports";
		conditions = "true";
		class Items {
			class CopperBar {};
			class SilverBar {};
			class IronBar {};
		};
	};

	class Uranium {
		storeName = "Uranium Trader";
		conditions = "true";
		class Items {
			class UraniumBar {};
		};
	};

	class Gold {
		storeName = "Gold Buyer";
		conditions = "true";
		class Items {
			class MakredGold {};
			class UnmakredGold {};
		};
	};

	class Drug {
		storeName = "Drug Dealer";
		conditions = "true";
		class Items {
			class ProcessedWeed {};
			class PurifiedWeed {};
			class ProcessedHeroin {};
			class PurifiedHeroin {};
			class ProcessedCocaine {};
			class PurifiedCocaine {};
			class ProcessedMeth {};
			class PurifiedMeth {};
			class Moonshine {};
			class PurifiedMoonshine {};
			class Ecstasy {};
		};
	};
};