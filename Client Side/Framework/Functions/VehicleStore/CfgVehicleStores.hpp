class CfgVehicleStores {
	class Base {
		factions[] = { "Civilian", "Dunamis" };
		licenses[] = {};
		conditions = "true";
	};

	class PoliceCar : Base {
		storeName = "Police Vehicle Store";
		factions[] = { "Police" };
		class Vehicles {
			class C_Quadbike_01_F {
				class Textures { class Black {}; };
			};
			class C_SUV_01_F { condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess"; };
			class C_Offroad_02_unarmed_F { condition = "[""Police_Main"", 4] call ULP_fnc_hasAccess"; };
			class C_Hatchback_01_sport_F { condition = "[""Police_RPU"", 1] call ULP_fnc_hasAccess"; };
			class B_GEN_Van_02_transport_F { condition = "[""Police_Main"", 4] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 1] call ULP_fnc_hasAccess } || { [""Police_COL"", 1] call ULP_fnc_hasAccess }"; };
			class B_GEN_Van_02_vehicle_F { condition = "[""Police_Main"", 4] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_RPU"", 1] call ULP_fnc_hasAccess } || { [""Police_COL"", 1] call ULP_fnc_hasAccess }"; };
			class B_LSV_01_unarmed_black_F { condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess"; };
			class O_LSV_02_unarmed_F { condition = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_Main"", 6] call ULP_fnc_hasAccess && { [""Police_SFO"", 1] call ULP_fnc_hasAccess } }"; };
			class B_MRAP_01_F { condition = "[""Police_SCO"", 2] call ULP_fnc_hasAccess"; };
		};
	};

	class PoliceAir : Base {
		storeName = "Police Vehicle Store";
		factions[] = { "Police" };
		conditions = "[""Police_NPAS"", 1] call ULP_fnc_hasAccess";
		class Vehicles {
			class C_Heli_Light_01_civil_F {};
			class B_Heli_Light_01_F {};
			class I_Heli_light_03_unarmed_F {};
			class O_Heli_Light_02_unarmed_F { condition = "[""Police_NPAS"", 2] call ULP_fnc_hasAccess"; };
			class O_Heli_Transport_04_black_F { condition = "[""Police_NPAS"", 2] call ULP_fnc_hasAccess"; };
			class O_Heli_Transport_04_covered_black_F { condition = "[""Police_NPAS"", 2] call ULP_fnc_hasAccess"; };
			class B_Heli_Transport_03_unarmed_F { 
				condition = "[""Police_NPAS"", 2] call ULP_fnc_hasAccess"; 
				class Textures { class Black {}; };
			};
			class B_Heli_Transport_01_F { condition = "[""Police_NPAS"", 3] call ULP_fnc_hasAccess"; };
			class I_Heli_light_03_F { condition = "[""Police_NPAS"", 3] call ULP_fnc_hasAccess"; };
		};
	};

	class PoliceBoat : Base {
		storeName = "Police Vehicle Store";
		factions[] = { "Police" };
		conditions = "[""Police_MPU"", 1] call ULP_fnc_hasAccess || { [""Police_Main"", 2] call ULP_fnc_hasAccess && { missionNamespace getVariable [""ULP_SRV_Crime_HMSLiberty"", false] } }";
		class Vehicles {
			class C_Boat_Civil_01_police_F {};
			class C_Boat_Transport_02_F { condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess"; };
			class B_Boat_Armed_01_minigun_F { condition = "[""Police_MPU"", 2] call ULP_fnc_hasAccess"; };
			class B_SDV_01_F { condition = "[""Police_MPU"", 2] call ULP_fnc_hasAccess"; };
		};
	};

	class MedicCar : Base {
		storeName = "Medic Vehicle Store";
		factions[] = { "Medic" };
		class Vehicles {
			class C_Van_02_medevac_F {};
			class B_GEN_Van_02_transport_F { condition = "[""Medic_Main"", 3] call ULP_fnc_hasAccess"; };
			class B_GEN_Van_02_vehicle_F { condition = "[""Medic_Main"", 3] call ULP_fnc_hasAccess"; };
			class C_SUV_01_F { condition = "[""Medic_Main"", 2] call ULP_fnc_hasAccess"; };
			class C_Hatchback_01_F {};
			class C_Hatchback_01_sport_F { condition = "[""Medic_HART"", 2] call ULP_fnc_hasAccess"; };
			class C_Offroad_02_unarmed_F { condition = "[""Medic_HART"", 1] call ULP_fnc_hasAccess"; };
		};
	};

	class MedicAir : Base {
		storeName = "Medic Vehicle Store";
		factions[] = { "Medic" };
		conditions = "[""Medic_AA"", 1] call ULP_fnc_hasAccess";
		class Vehicles {
			class C_Heli_Light_01_civil_F {};
			class B_Heli_Light_01_F { condition = "[""Medic_AA"", 2] call ULP_fnc_hasAccess"; };
			class O_Heli_Light_02_unarmed_F {};
			class O_Heli_Transport_04_medevac_black_F { condition = "[""Medic_AA"", 3] call ULP_fnc_hasAccess"; };
			class I_Heli_Transport_02_F { condition = "[""Medic_AA"", 3] call ULP_fnc_hasAccess"; };
		};
	};

	class MedicBoat : Base {
		storeName = "Medic Vehicle Store";
		factions[] = { "Medic" };
		class Vehicles {
			class C_Boat_Civil_01_F {};
			class I_C_Boat_Transport_02_F {};
		};
	};

	class HatoCar : Base {
		storeName = "HATO Vehicle Store";
		factions[] = { "Hato" };
		class Vehicles {
			class C_Offroad_01_repair_F {};
			class C_Van_02_service_F {};
			class B_Truck_01_mover_F {};
			class B_Truck_01_flatbed_F {};
			class C_SUV_01_F { condition = "[""Hato_Main"", 2] call ULP_fnc_hasAccess"; };
			class C_Hatchback_01_sport_F { condition = "[""Hato_Main"", 3] call ULP_fnc_hasAccess"; };
		};
	};

	class Dunamis : Base {
		storeName = "Dunamis Vehicle Store";
		conditions = "[] call ULP_fnc_isDunamis";
		class Vehicles {
			class C_Hatchback_01_sport_F { 
				condition = "[""Dunamis_Commando"", 1] call ULP_fnc_hasAccess"; 
				class Textures { class DMS {}; };
			};
			class C_SUV_01_F {
				condition = "[""Dunamis_Main"", 3] call ULP_fnc_hasAccess";
				class Textures { class DMS {}; };
			};
			class C_Offroad_01_F {
				class Textures { class DMS {}; };
			};
			class B_G_Offroad_01_armed_F { 
				condition = "[""Dunamis_Main"", 7] call ULP_fnc_hasAccess || { [""Dunamis_Commando"", 2] call ULP_fnc_hasAccess }"; 
				class Textures { class DMS {}; };
			};
			class C_Offroad_02_unarmed_F { 
				condition = "[""Dunamis_Main"", 2] call ULP_fnc_hasAccess"; 
				class Textures { class DMS {}; };
			};
			class O_LSV_02_unarmed_F { 
				condition = "[""Dunamis_Main"", 4] call ULP_fnc_hasAccess || { [""Dunamis_Commando"", 1] call ULP_fnc_hasAccess }"; 
				class Textures { class DMS {}; };
			};
			class O_MRAP_02_F { 
				condition = "[""Dunamis_Commando"", 2] call ULP_fnc_hasAccess"; 
				class Textures { class DMS {}; };
			};

			class B_Heli_Light_01_F {
				condition = "[""Dunamis_AirWing"", 1] call ULP_fnc_hasAccess"; 
				class Textures { class DMS {}; };
			};
			class B_Heli_Light_01_armed_F {
				condition = "[""Dunamis_AirWing"", 3] call ULP_fnc_hasAccess"; 
				class Textures { class DMS {}; };
			};
			class O_Heli_Light_02_unarmed_F {
				condition = "[""Dunamis_AirWing"", 1] call ULP_fnc_hasAccess"; 
				class Textures { class DMS {}; };
			};
			class I_Heli_light_03_unarmed_F {
				condition = "[""Dunamis_AirWing"", 2] call ULP_fnc_hasAccess"; 
				class Textures { class DMS {}; };
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
		conditions = "[""Driving""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Quadbike_01_F {};
			class C_Hatchback_01_F {};
			class C_Hatchback_01_sport_F {};
			class C_Offroad_01_F {};
			class C_Offroad_01_covered_F {};
			class C_Offroad_02_unarmed_F {};
			class C_SUV_01_F {};
			class C_Van_02_transport_F {
				class Textures { 
					class Black {}; 
					class White {}; 
					class Red {}; 
					class Orange {}; 
				};
			};
			class C_Van_02_vehicle_F {
				class Textures { 
					class Black {}; 
					class White {}; 
					class Red {}; 
					class Orange {}; 
				};
			};
		};
	};

	class Truck : Base {
		storeName = "Truck Dealership";
		conditions = "[""Trucking""] call ULP_fnc_hasLicense";
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
			class B_Truck_01_cargo_F { condition = "[""HEMTTTrucks""] call ULP_fnc_hasGroupPerk"; };
			class B_Truck_01_transport_F { condition = "[""HEMTTTrucks""] call ULP_fnc_hasGroupPerk"; };
			class B_Truck_01_covered_F { condition = "[""HEMTTTrucks""] call ULP_fnc_hasGroupPerk"; };
			class B_Truck_01_ammo_F { condition = "[""HEMTTTrucks""] call ULP_fnc_hasGroupPerk"; };
			class B_Truck_01_fuel_F { condition = "[""HEMTTTrucks""] call ULP_fnc_hasGroupPerk"; };
			class B_Truck_01_box_F { condition = "[""HEMTTTrucks""] call ULP_fnc_hasGroupPerk"; };
		};
	};

	class Air : Base {
		storeName = "Altis International";
		conditions = "[""Piloting""] call ULP_fnc_hasLicense";
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
		conditions = "[""Boating""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Scooter_Transport_01_F {};
			class C_Rubberboat {};
			class C_Boat_Civil_01_F {};
			class C_Boat_Transport_02_F {};
		};
	};

	class Taxi : Base {
		storeName = "Taxi Vehicles";
		conditions = "[""Taxi""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Hatchback_01_F {};
			class C_Hatchback_01_sport_F {};
			class C_SUV_01_F {};
		};
	};

	class News : Base {
		storeName = "News Vehicles";
		conditions = "[""News""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Van_02_transport_F {
				class Textures { class Press {}; };
			};
			class C_Van_02_vehicle_F {
				class Textures { class Press {}; };
			};
		};
	};

	class IDAP : Base {
		storeName = "IDAP Vehicles";
		conditions = "[""IDAP""] call ULP_fnc_hasLicense && { ULP_Reputation >= 500 }";
		class Vehicles {
			class C_IDAP_Offroad_01_F {};
			class C_IDAP_Offroad_02_unarmed_F {};
			class C_IDAP_Van_02_transport_F {};
			class C_IDAP_Van_02_vehicle_F {};
			class C_IDAP_Truck_02_transport_F {};
			class C_IDAP_Truck_02_F {};
			class C_IDAP_Truck_02_water_F {};
		};
	};

	class Rebel : Base {
		storeName = "Rebel Outpost";
		conditions = "[""Rebel""] call ULP_fnc_hasLicense";
		class Vehicles {
			class C_Quadbike_01_F {};
			class C_Offroad_01_F {};
			class C_Offroad_01_covered_F {};
			class C_Offroad_01_comms_F {};
			class C_Offroad_02_unarmed_F {};
			class I_C_Offroad_02_LMG_F {};
			class O_LSV_02_unarmed_F {};
			class C_Van_01_transport_F {};
			class C_Van_01_box_F {};
			class C_Van_01_fuel_F {};
			class B_Heli_Light_01_F {};
		};
	};

	class Blackmarket : Base {
		storeName = "Blackmarket";
		conditions = "[""Blackmarket""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk || [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
		class Vehicles {
			class C_Quadbike_01_F {};
			class C_Offroad_01_F {};
			class C_Offroad_01_covered_F {};
			class C_Offroad_01_comms_F {};
			class C_Offroad_02_unarmed_F {};
			class I_C_Offroad_02_LMG_F {};
			class B_CTRG_LSV_01_light_F {};
			class B_LSV_01_unarmed_black_F {};
			class O_LSV_02_unarmed_F {};
			class O_MRAP_02_F { condition = "[""Ifrits""] call ULP_fnc_hasGroupPerk"; };
			class I_MRAP_03_F {};
			class C_Van_01_transport_F {};
			class C_Van_01_box_F {};
			class C_Van_01_fuel_F {};
			class O_Truck_03_device_F {};
			class B_Heli_Light_01_F {};
			class I_Heli_light_03_unarmed_F {};
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

	class GangBase : Base {
		storeName = "Gang Base Vehicles";
		class Vehicles {
			class C_Quadbike_01_F {};
			class C_Offroad_01_F {};
			class B_G_Offroad_01_armed_F {};
			class C_Offroad_01_covered_F {};
			class C_Offroad_01_comms_F {};
			class C_Offroad_02_unarmed_F {};
			class I_C_Offroad_02_LMG_F {};
			class B_CTRG_LSV_01_light_F {};
			class B_LSV_01_unarmed_black_F {};
			class O_LSV_02_armed_black_F {};
			class O_LSV_02_unarmed_F {};
			class O_MRAP_02_F { condition = "[""Ifrits""] call ULP_fnc_hasGroupPerk"; };
			class I_MRAP_03_F {};
			class C_Van_01_transport_F {};
			class C_Van_01_box_F {};
			class C_Van_01_fuel_F {};
			class B_Heli_Light_01_F {};
			class I_Heli_light_03_unarmed_F {};
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

	class GangWars : Base {
		storeName = "Gang Wars Vehicles";
		conditions = "[""Rebel""] call ULP_fnc_hasLicense && { missionNamespace getVariable [""ULP_SRV_Setting_BaseBidsActive"", false] }";
		class Vehicles {
			class C_Quadbike_01_F {};
			class C_Offroad_01_F {};
			class C_Offroad_01_covered_F {};
			class C_Offroad_01_comms_F {};
			class C_Offroad_02_unarmed_F {};
			class I_C_Offroad_02_LMG_F {};
			class B_CTRG_LSV_01_light_F {};
			class B_LSV_01_unarmed_black_F {};
			class O_LSV_02_unarmed_F {};
			class O_MRAP_02_F { condition = "[""Ifrits""] call ULP_fnc_hasGroupPerk"; };
			class I_MRAP_03_F {};
			class B_Heli_Light_01_F {};
			class O_Heli_Transport_04_black_F {};
		};
	};
};