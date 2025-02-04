class CfgFactories {
	markerType = "loc_Transmitter";
	colourDefault = "ColorEast";
	colourPowered = "ColorIndependent";
	class Altis {
		class VehicleSalvage {
			displayName = "Vehicle Salvage";
			markerName = "vehicle_salavge";
			requiredPower = 1;
			class Products {
				class FreshPeach {
					tickTime = 10;
					requiredPower = 1;
					materials[] = { { "FreshApple", 10 } };
				};
			};
		};
	};
};