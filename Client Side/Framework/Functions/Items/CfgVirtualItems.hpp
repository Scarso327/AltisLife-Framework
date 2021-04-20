class CfgVirtualItems {
	// Fresh Food
	class FreshApple {
		displayName = "Fresh Apples";
		description = "Fresh fruit picked from local trees and sold at markets.";
		icon = "Data\Icons\freshApples.paa";
		buyPrice = -1;
		sellPrice = 45;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		class Sustain {
			hunger = 40;
			thirst = 0;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class FreshPeach : FreshApple {
		displayName = "Fresh Peaches";
		icon = "Data\Icons\freshPeaches.paa";
		sellPrice = 51;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	
	// Regular Food
	class Apple {
		displayName = "Bought Apple";
		description = "A regular piece of fruit bought at a general market.";
		icon = "Data\Icons\apple.paa";
		buyPrice = 90;
		sellPrice = 45;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		class Sustain {
			hunger = 30;
			thirst = 0;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Peach : Apple {
		displayName = "Bought Peach";
		icon = "Data\Icons\peach.paa";
		buyPrice = 102;
		sellPrice = 51;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	class Bacon : Apple {
		displayName = "Bacon";
		description = "Regular food bought at various points around Altis.";
		icon = "Data\Icons\bacon.paa";
		buyPrice = 130;
		sellPrice = 65;
		class Settings : Settings {};
		class Sustain {
			hunger = 50;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Burger : Bacon {
		displayName = "Burger";
		icon = "Data\Icons\burger.paa";
		buyPrice = 165;
		sellPrice = 83;
		class Settings : Settings {};
		class Sustain {
			hunger = 70;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Hotdog : Bacon {
		displayName = "Hotdog";
		icon = "Data\Icons\hotdog.paa";
		buyPrice = 140;
		sellPrice = 70;
		class Settings : Settings {};
		class Sustain {
			hunger = 60;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Chips : Bacon {
		displayName = "Chips";
		icon = "Data\Icons\chips.paa";
		buyPrice = 105;
		sellPrice = 53;
		class Settings : Settings {};
		class Sustain {
			hunger = 45;
			thirst = 0;
		};
		class Events : Events {};
	};
	class RationPack : Bacon {
		displayName = "Ration Pack";
		icon = "Data\Icons\rationPack.paa";
		buyPrice = 325;
		sellPrice = 162;
		class Settings : Settings {};
		class Sustain {
			hunger = 80;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Doughnut : Bacon {
		displayName = "Doughnut";
		icon = "Data\Icons\doughnut.paa";
		buyPrice = 20;
		sellPrice = 10;
		class Settings : Settings {};
		class Sustain {
			hunger = 20;
			thirst = 0;
		};
		class Events : Events {};
	};

	// Regular Drinks
	class Water {
		displayName = "Water";
		description = "A regular drink used to keep you hydrated.";
		icon = "Data\Icons\bottle.paa";
		buyPrice = 10;
		sellPrice = 5;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 70;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Coffee : Water {
		displayName = "Coffee";
		icon = "Data\Icons\coffee.paa";
		buyPrice = 35;
		sellPrice = 18;
		class Settings : Settings {};
		class Sustain {
			hunger = 0;
			thirst = 60;
		};
		class Events : Events {};
	};
	class Tea : Coffee {
		displayName = "Tea";
		icon = "Data\Icons\tea.paa";
		buyPrice = 30;
		sellPrice = 15;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};

	// Energy Drinks
	class Redbull {
		displayName = "Redbull";
		description = "An energy drink designed to give a person faster reactions.";
		icon = "Data\Icons\can.paa";
		buyPrice = 2100;
		sellPrice = 1050;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 50;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};

	// Alcoholic Drinks
	class Beer {
		displayName = "Beer";
		description = "An alcoholic drink that causes uncomfortable side effects.";
		icon = "Data\Icons\beer.paa";
		buyPrice = 290;
		sellPrice = 145;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 25;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Schnapps : Beer {
		displayName = "Schnapps";
		icon = "Data\Icons\schnapps.paa";
		buyPrice = 580;
		sellPrice = 290;
		class Settings : Settings {};
		class Sustain {
			hunger = 0;
			thirst = 30;
		};
		class Events : Events {};
		conditions = "true";
	};
	class Gin : Beer {
		displayName = "Gin";
		icon = "Data\Icons\gin.paa";
		buyPrice = 375;
		sellPrice = 188;
		class Settings : Settings {};
		class Sustain {
			hunger = 0;
			thirst = 25;
		};
		class Events : Events {};
	};
	class Whiskey : Beer {
		displayName = "Whiskey";
		icon = "Data\Icons\whiskey.paa";
		buyPrice = 495;
		sellPrice = 248;
		class Settings : Settings {};
		class Sustain {
			hunger = 0;
			thirst = 15;
		};
		class Events : Events {};
	};

	// XP Rewards
	class TinyXPReward {
		displayName = "Tiny XP Reward";
		description = "A bottle that, when used, will provide valuable experience.";
		icon = "Data\Icons\xpReward.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [100, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
		conditions = "true";
	};
	class SmallXPReward : TinyXPReward {
		displayName = "Small XP Reward";
		icon = "Data\Icons\xpReward.paa";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [500, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class MediumXPReward : TinyXPReward {
		displayName = "Medium XP Reward";
		icon = "Data\Icons\xpReward.paa";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [1000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class LargeXPReward : TinyXPReward {
		displayName = "Large XP Reward";
		icon = "Data\Icons\xpReward.paa";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [5000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class HugeXPReward : TinyXPReward {
		displayName = "Huge XP Reward";
		icon = "Data\Icons\xpReward.paa";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [10000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};

	// General Items
	class Identification {
		displayName = "%1's ID";
		description = "A card containing a person's identifity. However, these are easily forged.";
		icon = "Data\Icons\identification.paa";
		buyPrice = 75000;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = true;
		};
		class Events {
			onUse = "_this call ULP_fnc_disguiseIdentity;";
			onRemove = "if ((player getVariable [""name"", """"]) isEqualTo (_this select 1)) then { player setVariable [""name"", nil, true]; [""You've lost the ID card you were disguising yourself with!""] call ULP_fnc_hint; };";
		};
		conditions = "true";
	};

	class Pickaxe {
		displayName = "Pickaxe";
		description = "A simple tool used for harvesting minerals.";
		icon = "Data\Icons\pickaxe.paa";
		buyPrice = 1200;
		sellPrice = 600;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		class Deconstruction {
			time = 20;
			workbench = false;
			blueprints[] = { { "Tools", "B_Pickaxe" } };
			materials[] = { {"IronBar", 1}, {"Wood", 1} };
		};
		conditions = "true";
	};
	class LumberAxe : Pickaxe {
		displayName = "Lumber Axe";
		icon = "Data\Icons\lumberAxe.paa";
		buyPrice = 1180;
		sellPrice = 590;
		class Settings : Settings {};
		class Deconstruction {
			time = 20;
			workbench = false;
			blueprints[] = { { "Tools", "B_LuberAxe" } };
			materials[] = { {"IronBar", 1}, {"Wood", 1} };
		};
	};
	class Shovel : Pickaxe {
		displayName = "Shovel";
		icon = "Data\Icons\shovel.paa";
		buyPrice = 1100;
		sellPrice = 550;
		class Settings : Settings {};
		class Deconstruction {
			time = 20;
			workbench = false;
			blueprints[] = { { "Tools", "B_Shovel" } };
			materials[] = { {"Wood", 1} };
		};
	};
	class Extractor : Pickaxe {
		displayName = "Extractor";
		icon = "Data\Icons\extractor.paa";
		buyPrice = 1950;
		sellPrice = 975;
		class Settings : Settings {};
		class Deconstruction {
			time = 20;
			workbench = false;
			blueprints[] = { { "Tools", "B_Extractor" } };
			materials[] = { {"IronBar", 2}, {"SilverBar", 1} };
		};
	};
	class FishingNet : Pickaxe {
		displayName = "Fishing Net";
		description = "A net designed to be deployed from a boat and catch fish.";
		icon = "Data\Icons\fishingNet.paa";
		buyPrice = 750;
		sellPrice = 375;
		class Settings : Settings {};
		class Deconstruction {
			time = 30;
			workbench = false;
			blueprints[] = { { "Tools", "B_FishingNet" } };
			materials[] = { {"Rope", 2} };
		};
	};
	class FuelCan : Pickaxe {
		displayName = "Fuel Can";
		description = "This can be used to refuel your vehicle anywhere.";
		icon = "Data\Icons\fuelCan.paa";
		buyPrice = 3000;
		sellPrice = 1500;
		weight = 3;
		class Settings : Settings {};
		class Deconstruction {
			time = 30;
			workbench = false;
			blueprints[] = { { "Tools", "B_FuelCan" } };
			materials[] = { {"IronBar", 3} };
		};
	};
	class Breathalyser : Pickaxe { // TODO
		displayName = "Breathalyser";
		description = "Used to determin whether or not someone is under the influence.";
		icon = "Data\Icons\breathalyser.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 1;
		class Settings : Settings {};
	};
	class PanicButton : Pickaxe {
		displayName = "Panic Button";
		description = "When pressed this will alert the police that you require immedate assistance.";
		icon = "Data\Icons\panicButton.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 0;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_panic;"; };
	};
	class Ziptie : Pickaxe {
		displayName = "Ziptie";
		description = "A tool used to retain others.";
		icon = "Data\Icons\ziptie.paa";
		buyPrice = 13500;
		sellPrice = 6750;
		weight = 1;
		class Settings : Settings {};
	};
	class Blindfold : Pickaxe { // TODO
		displayName = "Blindfold";
		description = "A tool used to blindfold others.";
		icon = "Data\Icons\blindfold.paa";
		buyPrice = 17000;
		sellPrice = 8500;
		weight = 1;
		class Settings : Settings {};
		conditions = "[""Civilian""]] call ULP_fnc_isFaction || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
	};
	class Stinger { // TODONOW
		displayName = "Stinger";
		description = "A deployable strip of spikes used to puncute a vehicle's tryes.";
		icon = "Data\Icons\stinger.paa";
		buyPrice = 33400;
		sellPrice = 16700;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
		};
		class Deconstruction {
			time = 30;
			workbench = true;
			blueprints[] = { { "Tools", "B_MakeshiftStinger" } };
			materials[] = { {"SteelBar", 22} };
		};
		conditions = "true";
	};
	class MakeshiftStinger : Stinger {
		displayName = "Makeshift Stinger";
		class Settings : Settings {};
	};
	class VehicleClamp : Stinger {
		displayName = "Vehicle Clamp";
		description = "A deployable clamp used to prevent a vehicle's movement.";
		icon = "Data\Icons\vehicleClamp.paa";
		buyPrice = 18200;
		sellPrice = 9700;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_clampVehicle;"; };
	};
	class Lighter : Stinger {
		displayName = "Lighter";
		description = "A simple lighter used to create fire.";
		icon = "Data\Icons\lighter.paa";
		buyPrice = 890;
		sellPrice = 445;
		weight = 1;
		class Settings : Settings {};
		class Deconstruction {
			time = 10;
			workbench = false;
			blueprints[] = { { "Tools", "B_Lighter" } };
			materials[] = { {"Iron", 1} };
		};
	};
	class Lockpick : Stinger {
		displayName = "Lockpick";
		description = "A tool used to pick the locks of vehicles and handcuffs.";
		icon = "Data\Icons\lockpick.paa";
		buyPrice = 2500;
		sellPrice = 1250;
		weight = 1;
		class Settings : Settings {};
		class Deconstruction {
			time = 10;
			workbench = false;
			blueprints[] = { { "Tools", "B_Lockpick" } };
			materials[] = { {"Iron", 2} };
		};
	};
	class BoltCutter : Stinger {
		displayName = "Bolt Cutter";
		description = "A tool used to cut strong locks found on properties, airdrops and strong doors.";
		icon = "Data\Icons\boltCutter.paa";
		buyPrice = 345000;
		sellPrice = 172500;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_boltcut;"; };
		class Deconstruction {
			time = 40;
			workbench = false;
			blueprints[] = { { "Tools", "B_BoltCutter" } };
			materials[] = { {"Iron", 8} };
		};
	};
	class HackingDevice : Stinger {
		displayName = "Hacking Device";
		description = "A tool used to hack various systems and malicously gain access to said systems.";
		icon = "Data\Icons\hackingDevice.paa";
		buyPrice = 475000;
		sellPrice = 237500;
		weight = 3;
		class Settings : Settings {};
		class Deconstruction {
			time = 120;
			workbench = true;
			blueprints[] = { { "Tools", "B_HackingDevice" } };
			materials[] = { {"Silver", 4}, {"CutDiamond", 2} };
		};
	};
	class ExplosiveCharge : Stinger {
		displayName = "Explosive Charge";
		description = "A tool used to destroy fortified locks.";
		icon = "Data\Icons\explosiveCharge.paa";
		buyPrice = 750000;
		sellPrice = 375000;
		weight = 4;
		class Settings : Settings {};
		class Deconstruction {
			time = 180;
			workbench = true;
			blueprints[] = { { "Tools", "B_ExplosiveCharge" } };
			materials[] = { {"ExplosiveMaterials", 4}, {"Coal", 7}, {"CutDiamond", 3} };
		};
	};
	class IndustrialDrill : ExplosiveCharge {
		displayName = "Industrial Drill";
		icon = "Data\Icons\industrialDrill.paa";
		buyPrice = 600000;
		sellPrice = 300000;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_drill;"; };
		class Deconstruction {
			time = 180;
			workbench = true;
			blueprints[] = { { "Tools", "B_IndustrialDrill" } };
			materials[] = { {"IronBar", 8}, {"CutDiamond", 2} };
		};
	};
	class Toolbox : Stinger {
		displayName = "Toolbox";
		description = "A box of tools used to deconstruct items into their core components.";
		icon = "Data\Icons\toolbox.paa";
		buyPrice = 25000;
		sellPrice = 12500;
		weight = 8;
		class Settings : Settings {};
	};

	// Medical Equipment
	class Painkillers { // TODO (Will give health immedately after use)
		displayName = "Painkillers";
		description = "Two pills that restore a small amount of health.";
		icon = "Data\Icons\painkillers.paa";
		buyPrice = 6000;
		sellPrice = 3000;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		conditions = "true";
	};
	class Bandage : Painkillers { // TODO (Will give health after a VERY qucik progress)
		displayName = "Bandage";
		description = "Used to quickly heal minor wounds.";
		icon = "Data\Icons\bandage.paa";
		buyPrice = 8500;
		sellPrice = 4250;
		class Settings : Settings {};
	};
	class BloodBag : Painkillers {
		displayName = "Blood Bag";
		description = "Used to prevent an incapacitated person from bleeding out.";
		icon = "Data\Icons\bloodbag.paa";
		buyPrice = 10000;
		sellPrice = 5000;
		class Settings : Settings {};
	};
	class FirstAidKit : Painkillers {
		displayName = "First Aid Kit";
		description = "A kit containing various medical tools that can provide assistance.";
		icon = "Data\Icons\firstAidKit.paa";
		buyPrice = 15000;
		sellPrice = 7500;
		class Settings : Settings {};
	};
	class MediKit : FirstAidKit {
		displayName = "MediKit";
		icon = "Data\Icons\mediKit.paa";
		buyPrice = 180000;
		sellPrice = 90000;
		weight = 2;
		class Settings : Settings {};
	};

	// Placeable Items
	class TapeSign_F { 
		displayName = "Red-White Tape";
		description = "A bundled up item ready to be placed.";
		icon = "Data\Icons\roadBarrier.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		conditions = "true";
	};
	class PlasticBarrier_02_yellow_F : TapeSign_F { 
		displayName = "Plastic Barrier (Medium, Yellow)";
		buyPrice = 0;
		sellPrice = 0;
		weight = 3;
		class Settings : Settings {};
	};
	class PlasticBarrier_02_grey_F : PlasticBarrier_02_yellow_F { 
		displayName = "Plastic Barrier (Medium, Gray)";
		class Settings : Settings {};
	};
	class PlasticBarrier_03_orange_F : TapeSign_F { 
		displayName = "Plastic Barrier (Large, Orange)";
		buyPrice = 0;
		sellPrice = 0;
		weight = 4;
		class Settings : Settings {};
	};
	class PlasticBarrier_03_blue_F : PlasticBarrier_03_orange_F { 
		displayName = "Plastic Barrier (Large, Blue)";
		class Settings : Settings {};
	};
	class RoadBarrier_small_F : TapeSign_F { 
		displayName = "Road Barrier (Small)";
		buyPrice = 0;
		sellPrice = 0;
		weight = 3;
		class Settings : Settings {};
	};
	class RoadBarrier_F : TapeSign_F { 
		displayName = "Road Barrier (Large)";
		buyPrice = 0;
		sellPrice = 0;
		weight = 5;
		class Settings : Settings {};
	};
	class Land_ConcreteHedgehog_01_F : TapeSign_F { 
		displayName = "Create Hedgehog";
		icon = "Data\Icons\hedgehog.paa";
		buyPrice = 0;
		sellPrice = 0;
		weight = 6;
		class Settings : Settings {};
	};
	class Land_PortableLight_single_F : TapeSign_F { 
		displayName = "Portable Light (Single)";
		icon = "Data\Icons\portableLight.paa";
		buyPrice = 0;
		sellPrice = 0;
		class Settings : Settings {};
	};
	class Land_PortableLight_double_F : Land_PortableLight_single_F { 
		displayName = "Portable Light (Double)";
		buyPrice = 0;
		sellPrice = 0;
		class Settings : Settings {};
	};
	class TargetP_Inf4_F : TapeSign_F { 
		displayName = "Pop-Up Target (Hostile)";
		icon = "Data\Icons\popupTarget.paa";
		buyPrice = 0;
		sellPrice = 0;
		class Settings : Settings {};
	};
	class TargetP_Civ_F : TargetP_Inf4_F { 
		displayName = "Pop-Up Target (Friendly)";
		class Settings : Settings {};
	};
	class TargetP_Civ3_F : TargetP_Inf4_F { 
		displayName = "Pop-Up Target (Hostage)";
		class Settings : Settings {};
	};

	// Misc. Run Items
	class StolenCargo {
		displayName = "Stolen Cargo";
		description = "Sealed cargo crates filled with stolen goods.";
		icon = "Data\Icons\crate.paa";
		buyPrice = -1;
		sellPrice = 98500;
		weight = 14;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
		};
		conditions = "true";
	};
	class SeizedContraband : StolenCargo {
		displayName = "Seized Contraband";
		description = "Contraband seized by the Police and stored in Evidence Storage.";
		icon = "Data\Icons\seizedContraband.paa";
		sellPrice = 237600;
		weight = 4;
		class Settings : Settings {};
	};
	class SmallGalleryPiece : StolenCargo {
		displayName = "Small Gallery Piece";
		description = "A piece of art commonly stored in the Altis Gallery.";
		icon = "Data\Icons\galleryPiece.paa";
		sellPrice = 365000;
		weight = 6;
		class Settings : Settings {};
	};
	class MediumGalleryPiece : SmallGalleryPiece {
		displayName = "Medium Gallery Piece";
		icon = "Data\Icons\galleryPiece.paa";
		sellPrice = 496000;
		weight = 9;
		class Settings : Settings {};
	};
	class LargeGalleryPiece : SmallGalleryPiece {
		displayName = "Large Gallery Piece";
		icon = "Data\Icons\galleryPiece.paa";
		sellPrice = 732500;
		weight = 13;
		class Settings : Settings {};
	};
	class MarkedGold : StolenCargo {
		displayName = "Marked Gold";
		description = "A marked gold bar that is commonly stored in the HM Treasury.";
		icon = "Data\Icons\ingot.paa";
		sellPrice = 250000;
		weight = 16;
		class Settings : Settings {};
	};
	class UnmarkedGold : MarkedGold {
		displayName = "Unmarked Gold";
		description = "An marked gold bar that has been debranded by a Goldsmith.";
		sellPrice = 700000;
		class Settings : Settings {};
	};
	class EncryptedDrive : StolenCargo {
		displayName = "Encrypted Drive";
		description = "An encrypted drive containing secrect files taken from the HMS Liberty's command deck.";
		icon = "Data\Icons\drive.paa";
		sellPrice = 400000;
		weight = 8;
		class Settings : Settings {};
	};
	class DecryptedDrive : EncryptedDrive {
		displayName = "Decrypted Drive";
		description = "An Decrypted drive containing secrect files taken from the HMS Liberty's command deck.";
		icon = "Data\Icons\drive.paa";
		sellPrice = 1000000;
		class Settings : Settings {};
	};

	// Legal Unprocessed
	class Tobacco {
		displayName = "Tobacco";
		description = "A common leaf that can be processed into cigarettes or cigars.";
		icon = "Data\Icons\tobacco.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
			isScripted = false;
		};
		conditions = "true";
	};
	class Clay : Tobacco {
		displayName = "Clay";
		description = "A simple material used for crafting.";
		icon = "Data\Icons\clay.paa";
		weight = 1;
		class Settings : Settings {};
	};
	class Wood : Tobacco {
		displayName = "Wood";
		description = "A simple piece of wood commonly found in crafting recipies.";
		icon = "Data\Icons\wood.paa";
		sellPrice = 6;
		weight = 2;
		class Settings : Settings {};
	};
	class Rope : Tobacco {
		displayName = "Rope";
		description = "A simple piece of rope commonly found in crafting recipies.";
		icon = "Data\Icons\rope.paa";
		weight = 1;
		class Settings : Settings {};
	};
	class DrillBit : Tobacco {
		displayName = "Drill Bit";
		description = "A strong drill bit commonly found in crafting recipies.";
		icon = "Data\Icons\drillBit.paa";
		weight = 1;
		class Settings : Settings {};
	};
	class Rock : Tobacco {
		displayName = "Rock";
		description = "A simple rock commonly gathered from the HMP Yard.";
		icon = "Data\Icons\ore.paa";
		sellPrice = 3;
		weight = 3;
		class Settings : Settings {};
		conditions = "ULP_Imprisioned";
	};
	class CopperOre : Tobacco {
		displayName = "Copper Ore";
		description = "Ore collected from a mineral mine.";
		icon = "Data\Icons\ore.paa";
		weight = 3;
		class Settings : Settings {};
	};
	class SilverOre : CopperOre {
		displayName = "Silver Ore";
		icon = "Data\Icons\ore.paa";
		class Settings : Settings {};
	};
	class IronOre : CopperOre {
		displayName = "Iron Ore";
		icon = "Data\Icons\ore.paa";
		class Settings : Settings {};
	};
	class Sand : Tobacco {
		displayName = "Sand";
		description = "Grains of sand that can be processed into glass.";
		icon = "Data\Icons\sand.paa";
		weight = 2;
		class Settings : Settings {};
	};
	class UnrefinedSalt : Tobacco {
		displayName = "Unrefined Salt";
		description = "Salt gathered from the salt flats.";
		icon = "Data\Icons\saltUnrefined.paa";
		weight = 3;
		class Settings : Settings {};
	};
	class UnprocessedOil : Tobacco {
		displayName = "Unrefinded Oil";
		description = "Unrefinded oil extracted from an oil well.";
		icon = "Data\Icons\oilUnrefinded.paa";
		weight = 6;
		class Settings : Settings {};
	};
	class UncutDiamond : CopperOre {
		displayName = "Diamond Ore";
		icon = "Data\Icons\ore.paa";
		class Settings : Settings {};
	};

	// Legal Processed
	class Cigarette {
		displayName = "Cigarette";
		description = "A roll of tobacco that can be sold or smoked.";
		icon = "Data\Icons\cigarette.paa";
		buyPrice = 5700;
		sellPrice = 2850;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		conditions = "true";
	};
	class Cigar : Cigarette {
		displayName = "Cigar";
		icon = "Data\Icons\cigar.paa";
		buyPrice = 6720;
		sellPrice = 3360;
		class Settings : Settings {};
	};
	class Coal : Cigarette {
		displayName = "Coal";
		description = "A simple lump of coal that can be sold at the Coal Plant.";
		icon = "Data\Icons\ore.paa";
		buyPrice = -1;
		sellPrice = 2400;
		weight = 4;
		class Settings : Settings {};
	};
	class CopperBar : Cigarette {
		displayName = "Copper Bar";
		description = "A processed metal bar.";
		icon = "Data\Icons\ingot.paa";
		sellPrice = 1900;
		weight = 2;
		class Settings : Settings {};
	};
	class SilverBar : CopperBar {
		displayName = "Silver Bar";
		sellPrice = 2200;
		class Settings : Settings {};
	};
	class IronBar : CopperBar {
		displayName = "Iron Bar";
		sellPrice = 7350;
		weight = 3;
		class Settings : Settings {};
	};
	class SteelBar : CopperBar {
		displayName = "Steel Bar";
		sellPrice = 9670;
		class Settings : Settings {};
	};
	class Glass : CopperBar {
		displayName = "Glass";
		description = "Strong glass that is ready to be sold.";
		icon = "Data\Icons\glass.paa";
		sellPrice = 2450;
		weight = 1;
		class Settings : Settings {};
	};
	class RefindedSalt : CopperBar {
		displayName = "Refinded Salt";
		description = "Refinded salt that is ready to be sold.";
		icon = "Data\Icons\saltRefined.paa";
		sellPrice = 3200;
		class Settings : Settings {};
	};
	class ProcessedOil : CopperBar {
		displayName = "Refinded Oil";
		description = "Refinded oil that remains completely flammable.";
		icon = "Data\Icons\oilRefinded.paa";
		sellPrice = 9850;
		weight = 4;
		class Settings : Settings {};
	};
	class CutDiamond : CopperBar {
		displayName = "Cut Diamond";
		description = "A finely cut diamond that women appear to love.";
		icon = "Data\Icons\diamond.paa";
		sellPrice = 6100;
		class Settings : Settings {};
	};

	// Illegal Unprocessed
	class UraniumOre : CopperOre {
		displayName = "Uranium Ore";
		icon = "Data\Icons\ore.paa";
		weight = 8;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
		};
	};
	class ExplosiveMaterials : UraniumOre {
		displayName = "Explosive Materials";
		description = "A collection of explosive materials that are commonly found in crafting recipies.";
		icon = "Data\Icons\explosiveMaterials.paa";
		weight = 3;
		class Settings : Settings {};
		class Deconstruction {
			time = 180;
			workbench = true;
			blueprints[] = { { "CraftingMaterials", "B_ExplosiveMaterials" } };
			materials[] = { {"IronBar", 32}, {"ProcessedOil", 9} };
		};
	};
	class Corn : UraniumOre {
		displayName = "Corn";
		description = "An item that remain illegal due to the popularity of moonshine.";
		icon = "Data\Icons\corn.paa";
		weight = 2;
		class Settings : Settings {};
	};
	class EphedrineBarrel : CopperOre {
		displayName = "Ephedrine Barrel";
		description = "The base material in making crystal meth.";
		icon = "Data\Icons\methUnprocessed.paa";
		buyPrice = 6050;
		weight = 12;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
		};
	};
	class UnprocessedWeed : UraniumOre {
		displayName = "Unprocessed Weed";
		description = "A drug useless until processed.";
		icon = "Data\Icons\weedUnprocessed.paa";
		weight = 4;
		class Settings : Settings {};
	};
	class UnprocessedHeroin : UnprocessedWeed {
		displayName = "Opium";
		icon = "Data\Icons\heroinUnprocessed.paa";
		weight = 5;
		class Settings : Settings {};
	};
	class UnprocessedCocaine : UnprocessedHeroin {
		displayName = "Coca Leaf";
		icon = "Data\Icons\cocaineUnprocessed.paa";
		weight = 6;
		class Settings : Settings {};
	};

	// Illegal Processed
	class Coral {
		displayName = "Coral";
		description = "Coral gathered from the coral reef near Kavala.";
		icon = "Data\Icons\coral.paa";
		buyPrice = -1;
		sellPrice = 6700;
		weight = 7;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
		};
		conditions = "true";
	};
	class ProcessedWeed : Coral {
		displayName = "Processed Weed";
		description = "Processed drugs that can be used or sold/bought at a drug dealer.";
		icon = "Data\Icons\weedProcessed.paa";
		buyPrice = 6680;
		sellPrice = 3340;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
		};
	};
	class ProcessedHeroin : ProcessedWeed {
		displayName = "Processed Heroin";
		icon = "Data\Icons\heroinProcessed.paa";
		buyPrice = 14160;
		sellPrice = 7080;
		weight = 4;
		class Settings : Settings {};
	};
	class ProcessedCocaine : ProcessedWeed {
		displayName = "Processed Cocaine";
		icon = "Data\Icons\cocaineProcessed.paa";
		buyPrice = 22900;
		sellPrice = 11450;
		weight = 5;
		class Settings : Settings {};
	};
	class ProcessedMeth : ProcessedWeed {
		displayName = "Meth";
		icon = "Data\Icons\methProcessed.paa";
		buyPrice = 61000;
		sellPrice = 30500;
		weight = 5;
		class Settings : Settings {};
	};
	class Moonshine : ProcessedWeed {
		displayName = "Moonshine";
		icon = "Data\Icons\moonshine.paa";
		buyPrice = 13400;
		sellPrice = 6700;
		weight = 1;
		class Settings : Settings {};
	};
	class Ecstasy : ProcessedWeed {
		displayName = "Ecstasy";
		icon = "Data\Icons\ecstasy.paa";
		buyPrice = 10500;
		sellPrice = 5250;
		weight = 1;
		class Settings : Settings {};
	};
	class UraniumBar : ProcessedWeed {
		displayName = "Uranium Bar";
		description = "An extremely dangeous mineral processed from a radiation zone.";
		icon = "Data\Icons\ingot.paa";
		buyPrice = -1;
		sellPrice = 28650;
		weight = 6;
		class Settings : Settings {};
	};

	// Illegal Purified
	class PurifiedWeed {
		displayName = "Purified Weed";
		description = "The highest quaility drugs on Altis made for an increased profit.";
		icon = "Data\Icons\weedProcessed.paa";
		buyPrice = 8016;
		sellPrice = 4008;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
		};
		conditions = "true";
	};
	class PurifiedHeroin : PurifiedWeed {
		displayName = "Purified Heroin";
		icon = "Data\Icons\heroinProcessed.paa";
		buyPrice = 16992;
		sellPrice = 8496;
		weight = 4;
		class Settings : Settings {};
	};
	class PurifiedCocaine : PurifiedWeed {
		displayName = "Purified Cocaine";
		icon = "Data\Icons\cocaineProcessed.paa";
		buyPrice = 27480;
		sellPrice = 13740;
		weight = 5;
		class Settings : Settings {};
	};
	class PurifiedMeth : PurifiedWeed {
		displayName = "Purified Meth";
		icon = "Data\Icons\methProcessed.paa";
		buyPrice = 73200;
		sellPrice = 36600;
		weight = 5;
		class Settings : Settings {};
	};
	class PurifiedMoonshine : PurifiedWeed {
		displayName = "Purified Moonshine";
		icon = "Data\Icons\moonshine.paa";
		buyPrice = 16080;
		sellPrice = 8040;
		weight = 1;
		class Settings : Settings {};
	};

	// Raw Fish
	class Salema_F_Raw {
		displayName = "Raw Salema";
		description = "Raw fish that can be sold at a fish market or cooked at a public cookhouse.";
		icon = "Data\Icons\fish.paa";
		buyPrice = -1;
		sellPrice = 450;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
			isScripted = false;
		};
		conditions = "true";
	};
	class Ornate_random_F_Raw : Salema_F_Raw {
		displayName = "Raw Ornate";
		sellPrice = 660;
		class Settings : Settings {};
	};
	class Mackerel_F_Raw : Salema_F_Raw {
		displayName = "Raw Mackerel";
		sellPrice = 740;
		class Settings : Settings {};
	};
	class Tuna_F_Raw : Salema_F_Raw {
		displayName = "Raw Tuna";
		sellPrice = 822;
		class Settings : Settings {};
	};
	class Mullet_F_Raw : Salema_F_Raw {
		displayName = "Raw Mullet";
		sellPrice = 990;
		class Settings : Settings {};
	};
	class CatShark_F_Raw : Salema_F_Raw {
		displayName = "Raw Catshark";
		sellPrice = 1237;
		class Settings : Settings {};
	};
	class Turtle : Salema_F_Raw {
		displayName = "Turtle";
		icon = "Data\Icons\turtle.paa";
		sellPrice = 65000;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
		};
	};

	// Cooked Fish
	class CookedSalema {
		displayName = "Cooked Salema";
		description = "Cooked fish that can be sold at a fish market.";
		icon = "Data\Icons\fish.paa";
		buyPrice = 2250;
		sellPrice = 1125;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		conditions = "true";
	};
	class CookedOrnate : CookedSalema {
		displayName = "Cooked Ornate";
		buyPrice = 3300;
		sellPrice = 1650;
		class Settings : Settings {};
	};
	class CookedMackerel : CookedSalema {
		displayName = "Cooked Mackerel";
		buyPrice = 3700;
		sellPrice = 1850;
		class Settings : Settings {};
	};
	class CookedTuna : CookedSalema {
		displayName = "Cooked Tuna";
		buyPrice = 4112;
		sellPrice = 2056;
		class Settings : Settings {};
	};
	class CookedMullet : CookedSalema {
		displayName = "Cooked Mullet";
		buyPrice = 4950;
		sellPrice = 2475;
		class Settings : Settings {};
	};
	class CookedCatshark : CookedSalema {
		displayName = "Cooked Catshark";
		buyPrice = 6187;
		sellPrice = 3093;
		class Settings : Settings {};
	};

	// Archaeology Items
	class CommonMap {
		displayName = "Common Map";
		description = "A map containing various known artifact sites across Altis.";
		icon = "Data\Icons\map.paa";
		buyPrice = 20000;
		sellPrice = 10000;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		class Events { onUse = "[""Common""] call ULP_fnc_getSite;"; };
		conditions = "true";
	};
	class UncommonMap : CommonMap {
		displayName = "Uncommon Map";
		buyPrice = -1;
		sellPrice = 135000;
		class Settings : Settings {};
		class Events { onUse = "[""Uncommon""] call ULP_fnc_getSite;"; };
	};
	class RareMap : UncommonMap {
		displayName = "Rare Map";
		sellPrice = 180000;
		class Settings : Settings {};
		class Events { onUse = "[""Rare""] call ULP_fnc_getSite;"; };
	};

	class CommonMapFragment : UncommonMap {
		displayName = "Common Map Fragment";
		description = "A map fragment containing uncompleted map.";
		icon = "Data\Icons\mapFragment.paa";
		sellPrice = 15000;
		class Settings : Settings {};
	};
	class UncommonMapFragment : CommonMapFragment {
		displayName = "Uncommon Map Fragment";
		sellPrice = 30000;
		class Settings : Settings {};
	};
	class RareMapFragment : CommonMapFragment {
		displayName = "Rare Map Fragment";
		sellPrice = 45000;
		class Settings : Settings {};
	};

	class SurveyingEquipment {
		displayName = "Surveying Equipment";
		description = "Equipmented used to survay a dig site to locate artifacts.";
		icon = "Data\Icons\surveyingEquipment.paa";
		buyPrice = 28900;
		sellPrice = 14450;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		class Events { onUse = "[ULP_Archaeology] call ULP_fnc_surveySite;"; };
		class Deconstruction {
			time = 120;
			workbench = true;
			blueprints[] = { { "Tools", "B_SurveyingEquipment" } };
			materials[] = { {"CopperBar", 2}, {"SilverBar", 1} };
		};
		conditions = "true";
	};
	class ArchaeologistsEquipment : SurveyingEquipment {
		displayName = "Archaeologists' Equipment";
		description = "Equipment used to carefully dig up artifacts from dig sites.";
		icon = "Data\Icons\archaeologistsEquipment.paa";
		buyPrice = 24500;
		sellPrice = 12250;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[ULP_Archaeology] call ULP_fnc_digSite;"; };
		class Deconstruction {
			time = 120;
			workbench = true;
			blueprints[] = { { "Tools", "B_ArchaeologistsEquipment" } };
			materials[] = { {"IronBar", 4}, {"Wood", 2}, {"Rock", 1} };
		};
	};

	/// Common Rewards
	class OldCoin {
		displayName = "Old Coin";
		description = "Artifact collected from dig sites and sold at Altis Archaeologists.";
		icon = "Data\Icons\oldCoin.paa";
		buyPrice = -1;
		sellPrice = 11050;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
		};
		conditions = "true";
	};
	class CoinBundle : OldCoin {
		displayName = "Coin Bundle";
		icon = "Data\Icons\coinBundle.paa";
		sellPrice = 414375;
		weight = 6;
		class Settings : Settings {};
	};
	class BrokenPot : OldCoin {
		displayName = "Broken Pot";
		icon = "Data\Icons\brokenPot.paa";
		sellPrice = 22100;
		class Settings : Settings {};
	};
	class RestoredPot : OldCoin {
		displayName = "Restored Pot";
		icon = "Data\Icons\restoredPot.paa";
		sellPrice = 55250;
		class Settings : Settings {};
	};
	class BluntStoneKnife : OldCoin {
		displayName = "Blunt Stone Knife";
		icon = "Data\Icons\bluntStoneKnife.paa";
		sellPrice = 35700;
		class Settings : Settings {};
	};
	class SharpStoneKnife : OldCoin {
		displayName = "Sharp Stone Knife";
		icon = "Data\Icons\sharpStoneKnife.paa";
		sellPrice = 89250;
		class Settings : Settings {};
	};
	class FossilisedBone : OldCoin {
		displayName = "Fossilised Bone";
		icon = "Data\Icons\fossilisedBone.paa";
		sellPrice = 43460;
		class Settings : Settings {};
	};
	class UnidentifiedSkull : OldCoin {
		displayName = "Unidentified Skull";
		icon = "Data\Icons\unidentifiedSkull.paa";
		sellPrice = 87800;
		class Settings : Settings {};
	};
	class IdentifiedSkull : OldCoin {
		displayName = "Identified Skull";
		icon = "Data\Icons\unidentifiedSkull.paa";
		sellPrice = 1439000;
		class Settings : Settings {};
	};
	/// Uncommon Rewards
	class PetrifiedShield : OldCoin {
		displayName = "Petrified Shield";
		icon = "Data\Icons\petrifiedShield.paa";
		sellPrice = 96400;
		class Settings : Settings {};
	};
	class WeatheredSculpture : OldCoin {
		displayName = "Weathered Sculpture";
		icon = "Data\Icons\weatheredSculpture.paa";
		sellPrice = 129000;
		class Settings : Settings {};
	};
	class AncientAmber : OldCoin {
		displayName = "Ancient Amber";
		icon = "Data\Icons\ancientAmber.paa";
		sellPrice = 134570;
		class Settings : Settings {};
	};
	class RegliousTotem : OldCoin {
		displayName = "Reglious Totem";
		icon = "Data\Icons\regliousTotem.paa";
		sellPrice = 178600;
		class Settings : Settings {};
	};
	class StrongMetalRing : OldCoin {
		displayName = "Strong Metal Ring";
		icon = "Data\Icons\strongMetalRing.paa";
		sellPrice = 185200;
		class Settings : Settings {};
	};
	class DiamondRing : OldCoin {
		displayName = "Diamond Metal Ring";
		icon = "Data\Icons\diamondRing.paa";
		sellPrice = 185200;
		class Settings : Settings {};
	};
	/// Rare Rewards
	class EmeraldAmulet : OldCoin {
		displayName = "Emerald Amulet";
		icon = "Data\Icons\emeraldAmulet.paa";
		sellPrice = 347500;
		class Settings : Settings {};
	};
	class AncientLedger : OldCoin {
		displayName = "Ancient Ledger";
		icon = "Data\Icons\ancientLedger.paa";
		sellPrice = 489650;
		class Settings : Settings {};
	};
	class HandSmoothedRunestone : OldCoin {
		displayName = "Hand-Smoothed Runestone";
		icon = "Data\Icons\handSmoothedRunestone.paa";
		sellPrice = 372050;
		class Settings : Settings {};
	};
	class JeweledNecklace : OldCoin {
		displayName = "Jeweled Necklace";
		icon = "Data\Icons\jeweledNecklace.paa";
		sellPrice = 376450;
		class Settings : Settings {};
	};
	class BrokenTimepiece : OldCoin {
		displayName = "Broken Timepiece";
		icon = "Data\Icons\brokenTimepiece.paa";
		sellPrice = 411300;
		class Settings : Settings {};
	};
};