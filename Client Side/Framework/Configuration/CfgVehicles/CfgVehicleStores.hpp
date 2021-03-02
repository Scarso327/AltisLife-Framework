class CfgVehicleStores {
	class Base {
		factions[] = { "Civilian" };
		licenses[] = {};
		conditions = "true";
	};

	class Civilian : Base {
		storeName = "Vehicle Store";
		class Vehicles {
			class C_SUV_01_F {};
		};
	};

	class Police : Base {
		storeName = "Police Vehicle Store";
		factions[] = { "Police" };
		class Vehicles {
			class C_SUV_01_F {
				class Textures {
					class PoliceWhite {};
					class PoliceBlack {};
					class PoliceANPR {};
					class PoliceUnmarked {};
				};
			};
		};
	};
};