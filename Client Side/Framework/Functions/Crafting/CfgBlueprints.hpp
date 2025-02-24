class CfgBlueprints {
	class CraftingMaterials {
		displayName = "Crafting Materials";

		class B_Clay {
			icon = "Data\Icons\clay.paa";
			displayName = "Clay";
			description = "A material used for almost exclusively for crafting";
			materials[] = { 
				{"Sand", 1}, 
				{"Water", 1} 
			};
			item = "Clay";
			isDefault = true;
			workbench = false;
			time = 2;
		};
		class B_Plank : B_Clay {
			icon = "Data\Icons\plank.paa";
			displayName = "Plank";
			materials[] = { {"Wood", 2} };
			item = "Plank";
		};
		class B_Rubber : B_Clay {
			displayName = "Rubber";
			icon = "Data\Icons\rubber.paa";
			materials[] = { {"Wood", 3} };
			item = "Rubber";
			workbench = true;
			time = 2;
		};
		class B_RubberSheet : B_Rubber {
			displayName = "Rubber Sheet";
			icon = "Data\Icons\rubberSheet.paa";
			materials[] = { {"Rubber", 2} };
			item = "RubberSheet";
			time = 3;
		};
		class B_SteelBar : B_Rubber {
			displayName = "Steel Bar";
			icon = "Data\Icons\ingot.paa";
			materials[] = { 
				{"IronBar", 1},
				{"ProcessedOil", 1}
			};
			item = "SteelBar";
			time = 3;
		};
		class B_GlassPanel : B_Rubber {
			displayName = "Glass Panel";
			icon = "Data\Icons\glass.paa";
			materials[] = { {"Glass", 2} };
			item = "GlassPanel";
			time = 2;
		};
		class B_ReinforcedGlassPanel : B_GlassPanel {
			displayName = "Reinforced Glass Panel";
			materials[] = { 
				{"GlassPanel", 2},
				{"SteelPlate", 1},
				{"FlawlessDiamond", 1}
			};
			item = "ReinforcedGlassPanel";
			time = 4;
		};
		class B_CopperWiring : B_Rubber {
			displayName = "Copper Wiring";
			icon = "Data\Icons\copperWiring.paa";
			materials[] = { 
				{"CopperBar", 2},
				{"Rubber", 1}
			};
			item = "CopperWiring";
			time = 3;
		};
		class B_CopperPlate : B_Rubber {
			displayName = "Copper Plate";
			icon = "Data\Icons\metalPlate.paa";
			materials[] = { {"CopperBar", 2} };
			item = "CopperPlate";
			time = 2;
		};
		class B_IronPlate : B_CopperPlate {
			displayName = "Iron Plate";
			materials[] = { {"IronBar", 2} };
			item = "IronPlate";
		};
		class B_SilverPlate : B_CopperPlate {
			displayName = "Silver Plate";
			materials[] = { {"SilverBar", 2} };
			item = "SilverPlate";
		};
		class B_SteelPlate : B_CopperPlate {
			displayName = "Steel Plate";
			materials[] = { {"SteelBar", 2} };
			item = "SteelPlate";
		};
		class B_PackedOil : B_Clay {
			displayName = "Packed Oil";
			icon = "Data\Icons\oil.paa";
			materials[] = { {"ProcessedOil", 4} };
			item = "PackedOil";
			time = 4;
		};
		class B_DiamondDrillBit : B_Rubber {
			displayName = "DiamondDrillBit";
			icon = "Data\Icons\drillBit.paa";
			materials[] = { 
				{"SilverBar", 2},
				{"FlawlessDiamond", 1}
			};
			item = "DiamondDrillBit";
			time = 10;
		};
		class B_ExplosiveMaterials : B_Rubber {
			displayName = "Explosive Materials";
			icon = "Data\Icons\explosiveMaterials.paa";
			materials[] = { 
				{"CopperWiring", 32},
				{"IronPlate", 12},
				{"UraniumBar", 8},
				{"SteelPlate", 4},
				{"PackedOil", 4}
			};
			item = "ExplosiveMaterials";
			isDefault = false;
			time = 90;
		};
	};

	class HandheldTools {
		displayName = "Handheld Tools";

		class B_Toolbox {
			icon = "Data\Icons\toolbox.paa";
			displayName = "Toolbox";
			description = "A box of tools used to deconstruct items into their core components";
			materials[] = { 
				{"IronBar", 3},
				{"Wood", 1}
			};
			item = "Toolbox";
			isDefault = true;
			workbench = false;
			time = 10;
		};
		class B_Lockpick : B_Toolbox {
			icon = "Data\Icons\lockpick.paa";
			displayName = "Lockpick";
			description = "A tool used to pick the locks of vehicles and handcuffs";
			materials[] = { {"IronBar", 2} };
			item = "Lockpick";
			time = 2;
		};
		class B_SnapGun : B_Toolbox {
			icon = "Data\Icons\snapGun.paa";
			displayName = "Snap Gun";
			description = "A tool used to pick the locks of vehicles and handcuffs, but doesn't break";
			materials[] = { 
				{"SteelBar", 2},
				{"FlawlessDiamond", 1} 
			};
			item = "SnapGun";
			isDefault = false;
			workbench = true;
			time = 15;
		};
		class B_Lighter : B_Lockpick {
			icon = "Data\Icons\lighter.paa";
			displayName = "Lighter";
			description = "A simple lighter used to create fire";
			materials[] = { 
				{"IronBar", 2}, 
				{"ProcessedOil", 1} 
			};
			item = "Lighter";
			time = 2;
		};
		class B_FuelCan : B_Lockpick {
			icon = "Data\Icons\fuelCan.paa";
			displayName = "Fuel Can";
			description = "This can be used to refuel your vehicle anywhere";
			materials[] = { 
				{"IronPlate", 1}, 
				{"PackedOil", 1} 
			};
			item = "fuelCan";
			time = 4;
		};
		class B_Pickaxe : B_Lockpick {
			icon = "Data\Icons\pickaxe.paa";
			displayName = "Pickaxe";
			description = "A tool used for mining ores";
			materials[] = { 
				{"IronBar", 3}, 
				{"Wood", 2} 
			};
			item = "Pickaxe";
			time = 3;
		};
		class B_LumberAxe : B_Pickaxe {
			icon = "Data\Icons\lumberAxe.paa";
			displayName = "Lumber Axe";
			description = "A tool used for chopping trees";
			item = "LumberAxe";
		};
		class B_Shovel : B_Pickaxe {
			icon = "Data\Icons\shovel.paa";
			displayName = "Shovel";
			description = "A tool used for gathering sand";
			materials[] = { 
				{"IronBar", 1}, 
				{"Wood", 2} 
			};
			item = "Shovel";
		};
		class B_Extractor : B_Pickaxe {
			icon = "Data\Icons\extractor.paa";
			displayName = "Extractor";
			description = "A tool used for extracting oil";
			materials[] = { 
				{"SteelBar", 3}, 
				{"SilverBar", 2}, 
				{"Wood", 2} 
			};
			item = "Extractor";
		};
		class B_BoltCutter : B_Lockpick {
			icon = "Data\Icons\boltCutter.paa";
			displayName = "Bolt Cutter";
			description = "A tool used to cut strong locks found on properties, airdrops and shipwrecks";
			materials[] = { 
				{"SteelPlate", 4},
				{"Wood", 2},
				{"Rubber", 2},
				{"FlawlessDiamond", 1}
			};
			item = "BoltCutter";
			isDefault = false;
			workbench = true;
			time = 45;
		};
		class B_IndustrialDrill : B_BoltCutter {
			icon = "Data\Icons\industrialDrill.paa";
			displayName = "Industrial Drill";
			materials[] = { 
				{"SteelPlate", 8},
				{"ProcessedOil", 4}, 
				{"DiamondDrillBit", 1}
			};
			item = "IndustrialDrill";
			time = 100;
		};
		class B_ExplosiveCharge : B_BoltCutter {
			icon = "Data\Icons\explosiveCharge.paa";
			displayName = "Explosive Charge";
			description = "A tool used to destroy fortified locks";
			materials[] = { 
				{"SteelPlate", 12},
				{"CopperWiring", 8}, 
				{"ExplosiveMaterials", 2}, 
				{"SilverPlate", 2}, 
				{"RestoredTimepiece", 1}
			};
			item = "ExplosiveCharge";
			time = 100;
		};
		class B_MakeshiftStinger : B_BoltCutter {
			icon = "Data\Icons\stinger.paa";
			displayName = "Makeshift Stinger";
			description = "A deployable strip of spikes used to puncute a vehicle's tryes";
			materials[] = { 
				{"SteelBar", 16},
				{"IronBar", 16}, 
				{"SteelPlate", 8}, 
				{"FlawlessDiamond", 4}
			};
			item = "MakeshiftStinger";
			time = 45;
		};
		class B_SurveyingEquipment : B_BoltCutter {
			icon = "Data\Icons\surveyingEquipment.paa";
			displayName = "Surveying Equipment";
			description = "Equipmented used to survay a dig site to locate artifacts";
			materials[] = { 
				{"SilverPlate", 2}, 
				{"GlassPanel", 2}, 
				{"FlawlessDiamond", 1} 
			};
			item = "SurveyingEquipment";
			time = 25;
		};
		class B_ArchaeologistsEquipment : B_SurveyingEquipment {
			icon = "Data\Icons\archaeologistsEquipment.paa";
			displayName = "Archaeologists' Equipment";
			description = "Equipment used to carefully dig up artifacts from dig sites";
			materials[] = { 
				{"IronPlate", 2}, 
				{"CopperPlate", 1}, 
				{"Pickaxe", 1}, 
				{"Shovel", 1} 
			};
			item = "ArchaeologistsEquipment";
		};
	};

	class MedicalSupplies {
		displayName = "Medical Supplies";

		class B_FieldDressing {
			icon = "Data\Icons\fieldDressing.paa";
			displayName = "Field Dressing";
			description = "A bandage best used for treating abrasions";
			materials[] = { {"Bandage", 1} };
			item = "FieldDressing";
			isDefault = true;
			workbench = false;
			time = 2;
		};
		class B_Packing : B_FieldDressing {
			icon = "Data\Icons\packingBandage.paa";
			displayName = "Packing Bandage";
			description = "A bandage best used for treating abrasions and avulsions";
			materials[] = { {"Bandage", 2} };
			item = "Packing";
		};
		class B_Elastic : B_FieldDressing {
			icon = "Data\Icons\elasticBandage.paa";
			displayName = "Elastic Bandage";
			description = "A bandage best used for treating abrasions and lacerations";
			item = "Elastic";
		};
		class B_QuickClot : B_FieldDressing {
			icon = "Data\Icons\quikClot.paa";
			displayName = "QuikClot";
			description = "A bandage best used for treating abrasions and lacersations";
			materials[] = { {"Sand", 2} };
			item = "Elastic";
		};
		class B_FirstAidKit : B_FieldDressing {
			icon = "Data\Icons\firstAidKit.paa";
			displayName = "First Aid Kit";
			description = "A collection of medical supplies used to treat minor injuries";
			materials[] = { 
				{"Painkillers", 2},
				{"Bandage", 4},
				{"BloodBag", 1}
			};
			item = "FirstAidKit";
			workbench = true;
			time = 15;
		};
		class B_MediKit : B_FirstAidKit {
			icon = "Data\Icons\mediKit.paa";
			displayName = "MediKit";
			materials[] = { 
				{"Bandage", 10},
				{"Painkillers", 5}, 
				{"BloodBag", 3},
				{"Morphine", 2}, 
				{"Epinephrine", 1} 
			};
			item = "MediKit";
		};
		class B_Defibrillator : B_FirstAidKit {
			icon = "Data\Icons\defibrillator.paa";
			displayName = "Defibrillator";
			materials[] = {
				{"CopperWiring", 4}, 
				{"SilverPlate", 2},
				{"FlawlessDiamond", 1} 
			};
			item = "Defibrillator";
			time = 20;
		};
		class B_Stretcher : B_FirstAidKit {
			icon = "Data\Icons\stretcher.paa";
			displayName = "Stretcher";
			materials[] = {
				{"Bandage", 10},
				{"SteelBar", 4},
				{"SilverPlate", 3} 
			};
			item = "Stretcher";
			time = 15;
		};
	};

	class Gems {
		displayName = "Gems";

		class B_FlawlessDiamond {
			icon = "Data\Icons\gem.paa";
			displayName = "Flawless Diamond";
			description = "A collection of gems crafted togther to become flawless";
			materials[] = { {"CutDiamond", 5} };
			item = "FlawlessDiamond";
			isDefault = true;
			workbench = true;
			time = 6;
		};
	};

	class Archaeology {
		displayName = "Archaeology";
		
		class B_CommonMap {
			icon = "Data\Icons\map.paa";
			displayName = "Common Map";
			description = "A map containing various known artifact sites across Altis";
			materials[] = { {"CommonMapFragment", 4} };
			item = "CommonMap";
			isDefault = true;
			workbench = false;
			time = 6;
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
		class B_LegendaryMap : B_CommonMap {
			icon = "Data\Icons\map.paa";
			displayName = "Legendary Map";
			materials[] = { {"LegendaryMapFragment", 4} };
			item = "LegendaryMap";
		};
		class B_CoinBundle : B_CommonMap {
			icon = "Data\Icons\coinBundle.paa";
			displayName = "Coin Bundle";
			description = "A bundle of old coints gathered from dig site";
			materials[] = { {"OldCoin", 30} };
			item = "CoinBundle";
			time = 12;
		};
		class B_RestoredPot : B_CoinBundle {
			icon = "Data\Icons\restoredPot.paa";
			displayName = "Restored Pot";
			description = "A restored artifact that can be sold for a greater profit";
			materials[] = { 
				{"Clay", 4}, 
				{"BrokenPot", 1} 
			};
			item = "RestoredPot";
			workbench = true;
		};
		class B_SharpStoneKnife : B_RestoredPot {
			icon = "Data\Icons\sharpStoneKnife.paa";
			displayName = "Sharpended Knife";
			materials[] = { 
				{"IronBar", 2}, 
				{"BluntStoneKnife", 1}
			};
			item = "SharpStoneKnife";
		};
		class B_IdentifiedSkull : B_RestoredPot {
			icon = "Data\Icons\unidentifiedSkull.paa";
			displayName = "Identified Skull";
			materials[] = { 
				{"UnidentifiedSkull", 1}, 
				{"DecryptedDrive", 1} 
			};
			item = "IdentifiedSkull";
		};
		class B_DiamondRing : B_RestoredPot {
			icon = "Data\Icons\diamondRing.paa";
			displayName = "Diamond Ring";
			materials[] = { 
				{"StrongMetalRing", 1}, 
				{"CutDiamond", 1} 
			};
			item = "DiamondRing";
		};
		class B_RestoredTimepiece : B_RestoredPot {
			icon = "Data\Icons\brokenTimepiece.paa";
			displayName = "Restored Timepiece";
			materials[] = { 
				{"BrokenTimepiece", 1}, 
				{"SilverBar", 1}, 
				{"CutDiamond", 1}
			};
			item = "RestoredTimepiece";
		};
	};

	class Electronics {
		displayName = "Electronics";

		class B_Capacitor {
			icon = "Data\Icons\capacitor.paa";
			displayName = "Capacitor";
			description = "A component used for crafting electronics";
			materials[] = { {"SilverBar", 2} };
			item = "Capacitor";
			isDefault = true;
			workbench = true;
			time = 1;
		};
		class B_ElectronicCircuit : B_Capacitor {
			icon = "Data\Icons\electronicCircuit.paa";
			displayName = "Electronic Circuit";
			materials[] = { 
				{"CopperWiring", 1}, 
				{"CopperPlate", 1}
			};
			item = "ElectronicCircuit";
		};
		class B_PrintedCircuitBoard : B_ElectronicCircuit {
			displayName = "Printed Circuit Board";
			materials[] = { 
				{"CopperBar", 1}, 
				{"RubberSheet", 1}
			};
			item = "PrintedCircuitBoard";
		};
		class B_Motherboard : B_Capacitor {
			icon = "Data\Icons\motherboard.paa";
			displayName = "Motherboard";
			materials[] = { 
				{"PrintedCircuitBoard", 3},
				{"CopperWiring", 2} 
			};
			item = "Motherboard";
			time = 5;
		};
		class B_CentralProcessingUnit : B_Motherboard {
			icon = "Data\Icons\cpu.paa";
			displayName = "Central Processing Unit";
			materials[] = { 
				{"SilverPlate", 1},
				{"CopperWiring", 1},
				{"Capacitor", 1} 
			};
			item = "CentralProcessingUnit";
			time = 3;
		};
		class B_GraphicsProcessingUnit : B_Motherboard {
			icon = "Data\Icons\gpu.paa";
			displayName = "Graphics Processing Unit";
			materials[] = { 
				{"ElectronicCircuit", 3},
				{"PrintedCircuitBoard", 2},
				{"Capacitor", 2},
				{"CopperWiring", 1}
			};
			item = "GraphicsProcessingUnit";
			time = 5;
		};
		class B_RandomAccessMemory : B_Motherboard {
			icon = "Data\Icons\ram.paa";
			displayName = "Random Access Memory";
			materials[] = { 
				{"PrintedCircuitBoard", 2},
				{"CopperBar", 1}
			};
			item = "RandomAccessMemory";
			time = 3;
		};
		class B_SolidStateDrive : B_Motherboard {
			icon = "Data\Icons\ssd.paa";
			displayName = "Solid State Drive";
			materials[] = { 
				{"PrintedCircuitBoard", 1},
				{"Capacitor", 1}
			};
			item = "SolidStateDrive";
			time = 2;
		};
		class B_PowerSupplyUnit : B_Motherboard {
			icon = "Data\Icons\psu.paa";
			displayName = "Power Supply Unit";
			materials[] = { 
				{"Capacitor", 4},
				{"PrintedCircuitBoard", 2}
			};
			item = "PowerSupplyUnit";
			time = 5;
		};
		class B_Laptop : B_Motherboard {
			icon = "Data\Icons\laptop.paa";
			displayName = "Laptop";
			description = "An electronic sold at Altis Electronics";
			materials[] = { 
				{"CentralProcessingUnit", 1},
				{"RandomAccessMemory", 1},
				{"Motherboard", 1},
				{"SolidStateDrive", 1},
				{"PowerSupplyUnit", 1}
			};
			item = "Laptop";
			time = 15;
		};
		class B_Desktop : B_Laptop {
			icon = "Data\Icons\desktop.paa";
			displayName = "Desktop";
			materials[] = { 
				{"CentralProcessingUnit", 1},
				{"RandomAccessMemory", 2},
				{"GraphicsProcessingUnit", 2},
				{"Motherboard", 1},
				{"SolidStateDrive", 2},
				{"PowerSupplyUnit", 1}
			};
			item = "Desktop";
			time = 20;
		};
		class B_MiningRig : B_Laptop {
			icon = "Data\Icons\miningRig.paa";
			displayName = "Mining Rig";
			materials[] = { 
				{"CentralProcessingUnit", 1},
				{"RandomAccessMemory", 4},
				{"GraphicsProcessingUnit", 20},
				{"Motherboard", 1},
				{"SolidStateDrive", 5},
				{"PowerSupplyUnit", 10}
			};
			item = "MiningRig";
			time = 120;
		};
		class B_SignalJammer : B_Laptop {
			icon = "Data\Icons\signalJammer.paa";
			displayName = "Signal Jammer";
			materials[] = { 
				{"ElectronicCircuit", 2},
				{"PrintedCircuitBoard", 1},
				{"GlassPanel", 1}
			};
			item = "SignalJammer";
			time = 20;
		};
		class B_HackingDevice : B_Motherboard {
			icon = "Data\Icons\hackingDevice.paa";
			displayName = "Hacking Device";
			description = "A tool used to gain access to Major Crime sites";
			materials[] = { 
				{"ElectronicCircuit", 2},
				{"PrintedCircuitBoard", 1},
				{"GlassPanel", 1},
				{"Laptop", 1}
			};
			item = "HackingDevice";
			isDefault = false;
			time = 100;
		};
		class B_PanicButton : B_HackingDevice {
			icon = "Data\Icons\panicButton.paa";
			displayName = "Panic Button";
			description = "A tool that will send an alert to the Police";
			materials[] = { 
				{"CopperWiring", 2},
				{"SilverPlate", 2},
				{"GlassPanel", 2},
				{"CopperPlate", 1}
			};
			item = "PanicButton";
			workbench = false;
			time = 45;
		};
	};
};