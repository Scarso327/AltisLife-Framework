class CfgFactories {
	markerType = "loc_Transmitter";
	colourDefault = "ColorEast";
	colourPowered = "ColorIndependent";
	
	class Altis {
		class ComponentsFactory {
			displayName = "Components Factory";
			requiredPower = 1;
			class Products {
				// Vehicle Components
				class Tyre {
					tickTime = 15;
					materials[] = { 
						{ "RubberSheet", 2 },
						{ "SteelPlate", 1 }
					};
					blueprints[] = { "B_Tyre" };
				};
				class ReinforcedTyre {
					requiredPower = 2;
					tickTime = 30;
					materials[] = { 
						{ "RubberSheet", 4 },
						{ "SteelPlate", 3 },
						{ "FlawlessDiamond", 1 }
					};
					blueprints[] = { "B_ReinforcedTyre" };
				};
				class LightArmourPlate {
					tickTime = 15;
					materials[] = { 
						{ "SteelPlate", 8 }
					};
					blueprints[] = { "B_LightArmourPlate" };
				};
				class HeavyArmourPlate {
					requiredPower = 2;
					tickTime = 30;
					materials[] = { 
						{ "SteelPlate", 24 },
						{ "FlawlessDiamond", 4 }
					};
					blueprints[] = { "B_HeavyArmourPlate" };
				};
				class SmallCargoBed {
					tickTime = 15;
					materials[] = { 
						{ "Plank", 12 },
						{ "SteelPlate", 4 }
					};
					blueprints[] = { "B_SmallCargoBed" };
				};
				class LargeCargoBed {
					requiredPower = 2;
					tickTime = 30;
					materials[] = { 
						{ "Plank", 32 },
						{ "SteelPlate", 8 }
					};
					blueprints[] = { "B_LargeCargoBed" };
				};
				class GuidanceSystem {
					tickTime = 20;
					materials[] = { 
						{ "SilverPlate", 6 },
						{ "FlawlessDiamond", 5 },
						{ "CopperPlate", 4 },
						{ "CopperWiring", 8 }
					};
					blueprints[] = { "B_GuidanceSystem" };
				};
				class EngineComponent {
					requiredPower = 2;
					tickTime = 25;
					materials[] = { 
						{ "SteelPlate", 12 },
						{ "CopperPlate", 4 },
						{ "PackedOil", 3 }
					};
					blueprints[] = { "B_EngineComponent" };
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
					blueprints[] = { "B_BasicFlightInstruments" };
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
					blueprints[] = { "B_AdvancedFlightInstruments" };
				};
				class SimpleVehicleComponent {
					tickTime = 15;
					materials[] = { 
						{ "VehicleParts", 4 },
						{ "SteelPlate", 4 }
					};
					blueprints[] = { "B_SimpleVehicleComponent" };
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
					blueprints[] = { "B_ImprovedVehicleComponent" };
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
					blueprints[] = { "B_PerfectedVehicleComponent" };
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
						{ "signalJammer", 1 }
					};
				};
			};
		};
	};
};