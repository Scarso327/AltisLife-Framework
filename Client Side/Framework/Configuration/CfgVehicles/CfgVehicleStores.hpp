class CfgVehicleStores {
	class Base {
		factions[] = { "Civilian" };
		licenses[] = {};
		conditions = "true";
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
			class C_Hatchback_01_sport_F {
				class Textures {
					class PoliceWhite {};
					class PoliceBlack {};
				};
			};
			class B_GEN_Van_02_transport_F {
				class Textures {
					class PoliceWhite {};
					class PoliceUnmarked {};
				};
			};
			class B_GEN_Van_02_vehicle_F {
				class Textures {
					class PoliceWhite {};
					class PoliceUnmarked {};
				};
			};
			class B_T_LSV_01_unarmed_black_F {
				class Textures {
					class PoliceBlack {};
				};
			};
			class O_LSV_02_unarmed_F {
				class Textures {
					class PoliceBlack {};
				};
			};
			class B_MRAP_01_F {
				class Textures {
					class PoliceBlack {};
				};
			};
		};
	};

	class Medic : Base {
		storeName = "Medic Vehicle Store";
		factions[] = { "Medic" };
		class Vehicles {
			class C_SUV_01_F {
				class Textures {
					class Medic {};
				};
			};
			class C_Offroad_02_unarmed_F {
				class Textures {
					class Medic {};
				};
			};
			class C_Hatchback_01_sport_F {
				class Textures {
					class Medic {};
				};
			};
			class C_Van_02_medevac_F {
				class Textures {
					class Medic {};
				};
			};
		};
	};

	class Kart : Base {
		storeName = "Kart Dealership";
		class Vehicles {
			class C_Kart_01_Blu_F {};
			class C_Kart_01_Fuel_F {};
			class C_Kart_01_Red_F {};
			class C_Kart_01_Vrana_F {};
			class C_Kart_01_black_F {};
			class C_Kart_01_white_F {};
			class C_Kart_01_green_F {};
			class C_Kart_01_orange_F {};
			class C_Kart_01_yellow_F {};
		};
	};

	class Car : Base {
		storeName = "Car Dealership";
		class Vehicles {
			class C_Quadbike_01_F {};
			class C_Hatchback_01_F {};
			class C_Hatchback_01_sport_F {};
			class C_Offroad_01_F {};
			class C_Offroad_01_covered_F {};
			class C_Offroad_01_comms_F {};
			class C_Offroad_02_unarmed_F {};
			class C_SUV_01_F {};
			class C_Van_02_transport_F {};
			class C_Van_02_vehicle_F {};
		};
	};

	class Truck : Base {
		storeName = "Truck Dealership";
		class Vehicles {
			class C_Tractor_01_F {};
			class C_Van_01_transport_F {};
			class C_Van_01_box_F {};
			class C_Van_01_fuel_F {};
			class I_Truck_02_transport_F {};
			class I_Truck_02_covered_F {};
			class I_Truck_02_fuel_F {};
			class O_Truck_03_transport_F {};
			class O_Truck_03_covered_F {};
			class O_Truck_03_ammo_F {};
			class O_Truck_03_fuel_F {};
			class O_Truck_03_device_F {};
			class B_Truck_01_mover_F {};
			class B_Truck_01_flatbed_F {};
			class B_Truck_01_cargo_F {};
			class B_Truck_01_transport_F {};
			class B_Truck_01_covered_F {};
			class B_Truck_01_ammo_F {};
			class B_T_Truck_01_fuel_F {};
			class B_Truck_01_box_F {};
		};
	};

	class Air : Base {
		storeName = "Altis International";
		class Vehicles {
			class C_Heli_Light_01_civil_F {};
			class O_Heli_Light_02_unarmed_F {};
			class I_Heli_Transport_02_F {};
			class B_Heli_Transport_03_unarmed_F {};
			class C_Plane_Civil_01_F {};
			class C_Plane_Civil_01_racing_F {};
			class B_T_VTOL_01_infantry_F {};
			class B_T_VTOL_01_vehicle_F {};
			class I_Plane_Fighter_03_CAS_F {};
			class I_Plane_Fighter_04_F {};
			class B_Plane_CAS_01_F {};
			class B_Plane_Fighter_01_F {};
			class B_Plane_Fighter_01_Stealth_F {};
			class O_Plane_CAS_02_F {};
			class O_Plane_Fighter_02_F {};
			class O_Plane_Fighter_02_Stealth_F {};
		};
	};

	class Boat : Base {
		storeName = "Boat Dealership";
		class Vehicles {
			class C_Scooter_Transport_01_F {};
			class C_Rubberboat {};
			class C_Boat_Civil_01_F {};
			class C_Boat_Transport_02_F {};
		};
	};

	class Rebel : Base {
		storeName = "Rebel Outpost";
		class Vehicles {
			class C_Quadbike_01_F {};
			class C_Offroad_01_F {};
			class C_Offroad_01_covered_F {};
			class C_Offroad_01_comms_F {};
			class C_Offroad_02_unarmed_F {};
			class I_C_Offroad_02_LMG_F {};
			class C_Van_02_transport_F {};
			class C_Van_02_vehicle_F {};
			class O_LSV_02_unarmed_F {};
			class C_Van_01_transport_F {};
			class C_Van_01_box_F {};
			class C_Van_01_fuel_F {};
			class B_Heli_Light_01_F {};
		};
	};

	class Blackmarket : Base {
		storeName = "Blackmarket";
		class Vehicles {
			class C_Quadbike_01_F {};
			class C_Offroad_01_F {};
			class B_G_Offroad_01_armed_F {};
			class C_Offroad_01_covered_F {};
			class C_Offroad_01_comms_F {};
			class C_Offroad_02_unarmed_F {};
			class I_C_Offroad_02_LMG_F {};
			class C_Van_02_transport_F {};
			class C_Van_02_vehicle_F {};
			class B_CTRG_LSV_01_light_F {};
			class B_T_LSV_01_unarmed_black_F {};
			class O_LSV_02_unarmed_F {};
			class O_MRAP_02_F {};
			class I_MRAP_03_F {};
			class C_Van_01_transport_F {};
			class C_Van_01_box_F {};
			class C_Van_01_fuel_F {};
			class B_Heli_Light_01_F {};
			class I_Heli_light_03_unarmed_F {};
			class B_Heli_Transport_01_F {};
			class O_Heli_Transport_04_black_F {};
			class O_Heli_Transport_04_bench_black_F {};
			class O_Heli_Transport_04_covered_black_F {};
			class O_Heli_Transport_04_box_black_F {};
			class O_Heli_Transport_04_ammo_black_F {};
			class O_Heli_Transport_04_fuel_black_F {};
			class O_T_VTOL_02_infantry_F {};
			class O_T_VTOL_02_vehicle_F {};
		};
	};
};