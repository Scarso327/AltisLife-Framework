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
					tickTime = 15;
					materials[] = { 
						{ "RubberSheet", 2 },
						{ "SteelPlate", 1 }
					};
				};
				class ReinforcedTyre {
					requiredPower = 2;
					tickTime = 30;
					materials[] = { 
						{ "RubberSheet", 4 },
						{ "SteelPlate", 3 },
						{ "FlawlessDiamond", 1 }
					};
				};
				class LightArmourPlate {
					tickTime = 15;
					materials[] = { 
						{ "SteelPlate", 8 }
					};
				};
				class HeavyArmourPlate {
					requiredPower = 2;
					tickTime = 30;
					materials[] = { 
						{ "SteelPlate", 24 },
						{ "FlawlessDiamond", 4 }
					};
				};
				class SmallCargoBed {
					tickTime = 15;
					materials[] = { 
						{ "Plank", 12 },
						{ "SteelPlate", 4 }
					};
				};
				class LargeCargoBed {
					requiredPower = 2;
					tickTime = 30;
					materials[] = { 
						{ "Plank", 32 },
						{ "SteelPlate", 8 }
					};
				};
				class GuidanceSystem {
					tickTime = 20;
					materials[] = { 
						{ "SilverPlate", 6 },
						{ "FlawlessDiamond", 5 },
						{ "CopperPlate", 4 },
						{ "CopperWiring", 8 }
					};
				};
				class EngineComponent {
					requiredPower = 2;
					tickTime = 25;
					materials[] = { 
						{ "SteelPlate", 12 },
						{ "CopperPlate", 4 },
						{ "PackedOil", 3 }
					};
				};
				class BasicFlightInstruments {
					tickTime = 30;
					materials[] = { 
						{ "CopperWiring", 16 },
						{ "SilverPlate", 3 },
						{ "GlassPanel", 2 },
						{ "SteelPlate", 2 },
						{ "FlawlessDiamond", 1 },
						{ "GuidanceSystem", 1 }
					};
				};
				class AdvancedFlightInstruments {
					requiredPower = 2;
					tickTime = 60;
					materials[] = { 
						{ "CopperWiring", 32 },
						{ "FlawlessDiamond", 4 },
						{ "SilverPlate", 4 },
						{ "GlassPanel", 4 },
						{ "SteelPlate", 3 },
						{ "GuidanceSystem", 3 },
						{ "ReinforcedGlassPanel", 2 }
					};
				};
				class SimpleVehicleComponent {
					tickTime = 15;
					materials[] = { 
						{ "VehicleParts", 4 },
						{ "SteelPlate", 4 }
					};
				};
				class ImprovedVehicleComponent {
					requiredPower = 2;
					tickTime = 45;
					materials[] = { 
						{ "SteelPlate", 6 },
						{ "SimpleVehicleComponent", 4 },
						{ "FlawlessDiamond", 3 },
						{ "SilverPlate", 2 },
						{ "CopperPlate", 2 }
					};
				};
				class PerfectedVehicleComponent {
					requiredPower = 2;
					tickTime = 90;
					materials[] = { 
						{ "SteelPlate", 8 },
						{ "FlawlessDiamond", 6 },
						{ "SimpleVehicleComponent", 4 },
						{ "PackedOil", 4 },
						{ "SilverPlate", 3 },
						{ "CopperPlate", 3 }
					};
				};

				// Vehicle Upgrades
				class ImprovedStorageUpgrade {
					requiredPower = 2;
					tickTime = 120;
					materials[] = { 
						{ "SteelPlate", 4 },
						{ "PackedOil", 2 },
						{ "LargeCargoBed", 1 },
						{ "EngineComponent", 1 },
						{ "ReinforcedTyre", 1 }
					};
				};
				class ImprovedLocksUpgrade : ImprovedStorageUpgrade {
					materials[] = { 
						{ "SilverPlate", 4 },
						{ "ReinforcedGlassPanel", 4 },
						{ "LightArmourPlate", 2 }
					};
				};
				class ImprovedHullUpgrade : ImprovedStorageUpgrade {
					materials[] = { 
						{ "ReinforcedGlassPanel", 4 },
						{ "HeavyArmourPlate", 2 }
					};
				};
				class ImprovedTyresUpgrade : ImprovedStorageUpgrade {
					materials[] = { 
						{ "ReinforcedTyre", 4 },
						{ "SteelPlate", 4 }
					};
				};
				class PerformanceEngineUpgrade : ImprovedStorageUpgrade {
					materials[] = { 
						{ "CopperWiring", 4 },
						{ "FlawlessDiamond", 2 },
						{ "EngineComponent", 2 },
						{ "PackedOil", 2 }
					};
				};
				class EfficientEngineUpgrade : ImprovedStorageUpgrade {
					materials[] = { 
						{ "PackedOil", 4 },
						{ "SteelPlate", 4 },
						{ "EngineComponent", 2 }
					};
				};
				class StongCasingUpgrade : ImprovedStorageUpgrade {
					materials[] = { 
						{ "SteelPlate", 4 },
						{ "HeavyArmourPlate", 4 },
						{ "FlawlessDiamond", 2 }
					};
				};
				class TrackingDeviceUpgrade : ImprovedStorageUpgrade {
					materials[] = { 
						{ "CopperWiring", 5 },
						{ "SilverBar", 4 },
						{ "GuidanceSystem", 2 }
					};
				};
				class ClonedPlatesUpgrade : ImprovedStorageUpgrade {
					materials[] = { 
						{ "CopperWiring", 5 },
						{ "CopperPlate", 2 },
						{ "SignalJammer", 1 }
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
				class C_Kart_01_black_F {
					tickTime = 400;
					materials[] = { 
						{ "VehicleParts", 1 }
					};
				};
				class C_Kart_01_Blu_F : C_Kart_01_black_F {};
				class C_Kart_01_Fuel_F : C_Kart_01_black_F {};
				class C_Kart_01_green_F : C_Kart_01_black_F {};
				class C_Kart_01_orange_F : C_Kart_01_black_F {};
				class C_Kart_01_Red_F : C_Kart_01_black_F {};
				class C_Kart_01_Vrana_F : C_Kart_01_black_F {};
				class C_Kart_01_white_F : C_Kart_01_black_F {};
				class C_Kart_01_yellow_F : C_Kart_01_black_F {};
				class C_Rubberboat : C_Kart_01_black_F {};
				class C_Quadbike_01_F : C_Kart_01_black_F {};
				class C_Scooter_Transport_01_F : C_Kart_01_black_F {};

				class C_Hatchback_01_F {
					tickTime = 425;
					materials[] = { 
						{ "VehicleParts", 1 },
						{ "Tyre", 1 }
					};
				};
				class C_Tractor_01_F : C_Hatchback_01_F {};
				class C_Offroad_02_unarmed_F : C_Hatchback_01_F {
					materials[] = { 
						{ "VehicleParts", 2 },
						{ "Tyre", 1 }
					};
				};
				class C_IDAP_Offroad_02_unarmed_F : C_Offroad_02_unarmed_F {};
				class B_GEN_Offroad_01_gen_F : C_Offroad_02_unarmed_F {};
				class C_Offroad_01_F : C_Offroad_02_unarmed_F {};
				class C_IDAP_Offroad_01_F : C_Offroad_02_unarmed_F {};
				class C_Offroad_01_covered_F : C_Offroad_02_unarmed_F {};
				class C_Offroad_01_comms_F : C_Offroad_02_unarmed_F {};
				class C_Offroad_01_repair_F : C_Offroad_02_unarmed_F {};

				class C_SUV_01_F {
					tickTime = 450;
					materials[] = { 
						{ "VehicleParts", 2 },
						{ "Tyre", 1 },
						{ "GlassPanel", 1 }
					};
				};
				class C_Van_02_medevac_F : C_SUV_01_F {
					materials[] = { 
						{ "VehicleParts", 3 },
						{ "Tyre", 2 },
						{ "GlassPanel", 1 },
						{ "SmallCargoBed", 1 }
					};
				};
				class B_GEN_Van_02_transport_F : C_Van_02_medevac_F {};
				class C_Van_02_transport_F : C_Van_02_medevac_F {};
				class C_IDAP_Van_02_transport_F : C_Van_02_medevac_F {};
				class C_Van_02_vehicle_F : C_Van_02_medevac_F {};
				class C_Van_02_service_F : C_Van_02_medevac_F {};
				class C_IDAP_Van_02_vehicle_F : C_Van_02_medevac_F {};
				class C_Van_01_transport_F : C_Van_02_medevac_F {};
				class B_UAV_01_F : C_SUV_01_F {
					requiredPower = 2;
					materials[] = { 
						{ "VehicleParts", 3 }
					};
				};
				class C_UAV_06_medical_F : B_UAV_01_F {};

				class C_Van_01_box_F {
					tickTime = 475;
					materials[] = { 
						{ "VehicleParts", 4 },
						{ "Tyre", 2 },
						{ "GlassPanel", 1 },
						{ "SmallCargoBed", 1 }
					};
				};
				class C_Van_01_fuel_F : C_Van_01_box_F {};
				class C_Boat_Civil_01_F : C_Van_01_box_F {
					materials[] = { 
						{ "VehicleParts", 4 }
					};
				};
				class C_Boat_Civil_01_police_F : C_Boat_Civil_01_F {};
				class C_Hatchback_01_sport_F : C_Van_01_box_F {
					materials[] = { 
						{ "VehicleParts", 4 },
						{ "GlassPanel", 1 },
						{ "EngineComponent", 1 }
					};
				};
				class C_Boat_Transport_02_F : C_Van_01_box_F {
					materials[] = { 
						{ "VehicleParts", 4 },
						{ "GuidanceSystem", 1 }
					};
				};
				class B_SDV_01_F : C_Boat_Transport_02_F {
					requiredPower = 2;
				};

				class I_Truck_02_transport_F {
					tickTime = 500;
					materials[] = { 
						{ "VehicleParts", 5 },
						{ "Tyre", 41 },
						{ "GlassPanel", 2 },
						{ "SmallCargoBed", 1 }
					};
				};
				class C_IDAP_Truck_02_transport_F : I_Truck_02_transport_F {};
				class C_IDAP_Truck_02_water_F : I_Truck_02_transport_F {};
				class C_IDAP_Truck_02_F : I_Truck_02_transport_F {};
				class C_Heli_Light_01_civil_F : I_Truck_02_transport_F {
					materials[] = { 
						{ "VehicleParts", 6 },
						{ "BasicFlightInstruments", 2 }
					};
				};
				class B_Truck_01_mover_F : I_Truck_02_transport_F {
					materials[] = { 
						{ "VehicleParts", 6 },
						{ "ReinforcedTyre", 1 },
						{ "LightArmourPlate", 1 }
					};
				};
				class B_Truck_01_flatbed_F : I_Truck_02_transport_F {
					materials[] = { 
						{ "VehicleParts", 6 },
						{ "ReinforcedTyre", 1 },
						{ "LightArmourPlate", 1 },
						{ "LargeCargoBed", 1 }
					};
				};
				class B_Heli_Light_01_F : I_Truck_02_transport_F {
					materials[] = { 
						{ "VehicleParts", 6 },
						{ "BasicFlightInstruments", 2 },
						{ "GuidanceSystem", 1 }
					};
				};
				class B_CTRG_LSV_01_light_F : I_Truck_02_transport_F {
					requiredPower = 2;
					materials[] = { 
						{ "VehicleParts", 6 },
						{ "LightArmourPlate", 1 },
						{ "ReinforcedTyre", 1 }
					};
				};
				class B_LSV_01_unarmed_black_F : B_CTRG_LSV_01_light_F {};
				class I_C_Offroad_02_LMG_F : B_CTRG_LSV_01_light_F {};
				class O_LSV_02_unarmed_F : B_CTRG_LSV_01_light_F {};
				class I_Truck_02_covered_F : I_Truck_02_transport_F {
					materials[] = { 
						{ "VehicleParts", 5 },
						{ "Tyre", 4 },
						{ "GlassPanel", 2 },
						{ "SmallCargoBed", 1 }
					};
				};
				class I_Truck_02_fuel_F : I_Truck_02_covered_F {};
				class O_Truck_03_transport_F : I_Truck_02_transport_F {
					materials[] = { 
						{ "VehicleParts", 8 },
						{ "LargeCargoBed", 1 },
						{ "HeavyArmourPlate", 1 },
						{ "ReinforcedTyre", 1 },
						{ "EngineComponent", 1 }
					};
				};
				class O_Truck_03_covered_F : O_Truck_03_transport_F {};
				class O_Truck_03_ammo_F : O_Truck_03_transport_F {};
				class O_Truck_03_repair_F : O_Truck_03_transport_F {};
				class O_Truck_03_fuel_F : O_Truck_03_transport_F {};
				class O_Truck_03_device_F : O_Truck_03_transport_F {
					requiredPower = 3;
				};
				class B_Truck_01_cargo_F : I_Truck_02_transport_F {
					materials[] = { 
						{ "VehicleParts", 8 },
						{ "LargeCargoBed", 1 },
						{ "HeavyArmourPlate", 1 }
					};
				};
				class B_Truck_01_transport_F : B_Truck_01_cargo_F {};
				class B_Truck_01_covered_F : B_Truck_01_cargo_F {};
				class B_Truck_01_ammo_F : B_Truck_01_cargo_F {};
				class B_Truck_01_fuel_F : B_Truck_01_cargo_F {};
				class B_Truck_01_box_F : B_Truck_01_cargo_F {
					requiredPower = 2;
					materials[] = { 
						{ "VehicleParts", 8 },
						{ "LargeCargoBed", 1 },
						{ "HeavyArmourPlate", 1 },
						{ "EngineComponent", 1 },
						{ "ImprovedVehicleComponent", 1 }
					};
				};
				class C_Plane_Civil_01_F : I_Truck_02_transport_F {
					materials[] = { 
						{ "VehicleParts", 9 },
						{ "GuidanceSystem", 1 },
						{ "EngineComponent", 1 }
					};
				};
				class C_Plane_Civil_01_racing_F : C_Plane_Civil_01_F {};
				class O_Heli_Light_02_unarmed_F : I_Truck_02_transport_F {
					materials[] = { 
						{ "VehicleParts", 9 },
						{ "GuidanceSystem", 1 },
						{ "EngineComponent", 1 },
						{ "BasicFlightInstruments", 1 }
					};
				};
				class I_Heli_light_03_unarmed_F : I_Truck_02_transport_F {
					requiredPower = 2;
					materials[] = { 
						{ "VehicleParts", 9 },
						{ "GuidanceSystem", 1 },
						{ "EngineComponent", 1 },
						{ "BasicFlightInstruments", 1 },
						{ "ImprovedVehicleComponent", 1 }
					};
				};

				class B_G_Offroad_01_armed_F {
					tickTime = 550;
					requiredPower = 2;
					materials[] = { 
						{ "VehicleParts", 8 },
						{ "ReinforcedTyre", 2 },
						{ "HeavyArmourPlate", 1 },
						{ "EngineComponent", 1 },
						{ "ImprovedVehicleComponent", 1 }
					};
				};
				class I_MRAP_03_F : B_G_Offroad_01_armed_F {
					requiredPower = 3;
				};
				class O_MRAP_02_F : I_MRAP_03_F {};
				class B_MRAP_01_F : I_MRAP_03_F {};
				class O_LSV_02_armed_black_F : I_MRAP_03_F {};

				class O_Heli_Transport_04_bench_black_F {
					tickTime = 600;
					requiredPower = 2;
					materials[] = { 
						{ "VehicleParts", 9 },
						{ "GuidanceSystem", 1 },
						{ "EngineComponent", 1 },
						{ "AdvancedFlightInstruments", 1 },
						{ "ImprovedVehicleComponent", 1 }
					};
				};
				class O_Heli_Transport_04_black_F : O_Heli_Transport_04_bench_black_F {};
				class O_Heli_Transport_04_medevac_black_F : O_Heli_Transport_04_bench_black_F {};
				class O_Heli_Transport_04_covered_black_F : O_Heli_Transport_04_bench_black_F {};
				class O_Heli_Transport_04_fuel_black_F : O_Heli_Transport_04_bench_black_F {};
				class O_Heli_Transport_04_box_black_F : O_Heli_Transport_04_bench_black_F {};
				class O_Heli_Transport_04_ammo_black_F : O_Heli_Transport_04_bench_black_F {};
				class I_Heli_Transport_02_F : O_Heli_Transport_04_bench_black_F {};
				class C_IDAP_Heli_Transport_02_F : O_Heli_Transport_04_bench_black_F {};
				class B_Boat_Armed_01_minigun_F : O_Heli_Transport_04_bench_black_F {
					requiredPower = 3;
					materials[] = { 
						{ "VehicleParts", 10 }
					};
				};
				class B_Heli_Transport_01_F : B_Boat_Armed_01_minigun_F {
					materials[] = { 
						{ "VehicleParts", 9 },
						{ "GuidanceSystem", 1 },
						{ "EngineComponent", 1 },
						{ "AdvancedFlightInstruments", 1 },
						{ "PerfectedVehicleComponent", 1 }
					};
				};
				class I_Heli_light_03_F : B_Boat_Armed_01_minigun_F {};

				class B_Heli_Transport_03_unarmed_F {
					tickTime = 700;
					requiredPower = 3;
					materials[] = { 
						{ "VehicleParts", 9 },
						{ "GuidanceSystem", 1 },
						{ "EngineComponent", 1 },
						{ "AdvancedFlightInstruments", 1 },
						{ "PerfectedVehicleComponent", 1 }
					};
				};
				class I_Plane_Fighter_03_CAS_F : B_Heli_Transport_03_unarmed_F {};
				class I_Plane_Fighter_04_F : B_Heli_Transport_03_unarmed_F {};
				class B_T_VTOL_01_infantry_F : B_Heli_Transport_03_unarmed_F {};
				class B_T_VTOL_01_vehicle_F : B_Heli_Transport_03_unarmed_F {};
				class O_Plane_CAS_02_F : B_Heli_Transport_03_unarmed_F {};
				class B_Plane_CAS_01_F : B_Heli_Transport_03_unarmed_F {};
				class B_Plane_Fighter_01_F : B_Heli_Transport_03_unarmed_F {};
				class O_Plane_Fighter_02_F : B_Heli_Transport_03_unarmed_F {};
				class B_Plane_Fighter_01_Stealth_F : B_Heli_Transport_03_unarmed_F {};
				class O_T_VTOL_02_infantry_F : B_Heli_Transport_03_unarmed_F {};
				class O_T_VTOL_02_vehicle_F : B_Heli_Transport_03_unarmed_F {};
				class O_Plane_Fighter_02_Stealth_F : B_Heli_Transport_03_unarmed_F {};
				class B_Heli_Attack_01_F : B_Heli_Transport_03_unarmed_F {};
				class O_Heli_Attack_02_F : B_Heli_Transport_03_unarmed_F {};
			};
		};
	};
};