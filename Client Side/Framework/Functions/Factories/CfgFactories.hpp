class CfgFactories {
	markerType = "loc_Transmitter";
	colourDefault = "ColorEast";
	colourPowered = "ColorIndependent";

	class Altis {
		class ComponentsFactory {
			displayName = "Components Factory";
			requiredPower = 1;
			class Events {
				onOpen = "[""DialogFactory"", _this] call ULP_UI_fnc_createDialog";
				onStart = "_this call ULP_SRV_fnc_startComponentFactory";
				onTick = "_this call ULP_SRV_fnc_tickComponentFactory";
				preTickCondition = "true";
			};
			class Products {
				// Vehicle Components
				class Tyre {
					tickTime = 5;
					materials[] = { 
						{ "RubberSheet", 2 },
						{ "IronBar", 2 }
					};
				};
				class ReinforcedTyre {
					requiredPower = 2;
					tickTime = 10;
					materials[] = { 
						{ "Tyre", 4 },
						{ "SteelPlate", 1 }
					};
				};
				class LightArmourPlate {
					tickTime = 15;
					materials[] = { { "IronPlate", 2 } };
				};
				class HeavyArmourPlate {
					requiredPower = 2;
					tickTime = 20;
					materials[] = { 
						{ "LightArmourPlate", 1 },
						{ "FlawlessDiamond", 1 },
						{ "SteelPlate", 2 },
					};
				};
				class SmallCargoBed {
					tickTime = 10;
					materials[] = { 
						{ "Plank", 8 },
						{ "IronPlate", 2 }
					};
				};
				class LargeCargoBed {
					requiredPower = 2;
					tickTime = 20;
					materials[] = { 
						{ "SmallCargoBed", 2 },
						{ "SteelPlate", 1 }
					};
				};
				class GuidanceSystem {
					tickTime = 20;
					materials[] = { 
						{ "SilverPlate", 1 },
						{ "FlawlessDiamond", 4 },
						{ "ElectronicCircuit", 2 }
					};
				};
				class EngineComponent {
					requiredPower = 2;
					tickTime = 25;
					materials[] = { 
						{ "SteelPlate", 2 },
						{ "CopperPlate", 1 },
						{ "PackedOil", 4 }
					};
				};
				class BasicFlightInstruments {
					tickTime = 30;
					materials[] = { 
						{ "CentralProcessingUnit", 8 },
						{ "GlassPanel", 2 },
						{ "GuidanceSystem", 1 }
					};
				};
				class AdvancedFlightInstruments {
					requiredPower = 2;
					tickTime = 60;
					materials[] = { 
						{ "BasicFlightInstruments", 1 },
						{ "FlawlessDiamond", 6 },
						{ "SilverPlate", 2 },
						{ "GlassPanel", 4 },
						{ "GuidanceSystem", 1 }
					};
				};
				class SimpleVehicleComponent {
					tickTime = 10;
					materials[] = { 
						{ "VehicleParts", 4 },
						{ "CopperPlate", 4 }
					};
				};
				class ImprovedVehicleComponent {
					requiredPower = 2;
					tickTime = 20;
					materials[] = { 
						{ "SimpleVehicleComponent", 4 },
						{ "FlawlessDiamond", 2 },
						{ "SilverPlate", 2 }
					};
				};
				class PerfectedVehicleComponent {
					requiredPower = 3;
					tickTime = 30;
					materials[] = { 
						{ "ImprovedVehicleComponent", 4 },
						{ "FlawlessDiamond", 8 },
						{ "PackedOil", 4 },
						{ "SteelPlate", 2 }
					};
				};

				// Vehicle Upgrades
				class ImprovedStorageUpgrade {
					requiredPower = 2;
					tickTime = 120;
					materials[] = { 
						{ "SteelPlate", 4 },
						{ "PackedOil", 4 },
						{ "LargeCargoBed", 1 },
						{ "EngineComponent", 1 }
					};
				};
				class ImprovedLocksUpgrade : ImprovedStorageUpgrade {
					requiredPower = 1;
					materials[] = { 
						{ "SilverPlate", 2 },
						{ "LightArmourPlate", 2 },
						{ "FlawlessDiamond", 1 }
					};
				};
				class ImprovedHullUpgrade : ImprovedStorageUpgrade {
					requiredPower = 1;
					materials[] = { { "HeavyArmourPlate", 2 } };
				};
				class ImprovedTyresUpgrade : ImprovedStorageUpgrade {
					requiredPower = 1;
					materials[] = { { "ReinforcedTyre", 4 } };
				};
				class EfficientEngineUpgrade : ImprovedStorageUpgrade {
					requiredPower = 1;
					materials[] = { 
						{ "PackedOil", 4 },
						{ "EngineComponent", 1 }
					};
				};
				class StongCasingUpgrade : ImprovedStorageUpgrade {
					materials[] = { 
						{ "ReinforcedGlassPanel", 4 },
						{ "HeavyArmourPlate", 4 }
					};
				};
				class TrackingDeviceUpgrade : ImprovedStorageUpgrade {
					requiredPower = 1;
					materials[] = { { "GuidanceSystem", 1 } };
				};
				class ClonedPlatesUpgrade : ImprovedStorageUpgrade {
					requiredPower = 1;
					materials[] = { 
						{ "CopperPlate", 1 },
						{ "SignalJammer", 1 }
					};
				};

				// Housing Upgrades
				class PersonalAlarmUpgrade {
					requiredPower = 1;
					tickTime = 120;
					materials[] = { 
						{ "ElectronicCircuit", 2 },
						{ "ReinforcedGlassPanel", 1 },
						{ "Laptop", 1 }
					};
				};
				class CentralAlarmUpgrade : PersonalAlarmUpgrade {
					requiredPower = 2;
					materials[] = { 
						{ "PersonalAlarmUpgrade", 1 },
						{ "FlawlessDiamond", 2 },
						{ "PanicButton", 1 }
					};
				};
				class ImprovedDoorsUpgrade : PersonalAlarmUpgrade {
					materials[] = { { "HeavyArmourPlate", 2 } };
				};
				class ImprovedContainerUpgrade : PersonalAlarmUpgrade {
					requiredPower = 2;
					materials[] = { 
						{ "SteelPlate", 6 },
						{ "LargeCargoBed", 4 }
					};
				};
				class PersonalMailboxUpgrade : PersonalAlarmUpgrade {
					materials[] = { 
						{ "FlawlessDiamond", 4 },
						{ "Desktop", 1 }
					};
				};
			};
		};

		class WeaponsFactory {
			displayName = "Weapons Factory";
			requiredPower = 1;
			class Events {
				onOpen = "[""DialogFactory"", _this] call ULP_UI_fnc_createDialog";
				onStart = "_this call ULP_SRV_fnc_startComponentFactory";
				onTick = "_this call ULP_SRV_fnc_tickComponentFactory";
				preTickCondition = "true";
			};
			class Products {
				// Weapons
				class LMG_Zafir_F {
					tickTime = 180;
					requiredPower = 2;
					materials[] = { 
						{ "SteelPlate", 12 },
						{ "FlawlessDiamond", 2 },
						{ "WeaponParts", 20 },
						{ "DecryptedDrive", 1 },
					};
				};
				class srifle_DMR_04_Tan_F {
					tickTime = 180;
					requiredPower = 2;
					materials[] = { 
						{ "SteelPlate", 8 },
						{ "CopperPlate", 12 },
						{ "RubberSheet", 24 },
						{ "FlawlessDiamond", 6 },
						{ "WeaponParts", 16 }
					};
				};
				class srifle_DMR_02_sniper_F {
					tickTime = 180;
					requiredPower = 2;
					materials[] = { 
						{ "SteelPlate", 14 },
						{ "SilverPlate", 16 },
						{ "CopperPlate", 6 },
						{ "FlawlessDiamond", 2 },
						{ "WeaponParts", 18 },
						{ "UnmarkedGold", 1 }
					};
				};
				class srifle_DMR_05_tan_f {
					tickTime = 180;
					requiredPower = 2;
					materials[] = { 
						{ "SteelPlate", 14 },
						{ "SilverPlate", 16 },
						{ "FlawlessDiamond", 4 },
						{ "WeaponParts", 18 },
						{ "UnmarkedGold", 1 }
					};
				};
				class srifle_LRR_F {
					tickTime = 180;
					requiredPower = 3;
					materials[] = { 
						{ "SteelPlate", 16 },
						{ "SilverPlate", 12 },
						{ "FlawlessDiamond", 4 },
						{ "WeaponParts", 26 },
						{ "UnmarkedGold", 2 }
					};
				};

				// Attachments
				class muzzle_snds_L {
					tickTime = 60;
					materials[] = { 
						{ "RubberSheet", 4 },
						{ "CopperPlate", 2 },
						{ "FlawlessDiamond", 1 }
					};
				};
				class muzzle_snds_acp {
					tickTime = 60;
					materials[] = { 
						{ "RubberSheet", 4 },
						{ "CopperPlate", 2 },
						{ "FlawlessDiamond", 1 }
					};
				};
				class muzzle_snds_M {
					tickTime = 60;
					materials[] = { 
						{ "RubberSheet", 6 },
						{ "CopperPlate", 2 },
						{ "FlawlessDiamond", 1 }
					};
				};
				class muzzle_snds_570 {
					tickTime = 60;
					materials[] = { 
						{ "RubberSheet", 4 },
						{ "CopperPlate", 2 },
						{ "FlawlessDiamond", 1 }
					};
				};
				class muzzle_snds_H {
					tickTime = 60;
					requiredPower = 2;
					materials[] = { 
						{ "RubberSheet", 12 },
						{ "CopperPlate", 3 },
						{ "SilverPlate", 1 },
						{ "FlawlessDiamond", 3 },
						{ "ProcessedOil", 2 }
					};
				};
				class muzzle_snds_B {
					tickTime = 90;
					requiredPower = 3;
					materials[] = { 
						{ "RubberSheet", 24 },
						{ "SilverPlate", 4 },
						{ "FlawlessDiamond", 6 },
						{ "ProcessedOil", 3 },
						{ "AncientAmber", 1 }
					};
				};
				class optic_KHS_old {
					tickTime = 60;
					requiredPower = 2;
					materials[] = { 
						{ "ReinforcedGlassPanel", 1 },
						{ "SteelPlate", 2 },
						{ "FlawlessDiamond", 2 },
						{ "AncientAmber", 1 }
					};
				};
				class optic_LRPS {
					tickTime = 90;
					requiredPower = 3;
					materials[] = { 
						{ "ReinforcedGlassPanel", 3 },
						{ "SteelPlate", 2 },
						{ "SilverPlate", 1 },
						{ "FlawlessDiamond", 5 },
						{ "UnmarkedGold", 1 }
					};
				};

				// Magazines
				class 150Rnd_762x54_Box {
					tickTime = 60;
					requiredPower = 2;
					materials[] = { 
						{ "PackedOil", 4 },
						{ "Coal", 16 },
						{ "Sand", 16 },
						{ "CutBloodDiamond", 4 }
					};
				};
				class 10Rnd_93x64_DMR_05_Mag {
					tickTime = 60;
					requiredPower = 2;
					materials[] = { 
						{ "PackedOil", 6 },
						{ "Coal", 12 },
						{ "Sand", 12 },
						{ "CutBloodDiamond", 6 }
					};
				};
				class 10Rnd_127x54_Mag {
					tickTime = 60;
					requiredPower = 2;
					materials[] = { 
						{ "PackedOil", 6 },
						{ "Coal", 4 },
						{ "Sand", 4 },
						{ "CutBloodDiamond", 12 },
						{ "AncientAmber", 1 }
					};
				};
				class 10Rnd_338_Mag {
					tickTime = 60;
					requiredPower = 2;
					materials[] = { 
						{ "PackedOil", 6 },
						{ "Coal", 12 },
						{ "Sand", 12 },
						{ "CutBloodDiamond", 6 }
					};
				};
				class 7Rnd_408_Mag {
					tickTime = 60;
					requiredPower = 2;
					materials[] = { 
						{ "PackedOil", 12 },
						{ "Coal", 16 },
						{ "Sand", 16 },
						{ "CutBloodDiamond", 14 },
						{ "UnmarkedGold", 1 }
					};
				};
				class 10Rnd_50BW_Mag_F {
					tickTime = 60;
					requiredPower = 3;
					materials[] = { 
						{ "PackedOil", 4 },
						{ "ExplosiveMaterials", 1 },
						{ "DecryptedDrive", 1 }
					};
				};

				// CBRN Equipment
				class U_C_CBRN_Suit_01_Blue_F {
					tickTime = 180;
					materials[] = { 
						{ "FlawlessDiamond", 4 },
						{ "Capacitor", 6 },
						{ "CopperWiring", 2 }
					};
				};
				class G_RegulatorMask_F {
					tickTime = 120;
					materials[] = { 
						{ "FlawlessDiamond", 2 },
						{ "GlassPanel", 2 },
						{ "Rubber", 2 }
					};
				};
			};
		};

		class VehicleFactory {
			displayName = "Vehicle Factory";
			requiredPower = 1;
			class Events {
				onOpen = "[""DialogVehicleFactory"", _this] call ULP_UI_fnc_createDialog";
				onStart = "_this call ULP_SRV_fnc_startVehicleFactory";
				onTick = "_this call ULP_SRV_fnc_tickVehicleFactory";
				preTickCondition = "true";
			};
			class Products {
				class I_C_Offroad_02_LMG_F {
					tickTime = 120;
					materials[] = { 
						{ "Tyre", 4 },
						{ "GlassPanel", 4 },
						{ "IronPlate", 4 },
						{ "EngineComponent", 1 },
						{ "WeaponParts", 2 },
						{ "SimpleVehicleComponent", 4 }
					};
				};
				class B_G_Offroad_01_armed_F {
					tickTime = 180;
					materials[] = { 
						{ "Tyre", 4 },
						{ "GlassPanel", 4 },
						{ "IronPlate", 6 },
						{ "EngineComponent", 1 },
						{ "WeaponParts", 4 },
						{ "ImprovedVehicleComponent", 2 }
					};
				};
				class B_CTRG_LSV_01_light_F {
					tickTime = 120;
					materials[] = { 
						{ "Tyre", 4 },
						{ "SteelBar", 4 },
						{ "EngineComponent", 1 },
						{ "SimpleVehicleComponent", 6 }
					};
				};
				class B_LSV_01_unarmed_black_F {
					tickTime = 180;
					materials[] = { 
						{ "Tyre", 4 },
						{ "LightArmourPlate", 4 },
						{ "EngineComponent", 1 },
						{ "SimpleVehicleComponent", 6 }
					};
				};
				class O_LSV_02_unarmed_F {
					tickTime = 180;
					materials[] = { 
						{ "ReinforcedTyre", 4 },
						{ "HeavyArmourPlate", 2 },
						{ "EngineComponent", 1 },
						{ "ImprovedVehicleComponent", 6 }
					};
				};
				class O_LSV_02_armed_black_F {
					tickTime = 180;
					materials[] = { 
						{ "ReinforcedTyre", 4 },
						{ "HeavyArmourPlate", 2 },
						{ "EngineComponent", 1 },
						{ "WeaponParts", 4 },
						{ "ImprovedVehicleComponent", 6 }
					};
				};
				class I_MRAP_03_F {
					tickTime = 300;
					requiredPower = 2;
					materials[] = { 
						{ "ReinforcedTyre", 4 },
						{ "ReinforcedGlassPanel", 6 },
						{ "HeavyArmourPlate", 4 },
						{ "EngineComponent", 2 },
						{ "PerfectedVehicleComponent", 8 }
					};
				};
				class O_MRAP_02_F {
					tickTime = 300;
					requiredPower = 2;
					materials[] = { 
						{ "ReinforcedTyre", 4 },
						{ "ReinforcedGlassPanel", 8 },
						{ "HeavyArmourPlate", 6 },
						{ "EngineComponent", 2 },
						{ "PerfectedVehicleComponent", 10 }
					};
				};
				class O_Truck_03_device_F {
					tickTime = 600;
					requiredPower = 3;
					materials[] = { 
						{ "ReinforcedTyre", 6 },
						{ "ReinforcedGlassPanel", 4 },
						{ "HeavyArmourPlate", 4 },
						{ "EngineComponent", 4 },
						{ "CentralProcessingUnit", 3 },
						{ "MiningRig", 2 },
						{ "PerfectedVehicleComponent", 12 }
					};
				};
				class I_Heli_light_03_unarmed_F {
					tickTime = 300;
					requiredPower = 2;
					materials[] = { 
						{ "GlassPanel", 4 },
						{ "LightArmourPlate", 2 },
						{ "EngineComponent", 2 },
						{ "AdvancedFlightInstruments", 2 },
						{ "ImprovedVehicleComponent", 8 }
					};
				};
				class O_T_VTOL_02_infantry_F {
					tickTime = 600;
					requiredPower = 3;
					materials[] = { 
						{ "ReinforcedGlassPanel", 2 },
						{ "HeavyArmourPlate", 4 },
						{ "EngineComponent", 4 },
						{ "AdvancedFlightInstruments", 4 },
						{ "PerfectedVehicleComponent", 24 }
					};
				};
				class O_T_VTOL_02_vehicle_F {
					tickTime = 600;
					requiredPower = 3;
					materials[] = { 
						{ "ReinforcedGlassPanel", 2 },
						{ "HeavyArmourPlate", 4 },
						{ "EngineComponent", 4 },
						{ "LargeCargoBed", 2 },
						{ "AdvancedFlightInstruments", 4 },
						{ "PerfectedVehicleComponent", 26 }
					};
				};
			};
		};

		class SalvageYard {
			displayName = "Salvage Yard";
			requiredPower = 1;
			class Events {
				onOpen = "_this call ULP_fnc_salvageVehicle";
				onStart = "_this call ULP_SRV_fnc_startSalvageFactory";
				onTick = "_this call ULP_SRV_fnc_tickSalvageFactory";
				preTickCondition = "private _vehicle = _this getVariable [""factory_vehicle"", objNull]; (!isNull _vehicle && { alive _vehicle } && { (count (crew _vehicle)) isEqualTo 0 })";
			};
			class Products {
				// 1 Power
				class C_Hatchback_01_F {
					tickTime = 300;
					materials[] = { { "VehicleParts", 1 }, { "Tyre", 2 }, { "GlassPanel", 1 } };
				};
				class C_Tractor_01_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 2 }, { "Tyre", 2 } }; };
				class C_Offroad_02_unarmed_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 2 }, { "Tyre", 2 }, { "GlassPanel", 1 } }; };
				class C_IDAP_Offroad_02_unarmed_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 2 }, { "Tyre", 2 }, { "GlassPanel", 1 } }; };
				class B_GEN_Offroad_01_gen_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 2 }, { "Tyre", 2 }, { "GlassPanel", 1 } }; };
				class C_Offroad_01_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 2 }, { "Tyre", 2 }, { "GlassPanel", 1 } }; };
				class C_IDAP_Offroad_01_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 2 }, { "Tyre", 2 }, { "GlassPanel", 1 } }; };
				class C_Offroad_01_covered_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 3 }, { "Tyre", 2 }, { "GlassPanel", 1 } }; };
				class C_Offroad_01_comms_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 3 }, { "Tyre", 2 }, { "GlassPanel", 1 } }; };
				class C_Offroad_01_repair_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 3 }, { "Tyre", 2 }, { "GlassPanel", 1 } }; };
				class C_SUV_01_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 3 }, { "Tyre", 2 }, { "GlassPanel", 2 } }; };
				class C_Van_02_medevac_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 4 }, { "Tyre", 2 }, { "GlassPanel", 2 }, { "SmallCargoBed", 1 } }; };
				class B_GEN_Van_02_transport_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 5 }, { "Tyre", 2 }, { "GlassPanel", 2 }, { "SmallCargoBed", 1 } }; };
				class C_Van_02_transport_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 5 }, { "Tyre", 2 }, { "GlassPanel", 2 }, { "SmallCargoBed", 1 } }; };
				class C_IDAP_Van_02_transport_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 5 }, { "Tyre", 2 }, { "GlassPanel", 2 }, { "SmallCargoBed", 1 } }; };
				class C_Van_02_vehicle_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 6 }, { "Tyre", 2 }, { "GlassPanel", 2 }, { "SmallCargoBed", 1 } }; };
				class C_Van_02_service_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 6 }, { "Tyre", 2 }, { "GlassPanel", 2 }, { "SmallCargoBed", 1 } }; };
				class C_IDAP_Van_02_vehicle_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 6 }, { "Tyre", 2 }, { "GlassPanel", 2 }, { "SmallCargoBed", 1 } }; };
				class C_Van_01_transport_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 7 }, { "Tyre", 2 }, { "GlassPanel", 2 }, { "SmallCargoBed", 1 } }; };
				class C_Van_01_box_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 10 }, { "Tyre", 2 }, { "GlassPanel", 2 }, { "SmallCargoBed", 1 } }; };
				class C_Boat_Civil_01_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 10 } }; };
				class C_Boat_Civil_01_police_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 10 } }; };
				class C_Van_01_fuel_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 13 }, { "Tyre", 2 }, { "GlassPanel", 2 }, { "SmallCargoBed", 1 } }; };
				class C_Hatchback_01_sport_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 18 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "EngineComponent", 1 } }; };
				class C_Boat_Transport_02_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 20 }, { "SmallCargoBed", 1 } }; };
				class I_Truck_02_transport_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 28 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LargeCargoBed", 1 } }; };
				class C_IDAP_Truck_02_transport_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 28 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LargeCargoBed", 1 } }; };
				class C_IDAP_Truck_02_water_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 31 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LargeCargoBed", 1 } }; };
				class C_Heli_Light_01_civil_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 32 }, { "GlassPanel", 4 }, { "BasicFlightInstruments", 1 }, { "EngineComponent", 1 } }; };
				class B_Truck_01_mover_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 32 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LightArmourPlate", 2 }, { "LargeCargoBed", 1 } }; };
				class B_Truck_01_flatbed_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 33 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LightArmourPlate", 2 }, { "LargeCargoBed", 1 } }; };
				class C_IDAP_Truck_02_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 37 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LargeCargoBed", 1 } }; };
				class B_Heli_Light_01_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 39 }, { "GlassPanel", 4 }, { "BasicFlightInstruments", 1 }, { "EngineComponent", 1 } }; };
				class I_Truck_02_covered_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 40 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LargeCargoBed", 1 } }; };
				class I_Truck_02_fuel_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 50 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LargeCargoBed", 1 } }; };
				class C_Plane_Civil_01_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 84 }, { "GlassPanel", 6 }, { "BasicFlightInstruments", 2 }, { "GuidanceSystem", 1 } }; };
				class C_Plane_Civil_01_racing_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 92 }, { "GlassPanel", 6 }, { "BasicFlightInstruments", 2 }, { "GuidanceSystem", 1 } }; };
				class O_Heli_Light_02_unarmed_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 123 }, { "ReinforcedGlassPanel", 4 }, { "BasicFlightInstruments", 1 }, { "EngineComponent", 1 }, { "HeavyArmourPlate", 2 } }; };
				class O_Truck_03_transport_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 57 }, { "ReinforcedGlassPanel", 4 }, { "HeavyArmourPlate", 2 }, { "ReinforcedTyre", 4 }, { "EngineComponent", 1 }, { "LargeCargoBed", 1 } }; };
				class O_Truck_03_covered_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 66 }, { "ReinforcedGlassPanel", 4 }, { "HeavyArmourPlate", 2 }, { "ReinforcedTyre", 4 }, { "EngineComponent", 1 }, { "LargeCargoBed", 1 } }; };
				class B_Truck_01_cargo_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 78 }, { "GlassPanel", 2 }, { "HeavyArmourPlate", 2 }, { "ReinforcedTyre", 4 }, { "EngineComponent", 1 }, { "LargeCargoBed", 1 } }; };
				class O_Truck_03_ammo_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 85 }, { "ReinforcedGlassPanel", 4 }, { "HeavyArmourPlate", 2 }, { "ReinforcedTyre", 4 }, { "EngineComponent", 1 }, { "LargeCargoBed", 1 } }; };
				class O_Truck_03_repair_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 93 }, { "ReinforcedGlassPanel", 4 }, { "HeavyArmourPlate", 2 }, { "ReinforcedTyre", 4 }, { "EngineComponent", 1 }, { "LargeCargoBed", 1 } }; };
				class O_Truck_03_fuel_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 100 }, { "ReinforcedGlassPanel", 4 }, { "HeavyArmourPlate", 2 }, { "ReinforcedTyre", 4 }, { "EngineComponent", 1 }, { "LargeCargoBed", 1 } }; };
				class B_Truck_01_transport_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 106 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LightArmourPlate", 2 }, { "LargeCargoBed", 1 } }; };
				class B_Truck_01_covered_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 122 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LightArmourPlate", 2 }, { "LargeCargoBed", 1 } }; };
				class B_Truck_01_ammo_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 144 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LightArmourPlate", 2 }, { "LargeCargoBed", 1 } }; };
				class B_Truck_01_fuel_F : C_Hatchback_01_F { materials[] = { { "VehicleParts", 200 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LightArmourPlate", 2 }, { "LargeCargoBed", 2 } }; };

				// 2 Power
				class B_UAV_01_F {
					tickTime = 480;
					materials[] = { { "VehicleParts", 7 } };
				};
				class C_UAV_06_medical_F : B_UAV_01_F { materials[] = { { "VehicleParts", 7 } }; };
				class B_SDV_01_F : B_UAV_01_F { materials[] = { { "VehicleParts", 26 }, { "GuidanceSystem", 1 } }; };
				class B_CTRG_LSV_01_light_F : B_UAV_01_F { materials[] = { { "VehicleParts", 39 }, { "LightArmourPlate", 4 } }; };
				class B_LSV_01_unarmed_black_F : B_UAV_01_F { materials[] = { { "VehicleParts", 39 }, { "LightArmourPlate", 4 } }; };
				class O_LSV_02_unarmed_F : B_UAV_01_F { materials[] = { { "VehicleParts", 45 }, { "LightArmourPlate", 6 } }; };
				class I_Heli_light_03_unarmed_F : B_UAV_01_F { materials[] = { { "VehicleParts", 142 }, { "GlassPanel", 6 }, { "AdvancedFlightInstruments", 2 }, { "EngineComponent", 2 } }; };
				class I_C_Offroad_02_LMG_F : B_UAV_01_F { materials[] = { { "VehicleParts", 45 }, { "Tyre", 4 }, { "GlassPanel", 2 } }; };
				class B_G_Offroad_01_armed_F : B_UAV_01_F { materials[] = { { "VehicleParts", 285 }, { "Tyre", 4 }, { "GlassPanel", 2 }, { "LightArmourPlate", 2 } }; };
				class B_Truck_01_box_F : B_UAV_01_F { materials[] = { { "VehicleParts", 174 }, { "Tyre", 4 }, { "GlassPanel", 4 }, { "LightArmourPlate", 2 }, { "LargeCargoBed", 2 } }; };
				class O_Heli_Transport_04_bench_black_F : B_UAV_01_F { materials[] = { { "VehicleParts", 745 }, { "ReinforcedGlassPanel", 4 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 2 }, { "HeavyArmourPlate", 2 } }; };
				class O_Heli_Transport_04_black_F : B_UAV_01_F { materials[] = { { "VehicleParts", 757 }, { "ReinforcedGlassPanel", 4 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 2 }, { "HeavyArmourPlate", 2 } }; };
				class O_Heli_Transport_04_medevac_black_F : B_UAV_01_F { materials[] = { { "VehicleParts", 799 }, { "ReinforcedGlassPanel", 4 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 2 }, { "HeavyArmourPlate", 2 } }; };
				class O_Heli_Transport_04_covered_black_F : B_UAV_01_F { materials[] = { { "VehicleParts", 845 }, { "ReinforcedGlassPanel", 4 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 2 }, { "HeavyArmourPlate", 2 } }; };
				class I_Heli_Transport_02_F : B_UAV_01_F { materials[] = { { "VehicleParts", 883 }, { "GlassPanel", 10 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 2 }, { "LargeCargoBed", 2 } }; };
				class C_IDAP_Heli_Transport_02_F : B_UAV_01_F { materials[] = { { "VehicleParts", 883 }, { "GlassPanel", 10 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 2 }, { "LargeCargoBed", 2 } }; };
				class O_Heli_Transport_04_fuel_black_F : B_UAV_01_F { materials[] = { { "VehicleParts", 909 }, { "ReinforcedGlassPanel", 4 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 2 }, { "HeavyArmourPlate", 2 } }; };
				class O_Heli_Transport_04_box_black_F : B_UAV_01_F { materials[] = { { "VehicleParts", 1927 }, { "ReinforcedGlassPanel", 4 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 2 }, { "HeavyArmourPlate", 2 } }; };
				class O_Heli_Transport_04_ammo_black_F : B_UAV_01_F { materials[] = { { "VehicleParts", 1964 }, { "ReinforcedGlassPanel", 4 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 2 }, { "HeavyArmourPlate", 2 } }; };
				class O_LSV_02_armed_black_F : B_UAV_01_F { materials[] = { { "VehicleParts", 439 }, { "LightArmourPlate", 6 } }; };

				// 3 Power
				class I_MRAP_03_F {
					tickTime = 600;
					materials[] = { { "VehicleParts", 383 }, { "HeavyArmourPlate", 4 }, { "ReinforcedTyre", 4 }, { "ReinforcedGlassPanel", 6 } };
				};
				class O_Truck_03_device_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 480 }, { "ReinforcedGlassPanel", 4 }, { "HeavyArmourPlate", 2 }, { "ReinforcedTyre", 4 }, { "EngineComponent", 1 }, { "LargeCargoBed", 1 } }; };
				class O_MRAP_02_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 500 }, { "HeavyArmourPlate", 4 }, { "ReinforcedTyre", 4 }, { "ReinforcedGlassPanel", 6 } }; };
				class B_MRAP_01_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 653 }, { "HeavyArmourPlate", 4 }, { "ReinforcedTyre", 4 }, { "ReinforcedGlassPanel", 6 } }; };
				class B_Boat_Armed_01_minigun_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 957 }, { "HeavyArmourPlate", 4 }, { "EngineComponent", 2 } }; };
				class B_Heli_Transport_01_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 1297 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 2 }, { "HeavyArmourPlate", 4 } }; };
				class I_Heli_light_03_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 1563 }, { "AdvancedFlightInstruments", 2 }, { "EngineComponent", 2 }, { "LightArmourPlate", 4 } }; };
				class B_Heli_Transport_03_unarmed_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 2227 }, { "AdvancedFlightInstruments", 2 }, { "EngineComponent", 2 }, { "LightArmourPlate", 4 } }; };
				class I_Plane_Fighter_03_CAS_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 4890 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 4 }, { "GuidanceSystem", 1 } }; };
				class I_Plane_Fighter_04_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 5033 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 4 }, { "GuidanceSystem", 1 } }; };
				class O_Plane_CAS_02_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 5767 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 4 }, { "GuidanceSystem", 1 } }; };
				class B_Plane_CAS_01_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 6033 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 4 }, { "GuidanceSystem", 1 } }; };
				class B_Plane_Fighter_01_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 7033 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 4 }, { "GuidanceSystem", 1 } }; };
				class O_Plane_Fighter_02_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 7700 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 4 }, { "GuidanceSystem", 1 } }; };
				class B_Plane_Fighter_01_Stealth_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 7707 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 4 }, { "GuidanceSystem", 1 } }; };
				class O_Plane_Fighter_02_Stealth_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 8700 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 4 }, { "GuidanceSystem", 1 } }; };
				class B_Heli_Attack_01_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 9771 }, { "AdvancedFlightInstruments", 1 }, { "EngineComponent", 2 }, { "HeavyArmourPlate", 6 } }; };
				class O_Heli_Attack_02_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 14156 }, { "AdvancedFlightInstruments", 2 }, { "EngineComponent", 2 }, { "HeavyArmourPlate", 6 } }; };
				class B_T_VTOL_01_infantry_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 5033 }, { "ReinforcedGlassPanel", 14 }, { "AdvancedFlightInstruments", 4 }, { "GuidanceSystem", 2 }, { "EngineComponent", 6 }, { "LargeCargoBed", 8 } }; };
				class B_T_VTOL_01_vehicle_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 5717 }, { "ReinforcedGlassPanel", 14 }, { "AdvancedFlightInstruments", 4 }, { "GuidanceSystem", 2 }, { "EngineComponent", 6 }, { "LargeCargoBed", 8 } }; };
				class O_T_VTOL_02_infantry_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 7710 }, { "ReinforcedGlassPanel", 10 }, { "AdvancedFlightInstruments", 4 }, { "GuidanceSystem", 2 }, { "EngineComponent", 8 }, { "LargeCargoBed", 4 } }; };
				class O_T_VTOL_02_vehicle_F : I_MRAP_03_F { materials[] = { { "VehicleParts", 8369 }, { "ReinforcedGlassPanel", 10 }, { "AdvancedFlightInstruments", 4 }, { "GuidanceSystem", 2 }, { "EngineComponent", 8 }, { "LargeCargoBed", 4 } }; };
			};
		};
	};
};