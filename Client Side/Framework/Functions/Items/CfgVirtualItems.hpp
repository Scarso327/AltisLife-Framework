class CfgVirtualItems {
	// Food & Drinks
	class FreshApple {
		displayName = "Fresh Apple";
		icon = "Data\Icons\apple.paa";
		buyPrice = -1;
		sellPrice = 51;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 40;
			thirst = 0;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};
	
	class Apple {
		displayName = "Apple";
		icon = "Data\Icons\apple.paa";
		buyPrice = 0;
		sellPrice = 51;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 30;
			thirst = 0;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class FreshPeach {
		displayName = "Fresh Peach";
		icon = "Data\Icons\peach.paa";
		buyPrice = -1;
		sellPrice = 51;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 40;
			thirst = 0;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Peach {
		displayName = "Peach";
		icon = "Data\Icons\peach.paa";
		buyPrice = 0;
		sellPrice = 51;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 30;
			thirst = 0;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Bacon {
		displayName = "Bacon";
		icon = "Data\Icons\bacon.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 50;
			thirst = 0;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Burger {
		displayName = "Burger";
		icon = "Data\Icons\burger.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 70;
			thirst = 0;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Hotdog {
		displayName = "Hotdog";
		icon = "Data\Icons\hotdog.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 60;
			thirst = 0;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Chips {
		displayName = "Chips";
		icon = "Data\Icons\chips.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 45;
			thirst = 0;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class RationPack {
		displayName = "Ration Pack";
		icon = "Data\Icons\rationPack.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 80;
			thirst = 0;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Doughnut {
		displayName = "Doughnut";
		icon = "Data\Icons\doughnut.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 20;
			thirst = 0;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Water {
		displayName = "Water";
		icon = "Data\Icons\bottle.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 0;
			thirst = 70;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Coffee {
		displayName = "Coffee";
		icon = "Data\Icons\coffee.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 0;
			thirst = 60;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Tea {
		displayName = "Tea";
		icon = "Data\Icons\tea.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 0;
			thirst = 60;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Redbull {
		displayName = "Redbull";
		icon = "Data\Icons\can.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 0;
			thirst = 50;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Beer {
		displayName = "Beer";
		icon = "Data\Icons\beer.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 0;
			thirst = 25;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Schnapps {
		displayName = "Schnapps";
		icon = "Data\Icons\Schnapps.paa";
		buyPrice = 580;
		sellPrice = 290;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 0;
			thirst = 30;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Gin {
		displayName = "Gin";
		icon = "Data\Icons\gin.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 0;
			thirst = 25;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	class Whiskey {
		displayName = "Whiskey";
		icon = "Data\Icons\whiskey.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		class Sustain {
			hunger = 0;
			thirst = 15;
		};
		class Events {
			onUse = "[(_this select 0)] call ULP_fnc_addSustenance;";
		};
		conditions = "true";
	};

	// General Items
	class StollenCargo {
		displayName = "StollenCargo";
		icon = "Data\Icons\stollenCargo.paa";
		buyPrice = -1;
		sellPrice = 98500;
		weight = 14;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
		};
		conditions = "true";
	};

	class Tobacco {
		displayName = "Tobacco";
		icon = "Data\Icons\tobacco.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class Cigarette {
		displayName = "Cigarette";
		icon = "Data\Icons\cigaretee.paa";
		buyPrice = 5700;
		sellPrice = 2850;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class Cigar {
		displayName = "Cigar";
		icon = "Data\Icons\cigar.paa";
		buyPrice = 6720;
		sellPrice = 3360;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class Coral {
		displayName = "Coral";
		icon = "Data\Icons\coral.paa";
		buyPrice = -1;
		sellPrice = 6700;
		weight = 7;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
		};
		conditions = "true";
	};

	class Pickaxe {
		displayName = "Pickaxe";
		icon = "Data\Icons\pickaxe.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class Shovel {
		displayName = "Shovel";
		icon = "Data\Icons\shovel.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class FishingNet {
		displayName = "Fishing Net";
		icon = "Data\Icons\fishingNet.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class FuelCan {
		displayName = "Fuel Can";
		icon = "Data\Icons\fuelCan.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class Breathalyser {
		displayName = "Breathalyser";
		icon = "Data\Icons\breathalyser.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class GPSTracker {
		displayName = "GPS Tracker";
		icon = "Data\Icons\gpsTracker.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class Ziptie {
		displayName = "Ziptie";
		icon = "Data\Icons\ziptie.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class Blindfold {
		displayName = "Blindfold";
		icon = "Data\Icons\blindfold.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class Stinger {
		displayName = "Stinger";
		icon = "Data\Icons\stringer.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class Lockpick {
		displayName = "Lockpick";
		icon = "Data\Icons\lockpick.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class BoltCutter {
		displayName = "Bolt Cutter";
		icon = "Data\Icons\boltCutter.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class HackingDevice {
		displayName = "Hacking Device";
		icon = "Data\Icons\hackingDevice.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class ExplosiveCharge {
		displayName = "Explosive Charge";
		icon = "Data\Icons\explosiveCharge.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class IndustrialDrill {
		displayName = "Industrial Drill";
		icon = "Data\Icons\industrialDrill.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class GalleryPiece {
		displayName = "Gallery Piece";
		icon = "Data\Icons\galleryPiece.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 7;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
		};
		conditions = "true";
	};

	// Medical Equipment
	class Painkillers {
		displayName = "Painkillers";
		icon = "Data\Icons\painkillers.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class Bandage {
		displayName = "Bandage";
		icon = "Data\Icons\bandage.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class BloodBag {
		displayName = "Blood Bag";
		icon = "Data\Icons\bloodbag.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class FirstAidKit {
		displayName = "First Aid Kit";
		icon = "Data\Icons\firstAidKit.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class MediKit {
		displayName = "MediKit";
		icon = "Data\Icons\mediKit.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	// Minerals
	class Coal {
		displayName = "Coal";
		icon = "Data\Icons\coal.paa";
		buyPrice = -1;
		sellPrice = 2400;
		weight = 4;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class CopperOre {
		displayName = "Copper Ore";
		icon = "Data\Icons\ore.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class CopperBar {
		displayName = "Copper Bar";
		icon = "Data\Icons\ingotUnmarked.paa";
		buyPrice = -1;
		sellPrice = 1900;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class SilverOre {
		displayName = "Silver Ore";
		icon = "Data\Icons\ore.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class SilverBar {
		displayName = "Silver Bar";
		icon = "Data\Icons\ingotUnmarked.paa";
		buyPrice = -1;
		sellPrice = 2200;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class IronOre {
		displayName = "Iron Ore";
		icon = "Data\Icons\ore.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class IronBar {
		displayName = "Iron Bar";
		icon = "Data\Icons\ingotUnmarked.paa";
		buyPrice = -1;
		sellPrice = 7350;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class UraniumOre {
		displayName = "Uranium Ore";
		icon = "Data\Icons\ore.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 8;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
		};
		conditions = "true";
	};

	class UraniumBar {
		displayName = "Uranium Bar";
		icon = "Data\Icons\ingotUnmarked.paa";
		buyPrice = -1;
		sellPrice = 28650;
		weight = 6;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class MakredGold {
		displayName = "Marked Gold";
		icon = "Data\Icons\ingotMarked.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 16;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
		};
		conditions = "true";
	};

	class UnmarkedGold {
		displayName = "Unmarked Gold";
		icon = "Data\Icons\ingotUnmarked.paa";
		buyPrice = -1;
		sellPrice = 700000;
		weight = 16;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
		};
		conditions = "true";
	};

	class Sand {
		displayName = "Sand";
		icon = "Data\Icons\sand.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class Glass {
		displayName = "Glass";
		icon = "Data\Icons\glass.paa";
		buyPrice = -1;
		sellPrice = 2450;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class UnrefinedSalt {
		displayName = "Unrefined Salt";
		icon = "Data\Icons\saltUnprocessed.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class RefindedSalt {
		displayName = "Refinded Salt";
		icon = "Data\Icons\saltProcessed.paa";
		buyPrice = -1;
		sellPrice = 3200;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class UncutDiamond {
		displayName = "Diamond Ore";
		icon = "Data\Icons\ore.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class CutDiamond {
		displayName = "Cut Diamond";
		icon = "Data\Icons\diamond.paa";
		buyPrice = -1;
		sellPrice = 6100;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class UnprocessedOil {
		displayName = "Unprocessed Oil";
		icon = "Data\Icons\oilUnprocessed.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 6;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class ProcessedOil {
		displayName = "Processed Oil";
		icon = "Data\Icons\oilProcessed.paa";
		buyPrice = -1;
		sellPrice = 9850;
		weight = 4;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	// Drugs
	class UnprocessedWeed {
		displayName = "Unprocessed Weed";
		icon = "Data\Icons\weedUnprocessed.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
		};
		conditions = "true";
	};

	class ProcessedWeed {
		displayName = "Processed Weed";
		icon = "Data\Icons\weedProcessed.paa";
		buyPrice = 6680;
		sellPrice = 3340;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class PurifiedWeed {
		displayName = "Purified Weed";
		icon = "Data\Icons\weedProcessed.paa";
		buyPrice = 8016;
		sellPrice = 4008;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class UnprocessedHeroin {
		displayName = "Opium";
		icon = "Data\Icons\heroinUnprocessed.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 5;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
		};
		conditions = "true";
	};

	class ProcessedHeroin {
		displayName = "Processed Heroin";
		icon = "Data\Icons\heroinProcessed.paa";
		buyPrice = 14160;
		sellPrice = 7080;
		weight = 4;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class PurifiedHeroin {
		displayName = "Purified Heroin";
		icon = "Data\Icons\heroinProcessed.paa";
		buyPrice = 16992;
		sellPrice = 8496;
		weight = 4;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class UnprocessedCocaine {
		displayName = "Coca Leaf";
		icon = "Data\Icons\cocaineUnprocessed.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 6;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
		};
		conditions = "true";
	};

	class ProcessedCocaine {
		displayName = "Processed Cocaine";
		icon = "Data\Icons\cocaineProcessed.paa";
		buyPrice = 22900;
		sellPrice = 11450;
		weight = 5;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class PurifiedCocaine {
		displayName = "Purified Cocaine";
		icon = "Data\Icons\cocaineProcessed.paa";
		buyPrice = 27480;
		sellPrice = 13740;
		weight = 5;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class EphedrineBarrel {
		displayName = "Ephedrine Barrel";
		icon = "Data\Icons\ephedrine.paa";
		buyPrice = 6050;
		sellPrice = -1;
		weight = 12;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
		};
		conditions = "true";
	};

	class ProcessedMeth {
		displayName = "Meth";
		icon = "Data\Icons\meth.paa";
		buyPrice = 61000;
		sellPrice = 30500;
		weight = 5;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class PurifiedMeth {
		displayName = "Purified Meth";
		icon = "Data\Icons\meth.paa";
		buyPrice = 73200;
		sellPrice = 36600;
		weight = 5;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class Corn {
		displayName = "Corn";
		icon = "Data\Icons\corn.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
		};
		conditions = "true";
	};

	class Moonshine {
		displayName = "Moonshine";
		icon = "Data\Icons\moonshine.paa";
		buyPrice = 13400;
		sellPrice = 6700;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class PurifiedMoonshine {
		displayName = "Purified Moonshine";
		icon = "Data\Icons\moonshine.paa";
		buyPrice = 16080;
		sellPrice = 8040;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	class Ecstasy {
		displayName = "Ecstasy";
		icon = "Data\Icons\ecstasy.paa";
		buyPrice = 10500;
		sellPrice = 5250;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};

	// Animals
	class RawSalema {
		displayName = "Raw Salema";
		icon = "Data\Icons\fishRaw.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class CookedSalema {
		displayName = "Cooked Salema";
		icon = "Data\Icons\fishCooked.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class RawOrnate {
		displayName = "Raw Ornate";
		icon = "Data\Icons\fishRaw.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class CookedOrnate {
		displayName = "Cooked Ornate";
		icon = "Data\Icons\fishCooked.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class RawTuna {
		displayName = "Raw Tuna";
		icon = "Data\Icons\fishRaw.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class CookedTuna {
		displayName = "Cooked Tuna";
		icon = "Data\Icons\fishCooked.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class RawMullet {
		displayName = "Raw Mullet";
		icon = "Data\Icons\fishRaw.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class CookedMullet {
		displayName = "Cooked Mullet";
		icon = "Data\Icons\fishCooked.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class RawCatshark {
		displayName = "Raw Catshark";
		icon = "Data\Icons\fishRaw.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = false;
		};
		conditions = "true";
	};

	class CookedCatshark {
		displayName = "Cooked Catshark";
		icon = "Data\Icons\fishCooked.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
		};
		conditions = "true";
	};

	class Turtle {
		displayName = "Turtle";
		icon = "Data\Icons\turtle.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
		};
		conditions = "true";
	};
};