class CfgHousing {
	nameLength = 32;
	houseLimit = 4;
	
	class Houses {
		// GARAGES
		class Land_i_Garage_V1_F {
			price = 3500000;
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
			price = 13000000;
			spawnPos[] = {1.46875,0.984863,-1.0281};
			
			class Storage {
				object = "Land_WoodenCrate_01_F";
				position[] = {{2.84766,2.18945,-0.980395}, 0};
			};
		};

		class Land_i_Stone_Shed_V1_F : BaseHouse {
			price = 1650000;
			spawnPos[] = {-0.27002,2.06299,-0.360504};
			
			class Storage {
				object = "Land_WoodenCrate_01_F";
				position[] = {{-1.91016,3.89063,-0.362943}, 90};
			};
		};
		class Land_i_Stone_Shed_V2_F : Land_i_Stone_Shed_V1_F {};
		class Land_i_Stone_Shed_V3_F : Land_i_Stone_Shed_V1_F {};

		class Land_i_Stone_HouseSmall_V1_F : BaseHouse {
			price = 2100000;
			spawnPos[] = {-5.47412,2.09326,-1.86095};
			
			class Storage {
				object = "Land_WoodenCrate_01_F";
				position[] = {{5.80176,4.75635,-1.79905}, 270};
			};
		};
		class Land_i_Stone_HouseSmall_V2_F : Land_i_Stone_HouseSmall_V1_F {};
		class Land_i_Stone_HouseSmall_V3_F : Land_i_Stone_HouseSmall_V1_F {};

		class Land_i_Addon_02_V1_F : BaseHouse {
			price = 1950000;
			spawnPos[] = {-0.0400391,1.93896,-0.201251};
			
			class Storage {
				object = "Land_WoodenCrate_01_F";
				position[] = {{-2.8501,2.09277,-0.20369}, 0};
			};
		};

		class Land_i_House_Small_02_V1_F : BaseHouse {
			price = 2450000;
			spawnPos[] = {-1.74902,-0.0688477,-1.12361};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{4.62061,-2.86719,-1.12596}, 90};
			};
		};
		class Land_i_House_Small_02_V2_F : Land_i_House_Small_02_V1_F {};
		class Land_i_House_Small_02_V3_F : Land_i_House_Small_02_V1_F {};

		class Land_i_House_Small_01_V1_F : BaseHouse {
			price = 2900000;
			spawnPos[] = {3.16797,1.87061,-1.34062};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{-1.13623,-3.92871,-1.34306}, 90};
			};
		};
		class Land_i_House_Small_01_V2_F : Land_i_House_Small_01_V1_F {};
		class Land_i_House_Small_01_V3_F : Land_i_House_Small_01_V1_F {};

		class Land_i_House_Small_03_V1_F : BaseHouse {
			price = 3250000;
			spawnPos[] = {-3.26758,0.970703,-0.314249};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{0.559082,4.48291,-0.316688}, 270};
			};
		};

		class Land_i_House_Big_02_V1_F : BaseHouse {
			price = 4050000;
			spawnPos[] = {0.442383,2.39697,-2.88253};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{4.28613,2.84229,-2.88497}, 0};
			};
		};
		class Land_i_House_Big_02_V2_F : Land_i_House_Big_02_V1_F {};
		class Land_i_House_Big_02_V3_F : Land_i_House_Big_02_V1_F {};

		class Land_i_House_Big_01_V1_F : BaseHouse {
			price = 4400000;
			spawnPos[] = {-1.91992,-1.29736,-3.06494};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{-4.03271,5.45361,-3.06737}, 180};
			};
		};
		class Land_i_House_Big_01_V2_F : Land_i_House_Big_01_V1_F {};
		class Land_i_House_Big_01_V3_F : Land_i_House_Big_01_V1_F {};

		class Land_LightHouse_F : BaseHouse {
			price = 560000000;
			spawnPos[] = {0.598145,-2.52051,-11.5156};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{1.00732,-4.0791,-11.1185}, 102.99};
			};
		};

		class C_Boat_Civil_04_F : BaseHouse {
			price = 760000000;
			canShare = false;
			spawnPos[] = {-2.46826,-7.74512,-7.68176};
			
			class Storage {
				object = "Land_Cargo20_white_F";
				position[] = {{-0.169434,-8.78467,-7.70293}, 270};
			};
		};

		// WAREHOUSES
		class Land_i_Shed_Ind_F : BaseHouse {
			price = 17500000;
			breakIn = 10 * 60;
			spawnPos[] = {5.79297,3.77783,-1.68354};
			
			class Storage {
				object = "Land_Cargo20_white_F";
				position[] = {{-0.140137,0.405273,-1.64059}, 180};
			};
			class Garage {
				spawnPos[] = {{0, 0, 0}, 0};
			};
		};
	};

	class Upgrades {};
};