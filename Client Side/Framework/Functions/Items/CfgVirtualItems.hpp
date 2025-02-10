class CfgVirtualItems {
	// Fresh Food
	class FreshApple {
		displayName = "Fresh Apples";
		description = "Fresh fruit picked from local trees and sold at markets";
		icon = "Data\Icons\freshApples.paa";
		buyPrice = -1;
		sellPrice = 56;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
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
		sellPrice = 64;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	
	// Regular Food
	class Apple {
		displayName = "Apple";
		description = "Regular food that keeps you well fed";
		icon = "Data\Icons\apple.paa";
		buyPrice = 90;
		sellPrice = 45;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 20;
			thirst = 10;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Peach : Apple {
		displayName = "Peach";
		icon = "Data\Icons\peach.paa";
		buyPrice = 102;
		sellPrice = 51;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	class Bacon : Apple {
		displayName = "Bacon";
		icon = "Data\Icons\bacon.paa";
		buyPrice = 130;
		sellPrice = 65;
		class Settings : Settings {};
		class Sustain {
			hunger = 25;
			thirst = 0;
		};
		class Events : Events {};
	};
	class SausageRoll : Apple {
		displayName = "VEEgan Sausage Roll";
		icon = "Data\Icons\sausageRoll.paa";
		buyPrice = 150;
		sellPrice = 75;
		class Settings : Settings {};
		class Sustain {
			hunger = 40;
			thirst = 0;
		};
		class Events : Events { onUse = "[""Vegan""] call ULP_fnc_achieve; [(_this select 0)] call ULP_fnc_addSustenance;"; };
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
			hunger = 40;
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
			hunger = 30;
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
			hunger = 50;
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
			hunger = 15;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Sweetie : Bacon {
		displayName = "Sweetie";
		icon = "Data\Icons\sweetie.paa";
		buyPrice = 8;
		sellPrice = 4;
		class Settings : Settings {};
		class Sustain {
			hunger = 5;
			thirst = 0;
		};
		class Events : Events {};
	};

	// Regular Drinks
	class Water {
		displayName = "Water";
		description = "A regular drink used to keep you hydrated";
		icon = "Data\Icons\bottle.paa";
		buyPrice = 10;
		sellPrice = 5;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 50;
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
			thirst = 25;
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
		description = "An energy drink designed to give a person faster reactions";
		icon = "Data\Icons\can.paa";
		buyPrice = 2100;
		sellPrice = 1050;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 30;
		};
		class Events { onUse = "if ([(_this select 0)] call ULP_fnc_addSustenance) then { player setCustomAimCoef 0.5; [ { !(alive player) || { player getVariable [""isIncapacitated"", false] } || { diag_tickTime > (_this select 0) } }, [diag_tickTime + (3 * 60)], { player setCustomAimCoef 1; }] call ULP_fnc_waitUntilExecute; };"; };
		conditions = "true";
	};

	// Alcoholic Drinks
	class Beer {
		displayName = "Beer";
		description = "An alcoholic drink that causes uncomfortable side effects";
		icon = "Data\Icons\beer.paa";
		buyPrice = 290;
		sellPrice = 145;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 10;
		};
		class Events { onUse = "[""FirstDrink""] call ULP_fnc_achieve; [(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Schnapps : Beer {
		displayName = "Schnapps";
		icon = "Data\Icons\schnapps.paa";
		buyPrice = 725;
		sellPrice = 363;
		class Settings : Settings { 
			onMarket = true; 
			isEventItem = true;
		};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	class Gin : Beer {
		displayName = "Gin";
		icon = "Data\Icons\gin.paa";
		buyPrice = 375;
		sellPrice = 188;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	class Whiskey : Beer {
		displayName = "Whiskey";
		icon = "Data\Icons\whiskey.paa";
		buyPrice = 495;
		sellPrice = 248;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};

	// XP Rewards
	class TinyXPReward {
		displayName = "Tiny XP Reward";
		description = "A bottle that will provide valuable experience";
		icon = "Data\Icons\xpReward.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [100, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
		conditions = "true";
	};
	class SmallXPReward : TinyXPReward {
		displayName = "Small XP Reward";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [500, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class MediumXPReward : TinyXPReward {
		displayName = "Medium XP Reward";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [1000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class LargeXPReward : TinyXPReward {
		displayName = "Large XP Reward";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [5000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class HugeXPReward : TinyXPReward {
		displayName = "Huge XP Reward";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [10000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};

	// Event Triggers
	class AirdropTrigger {
		displayName = "Airdrop Trigger";
		description = "An item used to trigger a specific event";
		icon = "Data\Icons\airdropTrigger.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "[_this # 0, missionConfigFile >> ""CfgRandomEvents"" >> ""Airdrop""] call ULP_fnc_triggerEvent"; };
		conditions = "true";
	};

	class ShipwreckTrigger : AirdropTrigger {
		displayName = "Shipwreck Trigger";
		icon = "Data\Icons\shipwreckTrigger.paa";
		class Settings : Settings {};
		class Events { onUse = "[_this # 0, missionConfigFile >> ""CfgRandomEvents"" >> ""Shipwreck""] call ULP_fnc_triggerEvent"; };
	};

	class PopupTrigger : AirdropTrigger {
		displayName = "Popup Trigger";
		icon = "Data\Icons\popupTrigger.paa";
		class Settings : Settings {};
		class Events { onUse = "[_this # 0, missionConfigFile >> ""CfgRandomEvents"" >> ""PopupCartel""] call ULP_fnc_triggerEvent"; };
	};

	// General Items
	class DroppedMoney {
		displayName = "£%1";
		description = "Money found in body bags";
		icon = "Data\Icons\cash.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
			isScripted = true;
			isSystemItem = false;
		};
		conditions = "true";
	};

	class Identification {
		displayName = "%1's ID";
		description = "A card containing a person's identifity";
		icon = "Data\Icons\identification.paa";
		buyPrice = 75000;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = true;
			isSystemItem = false;
		};
		class Events {
			onUse = "_this call ULP_fnc_disguiseIdentity;";
			onRemove = "if ((player getVariable [""name"", """"]) isEqualTo (_this select 1)) then { player setVariable [""name"", nil, true]; [""You've lost the ID card you were disguising yourself with!""] call ULP_fnc_hint; };";
		};
		conditions = "true";
	};

	class Pickaxe {
		displayName = "Pickaxe";
		description = "A tool used for gathering items";
		icon = "Data\Icons\pickaxe.paa";
		buyPrice = 1200;
		sellPrice = 600;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class LumberAxe : Pickaxe {
		displayName = "Lumber Axe";
		icon = "Data\Icons\lumberAxe.paa";
		buyPrice = 1180;
		sellPrice = 590;
		class Settings : Settings {};
	};
	class Shovel : Pickaxe {
		displayName = "Shovel";
		icon = "Data\Icons\shovel.paa";
		buyPrice = 1100;
		sellPrice = 550;
		class Settings : Settings {};
	};
	class Extractor : Pickaxe {
		displayName = "Extractor";
		icon = "Data\Icons\extractor.paa";
		buyPrice = 1950;
		sellPrice = 975;
		class Settings : Settings {};
	};
	class FishingNet : Pickaxe {
		displayName = "Fishing Net";
		description = "A net designed to be deployed from a boat and catch fish";
		icon = "Data\Icons\fishingNet.paa";
		buyPrice = 750;
		sellPrice = 375;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_dropFishingNet;"; };
	};
	class FuelCan : Pickaxe {
		displayName = "Fuel Can";
		description = "Used to refuel your vehicle";
		icon = "Data\Icons\fuelCan.paa";
		buyPrice = 3000;
		sellPrice = 1500;
		weight = 12;
		class Settings : Settings {};
	};
	class Breathalyser : Pickaxe {
		displayName = "Breathalyser";
		description = "A device used to measure current levels of intoxication";
		icon = "Data\Icons\breathalyser.paa";
		buyPrice = 8400;
		sellPrice = 4200;
		weight = 1;
		class Settings : Settings {};
	};
	class Ziptie : Pickaxe {
		displayName = "Ziptie";
		description = "Used to restrain players when handcuffs aren't an option";
		icon = "Data\Icons\ziptie.paa";
		buyPrice = 13500;
		sellPrice = 6750;
		weight = 1;
		class Settings : Settings {};
	};
	class Blindfold : Pickaxe {
		displayName = "Blindfold";
		description = "Used to blindfold others";
		icon = "Data\Icons\blindfold.paa";
		buyPrice = 17000;
		sellPrice = 8500;
		weight = 1;
		class Settings : Settings {};
	};
	class Toolbox : Pickaxe {
		displayName = "Toolbox";
		description = "A box of tools used to deconstruct items into their core components";
		icon = "Data\Icons\toolbox.paa";
		buyPrice = 25000;
		sellPrice = 12500;
		weight = 4;
		class Settings : Settings {};
	};
	class VehicleClamp : Pickaxe {
		displayName = "Vehicle Clamp";
		description = "A deployable clamp used to prevent a vehicle's movement";
		icon = "Data\Icons\vehicleClamp.paa";
		buyPrice = 18200;
		sellPrice = 9700;
		weight = 8;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_clampVehicle;"; };
	};
	class Lighter : Pickaxe {
		displayName = "Lighter";
		description = "A simple lighter used to create fire";
		icon = "Data\Icons\lighter.paa";
		buyPrice = 890;
		sellPrice = 445;
		weight = 1;
		class Settings : Settings {};
	};
	class Lockpick : Pickaxe {
		displayName = "Lockpick";
		description = "Used to pick the locks of vehicles and handcuffs";
		icon = "Data\Icons\lockpick.paa";
		buyPrice = 2500;
		sellPrice = 1250;
		weight = 1;
		class Settings : Settings {};
	};
	class BoltCutter : Pickaxe {
		displayName = "Bolt Cutter";
		description = "Used to cut locks found on properties, airdrops and shipwrecks";
		icon = "Data\Icons\boltCutter.paa";
		buyPrice = 345000;
		sellPrice = 172500;
		weight = 8;
		class Settings : Settings { isIllegal = true; };
		class Events { onUse = "[] call ULP_fnc_boltcut;"; };
		class Deconstruction {
			time = 40;
			workbench = false;
			blueprints[] = { { "HandheldTools", "B_BoltCutter" } };
			materials[] = { 
				{"SteelPlate", 2},
				{"Wood", 1},
				{"Rubber", 1}
			};
		};
	};
	class BigRedKey : BoltCutter {
		displayName = "Big Red Key";
		buyPrice = 31200;
		sellPrice = 15600;
		weight = 14;
		class Settings : Settings {};
		class Events : Events {};
		conditions = "[""Police_Main"", 5] call ULP_fnc_hasAccess";
	};
	class ExplosiveCharge : Pickaxe {
		displayName = "Explosive Charge";
		description = "Used to destroy fortified locks";
		icon = "Data\Icons\explosiveCharge.paa";
		buyPrice = 750000;
		sellPrice = 375000;
		weight = 3;
		class Settings : Settings { isIllegal = true; };
		class Deconstruction {
			time = 180;
			workbench = true;
			blueprints[] = { { "HandheldTools", "B_ExplosiveCharge" } };
			materials[] = { 
				{"SteelPlate", 6},
				{"CopperWiring", 4}, 
				{"ExplosiveMaterials", 1}, 
				{"SilverPlate", 1}
			};
		};
	};
	class IndustrialDrill : Pickaxe {
		displayName = "Industrial Drill";
		icon = "Data\Icons\industrialDrill.paa";
		description = "Used to break heavily reinforced locks";
		buyPrice = 600000;
		sellPrice = 300000;
		weight = 16;
		class Settings : Settings { isIllegal = true; };
		class Events { onUse = "[] call ULP_fnc_drill;"; };
		class Deconstruction {
			time = 180;
			workbench = true;
			blueprints[] = { { "HandheldTools", "B_IndustrialDrill" } };
			materials[] = { 
				{"SteelPlate", 4},
				{"ProcessedOil", 2}
			};
		};
	};

	// Medical Supplies
	class Painkillers {
		displayName = "Painkillers";
		description = "Two pills that restore a small amount of health";
		icon = "Data\Icons\painkillers.paa";
		buyPrice = 800;
		sellPrice = 400;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Bandage : Painkillers {
		displayName = "Generic Bandage";
		description = "Used as a crafting material for medical equipment";
		icon = "Data\Icons\bandage.paa";
		buyPrice = 850;
		sellPrice = 425;
		class Settings : Settings {};
	};
	class FieldDressing : Bandage {
		displayName = "Field Dressing";
		icon = "Data\Icons\fieldDressing.paa";
		description = "A bandage best used for treating abrasions";
	};
	class Packing : Bandage {
		displayName = "Packing Bandage";
		icon = "Data\Icons\packingBandage.paa";
		description = "A bandage best used for treating abrasions and avulsions";
		buyPrice = 1000;
		sellPrice = 655;
	};
	class Elastic : Bandage {
		displayName = "Elastic Bandage";
		icon = "Data\Icons\elasticBandage.paa";
		description = "A bandage best used for treating abrasions and lacerations";
		buyPrice = 1085;
		sellPrice = 750;
	};
	class QuickClot : Bandage {
		displayName = "QuikClot";
		icon = "Data\Icons\quikClot.paa";
		description = "A bandage best used for treating abrasions and lacersations";
		buyPrice = 345;
		sellPrice = 125;
	};
	class BloodBag : Painkillers {
		displayName = "Blood Bag";
		description = "Used to prevent an incapacitated person from bleeding out";
		icon = "Data\Icons\bloodbag.paa";
		buyPrice = 1000;
		sellPrice = 500;
		weight = 2;
		class Settings : Settings {};
	};
	class Morphine : Painkillers {
		displayName = "Morphine";
		description = "Used to lower a person's heart rate in order to revive them";
		icon = "Data\Icons\injector.paa";
		buyPrice = 1200;
		sellPrice = 600;
		class Settings : Settings {};
	};
	class Epinephrine : Morphine {
		displayName = "Epinephrine";
		description = "Used to raise a person's heart rate in order to revive them";
		class Settings : Settings {};
	};
	class FirstAidKit : Painkillers {
		displayName = "First Aid Kit";
		description = "A kit containing various medical tools that can provide assistance";
		icon = "Data\Icons\firstAidKit.paa";
		buyPrice = 1500;
		sellPrice = 750;
		weight = 3;
		class Settings : Settings {};
	};
	class MediKit : FirstAidKit {
		displayName = "MediKit";
		icon = "Data\Icons\mediKit.paa";
		buyPrice = 18700;
		sellPrice = 9350;
		weight = 3;
		class Settings : Settings {};
	};
	class Defibrillator : MediKit {
		displayName = "Defibrillator";
		description = "A device that diagnoses life-threatening cardiac arrhythmias";
		icon = "Data\Icons\defibrillator.paa";
		buyPrice = 22600;
		sellPrice = 11300;
		weight = 3;
		class Settings : Settings {};
	};

	// Placeable Items
	class Stinger  {
		displayName = "Stinger";
		description = "A deployable strip of spikes used to puncute a vehicle's tryes";
		icon = "Data\Icons\stinger.paa";
		buyPrice = 8400;
		sellPrice = 2200;
		weight = 10;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Deconstruction {
			time = 45;
			workbench = true;
			blueprints[] = { { "HandheldTools", "B_MakeshiftStinger" } };
			materials[] = { 
				{"SteelBar", 8},
				{"IronBar", 8}, 
				{"SteelPlate", 4}, 
				{"FlawlessDiamond", 2}
			};
		};
		class Events { onUse = "_this call ULP_fnc_spikeStrip;"; };
		conditions = "true";
	};
	class MakeshiftStinger : Stinger {
		displayName = "Makeshift Stinger";
		class Settings : Settings {};
		class Events : Events {};
	};

	class Stretcher {
		displayName = "Stretcher";
		description = "A stretcher is a lightweight, portable frame used to carry injured or incapacitated individuals";
		icon = "Data\Icons\stretcher.paa";
		buyPrice = 12500;
		sellPrice = 4350;
		weight = 5;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Deconstruction {
			time = 15;
			workbench = true;
			blueprints[] = { { "MedicalSupplies", "B_Stretcher" } };
			materials[] = { 
				{"Bandage", 5},
				{"SteelBar", 2}, 
				{"SilverPlate", 1}
			};
		};
		class Events { onUse = "[""Stretcher"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[player, [""Police"", ""Medic"", ""Hato""]] call ULP_fnc_isFaction || { ULP_Level >= 5 }";
	};

	class RoadCone_F : Stretcher { 
		displayName = "Road Cone";
		description = "A bundled up item ready to be placed";
		icon = "Data\Icons\cone.paa";
		buyPrice = 800;
		sellPrice = 400;
		weight = 3;
		class Settings : Settings {};
		class Deconstruction {};
		class Events { onUse = "[""RoadCone_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class RoadCone_L_F : RoadCone_F { 
		displayName = "Road Cone (Light)";
		buyPrice = 900;
		sellPrice = 450;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[""RoadCone_L_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Pole_F : RoadCone_F { 
		displayName = "Pole";
		buyPrice = 300;
		sellPrice = 150;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""Pole_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class Land_PortableLight_single_F : RoadCone_F { 
		displayName = "Portable Light (Single)";
		icon = "Data\Icons\portableLight.paa";
		buyPrice = 1500;
		sellPrice = 750;
		weight = 6;
		class Settings : Settings {};
		class Events { onUse = "[""Land_PortableLight_single_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_PortableLight_double_F : Land_PortableLight_single_F { 
		displayName = "Portable Light (Double)";
		buyPrice = 1700;
		sellPrice = 850;
		class Settings : Settings {};
		class Events { onUse = "[""Land_PortableLight_double_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_PortableLight_02_single_yellow_F : Land_PortableLight_single_F { 
		displayName = "Portable Lamp (Single, Yellow)";
		buyPrice = 800;
		sellPrice = 400;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[""Land_PortableLight_02_single_yellow_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_PortableLight_02_double_yellow_F : Land_PortableLight_02_single_yellow_F { 
		displayName = "Portable Lamp (Double, Yellow)";
		class Settings : Settings {};
		class Events { onUse = "[""Land_PortableLight_02_double_yellow_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_PortableLight_02_quad_yellow_F : Land_PortableLight_02_single_yellow_F { 
		displayName = "Portable Lamp (Quad, Yellow)";
		class Settings : Settings {};
		class Events { onUse = "[""Land_PortableLight_02_quad_yellow_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class Land_BarGate_F : RoadCone_F { 
		displayName = "Bar Gate";
		icon = "Data\Icons\barGate.paa";
		buyPrice = 18000;
		sellPrice = 9000;
		weight = 24;
		class Settings : Settings {};
		class Events { onUse = "[""Land_BarGate_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_RoadBarrier_01_F : Land_BarGate_F { 
		displayName = "Bar Gate (V2)";
		class Settings : Settings {};
		class Events { onUse = "[""Land_RoadBarrier_01_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class TapeSign_F : RoadCone_F { 
		displayName = "Red-White Tape";
		icon = "Data\Icons\roadBarrier.paa";
		buyPrice = 500;
		sellPrice = 250;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[""TapeSign_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class RoadBarrier_F : TapeSign_F { 
		displayName = "Road Barrier";
		buyPrice = 4300;
		sellPrice = 2150;
		weight = 6;
		class Settings : Settings {};
		class Events { onUse = "[""RoadBarrier_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class RoadBarrier_small_F : RoadBarrier_F { 
		displayName = "Road Barrier (Small)";
		buyPrice = 3600;
		sellPrice = 1800;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[""RoadBarrier_small_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PlasticBarrier_03_orange_F : RoadBarrier_F { 
		displayName = "Plastic Barrier (Large, Orange)";
		buyPrice = 3500;
		sellPrice = 1750;
		weight = 12;
		class Settings : Settings {};
		class Events { onUse = "[""PlasticBarrier_03_orange_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PlasticBarrier_03_blue_F : PlasticBarrier_03_orange_F { 
		displayName = "Plastic Barrier (Large, Blue)";
		class Settings : Settings {};
		class Events { onUse = "[""PlasticBarrier_03_blue_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PlasticBarrier_02_yellow_F : RoadBarrier_F { 
		displayName = "Plastic Barrier (Medium, Yellow)";
		buyPrice = 3100;
		sellPrice = 1550;
		weight = 8;
		class Settings : Settings {};
		class Events { onUse = "[""PlasticBarrier_02_yellow_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PlasticBarrier_02_grey_F : PlasticBarrier_02_yellow_F { 
		displayName = "Plastic Barrier (Medium, Grey)";
		class Settings : Settings {};
		class Events { onUse = "[""PlasticBarrier_02_grey_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_CncBarrier_F : RoadBarrier_F { 
		displayName = "Concrete Barrier";
		buyPrice = 8000;
		sellPrice = 4000;
		weight = 10;
		class Settings : Settings {};
		class Events { onUse = "[""Land_CncBarrier_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_CncBarrier_stripes_F : Land_CncBarrier_F { 
		displayName = "Concrete Barrier (Stripes)";
		class Settings : Settings {};
		class Events { onUse = "[""Land_CncBarrier_stripes_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class Land_SandbagBarricade_01_half_F : RoadCone_F { 
		displayName = "Sandbag Barricade (Short)";
		icon = "Data\Icons\sandbag.paa";
		buyPrice = 6000;
		sellPrice = 3000;
		weight = 5;
		class Settings : Settings {};
		class Events { onUse = "[""Land_SandbagBarricade_01_half_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_BagFence_Long_F : Land_SandbagBarricade_01_half_F { 
		displayName = "Sandbag Wall (Long)";
		buyPrice = 4000;
		sellPrice = 2000;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[""Land_BagFence_Long_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_BagFence_Short_F : Land_BagFence_Long_F { 
		displayName = "Sandbag Wall (Short)";
		class Settings : Settings {};
		class Events { onUse = "[""Land_BagFence_Short_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_BagFence_Round_F : Land_BagFence_Long_F { 
		displayName = "Sandbag Wall (Round)";
		class Settings : Settings {};
		class Events { onUse = "[""Land_BagFence_Round_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class Land_CzechHedgehog_01_old_F : RoadCone_F { 
		displayName = "Czech Hedgehog";
		icon = "Data\Icons\hedgehog.paa";
		buyPrice = 16000;
		sellPrice = 8000;
		weight = 10;
		class Settings : Settings {};
		class Events { onUse = "[""Land_CzechHedgehog_01_old_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class Land_CampingTable_white_F : RoadCone_F { 
		displayName = "Comping Table (White)";
		icon = "Data\Icons\table.paa";
		buyPrice = 2000;
		sellPrice = 1000;
		weight = 6;
		class Settings : Settings {};
		class Events { onUse = "[""Land_CampingTable_white_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_CampingTable_small_white_F : Land_CampingTable_white_F { 
		displayName = "Comping Table (Small, White)";
		buyPrice = 1500;
		sellPrice = 750;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[""Land_CampingTable_small_white_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_CampingChair_V2_white_F : RoadCone_F { 
		displayName = "Comping Chair (White)";
		icon = "Data\Icons\chair.paa";
		buyPrice = 900;
		sellPrice = 450;
		weight = 3;
		class Settings : Settings {};
		class Events { onUse = "[""Land_CampingChair_V2_white_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_FieldToilet_F : RoadCone_F { 
		displayName = "Field Toilet";
		icon = "Data\Icons\toilet.paa";
		buyPrice = 1800;
		sellPrice = 900;
		weight = 10;
		class Settings : Settings {};
		class Events { onUse = "[""Land_FieldToilet_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class Target_F : RoadCone_F { 
		displayName = "Simple Target";
		icon = "Data\Icons\target.paa";
		buyPrice = 900;
		sellPrice = 450;
		weight = 5;
		class Settings : Settings {};
		class Events { onUse = "[""Target_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_Target_Dueling_01_F : Target_F { 
		displayName = "Dueling Target";
		buyPrice = 200;
		sellPrice = 100;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[""Land_Target_Dueling_01_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Scarecrow_01_F : RoadCone_F { 
		displayName = "Scarecrow";
		icon = "Data\Icons\scarecrow.paa";
		buyPrice = 100;
		sellPrice = 50;
		weight = 3;
		class Settings : Settings {};
		class Events { onUse = "[""Scarecrow_01_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class Flag_UK_F : RoadCone_F { 
		displayName = "Flag (UK)";
		icon = "Data\Icons\flag.paa";
		buyPrice = 900;
		sellPrice = 450;
		weight = 3;
		class Settings : Settings {};
		class Events { onUse = "[""Flag_UK_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Flag_AltisColonial_F : Flag_UK_F { 
		displayName = "Flag (Altis Colonial)";
		class Settings : Settings {};
		class Events { onUse = "[""Flag_AltisColonial_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Flag_RedCrystal_F : Flag_UK_F { 
		displayName = "Flag (Red Crystal)";
		class Settings : Settings {};
		class Events { onUse = "[""Flag_RedCrystal_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class PortableHelipadLight_01_yellow_F : RoadCone_F { 
		displayName = "Portable Light (Yellow)";
		icon = "Data\Icons\portableLamp.paa";
		buyPrice = 400;
		sellPrice = 200;
		weight = 1;
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_yellow_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PortableHelipadLight_01_white_F : PortableHelipadLight_01_yellow_F { 
		displayName = "Portable Light (White)";
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_white_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PortableHelipadLight_01_red_F : PortableHelipadLight_01_yellow_F { 
		displayName = "Portable Light (Red)";
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_red_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PortableHelipadLight_01_green_F : PortableHelipadLight_01_yellow_F { 
		displayName = "Portable Light (Green)";
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_green_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PortableHelipadLight_01_blue_F : PortableHelipadLight_01_yellow_F { 
		displayName = "Portable Light (Blue)";
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_blue_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PortableHelipadLight_01_F : PortableHelipadLight_01_yellow_F { 
		displayName = "Portable Light (Pink)";
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	// Major Crime Items
	class MarkedGold {
		displayName = "Marked Gold";
		description = "Gold from the HM Treasury marked with the King's Cypher";
		icon = "Data\Icons\ingot.paa";
		buyPrice = -1;
		sellPrice = 312500;
		weight = 16;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
			canSlingLoad = false;
		};
		conditions = "true";
	};
	class UnmarkedGold : MarkedGold {
		displayName = "Unmarked Gold";
		description = "Gold from the HM Treasury that's been debranded";
		sellPrice = 875000;
		class Settings : Settings {};
	};
	class EncryptedDrive : MarkedGold {
		displayName = "Encrypted Drive";
		description = "An encrypted drive from the HMS Liberty's command deck";
		icon = "Data\Icons\drive.paa";
		sellPrice = 500000;
		weight = 8;
		class Settings : Settings {};
	};
	class DecryptedDrive : EncryptedDrive {
		displayName = "Decrypted Drive";
		description = "A decrypted drive from the HMS Liberty's command deck";
		sellPrice = 1250000;
		class Settings : Settings {};
	};
	class SpaceCapsuleDataDrive : DecryptedDrive {
		displayName = "Space Capsule Date Drive";
		description = "A data drive from a space capsule containing unknown secrets";
		sellPrice = 25000000;
		weight = 25;
		class Settings : Settings {};
	};
	class SeizedContraband : MarkedGold {
		displayName = "Seized Contraband";
		description = "Contraband seized by the Police and stored in a secure facility";
		icon = "Data\Icons\seizedContraband.paa";
		sellPrice = 297000;
		weight = 4;
		class Settings : Settings {};
	};
	class LargeGalleryPiece : MarkedGold {
		displayName = "Large Gallery Piece";
		description = "A piece of art displayed in the Art Gallery";
		icon = "Data\Icons\galleryPiece.paa";
		sellPrice = 915625;
		weight = 14;
		class Settings : Settings {};
	};
	class MediumGalleryPiece : LargeGalleryPiece {
		displayName = "Medium Gallery Piece";
		sellPrice = 620000;
		weight = 10;
		class Settings : Settings {};
	};
	class SmallGalleryPiece : LargeGalleryPiece {
		displayName = "Small Gallery Piece";
		sellPrice = 456250;
		weight = 6;
		class Settings : Settings {};
	};

	// Unprocessed Materials
	class Tobacco {
		displayName = "Tobacco";
		description = "A leaf that can be processed into cigarettes or cigars";
		icon = "Data\Icons\tobacco.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Rock : Tobacco {
		displayName = "Rock";
		description = "A rock mined at His Majesty's pleasure";
		icon = "Data\Icons\ore.paa";
		sellPrice = 3;
		weight = 3;
		class Settings : Settings {};
		conditions = "ULP_Imprisioned";
	};
	class Coal : Tobacco {
		displayName = "Coal";
		description = "A lump of coal sold at the Coal Plant without processing";
		icon = "Data\Icons\ore.paa";
		buyPrice = -1;
		sellPrice = 3000;
		weight = 4;
		class Settings : Settings {
			onMarket = true;
			isSavable = true;
			isEventItem = true;
		};
	};
	class Coral : Coal {
		displayName = "Coral";
		description = "Coral gathered and sold near Kavala without processing";
		icon = "Data\Icons\coral.paa";
		sellPrice = 8375;
		weight = 7;
		class Settings : Settings { isIllegal = true; };
		conditions = "true";
	};
	class CopperOre : Tobacco {
		displayName = "Copper Ore";
		description = "Ore mined with a pickaxe and requiring processing";
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
		weight = 5;
		class Settings : Settings {};
	};
	class UraniumOre : CopperOre {
		displayName = "Uranium Ore";
		icon = "Data\Icons\ore.paa";
		weight = 6;
		class Settings : Settings { isIllegal = true; };
	};
	class Sand : CopperOre {
		displayName = "Sand";
		description = "Sand gathered with a shovel and requiring processing";
		icon = "Data\Icons\sand.paa";
		weight = 2;
		class Settings : Settings {};
	};
	class UnrefinedSalt : CopperOre {
		displayName = "Unrefined Salt";
		description = "Salt mined with a pickaxe and requiring processing";
		icon = "Data\Icons\saltUnrefined.paa";
		weight = 3;
		class Settings : Settings {};
	};
	class UnprocessedOil : CopperOre {
		displayName = "Unrefinded Oil";
		description = "Oil drilled with an extractor, requiring a fliud track and processing";
		icon = "Data\Icons\liquid.paa";
		weight = 6;
		class Settings : Settings {};
	};
	class UncutDiamond : CopperOre {
		displayName = "Diamond Ore";
		icon = "Data\Icons\ore.paa";
		description = "A gem mined with a pickaxe and requiring processing";
		class Settings : Settings {};
	};
	class UncutBloodDiamond : CopperOre {
		displayName = "Blood Diamond Ore";
		icon = "Data\Icons\ore.paa";
		class Settings : Settings { isIllegal = true; };
	};

	// Processed Materials
	class Cigarette {
		displayName = "Cigarette";
		description = "A roll of tobacco that can be sold or smoked";
		icon = "Data\Icons\cigarette.paa";
		buyPrice = -1;
		sellPrice = 3563;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = true;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Cigar : Cigarette {
		displayName = "Cigar";
		icon = "Data\Icons\cigar.paa";
		sellPrice = 3360;
		class Settings : Settings {};
	};
	class CopperBar : Cigarette {
		displayName = "Copper Bar";
		description = "A metal bar sold at Altis Metal Exports";
		icon = "Data\Icons\ingot.paa";
		buyPrice = -1;
		sellPrice = 2375;
		weight = 2;
		class Settings : Settings {};
	};
	class SilverBar : CopperBar {
		displayName = "Silver Bar";
		sellPrice = 2750;
		class Settings : Settings {};
	};
	class IronBar : CopperBar {
		displayName = "Iron Bar";
		sellPrice = 9188;
		class Settings : Settings {};
	};
	class UraniumBar : CopperBar {
		displayName = "Uranium Bar";
		description = "A metal bar sold at its own trader";
		sellPrice = 27688;
		weight = 3;
		class Settings : Settings { isIllegal = true; };
	};
	class Glass : CopperBar {
		displayName = "Glass";
		description = "Basically just hot sand that can be sold";
		icon = "Data\Icons\glass.paa";
		sellPrice = 3188;
		weight = 1;
		class Settings : Settings {};
	};
	class RefinedSalt : CopperBar {
		displayName = "Refined Salt";
		description = "Refined blocks salt ready to be sold";
		icon = "Data\Icons\saltRefined.paa";
		sellPrice = 4000;
		class Settings : Settings {};
	};
	class ProcessedOil : CopperBar {
		displayName = "Refinded Oil";
		description = "Refinded oil that has been barreled and ready to be sold";
		icon = "Data\Icons\oil.paa";
		sellPrice = 13688;
		weight = 4;
		class Settings : Settings {};
	};
	class CutDiamond : CopperBar {
		displayName = "Cut Diamond";
		description = "A finely cut gem ready to be sold";
		icon = "Data\Icons\gem.paa";
		sellPrice = 8125;
		class Settings : Settings {};
	};
	class CutBloodDiamond : CutDiamond {
		displayName = "Cut Blood Diamond";
		icon = "Data\Icons\gem.paa";
		sellPrice = 11875;
		class Settings : Settings { isIllegal = true; };
	};
	class FlawlessDiamond : CutDiamond {
		displayName = "Flawless Diamond";
		sellPrice = 60938;
		class Settings : Settings { isEventItem = false; };
	};

	// Unprocessed Drugs
	class UnprocessedWeed {
		displayName = "Unprocessed Weed";
		description = "An item that requires processing into a drug";
		icon = "Data\Icons\weedUnprocessed.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
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
	class EphedrineBarrel : UnprocessedWeed {
		displayName = "Ephedrine Barrel";
		description = "The base material in making crystal meth";
		icon = "Data\Icons\methUnprocessed.paa";
		buyPrice = 6050;
		weight = 12;
		class Settings : Settings { onMarket = true; };
	};
	class Corn : UnprocessedWeed {
		displayName = "Corn";
		description = "The base material in making moonshine";
		icon = "Data\Icons\corn.paa";
		weight = 3;
		class Settings : Settings {};
	};

	// Processed Drugs
	class ProcessedWeed {
		displayName = "Processed Weed";
		description = "A drugs sold at a Drug Dealer";
		icon = "Data\Icons\weedProcessed.paa";
		buyPrice = 16275;
		sellPrice = 5425;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
			isEventItem = true;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class ProcessedHeroin : ProcessedWeed {
		displayName = "Processed Heroin";
		icon = "Data\Icons\heroinProcessed.paa";
		buyPrice = 26550;
		sellPrice = 8850;
		weight = 4;
		class Settings : Settings {};
	};
	class ProcessedCocaine : ProcessedWeed {
		displayName = "Processed Cocaine";
		icon = "Data\Icons\cocaineProcessed.paa";
		buyPrice = 42938;
		sellPrice = 14313;
		weight = 5;
		class Settings : Settings {};
	};
	class ProcessedMeth : ProcessedWeed {
		displayName = "Meth";
		icon = "Data\Icons\methProcessed.paa";
		buyPrice = 114375;
		sellPrice = 38125;
		weight = 5;
		class Settings : Settings {};
	};
	class Moonshine : ProcessedWeed {
		displayName = "Moonshine";
		icon = "Data\Icons\moonshine.paa";
		buyPrice = 25125;
		sellPrice = 8375;
		weight = 2;
		class Settings : Settings {};
	};
	class Ecstasy : ProcessedWeed {
		displayName = "Ecstasy";
		icon = "Data\Icons\ecstasy.paa";
		buyPrice = 19688;
		sellPrice = 6563;
		weight = 1;
		class Settings : Settings {};
	};

	// Purified Drugs
	class PurifiedWeed {
		displayName = "Purified Weed";
		description = "A purified drug made when the Northern Drug Cartel is owned";
		icon = "Data\Icons\weedProcessed.paa";
		buyPrice = 16909;
		sellPrice = 5636;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
			isEventItem = true;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class PurifiedHeroin : PurifiedWeed {
		displayName = "Purified Heroin";
		icon = "Data\Icons\heroinProcessed.paa";
		buyPrice = 35843;
		sellPrice = 11948;
		weight = 4;
		class Settings : Settings {};
	};
	class PurifiedCocaine : PurifiedWeed {
		displayName = "Purified Cocaine";
		icon = "Data\Icons\cocaineProcessed.paa";
		buyPrice = 57964;
		sellPrice = 19321;
		weight = 5;
		class Settings : Settings {};
	};
	class PurifiedMeth : PurifiedWeed {
		displayName = "Purified Meth";
		icon = "Data\Icons\methProcessed.paa";
		buyPrice = 139406;
		sellPrice = 46469;
		weight = 5;
		class Settings : Settings {};
	};
	class PurifiedMoonshine : PurifiedWeed {
		displayName = "Purified Moonshine";
		icon = "Data\Icons\moonshine.paa";
		buyPrice = 30169;
		sellPrice = 10056;
		weight = 1;
		class Settings : Settings {};
	};

	// Weapons
	class WeaponParts {
		displayName = "Weapon Parts";
		description = "Parts processed when the Church Arms Cartel is owned";
		icon = "Data\Icons\weaponParts.paa";
		buyPrice = 5900;
		sellPrice = -1;
		weight = 6;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class WeaponCrate : WeaponParts {
		displayName = "Weapon Crate";
		description = "Processed and sold when Church Arms Cartel is owned";
		icon = "Data\Icons\weaponCrate.paa";
		buyPrice = -1;
		sellPrice = 73375;
		weight = 5;
		class Settings : Settings {
			isSavable = true;
			isEventItem = true;
		};
	};

	// Cargo Mission Items
	class FreightCargo {
		displayName = "Freight Cargo";
		description = "Crates designed only for vehicles containing valuables";
		icon = "Data\Icons\freightCargo.paa";
		buyPrice = -1;
		sellPrice = 44600;
		weight = 24;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = false;
			isScripted = false;
			isEventItem = true;
			isSystemItem = true;
			canSlingLoad = false;
		};
		conditions = "true";
	};
	class StolenCargo : FreightCargo {
		displayName = "Stolen Cargo";
		icon = "Data\Icons\crate.paa";
		sellPrice = 89200;
		weight = 28;
		class Settings : Settings { isIllegal = true; };
	};

	// Raw Fish
	class Salema_F_Raw {
		displayName = "Raw Salema";
		description = "Raw fish sold at a Fish Market or cooked at a Cookhouse";
		icon = "Data\Icons\fish.paa";
		buyPrice = -1;
		sellPrice = 563;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
			isScripted = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Ornate_random_F_Raw : Salema_F_Raw {
		displayName = "Raw Ornate";
		sellPrice = 825;
		class Settings : Settings {};
	};
	class Mackerel_F_Raw : Salema_F_Raw {
		displayName = "Raw Mackerel";
		sellPrice = 925;
		class Settings : Settings {};
	};
	class Tuna_F_Raw : Salema_F_Raw {
		displayName = "Raw Tuna";
		sellPrice = 1028;
		class Settings : Settings {};
	};
	class Mullet_F_Raw : Salema_F_Raw {
		displayName = "Raw Mullet";
		sellPrice = 1238;
		class Settings : Settings {};
	};
	class CatShark_F_Raw : Salema_F_Raw {
		displayName = "Raw Catshark";
		sellPrice = 1237;
		class Settings : Settings {};
	};
	class Turtle_F_Raw : Salema_F_Raw {
		displayName = "Turtle";
		description = "Turtles shot, caught and later sold at a dealer";
		icon = "Data\Icons\turtle.paa";
		sellPrice = 35625;
		weight = 5;
		class Settings : Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isEventItem = true;
		};
	};

	// Cooked Fish
	class CookedSalema {
		displayName = "Cooked Salema";
		description = "Cooked fish sold at a Fish Market";
		icon = "Data\Icons\fish.paa";
		buyPrice = 2813;
		sellPrice = 1406;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class CookedOrnate : CookedSalema {
		displayName = "Cooked Ornate";
		buyPrice = 4125;
		sellPrice = 2063;
		class Settings : Settings {};
	};
	class CookedMackerel : CookedSalema {
		displayName = "Cooked Mackerel";
		buyPrice = 4625;
		sellPrice = 2313;
		class Settings : Settings {};
	};
	class CookedTuna : CookedSalema {
		displayName = "Cooked Tuna";
		buyPrice = 5140;
		sellPrice = 2570;
		class Settings : Settings {};
	};
	class CookedMullet : CookedSalema {
		displayName = "Cooked Mullet";
		buyPrice = 6188;
		sellPrice = 3094;
		class Settings : Settings {};
	};
	class CookedCatshark : CookedSalema {
		displayName = "Cooked Catshark";
		buyPrice = 7733;
		sellPrice = 3866;
		class Settings : Settings {};
	};

	// Crafting Materials
	class Clay {
		displayName = "Clay";
		description = "A material used in crafting";
		icon = "Data\Icons\clay.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Wood : Clay {
		displayName = "Wood";
		icon = "Data\Icons\wood.paa";
		sellPrice = 450;
		weight = 2;
		class Settings : Settings {};
	};
	class Plank : Clay {
		displayName = "Plank";
		description = "A material used in crafting or sold at the Market";
		icon = "Data\Icons\plank.paa";
		sellPrice = 1688;
		weight = 2;
		class Settings {
			onMarket = true;
			isEventItem = true;
		};
	};
	class Rubber : Clay {
		displayName = "Rubber";
		icon = "Data\Icons\rubber.paa";
		class Settings : Settings {};
	};
	class RubberSheet : Clay {
		displayName = "Rubber Sheet";
		icon = "Data\Icons\rubberSheet.paa";
		class Settings : Settings {};
	};
	class SteelBar : Clay {
		displayName = "Steel Bar";
		icon = "Data\Icons\ingot.paa";
		weight = 2;
		class Settings : Settings {};
	};
	class GlassPanel : Clay {
		displayName = "Glass Panel";
		icon = "Data\Icons\glass.paa";
		class Settings : Settings {};
	};
	class ReinforcedGlassPanel : GlassPanel {
		displayName = "Reinforced Glass Panel";
		class Settings : Settings {};
	};
	class CopperWiring : Clay {
		displayName = "Copper Wiring";
		icon = "Data\Icons\copperWiring.paa";
		class Settings : Settings {};
	};
	class CopperPlate : Clay {
		displayName = "Copper Plate";
		icon = "Data\Icons\metalPlate.paa";
		class Settings : Settings {};
	};
	class IronPlate : CopperPlate {
		displayName = "Iron Plate";
		class Settings : Settings {};
	};
	class SilverPlate : CopperPlate {
		displayName = "Silver Plate";
		class Settings : Settings {};
	};
	class SteelPlate : CopperPlate {
		displayName = "Steel Plate";
		class Settings : Settings {};
	};
	class PackedOil : CopperPlate {
		displayName = "Packed Oil";
		icon = "Data\Icons\oil.paa";
		class Settings : Settings {};
	};
	class DiamondDrillBit : Clay {
		displayName = "Diamond Drill Bit";
		icon = "Data\Icons\drillBit.paa";
		class Settings : Settings {};
	};
	class ExplosiveMaterials : Clay {
		displayName = "Explosive Materials";
		icon = "Data\Icons\explosiveMaterials.paa";
		weight = 3;
		class Settings : Settings {};
		class Deconstruction {
			time = 90;
			workbench = true;
			blueprints[] = { { "CraftingMaterials", "B_ExplosiveMaterials" } };
			materials[] = { 
				{"CopperWiring", 16},
				{"IronPlate", 6},
				{"UraniumBar", 4},
				{"SteelPlate", 2},
				{"PackedOil", 2}
			};
		};
	};

	// Archaeology Items
	class SurveyingEquipment {
		displayName = "Surveying Equipment";
		description = "Equipment used to survey a dig site to locate artifacts";
		icon = "Data\Icons\surveyingEquipment.paa";
		buyPrice = 28900;
		sellPrice = 14450;
		weight = 6;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "[ULP_Archaeology] call ULP_fnc_surveySite;"; };
		class Deconstruction {
			time = 25;
			workbench = true;
			blueprints[] = { { "HandheldTools", "B_SurveyingEquipment" } };
			materials[] = { 
				{"SilverPlate", 1}, 
				{"GlassPanel", 1}
			};
		};
		conditions = "true";
	};
	class ArchaeologistsEquipment : SurveyingEquipment {
		displayName = "Archaeologists' Equipment";
		description = "Equipment used to dig artifacts from dig sites";
		icon = "Data\Icons\archaeologistsEquipment.paa";
		buyPrice = 24500;
		sellPrice = 12250;
		class Settings : Settings {};
		class Events { onUse = "[ULP_Archaeology] call ULP_fnc_digSite;"; };
		class Deconstruction {
			time = 25;
			workbench = true;
			blueprints[] = { { "HandheldTools", "B_ArchaeologistsEquipment" } };
			materials[] = { {"IronPlate", 1} };
		};
	};

	class CommonMap {
		displayName = "Common Map";
		description = "A map containing of artifact sites across Altis";
		icon = "Data\Icons\map.paa";
		buyPrice = 20000;
		sellPrice = 12500;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "[""Common""] call ULP_fnc_getSite;"; };
		conditions = "true";
	};
	class UncommonMap : CommonMap {
		displayName = "Uncommon Map";
		buyPrice = -1;
		sellPrice = 168750;
		class Settings : Settings {};
		class Events { onUse = "[""Uncommon""] call ULP_fnc_getSite;"; };
	};
	class RareMap : UncommonMap {
		displayName = "Rare Map";
		sellPrice = 225000;
		class Settings : Settings {};
		class Events { onUse = "[""Rare""] call ULP_fnc_getSite;"; };
	};
	class LegendaryMap : UncommonMap {
		displayName = "Legendary Map";
		sellPrice = 312500;
		class Settings : Settings {};
		class Events { onUse = "[""Legendary""] call ULP_fnc_getSite;"; };
	};

	class CommonMapFragment {
		displayName = "Common Map Fragment";
		description = "A fragment of an incomplete map";
		icon = "Data\Icons\mapFragment.paa";
		buyPrice = -1;
		sellPrice = 18750;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class UncommonMapFragment : CommonMapFragment {
		displayName = "Uncommon Map Fragment";
		sellPrice = 37500;
		class Settings : Settings {};
	};
	class RareMapFragment : CommonMapFragment {
		displayName = "Rare Map Fragment";
		sellPrice = 56250;
		class Settings : Settings {};
	};
	class LegendaryMapFragment : CommonMapFragment {
		displayName = "Legendary Map Fragment";
		sellPrice = 75000;
		class Settings : Settings {};
	};

	class OldCoin {
		displayName = "Old Coin";
		description = "An artifact sold at Altis Archaeologists";
		icon = "Data\Icons\oldCoin.paa";
		buyPrice = -1;
		sellPrice = 9109;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class CoinBundle : OldCoin {
		displayName = "Coin Bundle";
		icon = "Data\Icons\coinBundle.paa";
		sellPrice = 388476;
		weight = 2;
		class Settings : Settings {};
	};
	class BrokenPot : OldCoin {
		displayName = "Broken Pot";
		icon = "Data\Icons\brokenPot.paa";
		sellPrice = 19469;
		weight = 4;
		class Settings : Settings {};
	};
	class RestoredPot : BrokenPot {
		displayName = "Restored Pot";
		icon = "Data\Icons\restoredPot.paa";
		sellPrice = 49296;
		class Settings : Settings {};
	};
	class BluntStoneKnife : OldCoin {
		displayName = "Blunt Stone Knife";
		icon = "Data\Icons\bluntStoneKnife.paa";
		sellPrice = 30969;
		weight = 2;
		class Settings : Settings {};
	};
	class SharpStoneKnife : OldCoin {
		displayName = "Sharp Stone Knife";
		icon = "Data\Icons\sharpStoneKnife.paa";
		sellPrice = 96171;
		weight = 2;
		class Settings : Settings {};
	};
	class FossilisedBone : OldCoin {
		displayName = "Fossilised Bone";
		icon = "Data\Icons\fossilisedBone.paa";
		sellPrice = 39494;
		weight = 2;
		class Settings : Settings {};
	};
	class UnidentifiedSkull : OldCoin {
		displayName = "Unidentified Skull";
		sellPrice = 82313;
		weight = 4;
		class Settings : Settings {};
	};
	class IdentifiedSkull : UnidentifiedSkull {
		displayName = "Identified Skull";
		icon = "Data\Icons\unidentifiedSkull.paa";
		sellPrice = 2423750;
		class Settings : Settings {};
	};
	class PetrifiedShield : OldCoin {
		displayName = "Petrified Shield";
		icon = "Data\Icons\petrifiedShield.paa";
		sellPrice = 87875;
		weight = 6;
		class Settings : Settings {};
	};
	class WeatheredSculpture : OldCoin {
		displayName = "Weathered Sculpture";
		icon = "Data\Icons\weatheredSculpture.paa";
		sellPrice = 102188;
		weight = 5;
		class Settings : Settings {};
	};
	class AncientAmber : OldCoin {
		displayName = "Ancient Amber";
		icon = "Data\Icons\ancientAmber.paa";
		sellPrice = 113659;
		class Settings : Settings {};
	};
	class ReligiousTotem : OldCoin {
		displayName = "Religious Totem";
		icon = "Data\Icons\religiousTotem.paa";
		sellPrice = 122438;
		weight = 2;
		class Settings : Settings {};
	};
	class StrongMetalRing : OldCoin {
		displayName = "Strong Metal Ring";
		icon = "Data\Icons\strongMetalRing.paa";
		sellPrice = 148625;
		class Settings : Settings {};
	};
	class DiamondRing : OldCoin {
		displayName = "Diamond Metal Ring";
		icon = "Data\Icons\diamondRing.paa";
		sellPrice = 307625;
		class Settings : Settings {};
	};
	class EmeraldAmulet : OldCoin {
		displayName = "Emerald Amulet";
		icon = "Data\Icons\emeraldAmulet.paa";
		sellPrice = 250781;
		weight = 1;
		class Settings : Settings {};
	};
	class AncientLedger : OldCoin {
		displayName = "Ancient Ledger";
		icon = "Data\Icons\ancientLedger.paa";
		sellPrice = 296546;
		weight = 3;
		class Settings : Settings {};
	};
	class HandSmoothedRunestone : OldCoin {
		displayName = "Hand-Smoothed Runestone";
		icon = "Data\Icons\handSmoothedRunestone.paa";
		sellPrice = 348796;
		weight = 4;
		class Settings : Settings {};
	};
	class JeweledNecklace : OldCoin {
		displayName = "Jeweled Necklace";
		icon = "Data\Icons\jeweledNecklace.paa";
		sellPrice = 415421;
		class Settings : Settings {};
	};
	class BrokenTimepiece : OldCoin {
		displayName = "Broken Timepiece";
		icon = "Data\Icons\brokenTimepiece.paa";
		sellPrice = 385594;
		weight = 1;
		class Settings : Settings {};
	};
	class RestoredTimepiece : BrokenTimepiece {
		displayName = "Restored Timepiece";
		sellPrice = 580125;
		weight = 1;
		class Settings : Settings {};
	};

	// Electronics
	class Capacitor {
		displayName = "Capacitor";
		description = "A component used for crafting electronics";
		icon = "Data\Icons\capacitor.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class ElectronicCircuit : Capacitor {
		displayName = "Electronic Circuit";
		icon = "Data\Icons\electronicCircuit.paa";
		class Settings : Settings {};
	};
	class PrintedCircuitBoard : Capacitor {
		displayName = "Printed Circuit Board";
		icon = "Data\Icons\electronicCircuit.paa";
		class Settings : Settings {};
	};
	class Motherbord : Capacitor {
		displayName = "Motherbord";
		icon = "Data\Icons\motherbord.paa";
		class Settings : Settings {};
	};
	class CentralProcessingUnit : Capacitor {
		displayName = "Central Processing Unit";
		icon = "Data\Icons\cpu.paa";
		class Settings : Settings {};
	};
	class GraphicsProcessingUnit : Capacitor {
		displayName = "Graphics Processing Unit";
		icon = "Data\Icons\gpu.paa";
		weight = 2;
		class Settings : Settings {};
	};
	class RandomAccessMemory : Capacitor {
		displayName = "Random Access Memory";
		icon = "Data\Icons\ram.paa";
		class Settings : Settings {};
	};
	class SolidStateDrive : Capacitor {
		displayName = "Solid State Drive";
		icon = "Data\Icons\ssd.paa";
		class Settings : Settings {};
	};
	class PowerSupplyUnit : Capacitor {
		displayName = "Power Supply Unit";
		icon = "Data\Icons\psu.paa";
		weight = 2;
		class Settings : Settings {};
	};
	class Laptop : Capacitor {
		displayName = "Laptop";
		description = "An electronic sold at Altis Electronics";
		icon = "Data\Icons\laptop.paa";
		sellPrice = 279188;
		weight = 10;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
	};
	class Desktop : Laptop {
		displayName = "Desktop";
		icon = "Data\Icons\desktop.paa";
		sellPrice = 563438;
		weight = 15;
		class Settings : Settings {};
	};
	class MiningRig : Laptop {
		displayName = "Mining Rig";
		icon = "Data\Icons\miningRig.paa";
		sellPrice = 3179813;
		weight = 64;
		class Settings : Settings {};
	};
	class SignalJammer : Laptop {
		displayName = "Signal Jammer";
		icon = "Data\Icons\signalJammer.paa";
		weight = 1;
		sellPrice = 55150;
		class Settings : Settings {};
	};
	class HackingDevice : Laptop {
		displayName = "Hacking Device";
		description = "A tool used to gain access to Major Crime sites";
		icon = "Data\Icons\hackingDevice.paa";
		buyPrice = 475000;
		sellPrice = 237500;
		weight = 1;
		class Settings : Settings {};
		class Deconstruction {
			time = 100;
			workbench = true;
			blueprints[] = { { "Electronics", "B_HackingDevice" } };
			materials[] = { 
				{"ElectronicCircuit", 1}
			};
		};
	};
	class PanicButton : Capacitor {
		displayName = "Panic Button";
		description = "A tool that will send an alert to the Police";
		icon = "Data\Icons\panicButton.paa";
		buyPrice = 900;
		sellPrice = 450;
		weight = 1;
		class Settings : Settings {};
		class Deconstruction {
			time = 45;
			workbench = false;
			blueprints[] = { { "Electronics", "B_PanicButton" } };
			materials[] = { 
				{"CopperWiring", 1},
				{"SilverPlate", 1},
				{"GlassPanel", 1}
			};
		};
		class Events { onUse = "[] call ULP_fnc_panic;"; };
	};

	// Vehicle Components
	class Tyre {
		displayName = "Tyre";
		description = "A component used for crafting vehicles";
		icon = "Data\Icons\tyre.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 5;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class ReinforcedTyre : Tyre {
		displayName = "Reinforced Tyre";
		weight = 10;
		class Settings : Settings {};
	};
	class LightArmourPlate : Tyre {
		displayName = "Light Armour Plate";
		icon = "Data\Icons\armourPlate.paa";
		class Settings : Settings {};
	};
	class HeavyArmourPlate : LightArmourPlate {
		displayName = "Heavy Armour Plate";
		weight = 15;
		class Settings : Settings {};
	};
	class SmallCargoBed : Tyre {
		displayName = "Small Cargo Bed";
		icon = "Data\Icons\cargoBed.paa";
		weight = 10;
		class Settings : Settings {};
	};
	class LargeCargoBed : SmallCargoBed {
		displayName = "Large Cargo Bed";
		weight = 20;
		class Settings : Settings {};
	};
	class GuidanceSystem : Tyre {
		displayName = "Guidance System";
		icon = "Data\Icons\guidanceSystem.paa";
		class Settings : Settings {};
	};
	class EngineComponent : Tyre {
		displayName = "Engine Component";
		icon = "Data\Icons\engineComponent.paa";
		weight = 20;
		class Settings : Settings {};
	};
	class BasicFlightInstruments : Tyre {
		displayName = "Basic Flight Instruments";
		icon = "Data\Icons\flightInstruments.paa";
		class Settings : Settings {};
	};
	class AdvancedFlightInstruments : BasicFlightInstruments {
		displayName = "Advanced Flight Instruments";
		class Settings : Settings {};
	};
	class VehicleParts : Tyre {
		displayName = "Vehicle Parts";
		icon = "Data\Icons\vehicleParts.paa";
		weight = 1;
		class Settings : Settings {};
	};
	class SimpleVehicleComponent : Tyre {
		displayName = "Simple Vehicle Component";
		icon = "Data\Icons\vehicleComponent.paa";
		class Settings : Settings {};
	};
	class ImprovedVehicleComponent : SimpleVehicleComponent {
		displayName = "Improved Vehicle Component";
		weight = 10;
		class Settings : Settings {};
	};
	class PerfectedVehicleComponent : SimpleVehicleComponent {
		displayName = "Perfected Vehicle Component";
		weight = 15;
		class Settings : Settings {};
	};

	// Vehicle Upgrades
	class ImprovedStorageUpgrade {
		displayName = "Improved Storage Upgrade";
		description = "Increases storage by 10%";
		icon = "Data\Icons\improvedStorageUpgrade.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 10;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class ImprovedLocksUpgrade : ImprovedStorageUpgrade {
		displayName = "Improved Locks Upgrade";
		description = "Increases the time it takes to lockpick by 50%";
		icon = "Data\Icons\improvedLocksUpgrade.paa";
		class Settings : Settings {};
	};
	class ImprovedHullUpgrade : ImprovedStorageUpgrade {
		displayName = "Improved Hull Upgrade";
		description = "Increases hull armour value by 25%";
		icon = "Data\Icons\improvedHullUpgrade.paa";
		class Settings : Settings {};
	};
	class ImprovedTyresUpgrade : ImprovedStorageUpgrade {
		displayName = "Improved Tyres Upgrade";
		description = "Increases tyre armour value by 25%";
		icon = "Data\Icons\tyre.paa";
		class Settings : Settings {};
	};
	class performanceEngineUpgrade : ImprovedStorageUpgrade {
		displayName = "Performance Engine Upgrade";
		description = "Increases acceleration by 10% & top speed by 5% [Mutually exclusive with Efficient Engine]";
		icon = "Data\Icons\improvedEngineUpgrade.paa";
		class Settings : Settings {};
	};
	class efficientEngineUpgrade : ImprovedStorageUpgrade {
		displayName = "Efficient Engine Upgrade";
		description = "Decreases fuel consumption by 30% [Mutually exclusive with Performance Engine]";
		icon = "Data\Icons\improvedEngineUpgrade.paa";
		class Settings : Settings {};
	};
	class StongCasingUpgrade : ImprovedStorageUpgrade {
		displayName = "Stong Casing Upgrade";
		description = "Increases chop process by 50%";
		icon = "Data\Icons\stongCasingUpgrade.paa";
		class Settings : Settings {};
	};
	class TrackingDeviceUpgrade : ImprovedStorageUpgrade {
		displayName = "Tracking Device Upgrade";
		description = "Updates the vehicle's location on map every 15 seconds";
		icon = "Data\Icons\trackingDeviceUpgrade.paa";
		class Settings : Settings {};
	};
	class ClonedPlatesUpgrade : ImprovedStorageUpgrade {
		displayName = "Cloned Plates Upgrade";
		description = "Randomises the vehicle's plate for ANPR systems";
		icon = "Data\Icons\clonedPlatesUpgrade.paa";
		class Settings : Settings {};
	};
};