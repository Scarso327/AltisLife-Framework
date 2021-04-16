class CfgBlueprints {
	defaultUnlocks[] = { 
		{ "Archaeology", "B_CommonMap" },
		{ "Archaeology", "B_UncommonMap" },
		{ "Archaeology", "B_RareMap" }  
	};

	class Tools {
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
			item = "Shovel";
		};
		class B_Extractor : B_Pickaxe {
			icon = "Data\Icons\extractor.paa";
			displayName = "Extractor";
			item = "Extractor";
		};
		class B_FishingNet : B_Pickaxe {
			icon = "Data\Icons\fishingNet.paa";
			displayName = "Fishing Net";
			description = "A net designed to be deployed from a boat and catch fish.";
			item = "FishingNet";
			time = 40;
		};
		class B_Lockpick : B_Pickaxe {
			icon = "Data\Icons\lockpick.paa";
			displayName = "Lockpick";
			description = "A tool used to pick the locks of vehicles and handcuffs.";
			item = "Lockpick";
			time = 30;
		};
		class B_BoltCutter : B_Pickaxe {
			icon = "Data\Icons\boltCutter.paa";
			displayName = "BoltCutter";
			description = "A tool used to cut strong locks found on properties, airdrops and strong doors.";
			item = "BoltCutter";
			time = 120;
		};
		class B_HackingDevice : B_Pickaxe {
			icon = "Data\Icons\hackingDevice.paa";
			displayName = "HackingDevice";
			description = "A tool used to hack various systems and malicously gain access to said systems.";
			item = "HackingDevice";
			time = 300;
		};
	};

	class MedicalEquipment {
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