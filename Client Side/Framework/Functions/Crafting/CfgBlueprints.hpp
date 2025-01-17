class CfgBlueprints {
	class CraftingMaterials {
		displayName = "Crafting Materials";

		class B_Clay {
			icon = "Data\Icons\clay.paa";
			displayName = "Clay";
			description = "A simple material used for crafting.";
			materials[] = { {"Sand", 2}, {"Water", 1} };
			item = "Clay";
			isDefault = true;
			workbench = false;
			time = 2;
		};
		class B_Plank : B_Clay {
			icon = "Data\Icons\wood.paa";
			displayName = "Plank";
			description = "Processed wood.";
			materials[] = { {"Wood", 2} };
			item = "Wood";
			time = 2;
		};
		class B_Steel : B_Clay {
			icon = "Data\Icons\ingot.paa";
			displayName = "Steel Bar";
			description = "A processed metal bar.";
			materials[] = { {"IronBar", 2}, {"ProcessedOil", 1} };
			item = "SteelBar";
			workbench = true;
			time = 3;
		};
		class B_ExplosiveMaterials : B_Steel {
			icon = "Data\Icons\explosiveMaterials.paa";
			displayName = "Explosive Materials";
			description = "A collection of explosive materials that are commonly found in crafting recipies.";
			materials[] = { {"IronBar", 64}, {"ProcessedOil", 18}, {"SeizedContraband", 2} };
			item = "ExplosiveMaterials";
			isDefault = false;
			workbench = true;
			time = 90;
		};
	};

	class Tools {
		displayName = "Tools";

		class B_Toolbox {
			icon = "Data\Icons\toolbox.paa";
			displayName = "Toolbox";
			description = "A box of tools used to deconstruct items into their core components.";
			materials[] = { {"IronBar", 4} };
			item = "Toolbox";
			isDefault = true;
			workbench = false;
			time = 40;
		};
		class B_Pickaxe : B_Toolbox {
			icon = "Data\Icons\pickaxe.paa";
			displayName = "Pickaxe";
			description = "A simple tool used for harvesting minerals.";
			materials[] = { {"IronBar", 3}, {"Wood", 2} };
			item = "Pickaxe";
			isDefault = false;
		};
		class B_LumberAxe : B_Pickaxe {
			icon = "Data\Icons\lumberAxe.paa";
			displayName = "Lumber Axe";
			item = "LumberAxe";
		};
		class B_Shovel : B_Pickaxe {
			icon = "Data\Icons\shovel.paa";
			displayName = "Shovel";
			materials[] = { {"IronBar", 1}, {"Wood", 2} };
			item = "Shovel";
		};
		class B_Extractor : B_Pickaxe {
			icon = "Data\Icons\extractor.paa";
			displayName = "Extractor";
			materials[] = { {"SteelBar", 4}, {"SilverBar", 2} };
			item = "Extractor";
		};
		class B_SurveyingEquipment : B_Pickaxe {
			icon = "Data\Icons\surveyingEquipment.paa";
			displayName = "Surveying Equipment";
			description = "Equipmented used to survay a dig site to locate artifacts.";
			materials[] = { {"CopperBar", 4}, {"SilverBar", 2}, {"Glass", 1} };
			item = "SurveyingEquipment";
			workbench = true;
			time = 60;
		};
		class B_ArchaeologistsEquipment : B_SurveyingEquipment {
			icon = "Data\Icons\archaeologistsEquipment.paa";
			displayName = "Archaeologists' Equipment";
			description = "Equipment used to carefully dig up artifacts from dig sites.";
			materials[] = { {"Pickaxe", 1}, {"Shovel", 1}, {"SharpStoneKnife", 1} };
			item = "ArchaeologistsEquipment";
		};
		class B_FuelCan : B_Pickaxe {
			icon = "Data\Icons\fuelCan.paa";
			displayName = "Fuel Can";
			description = "This can be used to refuel your vehicle anywhere.";
			materials[] = { {"IronBar", 7}, {"ProcessedOil", 2} };
			item = "fuelCan";
			time = 30;
		};
		class B_Lighter : B_Pickaxe {
			icon = "Data\Icons\lighter.paa";
			displayName = "Lighter";
			description = "A simple lighter used to create fire.";
			materials[] = { {"Iron", 3}, {"ProcessedOil", 1} };
			item = "Lighter";
			time = 20;
		};
		class B_Lockpick : B_Pickaxe {
			icon = "Data\Icons\lockpick.paa";
			displayName = "Lockpick";
			description = "A tool used to pick the locks of vehicles and handcuffs.";
			materials[] = { {"Iron", 4} };
			item = "Lockpick";
			time = 15;
		};
		class B_BoltCutter : B_Pickaxe {
			icon = "Data\Icons\boltCutter.paa";
			displayName = "Bolt Cutter";
			description = "A tool used to cut strong locks found on properties, airdrops and strong doors.";
			materials[] = { {"SteelBar", 16} };
			item = "BoltCutter";
			workbench = true;
			time = 120;
		};
		class B_HackingDevice : B_BoltCutter {
			icon = "Data\Icons\hackingDevice.paa";
			displayName = "Hacking Device";
			description = "A tool used to hack various systems and malicously gain access to said systems.";
			materials[] = { {"Silver", 8}, {"CutDiamond", 4}, {"DecryptedDrive", 1} };
			item = "HackingDevice";
			time = 300;
		};
		class B_ExplosiveCharge : B_BoltCutter {
			icon = "Data\Icons\explosiveCharge.paa";
			displayName = "Explosive Charge";
			description = "A tool used to destroy fortified locks.";
			materials[] = { {"ExplosiveMaterials", 8}, {"Coal", 14}, {"CutDiamond", 6}, {"BrokenTimepiece", 1} };
			item = "ExplosiveCharge";
			time = 360;
		};
		class B_IndustrialDrill : B_ExplosiveCharge {
			icon = "Data\Icons\industrialDrill.paa";
			displayName = "Industrial Drill";
			materials[] = { {"SteelBar", 16}, {"CutDiamond", 4}, {"DrillBit", 1} };
			item = "IndustrialDrill";
		};
	};

	class PoliceEquipment {
		displayName = "Police Equipment";

		class B_PanicButton {
			icon = "Data\Icons\panicButton.paa";
			displayName = "Makeshift Stinger";
			description = "When pressed this will alert the police that you require immedate assistance.";
			materials[] = { {"CopperBar", 20}, {"SilverBar", 16}, {"Glass", 2} };
			item = "PanicButton";
			isDefault = false;
			workbench = true;
			time = 90;
		};
		class B_MakeshiftStinger : B_PanicButton {
			icon = "Data\Icons\stinger.paa";
			displayName = "Makeshift Stinger";
			description = "A deployable strip of spikes used to puncute a vehicle's tryes.";
			materials[] = { {"SteelBar", 45}, {"Ziptie", 6} };
			item = "MakeshiftStinger";
			time = 180;
		};
	};

	class MedicalEquipment {
		displayName = "Medical Equipment";

		class B_FieldDressing {
			icon = "Data\Icons\fieldDressing.paa";
			displayName = "Field Dressing";
			description = "A bandage best used for treating abrasions.";
			materials[] = { {"Bandage", 1} };
			item = "FieldDressing";
			isDefault = true;
			workbench = false;
			time = 5;
		};
		class B_Packing : B_FieldDressing {
			icon = "Data\Icons\packingBandage.paa";
			displayName = "Packing Bandage";
			description = "A bandage best used for treating abrasions and avulsions.";
			materials[] = { {"Bandage", 2} };
			item = "Packing";
		};
		class B_Elastic : B_FieldDressing {
			icon = "Data\Icons\elasticBandage.paa";
			displayName = "Elastic Bandage";
			description = "A bandage best used for treating abrasions and lacerations.";
			item = "Elastic";
		};
		class B_QuickClot : B_FieldDressing {
			icon = "Data\Icons\quikClot.paa";
			displayName = "QuikClot";
			description = "A bandage best used for treating abrasions and lacersations..";
			materials[] = { {"Bandage", 1}, {"Sand", 1} };
			item = "Elastic";
		};
		class B_FirstAidKit : B_FieldDressing {
			icon = "Data\Icons\firstAidKit.paa";
			displayName = "First Aid Kit";
			description = "A map containing various known artifact sites across Altis.";
			materials[] = { {"Painkillers", 2}, {"Bandage", 4}, {"BloodBag", 1} };
			item = "FirstAidKit";
			workbench = true;
			time = 60;
		};
		class B_MediKit : B_FirstAidKit {
			icon = "Data\Icons\mediKit.paa";
			displayName = "MediKit";
			materials[] = { {"Painkillers", 5}, {"Morphine", 2}, {"Epinephrine", 1}, {"Bandage", 10}, {"BloodBag", 3} };
			item = "MediKit";
		};
		class B_AutomatedExternalDefibrillator : B_FirstAidKit {
			icon = "Data\Icons\defibrillator.paa";
			displayName = "Automated External Defibrillator";
			materials[] = { {"SilverBar", 6}, {"CutDiamond", 2} };
			item = "AutomatedExternalDefibrillator";
			time = 120;
		};
	};

	class Electronics {
		displayName = "Electronics";

		class B_MiningRig {
			icon = "Data\Icons\miningRig.paa";
			ddisplayName = "Mining Rig";
			description = "A constructed rig for mining crypto in specialised warehouses.";
			materials[] = { {"Motherboard", 1}, {"CPU", 1}, {"GPU", 2}, {"RAM", 4}, {"PSU", 1} };
			item = "MiningRig";
			isDefault = false;
			workbench = true;
			time = 300;
		};
		class B_Motherboard : B_MiningRig {
			icon = "Data\Icons\motherboard.paa";
			displayName = "Motherboard";
			description = "A component used for crafting mining rigs.";
			materials[] = { {"Motherboard", 1} };
			item = "Motherboard";
			time = 180;
		};
		class B_CPU : B_Motherboard {
			icon = "Data\Icons\cpu.paa";
			displayName = "CPU";
			item = "CPU";
		};
		class B_GPU : B_Motherboard {
			icon = "Data\Icons\gpu.paa";
			displayName = "GPU";
			item = "GPU";
		};
		class B_RAM : B_Motherboard {
			icon = "Data\Icons\ram.paa";
			displayName = "RAM";
			item = "RAM";
		};
		class B_PSU : B_Motherboard {
			icon = "Data\Icons\psu.paa";
			displayName = "PSU";
			item = "PSU";
		};
	};

	class Archaeology {
		displayName = "Archaeology Finds";
		
		class B_CommonMap {
			icon = "Data\Icons\map.paa";
			displayName = "Common Map";
			description = "A map containing various known artifact sites across Altis.";
			materials[] = { {"CommonMapFragment", 4} };
			item = "CommonMap";
			isDefault = true;
			workbench = false;
			time = 10;
		};
		class B_UncommonMap : B_CommonMap {
			icon = "Data\Icons\map.paa";
			displayName = "Uncommon Map";
			materials[] = { {"UncommonMapFragment", 4} };
			item = "UncommonMap";
		};
		class B_RareMap : B_CommonMap {
			icon = "Data\Icons\map.paa";
			displayName = "Rare Map";
			materials[] = { {"RareMapFragment", 4} };
			item = "RareMap";
		};
		class B_CoinBundle : B_CommonMap {
			icon = "Data\Icons\coinBundle.paa";
			displayName = "Coin Bundle";
			description = "A bundle of old coints gathered from dig sites and sold at Altis Archaeologists.";
			materials[] = { {"OldCoin", 30} };
			item = "CoinBundle";
		};
		class B_RestoredPot : B_CoinBundle {
			icon = "Data\Icons\restoredPot.paa";
			displayName = "Restored Pot";
			description = "A restored artifact that can be sold at Altis Archaeologists.";
			materials[] = { {"BrokenPot", 1}, {"Clay", 3} };
			item = "RestoredPot";
			time = 20;
		};
		class B_SharpStoneKnife : B_RestoredPot {
			icon = "Data\Icons\sharpStoneKnife.paa";
			displayName = "Sharpended Knife";
			materials[] = { {"BluntStoneKnife", 1}, {"Rock", 1} };
			item = "SharpStoneKnife";
		};
		class B_IdentifiedSkull : B_RestoredPot {
			icon = "Data\Icons\unidentifiedSkull.paa";
			displayName = "Identified Skull";
			materials[] = { {"UnidentifiedSkull", 1}, {"DecryptedDrive", 1} };
			item = "IdentifiedSkull";
			time = 60;
		};
		class B_DiamondRing : B_RestoredPot {
			icon = "Data\Icons\diamondRing.paa";
			displayName = "Diamond Ring";
			materials[] = { {"StrongMetalRing", 1}, {"CutDiamond", 1} };
			item = "DiamondRing";
			time = 25;
		};
	};
};