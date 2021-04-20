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
			time = 15;
		};
		class B_Steel : B_Clay {
			icon = "Data\Icons\ingot.paa";
			displayName = "Steel Bar";
			description = "A processed metal bar.";
			materials[] = { {"IronBar", 2}, {"ProcessedOil", 1} };
			item = "SteelBar";
			workbench = true;
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
			time = 60;
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
		class B_FishingNet : B_Pickaxe {
			icon = "Data\Icons\fishingNet.paa";
			displayName = "Fishing Net";
			description = "A net designed to be deployed from a boat and catch fish.";
			materials[] = { {"Rope", 4} };
			item = "FishingNet";
			time = 40;
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
			time = 30;
		};
		class B_Lockpick : B_Pickaxe {
			icon = "Data\Icons\lockpick.paa";
			displayName = "Lockpick";
			description = "A tool used to pick the locks of vehicles and handcuffs.";
			materials[] = { {"Iron", 4} };
			item = "Lockpick";
			time = 30;
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

	class MedicalEquipment {
		displayName = "Medical Equipment";

		class B_FirstAidKit {
			icon = "Data\Icons\firstAidKit.paa";
			displayName = "First Aid Kit";
			description = "A map containing various known artifact sites across Altis.";
			materials[] = { {"Painkillers", 2}, {"Bandage", 4}, {"BloodBag", 1} };
			item = "FirstAidKit";
			isDefault = false;
			workbench = true;
			time = 120;
		};
		class B_MediKit : B_FirstAidKit {
			icon = "Data\Icons\mediKit.paa";
			displayName = "MediKit";
			materials[] = { {"Painkillers", 5}, {"Bandage", 10}, {"BloodBag", 3} };
			item = "MediKit";
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
			time = 90;
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
			time = 300;
		};
		class B_SharpStoneKnife : B_RestoredPot {
			icon = "Data\Icons\sharpStoneKnife.paa";
			displayName = "Sharpended Knife";
			materials[] = { {"BluntStoneKnife", 1}, {"Rock", 1} };
			item = "RestoredPot";
		};
		class B_IdentifiedSkull : B_RestoredPot {
			icon = "Data\Icons\unidentifiedSkull.paa";
			displayName = "Identified Skull";
			materials[] = { {"UnidentifiedSkull", 1}, {"DecryptedDrive", 1} };
			item = "IdentifiedSkull";
			time = 420;
		};
		class B_DiamondRing : B_RestoredPot {
			icon = "Data\Icons\diamondRing.paa";
			displayName = "Diamond Ring";
			materials[] = { {"StrongMetalRing", 1}, {"CutDiamond", 1} };
			item = "DiamondRing";
			time = 360;
		};
	};
};