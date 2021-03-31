class CfgHousing {
	nameLength = 32;
	houseLimit = 4;
	
	class Houses {
		class Base {
			price = 1500000;
			sellMultiplier = 0.4; // 40% of buy...
			breakIn = 5 * 60;
			canShare = true;
			canSpawn = true;
			spawnPos[] = {0, 0, 0};
			disabledUpgrades[] = {};
			class Storage {
				object = "";
				position[] = {{0, 0, 0}, 0};
			};
		};

		// Houses...
		class Land_i_House_Big_02_V1_F : Base {
			spawnPos[] = {0.40625, 2.4375, -2.88253};

			class Storage {
				object = "Land_PlasticCase_01_large_gray_F";
				position[] = {{4.37598, 2.84668, -2.88497}, 0};
			};
		};

		// Garages...
		class Land_i_Garage_V1_F : Base {
			canSpawn = false;
			class Garage {
				spawnPos[] = {{0, 0, 0}, 0};
			};
		};

		// Warehouses / Industrial Style Buildings...
		class Land_i_Shed_Ind_F : Base {};
	};

	class Upgrades {};
};