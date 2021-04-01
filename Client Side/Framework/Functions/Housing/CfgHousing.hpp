class CfgHousing {
	nameLength = 32;
	houseLimit = 4;
	
	class Houses {
		// GARAGES
		class Land_i_Garage_V1_F {
			price = 1500000;
			sellMultiplier = 0.4;
			breakIn = 3 * 60;
			canShare = true;
			canSpawn = false;
			spawnPos[] = {0, 0, 0};
			disabledUpgrades[] = {};

			class Storage {
				object = "";
				position[] = {{0, 0, 0}, 0};
			};
			class Garage {
				spawnPos[] = {{0, 0, 0}, 0};
			};
		};
		class Land_i_Garage_V2_F : Land_i_Garage_V1_F {};

		// HOUSES
		class BaseHouse {
			sellMultiplier = 0.4;
			breakIn = 5 * 60;
			canShare = true;
			canSpawn = true;
			disabledUpgrades[] = {};
		};

		class Land_Slub_House02_F : BaseHouse {
			price = 0;
			spawnPos[] = {1.46924,0.984863,-1.0281};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{-0.611529,0,0}, 0};
			};
		};

		class Land_i_Stone_Shed_V1_F : BaseHouse {
			price = 0;
			spawnPos[] = {-0.27002,2.06299,-0.360504};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{0,0,-0.641529}, 0};
			};
		};
		class Land_i_Stone_Shed_V2_F : Land_i_Stone_Shed_V1_F {};
		class Land_i_Stone_Shed_V3_F : Land_i_Stone_Shed_V1_F {};

		class Land_i_Stone_HouseSmall_V1_F : BaseHouse {
			price = 0;
			spawnPos[] = {-0.0405273,1.93848,-0.201251};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{0,0,-0.695044}, 0};
			};
		};
		class Land_i_Stone_HouseSmall_V2_F : Land_i_Stone_HouseSmall_V1_F {};
		class Land_i_Stone_HouseSmall_V3_F : Land_i_Stone_HouseSmall_V1_F {};

		class Land_i_Addon_02_V1_F : BaseHouse {
			price = 0;
			spawnPos[] = {-5.35059,2.10596,-1.86095};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{0.00390625,0.0185547,-1.62997}, 0};
			};
		};

		class Land_i_House_Small_02_V1_F : BaseHouse {
			price = 0;
			spawnPos[] = {-1.74902,-0.0693359,-1.12361};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{-0.000976563,-0.80283}, 0};
			};
		};
		class Land_i_House_Small_02_V2_F : Land_i_House_Small_02_V1_F {};
		class Land_i_House_Small_02_V3_F : Land_i_House_Small_02_V1_F {};

		class Land_i_House_Small_01_V1_F : BaseHouse {
			price = 0;
			spawnPos[] = {3.16748,1.87109,-1.34062};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{0,-0.000488281,-0.681095}, 0};
			};
		};
		class Land_i_House_Small_01_V2_F : Land_i_House_Small_01_V1_F {};
		class Land_i_House_Small_01_V3_F : Land_i_House_Small_01_V1_F {};

		class Land_i_House_Small_03_V1_F : BaseHouse {
			price = 0;
			spawnPos[] = {-3.26807,0.971191,-0.314249};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{0,0,-0.701529}, 0};
			};
		};

		class Land_i_House_Big_02_V1_F : BaseHouse {
			price = 0;
			spawnPos[] = {0.441895,2.39648,-2.88253};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{0,0,-4.04812}, 0};
			};
		};
		class Land_i_House_Big_02_V2_F : Land_i_House_Big_02_V1_F {};
		class Land_i_House_Big_02_V3_F : Land_i_House_Big_02_V1_F {};

		class Land_i_House_Big_01_V1_F : BaseHouse {
			price = 0;
			spawnPos[] = {-1.92041,-1.29736,-3.06494};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{0,0,-4.30153}, 0};
			};
		};
		class Land_i_House_Big_01_V2_F : Land_i_House_Big_01_V1_F {};
		class Land_i_House_Big_01_V3_F : Land_i_House_Big_01_V1_F {};

		class Land_LightHouse_F : BaseHouse {
			price = 0;
			spawnPos[] = {0.598633,-2.52002,-11.5156};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{0,0,-0.381529}, 0};
			};
		};

		class C_Boat_Civil_04_F : BaseHouse {
			price = 0;
			canShare = false;
			spawnPos[] = {-0.215332,-7.34668,-7.68176};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{0,0,-4.93714}, 0};
			};
		};

		// WAREHOUSES
		class Land_i_Shed_Ind_F : BaseHouse {
			price = 0;
			breakIn = 10 * 60;
			spawnPos[] = {5.79297,3.77734,-1.68373};
			
			class Storage {
				object = "Land_Cargo20_white_F";
				position[] = {{0,0,-1.47017}, 0};
			};
			class Garage {
				spawnPos[] = {{0, 0, 0}, 0};
			};
		};
	};

	class Upgrades {};
};