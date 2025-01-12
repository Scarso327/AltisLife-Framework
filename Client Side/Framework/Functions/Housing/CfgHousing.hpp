class CfgHousing {
	nameLength = 32;
	houseLimit = 2;
	
	class Houses {
		// GARAGES
		class Land_i_Garage_V1_F {
			icon = "Data\UI\Spawns\garage.paa";
			price = 3500000;
			sellMultiplier = 0.4;
			breakIn = 3 * 60;
			canShare = true;
			canSpawn = false;
			spawnPos[] = {0, 0, 0};
			disabledUpgrades[] = {};
			condition = "true";

			class Storage {
				object = "";
				position[] = {{0, 0, 0}, 0};
			};
			class Garage {
				spawnPos[] = {{-12.019,0.273438,-0.230196}, 270};
			};
		};
		class Land_i_Garage_V2_F : Land_i_Garage_V1_F {};

		// HOUSES
		class BaseHouse {
			icon = "Data\UI\Spawns\house.paa";
			sellMultiplier = 0.4;
			breakIn = 5 * 60;
			canShare = true;
			canSpawn = true;
			disabledUpgrades[] = {};
			condition = "true";
		};

		class Land_Slub_House02_F : BaseHouse {
			price = 13000000;
			spawnPos[] = {1.46875,0.984863,-1.0281};
			
			class Storage {
				object = "Land_MetalCase_01_medium_F";
				position[] = {{2.84766,2.18945,-0.980395}, 0};
			};
		};

		class Land_i_Stone_Shed_V1_F : BaseHouse {
			price = 1650000;
			spawnPos[] = {0.090332,2.4209,-0.100504};
			
			class Storage {
				object = "Land_PlasticCase_01_small_F";
				position[] = {{-3.37132,3.99512,-0.102937}, 0};
			};
		};
		class Land_i_Stone_Shed_V2_F : Land_i_Stone_Shed_V1_F {};
		class Land_i_Stone_Shed_V3_F : Land_i_Stone_Shed_V1_F {};

		class Land_i_Addon_02_V1_F : Land_i_Stone_Shed_V1_F {
			price = 1950000;
		};

		class Land_i_Stone_HouseSmall_V1_F : BaseHouse {
			price = 2100000;
			spawnPos[] = {-5.875,1.85156,-0.632767};
			
			class Storage {
				object = "Land_PlasticCase_01_medium_F";
				position[] = {{5.89418,4.7583,-0.595899}, 0};
			};
		};
		class Land_i_Stone_HouseSmall_V2_F : Land_i_Stone_HouseSmall_V1_F {};
		class Land_i_Stone_HouseSmall_V3_F : Land_i_Stone_HouseSmall_V1_F {};

		class Land_i_House_Small_02_V1_F : BaseHouse {
			price = 2450000;
			spawnPos[] = {4.23022,0.202148,-0.702804};
			
			class Storage {
				object = "Land_PlasticCase_01_medium_F";
				position[] = {{7.08643,-0.105469,-0.701562}, 0};
			};
		};
		class Land_i_House_Small_02_V2_F : Land_i_House_Small_02_V1_F {};
		class Land_i_House_Small_02_V3_F : Land_i_House_Small_02_V1_F {};

		class Land_i_House_Small_01_V1_F : BaseHouse {
			price = 2900000;
			spawnPos[] = {-1.41695,-1.80029,-1.04134};
			
			class Storage {
				object = "Land_PlasticCase_01_medium_F";
				position[] = {{-1.24918,-3.88306,-1.04354}, 0};
			};
		};
		class Land_i_House_Small_01_V2_F : Land_i_House_Small_01_V1_F {};
		class Land_i_House_Small_01_V3_F : Land_i_House_Small_01_V1_F {};

		class Land_i_House_Small_03_V1_F : BaseHouse {
			price = 3250000;
			spawnPos[] = {-1.32422,-0.259766,0.00575018};
			
			class Storage {
				object = "Land_PlasticCase_01_medium_F";
				position[] = {{1.21436,1.42822,0.00331211}, 0};
			};
		};

		class Land_i_House_Big_02_V1_F : BaseHouse {
			price = 4050000;
			spawnPos[] = {-0.286377,3.17383,0.784062};
			
			class Storage {
				object = "Land_PlasticCase_01_large_F";
				position[] = {{4.14893,0.503906,0.781623}, 0};
			};
		};
		class Land_i_House_Big_02_V2_F : Land_i_House_Big_02_V1_F {};
		class Land_i_House_Big_02_V3_F : Land_i_House_Big_02_V1_F {};

		class Land_i_House_Big_01_V1_F : BaseHouse {
			price = 4400000;
			spawnPos[] = {-0.25415,5.96484,0.855064};
			
			class Storage {
				object = "B_supplyCrate_F";
				position[] = {{3.61621,6.56787,0.852626}, 0};
			};
		};
		class Land_i_House_Big_01_V2_F : Land_i_House_Big_01_V1_F {};
		class Land_i_House_Big_01_V3_F : Land_i_House_Big_01_V1_F {};

		class Land_LightHouse_F : BaseHouse {
			icon = "Data\UI\Spawns\lighthouse.paa";
			price = 660000000;
			spawnPos[] = {0.598145,-2.52051,-11.5156};
			
			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{1.00732,-4.0791,-11.1185}, 102.99};
			};
		};

		class C_Boat_Civil_04_F : BaseHouse {
			icon = "Data\UI\Spawns\boat.paa";
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
			icon = "Data\UI\Spawns\warehouse.paa";
			price = 17500000;
			breakIn = 10 * 60;
			spawnPos[] = {5.79297,3.77783,-1.68354};
			onBought = "[""BuyWarehouse""] call ULP_fnc_achieve;";
			
			class Storage {
				object = "Land_Cargo20_white_F";
				position[] = {{-0.140137,0.405273,-1.64059}, 180};
			};
			class Garage {
				spawnPos[] = {{-12.6245,3.8877,-1.51542}, 0};
			};
		};

		// GROUP SPECIFIC
		class Land_Cargo_Tower_V1_F : BaseHouse {
			icon = "Data\UI\Spawns\dmt.paa";
			price = 34896000;
			breakIn = 20 * 60;
			spawnPos[] = {15171.1,15339,12.8876};
			condition = "[] call ULP_fnc_isGroup && { [""DMT""] call ULP_fnc_hasGroupPerk } && { [] call ULP_fnc_isGroupOwner }";
			
			class Storage {
				object = "CargoNet_01_box_F";
				position[] = {{15171.1,15338,12.8852}, 0};
			};
		};
		class Land_Cargo_Tower_V2_F : Land_Cargo_Tower_V1_F {};
		class Land_Cargo_Tower_V3_F : Land_Cargo_Tower_V1_F {};

		class Land_MilOffices_V1_F : BaseHouse {
			icon = "Data\UI\Spawns\office.paa";
			price = 83350000;
			breakIn = 15 * 60;
			spawnPos[] = {15177.2,15386.7,3.29152};
			condition = "[] call ULP_fnc_isGroup && { [""MilitaryOffices""] call ULP_fnc_hasGroupPerk } && { [] call ULP_fnc_isGroupOwner }";
			
			class Storage {
				object = "Land_Cargo20_grey_F";
				position[] = {{15193.8,15391.7,3.28908}, 0};
			};
		};
		class Land_Offices_01_V1_F : Land_MilOffices_V1_F {
			price = 41455000;
			breakIn = 5 * 60;
			spawnPos[] = {15177.2,15461.1,7.97687};
			condition = "[] call ULP_fnc_isGroup && { [""OfficeBuilding""] call ULP_fnc_hasGroupPerk } && { [] call ULP_fnc_isGroupOwner }";
			class Storage {
				object = "C_IDAP_supplyCrate_F";
				position[] = {{15183.3,15467.3,7.97443}, 0};
			};
		};
	};

	class Upgrades {};
};