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
			class Ziptie { 
				buyPrice = -1;
				sellPrice = 1688; 
			};
			class Blindfold { 
				buyPrice = -1;
				sellPrice = 2125; 
			};
			class Lockpick { 
				buyPrice = -1;
				sellPrice = 313; 
			};
			class SnapGun { 
				buyPrice = -1;
				sellPrice = 7500; 
			};
			class BoltCutter { 
				buyPrice = -1;
				sellPrice = 43125; 
			};
			class HackingDevice { 
				buyPrice = -1;
				sellPrice = 59375; 
			};
			class ExplosiveCharge { 
				buyPrice = -1;
				sellPrice = 93750; 
			};
			class IndustrialDrill { 
				buyPrice = -1;
				sellPrice = 75000; 
			};

			// Runs
			class Turtle_F_Raw { 
				buyPrice = -1;
				sellPrice = 8906; 
			};
			class Coral { 
				buyPrice = -1;
				sellPrice = 2094; 
			};
			class UnprocessedWeed { sellPrice = 743; };
			class UnprocessedHeroin { sellPrice = 1185; };
			class UnprocessedCocaine { sellPrice = 1931; };
			class ProcessedWeed { 
				buyPrice = -1;
				sellPrice = 1856; 
			};
			class ProcessedHeroin { 
				buyPrice = -1;
				sellPrice = 2963; 
			};
			class ProcessedCocaine { 
				buyPrice = -1;
				sellPrice = 4828; 
			};
			class ProcessedMeth { 
				buyPrice = -1;
				sellPrice = 9531; 
			};
			class Ecstasy { 
				buyPrice = -1;
				sellPrice = 1641; 
			};
			class PurifiedWeed { 
				buyPrice = -1;
				sellPrice = 2409; 
			};
			class PurifiedHeroin { 
				buyPrice = -1;
				sellPrice = 4237; 
			};
			class PurifiedCocaine { 
				buyPrice = -1;
				sellPrice = 6330; 
			};
			class PurifiedMeth { 
				buyPrice = -1;
				sellPrice = 13117; 
			};
			class UncutBloodDiamond { sellPrice = 1781; };
			class CutBloodDiamond { 
				buyPrice = -1;
				sellPrice = 2969; 
			};
			class EphedrineBarrel { 
				buyPrice = -1;
				sellPrice = 3050; 
			};
			class UraniumOre { sellPrice = 2769; };
			class UraniumBar { 
				buyPrice = -1;
				sellPrice = 6922; 
			};
			class WeaponParts { 
				buyPrice = -1;
				sellPrice = 7338; 
			};
			class WeaponCrate { 
				buyPrice = -1;
				sellPrice = 18344; 
			};

			// Majors
			class MarkedGold { sellPrice = 31250; }; // 10%
			class UnmarkedGold { sellPrice = 43750; }; // 5%
			class EncryptedDrive { sellPrice = 0; };
			class DecryptedDrive { sellPrice = 0; };
			class SpaceCapsuleDataDrive { sellPrice = 0; };
			class SeizedContraband { sellPrice = 0; };
			class LargeGalleryPiece { sellPrice = 0; };
			class MediumGalleryPiece { sellPrice = 0; };
			class SmallGalleryPiece { sellPrice = 0; };
		};
	};

	class PoliceTradeGoods {
		storeName = "Trade Goods";
		conditions = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 5] call ULP_fnc_hasAccess }";
		class Items {
			class FreshApple {
				buyPrice = 56;
				sellPrice = 56; 
			};
			class FreshPeach {
				buyPrice = 64;
				sellPrice = 64; 
			};
			class Cigarette { 
				buyPrice = 3563;
				sellPrice = 3563; 
			};
			class Cigar { 
				buyPrice = 3360;
				sellPrice = 3360; 
			};
			class CopperBar { 
				buyPrice = 2375;
				sellPrice = 2375; 
			};
			class SilverBar { 
				buyPrice = 2750;
				sellPrice = 2750; 
			};
			class IronBar { 
				buyPrice = 9188;
				sellPrice = 9188; 
			};
			class Glass { 
				buyPrice = 3188;
				sellPrice = 3188; 
			};
			class RefinedSalt { 
				buyPrice = 4000;
				sellPrice = 4000; 
			};
			class ProcessedOil { 
				buyPrice = 41063;
				sellPrice = 41063; 
			};
			class CutDiamond { 
				buyPrice = 8125;
				sellPrice = 8125; 
			};
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
			class FieldDressing { buyPrice = 0; };
			class Elastic { buyPrice = 0; };
			class Packing { buyPrice = 0; };
			class QuickClot { buyPrice = 0; };
			class BloodBag { buyPrice = 0; };
			class MediKit { buyPrice = 0; };
			class Defibrillator { buyPrice = 0; };
			class Stretcher { buyPrice = 0; };
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
			class Lockpick { buyPrice = 0; };
			class VehicleClamp { buyPrice = 0; };
			class FieldDressing {};
			class BloodBag {};
			class MediKit {};
			class Defibrillator {};
		};
	};

	class Placeables {
		storeName = "Placeables Store";
		conditions = "[player, [""Police""]] call ULP_fnc_isFaction || { [player, [""Medic""]] call ULP_fnc_isFaction } || { [player, [""Hato""]] call ULP_fnc_isFaction } || { [] call ULP_fnc_isDunamis }";
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
			class MediKit {};
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
			class MediKit {};
		};
	};

	class GangWars : Blackmarket {
		storeName = "Gang Wars Market";
		conditions = "[""Rebel""] call ULP_fnc_hasLicense && { missionNamespace getVariable [""ULP_SRV_Setting_BaseBidsActive"", false] }";
		class Items {
			class RationPack {};
			class Water {};
			class Redbull {};
			class Lockpick {};
			class FirstAidKit {};
			class MediKit {};
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
			class MediKit {};
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
			class Ecstasy {};
		};
	};

	class Weapons {
		storeName = "Weapons Dealer";
		conditions = "true";
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
