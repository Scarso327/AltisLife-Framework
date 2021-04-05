class CfgRandomEvents {
	/* TESTING SPAWN VALUES
	SpawnCondition = "true";
	NotifyDelay = 1 * 60;
	SpawnDelay = 1 * 60;
	Cooldown = 2 * 60;
	RandomAddition = 2 * 60;*/
	
	class Airdrop {
		SpawnCondition = "(count ([""Civilian""] call ULP_fnc_allMembers)) >= 20";
		NotifyDelay = 10 * 60;
		SpawnDelay = 30 * 60;
		Cooldown = 60 * 60;
		RandomAddition = 20 * 60;
		class Events {
			class OnWarning { code = "_this params [[""_message"", """", [""""]]]; hint parseText _message;"; };
			class OnSpawn { code = "_this params [[""_message"", """", [""""]]]; hint parseText _message;"; };
		};
		class ServerFunctions {
			onSpawn = "_this call ULP_SRV_fnc_airdrop;";
			onCompleted = "_this call ULP_SRV_fnc_spawnEvent;";
		};
		class Locations {
			// Drops INSIDE redzone
			class D_1 {
				position[] = {9165.79,8538.05,77.361};
				radius = 0;
			};
			class D_2 : D_1 { position[] = {9786.08,9421.7,55.6239}; };
			class D_3 : D_1 { position[] = {12377.5,9304.05,79.3657}; };
			class D_4 : D_1 { position[] = {12687.2,8225.15,9.85319}; };
			class D_5 : D_1 { position[] = {11718.9,8308.91,85.8831}; };
			class D_6 : D_1 { position[] = {11405.5,8240.43,134.813}; };
			class D_7 : D_1 { position[] = {10810.6,8105.16,105.331}; };
			class D_8 : D_1 { position[] = {10674.3,8427.96,72.9035}; };
			class D_9 : D_1 { position[] = {10211.3,8089.07,52.5622}; };
			class D_10 : D_1 { position[] = {9899.53,7495.14,100.983}; };
			class D_11 : D_1 { position[] = {10533.8,7132.13,143.591}; };
			class D_12 : D_1 { position[] = {10983.7,6891.62,149.694}; };
			class D_13 : D_1 { position[] = {13335.3,6591.93,36.947}; };
			class D_14 : D_1 { position[] = {12029.5,6733.74,81.2849}; };
			class D_15 : D_1 { position[] = {11848,7171.81,177.635}; };
			class D_16 : D_1 { position[] = {12151.5,7591.27,219.947}; };
			class D_17 : D_1 { position[] = {9774.65,8282.19,82.6306}; };
			class D_18 : D_1 { position[] = {11282.7,9202.61,79.3864}; };
			class D_19 : D_1 { position[] = {10149.5,9360.57,60.7545}; };
			class D_20 : D_1 { position[] = {12005.5,8911.8,65.3659}; };
			class D_21 : D_1 { position[] = {12084.9,9548.04,53.2381}; };
			class D_22 : D_1 { position[] = {12110.1,9705.98,29.1991}; };
			class D_23 : D_1 { position[] = {12385.1,10008.6,5.2118}; };
			class D_24 : D_1 { position[] = {11911.9,10445.5,12.1701}; };
			class D_25 : D_1 { position[] = {12789.9,9660.04,9.26665}; };
			class D_26 : D_1 { position[] = {10623.9,10072.3,17.0309}; };
			class D_27 : D_1 { position[] = {13170.9,7526.69,12.7628}; };
			class D_28 : D_1 { position[] = {10820.1,8891.23,62.7135}; };
			class D_29 : D_1 { position[] = {10482.7,9071.13,27.7921}; };
			class D_30 : D_1 { position[] = {10561.8,9225.02,36.2736}; };

			// Drops OUTSIDE redzone
			class D_31 {
				position[] = {21991.9,5405.2,9.4972};
				radius = 300;
			};
			class D_32 : D_31 { position[] = {21378.3,6078.43,29.702}; };
			class D_33 : D_31 { position[] = {21617.2,6409.82,18.0052}; };
			class D_34 : D_31 { position[] = {23096.3,6994.18,14.2764}; };
			class D_35 : D_31 { position[] = {23013.4,7496.05,18.3002}; };
			class D_36 : D_31 { position[] = {17416.7,9111.36,79.9217}; };
			class D_37 : D_31 { position[] = {17083.2,9129.42,92.0351}; };
			class D_38 : D_31 { position[] = {16755.4,9549.69,84.5089}; };
			class D_39 : D_31 { position[] = {16262.4,9546.67,19.3067}; };
			class D_40 : D_31 { position[] = {16513.3,9124.51,17.4657}; };
			class D_41 : D_31 { position[] = {18100,9500.49,114.426}; };
			class D_42 : D_31 { position[] = {18738.9,9727.68,123.674}; };
			class D_43 : D_31 { position[] = {19499.1,9925.84,164.749}; };
			class D_44 : D_31 { position[] = {22319,8244.17,34.1884}; };
			class D_45 : D_31 { position[] = {19172,9169.18,83.8668}; };
			class D_46 : D_31 { position[] = {18903.1,9383.18,142.241}; };
			class D_47 : D_31 { position[] = {19865.3,9320.71,73.9923}; };
			class D_48 : D_31 { position[] = {20144.7,8049.88,40.447}; };
			class D_49 : D_31 { position[] = {18444.1,8339.25,13.2348}; };
			class D_50 : D_31 { position[] = {21625.4,8800.08,54.836}; };
		};
	};

	class Shipwreck : Airdrop {
		SpawnCondition = "(count ([""Civilian""] call ULP_fnc_allMembers)) >= 5";
		NotifyDelay = 10 * 60;
		SpawnDelay = 20 * 60;
		Cooldown = 40 * 60;
		RandomAddition = 30 * 60;
		class Events : Events {
			class OnSpawn : OnSpawn {};
			class OnClaimed : OnSpawn {};
		};
		class ServerFunctions : ServerFunctions {
			onSpawn = "_this call ULP_SRV_fnc_shipwreck;";
		};
		class Locations {
			class Test {
				position[] = {0, 0, 0};
			};
		};
	};
};