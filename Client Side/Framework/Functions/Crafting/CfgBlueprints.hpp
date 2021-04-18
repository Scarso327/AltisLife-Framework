class CfgBlueprints {
	class Tools {
		displayName = "Tools";

		class B_Pickaxe {
			icon = "Data\Icons\pickaxe.paa";
			displayName = "Pickaxe";
			description = "A simple tool used for harvesting minerals.";
			materials[] = { {"IronBar", 3}, {"Wood", 2} };
			item = "Pickaxe";
			isDefault = false;
			workbench = false;
			time = 60;
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
			materials[] = { {"IronBar", 5}, {"SilverBar", 2} };
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
			materials[] = { {"Iron", 16} };
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
			materials[] = { {"IronBar", 16}, {"CutDiamond", 4}, {"DrillBit", 1} };
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
		displayName = "Archaeology";
		
		class B_CommonMap {
			icon = "Data\Icons\map.paa";
			displayName = "Common Map";
			description = "A map containing various known artifact sites across Altis.";
			materials[] = { {"CommonMapFragment", 4} };
			item = "CommonMap";
			isDefault = true;
			workbench = false;
			time = 45;
		};
		class B_UncommonMap : B_CommonMap {
			icon = "Data\Icons\map.paa";
			displayName = "Uncommon Map";
			materials[] = { {"UncommonMapFragment", 4} };
			item = "UncommonMap";
			workbench = false;
		};
		class B_RareMap : B_CommonMap {
			icon = "Data\Icons\map.paa";
			displayName = "Rare Map";
			materials[] = { {"RareMapFragment", 4} };
			item = "RareMap";
			workbench = false;
		};
	};
};