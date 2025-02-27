class CfgVirtualStores {
	class Police {
		storeName = "Equipment Store";
		conditions = "[player, [""Police""]] call ULP_fnc_isFaction";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class FuelCan {};
			class PanicButton {};
			class Stinger {};
			class Blindfold {};
			class Lockpick {};
			class BigRedKey {};
			class FieldDressing {};
			class BloodBag {};
			class MediKit {};
			class Defibrillator {};
			class Stretcher {};
		};
	};

	class PoliceEvidence {
		storeName = "Evidence Store";
		conditions = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 2] call ULP_fnc_hasAccess }";
		class Items {
			// Tools
			class Ziptie { sellPrice = 675; };
			class Blindfold { sellPrice = 850; };
			class Lockpick { sellPrice = 125; };
			class SnapGun { sellPrice = 3000; };
			class BoltCutter { sellPrice = 17250; };
			class HackingDevice { sellPrice = 23750; };
			class ExplosiveCharge { sellPrice = 37500; };
			class IndustrialDrill { sellPrice = 30000; };

			// Runs
			class Turtle_F_Raw { sellPrice = 3563; };
			class Coral { sellPrice = 838; };
			class ProcessedWeed { sellPrice = 743; };
			class ProcessedHeroin { sellPrice = 1185; };
			class ProcessedCocaine { sellPrice = 1931; };
			class Moonshine { sellPrice = 868; };
			class ProcessedMeth { sellPrice = 3813; };
			class PurifiedWeed { sellPrice = 964; };
			class PurifiedHeroin { sellPrice = 1695; };
			class PurifiedCocaine { sellPrice = 2532; };
			class PurifiedMoonshine { sellPrice = 1106; };
			class PurifiedMeth { sellPrice = 5247; };
			class Ecstasy { sellPrice = 656; };
			class CutBloodDiamond { sellPrice = 1188; };
			class UraniumBar { sellPrice = 2769; };
			class WeaponCrate { sellPrice = 7338; };

			// Majors
			class MarkedGold { sellPrice = 31250; };
			class UnmarkedGold { sellPrice = 87500; };
			class EncryptedDrive { sellPrice = 50000; };
			class DecryptedDrive { sellPrice = 125000; };
			class SeizedContraband { sellPrice = 29700; };
		};
	};

	class Medic : Police {
		storeName = "Equipment Store";
		conditions = "[player, [""Medic""]] call ULP_fnc_isFaction";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class Sweetie {};
			class FuelCan {};
			class PanicButton {};
			class Lockpick {};
			class FieldDressing {};
			class Elastic {};
			class Packing {};
			class QuickClot {};
			class BloodBag {};
			class MediKit {};
			class Defibrillator {};
			class Stretcher {};
		};
	};

	class Hato : Police {
		conditions = "[player, [""Hato""]] call ULP_fnc_isFaction";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class FuelCan {};
			class PanicButton {};
			class Lockpick {};
			class VehicleClamp {};
			class FieldDressing {};
			class BloodBag {};
			class MediKit {};
			class Defibrillator {};
		};
	};

	class Placeables {
		storeName = "Placeables Store";
		conditions = "[player, [""Police""]] call ULP_fnc_isFaction || [player, [""Medic""]] call ULP_fnc_isFaction || [player, [""Hato""]] call ULP_fnc_isFaction";
		class Items {
			// Cones
			class RoadCone_F {};
			class RoadCone_L_F {};
			class Pole_F {};

			// Portable Lights
			class Land_PortableLight_single_F {};
			class Land_PortableLight_double_F {};
			class Land_PortableLight_02_single_yellow_F {};
			class Land_PortableLight_02_double_yellow_F {};
			class Land_PortableLight_02_quad_yellow_F {};

			// Gates
			class Land_BarGate_F {};
			class Land_RoadBarrier_01_F {};

			// Barriers
			class TapeSign_F {};
			class RoadBarrier_F {};
			class RoadBarrier_small_F {};
			class PlasticBarrier_03_orange_F {};
			class PlasticBarrier_03_blue_F {};
			class PlasticBarrier_02_yellow_F {};
			class PlasticBarrier_02_grey_F {};
			class Land_CncBarrier_F {};
			class Land_CncBarrier_stripes_F {};

			// Sandbags
			class Land_SandbagBarricade_01_half_F {};
			class Land_BagFence_Long_F {};
			class Land_BagFence_Short_F {};
			class Land_BagFence_Round_F {};

			// Hedgehogs
			class Land_CzechHedgehog_01_old_F {};

			// Camping
			class Land_CampingTable_white_F {};
			class Land_CampingTable_small_white_F {};
			class Land_CampingChair_V2_white_F {};
			class Land_FieldToilet_F {};

			// Targets
			class Target_F {};
			class Land_Target_Dueling_01_F {};
			class Scarecrow_01_F {};

			// Flags
			class Flag_UK_F {};
			class Flag_AltisColonial_F {};
			class Flag_RedCrystal_F {};

			// Lights
			class PortableHelipadLight_01_yellow_F {};
			class PortableHelipadLight_01_white_F {};
			class PortableHelipadLight_01_red_F {};
			class PortableHelipadLight_01_green_F {};
			class PortableHelipadLight_01_blue_F {};
			class PortableHelipadLight_01_F {};
		};
	};

	class Dunamis {
		storeName = "Dunamis Market";
		conditions = "[] call ULP_fnc_isDunamis";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class Pickaxe {};
			class LumberAxe {};
            class Extractor {};
			class Shovel {};
			class FishingNet {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lighter {};
			class Lockpick {};
			class Toolbox {};
			class BoltCutter {};
			class HackingDevice {};
			class ExplosiveCharge {};
			class IndustrialDrill {};
			class FieldDressing {};
			class FirstAidKit {};
			class MediKit {};
		};
	};

	class Civilian {
		storeName = "General Market";
		conditions = "true";
		class Items {
			class Water {};
			class FreshApple {};
			class Apple {};
			class FreshPeach {};
			class Peach {};
			class Bacon {};
			class SausageRoll {};
			class Pickaxe {};
			class LumberAxe {};
            class Extractor {};
			class Shovel {};
			class FishingNet {};
			class FuelCan {};
			class Lighter {};
			class Lockpick {};
			class Toolbox {};
			class Plank {};
		};
	};

	class Government {
		storeName = "Government Market";
		conditions = "[] call ULP_fnc_isGovernor || { [] call ULP_fnc_isProtection }";
		class Items {
			class RationPack {};
			class Doughnut {};
			class Coffee {};
			class Tea {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class PanicButton {};
			class Painkillers {};
			class FieldDressing {};
			class BloodBag {};
			class FirstAidKit {};
			class MediKit {};
		};
	};

	class Hideout {
		storeName = "Hideout Market";
		conditions = "true";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			class FieldDressing {};
			class FirstAidKit {};
		};
	};

	class Rebel {
		storeName = "Rebel Market";
		conditions = "[""Rebel""] call ULP_fnc_hasLicense";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class FuelCan {};
			class Ziptie {};
			class Blindfold {};
			class Lockpick {};
			class BoltCutter {};
			class FieldDressing {};
			class FirstAidKit {};
		};
	};

	class Blackmarket {
		storeName = "Blackmarket";
		conditions = "[""Blackmarket""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk || [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
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
			class FieldDressing {};
			class FirstAidKit {};
		};
	};

	class Base : Blackmarket {
		storeName = "Gang Base Market";
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
			class FieldDressing {};
			class FirstAidKit {};
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
			class Schnapps {};
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
			class FieldDressing {};
			class Elastic {};
			class Packing {};
			class QuickClot {};
			class BloodBag {};
			class Morphine {};
			class Epinephrine {};
			class FirstAidKit {};
			class Defibrillator {};
		};
	};

	class Fish {
		storeName = "Fish Market";
		conditions = "true";
		class Items {
			class Salema_F_Raw {};
			class CookedSalema {};
			class Ornate_random_F_Raw {};
			class CookedOrnate {};
			class Mackerel_F_Raw {};
			class CookedMackerel {};
			class Tuna_F_Raw {};
			class CookedTuna {};
			class Mullet_F_Raw {};
			class CookedMullet {};
			class CatShark_F_Raw {};
			class CookedCatshark {};
		};
	};

	class Turtle {
		storeName = "Turtle Dealer";
		conditions = "true";
		class Items {
			class Turtle_F_Raw {};
		};
	};
	
	class Cigarette {
		storeName = "Cigarette Trader";
		conditions = "true";
		class Items {
			class Lighter {};
			class Cigarette {};
		};
	};

	class Cigar {
		storeName = "Cigar Trader";
		conditions = "true";
		class Items {
			class Lighter {};
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
			class RefinedSalt {};
		};
	};

	class Diamond {
		storeName = "Diamond Trader";
		conditions = "true";
		class Items {
			class CutDiamond {};
			class CutBloodDiamond {};
			class FlawlessDiamond {};
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
			class MarkedGold {};
			class UnmarkedGold {};
		};
	};

	class Secrets {
		storeName = "Secrets Buyer";
		conditions = "true";
		class Items {
			class SpaceCapsuleDataDrive {};
			class EncryptedDrive {};
			class DecryptedDrive {};
		};
	};

	class Contraband {
		storeName = "Contraband Trader";
		conditions = "true";
		class Items {
			class SeizedContraband {};
		};
	};

	class Dispensary {
		storeName = "Meth Dispensary";
		conditions = "true";
		class Items {
			class EphedrineBarrel {};
		};
	};

	class WeaponParts {
		storeName = "Weapon Parts";
		conditions = "true";
		class Items {
			class WeaponParts {};
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

	class Weapons {
		storeName = "Weapon Parts";
		conditions = "[""Church""] call ULP_fnc_ownsCartel";
		class Items {
			class WeaponCrate {};
		};
	};

	class HMP {
		storeName = "HMP Market";
		conditions = "ULP_Imprisioned";
		class Items {
			class RationPack {};
			class Water {};
			class Pickaxe {};
			class Rock {};
		};
	};

	class Archaeology {
		storeName = "Altis Archaeologists";
		class Items {
			class CommonMap {};
			class UncommonMap {};
			class RareMap {};
			class LegendaryMap {};
			class SurveyingEquipment {};
			class ArchaeologistsEquipment {};
		};
	};

	class Artifact {
		storeName = "Artifact Trader";
		class Items {
			class CommonMapFragment {};
			class UncommonMapFragment {};
			class RareMapFragment {};
			class LegendaryMapFragment {};
			class OldCoin {};
			class CoinBundle {};
			class BrokenPot {};
			class RestoredPot {};
			class BluntStoneKnife {};
			class SharpStoneKnife {};
			class FossilisedBone {};
			class UnidentifiedSkull {};
			class IdentifiedSkull {};
			class PetrifiedShield {};
			class WeatheredSculpture {};
			class AncientAmber {};
			class ReligiousTotem {};
			class StrongMetalRing {};
			class DiamondRing {};
			class EmeraldAmulet {};
			class AncientLedger {};
			class HandSmoothedRunestone {};
			class JeweledNecklace {};
			class BrokenTimepiece {};
			class RestoredTimepiece {};
		};
	};

	class Electronics {
		storeName = "Electronics Trader";
		class Items {
			class MiningRig {};
			class Desktop {};
			class Laptop {};
			class SignalJammer {};
		};
	};
};
